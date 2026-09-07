// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/amp/gfxampprofileframe.cpp
// Functions: 167
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\amp\gfxampprofileframe.h"

//------------------------------------------------------------------------------
// Address: 0x100FEF60
// Name: void readString(class GFile __near &,class GString __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl readString(struct GFile *a1, struct GString *a2)
{
  struct GFile *v2; // esi
  int (__thiscall *Read)(GFile *, unsigned __int8 *, int); // edx
  int v4; // edi
  struct GString *v5; // ebx
  int (__thiscall *v6)(GFile *, unsigned __int8 *, int); // edx
  int v7; // [esp+8h] [ebp-4h] BYREF

  v2 = a1;
  Read = a1->Read;
  v7 = 0;
  Read(this: a1, a2: (unsigned __int8 *)&v7, a3: 4);
  v4 = v7;
  if ( v7 != 0 )
  {
    v5 = a2;
    do
    {
      v6 = v2->Read;
      HIBYTE(a1) = 0;
      v6(this: v2, a2: (unsigned __int8 *)&a1 + 3, a3: 1);
      GString::AppendChar(this: (unsigned int *)v5, result: (CImagePacker *)SHIBYTE(a1));
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FEFC0
// Name: void writeString(class GFile __near &,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl writeString(struct GFile *a1, struct GString *a2)
{
  struct GString *v2; // edi
  int Length; // eax
  struct GFile *v4; // ebx
  unsigned int i; // esi
  int (__thiscall *Write)(GFile *, const unsigned __int8 *, int); // edx
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v2 = a2;
  Length = GString::GetLength(this: a2);
  v4 = a1;
  v7 = Length;
  a1->Write(this: a1, a2: (const unsigned __int8 *)&v7, a3: 4);
  for ( i = 0; i < GString::GetLength(this: v2); ++i )
  {
    Write = v4->Write;
    LOBYTE(a1) = *(_BYTE *)((v2->HeapTypeBits & 0xFFFFFFFC) + i + 8);
    Write(this: v4, a2: (const unsigned __int8 *)&a1, a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF030
// Name: public: void GFxAmpMemItem::SetValue(unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxAmpMemItem::SetValue(CFunctorCallbackBase *this, unsigned int memValue)
{
  *((_DWORD *)this + 3) = memValue;
  *((_BYTE *)this + 16) = 1;
  return memValue;
}

//------------------------------------------------------------------------------
// Address: 0x100FF050
// Name: public: void GFxAmpMemSegment::Read(class GFile __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMemSegment::Read(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,float),CFuncMemPolicyNone> *this,
        int a2,
        unsigned int version)
{
  int v3; // edi
  void (__thiscall *v4)(int, int *, int); // edx
  int v6; // ecx
  void (__thiscall *v7)(int, int *, int); // edx
  int v8; // ecx
  void (__thiscall *v9)(int, char *, int); // edx
  void (__thiscall *v10)(int, int *, int); // edx
  int v11; // ecx
  int v12; // [esp+Ch] [ebp-8h] BYREF
  int v13; // [esp+10h] [ebp-4h]

  v3 = a2;
  v4 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 40);
  v12 = 0;
  v13 = 0;
  v4(a1: a2, a2: &v12, a3: 8);
  v6 = v13;
  LODWORD(this->m_pfnProxied) = v12;
  DWORD1(this->m_pfnProxied) = v6;
  v7 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)v3 + 40);
  v12 = 0;
  v13 = 0;
  v7(a1: v3, a2: &v12, a3: 8);
  v8 = v13;
  DWORD2(this->m_pfnProxied) = v12;
  HIDWORD(this->m_pfnProxied) = v8;
  v9 = *(void (__thiscall **)(int, char *, int))(*(_DWORD *)v3 + 40);
  HIBYTE(a2) = 0;
  v9(a1: v3, a2: (char *)&a2 + 3, a3: 1);
  LOBYTE(this->m_pObject) = HIBYTE(a2);
  v10 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)v3 + 40);
  v12 = 0;
  v13 = 0;
  v10(a1: v3, a2: &v12, a3: 8);
  v11 = v13;
  *((_DWORD *)this + 6) = v12;
  *((_DWORD *)this + 7) = v11;
}

//------------------------------------------------------------------------------
// Address: 0x100FF0F0
// Name: public: void GFxAmpMovieInstructionStats::ScriptBufferStats::Write(class GFile __near &,unsigned long)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMovieInstructionStats::ScriptBufferStats::Write(
        GFxAmpMovieInstructionStats::ScriptBufferStats *this,
        struct GFile *i,
        unsigned int version)
{
  struct GFile *v3; // esi
  int (__thiscall *Write)(GFile *, const unsigned __int8 *, int); // edx
  int (__thiscall *v6)(GFile *, const unsigned __int8 *, int); // edx
  int (__thiscall *v7)(GFile *, const unsigned __int8 *, int); // edx
  int (__thiscall *v8)(GFile *, const unsigned __int8 *, int); // edx
  int v9; // ebx
  int (__thiscall *v10)(GFile *, const unsigned __int8 *, int); // edx
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  GFile_vtbl *v14; // eax
  _DWORD v15[2]; // [esp+Ch] [ebp-Ch] BYREF
  int v16; // [esp+14h] [ebp-4h] BYREF

  v3 = i;
  Write = i->Write;
  v16 = *((_DWORD *)this + 2);
  Write(this: i, a2: (const unsigned __int8 *)&v16, a3: 4);
  v6 = v3->Write;
  i = *((struct GFile **)this + 3);
  v6(this: v3, a2: (const unsigned __int8 *)&i, a3: 4);
  v7 = v3->Write;
  i = *((struct GFile **)this + 4);
  v7(this: v3, a2: (const unsigned __int8 *)&i, a3: 4);
  v8 = v3->Write;
  i = *((struct GFile **)this + 6);
  v8(this: v3, a2: (const unsigned __int8 *)&i, a3: 4);
  v9 = 0;
  for ( i = nullptr; (unsigned int)i < *((_DWORD *)this + 6); i = (struct GFile *)((char *)i + 1) )
  {
    v10 = v3->Write;
    v16 = *(_DWORD *)(v9 + *((_DWORD *)this + 5));
    v10(this: v3, a2: (const unsigned __int8 *)&v16, a3: 4);
    v11 = *((_DWORD *)this + 5);
    v12 = *(_DWORD *)(v11 + v9 + 8);
    v13 = *(_DWORD *)(v11 + v9 + 12);
    v14 = v3->__vftable;
    v15[0] = v12;
    v15[1] = v13;
    v14->Write(this: v3, a2: (const unsigned __int8 *)v15, a3: 8);
    v9 += 16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF1B0
// Name: public: struct GFxAmpMemItem const __near * GFxAmpMemItem::SearchForName(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *__thiscall GFxAmpMemItem::SearchForName(
        _DWORD *this,
        const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *result)
{
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v3; // eax
  int v4; // esi

  if ( strcmp((const char *)((*(this + 2) & 0xFFFFFFFC) + 8), (const char *)result) == 0 )
    return (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *)this;
  v4 = 0;
  if ( *(this + 8) == 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = GFxAmpMemItem::SearchForName(result);
    if ( v3 != nullptr )
      break;
    if ( (unsigned int)++v4 >= *(this + 8) )
      return nullptr;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100FF220
// Name: public: unsigned long GFxAmpMemItem::GetMaxId(void)const
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *__thiscall GFxAmpMemItem::GetMaxId(
        const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> **this)
{
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v2; // ebx
  unsigned int v3; // edi
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *MaxId; // eax
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v6; // [esp+0h] [ebp-Ch]

  v2 = *(this + 5);
  v3 = 0;
  if ( *(this + 8) != nullptr )
  {
    do
    {
      MaxId = GFxAmpMemItem::GetMaxId(result: v6);
      if ( MaxId >= v2 )
        v2 = MaxId;
      ++v3;
    }
    while ( v3 < (unsigned int)*(this + 8) );
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100FF250
// Name: public: void GFxAmpMemItem::Write(class GFile __near &,unsigned long)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpMemItem::Write(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *this@<ecx>,
        CMatRenderContextBase *str,
        __int128 version)
{
  CMatRenderContextBase *v3; // esi
  void (__thiscall *Bind)(struct CMatRenderContextBase *, IMaterial *, void *); // edx
  void (__thiscall *v6)(struct CMatRenderContextBase *, IMaterial *, void *); // edx
  void (__thiscall *v7)(struct CMatRenderContextBase *, IMaterial *, void *); // edx
  void (__thiscall *v8)(struct CMatRenderContextBase *, IMaterial *, void *); // edx
  void (__thiscall *v9)(struct CMatRenderContextBase *, IMaterial *, void *); // edx
  void (__thiscall *v10)(struct CMatRenderContextBase *, IMaterial *, void *); // edx
  unsigned int i; // ebx
  __int128 v12; // [esp-4h] [ebp-10h]

  v3 = str;
  writeString(a1: (struct GFile *)str, a2: (struct GString *)&this->m_pfnProxied + 2);
  Bind = v3->Bind;
  LOBYTE(str) = LOBYTE(this->m_pObject) != 0;
  Bind(this: v3, a2: (IMaterial *)&str, a3: (void *)1);
  v6 = v3->Bind;
  LOBYTE(str) = BYTE1(this->m_pObject) != 0;
  v6(this: v3, a2: (IMaterial *)&str, a3: (void *)1);
  v7 = v3->Bind;
  str = (CMatRenderContextBase *)HIDWORD(this->m_pfnProxied);
  v7(this: v3, a2: (IMaterial *)&str, a3: (void *)4);
  v8 = v3->Bind;
  str = *(&this->m_pObject + 1);
  v8(this: v3, a2: (IMaterial *)&str, a3: (void *)4);
  v9 = v3->Bind;
  str = *((CMatRenderContextBase **)this + 6);
  v9(this: v3, a2: (IMaterial *)&str, a3: (void *)4);
  v10 = v3->Bind;
  str = *((CMatRenderContextBase **)this + 8);
  v10(this: v3, a2: (IMaterial *)&str, a3: (void *)4);
  for ( i = 0; i < *((_DWORD *)this + 8); ++i )
  {
    LODWORD(v12) = version;
    GFxAmpMemItem::Write(
      this: *(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> **)(*((_DWORD *)this + 7) + 4 * i),
      str: v3,
      version: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF320
// Name: public: void GFxAmpCurrentState::Write(class GFile __near &,unsigned long)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpCurrentState::Write(
        GFxAmpCurrentState *this@<ecx>,
        int a2@<ebx>,
        struct GFile *Size,
        unsigned int version)
{
  struct GFile *v4; // esi
  int (__thiscall *Write)(GFile *, const unsigned __int8 *, int); // edx
  GFile_vtbl *v7; // eax
  unsigned int i; // ebx
  int (__thiscall *v9)(GFile *, const unsigned __int8 *, int); // edx
  GFile_vtbl *v10; // eax
  GFile_vtbl *v11; // eax
  GFile_vtbl *v12; // eax
  unsigned int CurrentFileId_high; // ecx
  int (__thiscall *v14)(GFile *, const unsigned __int8 *, int); // edx
  int (__thiscall *v15)(GFile *, const unsigned __int8 *, int); // edx
  int CurrentFileId; // [esp+8h] [ebp-8h] BYREF
  unsigned int StateFlags; // [esp+Ch] [ebp-4h] BYREF

  v4 = Size;
  Write = Size->Write;
  StateFlags = this->StateFlags;
  Write(this: Size, a2: (const unsigned __int8 *)&StateFlags, a3: 4);
  writeString(a1: v4, a2: &this->ConnectedApp);
  if ( version >= 5 )
    writeString(a1: v4, a2: &this->ConnectedFile);
  writeString(a1: v4, a2: &this->AaMode);
  writeString(a1: v4, a2: &this->StrokeType);
  writeString(a1: v4, a2: &this->CurrentLocale);
  v7 = v4->__vftable;
  Size = (struct GFile *)this->Locales.Data.Size;
  ((void (__thiscall *)(struct GFile *, struct GFile **, int, int))v7->Write)(a1: v4, a2: &Size, a3: 4, a4: a2);
  for ( i = 0; i < this->Locales.Data.Size; ++i )
    writeString(a1: v4, a2: &this->Locales.Data.Data[i]);
  v9 = v4->Write;
  Size = (struct GFile *)LODWORD(this->CurveTolerance);
  ((void (__thiscall *)(struct GFile *, struct GFile **))v9)(a1: v4, a2: &Size);
  v10 = v4->__vftable;
  Size = (struct GFile *)LODWORD(this->CurveToleranceMin);
  v10->Write(this: v4, a2: (const unsigned __int8 *)&Size, a3: 4);
  v11 = v4->__vftable;
  Size = (struct GFile *)LODWORD(this->CurveToleranceMax);
  v11->Write(this: v4, a2: (const unsigned __int8 *)&Size, a3: 4);
  v12 = v4->__vftable;
  Size = (struct GFile *)LODWORD(this->CurveToleranceStep);
  v12->Write(this: v4, a2: (const unsigned __int8 *)&Size, a3: 4);
  if ( version >= 0xA )
  {
    CurrentFileId_high = HIDWORD(this->CurrentFileId);
    v14 = v4->Write;
    CurrentFileId = this->CurrentFileId;
    StateFlags = CurrentFileId_high;
    v14(this: v4, a2: (const unsigned __int8 *)&CurrentFileId, a3: 8);
    v15 = v4->Write;
    version = this->CurrentLineNumber;
    v15(this: v4, a2: (const unsigned __int8 *)&version, a3: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF620
// Name: public: void GFxAmpMovieInstructionStats::ScriptBufferStats::Read(class GFile __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMovieInstructionStats::ScriptBufferStats::Read(
        IMatRenderContext *this,
        MaterialNonInteractiveMode_t str,
        unsigned int version)
{
  MaterialNonInteractiveMode_t v3; // esi
  void (__thiscall *v4)(MaterialNonInteractiveMode_t, unsigned int *, int); // edx
  void (__thiscall *v6)(MaterialNonInteractiveMode_t, MaterialNonInteractiveMode_t *, int); // edx
  void (__thiscall *v7)(MaterialNonInteractiveMode_t, MaterialNonInteractiveMode_t *, int); // edx
  void (__thiscall *v8)(MaterialNonInteractiveMode_t, MaterialNonInteractiveMode_t *, int); // edx
  MaterialNonInteractiveMode_t v9; // eax
  IMatRenderContext *v10; // ebx
  bool v11; // zf
  int v12; // edi
  void (__thiscall *v13)(MaterialNonInteractiveMode_t, MaterialNonInteractiveMode_t *, int); // edx
  void (__thiscall *v14)(MaterialNonInteractiveMode_t, void (__thiscall **)(IMatRenderContext *), int); // edx
  IMatRenderContext_vtbl *v15; // eax
  IMatRenderContext *v16; // ecx
  void (__thiscall *v17)(IMatRenderContext *); // [esp+Ch] [ebp-10h] BYREF
  void (__thiscall *v18)(IMatRenderContext *); // [esp+10h] [ebp-Ch]
  IMatRenderContext *v19; // [esp+14h] [ebp-8h]
  unsigned int i; // [esp+18h] [ebp-4h] BYREF

  v3 = str;
  v4 = *(void (__thiscall **)(MaterialNonInteractiveMode_t, unsigned int *, int))(*(_DWORD *)str + 40);
  v19 = this;
  i = 0;
  v4(a1: str, a2: &i, a3: 4);
  *((_DWORD *)this + 2) = i;
  v6 = *(void (__thiscall **)(MaterialNonInteractiveMode_t, MaterialNonInteractiveMode_t *, int))(*(_DWORD *)v3 + 40);
  str = MATERIAL_NON_INTERACTIVE_MODE_STARTUP;
  v6(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 3) = str;
  v7 = *(void (__thiscall **)(MaterialNonInteractiveMode_t, MaterialNonInteractiveMode_t *, int))(*(_DWORD *)v3 + 40);
  str = MATERIAL_NON_INTERACTIVE_MODE_STARTUP;
  v7(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 4) = str;
  v8 = *(void (__thiscall **)(MaterialNonInteractiveMode_t, MaterialNonInteractiveMode_t *, int))(*(_DWORD *)v3 + 40);
  str = MATERIAL_NON_INTERACTIVE_MODE_STARTUP;
  v8(a1: v3, a2: &str, a3: 4);
  v9 = str;
  v10 = this + 5;
  if ( (unsigned int)str >= *((_DWORD *)this + 6) )
  {
    if ( (unsigned int)str < *((_DWORD *)this + 7) )
      goto LABEL_7;
    GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)this + 5,
      pheapAddr: (ButtonCode_t)(this + 5),
      newCapacity: str + ((unsigned int)str >> 2));
  }
  else
  {
    if ( (unsigned int)str >= *((_DWORD *)this + 7) >> 1 )
      goto LABEL_7;
    GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)this + 5,
      pheapAddr: (ButtonCode_t)(this + 5),
      newCapacity: str);
  }
  v9 = str;
LABEL_7:
  *((_DWORD *)this + 6) = v9;
  v11 = *((_DWORD *)this + 6) == 0;
  i = 0;
  if ( !v11 )
  {
    v12 = 0;
    do
    {
      v13 = *(void (__thiscall **)(MaterialNonInteractiveMode_t, MaterialNonInteractiveMode_t *, int))(*(_DWORD *)v3 + 40);
      str = MATERIAL_NON_INTERACTIVE_MODE_STARTUP;
      v13(a1: v3, a2: &str, a3: 4);
      *(int (__thiscall **)(struct IMatRenderContext *))((char *)&v10->AddRef + v12) = (int (__thiscall *)(struct IMatRenderContext *))str;
      v14 = *(void (__thiscall **)(MaterialNonInteractiveMode_t, void (__thiscall **)(IMatRenderContext *), int))(*(_DWORD *)v3 + 40);
      v17 = nullptr;
      v18 = nullptr;
      v14(a1: v3, a2: &v17, a3: 8);
      v15 = v10->__vftable;
      *(void (__thiscall **)(IMatRenderContext *))((char *)&v15->BeginRender + v12) = v17;
      v16 = v19;
      *(void (__thiscall **)(IMatRenderContext *))((char *)&v15->EndRender + v12) = v18;
      v12 += 16;
      ++i;
    }
    while ( (IMatRenderContext_vtbl *)i < v16[6].__vftable );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF730
// Name: public: void GFxAmpMovieFunctionStats::Write(class GFile __near &,unsigned long)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMovieFunctionStats::Write(GFxAmpMovieFunctionStats *this, struct GFile *i, unsigned int a3)
{
  struct GFile *v3; // esi
  int (__thiscall *Write)(GFile *, const unsigned __int8 *, int); // edx
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  GFile_vtbl *v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  GFile_vtbl *v14; // eax
  int (__thiscall *v15)(GFile *, const unsigned __int8 *, int); // edx
  int v16; // eax
  int v17; // ecx
  int v18; // edx
  GFile_vtbl *v19; // eax
  struct GFile *v20; // eax
  char *v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // edx
  _DWORD *v24; // ecx
  signed int v25; // ebx
  int v26; // eax
  int v27; // edi
  int v28; // ecx
  int v29; // edx
  GFile_vtbl *v30; // eax
  int (__thiscall *v31)(GFile *, const unsigned __int8 *, int); // edx
  int v32; // eax
  int v33; // edx
  int v34; // eax
  int (__thiscall *v35)(GFile *, const unsigned __int8 *, int); // edx
  int (__thiscall *v36)(GFile *, const unsigned __int8 *, int); // edx
  unsigned int v37; // eax
  _DWORD *v38; // ecx
  int v39; // [esp+Ch] [ebp-20h] BYREF
  int v40; // [esp+10h] [ebp-1Ch]
  int v41; // [esp+14h] [ebp-18h] BYREF
  int v42; // [esp+18h] [ebp-14h]
  _DWORD v43[2]; // [esp+1Ch] [ebp-10h] BYREF
  char *v44; // [esp+24h] [ebp-8h]
  int v45; // [esp+28h] [ebp-4h] BYREF

  v3 = i;
  Write = i->Write;
  v45 = *((_DWORD *)this + 3);
  Write(this: i, a2: (const unsigned __int8 *)&v45, a3: 4);
  v6 = 0;
  for ( i = nullptr; (unsigned int)i < *((_DWORD *)this + 3); i = (struct GFile *)((char *)i + 1) )
  {
    v7 = *((_DWORD *)this + 2);
    v8 = *(_DWORD *)(v6 + v7);
    v9 = *(_DWORD *)(v6 + v7 + 4);
    v10 = v3->__vftable;
    v43[0] = v8;
    v43[1] = v9;
    v10->Write(this: v3, a2: (const unsigned __int8 *)v43, a3: 8);
    v11 = *((_DWORD *)this + 2);
    v12 = *(_DWORD *)(v6 + v11 + 8);
    v13 = *(_DWORD *)(v6 + v11 + 12);
    v14 = v3->__vftable;
    v41 = v12;
    v42 = v13;
    v14->Write(this: v3, a2: (const unsigned __int8 *)&v41, a3: 8);
    v15 = v3->Write;
    v45 = *(_DWORD *)(v6 + *((_DWORD *)this + 2) + 16);
    v15(this: v3, a2: (const unsigned __int8 *)&v45, a3: 4);
    v16 = *((_DWORD *)this + 2);
    v17 = *(_DWORD *)(v6 + v16 + 24);
    v18 = *(_DWORD *)(v6 + v16 + 28);
    v19 = v3->__vftable;
    v39 = v17;
    v40 = v18;
    v19->Write(this: v3, a2: (const unsigned __int8 *)&v39, a3: 8);
    v6 += 32;
  }
  v20 = *((struct GFile **)this + 5);
  if ( v20 != nullptr )
    v20 = (struct GFile *)v20->__vftable;
  i = v20;
  v3->Write(this: v3, a2: (const unsigned __int8 *)&i, a3: 4);
  v21 = *((char **)this + 5);
  if ( v21 != nullptr )
  {
    v23 = *((_DWORD *)v21 + 1);
    v22 = 0;
    v24 = v21 + 8;
    do
    {
      if ( *v24 != -2 )
        break;
      ++v22;
      v24 += 6;
    }
    while ( v22 <= v23 );
    v21 = (char *)this + 20;
  }
  else
  {
    v22 = 0;
  }
  v44 = v21;
  v25 = v22;
  while ( v44 != nullptr )
  {
    v26 = *(_DWORD *)v44;
    if ( *(_DWORD *)v44 == 0 || v25 > *(_DWORD *)(v26 + 4) )
      break;
    v27 = 24 * v25;
    v28 = *(_DWORD *)(24 * v25 + v26 + 16);
    v29 = *(_DWORD *)(24 * v25 + v26 + 20);
    v30 = v3->__vftable;
    v39 = v28;
    v40 = v29;
    v30->Write(this: v3, a2: (const unsigned __int8 *)&v39, a3: 8);
    writeString(a1: v3, a2: (struct GString *)(*(_DWORD *)(24 * v25 + *(_DWORD *)v44 + 24) + 8));
    v31 = v3->Write;
    i = *(struct GFile **)(*(_DWORD *)(24 * v25 + *(_DWORD *)v44 + 24) + 12);
    v31(this: v3, a2: (const unsigned __int8 *)&i, a3: 4);
    if ( a3 >= 9 )
    {
      v32 = *(_DWORD *)(v27 + *(_DWORD *)v44 + 24);
      v33 = *(_DWORD *)(v32 + 16);
      v34 = *(_DWORD *)(v32 + 20);
      v41 = v33;
      v35 = v3->Write;
      v42 = v34;
      v35(this: v3, a2: (const unsigned __int8 *)&v41, a3: 8);
      v36 = v3->Write;
      i = *(struct GFile **)(*(_DWORD *)(v27 + *(_DWORD *)v44 + 24) + 24);
      v36(this: v3, a2: (const unsigned __int8 *)&i, a3: 4);
    }
    v37 = *(_DWORD *)(*(_DWORD *)v44 + 4);
    if ( v25 <= (int)v37 && ++v25 <= v37 )
    {
      v38 = (_DWORD *)(*(_DWORD *)v44 + 24 * v25 + 8);
      do
      {
        if ( *v38 != -2 )
          break;
        ++v25;
        v38 += 6;
      }
      while ( v25 <= v37 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF940
// Name: public: void MovieSourceLineStats::Write(class GFile __near &,unsigned long)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge MovieSourceLineStats::Write(
        MovieSourceLineStats *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        struct GFile *a4,
        unsigned int i)
{
  struct GFile *v6; // esi
  int (__thiscall *Write)(GFile *, const unsigned __int8 *, int); // edx
  int v8; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  GFile_vtbl *v12; // eax
  int (__thiscall *v13)(GFile *, const unsigned __int8 *, int); // edx
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  GFile_vtbl *v17; // eax
  _DWORD *v18; // eax
  MovieSourceLineStats *v19; // ecx
  unsigned int v20; // eax
  unsigned int v21; // edx
  _DWORD *v22; // ecx
  signed int v23; // edi
  int v24; // eax
  int v25; // ecx
  int v26; // edx
  GFile_vtbl *v27; // eax
  unsigned int v28; // eax
  _DWORD *v29; // ecx
  int v31; // [esp+4h] [ebp-10h] BYREF
  int v32; // [esp+8h] [ebp-Ch]
  _DWORD v33[2]; // [esp+Ch] [ebp-8h] BYREF

  if ( i >= 9 )
  {
    v6 = a4;
    Write = a4->Write;
    i = *((_DWORD *)this + 3);
    ((void (__thiscall *)(struct GFile *, unsigned int *, int, int, int))Write)(a1: a4, a2: &i, a3: 4, a4: a2, a5: a3);
    v8 = 0;
    for ( i = 0; i < *((_DWORD *)this + 3); ++i )
    {
      v9 = *((_DWORD *)this + 2);
      v10 = *(_DWORD *)(v8 + v9);
      v11 = *(_DWORD *)(v8 + v9 + 4);
      v12 = v6->__vftable;
      v33[0] = v10;
      v33[1] = v11;
      v12->Write(this: v6, a2: (const unsigned __int8 *)v33, a3: 8);
      v13 = v6->Write;
      a4 = *(struct GFile **)(v8 + *((_DWORD *)this + 2) + 8);
      v13(this: v6, a2: (const unsigned __int8 *)&a4, a3: 4);
      v14 = *((_DWORD *)this + 2);
      v15 = *(_DWORD *)(v8 + v14 + 16);
      v16 = *(_DWORD *)(v8 + v14 + 20);
      v17 = v6->__vftable;
      v31 = v15;
      v32 = v16;
      v17->Write(this: v6, a2: (const unsigned __int8 *)&v31, a3: 8);
      v8 += 24;
    }
    v18 = *((_DWORD **)this + 5);
    if ( v18 != nullptr )
      v18 = (_DWORD *)*v18;
    i = (unsigned int)v18;
    v6->Write(this: v6, a2: (const unsigned __int8 *)&i, a3: 4);
    v19 = *((MovieSourceLineStats **)this + 5);
    if ( v19 != nullptr )
    {
      v21 = *((_DWORD *)v19 + 1);
      v20 = 0;
      v22 = v19 + 2;
      do
      {
        if ( *v22 != -2 )
          break;
        ++v20;
        v22 += 6;
      }
      while ( v20 <= v21 );
      v19 = this + 5;
    }
    else
    {
      v20 = 0;
    }
    v33[0] = v19;
    v23 = v20;
    while ( v33[0] != 0 )
    {
      v24 = *(_DWORD *)v33[0];
      if ( *(_DWORD *)v33[0] == 0 || v23 > *(_DWORD *)(v24 + 4) )
        break;
      v25 = *(_DWORD *)(24 * v23 + v24 + 16);
      v26 = *(_DWORD *)(24 * v23 + v24 + 20);
      v27 = v6->__vftable;
      v31 = v25;
      v32 = v26;
      v27->Write(this: v6, a2: (const unsigned __int8 *)&v31, a3: 8);
      writeString(a1: v6, a2: (struct GString *)(24 * v23 + *(_DWORD *)v33[0] + 24));
      v28 = *(_DWORD *)(*(_DWORD *)v33[0] + 4);
      if ( v23 <= (int)v28 && ++v23 <= v28 )
      {
        v29 = (_DWORD *)(*(_DWORD *)v33[0] + 24 * v23 + 8);
        do
        {
          if ( *v29 != -2 )
            break;
          ++v23;
          v29 += 6;
        }
        while ( v23 <= v28 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FFAB0
// Name: public: void GFxAmpMemFragReport::Write(class GFile __near &,unsigned long)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxAmpMemFragReport::Write(
        CUtlVector<virtualsequence_t,CUtlMemory<virtualsequence_t,int> > *this,
        virtualsequence_t *str,
        unsigned int version)
{
  struct GFile *v3; // esi
  void (__thiscall *v4)(virtualsequence_t *, unsigned int *, int); // edx
  int v6; // edi
  int v7; // ecx
  int (__thiscall *Write)(GFile *, const unsigned __int8 *, int); // edx
  GString::DataDesc *v9; // ecx
  int (__thiscall *v10)(GFile *, const unsigned __int8 *, int); // edx
  int (__thiscall *v11)(GFile *, const unsigned __int8 *, int); // edx
  int v12; // ecx
  int (__thiscall *v13)(GFile *, const unsigned __int8 *, int); // edx
  const virtualsequence_t *v14; // eax
  CUtlVector<virtualsequence_t,CUtlMemory<virtualsequence_t,int> > *v15; // ecx
  unsigned int v16; // eax
  unsigned int m_nAllocationCount; // edx
  int *p_m_nGrowSize; // ecx
  signed int v19; // edi
  _DWORD *result; // eax
  int v21; // ecx
  int v22; // edx
  GFile_vtbl *v23; // eax
  struct GString *v24; // ebx
  GString::DataDesc *pData; // eax
  int (__thiscall *v26)(GFile *, const unsigned __int8 *, int); // edx
  int (__thiscall *v27)(GFile *, const unsigned __int8 *, int); // edx
  unsigned int activity; // eax
  int *v29; // ecx
  int v30; // [esp+Ch] [ebp-24h] BYREF
  int v31; // [esp+10h] [ebp-20h]
  GString::DataDesc *v32; // [esp+14h] [ebp-1Ch] BYREF
  GString::DataDesc *v33; // [esp+18h] [ebp-18h]
  _DWORD v34[2]; // [esp+1Ch] [ebp-14h] BYREF
  CUtlVector<virtualsequence_t,CUtlMemory<virtualsequence_t,int> > *v35; // [esp+24h] [ebp-Ch]
  unsigned int i; // [esp+28h] [ebp-8h] BYREF
  int v37; // [esp+2Ch] [ebp-4h]

  v3 = (struct GFile *)str;
  v4 = *(void (__thiscall **)(virtualsequence_t *, unsigned int *, int))(str->flags + 36);
  i = this->m_Size;
  v4(a1: str, a2: &i, a3: 4);
  i = 0;
  if ( this->m_Size != 0 )
  {
    v37 = 0;
    do
    {
      v6 = v37 + this->m_Memory.m_nGrowSize;
      v7 = *(_DWORD *)(v6 + 4);
      Write = v3->Write;
      v34[0] = *(_DWORD *)v6;
      v34[1] = v7;
      Write(this: v3, a2: (const unsigned __int8 *)v34, a3: 8);
      v9 = *(GString::DataDesc **)(v6 + 12);
      v10 = v3->Write;
      v32 = *(GString::DataDesc **)(v6 + 8);
      v33 = v9;
      v10(this: v3, a2: (const unsigned __int8 *)&v32, a3: 8);
      v11 = v3->Write;
      LOBYTE(str) = *(_BYTE *)(v6 + 16);
      v11(this: v3, a2: (const unsigned __int8 *)&str, a3: 1);
      v12 = *(_DWORD *)(v6 + 28);
      v13 = v3->Write;
      v30 = *(_DWORD *)(v6 + 24);
      v31 = v12;
      v13(this: v3, a2: (const unsigned __int8 *)&v30, a3: 8);
      v37 += 32;
      ++i;
    }
    while ( i < this->m_Size );
  }
  v14 = *((const virtualsequence_t **)this + 5);
  if ( v14 != nullptr )
    v14 = (const virtualsequence_t *)v14->flags;
  str = (virtualsequence_t *)v14;
  v3->Write(this: v3, a2: (const unsigned __int8 *)&str, a3: 4);
  v15 = *((CUtlVector<virtualsequence_t,CUtlMemory<virtualsequence_t,int> > **)this + 5);
  if ( v15 != nullptr )
  {
    m_nAllocationCount = v15->m_Memory.m_nAllocationCount;
    v16 = 0;
    p_m_nGrowSize = &v15->m_Memory.m_nGrowSize;
    do
    {
      if ( *p_m_nGrowSize != -2 )
        break;
      ++v16;
      p_m_nGrowSize += 6;
    }
    while ( v16 <= m_nAllocationCount );
    v15 = this + 1;
  }
  else
  {
    v16 = 0;
  }
  v35 = v15;
  v19 = v16;
  while ( 1 )
  {
    result = &v35->m_Memory.m_pMemory;
    if ( v35 == nullptr )
      break;
    result = &v35->m_Memory.m_pMemory->flags;
    if ( v35->m_Memory.m_pMemory == nullptr || v19 > result[1] )
      break;
    v21 = result[6 * v19 + 4];
    v22 = result[6 * v19 + 5];
    v23 = v3->__vftable;
    v30 = v21;
    v31 = v22;
    v23->Write(this: v3, a2: (const unsigned __int8 *)&v30, a3: 8);
    v24 = (struct GString *)*(&v35->m_Memory.m_pMemory[1].group + 6 * v19);
    pData = v24[3].pData;
    v32 = v24[2].pData;
    v26 = v3->Write;
    v33 = pData;
    v26(this: v3, a2: (const unsigned __int8 *)&v32, a3: 8);
    v27 = v3->Write;
    str = (virtualsequence_t *)v24[4].pData;
    v27(this: v3, a2: (const unsigned __int8 *)&str, a3: 4);
    writeString(a1: v3, a2: v24 + 5);
    activity = v35->m_Memory.m_pMemory->activity;
    if ( v19 <= (int)activity && ++v19 <= activity )
    {
      v29 = &v35->m_Memory.m_pMemory->group + 6 * v19;
      do
      {
        if ( *v29 != -2 )
          break;
        ++v19;
        v29 += 6;
      }
      while ( v19 <= activity );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FFC70
// Name: public: virtual GFxAmpMovieInstructionStats::~GFxAmpMovieInstructionStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMovieInstructionStats::~GFxAmpMovieInstructionStats(IShaderAPI *this)
{
  int v2; // eax
  IShaderAPI **v3; // esi
  int v4; // ebx

  v2 = *((_DWORD *)this + 3);
  v3 = (IShaderAPI **)(*((_DWORD *)this + 2) + 4 * v2 - 4);
  if ( v2 != 0 )
  {
    v4 = *((_DWORD *)this + 3);
    do
    {
      if ( *v3 != nullptr )
        GRefCountImpl::Release(this: *v3);
      --v3;
      --v4;
    }
    while ( v4 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 2));
  GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x100FFCF0
// Name: public: void GFxMovieStats::Write(class GFile __near &,unsigned long)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieStats::Write(
        int a1@<ecx>,
        ID3D11DeviceContext *this,
        unsigned int str,
        unsigned int version,
        ID3D11Buffer **a5,
        unsigned int *a6,
        unsigned int *a7)
{
  struct GFile *v7; // esi
  void (__stdcall *PSSetShader)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  int (__thiscall *Write)(GFile *, const unsigned __int8 *, int); // edx
  int (__thiscall *v11)(GFile *, const unsigned __int8 *, int); // edx
  unsigned int v12; // ebx
  int (__thiscall *v13)(GFile *, const unsigned __int8 *, int); // edx
  GFile_vtbl *v14; // eax
  GFile_vtbl *v15; // eax
  GFile_vtbl *v16; // eax
  int (__thiscall *v17)(GFile *, const unsigned __int8 *, int); // edx
  int (__thiscall *v18)(GFile *, const unsigned __int8 *, int); // edx
  unsigned int i; // ebx
  int (__thiscall *v20)(GFile *, const unsigned __int8 *, int); // edx
  int v21; // ebx
  int (__thiscall *v22)(GFile *, const unsigned __int8 *, int); // edx
  bool v23; // zf
  unsigned int v24; // ebx
  int v25; // [esp+Ch] [ebp-4h] BYREF

  v7 = (struct GFile *)this;
  PSSetShader = this->PSSetShader;
  v25 = *(_DWORD *)(a1 + 8);
  ((void (__thiscall *)(ID3D11DeviceContext *, int *, int))PSSetShader)(a1: this, a2: &v25, a3: 4);
  Write = v7->Write;
  this = *(ID3D11DeviceContext **)(a1 + 12);
  Write(this: v7, a2: (const unsigned __int8 *)&this, a3: 4);
  v11 = v7->Write;
  this = *(ID3D11DeviceContext **)(a1 + 16);
  v11(this: v7, a2: (const unsigned __int8 *)&this, a3: 4);
  v12 = str;
  if ( str >= 4 )
  {
    writeString(a1: v7, a2: (struct GString *)(a1 + 20));
    v13 = v7->Write;
    this = *(ID3D11DeviceContext **)(a1 + 24);
    v13(this: v7, a2: (const unsigned __int8 *)&this, a3: 4);
    v14 = v7->__vftable;
    this = *(ID3D11DeviceContext **)(a1 + 28);
    v14->Write(this: v7, a2: (const unsigned __int8 *)&this, a3: 4);
    v15 = v7->__vftable;
    this = *(ID3D11DeviceContext **)(a1 + 32);
    v15->Write(this: v7, a2: (const unsigned __int8 *)&this, a3: 4);
    v16 = v7->__vftable;
    this = *(ID3D11DeviceContext **)(a1 + 36);
    v16->Write(this: v7, a2: (const unsigned __int8 *)&this, a3: 4);
    v17 = v7->Write;
    this = *(ID3D11DeviceContext **)(a1 + 40);
    v17(this: v7, a2: (const unsigned __int8 *)&this, a3: 4);
  }
  if ( v12 >= 6 )
  {
    v18 = v7->Write;
    this = *(ID3D11DeviceContext **)(a1 + 48);
    v18(this: v7, a2: (const unsigned __int8 *)&this, a3: 4);
    for ( i = 0; i < *(_DWORD *)(a1 + 48); ++i )
    {
      if ( str >= 0xB )
        writeString(a1: v7, a2: (struct GString *)(*(_DWORD *)(*(_DWORD *)(a1 + 44) + 4 * i) + 8));
      v20 = v7->Write;
      this = *(ID3D11DeviceContext **)(*(_DWORD *)(*(_DWORD *)(a1 + 44) + 4 * i) + 12);
      v20(this: v7, a2: (const unsigned __int8 *)&this, a3: 4);
    }
  }
  v21 = *(_DWORD *)(a1 + 56);
  v22 = v7->Write;
  this = *(ID3D11DeviceContext **)(v21 + 12);
  v22(this: v7, a2: (const unsigned __int8 *)&this, a3: 4);
  v23 = *(_DWORD *)(v21 + 12) == 0;
  *(float *)&this = 0.0;
  if ( !v23 )
  {
    do
    {
      GFxAmpMovieInstructionStats::ScriptBufferStats::Write(
        this: *(GFxAmpMovieInstructionStats::ScriptBufferStats **)(*(_DWORD *)(v21 + 8) + 4 * (_DWORD)this),
        i: v7,
        version: str);
      this = (ID3D11DeviceContext *)((char *)this + 1);
    }
    while ( (unsigned int)this < *(_DWORD *)(v21 + 12) );
  }
  v24 = str;
  GFxAmpMovieFunctionStats::Write(this: *(GFxAmpMovieFunctionStats **)(a1 + 60), i: v7, a3: str);
  MovieSourceLineStats::Write(this: *(MovieSourceLineStats **)(a1 + 64), a2: a1, a3: (int)v7, a4: v7, i: v24);
}

//------------------------------------------------------------------------------
// Address: 0x100FFE80
// Name: public: void GFxAmpMovieInstructionStats::Read(class GFile __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMovieInstructionStats::Read(
        GFxAmpMovieInstructionStats *this,
        MaterialNonInteractiveMode_t str,
        unsigned int a3)
{
  void (__thiscall *v4)(MaterialNonInteractiveMode_t, unsigned int *, int); // eax
  unsigned int v5; // esi
  unsigned int v6; // edi
  GRenderer::CachedData *v7; // ebx
  int v8; // esi
  GRenderer_vtbl **v9; // eax
  int i; // ecx
  _DWORD *v11; // eax
  GRenderer *pRenderer; // esi
  int v13; // edi
  IShaderAPI *v14; // ecx
  int v15; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v16; // [esp+10h] [ebp-Ch] BYREF
  GFxAmpMovieInstructionStats *v17; // [esp+14h] [ebp-8h]
  unsigned int j; // [esp+18h] [ebp-4h]

  v4 = *(void (__thiscall **)(MaterialNonInteractiveMode_t, unsigned int *, int))(*(_DWORD *)str + 40);
  v17 = this;
  v16 = 0;
  v4(a1: str, a2: &v16, a3: 4);
  v5 = v16;
  v6 = *((_DWORD *)this + 3);
  v7 = (GRenderer::CachedData *)(this + 2);
  GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: v7,
    result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)v7,
    newSize: v16);
  if ( v5 > v6 )
  {
    v8 = v5 - v6;
    v9 = &v7->pRenderer->__vftable + v6;
    if ( v8 != 0 )
    {
      for ( i = v8; i != 0; --i )
      {
        if ( v9 != nullptr )
          *v9 = nullptr;
        ++v9;
      }
    }
  }
  for ( j = 0; j < *((_DWORD *)v17 + 3); ++j )
  {
    v15 = 2;
    v11 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v17, a3: 32, a4: &v15);
    if ( v11 != nullptr )
    {
      *v11 = &GRefCountImplCore::`vftable';
      v11[1] = 1;
      *v11 = &GFxAmpMovieInstructionStats::ScriptBufferStats::`vftable';
      v11[5] = 0;
      v11[6] = 0;
      v11[7] = 0;
      v15 = (int)v11;
    }
    else
    {
      v15 = 0;
    }
    pRenderer = v7->pRenderer;
    v13 = 4 * j;
    v14 = *((IShaderAPI **)&v7->pRenderer->__vftable + j);
    if ( v14 != nullptr )
      GRefCountImpl::Release(this: v14);
    *(GRenderer_vtbl **)((char *)&pRenderer->__vftable + v13) = (GRenderer_vtbl *)v15;
    GFxAmpMovieInstructionStats::ScriptBufferStats::Read(
      this: *(IMatRenderContext **)((char *)&v7->pRenderer->__vftable + v13),
      str,
      version: a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FFF90
// Name: public: struct GFxAmpMemItem __near * GFxAmpMemItem::AddChild(unsigned long,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMemItem::AddChild(_DWORD *this, CFunctor *id, unsigned __int8 *a3)
{
  char *v4; // eax
  char *v5; // esi
  int v6; // eax
  GRenderer::CachedData *v7; // edi
  GRenderer *v8; // edi
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v9 = 2;
  v4 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 40, a4: &v9);
  v5 = v4;
  if ( v4 != nullptr )
  {
    *(_DWORD *)v4 = &GRefCountImplCore::`vftable';
    *((_DWORD *)v4 + 1) = 1;
    *(_DWORD *)v4 = &GFxAmpMemItem::`vftable';
    GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v4 + 8));
    *((_DWORD *)v5 + 3) = 0;
    *((_WORD *)v5 + 8) = 0;
    *((_DWORD *)v5 + 5) = id;
    *((_DWORD *)v5 + 6) = 0;
    *((_DWORD *)v5 + 7) = 0;
    *((_DWORD *)v5 + 8) = 0;
    *((_DWORD *)v5 + 9) = 0;
  }
  else
  {
    v5 = nullptr;
  }
  GString::operator=(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v5 + 8), a2: a3);
  v6 = *(this + 8);
  v7 = (GRenderer::CachedData *)(this + 7);
  GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: v7,
    result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)v7,
    newSize: v6 + 1);
  v8 = (GRenderer *)((char *)v7->pRenderer + 4 * (int)v7->hData - 4);
  if ( v8 != nullptr )
  {
    if ( v5 != nullptr )
      GRefCountImpl::AddRef(this: (IShaderDevice *)v5);
    v8->__vftable = (GRenderer_vtbl *)v5;
  }
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: (IShaderAPI *)v5);
}

//------------------------------------------------------------------------------
// Address: 0x10100040
// Name: public: struct GFxAmpMemItem __near * GFxAmpMemItem::AddChild(unsigned long,char const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
struct GFxAmpMemItem *__thiscall GFxAmpMemItem::AddChild(
        GFxAmpMemItem *this,
        unsigned int id,
        char *a3,
        unsigned int memValue)
{
  char *v5; // eax
  char *v6; // esi
  GRenderer::CachedData *p_Children; // edi
  GRenderer *v8; // edi
  int v10; // [esp+Ch] [ebp-4h] BYREF

  v10 = 2;
  v5 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 40, a4: &v10);
  v6 = v5;
  if ( v5 != nullptr )
  {
    *(_DWORD *)v5 = &GRefCountImplCore::`vftable';
    *((_DWORD *)v5 + 1) = 1;
    *(_DWORD *)v5 = &GFxAmpMemItem::`vftable';
    GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v5 + 8));
    *((_DWORD *)v6 + 3) = 0;
    *((_WORD *)v6 + 8) = 0;
    *((_DWORD *)v6 + 5) = id;
    *((_DWORD *)v6 + 6) = 0;
    *((_DWORD *)v6 + 7) = 0;
    *((_DWORD *)v6 + 8) = 0;
    *((_DWORD *)v6 + 9) = 0;
  }
  else
  {
    v6 = nullptr;
  }
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v6 + 8),
    a2: (unsigned __int8 *)a3);
  p_Children = (GRenderer::CachedData *)&this->Children;
  *((_DWORD *)v6 + 3) = memValue;
  v6[16] = 1;
  GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: p_Children,
    result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)p_Children,
    newSize: (unsigned int)p_Children->hData + 1);
  v8 = (GRenderer *)((char *)p_Children->pRenderer + 4 * (int)p_Children->hData - 4);
  if ( v8 != nullptr )
  {
    GRefCountImpl::AddRef(this: (IShaderDevice *)v6);
    v8->__vftable = (GRenderer_vtbl *)v6;
  }
  GRefCountImpl::Release(this: (IShaderAPI *)v6);
  return (struct GFxAmpMemItem *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x10100100
// Name: public: void GFxAmpMemItem::Read(class GFile __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMemItem::Read(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *this,
        struct GFile *a2,
        unsigned int version)
{
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v3; // esi
  struct GFile *v4; // edi
  int (__thiscall *Read)(GFile *, unsigned __int8 *, int); // edx
  int (__thiscall *v6)(GFile *, unsigned __int8 *, int); // edx
  int (__thiscall *v7)(GFile *, unsigned __int8 *, int); // edx
  int (__thiscall *v8)(GFile *, unsigned __int8 *, int); // edx
  int (__thiscall *v9)(GFile *, unsigned __int8 *, int); // edx
  int (__thiscall *v10)(GFile *, unsigned __int8 *, int); // edx
  unsigned int v11; // edx
  _DWORD *v12; // eax
  int v13; // ecx
  char *v14; // eax
  _DWORD *v15; // esi
  int v16; // esi
  IShaderAPI *v17; // ecx
  int *v18; // esi
  int v19; // [esp+Ch] [ebp-20h] BYREF
  int v20; // [esp+10h] [ebp-1Ch] BYREF
  int v21; // [esp+14h] [ebp-18h] BYREF
  int v22; // [esp+18h] [ebp-14h] BYREF
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> *v23; // [esp+1Ch] [ebp-10h]
  unsigned int v24; // [esp+20h] [ebp-Ch] BYREF
  unsigned int i; // [esp+24h] [ebp-8h]
  char v26; // [esp+2Bh] [ebp-1h] BYREF

  v3 = this;
  v4 = a2;
  v23 = this;
  readString(a1: a2, a2: (struct GString *)&this->m_pfnProxied + 2);
  Read = v4->Read;
  HIBYTE(a2) = 0;
  Read(this: v4, a2: (unsigned __int8 *)&a2 + 3, a3: 1);
  LOBYTE(v3->m_pObject) = HIBYTE(a2) != 0;
  v6 = v4->Read;
  v26 = 0;
  v6(this: v4, a2: (unsigned __int8 *)&v26, a3: 1);
  BYTE1(v3->m_pObject) = v26 != 0;
  v7 = v4->Read;
  v22 = 0;
  v7(this: v4, a2: (unsigned __int8 *)&v22, a3: 4);
  HIDWORD(v3->m_pfnProxied) = v22;
  v8 = v4->Read;
  v21 = 0;
  v8(this: v4, a2: (unsigned __int8 *)&v21, a3: 4);
  *((_DWORD *)&v3->m_pObject + 1) = v21;
  v9 = v4->Read;
  v20 = 0;
  v9(this: v4, a2: (unsigned __int8 *)&v20, a3: 4);
  LODWORD(v3[1].m_pfnProxied) = v20;
  v10 = v4->Read;
  v24 = 0;
  v10(this: v4, a2: (unsigned __int8 *)&v24, a3: 4);
  i = DWORD2(v3[1].m_pfnProxied);
  GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (GRenderer::CachedData *)((char *)&v3[1].m_pfnProxied + 4),
    result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)((char *)&v3[1].m_pfnProxied + 4),
    newSize: v24);
  v11 = v24;
  if ( v24 > i )
  {
    v12 = (_DWORD *)(DWORD1(v3[1].m_pfnProxied) + 4 * i);
    v13 = v24 - i;
    if ( v24 != i )
    {
      do
      {
        if ( v12 != nullptr )
          *v12 = 0;
        ++v12;
        --v13;
      }
      while ( v13 != 0 );
    }
  }
  i = 0;
  if ( v11 != 0 )
  {
    while ( 1 )
    {
      v19 = 2;
      v14 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v3, a3: 40, a4: &v19);
      v15 = v14;
      if ( v14 != nullptr )
      {
        *(_DWORD *)v14 = &GRefCountImplCore::`vftable';
        *((_DWORD *)v14 + 1) = 1;
        *(_DWORD *)v14 = &GFxAmpMemItem::`vftable';
        GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v14 + 8));
        v15[3] = 0;
        *((_WORD *)v15 + 8) = 0;
        v15[5] = 0;
        v15[6] = 0;
        v15[7] = 0;
        v15[8] = 0;
        v15[9] = 0;
        v19 = (int)v15;
      }
      else
      {
        v19 = 0;
      }
      v16 = DWORD1(v23[1].m_pfnProxied);
      v17 = *(IShaderAPI **)(v16 + 4 * i);
      v18 = (int *)(4 * i + v16);
      if ( v17 != nullptr )
        GRefCountImpl::Release(this: v17);
      *v18 = v19;
      GFxAmpMemItem::Read(this: *(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> **)(DWORD1(v23[1].m_pfnProxied) + 4 * i++));
      if ( i >= v24 )
        break;
      v3 = v23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101002B0
// Name: public: class GFxAmpCurrentState __near & GFxAmpCurrentState::operator=(class GFxAmpCurrentState const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpCurrentState::operator=(CCheckerboardTexture *this, int a2)
{
  unsigned int i; // ebx
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+0h] [ebp-Ch]
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+0h] [ebp-Ch]
  int v8; // [esp+0h] [ebp-Ch]
  int v9; // [esp+0h] [ebp-Ch]

  this->m_Color1 = *(color32_s *)(a2 + 8);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&this->m_Color2,
    src: (_DWORD *)(a2 + 12),
    a3: v4);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 1),
    src: (_DWORD *)(a2 + 16),
    a3: v5);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)this + 1,
    src: (_DWORD *)(a2 + 20),
    a3: v6);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 24),
    src: (_DWORD *)(a2 + 24),
    a3: v7);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 28),
    src: (_DWORD *)(a2 + 28),
    a3: v8);
  GArrayData<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy>::Resize(
    this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> *)(this + 2),
    newSize: *(_DWORD *)(a2 + 36));
  for ( i = 0; i < *((_DWORD *)this + 9); ++i )
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(4 * i + *((_DWORD *)this + 8)),
      src: (_DWORD *)(4 * i + *(_DWORD *)(a2 + 32)),
      a3: v9);
  *((float *)this + 11) = *(float *)(a2 + 44);
  *((float *)this + 12) = *(float *)(a2 + 48);
  *((float *)this + 13) = *(float *)(a2 + 52);
  *((float *)this + 14) = *(float *)(a2 + 56);
  *((_DWORD *)this + 16) = *(_DWORD *)(a2 + 64);
  *((_DWORD *)this + 17) = *(_DWORD *)(a2 + 68);
  *((_DWORD *)this + 18) = *(_DWORD *)(a2 + 72);
}

//------------------------------------------------------------------------------
// Address: 0x10100360
// Name: public: void GFxAmpCurrentState::Read(class GFile __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpCurrentState::Read(GFxAmpCurrentState *this, float a2, unsigned int a3)
{
  struct GFile *v3; // esi
  int (__thiscall *v4)(GFile *, unsigned __int8 *, int); // edx
  int (__thiscall *Read)(GFile *, unsigned __int8 *, int); // edx
  unsigned int v7; // ebx
  int (__thiscall *v8)(GFile *, unsigned __int8 *, int); // edx
  GString *v9; // ebx
  int (__thiscall *v10)(GFile *, unsigned __int8 *, int); // edx
  int (__thiscall *v11)(GFile *, unsigned __int8 *, int); // edx
  int (__thiscall *v12)(GFile *, unsigned __int8 *, int); // edx
  int (__thiscall *v13)(GFile *, unsigned __int8 *, int); // edx
  int (__thiscall *v14)(GFile *, unsigned __int8 *, int); // edx
  bool v15; // cf
  int (__thiscall *v16)(GFile *, unsigned __int8 *, int); // edx
  float v17; // ecx
  int (__thiscall *v18)(GFile *, unsigned __int8 *, int); // edx
  int v19; // [esp+Ch] [ebp-10h] BYREF
  float v20; // [esp+10h] [ebp-Ch]
  unsigned int v21; // [esp+14h] [ebp-8h] BYREF
  unsigned int v22; // [esp+18h] [ebp-4h]

  v3 = (struct GFile *)LODWORD(a2);
  v4 = *(int (__thiscall **)(GFile *, unsigned __int8 *, int))(*(_DWORD *)LODWORD(a2) + 40);
  v21 = 0;
  v4(this: (GFile *)LODWORD(a2), a2: (unsigned __int8 *)&v21, a3: 4);
  this->StateFlags = v21;
  readString(a1: v3, a2: &this->ConnectedApp);
  if ( a3 >= 5 )
    readString(a1: v3, a2: &this->ConnectedFile);
  readString(a1: v3, a2: &this->AaMode);
  readString(a1: v3, a2: &this->StrokeType);
  readString(a1: v3, a2: &this->CurrentLocale);
  Read = v3->Read;
  v21 = 0;
  Read(this: v3, a2: (unsigned __int8 *)&v21, a3: 4);
  v7 = v21;
  GArrayData<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy>::Resize(
    this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> *)&this->Locales,
    newSize: v21);
  v22 = 0;
  if ( v7 != 0 )
  {
    do
    {
      v8 = v3->Read;
      v9 = &this->Locales.Data.Data[v22];
      a2 = 0.0;
      v8(this: v3, (unsigned __int8 *)&a2, a3: 4);
      if ( a2 != 0.0 )
      {
        v20 = a2;
        do
        {
          v10 = v3->Read;
          HIBYTE(a2) = 0;
          v10(this: v3, a2: (unsigned __int8 *)&a2 + 3, a3: 1);
          GString::AppendChar(this: (unsigned int *)v9, result: (CImagePacker *)SHIBYTE(a2));
          --LODWORD(v20);
        }
        while ( v20 != 0.0 );
      }
      ++v22;
    }
    while ( v22 < v21 );
  }
  v11 = v3->Read;
  a2 = 0.0;
  v11(this: v3, (unsigned __int8 *)&a2, a3: 4);
  this->CurveTolerance = a2;
  v12 = v3->Read;
  a2 = 0.0;
  v12(this: v3, (unsigned __int8 *)&a2, a3: 4);
  this->CurveToleranceMin = a2;
  v13 = v3->Read;
  a2 = 0.0;
  v13(this: v3, (unsigned __int8 *)&a2, a3: 4);
  this->CurveToleranceMax = a2;
  v14 = v3->Read;
  a2 = 0.0;
  v14(this: v3, (unsigned __int8 *)&a2, a3: 4);
  v15 = a3 < 0xA;
  this->CurveToleranceStep = a2;
  if ( !v15 )
  {
    v16 = v3->Read;
    v19 = 0;
    v20 = 0.0;
    v16(this: v3, a2: (unsigned __int8 *)&v19, a3: 8);
    v17 = v20;
    LODWORD(this->CurrentFileId) = v19;
    *((float *)&this->CurrentFileId + 1) = v17;
    v18 = v3->Read;
    a3 = 0;
    v18(this: v3, a2: (unsigned __int8 *)&a3, a3: 4);
    this->CurrentLineNumber = a3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100510
// Name: public: void GFxAmpProfileFrame::Write(class GFile __near &,unsigned long)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpProfileFrame::Write(
        CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> *str,
        CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> >::NodeColor_t version)
{
  ID3D11DeviceContext *v3; // esi
  void (__thiscall *v4)(UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> *, unsigned int **, int); // edx
  unsigned int *m_nAllocationCount; // eax
  int m_nGrowSize; // ecx
  void (__stdcall *PSSetShader)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v9)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v10)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v11)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v12)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v13)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v14)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v15)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v16)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v17)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v18)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v19)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v20)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v21)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v22)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v23)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v24)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v25)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v26)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v27)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v28)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v29)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v30)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v31)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v32)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v33)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v34)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v35)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v36)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v37)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  void (__stdcall *v38)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  unsigned int i; // ebx
  ID3D11DeviceContext v40; // eax
  unsigned int j; // ebx
  void (__stdcall *v42)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> >::NodeColor_t v43; // ebx
  void (__stdcall *v44)(ID3D11DeviceContext *, ID3D11PixelShader *, ID3D11ClassInstance *const *, unsigned int); // edx
  unsigned int k; // ebx
  int v46; // eax
  unsigned int *v47; // ecx
  int v48; // edx
  ID3D11DeviceContext v49; // eax
  __int128 v50; // [esp-4h] [ebp-18h]
  __int128 v51; // [esp-4h] [ebp-18h]
  __int128 v52; // [esp-4h] [ebp-18h]
  unsigned int *v53; // [esp+Ch] [ebp-8h] BYREF
  int v54; // [esp+10h] [ebp-4h]

  v3 = (ID3D11DeviceContext *)str;
  v4 = *(void (__thiscall **)(UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> *, unsigned int **, int))(*(_DWORD *)&str->m_Left + 36);
  m_nAllocationCount = (unsigned int *)this->m_Elements.m_nAllocationCount;
  m_nGrowSize = this->m_Elements.m_nGrowSize;
  v53 = m_nAllocationCount;
  v54 = m_nGrowSize;
  v4(a1: str, a2: &v53, a3: 8);
  PSSetShader = v3->PSSetShader;
  str = *(UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)&this->m_Root;
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))PSSetShader)(
    a1: v3,
    a2: &str,
    a3: 4);
  v9 = v3->PSSetShader;
  str = *(UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)&this->m_FirstFree;
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v9)(
    a1: v3,
    a2: &str,
    a3: 4);
  v10 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 8);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v10)(
    a1: v3,
    a2: &str,
    a3: 4);
  v11 = v3->PSSetShader;
  str = this->m_pElements;
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v11)(
    a1: v3,
    a2: &str,
    a3: 4);
  v12 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 7);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v12)(
    a1: v3,
    a2: &str,
    a3: 4);
  v13 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 9);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v13)(
    a1: v3,
    a2: &str,
    a3: 4);
  v14 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 10);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v14)(
    a1: v3,
    a2: &str,
    a3: 4);
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 11);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v3->PSSetShader)(
    a1: v3,
    a2: &str,
    a3: 4);
  v15 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 12);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v15)(
    a1: v3,
    a2: &str,
    a3: 4);
  v16 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 13);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v16)(
    a1: v3,
    a2: &str,
    a3: 4);
  v17 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 14);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v17)(
    a1: v3,
    a2: &str,
    a3: 4);
  v18 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 15);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v18)(
    a1: v3,
    a2: &str,
    a3: 4);
  v19 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 16);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v19)(
    a1: v3,
    a2: &str,
    a3: 4);
  v20 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 17);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v20)(
    a1: v3,
    a2: &str,
    a3: 4);
  v21 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 18);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v21)(
    a1: v3,
    a2: &str,
    a3: 4);
  v22 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 19);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v22)(
    a1: v3,
    a2: &str,
    a3: 4);
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 20);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v3->PSSetShader)(
    a1: v3,
    a2: &str,
    a3: 4);
  v23 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 21);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v23)(
    a1: v3,
    a2: &str,
    a3: 4);
  v24 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 22);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v24)(
    a1: v3,
    a2: &str,
    a3: 4);
  v25 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 23);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v25)(
    a1: v3,
    a2: &str,
    a3: 4);
  v26 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 24);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v26)(
    a1: v3,
    a2: &str,
    a3: 4);
  v27 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 25);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v27)(
    a1: v3,
    a2: &str,
    a3: 4);
  v28 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 26);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v28)(
    a1: v3,
    a2: &str,
    a3: 4);
  v29 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 27);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v29)(
    a1: v3,
    a2: &str,
    a3: 4);
  v30 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 28);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v30)(
    a1: v3,
    a2: &str,
    a3: 4);
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 29);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v3->PSSetShader)(
    a1: v3,
    a2: &str,
    a3: 4);
  v31 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 30);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v31)(
    a1: v3,
    a2: &str,
    a3: 4);
  v32 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 31);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v32)(
    a1: v3,
    a2: &str,
    a3: 4);
  v33 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 32);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v33)(
    a1: v3,
    a2: &str,
    a3: 4);
  v34 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 33);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v34)(
    a1: v3,
    a2: &str,
    a3: 4);
  v35 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 34);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v35)(
    a1: v3,
    a2: &str,
    a3: 4);
  v36 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 35);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v36)(
    a1: v3,
    a2: &str,
    a3: 4);
  v37 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 36);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v37)(
    a1: v3,
    a2: &str,
    a3: 4);
  v38 = v3->PSSetShader;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 37);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v38)(
    a1: v3,
    a2: &str,
    a3: 4);
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 39);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v3->PSSetShader)(
    a1: v3,
    a2: &str,
    a3: 4);
  for ( i = 0; i < *((_DWORD *)this + 39); ++i )
    GFxMovieStats::Write(
      a1: *(_DWORD *)(*((_DWORD *)this + 38) + 4 * i),
      this: v3,
      str: version,
      version: DWORD1(v50),
      a5: (ID3D11Buffer **)DWORD2(v50),
      a6: (unsigned int *)HIDWORD(v50),
      a7: v53);
  v40.__vftable = v3->__vftable;
  str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 42);
  ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v40.PSSetShader)(
    a1: v3,
    a2: &str,
    a3: 4);
  for ( j = 0; j < *((_DWORD *)this + 42); ++j )
  {
    v42 = v3->PSSetShader;
    str = *(UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)(*((_DWORD *)this + 41) + 4 * j);
    ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v42)(
      a1: v3,
      a2: &str,
      a3: 4);
  }
  v43 = version;
  if ( (unsigned int)version >= 9 )
  {
    v44 = v3->PSSetShader;
    str = *((UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **)this + 45);
    ((void (__thiscall *)(ID3D11DeviceContext *, UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> **, int))v44)(
      a1: v3,
      a2: &str,
      a3: 4);
    for ( k = 0; k < *((_DWORD *)this + 45); ++k )
    {
      v46 = *((_DWORD *)this + 44);
      v47 = *(unsigned int **)(v46 + 8 * k);
      v48 = *(_DWORD *)(v46 + 8 * k + 4);
      v49.__vftable = v3->__vftable;
      v53 = v47;
      v54 = v48;
      ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int **, int))v49.PSSetShader)(a1: v3, a2: &v53, a3: 8);
    }
    v43 = version;
  }
  LODWORD(v50) = v43;
  GFxAmpMemItem::Write(
    this: *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> **)this
    + 47),
    str: (CMatRenderContextBase *)v3,
    version: v50);
  LODWORD(v51) = v43;
  GFxAmpMemItem::Write(
    this: *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> **)this
    + 48),
    str: (CMatRenderContextBase *)v3,
    version: v51);
  if ( (unsigned int)v43 >= 3 )
  {
    LODWORD(v52) = v43;
    GFxAmpMemItem::Write(
      this: *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> **)this
      + 49),
      str: (CMatRenderContextBase *)v3,
      version: v52);
  }
  if ( (unsigned int)v43 >= 7 )
  {
    LODWORD(v52) = v43;
    GFxAmpMemItem::Write(
      this: *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> **)this
      + 50),
      str: (CMatRenderContextBase *)v3,
      version: v52);
  }
  if ( (unsigned int)v43 < 8 )
    GFxAmpMemFragReport::Write(
      this: *((CUtlVector<virtualsequence_t,CUtlMemory<virtualsequence_t,int> > **)this + 51),
      str: (virtualsequence_t *)v3,
      version: v43);
}

//------------------------------------------------------------------------------
// Address: 0x10100960
// Name: public: GFxAmpCurrentState::GFxAmpCurrentState(void)
// Source: json
//------------------------------------------------------------------------------
GFxAmpCurrentState *__thiscall GFxAmpCurrentState::GFxAmpCurrentState(GFxAmpCurrentState *this)
{
  this->__vftable = (GFxAmpCurrentState_vtbl *)&GRefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (GFxAmpCurrentState_vtbl *)&GFxAmpCurrentState::`vftable';
  this->StateFlags = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)&this->ConnectedApp);
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)&this->ConnectedFile);
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)&this->AaMode);
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)&this->StrokeType);
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)&this->CurrentLocale);
  this->Locales.Data.Data = nullptr;
  this->Locales.Data.Size = 0;
  this->Locales.Data.Policy.Capacity = 0;
  this->CurveTolerance = 0.0;
  this->CurveToleranceMin = 0.0;
  this->CurrentFileId = 0;
  this->CurveToleranceMax = 0.0;
  this->CurrentLineNumber = 0;
  this->CurveToleranceStep = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10100A00
// Name: public: GFxAmpProfileFrame::GFxAmpProfileFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpProfileFrame::GFxAmpProfileFrame(
        CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  char *v2; // eax
  char *v3; // edi
  IShaderAPI *v4; // ecx
  char *v5; // eax
  char *v6; // edi
  IShaderAPI *v7; // ecx
  char *v8; // eax
  char *v9; // edi
  IShaderAPI *v10; // ecx
  char *v11; // eax
  char *v12; // edi
  IShaderAPI *v13; // ecx
  _DWORD *v14; // eax
  _DWORD *v15; // edi
  IShaderAPI *v16; // ecx
  int v17; // [esp+Ch] [ebp-14h] BYREF
  int v18; // [esp+10h] [ebp-10h] BYREF
  int v19; // [esp+14h] [ebp-Ch] BYREF
  int v20; // [esp+18h] [ebp-8h] BYREF
  int v21; // [esp+1Ch] [ebp-4h] BYREF

  this->m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))&GRefCountImplCore::`vftable';
  this->m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> *)1;
  this->m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))&GFxAmpProfileFrame::`vftable';
  this->m_Elements.m_nAllocationCount = 0;
  this->m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&this->m_Root = 0;
  *(_DWORD *)&this->m_FirstFree = 0;
  this->m_pElements = nullptr;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 40) = 0;
  *((_DWORD *)this + 41) = 0;
  *((_DWORD *)this + 42) = 0;
  *((_DWORD *)this + 43) = 0;
  *((_DWORD *)this + 44) = 0;
  *((_DWORD *)this + 45) = 0;
  *((_DWORD *)this + 46) = 0;
  *((_DWORD *)this + 47) = 0;
  *((_DWORD *)this + 48) = 0;
  *((_DWORD *)this + 49) = 0;
  *((_DWORD *)this + 50) = 0;
  *((_DWORD *)this + 51) = 0;
  v21 = 2;
  v2 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 40, a4: &v21);
  v3 = v2;
  if ( v2 != nullptr )
  {
    *(_DWORD *)v2 = &GRefCountImplCore::`vftable';
    *((_DWORD *)v2 + 1) = 1;
    *(_DWORD *)v2 = &GFxAmpMemItem::`vftable';
    GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v2 + 8));
    *((_DWORD *)v3 + 3) = 0;
    *((_WORD *)v3 + 8) = 0;
    *((_DWORD *)v3 + 5) = 0;
    *((_DWORD *)v3 + 6) = 0;
    *((_DWORD *)v3 + 7) = 0;
    *((_DWORD *)v3 + 8) = 0;
    *((_DWORD *)v3 + 9) = 0;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = *((IShaderAPI **)this + 47);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  *((_DWORD *)this + 47) = v3;
  v20 = 2;
  v5 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 40, a4: &v20);
  v6 = v5;
  if ( v5 != nullptr )
  {
    *(_DWORD *)v5 = &GRefCountImplCore::`vftable';
    *((_DWORD *)v5 + 1) = 1;
    *(_DWORD *)v5 = &GFxAmpMemItem::`vftable';
    GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v5 + 8));
    *((_DWORD *)v6 + 3) = 0;
    *((_WORD *)v6 + 8) = 0;
    *((_DWORD *)v6 + 5) = 0;
    *((_DWORD *)v6 + 6) = 0;
    *((_DWORD *)v6 + 7) = 0;
    *((_DWORD *)v6 + 8) = 0;
    *((_DWORD *)v6 + 9) = 0;
  }
  else
  {
    v6 = nullptr;
  }
  v7 = *((IShaderAPI **)this + 48);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  *((_DWORD *)this + 48) = v6;
  v19 = 2;
  v8 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 40, a4: &v19);
  v9 = v8;
  if ( v8 != nullptr )
  {
    *(_DWORD *)v8 = &GRefCountImplCore::`vftable';
    *((_DWORD *)v8 + 1) = 1;
    *(_DWORD *)v8 = &GFxAmpMemItem::`vftable';
    GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v8 + 8));
    *((_DWORD *)v9 + 3) = 0;
    *((_WORD *)v9 + 8) = 0;
    *((_DWORD *)v9 + 5) = 0;
    *((_DWORD *)v9 + 6) = 0;
    *((_DWORD *)v9 + 7) = 0;
    *((_DWORD *)v9 + 8) = 0;
    *((_DWORD *)v9 + 9) = 0;
  }
  else
  {
    v9 = nullptr;
  }
  v10 = *((IShaderAPI **)this + 49);
  if ( v10 != nullptr )
    GRefCountImpl::Release(this: v10);
  *((_DWORD *)this + 49) = v9;
  v18 = 2;
  v11 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 40, a4: &v18);
  v12 = v11;
  if ( v11 != nullptr )
  {
    *(_DWORD *)v11 = &GRefCountImplCore::`vftable';
    *((_DWORD *)v11 + 1) = 1;
    *(_DWORD *)v11 = &GFxAmpMemItem::`vftable';
    GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v11 + 8));
    *((_DWORD *)v12 + 3) = 0;
    *((_WORD *)v12 + 8) = 0;
    *((_DWORD *)v12 + 5) = 0;
    *((_DWORD *)v12 + 6) = 0;
    *((_DWORD *)v12 + 7) = 0;
    *((_DWORD *)v12 + 8) = 0;
    *((_DWORD *)v12 + 9) = 0;
  }
  else
  {
    v12 = nullptr;
  }
  v13 = *((IShaderAPI **)this + 50);
  if ( v13 != nullptr )
    GRefCountImpl::Release(this: v13);
  *((_DWORD *)this + 50) = v12;
  v17 = 2;
  v14 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 24, a4: &v17);
  if ( v14 != nullptr )
  {
    *v14 = &GRefCountImplCore::`vftable';
    v14[1] = 1;
    *v14 = &GFxAmpMemFragReport::`vftable';
    v14[2] = 0;
    v14[3] = 0;
    v14[4] = 0;
    v14[5] = 0;
    v15 = v14;
  }
  else
  {
    v15 = nullptr;
  }
  v16 = *((IShaderAPI **)this + 51);
  if ( v16 != nullptr )
    GRefCountImpl::Release(this: v16);
  *((_DWORD *)this + 51) = v15;
}

//------------------------------------------------------------------------------
// Address: 0x10100D00
// Name: public: virtual GFxAmpProfileFrame::~GFxAmpProfileFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpProfileFrame::~GFxAmpProfileFrame(
        CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  IShaderAPI *v2; // ecx
  IShaderAPI *v3; // ecx
  IShaderAPI *v4; // ecx
  IShaderAPI *v5; // ecx
  IShaderAPI *v6; // ecx
  int v7; // eax
  IShaderAPI **v8; // edi
  int v9; // ebx

  v2 = *((IShaderAPI **)this + 51);
  if ( v2 != nullptr )
    GRefCountImpl::Release(this: v2);
  v3 = *((IShaderAPI **)this + 50);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  v4 = *((IShaderAPI **)this + 49);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  v5 = *((IShaderAPI **)this + 48);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  v6 = *((IShaderAPI **)this + 47);
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 44));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 41));
  v7 = *((_DWORD *)this + 39);
  v8 = (IShaderAPI **)(*((_DWORD *)this + 38) + 4 * v7 - 4);
  if ( v7 != 0 )
  {
    v9 = *((_DWORD *)this + 39);
    do
    {
      if ( *v8 != nullptr )
        GRefCountImpl::Release(this: *v8);
      --v8;
      --v9;
    }
    while ( v9 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 38));
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10100E40
// Name: public: void GFxAmpMovieFunctionStats::Read(class GFile __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMovieFunctionStats::Read(
        CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> *this,
        UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *str,
        unsigned int version)
{
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *v3; // esi
  const char *pShaderName; // edx
  IShaderAPI *j; // edi
  unsigned int v7; // eax
  int *p_m_nGrowSize; // ebx
  const char *v9; // edx
  char *v10; // eax
  char *v11; // eax
  const char *v12; // edx
  const char *v13; // edx
  char *v14; // eax
  const char *v15; // edx
  const char *v16; // edx
  IShaderAPI *v17; // eax
  IShaderAPI *v18; // ebx
  const char *v19; // edx
  const char *v20; // edx
  const char *v21; // edx
  bool v22; // cf
  const char *v23; // edx
  IShaderAPI *v24; // ecx
  const char *v25; // edx
  int *v26[2]; // [esp+Ch] [ebp-60h] BYREF
  unsigned __int64 iKey; // [esp+14h] [ebp-58h] BYREF
  IShaderAPI *v28; // [esp+1Ch] [ebp-50h] BYREF
  IShaderAPI *v29; // [esp+20h] [ebp-4Ch]
  unsigned __int64 v30; // [esp+24h] [ebp-48h] BYREF
  int v31; // [esp+2Ch] [ebp-40h] BYREF
  int v32; // [esp+30h] [ebp-3Ch]
  int v33; // [esp+34h] [ebp-38h] BYREF
  int v34; // [esp+38h] [ebp-34h]
  int v35; // [esp+3Ch] [ebp-30h] BYREF
  int v36; // [esp+40h] [ebp-2Ch]
  int v37; // [esp+44h] [ebp-28h] BYREF
  int i; // [esp+48h] [ebp-24h]
  IShaderAPI *v39; // [esp+4Ch] [ebp-20h] BYREF
  CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> *v40; // [esp+50h] [ebp-1Ch]
  IShaderAPI *v41; // [esp+54h] [ebp-18h] BYREF
  IShaderAPI *v42; // [esp+58h] [ebp-14h] BYREF
  IShaderAPI *v43; // [esp+5Ch] [ebp-10h] BYREF
  int v44; // [esp+60h] [ebp-Ch] BYREF
  IShaderAPI_vtbl *v45; // [esp+64h] [ebp-8h] BYREF
  unsigned int v46; // [esp+68h] [ebp-4h] BYREF

  v3 = str;
  pShaderName = str->m_Element[2].pShaderName;
  j = nullptr;
  v40 = this;
  v46 = 0;
  ((void (__thiscall *)(UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *, unsigned int *, int))pShaderName)(
    a1: str,
    a2: &v46,
    a3: 4);
  v7 = v46;
  p_m_nGrowSize = &this->m_nGrowSize;
  if ( v46 >= p_m_nGrowSize[1] )
  {
    if ( v46 < p_m_nGrowSize[2] )
      goto LABEL_7;
    GArrayDataBase<GFxAmpMemSegment,GAllocatorLH<GFxAmpMemSegment,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)p_m_nGrowSize,
      result: (mstudiobonecontroller_t *)p_m_nGrowSize,
      newCapacity: v46 + (v46 >> 2));
  }
  else
  {
    if ( v46 >= (unsigned int)p_m_nGrowSize[2] >> 1 )
      goto LABEL_7;
    GArrayDataBase<GFxAmpMemSegment,GAllocatorLH<GFxAmpMemSegment,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)p_m_nGrowSize,
      result: (mstudiobonecontroller_t *)p_m_nGrowSize,
      newCapacity: v46);
  }
  v7 = v46;
LABEL_7:
  p_m_nGrowSize[1] = v7;
  if ( v7 != 0 )
  {
    str = (UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *)v46;
    do
    {
      v9 = v3->m_Element[2].pShaderName;
      v35 = 0;
      v36 = 0;
      ((void (__thiscall *)(UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *, int *, int))v9)(
        a1: v3,
        a2: &v35,
        a3: 8);
      v10 = (char *)*p_m_nGrowSize;
      *(_DWORD *)&v10[(_DWORD)j] = v35;
      *(_DWORD *)&v10[(_DWORD)j + 4] = v36;
      v33 = 0;
      v34 = 0;
      ((void (__thiscall *)(UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *, int *, int))v3->m_Element[2].pShaderName)(
        a1: v3,
        a2: &v33,
        a3: 8);
      v11 = (char *)*p_m_nGrowSize;
      *(_DWORD *)&v11[(_DWORD)j + 8] = v33;
      *(_DWORD *)&v11[(_DWORD)j + 12] = v34;
      v12 = v3->m_Element[2].pShaderName;
      v45 = nullptr;
      ((void (__thiscall *)(UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *, IShaderAPI_vtbl **, int))v12)(
        a1: v3,
        a2: &v45,
        a3: 4);
      *(IShaderAPI_vtbl **)((char *)&j[4].__vftable + *p_m_nGrowSize) = v45;
      v13 = v3->m_Element[2].pShaderName;
      v31 = 0;
      v32 = 0;
      ((void (__thiscall *)(UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *, int *, int))v13)(
        a1: v3,
        a2: &v31,
        a3: 8);
      v14 = (char *)*p_m_nGrowSize;
      *(_DWORD *)&v14[(_DWORD)j + 24] = v31;
      *(_DWORD *)&v14[(_DWORD)j + 28] = v32;
      j += 8;
      str = (UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *)((char *)str - 1);
    }
    while ( str != nullptr );
    j = nullptr;
  }
  v15 = v3->m_Element[2].pShaderName;
  v44 = 0;
  ((void (__thiscall *)(UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *, int *, int))v15)(
    a1: v3,
    a2: &v44,
    a3: 4);
  if ( v44 != 0 )
  {
    for ( i = v44; i != 0; --i )
    {
      v16 = v3->m_Element[2].pShaderName;
      LODWORD(v30) = j;
      HIDWORD(v30) = j;
      ((void (__thiscall *)(UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *, unsigned __int64 *, int))v16)(
        a1: v3,
        a2: &v30,
        a3: 8);
      iKey = v30;
      v37 = 2;
      v17 = (IShaderAPI *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v40, a3: 32, a4: &v37);
      v18 = v17;
      if ( v17 == j )
      {
        v18 = nullptr;
      }
      else
      {
        v17->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
        v17[1].__vftable = (IShaderAPI_vtbl *)1;
        v17->__vftable = (IShaderAPI_vtbl *)&GFxAmpFunctionDesc::`vftable';
        GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)&v17[2]);
      }
      v19 = v3->m_Element[2].pShaderName;
      v43 = j;
      ((void (__thiscall *)(UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *, IShaderAPI **, int))v19)(
        a1: v3,
        a2: &v43,
        a3: 4);
      if ( v43 > j )
      {
        for ( j = v43; j != nullptr; j = (IShaderAPI *)((char *)j - 1) )
        {
          v20 = v3->m_Element[2].pShaderName;
          HIBYTE(str) = 0;
          ((void (__thiscall *)(UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *, char *, int))v20)(
            a1: v3,
            a2: (char *)&str + 3,
            a3: 1);
          GString::AppendChar(this: (unsigned int *)&v18[2], result: (CImagePacker *)SHIBYTE(str));
        }
      }
      v21 = v3->m_Element[2].pShaderName;
      v42 = j;
      ((void (__thiscall *)(UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *, IShaderAPI **, int))v21)(
        a1: v3,
        a2: &v42,
        a3: 4);
      v22 = version < 9;
      v18[3].__vftable = (IShaderAPI_vtbl *)v42;
      if ( !v22 )
      {
        v23 = v3->m_Element[2].pShaderName;
        v28 = j;
        v29 = j;
        ((void (__thiscall *)(UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *, IShaderAPI **, int))v23)(
          a1: v3,
          a2: &v28,
          a3: 8);
        v24 = v29;
        v18[4].__vftable = (IShaderAPI_vtbl *)v28;
        v18[5].__vftable = (IShaderAPI_vtbl *)v24;
        v25 = v3->m_Element[2].pShaderName;
        v41 = j;
        ((void (__thiscall *)(UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *, IShaderAPI **, int))v25)(
          a1: v3,
          a2: &v41,
          a3: 4);
        v18[6].__vftable = (IShaderAPI_vtbl *)v41;
      }
      v26[0] = (int *)&iKey;
      v39 = v18;
      v26[1] = (int *)&v39;
      GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeRef>(
        a1: (CMeshBuilder *)&v40[1].m_nGrowSize,
        a2: (int)&v39,
        pheapAddr: (VertexCompressionType_t)&v40[1].m_nGrowSize,
        a4: v26);
      if ( v39 != j )
        GRefCountImpl::Release(this: v39);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101010A0
// Name: public: void MovieSourceLineStats::Read(class GFile __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __userpurge MovieSourceLineStats::Read(
        MovieSourceLineStats *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        CUtlMemory<CImagePacker,int> a4)
{
  CImagePacker *m_pMemory; // esi
  void (__thiscall *v6)(CImagePacker *, int *, int, int, int); // edx
  int m_nAllocationCount; // edi
  MovieSourceLineStats *v8; // ebx
  int v9; // edi
  char *v10; // eax
  void (__thiscall *v11)(CImagePacker *, int *, int); // edx
  void (__thiscall *v12)(CImagePacker *, int *, int); // edx
  char *v13; // eax
  void (__thiscall *v14)(CImagePacker *, int *, int); // edx
  int *v15; // edi
  void (__thiscall *v16)(CImagePacker *, int *, int); // edx
  void (__thiscall *v17)(CImagePacker *, int *, int); // edx
  int v18; // edx
  int j; // ebx
  void (__thiscall *v20)(CImagePacker *, char *, int); // edx
  void *v21; // ebx
  _DWORD v23[2]; // [esp+4h] [ebp-1Ch] BYREF
  int v24; // [esp+Ch] [ebp-14h] BYREF
  int v25; // [esp+10h] [ebp-10h]
  int v26; // [esp+14h] [ebp-Ch] BYREF
  int v27; // [esp+18h] [ebp-8h]
  MovieSourceLineStats *i; // [esp+1Ch] [ebp-4h]

  i = this;
  if ( a4.m_nAllocationCount >= 9u )
  {
    m_pMemory = a4.m_pMemory;
    v6 = *(void (__thiscall **)(CImagePacker *, int *, int, int, int))(a4.m_pMemory->m_MaxLightmapWidth + 40);
    a4.m_nAllocationCount = 0;
    v6(a1: a4.m_pMemory, a2: &a4.m_nAllocationCount, a3: 4, a4: a2, a5: a3);
    m_nAllocationCount = a4.m_nAllocationCount;
    v8 = this + 2;
    if ( a4.m_nAllocationCount >= *((_DWORD *)v8 + 1) )
    {
      if ( a4.m_nAllocationCount >= *((_DWORD *)v8 + 2) )
        GArrayDataBase<MovieSourceLineStats::SourceStats,GAllocatorLH<MovieSourceLineStats::SourceStats,2>,GArrayDefaultPolicy>::Reserve(
          this: (void **)v8,
          a2: v8,
          a3: a4.m_nAllocationCount + ((unsigned int)a4.m_nAllocationCount >> 2));
    }
    else if ( a4.m_nAllocationCount < *((_DWORD *)v8 + 2) >> 1 )
    {
      GArrayDataBase<MovieSourceLineStats::SourceStats,GAllocatorLH<MovieSourceLineStats::SourceStats,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)v8,
        a2: v8,
        a3: a4.m_nAllocationCount);
    }
    *((_DWORD *)v8 + 1) = m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      v9 = 0;
      a4.m_pMemory = (CImagePacker *)a4.m_nAllocationCount;
      do
      {
        v26 = 0;
        v27 = 0;
        (*(void (__thiscall **)(CImagePacker *, int *, int))(m_pMemory->m_MaxLightmapWidth + 40))(
          a1: m_pMemory,
          a2: &v26,
          a3: 8);
        v10 = (char *)*v8;
        *(_DWORD *)&v10[v9] = v26;
        *(_DWORD *)&v10[v9 + 4] = v27;
        v11 = *(void (__thiscall **)(CImagePacker *, int *, int))(m_pMemory->m_MaxLightmapWidth + 40);
        a4.m_nAllocationCount = 0;
        v11(a1: m_pMemory, a2: &a4.m_nAllocationCount, a3: 4);
        *(_DWORD *)(v9 + *v8 + 8) = a4.m_nAllocationCount;
        v12 = *(void (__thiscall **)(CImagePacker *, int *, int))(m_pMemory->m_MaxLightmapWidth + 40);
        v24 = 0;
        v25 = 0;
        v12(a1: m_pMemory, a2: &v24, a3: 8);
        v13 = (char *)*v8;
        *(_DWORD *)&v13[v9 + 16] = v24;
        *(_DWORD *)&v13[v9 + 20] = v25;
        v9 += 24;
        --a4.m_pMemory;
      }
      while ( a4.m_pMemory != nullptr );
    }
    v14 = *(void (__thiscall **)(CImagePacker *, int *, int))(m_pMemory->m_MaxLightmapWidth + 40);
    a4.m_nAllocationCount = 0;
    v14(a1: m_pMemory, a2: &a4.m_nAllocationCount, a3: 4);
    if ( a4.m_nAllocationCount != 0 )
    {
      v15 = (int *)(i + 5);
      v23[0] = &v26;
      v23[1] = &a4;
      for ( i = (MovieSourceLineStats *)a4.m_nAllocationCount; i != nullptr; i = (MovieSourceLineStats *)((char *)i - 1) )
      {
        v16 = *(void (__thiscall **)(CImagePacker *, int *, int))(m_pMemory->m_MaxLightmapWidth + 40);
        v24 = 0;
        v25 = 0;
        v16(a1: m_pMemory, a2: &v24, a3: 8);
        v27 = v25;
        v26 = v24;
        GString::GString(this: &a4);
        v17 = *(void (__thiscall **)(CImagePacker *, int *, int))(m_pMemory->m_MaxLightmapWidth + 40);
        a4.m_nAllocationCount = 0;
        v17(a1: m_pMemory, a2: &a4.m_nAllocationCount, a3: 4);
        for ( j = a4.m_nAllocationCount; j != 0; --j )
        {
          v20 = *(void (__thiscall **)(CImagePacker *, char *, int))(m_pMemory->m_MaxLightmapWidth + 40);
          HIBYTE(a4.m_nAllocationCount) = 0;
          v20(a1: m_pMemory, a2: (char *)&a4.m_nAllocationCount + 3, a3: 1);
          GString::AppendChar(this: (unsigned int *)&a4, result: (CImagePacker *)SHIBYTE(a4.m_nAllocationCount));
        }
        GHashSetBase<GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeRef>(
          a1: v15,
          a2: v18,
          a3: v15,
          a4: v23);
        v21 = (void *)((int)a4.m_pMemory & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)a4.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v21);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101270
// Name: public: GFxMovieStats::GFxMovieStats(void)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFxMovieStats::GFxMovieStats(ID3D11DeviceContext *this)
{
  int v1; // ecx
  _DWORD *v2; // esi
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  IShaderAPI *v5; // ecx
  _DWORD *v6; // eax
  _DWORD *v7; // ebx
  IShaderAPI *v8; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // ebx
  IShaderAPI *v11; // ecx
  int v12; // [esp+Ch] [ebp-Ch] BYREF
  int v13; // [esp+10h] [ebp-8h] BYREF
  int v14; // [esp+14h] [ebp-4h] BYREF

  v2 = (_DWORD *)v1;
  *(_DWORD *)v1 = &GRefCountImplCore::`vftable';
  *(_DWORD *)(v1 + 4) = 1;
  *(_DWORD *)v1 = &GFxMovieStats::`vftable';
  *(_DWORD *)(v1 + 8) = 0;
  *(_DWORD *)(v1 + 12) = 0;
  *(_DWORD *)(v1 + 16) = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v1 + 20));
  v2[11] = 0;
  v2[12] = 0;
  v2[13] = 0;
  v2[14] = 0;
  v2[15] = 0;
  v2[16] = 0;
  v14 = 2;
  v3 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v2, a3: 20, a4: &v14);
  if ( v3 != nullptr )
  {
    *v3 = &GRefCountImplCore::`vftable';
    v3[1] = 1;
    *v3 = &GFxAmpMovieInstructionStats::`vftable';
    v3[2] = 0;
    v3[3] = 0;
    v3[4] = 0;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (IShaderAPI *)v2[14];
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  v2[14] = v4;
  v13 = 2;
  v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v2, a3: 24, a4: &v13);
  if ( v6 != nullptr )
  {
    *v6 = &GRefCountImplCore::`vftable';
    v6[1] = 1;
    *v6 = &GFxAmpMemFragReport::`vftable';
    v6[2] = 0;
    v6[3] = 0;
    v6[4] = 0;
    v6[5] = 0;
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  v8 = (IShaderAPI *)v2[15];
  if ( v8 != nullptr )
    GRefCountImpl::Release(this: v8);
  v2[15] = v7;
  v12 = 2;
  v9 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v2, a3: 24, a4: &v12);
  if ( v9 != nullptr )
  {
    *v9 = &GRefCountImplCore::`vftable';
    v9[1] = 1;
    *v9 = &MovieSourceLineStats::`vftable';
    v9[2] = 0;
    v9[3] = 0;
    v9[4] = 0;
    v9[5] = 0;
    v10 = v9;
  }
  else
  {
    v10 = nullptr;
  }
  v11 = (IShaderAPI *)v2[16];
  if ( v11 != nullptr )
    GRefCountImpl::Release(this: v11);
  v2[16] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x101013B0
// Name: public: virtual GFxMovieStats::~GFxMovieStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieStats::~GFxMovieStats(IShaderAPI *this)
{
  IShaderAPI *v2; // ecx
  IShaderAPI *v3; // ecx
  IShaderAPI *v4; // ecx
  int v5; // eax
  IShaderAPI **v6; // edi
  int v7; // ebx
  volatile LONG *v8; // edi

  v2 = *((IShaderAPI **)this + 16);
  if ( v2 != nullptr )
    GRefCountImpl::Release(this: v2);
  v3 = *((IShaderAPI **)this + 15);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  v4 = *((IShaderAPI **)this + 14);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  v5 = *((_DWORD *)this + 12);
  v6 = (IShaderAPI **)(*((_DWORD *)this + 11) + 4 * v5 - 4);
  if ( v5 != 0 )
  {
    v7 = *((_DWORD *)this + 12);
    do
    {
      if ( *v6 != nullptr )
        GRefCountImpl::Release(this: *v6);
      --v6;
      --v7;
    }
    while ( v7 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 11));
  v8 = (volatile LONG *)(*(_DWORD *)(this + 5) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v8 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v8);
  GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x101014C0
// Name: public: void GFxMovieStats::Read(class GFile __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieStats::Read(_DWORD *ecx0, ID3D11DeviceContext *this, ID3D11InputLayout **str)
{
  ID3D11DeviceContext *v3; // esi
  void (__stdcall *PSSetSamplers)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  int v5; // edi
  void (__stdcall *v6)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v7)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  bool v8; // cf
  void (__stdcall *v9)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v10)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v11)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v12)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v13)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  char *v14; // ecx
  _DWORD *v15; // eax
  char *v16; // eax
  ID3D11DeviceContext *v17; // edi
  int v18; // edi
  unsigned int v19; // ebx
  IShaderAPI *v20; // ecx
  void (__stdcall *v21)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  unsigned int v22; // eax
  ID3D11InputLayout **v23; // ebx
  CUtlMemory<CImagePacker,int> v24; // [esp-8h] [ebp-44h]
  int v25; // [esp+Ch] [ebp-30h] BYREF
  ID3D11DeviceContext *v26; // [esp+10h] [ebp-2Ch] BYREF
  int v27; // [esp+14h] [ebp-28h] BYREF
  float v28; // [esp+18h] [ebp-24h] BYREF
  float v29; // [esp+1Ch] [ebp-20h] BYREF
  float v30; // [esp+20h] [ebp-1Ch] BYREF
  int v31; // [esp+24h] [ebp-18h] BYREF
  int v32; // [esp+28h] [ebp-14h] BYREF
  int v33; // [esp+2Ch] [ebp-10h] BYREF
  int v34; // [esp+30h] [ebp-Ch] BYREF
  unsigned int i; // [esp+34h] [ebp-8h]
  _DWORD *v36; // [esp+38h] [ebp-4h]

  v3 = this;
  PSSetSamplers = this->PSSetSamplers;
  v5 = (int)ecx0;
  v36 = ecx0;
  v34 = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, int *, int))PSSetSamplers)(a1: this, a2: &v34, a3: 4);
  *(_DWORD *)(v5 + 8) = v34;
  v6 = v3->PSSetSamplers;
  v33 = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, int *, int))v6)(a1: v3, a2: &v33, a3: 4);
  *(_DWORD *)(v5 + 12) = v33;
  v7 = v3->PSSetSamplers;
  v32 = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, int *, int))v7)(a1: v3, a2: &v32, a3: 4);
  v8 = (unsigned int)str < 4;
  *(_DWORD *)(v5 + 16) = v32;
  if ( !v8 )
  {
    readString(a1: (struct GFile *)v3, a2: (struct GString *)(v5 + 20));
    v9 = v3->PSSetSamplers;
    v31 = 0;
    ((void (__thiscall *)(ID3D11DeviceContext *, int *, int))v9)(a1: v3, a2: &v31, a3: 4);
    v30 = 0.0;
    *(_DWORD *)(v5 + 24) = v31;
    ((void (__thiscall *)(ID3D11DeviceContext *, float *, int))v3->PSSetSamplers)(a1: v3, a2: &v30, a3: 4);
    *(float *)(v5 + 28) = v30;
    v10 = v3->PSSetSamplers;
    v29 = 0.0;
    ((void (__thiscall *)(ID3D11DeviceContext *, float *, int))v10)(a1: v3, a2: &v29, a3: 4);
    *(float *)(v5 + 32) = v29;
    v11 = v3->PSSetSamplers;
    v28 = 0.0;
    ((void (__thiscall *)(ID3D11DeviceContext *, float *, int))v11)(a1: v3, a2: &v28, a3: 4);
    *(float *)(v5 + 36) = v28;
    v12 = v3->PSSetSamplers;
    v27 = 0;
    ((void (__thiscall *)(ID3D11DeviceContext *, int *, int))v12)(a1: v3, a2: &v27, a3: 4);
    *(_DWORD *)(v5 + 40) = v27;
  }
  if ( (unsigned int)str >= 6 )
  {
    v13 = v3->PSSetSamplers;
    this = nullptr;
    ((void (__thiscall *)(ID3D11DeviceContext *, ID3D11DeviceContext **, int))v13)(a1: v3, a2: &this, a3: 4);
    v26 = *(ID3D11DeviceContext **)(v5 + 48);
    GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (GRenderer::CachedData *)(v5 + 44),
      result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)(v5 + 44),
      newSize: (unsigned int)this);
    if ( this > v26 )
    {
      v14 = (char *)((char *)this - (char *)v26);
      v15 = (_DWORD *)(*(_DWORD *)(v5 + 44) + 4 * (_DWORD)v26);
      if ( this != v26 )
      {
        do
        {
          if ( v15 != nullptr )
            *v15 = 0;
          ++v15;
          --v14;
        }
        while ( v14 != nullptr );
      }
    }
    i = 0;
    if ( this != nullptr )
    {
      do
      {
        v25 = 2;
        v16 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v5, a3: 16, a4: &v25);
        v17 = (ID3D11DeviceContext *)v16;
        if ( v16 != nullptr )
        {
          *(_DWORD *)v16 = &GRefCountImplCore::`vftable';
          *((_DWORD *)v16 + 1) = 1;
          *(_DWORD *)v16 = &GFxAmpFunctionDesc::`vftable';
          GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v16 + 8));
          v26 = v17;
        }
        else
        {
          v26 = nullptr;
        }
        v18 = v36[11];
        v19 = 4 * i;
        v20 = *(IShaderAPI **)(v18 + 4 * i);
        if ( v20 != nullptr )
          GRefCountImpl::Release(this: v20);
        v8 = (unsigned int)str < 0xB;
        *(_DWORD *)(v18 + v19) = v26;
        if ( v8 )
          GString::operator=(
            this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(*(_DWORD *)(v19 + v36[11]) + 8),
            a2: "Marker");
        else
          readString(a1: (struct GFile *)v3, a2: (struct GString *)(*(_DWORD *)(v19 + v36[11]) + 8));
        v21 = v3->PSSetSamplers;
        v26 = nullptr;
        ((void (__thiscall *)(ID3D11DeviceContext *, ID3D11DeviceContext **, int))v21)(a1: v3, a2: &v26, a3: 4);
        v5 = (int)v36;
        v22 = i + 1;
        *(_DWORD *)(*(_DWORD *)(v19 + v36[11]) + 12) = v26;
        i = v22;
      }
      while ( v22 < (unsigned int)this );
    }
  }
  GFxAmpMovieInstructionStats::Read(
    this: *(GFxAmpMovieInstructionStats **)(v5 + 56),
    str: (MaterialNonInteractiveMode_t)v3,
    a3: (unsigned int)str);
  v23 = str;
  GFxAmpMovieFunctionStats::Read(
    this: *(CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> **)(v5 + 60),
    str: (UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *)v3,
    version: (unsigned int)str);
  v24.m_nAllocationCount = (int)v23;
  v24.m_pMemory = (CImagePacker *)v3;
  MovieSourceLineStats::Read(this: *(MovieSourceLineStats **)(v5 + 64), a2: v5, a3: (int)v3, a4: v24);
}

//------------------------------------------------------------------------------
// Address: 0x10101720
// Name: public: void GFxAmpMemFragReport::Read(class GFile __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMemFragReport::Read(
        CUtlVector<virtualsequence_t,CUtlMemory<virtualsequence_t,int> > *this,
        const virtualsequence_t *str,
        unsigned int version)
{
  const virtualsequence_t *v3; // esi
  void (__thiscall *v4)(const virtualsequence_t *, unsigned int *, int); // edx
  unsigned int m_Size; // ecx
  unsigned int v7; // eax
  int *p_m_nGrowSize; // edi
  void (__thiscall *v9)(const virtualsequence_t *, unsigned int *, int); // edx
  void (__thiscall *v10)(const virtualsequence_t *, unsigned __int64 *, int); // edx
  char *v11; // eax
  char *v12; // edi
  void (__thiscall *v13)(const virtualsequence_t *, int *, int); // edx
  int v14; // ecx
  void (__thiscall *v15)(const virtualsequence_t *, unsigned int *, int); // edx
  void (__thiscall *v16)(const virtualsequence_t *, IShaderAPI **, int); // edx
  void (__thiscall *v17)(const virtualsequence_t *, char *, int); // edx
  int *v18[2]; // [esp+Ch] [ebp-3Ch] BYREF
  unsigned __int64 key; // [esp+14h] [ebp-34h] BYREF
  int v20; // [esp+1Ch] [ebp-2Ch] BYREF
  int v21; // [esp+20h] [ebp-28h]
  unsigned __int64 v22; // [esp+24h] [ebp-24h] BYREF
  int v23; // [esp+2Ch] [ebp-1Ch] BYREF
  unsigned int j; // [esp+30h] [ebp-18h]
  CUtlVector<virtualsequence_t,CUtlMemory<virtualsequence_t,int> > *v25; // [esp+34h] [ebp-14h]
  IShaderAPI *k; // [esp+38h] [ebp-10h] BYREF
  IShaderAPI *v27; // [esp+3Ch] [ebp-Ch] BYREF
  unsigned int i; // [esp+40h] [ebp-8h] BYREF
  unsigned int v29; // [esp+44h] [ebp-4h] BYREF

  v3 = str;
  v4 = *(void (__thiscall **)(const virtualsequence_t *, unsigned int *, int))(str->flags + 40);
  v25 = this;
  v29 = 0;
  v4(a1: str, a2: &v29, a3: 4);
  m_Size = this->m_Size;
  v7 = v29;
  p_m_nGrowSize = &this->m_Memory.m_nGrowSize;
  str = (const virtualsequence_t *)m_Size;
  if ( v29 >= m_Size )
  {
    if ( v29 < p_m_nGrowSize[2] )
      goto LABEL_7;
    GArrayDataBase<GFxAmpMemSegment,GAllocatorLH<GFxAmpMemSegment,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)p_m_nGrowSize,
      result: (mstudiobonecontroller_t *)p_m_nGrowSize,
      newCapacity: v29 + (v29 >> 2));
  }
  else
  {
    if ( v29 >= (unsigned int)p_m_nGrowSize[2] >> 1 )
      goto LABEL_7;
    GArrayDataBase<GFxAmpMemSegment,GAllocatorLH<GFxAmpMemSegment,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)p_m_nGrowSize,
      result: (mstudiobonecontroller_t *)p_m_nGrowSize,
      newCapacity: v29);
  }
  v7 = v29;
  m_Size = (unsigned int)str;
LABEL_7:
  p_m_nGrowSize[1] = v7;
  if ( v7 > m_Size )
  {
    GConstructorMov<GFxAmpMemSegment>::ConstructArray(a1: *p_m_nGrowSize + 32 * m_Size, a2: v7 - m_Size);
    v7 = v29;
  }
  if ( v7 != 0 )
  {
    str = nullptr;
    for ( i = v7; i != 0; --i )
    {
      GFxAmpMemSegment::Read(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,float),CFuncMemPolicyNone> *)((char *)str + *p_m_nGrowSize),
        a2: (int)v3,
        version);
      str += 2;
    }
  }
  v9 = *(void (__thiscall **)(const virtualsequence_t *, unsigned int *, int))(v3->flags + 40);
  version = 0;
  v9(a1: v3, a2: &version, a3: 4);
  if ( version != 0 )
  {
    for ( j = version; j != 0; --j )
    {
      v10 = *(void (__thiscall **)(const virtualsequence_t *, unsigned __int64 *, int))(v3->flags + 40);
      v22 = 0;
      v10(a1: v3, a2: &v22, a3: 8);
      key = v22;
      v23 = 2;
      v11 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v25, a3: 24, a4: &v23);
      v12 = v11;
      if ( v11 != nullptr )
      {
        *(_DWORD *)v11 = &GRefCountImplCore::`vftable';
        *((_DWORD *)v11 + 1) = 1;
        *(_DWORD *)v11 = &GFxAmpHeapInfo::`vftable';
        *((_DWORD *)v11 + 2) = 0;
        *((_DWORD *)v11 + 3) = 0;
        *((_DWORD *)v11 + 4) = 0;
        GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v11 + 20));
      }
      else
      {
        v12 = nullptr;
      }
      v13 = *(void (__thiscall **)(const virtualsequence_t *, int *, int))(v3->flags + 40);
      v20 = 0;
      v21 = 0;
      v13(a1: v3, a2: &v20, a3: 8);
      v14 = v21;
      *((_DWORD *)v12 + 2) = v20;
      *((_DWORD *)v12 + 3) = v14;
      v15 = *(void (__thiscall **)(const virtualsequence_t *, unsigned int *, int))(v3->flags + 40);
      i = 0;
      v15(a1: v3, a2: &i, a3: 4);
      *((_DWORD *)v12 + 4) = i;
      v16 = *(void (__thiscall **)(const virtualsequence_t *, IShaderAPI **, int))(v3->flags + 40);
      v27 = nullptr;
      v16(a1: v3, a2: &v27, a3: 4);
      if ( v27 != nullptr )
      {
        for ( k = v27; k != nullptr; k = (IShaderAPI *)((char *)k - 1) )
        {
          v17 = *(void (__thiscall **)(const virtualsequence_t *, char *, int))(v3->flags + 40);
          HIBYTE(str) = 0;
          v17(a1: v3, a2: (char *)&str + 3, a3: 1);
          GString::AppendChar(this: (unsigned int *)v12 + 5, result: (CImagePacker *)SHIBYTE(str));
        }
      }
      v18[0] = (int *)&key;
      k = (IShaderAPI *)v12;
      v18[1] = (int *)&k;
      GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeRef>(
        a1: (CMeshBuilder *)&v25[1],
        a2: (int)&k,
        pheapAddr: (VertexCompressionType_t)&v25[1],
        a4: v18);
      if ( k != nullptr )
        GRefCountImpl::Release(this: k);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101910
// Name: public: void GFxAmpProfileFrame::Read(class GFile __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpProfileFrame::Read(
        CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned int str,
        unsigned int version)
{
  ID3D11DeviceContext *v3; // esi
  void (__thiscall *v4)(unsigned int, int *, int); // edx
  int v6; // ecx
  void (__stdcall *PSSetSamplers)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v8)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v9)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v10)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v11)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v12)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  ID3D11DeviceContext_vtbl *v13; // edx
  void (__stdcall *v14)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v15)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v16)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v17)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v18)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v19)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v20)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  ID3D11DeviceContext_vtbl *v21; // edx
  void (__stdcall *v22)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v23)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v24)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v25)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v26)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v27)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v28)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  ID3D11DeviceContext_vtbl *v29; // edx
  void (__stdcall *v30)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v31)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v32)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v33)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v34)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v35)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v36)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  ID3D11DeviceContext_vtbl *v37; // edx
  void (__stdcall *v38)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v39)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v40)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  void (__stdcall *v41)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  unsigned int v42; // eax
  _DWORD *v43; // ecx
  unsigned int v44; // eax
  IShaderAPI **v45; // eax
  IShaderAPI *v46; // ecx
  ID3D11InputLayout **v47; // edx
  void (__stdcall *v48)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  unsigned int v49; // eax
  GRenderer::CachedData *v50; // ecx
  void (__stdcall *v51)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  unsigned int v52; // eax
  void (__stdcall *v53)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  unsigned int v54; // eax
  CStudioHdr *v55; // ecx
  void (__stdcall *v56)(ID3D11DeviceContext *, unsigned int, unsigned int, ID3D11SamplerState *const *); // edx
  unsigned int v57; // ecx
  int v58; // eax
  unsigned int v59; // ebx
  ID3D11DeviceContext *v60; // [esp+0h] [ebp-18h]
  int v61; // [esp+Ch] [ebp-Ch] BYREF
  IShaderAPI **v62; // [esp+10h] [ebp-8h]
  unsigned int v63; // [esp+14h] [ebp-4h] BYREF

  v3 = (ID3D11DeviceContext *)str;
  v4 = *(void (__thiscall **)(unsigned int, int *, int))(*(_DWORD *)str + 40);
  v61 = 0;
  v62 = nullptr;
  v4(a1: str, a2: &v61, a3: 8);
  v6 = (int)v62;
  this->m_Elements.m_nAllocationCount = v61;
  this->m_Elements.m_nGrowSize = v6;
  PSSetSamplers = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))PSSetSamplers)(a1: v3, a2: &str, a3: 4);
  *(_DWORD *)&this->m_Root = str;
  v8 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v8)(a1: v3, a2: &str, a3: 4);
  *(_DWORD *)&this->m_FirstFree = str;
  v9 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v9)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 8) = str;
  v10 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v10)(a1: v3, a2: &str, a3: 4);
  this->m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short> *)str;
  v11 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v11)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 7) = str;
  v12 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v12)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 9) = str;
  v13 = v3->__vftable;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v13->PSSetSamplers)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 10) = str;
  v14 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v14)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 11) = str;
  v15 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v15)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 12) = str;
  v16 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v16)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 13) = str;
  v17 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v17)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 14) = str;
  v18 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v18)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 15) = str;
  v19 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v19)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 16) = str;
  v20 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v20)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 17) = str;
  v21 = v3->__vftable;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v21->PSSetSamplers)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 18) = str;
  v22 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v22)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 19) = str;
  v23 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v23)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 20) = str;
  v24 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v24)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 21) = str;
  v25 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v25)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 22) = str;
  v26 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v26)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 23) = str;
  v27 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v27)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 24) = str;
  v28 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v28)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 25) = str;
  v29 = v3->__vftable;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v29->PSSetSamplers)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 26) = str;
  v30 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v30)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 27) = str;
  v31 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v31)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 28) = str;
  v32 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v32)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 29) = str;
  v33 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v33)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 30) = str;
  v34 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v34)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 31) = str;
  v35 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v35)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 32) = str;
  v36 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v36)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 33) = str;
  v37 = v3->__vftable;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v37->PSSetSamplers)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 34) = str;
  v38 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v38)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 35) = str;
  v39 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v39)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 36) = str;
  v40 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v40)(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 37) = str;
  v41 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v41)(a1: v3, a2: &str, a3: 4);
  v63 = *((_DWORD *)this + 39);
  GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (GRenderer::CachedData *)this + 19,
    result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)((char *)this + 152),
    newSize: str);
  if ( str > v63 )
  {
    v42 = str - v63;
    v43 = (_DWORD *)(*((_DWORD *)this + 38) + 4 * v63);
    if ( str != v63 )
    {
      do
      {
        if ( v43 != nullptr )
          *v43 = 0;
        ++v43;
        --v42;
      }
      while ( v42 != 0 );
    }
  }
  for ( str = 0; str < *((_DWORD *)this + 39); ++str )
  {
    v63 = 2;
    if ( GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 68, a4: &v63) != nullptr )
    {
      GFxMovieStats::GFxMovieStats(this: v60);
      v63 = v44;
    }
    else
    {
      v63 = 0;
    }
    v45 = (IShaderAPI **)(4 * str + *((_DWORD *)this + 38));
    v46 = *v45;
    v62 = v45;
    if ( v46 != nullptr )
    {
      GRefCountImpl::Release(this: v46);
      v45 = v62;
    }
    v47 = (ID3D11InputLayout **)version;
    *v45 = (IShaderAPI *)v63;
    GFxMovieStats::Read(ecx0: *(_DWORD **)(4 * str + *((_DWORD *)this + 38)), this: v3, str: v47);
  }
  v48 = v3->PSSetSamplers;
  str = 0;
  ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v48)(a1: v3, a2: &str, a3: 4);
  v49 = str;
  v50 = (GRenderer::CachedData *)((char *)this + 164);
  if ( str >= *((_DWORD *)this + 42) )
  {
    if ( str < *((_DWORD *)this + 43) )
      goto LABEL_19;
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v50,
      pheapAddr: (char *)this + 164,
      newCapacity: str + (str >> 2));
  }
  else
  {
    if ( str >= *((_DWORD *)this + 43) >> 1 )
      goto LABEL_19;
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v50,
      pheapAddr: (char *)this + 164,
      newCapacity: str);
  }
  v49 = str;
LABEL_19:
  *((_DWORD *)this + 42) = v49;
  v63 = 0;
  if ( v49 != 0 )
  {
    do
    {
      v51 = v3->PSSetSamplers;
      str = 0;
      ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v51)(a1: v3, a2: &str, a3: 4);
      v52 = v63;
      *(_DWORD *)(*((_DWORD *)this + 41) + 4 * v63) = str;
      v63 = v52 + 1;
    }
    while ( v52 + 1 < *((_DWORD *)this + 42) );
  }
  if ( version >= 9 )
  {
    v53 = v3->PSSetSamplers;
    str = 0;
    ((void (__thiscall *)(ID3D11DeviceContext *, unsigned int *, int))v53)(a1: v3, a2: &str, a3: 4);
    v54 = str;
    v55 = (CStudioHdr *)((char *)this + 176);
    if ( str >= *((_DWORD *)this + 45) )
    {
      if ( str < *((_DWORD *)this + 46) )
        goto LABEL_28;
      GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::Reserve(
        this: v55,
        pheapAddr: (const CStudioHdr *)((char *)this + 176),
        newCapacity: str + (str >> 2));
    }
    else
    {
      if ( str >= *((_DWORD *)this + 46) >> 1 )
        goto LABEL_28;
      GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::Reserve(
        this: v55,
        pheapAddr: (const CStudioHdr *)((char *)this + 176),
        newCapacity: str);
    }
    v54 = str;
LABEL_28:
    *((_DWORD *)this + 45) = v54;
    str = 0;
    if ( v54 != 0 )
    {
      do
      {
        v56 = v3->PSSetSamplers;
        v61 = 0;
        v62 = nullptr;
        ((void (__thiscall *)(ID3D11DeviceContext *, int *, int))v56)(a1: v3, a2: &v61, a3: 8);
        v57 = str;
        v58 = *((_DWORD *)this + 44);
        *(_DWORD *)(v58 + 8 * str) = v61;
        *(_DWORD *)(v58 + 8 * v57 + 4) = v62;
        str = v57 + 1;
      }
      while ( v57 + 1 < *((_DWORD *)this + 45) );
    }
  }
  GFxAmpMemItem::Read(
    this: *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> **)this
    + 47),
    a2: (struct GFile *)v3,
    version);
  v59 = version;
  GFxAmpMemItem::Read(
    this: *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> **)this
    + 48),
    a2: (struct GFile *)v3,
    version);
  if ( v59 >= 3 )
    GFxAmpMemItem::Read(
      this: *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> **)this
      + 49),
      a2: (struct GFile *)v3,
      version: v59);
  if ( v59 >= 7 )
    GFxAmpMemItem::Read(
      this: *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),CFuncMemPolicyNone> **)this
      + 50),
      a2: (struct GFile *)v3,
      version: v59);
  if ( v59 < 8 )
    GFxAmpMemFragReport::Read(
      this: *((CUtlVector<virtualsequence_t,CUtlMemory<virtualsequence_t,int> > **)this + 51),
      str: (const virtualsequence_t *)v3,
      version: v59);
}

//------------------------------------------------------------------------------
// Address: 0x1020442A
// Name: long D3DXShader::AddChild(class D3DXShader::CInstruction __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall D3DXShader::AddChild(D3DXShader *this, struct D3DXShader::CInstruction *a2, unsigned int a3)
{
  int v3; // eax
  unsigned int *v4; // eax

  v3 = *((_DWORD *)this + 7);
  if ( (v3 & 7) == 0 )
  {
    v4 = D3DXShader::CInstruction::Alloc(a1: v3 + 8);
    if ( v4 == nullptr )
      return -2147024882;
    qmemcpy(v4, *((const void **)this + 8), 4 * *((_DWORD *)this + 7));
    *((_DWORD *)this + 8) = v4;
  }
  *(_DWORD *)(*((_DWORD *)this + 8) + 4 * (*((_DWORD *)this + 7))++) = a2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10204484
// Name: protected: long D3DXShader::CPSLegacyProgram::LegacyChildParentInfo(class D3DXShader::CInstruction __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::LegacyChildParentInfo(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3)
{
  D3DXShader::CPSLegacyProgram *v3; // edi
  unsigned int v4; // edx
  struct D3DXShader::CInstruction *v5; // eax
  unsigned int j; // ecx
  int v7; // esi
  unsigned int k; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  struct D3DXShader::CInstruction *v12; // ebx
  unsigned int v13; // esi
  bool v14; // zf
  int v15; // eax
  unsigned int m; // ecx
  int result; // eax
  unsigned int *v18; // eax
  unsigned int *v19; // edi
  unsigned int v20; // eax
  unsigned int v21; // [esp+0h] [ebp-41Ch]
  _DWORD v22[256]; // [esp+Ch] [ebp-410h] BYREF
  D3DXShader::CPSLegacyProgram *i; // [esp+40Ch] [ebp-10h]
  unsigned int v24; // [esp+410h] [ebp-Ch]
  int v25; // [esp+414h] [ebp-8h]
  struct D3DXShader::CInstruction *v26; // [esp+418h] [ebp-4h]

  v3 = this;
  v4 = 0;
  for ( i = this; v4 < a3; ++v4 )
  {
    v5 = a2[v4];
    if ( v5 != nullptr )
    {
      for ( j = 0; j < *((_DWORD *)v5 + 3); *(_DWORD *)(v7 + 72) = v4 )
        v7 = *(_DWORD *)(*((_DWORD *)v3 + 5) + 4 * *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * j++));
      *((_DWORD *)v5 + 7) = 0;
      *((_DWORD *)v5 + 5) = 0;
    }
  }
  for ( k = 0; k < *((_DWORD *)v3 + 2); ++k )
  {
    v9 = *((_DWORD *)v3 + 5);
    v10 = *(_DWORD *)(v9 + 4 * k);
    v11 = *(_DWORD *)(v10 + 56);
    if ( v11 != -1 )
      *(_DWORD *)(v10 + 72) = *(_DWORD *)(*(_DWORD *)(v9 + 4 * v11) + 72);
  }
  v26 = nullptr;
  if ( a3 == 0 )
    return 0;
  while ( 1 )
  {
    v12 = a2[(_DWORD)v26];
    v13 = 0;
    if ( v12 != nullptr )
    {
      v14 = *((_DWORD *)v12 + 1) == 0;
      v24 = 0;
      v25 = 0;
      if ( !v14 )
        break;
LABEL_22:
      v18 = D3DXShader::CInstruction::Alloc(a1: v13);
      *((_DWORD *)v12 + 6) = v18;
      if ( v18 == nullptr )
        return -2147024882;
      v19 = v18;
      v20 = v24;
      qmemcpy(v19, v22, 4 * v13);
      v3 = i;
      *((_DWORD *)v12 + 5) = v20;
    }
    v26 = (struct D3DXShader::CInstruction *)((char *)v26 + 1);
    if ( (unsigned int)v26 >= a3 )
      return 0;
  }
  while ( 1 )
  {
    v15 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v3 + 5) + 4 * *(_DWORD *)(*((_DWORD *)v12 + 2) + 4 * v25)) + 72);
    if ( v15 != -1 )
    {
      for ( m = 0; m < v13; ++m )
      {
        if ( v22[m] == v15 )
          break;
      }
      if ( m == v13 )
      {
        v22[v13++] = v15;
        v24 = v13;
      }
      result = D3DXShader::AddChild(this: a2[v15], a2: v26, a3: v21);
      if ( result < 0 )
        return result;
    }
    if ( (unsigned int)++v25 >= *((_DWORD *)v12 + 1) )
      goto LABEL_22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102045BC
// Name: protected: long D3DXShader::CPSLegacyProgram::MatchOutputModifier(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::MatchOutputModifier(D3DXShader::CPSLegacyProgram *this)
{
  int *v2; // eax
  int v3; // ecx
  int v4; // esi
  D3DXShader::CInstruction *v5; // eax
  unsigned int v6; // esi
  _DWORD *v7; // edi
  D3DXShader::CInstruction *v8; // ecx
  int v9; // edx
  int v10; // edi
  int v11; // ecx
  double v12; // st7
  int v13; // ecx
  _DWORD *v14; // eax
  unsigned int v15; // edi
  int v16; // edx
  D3DXShader::CInstruction *v17; // ecx
  int v18; // ecx
  double v19; // st7
  int v21; // edx
  unsigned int v22; // edx
  int v23; // eax
  long double v24; // st7
  int v25; // eax
  _DWORD *v26; // edx
  _DWORD *v27; // edi
  unsigned int v28; // ecx
  _DWORD *v29; // edi
  D3DXShader::CInstruction *v30; // eax
  int v31; // ecx
  unsigned int v32; // edx
  unsigned int v33; // edi
  unsigned int *v34; // esi
  bool v35; // zf
  unsigned __int8 *v36; // eax
  int v37; // edi
  int v38; // esi
  D3DXShader::CInstruction *v39; // eax
  D3DXShader::CInstruction *v40; // eax
  unsigned int v41; // edi
  unsigned int v42; // eax
  _DWORD *v43; // ecx
  unsigned int v44; // esi
  int v45; // ecx
  int v46; // eax
  int v47; // esi
  bool v48; // c0
  int v49; // edi
  unsigned int v50; // edi
  bool v51; // cf
  _DWORD v52[20]; // [esp+Ch] [ebp-90h] BYREF
  unsigned int v53[4]; // [esp+5Ch] [ebp-40h] BYREF
  _DWORD *v54; // [esp+6Ch] [ebp-30h]
  int v55; // [esp+70h] [ebp-2Ch]
  unsigned int v56; // [esp+74h] [ebp-28h]
  int v57; // [esp+78h] [ebp-24h]
  float v58; // [esp+7Ch] [ebp-20h]
  unsigned int v59; // [esp+80h] [ebp-1Ch]
  _DWORD *v60; // [esp+84h] [ebp-18h]
  D3DXShader::CInstruction *v61; // [esp+88h] [ebp-14h]
  int v62; // [esp+8Ch] [ebp-10h]
  _DWORD *i; // [esp+90h] [ebp-Ch]
  unsigned int v64; // [esp+94h] [ebp-8h]
  D3DXShader::CInstruction *v65; // [esp+98h] [ebp-4h]

  v59 = 0;
  v62 = 0;
  v2 = *((int **)this + 64);
  v3 = *((_DWORD *)this + 5);
  v4 = *v2;
  v5 = (D3DXShader::CInstruction *)v2[2];
  v6 = v4 & 0xFFFFF;
  v7 = *(_DWORD **)(v3 + 4 * *(_DWORD *)v5);
  v64 = (unsigned int)v5 + 4 * v6;
  v8 = *(D3DXShader::CInstruction **)(v3 + 4 * *(_DWORD *)v64);
  v9 = v7[1];
  v60 = v7;
  v10 = *((_DWORD *)this + 4);
  v61 = v8;
  i = *(_DWORD **)(v10 + 4 * v9);
  v11 = *((_DWORD *)this + 34);
  if ( v9 == v11
    && (*(_BYTE *)(*(_DWORD *)(v10 + 4 * *((_DWORD *)v61 + 1)) + 5) & 1) != 0
    && (**((_DWORD **)this + 64) & 0xFFF00000) == 0x20500000 )
  {
    v61 = v5;
    v5 = (D3DXShader::CInstruction *)v64;
  }
  else
  {
    v16 = *((_DWORD *)v61 + 1);
    if ( v16 != v11 || (*((_BYTE *)i + 5) & 1) == 0 || (**((_DWORD **)this + 64) & 0xFFF00000) != 0x20500000 )
    {
      if ( v60[1] != v11 || v16 != v11 || (**((_DWORD **)this + 64) & 0xFFF00000) != 0x20400000 )
        return 1;
      v62 = 1;
      if ( v6 != 0 )
      {
        v17 = v5;
        for ( i = (_DWORD *)v6; i != nullptr; i = (_DWORD *)((char *)i - 1) )
        {
          if ( *(_DWORD *)v17 != *(_DWORD *)((char *)v17 + v64 - (_DWORD)v5) )
            v62 = 0;
          v17 = (D3DXShader::CInstruction *)((char *)v17 + 4);
        }
      }
      v18 = v60[15];
      if ( v18 != *((_DWORD *)v61 + 15) )
        return 1;
      if ( v18 == 0x80000 )
      {
        v19 = -1.0;
      }
      else
      {
        if ( (v18 & 0x80000) != 0 )
          return 1;
        v19 = 1.0;
      }
      v61 = v5;
      if ( v62 == 0 )
        return 1;
      v5 = (D3DXShader::CInstruction *)v57;
      v12 = v19 + v19;
      goto LABEL_6;
    }
    v61 = (D3DXShader::CInstruction *)v64;
  }
  v12 = *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)v5) + 32);
LABEL_6:
  v65 = nullptr;
  v58 = v12;
  if ( v6 != 0 )
  {
    v13 = *((_DWORD *)this + 5);
    v64 = (unsigned int)v5;
    v60 = (_DWORD *)(v61 - v5);
    do
    {
      v14 = *(_DWORD **)(v13 + 4 * *(_DWORD *)((char *)v60 + v64));
      v15 = 0;
      i = v62 != 0 ? nullptr : *(_DWORD **)(v13 + 4 * *(_DWORD *)v64);
      v21 = *((_DWORD *)this + 63);
      if ( v14[22] != v21 || v14[21] != v21 || (v14[15] & 0x1FFE00) != 0 )
        return 1;
      if ( v59 != 0 )
      {
        do
        {
          if ( v14[18] == v52[v15 + 16] )
            break;
          ++v15;
        }
        while ( v15 < v59 );
      }
      if ( v15 == v59 )
      {
        v22 = v59;
        v23 = v14[18];
        ++v59;
        v52[v22 + 16] = v23;
      }
      if ( v62 == 0 && v58 != *((double *)i + 4) )
        return 1;
      v65 = (D3DXShader::CInstruction *)((char *)v65 + 1);
      v64 += 4;
    }
    while ( (unsigned int)v65 < v6 );
  }
  v24 = fabs(v58);
  if ( 2.0 != fabs(v24) || (v25 = 1024, (*((_DWORD *)this + 27) & 0x400) == 0) )
  {
    if ( v24 != 4.0 || (v25 = 2048, (*((_DWORD *)this + 27) & 0x800) == 0) )
    {
      if ( v24 != 8.0 || (v25 = 4096, (*((_DWORD *)this + 27) & 0x1000) == 0) )
      {
        if ( v24 != 0.5 || (v25 = 0x2000, (*((_DWORD *)this + 27) & 0x2000) == 0) )
        {
          if ( v24 != 0.25 || (v25 = 0x4000, (*((_DWORD *)this + 27) & 0x4000) == 0) )
          {
            if ( v24 != 0.125 )
              return 1;
            v25 = 0x8000;
            if ( (*((_DWORD *)this + 27) & 0x8000) == 0 )
              return 1;
          }
        }
      }
    }
  }
  v62 = v25;
  if ( v58 < 0.0 )
    BYTE2(v62) |= 8u;
  memset(v53, 0, sizeof(v53));
  v64 = 0;
  if ( v59 != 0 )
  {
    v60 = v52;
    i = nullptr;
    do
    {
      v26 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v52[v64 + 16]);
      if ( (*v26 & 0xF0000000) == 0x60000000 || (*v26 & 0xFF000000) == 0x72000000 )
        return 1;
      v27 = v60;
      v55 = 0;
      v65 = nullptr;
      v28 = v26[3];
      *v60 = -1;
      *++v27 = -1;
      *++v27 = -1;
      for ( v27[1] = -1; (unsigned int)v65 < v6; v65 = (D3DXShader::CInstruction *)((char *)v65 + 1) )
      {
        v56 = 0;
        if ( v28 != 0 )
        {
          v57 = *((_DWORD *)v61 + (_DWORD)v65);
          v54 = (_DWORD *)v26[4];
          v29 = (_DWORD *)((char *)v52 + (_DWORD)i);
          do
          {
            if ( *v54 == v57 )
            {
              v30 = v65;
              ++v53[v64];
              v31 = *(_DWORD *)(*((_DWORD *)this + 64) + 16);
              *v29 = v30;
              if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v31 + 4 * (_DWORD)v30)) + 61) & 2) != 0
                && v58 < 0.0 )
              {
                return 1;
              }
              ++v55;
            }
            ++v56;
            v28 = v26[3];
            ++v54;
            ++v29;
          }
          while ( v56 < v28 );
        }
      }
      if ( v55 != v28 )
        return 1;
      ++v64;
      v60 += 4;
      i += 4;
    }
    while ( v64 < v59 );
  }
  v32 = 0;
  i = nullptr;
  if ( v59 == 0 )
  {
LABEL_100:
    **((_DWORD **)this + 64) = 0;
    return 0;
  }
  v60 = v52;
  while ( 1 )
  {
    v33 = v53[v32];
    v34 = *(unsigned int **)(4 * v52[v32 + 16] + *((_DWORD *)this + 6));
    v35 = v33 == v34[3];
    v57 = 4 * v52[v32 + 16];
    v61 = (D3DXShader::CInstruction *)v34;
    if ( !v35 )
      break;
LABEL_82:
    v41 = 0;
    v35 = v53[v32] == 0;
    v65 = nullptr;
    if ( !v35 )
    {
      i = v60;
      while ( 1 )
      {
        v42 = v41;
        if ( v41 < 4 )
        {
          v43 = i;
          do
          {
            if ( *v43 != -1 )
              break;
            ++v42;
            ++v43;
          }
          while ( v42 < 4 );
        }
        v44 = v34[4];
        v64 = 0;
        v45 = 4 * v52[4 * v32 + v42];
        *(_DWORD *)(v44 + 4 * v41) = *(_DWORD *)(v45 + *(_DWORD *)(*((_DWORD *)this + 64) + 16));
        v46 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v45 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)));
        *(_DWORD *)(v46 + 60) |= v62;
        if ( *((_DWORD *)this + 2) != 0 )
        {
          do
          {
            v47 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v64);
            if ( *(_DWORD *)(v47 + 56) == *(_DWORD *)(v45 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)) )
            {
              v48 = v58 < 0.0;
              *(_DWORD *)(v47 + 60) |= v62 & 0xFFF7FFFF;
              v49 = *(_DWORD *)(v47 + 60);
              if ( v48 )
              {
                if ( (v49 & 0x80000) != 0 )
                  v50 = v49 & 0xFFF7FFFF;
                else
                  v50 = v49 | 0x80000;
                *(_DWORD *)(v47 + 60) = v50;
              }
            }
            ++v64;
          }
          while ( v64 < *((_DWORD *)this + 2) );
          v41 = (unsigned int)v65;
        }
        ++i;
        v51 = ++v41 < v53[v32];
        v65 = (D3DXShader::CInstruction *)v41;
        if ( !v51 )
          break;
        v34 = (unsigned int *)v61;
      }
    }
    v60 += 4;
    i = (_DWORD *)++v32;
    if ( v32 >= v59 )
      goto LABEL_100;
  }
  v36 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v36 != nullptr )
    v65 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v36);
  else
    v65 = nullptr;
  if ( v65 == nullptr )
    return -2147024882;
  v37 = D3DXShader::CInstruction::Initialize(this: v65, a2: *v34, a3: v34[1], a4: v33, a5: 0);
  if ( v37 < 0 )
  {
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v65, a2: 1);
    return v37;
  }
  v38 = D3DXShader::CInstruction::Instance(this: v65, a2: (struct D3DXShader::CInstruction *)v34);
  if ( v38 >= 0 )
  {
    v39 = v61;
    qmemcpy(*((void **)v65 + 2), *((const void **)v61 + 2), 4 * *((_DWORD *)v61 + 1));
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v39, a2: 1);
    v40 = v65;
    *(_DWORD *)(v57 + *((_DWORD *)this + 6)) = v65;
    v32 = (unsigned int)i;
    v61 = v40;
    v34 = (unsigned int *)v40;
    goto LABEL_82;
  }
  D3DXShader::CInstruction::`scalar deleting destructor'(this: v65, a2: 1);
  return v38;
}

//------------------------------------------------------------------------------
// Address: 0x10204B93
// Name: protected: long D3DXShader::CPSLegacyProgram::RemapInput(class D3DXShader::CInstruction __near * __near *,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::RemapInput(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int *a7)
{
  int v7; // ebx
  unsigned int v8; // eax
  struct D3DXShader::CInstruction *v9; // edi
  D3DXShader::CPSLegacyProgram *v10; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // esi
  unsigned int v14; // ecx
  unsigned int v15; // eax
  int v16; // ecx
  unsigned int v18; // [esp+8h] [ebp-1Ch]
  unsigned int v19; // [esp+14h] [ebp-10h]
  int IsTextureInst; // [esp+18h] [ebp-Ch]
  int v22; // [esp+20h] [ebp-4h]

  v7 = 0;
  v8 = 0;
  v19 = 0;
  if ( a3 == 0 )
    return 0;
  while ( 1 )
  {
    v9 = a2[v8];
    if ( v9 != nullptr && *(_DWORD *)v9 != 0 )
    {
      IsTextureInst = D3DXShader::IsTextureInst(this: (D3DXShader *)(*(_DWORD *)v9 & 0xFFF00000), a2: v18);
      if ( v11 == 285212672 )
        IsTextureInst = 1;
      v22 = 0;
      if ( *((_DWORD *)v9 + 1) != 0 )
        break;
    }
LABEL_22:
    v8 = ++v19;
    if ( v19 >= a3 )
      return 0;
  }
  while ( 1 )
  {
    v12 = *((_DWORD *)v10 + 5);
    v13 = *(_DWORD *)(v12 + 4 * *(_DWORD *)(*((_DWORD *)v9 + 2) + 4 * v22));
    if ( *(_DWORD *)(v13 + 4) != *((_DWORD *)v10 + 32)
      || (unsigned __int8)*(_DWORD *)(v13 + 108) != a4
      || a5 != *(unsigned __int8 *)(v13 + 109)
      || IsTextureInst != 0 && *(_DWORD *)(v13 + 60) == 0 )
    {
      goto LABEL_21;
    }
    if ( a6 != 0 )
    {
      v14 = *(_DWORD *)(v13 + 16);
      while ( v14 != *(_DWORD *)(*(_DWORD *)(v12 + 4 * a7[v7]) + 16) )
      {
        if ( ++v7 >= a6 )
          goto LABEL_19;
      }
      v15 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: 0, a4: v14, a5: 0.0);
      if ( v15 == -1 )
        return -2147024882;
      v16 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v15);
      *(_DWORD *)(v16 + 60) = *(_DWORD *)(v13 + 60);
      *(_DWORD *)(v16 + 56) = a7[v7];
      *(_DWORD *)(*((_DWORD *)v9 + 2) + 4 * v22) = v15;
    }
LABEL_19:
    if ( v7 == a6 )
      break;
    v10 = this;
    v7 = 0;
LABEL_21:
    if ( (unsigned int)++v22 >= *((_DWORD *)v9 + 1) )
      goto LABEL_22;
  }
  D3DXShader::CProgram::Error(
    this,
    a2: nullptr,
    a3: 0x12C1u,
    format: "internal error: InputRemap component matchup failed");
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x10204CEA
// Name: protected: long D3DXShader::CPSLegacyProgram::RemapInputTex(class D3DXShader::CInstruction __near * __near *,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::RemapInputTex(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int *a7)
{
  unsigned int v8; // eax
  struct D3DXShader::CInstruction *v9; // edi
  int v10; // eax
  int v11; // esi
  unsigned int v12; // ecx
  unsigned int v13; // eax
  int v14; // ecx
  unsigned int v16; // [esp+14h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-8h]
  int v18; // [esp+1Ch] [ebp-4h]

  v8 = 0;
  v16 = 0;
  if ( a3 == 0 )
    return 0;
  while ( 1 )
  {
    v9 = a2[v8];
    if ( v9 != nullptr )
    {
      v17 = 0;
      if ( *((_DWORD *)v9 + 1) != 0 )
        break;
    }
LABEL_16:
    v8 = ++v16;
    if ( v16 >= a3 )
      return 0;
  }
  while ( 1 )
  {
    v10 = *((_DWORD *)this + 5);
    v11 = *(_DWORD *)(v10 + 4 * *(_DWORD *)(*((_DWORD *)v9 + 2) + 4 * v17));
    if ( *(_DWORD *)(v11 + 4) == *((_DWORD *)this + 32)
      && *(_DWORD *)(v11 + 60) != 0
      && (unsigned __int8)*(_DWORD *)(v11 + 108) == a4
      && a5 == *(unsigned __int8 *)(v11 + 109) )
    {
      v18 = 0;
      if ( a6 != 0 )
      {
        while ( 1 )
        {
          v12 = *(_DWORD *)(v11 + 16);
          if ( v12 == *(_DWORD *)(*(_DWORD *)(v10 + 4 * a7[v18]) + 16) )
            break;
          if ( ++v18 >= a6 )
            goto LABEL_14;
        }
        v13 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: 0, a4: v12, a5: 0.0);
        if ( v13 == -1 )
          return -2147024882;
        v14 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v13);
        *(_DWORD *)(v14 + 60) = *(_DWORD *)(v11 + 60);
        *(_DWORD *)(v14 + 56) = a7[v18];
        *(_DWORD *)(*((_DWORD *)v9 + 2) + 4 * v17) = v13;
      }
LABEL_14:
      if ( v18 == a6 )
        break;
    }
    if ( (unsigned int)++v17 >= *((_DWORD *)v9 + 1) )
      goto LABEL_16;
  }
  D3DXShader::CProgram::Error(
    this,
    a2: nullptr,
    a3: 0x12C2u,
    format: "internal error: InputRemap component matchup failed");
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x10204E19
// Name: protected: long D3DXShader::CPSLegacyProgram::PullOut(unsigned int __near *,unsigned int,class D3DXShader::CInstruction __near * __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::PullOut(
        D3DXShader::CPSLegacyProgram *this,
        unsigned int *a2,
        unsigned int a3,
        struct D3DXShader::CInstruction **a4,
        unsigned int *a5)
{
  int v6; // esi
  unsigned int v7; // edx
  int v8; // eax
  int v9; // ecx
  unsigned int v10; // edi
  int result; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  _DWORD *v14; // ecx
  unsigned int v15; // [esp+Ch] [ebp-1Ch]
  unsigned int v16; // [esp+Ch] [ebp-1Ch]
  int v17; // [esp+10h] [ebp-18h]
  unsigned int v18; // [esp+14h] [ebp-14h]
  int v19; // [esp+18h] [ebp-10h]
  unsigned int v20; // [esp+1Ch] [ebp-Ch]
  int v21; // [esp+20h] [ebp-8h]
  int v22; // [esp+24h] [ebp-4h]

  v22 = 0;
  if ( *((_DWORD *)this + 3) == 0 )
    return 0;
  while ( 1 )
  {
    v6 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v22);
    if ( v6 != 0 && *(_DWORD *)(v6 + 36) != 1 && *(_DWORD *)v6 != 0 )
    {
      v17 = 0;
      v20 = 0;
      if ( *(_DWORD *)(v6 + 12) != 0 )
        break;
    }
LABEL_32:
    if ( (unsigned int)++v22 >= *((_DWORD *)this + 3) )
      return 0;
  }
  do
  {
    v21 = 0;
    if ( a3 != 0 )
    {
      while ( 1 )
      {
        v7 = a2[v21];
        v8 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v7);
        if ( *(_DWORD *)(v8 + 4) == *((_DWORD *)this + 32) && *(_BYTE *)(v8 + 108) != 3 )
        {
          D3DXShader::CProgram::Error(
            this,
            a2: *(struct D3DXShader::CNode **)(v6 + 60),
            a3: 0x11A1u,
            format: "cannot perform dependent texture read which in any way is based on color inputs");
          return -2147467259;
        }
        v9 = *(_DWORD *)(*(_DWORD *)(v6 + 16) + 4 * v20);
        if ( v9 == v7 || v9 == *(_DWORD *)(v8 + 56) )
        {
          v10 = *(_DWORD *)v6 & 0xFFFFF;
          v18 = 0;
          v15 = *(_DWORD *)(v6 + 4) / v10;
          if ( v15 != 0 )
            break;
        }
LABEL_15:
        if ( ++v21 >= a3 )
          goto LABEL_16;
      }
      v19 = 0;
      while ( 1 )
      {
        result = D3DXShader::CPSLegacyProgram::PullOut(
                   this,
                   a2: (unsigned int *)(v19 + *(_DWORD *)(v6 + 8)),
                   a3: v10,
                   a4,
                   a5);
        if ( result < 0 )
          return result;
        ++v18;
        v19 += 4 * v10;
        v17 = 1;
        if ( v18 >= v15 )
          goto LABEL_15;
      }
    }
LABEL_16:
    ++v20;
  }
  while ( v20 < *(_DWORD *)(v6 + 12) );
  if ( v17 == 0 )
    goto LABEL_32;
  v12 = *(_DWORD *)v6 & 0xFFF00000;
  if ( v12 != 1610612736
    && v12 != 1615855616
    && v12 != 1621098496
    && v12 != 1626341376
    && v12 != 1927282688
    && v12 != 1617952768
    && v12 != 1925185536
    && v12 != 1926234112
    && v12 != 285212672
    || (v13 = *(_DWORD *)v6 & 0xFFFFF, v16 = 2 * v13, v13 >= 2 * v13) )
  {
LABEL_31:
    a4[*a5] = (struct D3DXShader::CInstruction *)v6;
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * v22) + 36) = 1;
    ++*a5;
    goto LABEL_32;
  }
  v14 = (_DWORD *)(*(_DWORD *)(v6 + 8) + 4 * v13);
  while ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v14) + 4) != *((_DWORD *)this + 34) )
  {
    ++v13;
    ++v14;
    if ( v13 >= v16 )
      goto LABEL_31;
  }
  D3DXShader::CProgram::Error(
    this,
    a2: *(struct D3DXShader::CNode **)(v6 + 60),
    a3: 0x11B6u,
    format: "cannot perform double dependent texture read in ps_1_x");
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x10205009
// Name: protected: long D3DXShader::CPSLegacyProgram::TexturePullOut(class D3DXShader::CInstruction __near * __near *,unsigned int __near *,class D3DXShader::CInstruction __near * __near *,unsigned int,class D3DXShader::CInstruction __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::TexturePullOut(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int *a3,
        struct D3DXShader::CInstruction **a4,
        unsigned int a5,
        struct D3DXShader::CInstruction **a6,
        unsigned int a7)
{
  unsigned int v7; // edx
  struct D3DXShader::CInstruction **v9; // edi
  struct D3DXShader::CInstruction *v10; // eax
  unsigned int v11; // ecx
  D3DXShader::CArgument *v12; // ecx
  _DWORD *v13; // edi
  int v14; // eax
  unsigned int v15; // ecx
  unsigned int *v16; // ecx
  unsigned int v17; // edx
  unsigned int v18; // eax
  unsigned int *v19; // edi
  unsigned int v20; // esi
  unsigned __int8 *v21; // eax
  D3DXShader::CInstruction *v22; // eax
  int v23; // eax
  unsigned int v24; // esi
  unsigned int v25; // eax
  _DWORD *v26; // eax
  unsigned int v27; // ecx
  bool v28; // cf
  unsigned int v29; // esi
  unsigned int i; // esi
  unsigned int v31; // eax
  int v32; // ecx
  unsigned int v33; // edx
  D3DXShader::CInstruction **v34; // esi
  int result; // eax
  D3DXShader::CInstruction *v36; // eax
  int v37; // esi
  struct D3DXShader::CInstruction *v38; // edi
  unsigned int v39; // ecx
  int v40; // esi
  _DWORD *v41; // ecx
  int v42; // eax
  int v43; // edx
  unsigned int v44; // ecx
  int v45; // eax
  _DWORD *v46; // eax
  struct D3DXShader::CInstruction **v47; // ecx
  unsigned int v48; // eax
  unsigned int m; // ecx
  D3DXShader::CArgument *v50; // eax
  int v51; // edx
  int v52; // ecx
  unsigned int v53; // eax
  int *v54; // ecx
  int v55; // esi
  bool v56; // zf
  unsigned int v57; // eax
  unsigned int n; // ecx
  D3DXShader::CArgument *v59; // eax
  struct D3DXShader::CInstruction **v60; // esi
  unsigned __int8 *v61; // eax
  D3DXShader::CInstruction *v62; // eax
  unsigned int v63; // esi
  struct D3DXShader::CInstruction **v64; // eax
  struct D3DXShader::CInstruction *v65; // edx
  unsigned int v66; // [esp-4h] [ebp-60h]
  const char *v67; // [esp+0h] [ebp-5Ch]
  int v68; // [esp+4h] [ebp-58h]
  const char *v69; // [esp+4h] [ebp-58h]
  unsigned int v70[10]; // [esp+14h] [ebp-48h] BYREF
  unsigned int v71[4]; // [esp+3Ch] [ebp-20h] BYREF
  D3DXShader::CArgument *v72; // [esp+4Ch] [ebp-10h]
  struct D3DXShader::CInstruction **v73; // [esp+50h] [ebp-Ch]
  D3DXShader::CInstruction *k; // [esp+54h] [ebp-8h]
  unsigned int j; // [esp+58h] [ebp-4h]
  int v76; // [esp+74h] [ebp+18h]
  unsigned int v77; // [esp+78h] [ebp+1Ch]
  _DWORD *v78; // [esp+78h] [ebp+1Ch]
  unsigned int v79; // [esp+78h] [ebp+1Ch]

  v7 = a5;
  j = 0;
  memset(v70, 0, 0x18u);
  if ( a5 + a7 != 0 )
  {
    v9 = &a6[-a5];
    v73 = v9;
    do
    {
      if ( j >= v7 )
        v10 = *v9;
      else
        v10 = a4[j];
      if ( v10 != nullptr )
      {
        v11 = *(_DWORD *)v10 & 0xFFF00000;
        if ( v11 != 0
          && *((_DWORD *)v10 + 9) != 1
          && (v11 != 1610612736
           && v11 != 1615855616
           && v11 != 1621098496
           && v11 != 1626341376
           && v11 != 285212672
           && v11 != 1925185536
           && v11 != 1926234112
           || j >= v7) )
        {
          v12 = *((D3DXShader::CArgument **)v10 + 1);
          k = nullptr;
          v72 = v12;
          if ( v12 != nullptr )
          {
            v13 = *((_DWORD **)v10 + 2);
            do
            {
              v14 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v13);
              if ( *(_DWORD *)(v14 + 4) == *((_DWORD *)this + 32) )
              {
                v15 = *(unsigned __int8 *)(v14 + 109);
                if ( v15 > 5 )
                  break;
                if ( *(_BYTE *)(v14 + 108) == 3 )
                {
                  v16 = &v70[v15];
                  if ( j < a5 )
                  {
                    v18 = *(_DWORD *)(v14 + 16) + 1;
                    if ( v18 > *v16 )
                      *v16 = v18;
                  }
                  else
                  {
                    v17 = *(_DWORD *)(v14 + 16) + 1;
                    if ( v17 > *v16 && *(_DWORD *)(v14 + 60) != 0 )
                      *v16 = v17;
                  }
                }
              }
              k = (D3DXShader::CInstruction *)((char *)k + 1);
              ++v13;
            }
            while ( k < v72 );
            v7 = a5;
            v9 = v73;
          }
        }
      }
      ++j;
      v73 = ++v9;
    }
    while ( j < a5 + a7 );
  }
  j = 0;
  if ( *((_DWORD *)this + 15) != 0 )
  {
    v19 = v70;
    v72 = (D3DXShader::CArgument *)((char *)a2 - (char *)v70);
    do
    {
      v20 = *v19;
      if ( *v19 != 0 )
      {
        v21 = D3DXShader::CInstruction::operator new(a1: 0x74u);
        if ( v21 != nullptr )
          v22 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v21);
        else
          v22 = nullptr;
        k = v22;
        if ( v22 == nullptr )
          return -2147024882;
        v23 = D3DXShader::CInstruction::Initialize(this: v22, a2: v20 & 0xFFFFF | 0x72100000, a3: v20, a4: v20, a5: 0);
        if ( v23 < 0 )
        {
LABEL_54:
          v37 = v23;
          goto LABEL_57;
        }
        v24 = 0;
        if ( *v19 != 0 )
        {
          while ( 1 )
          {
            v25 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: j, a4: v24, a5: 0.0);
            v71[v24] = v25;
            if ( v25 == -1 )
              break;
            *(_DWORD *)(*((_DWORD *)k + 4) + 4 * v24) = v25;
            v26 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v25);
            v27 = j;
            v26[15] = 0;
            v26[14] = -1;
            v28 = ++v24 < *v19;
            v26[27] = (v27 << 8) | 3;
            if ( !v28 )
              goto LABEL_42;
          }
LABEL_55:
          v37 = -2147024882;
LABEL_57:
          D3DXShader::CInstruction::`scalar deleting destructor'(this: k, a2: 1);
          return v37;
        }
LABEL_42:
        v29 = *v19;
        v23 = D3DXShader::CPSLegacyProgram::RemapInput(this, a2: a4, a3: a5, a4: 3u, a5: j, a6: *v19, a7: v71);
        if ( v23 < 0 )
          goto LABEL_54;
        v23 = D3DXShader::CPSLegacyProgram::RemapInputTex(this, a2: a6, a3: a7, a4: 3u, a5: j, a6: v29, a7: v71);
        if ( v23 < 0 )
          goto LABEL_54;
        for ( i = 0; i < *v19; *(_DWORD *)(*((_DWORD *)k + 2) + 4 * i++) = v31 )
        {
          v31 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 32), a3: j, a4: i, a5: 0.0);
          v70[i + 6] = v31;
          if ( v31 == -1 )
            goto LABEL_55;
          v32 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v31);
          v33 = j;
          *(_DWORD *)(v32 + 60) = 0;
          *(_DWORD *)(v32 + 108) = (v33 << 8) | 3;
        }
        v34 = (D3DXShader::CInstruction **)((char *)v19 + (_DWORD)v72);
        if ( *(unsigned int *)((char *)v19 + (_DWORD)v72) != 0 )
        {
          D3DXShader::CProgram::Error(
            this,
            a2: nullptr,
            a3: 0x11A4u,
            format: "cannot read from a texcoord which was used as input in a sampler",
            (unsigned __int8)*((_DWORD *)this + 50));
          v37 = -2147467259;
          goto LABEL_57;
        }
        result = D3DXShader::CBaseProgram::AddInstruction(this, a2: k);
        if ( result < 0 )
          return result;
        *v34 = k;
      }
      ++j;
      ++v19;
    }
    while ( j < *((_DWORD *)this + 15) );
  }
  v76 = 1;
  while ( 1 )
  {
    j = 0;
    if ( a5 != 0 )
      break;
LABEL_124:
    if ( (unsigned int)++v76 >= 3 )
    {
      for ( j = 0; j < *((_DWORD *)this + 15); ++j )
      {
        v60 = &a2[j];
        if ( *v60 == nullptr )
        {
          v61 = D3DXShader::CInstruction::operator new(a1: 0x74u);
          if ( v61 != nullptr )
            v62 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v61);
          else
            v62 = nullptr;
          *v60 = v62;
          if ( v62 == nullptr )
            return -2147024882;
          D3DXShader::CInstruction::Initialize(this: v62, a2: 0, a3: 0, a4: 0, a5: 0);
          D3DXShader::CBaseProgram::AddInstruction(this, a2: *v60);
        }
      }
      v63 = 0;
      for ( *a3 = *((_DWORD *)this + 15); v63 < a5; ++v63 )
      {
        v64 = &a4[v63];
        v65 = *v64;
        if ( *v64 != nullptr && *((_DWORD *)v65 + 9) != 1 && *(_DWORD *)v65 != 0 )
        {
          a2[(*a3)++] = *v64;
          *((_DWORD *)*v64 + 9) = 1;
        }
      }
      return 0;
    }
  }
  v36 = (D3DXShader::CInstruction *)&a4[-a5];
  for ( k = v36; ; v36 = k )
  {
    if ( j >= 0x200 )
    {
      D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x11A2u, format: "program too big");
      return -2147467259;
    }
    v38 = j >= a5 ? *(struct D3DXShader::CInstruction **)v36 : a4[j];
    if ( v38 != nullptr && *((_DWORD *)v38 + 9) != 1 )
    {
      v39 = *(_DWORD *)v38 & 0xFFF00000;
      if ( v39 == 1610612736
        || v39 == 1615855616
        || v39 == 1621098496
        || v39 == 1626341376
        || v39 == 1927282688
        || v39 == 1617952768
        || v39 == 285212672
        || v39 == 1925185536
        || v39 == 1926234112 )
      {
        break;
      }
    }
LABEL_123:
    ++j;
    k = (D3DXShader::CInstruction *)((char *)k + 4);
    if ( j >= a5 )
      goto LABEL_124;
  }
  v40 = *(_DWORD *)v38 & 0xFFFFF;
  if ( v39 == 285212672 )
    v40 = 0;
  v41 = *((_DWORD **)v38 + 2);
  v42 = *((_DWORD *)this + 5);
  v43 = *(_DWORD *)(v42 + 4 * v41[v40]);
  if ( v40 != 0 )
    v40 = *(_DWORD *)(v42 + 4 * *v41);
  v56 = *(_DWORD *)(v43 + 4) == *((_DWORD *)this + 32);
  v72 = *(D3DXShader::CArgument **)(v43 + 4);
  if ( v56 && (unsigned __int16)*((_DWORD *)this + 50) != 260 && v76 == 1 )
  {
    v44 = *(unsigned __int8 *)(v43 + 109);
    v77 = v44;
    if ( v44 >= 6 )
      goto LABEL_124;
    if ( v40 != 0 )
    {
      v45 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v40 + 4));
      if ( (*(_WORD *)(v45 + 4) & 0x840) != 0 )
      {
        if ( v44 != *(_DWORD *)(v40 + 12) )
        {
          v68 = (unsigned __int8)*((_DWORD *)this + 50);
          if ( (*(_BYTE *)(v45 + 5) & 8) != 0 )
            v67 = "cannot bind sampler to user specified stage. In ps_1_%i, samplers must be bound to the same stage as their TEXCOORD";
          else
            v67 = "cannot bind sampler to sampler array. In ps_1_%i, samplers must be bound to the same stage as their TEXCOORD";
          v66 = 4515;
          goto LABEL_132;
        }
      }
      else
      {
        *(_DWORD *)(v40 + 12) = v44;
      }
    }
    v46 = (_DWORD *)((char *)this + 4 * v44 + 1060);
    if ( *v46 != -1 || (v47 = &a2[v44], v56 = *v47 == nullptr, v73 = v47, !v56) )
    {
      v68 = (unsigned __int8)*((_DWORD *)this + 50);
      v67 = "cannot read from same texcoord. In ps_1_%i, each sampler must have a unique TEXCOORD";
      v66 = 4516;
LABEL_132:
      D3DXShader::CProgram::Error(this, a2: *((struct D3DXShader::CNode **)v38 + 15), a3: v66, format: v67, v68);
      return -2147467259;
    }
    if ( v40 != 0 )
    {
      *((_DWORD *)this + v77 + 259) = *(_DWORD *)(v40 + 4);
      *v46 = **((_DWORD **)v38 + 2);
      v48 = D3DXShader::CBaseProgram::AddArgument(
              this,
              a2: *(_DWORD *)(v40 + 4),
              a3: *(_DWORD *)(v40 + 12),
              a4: *(_DWORD *)(v40 + 16),
              a5: *(double *)(v40 + 32));
      for ( m = 0; m < (*(_DWORD *)v38 & 0xFFFFFu); ++m )
        *(_DWORD *)(*((_DWORD *)v38 + 2) + 4 * m) = v48;
      v72 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v48);
      D3DXShader::CArgument::Initialize(this: v72, a2: (struct D3DXShader::CArgument *)v40);
      v50 = v72;
      *((_DWORD *)v72 + 3) = v77;
      v47 = v73;
      *(_DWORD *)(v40 + 64) = 1;
      *((_DWORD *)v50 + 16) = 0;
    }
    *v47 = v38;
    goto LABEL_122;
  }
  if ( v76 != 2 )
    goto LABEL_123;
  if ( v40 != 0 )
  {
    v51 = *(_DWORD *)(v40 + 4);
    v52 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v51);
    v53 = *(_DWORD *)(v40 + 12);
    v73 = (struct D3DXShader::CInstruction **)v52;
    if ( v53 >= 6 )
      goto LABEL_124;
    if ( (*(_WORD *)(v52 + 4) & 0x840) != 0 )
    {
      v54 = (int *)((char *)this + 4 * v53 + 1060);
      v55 = *v54;
      if ( *v54 == -1 )
      {
        if ( a2[v53] == nullptr )
        {
          *((_DWORD *)this + v53 + 259) = v51;
          *v54 = **((_DWORD **)v38 + 2);
LABEL_121:
          a2[v53] = v38;
LABEL_122:
          *((_DWORD *)a4[j] + 9) = 1;
          goto LABEL_123;
        }
        v55 = -1;
      }
      if ( v55 == **((_DWORD **)v38 + 2) )
      {
        if ( a2[v53] != nullptr )
        {
          D3DXShader::CProgram::Error(
            this,
            a2: nullptr,
            a3: 0x11A6u,
            format: "cannot perform texture lookup twice from a user bound or similar array access sampler in ps_1_%i",
            (unsigned __int8)*((_DWORD *)this + 50));
          return -2147467259;
        }
        goto LABEL_121;
      }
      if ( (*((_BYTE *)v73 + 5) & 8) != 0 )
        v69 = "conflicting user defined sampler bindings. If two samplers have the same user binding, they cannot both be"
              " used in the same shader";
      else
        v69 = "conflicting sampler array bindings";
      D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x11A5u, format: v69);
      return -2147467259;
    }
  }
  v53 = 0;
  v56 = *((_DWORD *)this + 19) == 0;
  if ( *((_DWORD *)this + 19) != 0 )
  {
    v78 = (_DWORD *)((char *)this + 1060);
    do
    {
      if ( a2[v53] == nullptr && (*v78 == **((_DWORD **)v38 + 2) || *v78 == -1) )
        break;
      ++v78;
      ++v53;
    }
    while ( v53 < *((_DWORD *)this + 19) );
    v56 = v53 == *((_DWORD *)this + 19);
  }
  if ( v56 )
  {
    D3DXShader::CProgram::Error(
      this,
      a2: nullptr,
      a3: 0x11A7u,
      format: "too many texture loads and reads from texcoords");
    return -2147467259;
  }
  v79 = v53;
  if ( v40 != 0 )
  {
    if ( (unsigned __int16)*((_DWORD *)this + 50) == 260 || v72 == *((D3DXShader::CArgument **)this + 32) )
    {
      *((_DWORD *)this + v53 + 259) = *(_DWORD *)(v40 + 4);
      *((_DWORD *)this + v53 + 265) = **((_DWORD **)v38 + 2);
    }
    v57 = D3DXShader::CBaseProgram::AddArgument(
            this,
            a2: *(_DWORD *)(v40 + 4),
            a3: *(_DWORD *)(v40 + 12),
            a4: *(_DWORD *)(v40 + 16),
            a5: *(double *)(v40 + 32));
    for ( n = 0; n < (*(_DWORD *)v38 & 0xFFFFFu); ++n )
      *(_DWORD *)(*((_DWORD *)v38 + 2) + 4 * n) = v57;
    v72 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v57);
    D3DXShader::CArgument::Initialize(this: v72, a2: (struct D3DXShader::CArgument *)v40);
    v59 = v72;
    *((_DWORD *)v72 + 3) = v79;
    *(_DWORD *)(v40 + 64) = 1;
    *((_DWORD *)v59 + 16) = 0;
    v53 = v79;
  }
  goto LABEL_121;
}

//------------------------------------------------------------------------------
// Address: 0x102057B7
// Name: protected: long D3DXShader::CPSLegacyProgram::GroupTexLoads(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::GroupTexLoads(D3DXShader::CPSLegacyProgram *this)
{
  bool v2; // zf
  int *v3; // eax
  int v4; // ecx
  unsigned int v5; // edx
  int v6; // edi
  unsigned int v7; // ecx
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  _DWORD *v12; // eax
  unsigned int v13; // ecx
  bool v14; // cf
  _DWORD *v15; // ebx
  unsigned int *v16; // edx
  unsigned int v17; // eax
  int v18; // ecx
  unsigned int i; // eax
  int v20; // ecx
  unsigned int v21; // ebx
  void *v22; // edi
  int result; // eax
  int v24; // eax
  int v25; // eax
  _DWORD *v26; // eax
  void *v27; // eax
  void *v28; // eax
  struct D3DXShader::CInstruction **v29; // eax
  void *v30; // edi
  _DWORD *v31; // eax
  unsigned int v32; // edx
  int v33; // ecx
  unsigned int *v34; // edx
  int v35; // ecx
  int v36; // edi
  int v37; // edi
  unsigned int v38; // edx
  _DWORD *v39; // eax
  int v40; // ecx
  unsigned int k; // eax
  unsigned int j; // ecx
  int v43; // eax
  _DWORD v44[6]; // [esp+Ch] [ebp-70h] BYREF
  _DWORD v45[6]; // [esp+24h] [ebp-58h] BYREF
  unsigned int v46[6]; // [esp+3Ch] [ebp-40h] BYREF
  unsigned int v47; // [esp+54h] [ebp-28h]
  int v48; // [esp+58h] [ebp-24h]
  int v49; // [esp+5Ch] [ebp-20h]
  unsigned int v50; // [esp+60h] [ebp-1Ch]
  _DWORD *v51; // [esp+64h] [ebp-18h]
  int v52; // [esp+68h] [ebp-14h]
  void *pMem; // [esp+6Ch] [ebp-10h]
  unsigned int v54; // [esp+70h] [ebp-Ch] BYREF
  struct D3DXShader::CInstruction **v55; // [esp+74h] [ebp-8h]
  unsigned int v56; // [esp+78h] [ebp-4h]

  pMem = nullptr;
  v55 = nullptr;
  memset(v45, 0, sizeof(v45));
  memset(v44, 0, sizeof(v44));
  memset(v46, 0, sizeof(v46));
  memset((char *)this + 1036, 0xFFu, 0x18u);
  memset((char *)this + 1060, 0xFFu, 0x18u);
  v2 = *((_DWORD *)this + 3) == 0;
  v52 = 1;
  v50 = 0;
  v56 = 0;
  if ( v2 )
    goto LABEL_32;
  do
  {
    v3 = *(int **)(*((_DWORD *)this + 6) + 4 * v56);
    v4 = *v3;
    v5 = *v3 & 0xFFF00000;
    v3[9] = 0;
    if ( v5 != 1610612736
      && v5 != 1615855616
      && v5 != 1621098496
      && v5 != 1927282688
      && v5 != 1617952768
      && v5 != 1626341376 )
    {
      if ( v5 == 285212672 )
      {
        v24 = *(_DWORD *)v3[2];
        goto LABEL_40;
      }
      if ( v5 != 1925185536 && v5 != 1926234112 )
      {
        v6 = v4 & 0xFFFFF;
        v48 = v4 & 0xFFFFF;
        if ( (v4 & 0xFFFFF) != 0 && v4 != 0 )
        {
          v54 = 0;
          if ( v3[1] != 0 )
          {
            v7 = v3[1];
            v8 = (_DWORD *)v3[2];
            v47 = v7;
            v51 = v8;
            do
            {
              v9 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v51);
              if ( *(_DWORD *)(v9 + 4) == *((_DWORD *)this + 32) )
              {
                v10 = *(unsigned __int8 *)(v9 + 109);
                if ( *(_BYTE *)(v9 + 108) == 3 )
                {
                  v11 = v10;
                  v12 = &v45[v10];
                  if ( *v12 != 0 && (unsigned __int16)*((_DWORD *)this + 50) != 260 && v46[v11] == 0 )
                    v52 = 0;
                  *v12 = 1;
                  v13 = v54 + v6;
                  v14 = v54 < v54 + v6;
                  v44[v11] = 1;
                  if ( v14 )
                  {
                    v15 = v51;
                    v16 = &v46[v11];
                    v17 = *v16;
                    v49 = v13 - v54;
                    do
                    {
                      v18 = *((_DWORD *)this + 5);
                      if ( *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v15) + 16) + 1 > v17 )
                        v17 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v15) + 16) + 1;
                      ++v15;
                      --v49;
                    }
                    while ( v49 != 0 );
                    v6 = v48;
                    *v16 = v17;
                  }
                }
              }
              v54 += v6;
              v51 += v6;
            }
            while ( v54 < v47 );
          }
          ++v50;
        }
        goto LABEL_29;
      }
    }
    v24 = *(_DWORD *)(v3[2] + 4 * (v4 & 0xFFFFF));
LABEL_40:
    v25 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v24);
    if ( *(_DWORD *)(v25 + 4) != *((_DWORD *)this + 32) || *(_DWORD *)(v25 + 60) != 0 )
    {
      v52 = 0;
    }
    else
    {
      if ( *(_BYTE *)(v25 + 108) != 3 )
      {
        D3DXShader::CProgram::Error(
          this,
          a2: *(struct D3DXShader::CNode **)(v25 + 96),
          a3: 0x11A1u,
          format: "texture loads or clips cannot be from inputs not marked TEXCOORD");
        return -2147467259;
      }
      v26 = &v45[*(unsigned __int8 *)(v25 + 109)];
      if ( *v26 != 0 && (unsigned __int16)*((_DWORD *)this + 50) != 260 )
        v52 = 0;
      *v26 = 1;
    }
LABEL_29:
    ++v56;
  }
  while ( v56 < *((_DWORD *)this + 3) );
  if ( v50 > 0x10 )
    v52 = 0;
LABEL_32:
  for ( i = 0; i < *((_DWORD *)this + 2); *(_DWORD *)(v20 + 64) = 0 )
    v20 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * i++);
  v21 = *((_DWORD *)this + 3);
  v47 = v21;
  if ( v52 != 0 )
  {
    *((_DWORD *)this + 139) = 0;
    v22 = MemAlloc_Alloc(nSize: 0x800u);
    *((_DWORD *)this + 140) = v22;
    if ( v22 != nullptr )
    {
      memset(v22, 0, 0x800u);
      result = D3DXShader::CPSLegacyProgram::TexturePullOut(
                 this,
                 a2: *((struct D3DXShader::CInstruction ***)this + 140),
                 a3: (unsigned int *)this + 137,
                 a4: *((struct D3DXShader::CInstruction ***)this + 6),
                 a5: v21,
                 a6: nullptr,
                 a7: 0);
      if ( result < 0 )
        return result;
LABEL_82:
      v37 = 0;
      for ( j = 0; j < *((_DWORD *)this + 2); ++j )
      {
        v43 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * j);
        if ( *(_DWORD *)(v43 + 64) == 1 )
          *(_DWORD *)(v43 + 4) = *((_DWORD *)this + 29);
      }
      goto LABEL_86;
    }
    return -2147024882;
  }
  v27 = MemAlloc_Alloc(nSize: 0x800u);
  *((_DWORD *)this + 139) = v27;
  if ( v27 == nullptr )
    return -2147024882;
  v28 = MemAlloc_Alloc(nSize: 0x800u);
  *((_DWORD *)this + 140) = v28;
  if ( v28 == nullptr )
    return -2147024882;
  pMem = MemAlloc_Alloc(nSize: 0x800u);
  if ( pMem == nullptr )
    return -2147024882;
  v29 = (struct D3DXShader::CInstruction **)MemAlloc_Alloc(nSize: 0x800u);
  v30 = *((void **)this + 139);
  v55 = v29;
  memset(v30, 0, 0x800u);
  memset(*((void **)this + 140), 0, 0x800u);
  memset(pMem, 0, 0x800u);
  memset(v55, 0, 0x800u);
  v2 = *((_DWORD *)this + 3) == 0;
  *((_DWORD *)this + 136) = 0;
  *((_DWORD *)this + 137) = 0;
  v54 = 0;
  v56 = 0;
  if ( v2 )
  {
LABEL_75:
    v38 = 0;
    if ( v54 != 0 )
    {
      v39 = pMem;
      v40 = (char *)v55 - (_BYTE *)pMem;
      do
      {
        *(_DWORD *)((char *)v39 + v40) = *v39;
        *v39 = 0;
        ++v38;
        ++v39;
      }
      while ( v38 < v54 );
    }
    v37 = D3DXShader::CPSLegacyProgram::TexturePullOut(
            this,
            a2: *((struct D3DXShader::CInstruction ***)this + 140),
            a3: (unsigned int *)this + 137,
            a4: *((struct D3DXShader::CInstruction ***)this + 6),
            a5: v47,
            a6: nullptr,
            a7: 0);
    if ( v37 < 0 )
      goto LABEL_86;
    for ( k = 0; k < v54; ++k )
      *((_DWORD *)v55[k] + 9) = 0;
    v37 = D3DXShader::CPSLegacyProgram::TexturePullOut(
            this,
            a2: *((struct D3DXShader::CInstruction ***)this + 139),
            a3: (unsigned int *)this + 136,
            a4: v55,
            a5: v54,
            a6: *((struct D3DXShader::CInstruction ***)this + 140),
            a7: *((_DWORD *)this + 19));
    if ( v37 < 0 )
      goto LABEL_86;
    goto LABEL_82;
  }
  while ( 2 )
  {
    if ( v56 >= 0x200 )
    {
      D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x11A2u, format: "program too big");
      return -2147467259;
    }
    v31 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v56);
    v32 = *v31 & 0xFFF00000;
    if ( v32 != 1610612736
      && v32 != 1615855616
      && v32 != 1621098496
      && v32 != 1927282688
      && v32 != 1617952768
      && v32 != 1626341376
      && v32 != 285212672
      && v32 != 1926234112
      && v32 != 1925185536 )
    {
LABEL_74:
      if ( ++v56 >= *((_DWORD *)this + 3) )
        goto LABEL_75;
      continue;
    }
    break;
  }
  v33 = *v31 & 0xFFFFF;
  v49 = v33;
  if ( v32 == 285212672 )
  {
    v33 = 0;
    v49 = 0;
  }
  v34 = (unsigned int *)(v31[2] + 4 * v33);
  v35 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v34);
  v36 = *(_DWORD *)(v35 + 4);
  if ( v36 == *((_DWORD *)this + 34) || *(_DWORD *)(v35 + 60) != 0 )
  {
    v37 = D3DXShader::CPSLegacyProgram::PullOut(
            this,
            a2: v34,
            a3: v31[1] - v49,
            a4: (struct D3DXShader::CInstruction **)pMem,
            a5: &v54);
    if ( v37 < 0 )
      goto LABEL_86;
    goto LABEL_74;
  }
  if ( v36 != *((_DWORD *)this + 32) )
    goto LABEL_74;
  if ( *(_BYTE *)(v35 + 108) == 3 )
  {
    if ( v44[*(unsigned __int8 *)(v35 + 109)] != 0 && (unsigned __int16)*((_DWORD *)this + 50) != 260 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: nullptr,
        a3: 0x11A8u,
        format: "can read from texcoord and use it for texlookup only in ps_1_4 and higher");
      goto LABEL_94;
    }
    goto LABEL_74;
  }
  D3DXShader::CProgram::Error(
    this,
    a2: nullptr,
    a3: 0x11A1u,
    format: "cannot perform dependent texture read which in any way is based on color inputs");
LABEL_94:
  v37 = -2147467259;
LABEL_86:
  if ( pMem != nullptr )
    free(pMem);
  if ( v55 != nullptr )
    free(pMem: v55);
  return v37;
}

//------------------------------------------------------------------------------
// Address: 0x10205D18
// Name: protected: unsigned int D3DXShader::CPSLegacyProgram::RegReassign(class D3DXShader::CInstruction __near * __near *,unsigned int,unsigned int,unsigned int,class D3DXShader::CArgument __near *,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CPSLegacyProgram::RegReassign(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        struct D3DXShader::CArgument *a6,
        int *a7)
{
  unsigned int i; // ecx
  struct D3DXShader::CInstruction *v8; // edi
  unsigned int v9; // ebx
  int v10; // esi
  _DWORD *v11; // edx
  unsigned int v14; // [esp+4h] [ebp-4h]

  v14 = 0;
  *a7 = 0;
  for ( i = a3; i < a4; ++i )
  {
    v8 = a2[i];
    v9 = 0;
    if ( v8 != nullptr && *((_DWORD *)v8 + 1) != 0 )
    {
      do
      {
        v10 = *(_DWORD *)(*((_DWORD *)v8 + 2) + 4 * v9);
        v11 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v10);
        if ( v10 == a5 || v11[14] == a5 )
        {
          v11[3] = *((_DWORD *)a6 + 3);
          v11[4] = *((_DWORD *)a6 + 4);
          v14 = i;
          *a7 = 1;
        }
        ++v9;
      }
      while ( v9 < *((_DWORD *)v8 + 1) );
    }
  }
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10205D95
// Name: protected: long D3DXShader::CPSLegacyProgram::Save(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::Save(D3DXShader::CPSLegacyProgram *this)
{
  int v2; // edi
  int v3; // ebx
  void *v4; // eax
  bool v5; // zf
  unsigned __int8 *v6; // eax
  int v7; // eax
  D3DXShader::CInstruction *v8; // ecx
  int v9; // edi
  unsigned __int8 *v10; // eax
  D3DXShader::CArgument *v11; // eax
  D3DXShader::CArgument *v12; // ecx

  v2 = 0;
  v3 = 0;
  *((_DWORD *)this + 173) = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 3));
  v4 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 2));
  v5 = *((_DWORD *)this + 173) == 0;
  *((_DWORD *)this + 174) = v4;
  if ( v5 || v4 == nullptr )
    return -2147024882;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    do
    {
      v6 = D3DXShader::CInstruction::operator new(a1: 0x74u);
      v7 = v6 != nullptr ? D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v6) : 0;
      *(_DWORD *)(*((_DWORD *)this + 173) + 4 * v2) = v7;
      v8 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 173) + 4 * v2);
      if ( v8 == nullptr )
        return -2147024882;
      v3 = D3DXShader::CInstruction::Initialize(
             this: v8,
             a2: *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v2));
      if ( v3 < 0 )
        return v3;
    }
    while ( (unsigned int)++v2 < *((_DWORD *)this + 3) );
  }
  v9 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    do
    {
      v10 = D3DXShader::CArgument::operator new(a1: 0x80u);
      v11 = v10 != nullptr ? D3DXShader::CArgument::CArgument(this: (D3DXShader::CArgument *)v10) : nullptr;
      *(_DWORD *)(*((_DWORD *)this + 174) + 4 * v9) = v11;
      v12 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 174) + 4 * v9);
      if ( v12 == nullptr )
        return -2147024882;
      v3 = D3DXShader::CArgument::Initialize(
             this: v12,
             a2: *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v9));
      if ( v3 < 0 )
        return v3;
    }
    while ( (unsigned int)++v9 < *((_DWORD *)this + 2) );
  }
  *((_DWORD *)this + 176) = *((_DWORD *)this + 3);
  *((_DWORD *)this + 175) = *((_DWORD *)this + 2);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10205E8E
// Name: protected: long D3DXShader::CPSLegacyProgram::Restore(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::Restore(D3DXShader::CPSLegacyProgram *this)
{
  int v2; // esi
  int v3; // esi
  unsigned int j; // ecx
  int v5; // esi
  int v6; // edx
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 176); ++i )
  {
    v2 = *(_DWORD *)(4 * i + *((_DWORD *)this + 173));
    qmemcpy(
      *(void **)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * i) + 8),
      *(const void **)(v2 + 8),
      4 * *(_DWORD *)(v2 + 4));
    v3 = *(_DWORD *)(4 * i + *((_DWORD *)this + 173));
    qmemcpy(
      *(void **)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * i) + 16),
      *(const void **)(v3 + 16),
      4 * *(_DWORD *)(v3 + 12));
  }
  for ( j = 0; j < *((_DWORD *)this + 175); *(_DWORD *)(v5 + 56) = v6 )
  {
    v5 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * j);
    v6 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 174) + 4 * j++) + 56);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10205F3B
// Name: protected: long D3DXShader::CPSLegacyProgram::CreateTexLoads(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::CreateTexLoads(D3DXShader::CPSLegacyProgram *this)
{
  int v2; // eax
  unsigned int v3; // ecx
  _DWORD *v4; // ebx
  int v5; // ecx
  unsigned int v6; // edi
  int v7; // edx
  int v8; // ecx
  unsigned int *v9; // eax
  unsigned int v10; // ecx
  unsigned int *v11; // eax
  unsigned int v12; // edx
  unsigned __int8 *v13; // eax
  int v14; // edi
  int v15; // ebx
  unsigned int k; // ebx
  unsigned int v17; // ebx
  unsigned int v18; // eax
  int v19; // ecx
  unsigned int v20; // edx
  _DWORD *v21; // edi
  int v22; // edx
  int v23; // ecx
  _DWORD *v24; // eax
  int v25; // eax
  int v27; // eax
  unsigned __int8 *v28; // eax
  D3DXShader::CInstruction *v29; // ebx
  int v30; // ecx
  int v31; // eax
  unsigned int v32; // eax
  unsigned int v33; // edx
  int v34; // ecx
  int v35; // eax
  int v36; // edx
  int v37; // ecx
  unsigned int j; // edi
  int v39; // eax
  struct D3DXShader::CInstruction *v40; // edi
  int v41; // eax
  int v42; // ecx
  int v43; // edx
  unsigned int v44; // eax
  int v45; // ecx
  int v46; // eax
  int v47; // ecx
  unsigned __int8 *v48; // eax
  int v49; // eax
  unsigned int v50; // ebx
  unsigned int v51; // eax
  unsigned int v52; // edx
  unsigned int v53; // [esp-4h] [ebp-48h]
  D3DXShader *v54; // [esp+4h] [ebp-40h]
  unsigned int v55; // [esp+8h] [ebp-3Ch]
  _DWORD v56[6]; // [esp+14h] [ebp-30h] BYREF
  unsigned int v57; // [esp+2Ch] [ebp-18h]
  unsigned int v58; // [esp+30h] [ebp-14h]
  int v59; // [esp+34h] [ebp-10h]
  unsigned int v60; // [esp+38h] [ebp-Ch]
  unsigned int i; // [esp+3Ch] [ebp-8h]
  D3DXShader::CInstruction *v62; // [esp+40h] [ebp-4h]

  memset(v56, 0, sizeof(v56));
  v58 = *((_DWORD *)this + 3);
  if ( v58 != 0 )
  {
    v60 = *((_DWORD *)this + 6);
    for ( i = v58; i != 0; --i )
    {
      v2 = *(_DWORD *)v60;
      if ( *(_DWORD *)v60 != 0 )
      {
        v62 = *(D3DXShader::CInstruction **)v2;
        if ( v62 != nullptr )
        {
          v3 = *(_DWORD *)(v2 + 4);
          v59 = 0;
          v57 = v3;
          if ( v3 != 0 )
          {
            v4 = *(_DWORD **)(v2 + 8);
            do
            {
              v5 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v4);
              if ( *(_DWORD *)(v5 + 4) == *((_DWORD *)this + 32) )
              {
                if ( *(unsigned __int8 *)(v5 + 109) > 5u )
                  break;
                if ( *(_BYTE *)(v5 + 108) == 3 )
                {
                  v6 = (unsigned int)v62 & 0xFFF00000;
                  if ( D3DXShader::IsTextureInst(this: (D3DXShader *)((unsigned int)v62 & 0xFFF00000), a2: v55) != 0
                    || v6 == 285212672 )
                  {
                    v11 = &v56[v7];
                    v12 = *(_DWORD *)(v8 + 16) + 1;
                    if ( v12 > *v11 && *(_DWORD *)(v8 + 60) != 0 )
                      *v11 = v12;
                  }
                  else
                  {
                    v9 = &v56[v7];
                    v10 = *(_DWORD *)(v8 + 16) + 1;
                    if ( v10 > *v9 )
                      *v9 = v10;
                  }
                }
              }
              ++v59;
              ++v4;
            }
            while ( v59 < v57 );
          }
        }
      }
      v60 += 4;
    }
  }
  i = 0;
  v62 = (D3DXShader::CInstruction *)v56;
  while ( *(_DWORD *)v62 == 0 )
  {
LABEL_34:
    ++i;
    v62 = (D3DXShader::CInstruction *)((char *)v62 + 4);
    if ( i >= 6 )
    {
      v62 = nullptr;
      if ( v58 == 0 )
      {
LABEL_59:
        for ( j = 0; j < v58; ++j )
        {
          v15 = D3DXShader::CBaseProgram::CopyInstruction(
                  this,
                  a2: *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * j));
          if ( v15 < 0 )
            return v15;
          **(_DWORD **)(*((_DWORD *)this + 6) + 4 * j) = 0;
        }
        v39 = *((_DWORD *)this + 3);
        v58 = 0;
        v59 = v39;
        if ( v39 == 0 )
          return D3DXShader::CProgram::CompactInstructions(this);
        while ( 1 )
        {
          v40 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v58);
          v41 = *(_DWORD *)v40;
          if ( *(_DWORD *)v40 != 0 )
          {
            v60 = v41 & 0xFFFFF;
            if ( D3DXShader::IsTextureInst(this: (D3DXShader *)(v41 & 0xFFF00000), a2: v55) != 0 || v42 == 285212672 )
            {
              v43 = *((_DWORD *)this + 4);
              v44 = v42 != 285212672 ? v60 : 0;
              v45 = *((_DWORD *)v40 + 2);
              v57 = 4 * v44;
              v46 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(4 * v44 + v45));
              v47 = *(_DWORD *)(*(_DWORD *)(v43 + 4 * *(_DWORD *)(v46 + 4)) + 4);
              if ( (v47 & 0x200) != 0 || (v47 & 0x10) != 0 && *(_BYTE *)(v46 + 108) == 1 )
              {
                v48 = D3DXShader::CInstruction::operator new(a1: 0x74u);
                if ( v48 != nullptr )
                  v62 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v48);
                else
                  v62 = nullptr;
                if ( v62 == nullptr )
                  return -2147024882;
                v15 = D3DXShader::CInstruction::Initialize(
                        this: v62,
                        a2: v60 & 0xFFFFF | 0x10000000,
                        a3: v60,
                        a4: v60,
                        a5: 0);
                if ( v15 < 0 )
                  return v15;
                v15 = D3DXShader::CInstruction::Instance(this: v62, a2: v40);
                if ( v15 < 0 )
                  return v15;
                i = 0;
                if ( v60 != 0 )
                {
                  v49 = *((_DWORD *)v40 + 2);
                  v50 = v57;
                  do
                  {
                    v53 = i;
                    *(_DWORD *)(*((_DWORD *)v62 + 2) + 4 * i) = *(_DWORD *)(v49 + v50);
                    v51 = D3DXShader::CBaseProgram::AddArgument(
                            this,
                            a2: *((_DWORD *)this + 34),
                            a3: 0,
                            a4: v53,
                            a5: 0.0);
                    v52 = i;
                    *(_DWORD *)(*((_DWORD *)v62 + 4) + 4 * i) = v51;
                    *(_DWORD *)(v50 + *((_DWORD *)v40 + 2)) = *(_DWORD *)(*((_DWORD *)v62 + 4) + 4 * v52);
                    v49 = *((_DWORD *)v40 + 2);
                    if ( *(_DWORD *)(v49 + v50) == -1 )
                      return -2147024882;
                    ++i;
                    v50 += 4;
                  }
                  while ( i < v60 );
                }
                D3DXShader::CBaseProgram::AddInstruction(this, a2: v62);
              }
            }
            D3DXShader::CBaseProgram::CopyInstruction(this, a2: v40);
            *(_DWORD *)v40 = 0;
          }
          if ( ++v58 >= v59 )
            return D3DXShader::CProgram::CompactInstructions(this);
        }
      }
      while ( 1 )
      {
        v21 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * (_DWORD)v62);
        v54 = (D3DXShader *)(*v21 & 0xFFF00000);
        v60 = *v21 & 0xFFFFF;
        if ( D3DXShader::IsTextureInst(this: v54, a2: v55) != 0 || v22 == 285212672 )
        {
          v24 = (_DWORD *)v21[2];
          v25 = v22 == 285212672 ? *v24 : v24[v23];
          v27 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v25);
          if ( (*(_BYTE *)(v27 + 62) & 0x1F) != 0 && *(_DWORD *)(v27 + 4) == *((_DWORD *)this + 34) )
          {
            v28 = D3DXShader::CInstruction::operator new(a1: 0x74u);
            if ( v28 != nullptr )
              v29 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v28);
            else
              v29 = nullptr;
            if ( v29 == nullptr )
              return -2147024882;
            v59 = D3DXShader::CInstruction::Initialize(
                    this: v29,
                    a2: v60 & 0xFFFFF | 0x10000000,
                    a3: v60,
                    a4: v60,
                    a5: 0);
            if ( v59 < 0 )
              return v59;
            v30 = *v21 & 0xFFFFF;
            if ( (*v21 & 0xFFF00000) == 0x11000000 )
              v30 = 0;
            i = 0;
            if ( v60 != 0 )
            {
              v59 = 4 * v30;
              do
              {
                v31 = *(_DWORD *)(v59 + v21[2]);
                v57 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v31);
                *(_DWORD *)(*((_DWORD *)v29 + 2) + 4 * i) = v31;
                v32 = D3DXShader::CBaseProgram::AddArgument(
                        this,
                        a2: *((_DWORD *)this + 34),
                        a3: 0,
                        a4: *(_DWORD *)(v57 + 16),
                        a5: 0.0);
                v33 = i;
                v34 = *((_DWORD *)v29 + 4);
                ++i;
                *(_DWORD *)(v34 + 4 * v33) = v32;
                v35 = *(_DWORD *)(*((_DWORD *)v29 + 4) + 4 * v33);
                v36 = v59;
                v37 = v21[2];
                v59 += 4;
                *(_DWORD *)(v36 + v37) = v35;
              }
              while ( i < v60 );
            }
            v59 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v29);
            if ( v59 < 0 )
              return v59;
          }
        }
        v62 = (D3DXShader::CInstruction *)((char *)v62 + 1);
        if ( (unsigned int)v62 >= v58 )
          goto LABEL_59;
      }
    }
  }
  v13 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v13 != nullptr )
    v14 = D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v13);
  else
    v14 = 0;
  if ( v14 == 0 )
    return -2147024882;
  v15 = D3DXShader::CInstruction::Initialize(
          this: (D3DXShader::CInstruction *)v14,
          a2: *(_DWORD *)v62 & 0xFFFFF | 0x72100000,
          a3: *(_DWORD *)v62,
          a4: *(_DWORD *)v62,
          a5: 0);
  if ( v15 < 0 )
    return v15;
  for ( k = 0; k < *(_DWORD *)v62; ++k )
  {
    *(_DWORD *)(*(_DWORD *)(v14 + 16) + 4 * k) = D3DXShader::CBaseProgram::AddArgument(
                                                   this,
                                                   a2: *((_DWORD *)this + 34),
                                                   a3: 0,
                                                   a4: k,
                                                   a5: 0.0);
    if ( *(_DWORD *)(*(_DWORD *)(v14 + 16) + 4 * k) == -1 )
    {
      D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v14, a2: 1);
      return -2147024882;
    }
  }
  v15 = D3DXShader::CPSLegacyProgram::RemapInput(
          this,
          a2: *((struct D3DXShader::CInstruction ***)this + 6),
          a3: *((_DWORD *)this + 3),
          a4: 3u,
          a5: i,
          a6: *(_DWORD *)v62,
          a7: *(unsigned int **)(v14 + 16));
  if ( v15 < 0 )
  {
    D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v14, a2: 1);
    return v15;
  }
  v17 = 0;
  if ( *(_DWORD *)v62 == 0 )
  {
LABEL_33:
    v15 = D3DXShader::CBaseProgram::AddInstruction(this, a2: (struct D3DXShader::CInstruction *)v14);
    v59 = v15;
    if ( v15 < 0 )
      return v15;
    goto LABEL_34;
  }
  while ( 1 )
  {
    v18 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 32), a3: i, a4: v17, a5: 0.0);
    if ( v18 == -1 )
      break;
    v19 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v18);
    v20 = i;
    *(_DWORD *)(v19 + 60) = 0;
    *(_DWORD *)(v19 + 108) = (v20 << 8) | 3;
    *(_DWORD *)(*(_DWORD *)(v14 + 8) + 4 * v17++) = v18;
    if ( v17 >= *(_DWORD *)v62 )
      goto LABEL_33;
  }
  D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v14, a2: 1);
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x1020649B
// Name: protected: long D3DXShader::CPSLegacyProgram::SetupDependency(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall D3DXShader::CPSLegacyProgram::SetupDependency@<eax>(
        D3DXShader::CPSLegacyProgram *this@<ecx>,
        unsigned int a2@<edi>)
{
  unsigned int i; // eax
  int v4; // edx
  struct D3DXShader::CInstruction *v5; // edi
  int v6; // edx
  struct D3DXShader::CInstruction **v7; // ecx
  int v8; // ebx
  unsigned int v10; // [esp-8h] [ebp-14h]
  int v11; // [esp+4h] [ebp-8h]
  unsigned int v12; // [esp+8h] [ebp-4h]

  v11 = D3DXShader::CPSLegacyProgram::LegacyChildParentInfo(
          this,
          a2: *((struct D3DXShader::CInstruction ***)this + 6),
          a3: *((_DWORD *)this + 3));
  if ( v11 >= 0 )
  {
    for ( i = 0; i < *((_DWORD *)this + 3); *(_DWORD *)(v4 + 36) = 0 )
    {
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * i) + 40) = 0;
      v4 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * i++);
    }
    v12 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      v10 = a2;
      do
      {
        v5 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v12);
        if ( D3DXShader::IsTextureInst(this: (D3DXShader *)(*(_DWORD *)v5 & 0xFFF00000), a2: v10) != 0
          || v6 == 285212672 )
        {
          v8 = *((_DWORD *)v5 + 9);
          D3DXShader::CShaderProgram::ColorParents(this, a2: v7, a3: v5, a4: 1u);
          *((_DWORD *)v5 + 9) = v8;
        }
        ++v12;
      }
      while ( v12 < *((_DWORD *)this + 3) );
    }
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x10206529
// Name: protected: unsigned int D3DXShader::CPSLegacyProgram::EnumerateCombos(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EnumerateCombos(D3DXShader::CPSLegacyProgram *this)
{
  unsigned int v1; // ebx
  int v2; // esi
  _DWORD *v3; // edi
  int v4; // edx
  unsigned int v6; // [esp+0h] [ebp-Ch]

  v1 = 0;
  v2 = 0;
  if ( *((_DWORD *)this + 3) == 0 )
  {
LABEL_9:
    *((_DWORD *)this + 288) = v1;
    return 1 << v1;
  }
  v3 = (_DWORD *)((char *)this + 1104);
  while ( 1 )
  {
    if ( D3DXShader::IsTextureInst(
           this: (D3DXShader *)(**(_DWORD **)(*((_DWORD *)this + 6) + 4 * v2) & 0xFFF00000),
           a2: v6) != 0
      || v4 == 1913651200
      || v4 == 285212672 )
    {
      if ( v1 >= 0xC )
        return -1;
      *v3 = v2;
      ++v1;
      ++v3;
    }
    if ( (unsigned int)++v2 >= *((_DWORD *)this + 3) )
      goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020658C
// Name: protected: int D3DXShader::CPSLegacyProgram::CheckDependents(class D3DXShader::CInstruction __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::CheckDependents(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction *a2,
        unsigned int a3)
{
  int v4; // edi
  unsigned int v6; // [esp+0h] [ebp-Ch]

  v4 = 0;
  if ( D3DXShader::IsTextureInst(this: (D3DXShader *)(*(_DWORD *)a2 & 0xFFF00000), a2: v6) != 0 )
  {
    if ( *((_DWORD *)a2 + 5) == 0 )
      return 1;
    if ( a3 != 0 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: *((struct D3DXShader::CNode **)a2 + 15),
        a3: 0x1194u,
        format: "dependent texture read chain cannot exceed 1 in ps_1_4");
      return 0;
    }
    a3 = 1;
  }
  if ( *((_DWORD *)a2 + 5) != 0 )
  {
    while ( D3DXShader::CPSLegacyProgram::CheckDependents(
              this,
              a2: *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4
                                                                          * *(_DWORD *)(*((_DWORD *)a2 + 6) + 4 * v4)),
              a3) != 0 )
    {
      if ( (unsigned int)++v4 >= *((_DWORD *)a2 + 5) )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10206603
// Name: protected: int D3DXShader::CPSLegacyProgram::TrivialReject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::TrivialReject(D3DXShader::CPSLegacyProgram *this)
{
  unsigned int v2; // ecx
  unsigned int v3; // edi
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // [esp+8h] [ebp-4h]

  v2 = *((_DWORD *)this + 3);
  v3 = 0;
  v10 = 0;
  if ( v2 <= 0x40 )
  {
    v5 = 0;
    if ( v2 != 0 )
    {
      do
      {
        v6 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v5++);
        *(_DWORD *)(v6 + 40) = 0;
      }
      while ( v5 < *((_DWORD *)this + 3) );
    }
    v7 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      while ( 1 )
      {
        v8 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v7);
        *((_DWORD *)this + 64) = v8;
        if ( *(_DWORD *)(v8 + 36) != 0 && *(_DWORD *)(v8 + 4) != 0 )
        {
          do
          {
            v9 = *((_DWORD *)this + 64);
            if ( *(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4 * v3)) + 108) == 1 )
            {
              D3DXShader::CProgram::Error(
                this,
                a2: *(struct D3DXShader::CNode **)(v9 + 60),
                a3: 0x1194u,
                format: "cannot perform texture load that is in anyway dependent on COLOR registers");
              v10 = 1;
            }
            ++v3;
          }
          while ( v3 < *(_DWORD *)(*((_DWORD *)this + 64) + 4) );
        }
        v3 = 0;
        if ( D3DXShader::CPSLegacyProgram::CheckDependents(
               this,
               a2: *((struct D3DXShader::CInstruction **)this + 64),
               a3: 0) == 0 )
          break;
        if ( (unsigned int)++v7 >= *((_DWORD *)this + 3) )
          return v10;
      }
      return 1;
    }
    return v10;
  }
  else
  {
    D3DXShader::CProgram::Error(
      this,
      a2: nullptr,
      a3: 0x1194u,
      format: "program is order of magnitude too large to compile to ps_1_4");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102066D6
// Name: protected: int D3DXShader::CPSLegacyProgram::AssignSampler(class D3DXShader::CInstruction __near * __near *,unsigned int __near *,class D3DXShader::CInstruction __near * __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::AssignSampler(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int *a3,
        struct D3DXShader::CInstruction **a4,
        unsigned int a5,
        unsigned int a6)
{
  D3DXShader::CPSLegacyProgram *v6; // esi
  unsigned int v7; // eax
  struct D3DXShader::CInstruction **v9; // edi
  struct D3DXShader::CInstruction *v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  struct D3DXShader::CInstruction **v16; // esi
  unsigned int *v17; // eax
  unsigned int v18; // eax
  unsigned int *v19; // esi
  struct D3DXShader::CInstruction **v20; // edx
  struct D3DXShader::CInstruction *v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  char *v24; // edi
  unsigned int v25; // ecx
  unsigned int v26; // eax
  struct D3DXShader::CInstruction **v27; // edx
  struct D3DXShader::CInstruction *v28; // ecx
  unsigned int v29; // eax
  unsigned int j; // eax
  unsigned int v31; // eax
  char *i; // [esp+Ch] [ebp-4h]
  unsigned int v34; // [esp+28h] [ebp+18h]
  unsigned int v35; // [esp+28h] [ebp+18h]
  unsigned int v36; // [esp+28h] [ebp+18h]

  v6 = this;
  if ( a6 == 0 )
  {
    v7 = 0;
    v34 = 0;
    if ( a5 != 0 )
    {
      while ( 1 )
      {
        v9 = &a4[v7];
        v10 = *v9;
        v11 = *(_DWORD *)*v9 & 0xFFF00000;
        if ( v11 != 285212672 && v11 != 1913651200 )
        {
          v12 = **((_DWORD **)v10 + 2);
          v13 = *(_DWORD *)(*((_DWORD *)v6 + 5) + 4 * v12);
          if ( (*(_WORD *)(*(_DWORD *)(*((_DWORD *)v6 + 4) + 4 * *(_DWORD *)(v13 + 4)) + 4) & 0x840) != 0 )
          {
            v14 = *(_DWORD *)(v13 + 12);
            if ( v14 >= 6 )
              return 0;
            v15 = v14;
            v16 = &a2[v15];
            if ( a2[v15] != nullptr )
              return 0;
            v17 = &a3[v15];
            if ( *v17 == -1 )
            {
              *v17 = v12;
            }
            else if ( *v17 != v12 )
            {
              return 0;
            }
            *v16 = v10;
            *v9 = nullptr;
            *v17 = **((_DWORD **)v10 + 2);
          }
        }
        v7 = ++v34;
        if ( v34 >= a5 )
          return 1;
        v6 = this;
      }
    }
    return 1;
  }
  if ( a6 == 1 )
  {
    v18 = 0;
    v35 = 0;
    if ( a5 != 0 )
    {
      v19 = a3;
      while ( 1 )
      {
        v20 = &a4[v18];
        v21 = *v20;
        if ( *v20 != nullptr )
        {
          v22 = *(_DWORD *)v21 & 0xFFF00000;
          if ( v22 != 285212672 && v22 != 1913651200 )
          {
            v23 = 0;
            v24 = (char *)((char *)a2 - (char *)v19);
            for ( i = (char *)((char *)a2 - (char *)v19);
                  *(unsigned int *)((char *)v19 + (_DWORD)v24) != 0 || *v19 != **((_DWORD **)v21 + 2) && *v19 != -1;
                  v24 = i )
            {
              ++v23;
              ++v19;
              if ( v23 >= 6 )
                break;
            }
            if ( v23 == 6 )
              return 0;
            v19 = a3;
            v25 = v23;
            a3[v25] = **((_DWORD **)v21 + 2);
            a2[v25] = v21;
            *v20 = nullptr;
          }
        }
        v18 = ++v35;
        if ( v35 >= a5 )
          return 1;
      }
    }
    return 1;
  }
  if ( a6 != 2 )
    return 1;
  v26 = 0;
  v36 = 0;
  if ( a5 == 0 )
    return 1;
  while ( 1 )
  {
    v27 = &a4[v26];
    v28 = *v27;
    if ( *v27 != nullptr )
    {
      v29 = *(_DWORD *)v28 & 0xFFF00000;
      if ( v29 != 285212672 && v29 != 1913651200 )
        goto LABEL_42;
      for ( j = 0; j < 6; ++j )
      {
        if ( a2[j] == nullptr )
          break;
      }
      if ( j == 6 )
        return 0;
      v31 = j;
      a3[v31] = **((_DWORD **)v28 + 2);
      a2[v31] = v28;
      *v27 = nullptr;
    }
LABEL_42:
    v26 = ++v36;
    if ( v36 >= a5 )
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102068AC
// Name: protected: int D3DXShader::CPSLegacyProgram::InitialCluster(unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::InitialCluster(
        D3DXShader::CPSLegacyProgram *this,
        unsigned int a2,
        int a3)
{
  unsigned int v3; // eax
  unsigned int i; // ecx
  int v6; // eax
  struct D3DXShader::CInstruction *v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // ecx
  int v10; // ecx
  unsigned int v11; // ecx
  unsigned int j; // edi
  _DWORD *v13; // edx
  D3DXShader *v14; // ecx
  _DWORD *v15; // eax
  int v16; // edx
  int v17; // ebx
  unsigned int v18; // eax
  unsigned int k; // ecx
  D3DXShader::CArgument *v20; // ecx
  int v21; // ebx
  unsigned int m; // eax
  bool v23; // zf
  unsigned int n; // eax
  struct D3DXShader::CInstruction *v25; // ecx
  struct D3DXShader::CInstruction *v26; // ecx
  unsigned int v28; // [esp+8h] [ebp-64h]
  struct D3DXShader::CInstruction *v29[6]; // [esp+14h] [ebp-58h] BYREF
  struct D3DXShader::CInstruction *v30[6]; // [esp+2Ch] [ebp-40h] BYREF
  unsigned int v31[6]; // [esp+44h] [ebp-28h] BYREF
  D3DXShader *v32; // [esp+5Ch] [ebp-10h]
  unsigned int IsTextureInst; // [esp+60h] [ebp-Ch]
  unsigned int v34; // [esp+64h] [ebp-8h]
  unsigned int v35; // [esp+68h] [ebp-4h]
  unsigned int v36; // [esp+74h] [ebp+8h]
  int v37; // [esp+78h] [ebp+Ch]

  v3 = a2;
  for ( i = 0; i < 7; ++i )
  {
    if ( v3 == 0 )
      break;
    v3 &= v3 - 1;
  }
  if ( i > 6 )
    return 0;
  v6 = *((_DWORD *)this + 288);
  if ( v6 - i > 6 )
    return 0;
  v35 = 0;
  v34 = 0;
  IsTextureInst = 0;
  if ( v6 != 0 )
  {
    v32 = (D3DXShader::CPSLegacyProgram *)((char *)this + 1104);
    do
    {
      v7 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)v32);
      v8 = *(_DWORD *)v7 & 0xFFF00000;
      if ( ((1 << IsTextureInst) & a2) != 0 )
      {
        if ( *((_DWORD *)v7 + 9) == 1 )
          return 0;
        v9 = v34++;
        v29[v9] = v7;
      }
      else
      {
        if ( v8 == 285212672 )
          return 0;
        if ( v8 != 1913651200 )
        {
          v10 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v7 + 2) + 4 * (*(_DWORD *)v7 & 0xFFFFF)));
          if ( *(_BYTE *)(v10 + 108) != 3 || *(_DWORD *)(v10 + 60) != 0 )
            return 0;
        }
        v11 = v35++;
        v30[v11] = v7;
      }
      ++IsTextureInst;
      v32 = (D3DXShader *)((char *)v32 + 4);
    }
    while ( IsTextureInst < *((_DWORD *)this + 288) );
  }
  memset(v31, 0xFFu, sizeof(v31));
  if ( D3DXShader::CPSLegacyProgram::AssignSampler(
         this,
         a2: *((struct D3DXShader::CInstruction ***)this + 139),
         a3: v31,
         a4: v30,
         a5: v35,
         a6: 0) == 0
    || D3DXShader::CPSLegacyProgram::AssignSampler(
         this,
         a2: *((struct D3DXShader::CInstruction ***)this + 140),
         a3: v31,
         a4: v29,
         a5: v34,
         a6: 0) == 0
    || D3DXShader::CPSLegacyProgram::AssignSampler(
         this,
         a2: *((struct D3DXShader::CInstruction ***)this + 139),
         a3: v31,
         a4: v30,
         a5: v35,
         a6: 1u) == 0
    || D3DXShader::CPSLegacyProgram::AssignSampler(
         this,
         a2: *((struct D3DXShader::CInstruction ***)this + 140),
         a3: v31,
         a4: v29,
         a5: v34,
         a6: 1u) == 0
    || D3DXShader::CPSLegacyProgram::AssignSampler(
         this,
         a2: *((struct D3DXShader::CInstruction ***)this + 139),
         a3: v31,
         a4: v30,
         a5: v35,
         a6: 2u) == 0
    || D3DXShader::CPSLegacyProgram::AssignSampler(
         this,
         a2: *((struct D3DXShader::CInstruction ***)this + 140),
         a3: v31,
         a4: v29,
         a5: v34,
         a6: 2u) == 0 )
  {
    return 0;
  }
  if ( a3 == 0 )
  {
    memset(v29, 0, sizeof(v29));
    memset(v30, 0, sizeof(v30));
    v37 = 0;
    for ( j = 0; j < 0x18; j += 4 )
    {
      v13 = *(_DWORD **)(j + *((_DWORD *)this + 139));
      if ( v13 != nullptr || *(_DWORD *)(j + *((_DWORD *)this + 140)) != 0 )
      {
        v14 = nullptr;
        v32 = nullptr;
        if ( v13 != nullptr )
          v14 = (D3DXShader *)(*v13 & 0xFFF00000);
        v15 = *(_DWORD **)(j + *((_DWORD *)this + 140));
        if ( v15 != nullptr )
          v32 = (D3DXShader *)(*v15 & 0xFFF00000);
        IsTextureInst = D3DXShader::IsTextureInst(this: v14, a2: v28);
        if ( IsTextureInst != 0 || D3DXShader::IsTextureInst(this: v32, a2: v28) != 0 )
        {
          v36 = -1;
          if ( IsTextureInst != 0 )
          {
            v17 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v16 + 8));
            v18 = D3DXShader::CBaseProgram::AddArgument(
                    this,
                    a2: *(_DWORD *)(v17 + 4),
                    a3: *(_DWORD *)(v17 + 12),
                    a4: *(_DWORD *)(v17 + 16),
                    a5: *(double *)(v17 + 32));
            v36 = v18;
            if ( v18 == -1 )
              return 0;
            for ( k = 0; k < (**(_DWORD **)(j + *((_DWORD *)this + 139)) & 0xFFFFFu); ++k )
              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(j + *((_DWORD *)this + 139)) + 8) + 4 * k) = v18;
            v20 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v18);
            v29[j / 4] = (struct D3DXShader::CInstruction *)v17;
            v34 = (unsigned int)v20;
            D3DXShader::CArgument::Initialize(this: v20, a2: (struct D3DXShader::CArgument *)v17);
            *(_DWORD *)(v34 + 12) = v37;
          }
          if ( D3DXShader::IsTextureInst(this: v32, a2: v28) != 0 )
          {
            v21 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*(_DWORD *)(j + *((_DWORD *)this + 140)) + 8));
            if ( v36 == -1 )
            {
              v36 = D3DXShader::CBaseProgram::AddArgument(
                      this,
                      a2: *(_DWORD *)(v21 + 4),
                      a3: *(_DWORD *)(v21 + 12),
                      a4: *(_DWORD *)(v21 + 16),
                      a5: *(double *)(v21 + 32));
              if ( v36 == -1 )
                return 0;
            }
            for ( m = 0; m < (**(_DWORD **)(j + *((_DWORD *)this + 140)) & 0xFFFFFu); ++m )
              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(j + *((_DWORD *)this + 140)) + 8) + 4 * m) = v36;
            v23 = IsTextureInst == 0;
            v30[j / 4] = (struct D3DXShader::CInstruction *)v21;
            if ( v23 )
            {
              v32 = *(D3DXShader **)(*((_DWORD *)this + 5) + 4 * v36);
              D3DXShader::CArgument::Initialize(this: v32, a2: (struct D3DXShader::CArgument *)v21);
              *((_DWORD *)v32 + 3) = v37;
            }
          }
          if ( v36 == -1 )
            return 0;
        }
      }
      ++v37;
    }
    for ( n = 0; n < 6; ++n )
    {
      v25 = v29[n];
      if ( v25 != nullptr )
        *((_DWORD *)v25 + 1) = *((_DWORD *)this + 29);
      v26 = v30[n];
      if ( v26 != nullptr )
        *((_DWORD *)v26 + 1) = *((_DWORD *)this + 29);
    }
  }
  *((_DWORD *)this + 136) = 6;
  *((_DWORD *)this + 137) = 6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10206C8B
// Name: protected: long D3DXShader::CPSLegacyProgram::AddPhaseLinkage(unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::AddPhaseLinkage(D3DXShader::CPSLegacyProgram *this, unsigned int *a2)
{
  int v3; // eax
  bool v4; // zf
  unsigned int v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  int v8; // edx
  unsigned int v9; // edi
  int v10; // edx
  int v11; // ecx
  _DWORD *v12; // ecx
  int *v13; // eax
  int v14; // eax
  _DWORD *v15; // eax
  int v16; // ecx
  int v17; // edx
  unsigned int *v18; // eax
  int n; // edi
  unsigned int v20; // ecx
  unsigned int v21; // ebx
  int v22; // eax
  unsigned int v23; // edx
  int *v24; // ecx
  int v25; // eax
  unsigned int v26; // edi
  unsigned int k; // edx
  unsigned __int8 *v28; // eax
  int v29; // edi
  D3DXShader::CInstruction *v30; // edx
  unsigned int v31; // eax
  int v32; // ecx
  int v33; // edi
  int v34; // eax
  int v35; // eax
  unsigned int v36; // ebx
  int v37; // eax
  unsigned int v38; // edx
  int v39; // ecx
  unsigned int v40; // eax
  _DWORD *v41; // eax
  int v42; // edi
  unsigned int v43; // eax
  unsigned int v44; // edi
  _DWORD *v45; // eax
  int v46; // eax
  unsigned int v47; // ecx
  bool v48; // cc
  _DWORD **v49; // edx
  _DWORD *v50; // eax
  unsigned int v51; // ecx
  unsigned int *v52; // eax
  _DWORD *v53; // eax
  unsigned int v54; // edi
  _DWORD *v55; // eax
  unsigned __int8 *v56; // eax
  int v57; // edi
  unsigned __int8 *v58; // eax
  unsigned int v59; // eax
  unsigned int v60; // ecx
  int v61; // ebx
  _DWORD *v62; // eax
  _DWORD *v63; // eax
  int v64; // eax
  int v65; // edx
  int v66; // eax
  unsigned int v67; // ecx
  unsigned int v68; // edx
  D3DXShader::CInstruction *v69; // eax
  int v70; // ecx
  unsigned int v71; // edx
  int v72; // edi
  int v74; // ecx
  int v75; // edx
  int v76; // eax
  _BYTE v77[152]; // [esp-Ch] [ebp-E4h]
  _DWORD v78[4]; // [esp+8Ch] [ebp-4Ch] BYREF
  unsigned int v79; // [esp+9Ch] [ebp-3Ch]
  unsigned int v80; // [esp+A0h] [ebp-38h]
  unsigned int v81; // [esp+A4h] [ebp-34h]
  int v82; // [esp+A8h] [ebp-30h]
  unsigned int v83; // [esp+ACh] [ebp-2Ch]
  unsigned int i; // [esp+B0h] [ebp-28h]
  unsigned int m; // [esp+B4h] [ebp-24h]
  int v86; // [esp+B8h] [ebp-20h]
  D3DXShader::CInstruction *v87; // [esp+BCh] [ebp-1Ch]
  unsigned int v88; // [esp+C0h] [ebp-18h]
  unsigned int jj; // [esp+C4h] [ebp-14h]
  _DWORD *v90; // [esp+C8h] [ebp-10h]
  unsigned int ii; // [esp+CCh] [ebp-Ch]
  D3DXShader::CInstruction *v92; // [esp+D0h] [ebp-8h]
  unsigned int j; // [esp+D4h] [ebp-4h]

  v82 = 0;
  v87 = nullptr;
  for ( i = 0; i < 6; ++i )
  {
    v3 = *(_DWORD *)(*((_DWORD *)this + 139) + 4 * i);
    if ( v3 != 0 && *(_DWORD *)(v3 + 12) != 0 )
    {
      v4 = *((_DWORD *)this + 137) == 0;
      ii = 0;
      if ( !v4 )
      {
        do
        {
          jj = *(_DWORD *)(*((_DWORD *)this + 140) + 4 * ii);
          v5 = jj;
          if ( jj != 0 )
          {
            v6 = *(_DWORD *)jj;
            if ( *(_DWORD *)jj != 0 )
            {
              m = 0;
              v7 = ii < 6;
              v79 = v7;
              v92 = (D3DXShader::CInstruction *)(v6 & 0xFFFFF);
              if ( (v6 & 0xFFFFF) != 0 )
              {
                v8 = *((_DWORD *)this + 139);
                v9 = *(_DWORD *)(v8 + 4 * i);
                v80 = *(_DWORD *)(jj + 4) / (unsigned int)v92;
                v4 = *(_DWORD *)(v9 + 12) == 0;
                v86 = 0;
                v88 = 0;
                if ( !v4 )
                {
                  v83 = *(_DWORD *)(*(_DWORD *)(v8 + 4 * i) + 12);
                  do
                  {
                    if ( v7 < v80 )
                    {
                      v10 = 4 * v7 * (_DWORD)v92;
                      v81 = v80 - v7;
                      do
                      {
                        v11 = *(_DWORD *)(v5 + 8);
                        v90 = *(_DWORD **)(*(_DWORD *)(v9 + 16) + 4 * v88);
                        v12 = (_DWORD *)(v10 + v11);
                        for ( j = (unsigned int)v92; j != 0; --j )
                        {
                          if ( ((_DWORD *)*v12 == v90
                             || *(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v12) + 56) == v90)
                            && ii > i )
                          {
                            v13 = *(int **)(*((_DWORD *)this + 140) + 4 * i);
                            if ( v13 != nullptr )
                            {
                              v14 = *v13;
                              if ( v14 != 0 && (v14 & 0xFFF00000) != 0x11000000 )
                              {
                                v86 = 1;
                                m = v9;
                              }
                            }
                          }
                          ++v12;
                        }
                        v5 = jj;
                        v7 = v79;
                        v10 += 4 * (_DWORD)v92;
                        --v81;
                      }
                      while ( v81 != 0 );
                    }
                    ++v88;
                  }
                  while ( v88 < v83 );
                  if ( v86 != 0 )
                  {
                    if ( a2 != nullptr )
                    {
                      ++*a2;
                      ++*a2;
                    }
                    else
                    {
                      memset(v78, 255, sizeof(v78));
                      v4 = *(_DWORD *)(v5 + 4) == 0;
                      j = 0;
                      v92 = nullptr;
                      if ( !v4 )
                      {
                        do
                        {
                          v22 = *(_DWORD *)(m + 12);
                          if ( v22 != 0 )
                          {
                            v23 = *(_DWORD *)(*(_DWORD *)(v5 + 8) + 4 * (_DWORD)v92);
                            v24 = *(int **)(m + 16);
                            v83 = v23;
                            v86 = v22;
                            while ( 1 )
                            {
                              v25 = *v24;
                              if ( *v24 == v23 || v25 == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v23) + 56) )
                              {
                                v26 = j;
                                for ( k = 0; k < j; ++k )
                                {
                                  if ( v78[k] == v25 )
                                    break;
                                }
                                if ( k == j )
                                {
                                  v78[j] = v25;
                                  j = v26 + 1;
                                }
                              }
                              ++v24;
                              if ( --v86 == 0 )
                                break;
                              v23 = v83;
                            }
                          }
                          v92 = (D3DXShader::CInstruction *)((char *)v92 + 1);
                        }
                        while ( (unsigned int)v92 < *(_DWORD *)(v5 + 4) );
                      }
                      v28 = D3DXShader::CInstruction::operator new(a1: 0x74u);
                      if ( v28 != nullptr )
                        v87 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v28);
                      else
                        v87 = nullptr;
                      if ( v87 == nullptr )
                        goto LABEL_71;
                      v29 = D3DXShader::CInstruction::Initialize(
                              this: v87,
                              a2: j & 0xFFFFF | 0x10000000,
                              a3: j,
                              a4: j,
                              a5: 0);
                      v90 = (_DWORD *)v29;
                      if ( v29 < 0 )
                        goto LABEL_140;
                      v30 = v87;
                      memset(*((void **)v87 + 4), 0xFFu, 4 * j);
                      v4 = *(_DWORD *)(v5 + 4) == 0;
                      v88 = 0;
                      if ( !v4 )
                      {
                        v31 = m;
                        do
                        {
                          v4 = *(_DWORD *)(v31 + 12) == 0;
                          v92 = nullptr;
                          if ( !v4 )
                          {
                            do
                            {
                              v32 = *(_DWORD *)(*(_DWORD *)(v5 + 8) + 4 * v88);
                              v33 = *((_DWORD *)this + 5);
                              v34 = *(_DWORD *)(v31 + 16);
                              v90 = *(_DWORD **)(v33 + 4 * v32);
                              v35 = *(_DWORD *)(v34 + 4 * (_DWORD)v92);
                              if ( v35 == v32 || v35 == v90[14] )
                              {
                                v36 = *(_DWORD *)(v33 + 4 * v35);
                                v37 = *((_DWORD *)v87 + 4);
                                v83 = v36;
                                v38 = 4 * (v88 % j);
                                v39 = *(_DWORD *)(v38 + v37);
                                if ( v39 == -1 )
                                {
                                  v40 = *((_DWORD *)this + 258);
                                  if ( v40 >= 0x40 )
                                    goto LABEL_71;
                                  v39 = *((_DWORD *)this + v40 + 193);
                                  *((_DWORD *)this + 258) = v40 + 1;
                                  v41 = *(_DWORD **)(v33 + 4 * v39);
                                  v42 = *((_DWORD *)this + 34);
                                  v41[15] = 0;
                                  v41[14] = -1;
                                  v36 = v83;
                                  v41[1] = v42;
                                  v41[4] = *(_DWORD *)(v36 + 16);
                                  if ( v39 == -1 )
                                    goto LABEL_71;
                                }
                                if ( *(_DWORD *)(*(_DWORD *)(m + 16) + 4 * (_DWORD)v92) == v90[14] )
                                {
                                  v43 = *((_DWORD *)this + 258);
                                  if ( v43 >= 0x40 )
                                    goto LABEL_71;
                                  v44 = *((_DWORD *)this + v43 + 193);
                                  *((_DWORD *)this + 258) = v43 + 1;
                                  v45 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v44);
                                  v45[4] = *(_DWORD *)(v36 + 16);
                                  v45[15] = v90[15];
                                  v45[14] = v39;
                                  v45[1] = *((_DWORD *)this + 34);
                                  v46 = *(_DWORD *)(jj + 8);
                                  v83 = v44;
                                  *(_DWORD *)(v46 + 4 * v88) = v44;
                                }
                                else
                                {
                                  *(_DWORD *)(*(_DWORD *)(jj + 8) + 4 * v88) = v39;
                                }
                                v5 = jj;
                                *(_DWORD *)(v38 + *((_DWORD *)v87 + 2)) = *(_DWORD *)(*(_DWORD *)(m + 16)
                                                                                    + 4 * (_DWORD)v92);
                                *(_DWORD *)(v38 + *((_DWORD *)v87 + 4)) = v39;
                                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v39) + 60) = 0;
                              }
                              v92 = (D3DXShader::CInstruction *)((char *)v92 + 1);
                              v31 = m;
                            }
                            while ( (unsigned int)v92 < *(_DWORD *)(m + 12) );
                            v30 = v87;
                          }
                          ++v88;
                        }
                        while ( v88 < *(_DWORD *)(v5 + 4) );
                      }
                      *(_DWORD *)(*((_DWORD *)this + 139) + 4 * (*((_DWORD *)this + 136))++) = v30;
                      v47 = *((_DWORD *)this + 257);
                      if ( v47 >= 0xC )
                      {
LABEL_71:
                        v29 = -2147024882;
LABEL_140:
                        if ( v87 != nullptr )
                          D3DXShader::CInstruction::`scalar deleting destructor'(this: v87, a2: 1);
                        return v29;
                      }
                      *((_DWORD *)this + v47 + 177) = v30;
                      ++*((_DWORD *)this + 257);
                      v87 = nullptr;
                    }
                  }
                }
              }
            }
          }
          ++ii;
        }
        while ( ii < *((_DWORD *)this + 137) );
      }
    }
  }
  for ( m = 0; m < *((_DWORD *)this + 136); ++m )
  {
    v15 = *(_DWORD **)(*((_DWORD *)this + 139) + 4 * m);
    if ( v15 != nullptr && *v15 != 0 )
    {
      v16 = v15[3];
      v86 = 0;
      if ( v16 != 0 )
      {
        v17 = *((_DWORD *)this + 5);
        v18 = (unsigned int *)v15[4];
        for ( n = v16; n != 0; --n )
        {
          v20 = *v18;
          if ( *(_DWORD *)(*(_DWORD *)(v17 + 4 * *v18) + 16) == 3 )
          {
            v21 = *v18;
            v86 = 1;
            i = v20;
          }
          else
          {
            v21 = i;
          }
          ++v18;
        }
        if ( v86 != 0 )
        {
          j = 0;
          v48 = *((_DWORD *)this + 137) <= 6u;
          ii = 6;
          if ( !v48 )
          {
            v49 = (_DWORD **)(*((_DWORD *)this + 140) + 24);
            do
            {
              v50 = *v49;
              if ( *v49 != nullptr && *v50 != 0 )
              {
                v4 = v50[1] == 0;
                jj = 0;
                if ( !v4 )
                {
                  v90 = (_DWORD *)v50[2];
                  do
                  {
                    if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v90) + 56) == v21 || *v90 == v21 )
                    {
                      if ( j >= 0x10 )
                        return -2147467259;
                      v51 = j++;
                      *(_DWORD *)&v77[4 * v51 + 88] = v50;
                    }
                    ++jj;
                    ++v90;
                  }
                  while ( jj < v50[1] );
                }
              }
              ++ii;
              ++v49;
            }
            while ( ii < *((_DWORD *)this + 137) );
          }
          v52 = a2;
          if ( a2 != nullptr )
          {
            ii = 0;
            if ( *((_DWORD *)this + 3) != 0 )
            {
              jj = *((_DWORD *)this + 6);
              do
              {
                v53 = *(_DWORD **)jj;
                if ( *(_DWORD *)jj != 0 && *v53 != 0 && v53[10] != 1 )
                {
                  v54 = v53[1];
                  v90 = nullptr;
                  if ( v54 != 0 )
                  {
                    v55 = (_DWORD *)v53[2];
                    do
                    {
                      if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v55) + 56) == v21 || *v55 == v21 )
                      {
                        if ( j >= 0x10 )
                          return -2147467259;
                        ++j;
                      }
                      v90 = (_DWORD *)((char *)v90 + 1);
                      ++v55;
                    }
                    while ( (unsigned int)v90 < v54 );
                  }
                }
                ++ii;
                jj += 4;
              }
              while ( ii < *((_DWORD *)this + 3) );
              v52 = a2;
            }
            if ( j == 0 )
              continue;
            ++*v52;
          }
          if ( j != 0 && v52 == nullptr )
          {
            if ( *((_DWORD *)this + 257) >= 0xCu )
              return 1;
            v56 = D3DXShader::CInstruction::operator new(a1: 0x74u);
            if ( v56 != nullptr )
              v57 = D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v56);
            else
              v57 = 0;
            v58 = D3DXShader::CInstruction::operator new(a1: 0x74u);
            if ( v58 != nullptr )
              v92 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v58);
            else
              v92 = nullptr;
            if ( v57 == 0 )
              return -2147024882;
            if ( v92 == nullptr )
              return -2147024882;
            v59 = *((_DWORD *)this + 258);
            if ( v59 > 0x40 )
              return -2147024882;
            v60 = *((_DWORD *)this + v59 + 194);
            v61 = *((_DWORD *)this + v59 + 193);
            v62 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v60);
            v62[14] = -1;
            v62[4] = 3;
            v62[15] = 0;
            v63 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v61);
            v63[14] = -1;
            v63[4] = 4;
            v63[15] = 0;
            *((_DWORD *)this + 258) += 2;
            v83 = v60;
            for ( ii = 0; ii < j; ++ii )
            {
              v64 = *(_DWORD *)&v77[4 * ii + 88];
              for ( jj = 0; jj < *(_DWORD *)(v64 + 4); v64 = *(_DWORD *)&v77[4 * ii + 88] )
              {
                v65 = *((_DWORD *)this + 5);
                v86 = *(_DWORD *)(v64 + 8) + 4 * jj;
                v66 = *(_DWORD *)(v65 + 4 * *(_DWORD *)v86);
                if ( *(_DWORD *)(v66 + 56) == i )
                {
                  *(_DWORD *)(v66 + 56) = v60;
                }
                else if ( *(_DWORD *)v86 == i )
                {
                  *(_DWORD *)v86 = v60;
                }
                ++jj;
              }
            }
            v90 = (_DWORD *)D3DXShader::CInstruction::Initialize(
                              this: (D3DXShader::CInstruction *)v57,
                              a2: 0x10000001u,
                              a3: 1u,
                              a4: 1u,
                              a5: 0);
            if ( (int)v90 < 0 )
              return (int)v90;
            v90 = (_DWORD *)D3DXShader::CInstruction::Initialize(this: v92, a2: 0x10000001u, a3: 1u, a4: 1u, a5: 0);
            if ( (int)v90 < 0 )
              return (int)v90;
            v67 = i;
            v68 = v83;
            **(_DWORD **)(v57 + 16) = v61;
            **(_DWORD **)(v57 + 8) = v67;
            v69 = v92;
            *(_DWORD *)(v57 + 40) = 1;
            **((_DWORD **)v69 + 4) = v68;
            **((_DWORD **)v69 + 2) = v61;
            *(_DWORD *)(v57 + 40) = 2;
            *((_DWORD *)this + *((_DWORD *)this + 257) + 177) = v57;
            *((_DWORD *)this + *((_DWORD *)this + 257) + 178) = v69;
            *((_DWORD *)this + 257) += 2;
            *(_DWORD *)(*((_DWORD *)this + 139) + 4 * *((_DWORD *)this + 136)) = v57;
            v70 = v82;
            ++*((_DWORD *)this + 136);
            ++v82;
            *(_DWORD *)&v77[4 * v70 + 24] = v69;
          }
        }
      }
    }
  }
  v71 = *((_DWORD *)this + 137);
  v72 = v82;
  if ( v71 + v82 <= 0x200 )
  {
    if ( v71 >= 6 )
    {
      v74 = 4 * (v71 + v82);
      do
      {
        *(_DWORD *)(*((_DWORD *)this + 140) + v74) = *(_DWORD *)(*((_DWORD *)this + 140) + 4 * v71--);
        v74 -= 4;
      }
      while ( v71 >= 6 );
    }
    if ( v72 != 0 )
    {
      v75 = v82;
      v76 = 24;
      do
      {
        *(_DWORD *)(v76 + *((_DWORD *)this + 140)) = *(_DWORD *)&v77[v76];
        v76 += 4;
        --v75;
      }
      while ( v75 != 0 );
    }
    *((_DWORD *)this + 137) += v82;
    v29 = 0;
    goto LABEL_140;
  }
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x1020748D
// Name: protected: int D3DXShader::CPSLegacyProgram::ViolatesPhaseLinkage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall D3DXShader::CPSLegacyProgram::ViolatesPhaseLinkage@<eax>(
        D3DXShader::CPSLegacyProgram *this@<ecx>,
        unsigned int a2@<edi>)
{
  _DWORD *v2; // eax
  int i; // esi
  int v4; // eax
  int v5; // edx
  int v6; // eax
  _DWORD *v7; // edx
  unsigned int v9; // [esp-8h] [ebp-34h]
  unsigned int v10; // [esp+4h] [ebp-28h]
  int v11; // [esp+8h] [ebp-24h]
  unsigned int v12; // [esp+Ch] [ebp-20h]
  unsigned int v13; // [esp+10h] [ebp-1Ch]
  unsigned int v14; // [esp+14h] [ebp-18h]
  int v15; // [esp+18h] [ebp-14h]
  int v16; // [esp+1Ch] [ebp-10h]
  unsigned int v17; // [esp+20h] [ebp-Ch]
  unsigned int v18; // [esp+24h] [ebp-8h]
  unsigned int v19; // [esp+28h] [ebp-4h]

  v2 = *((_DWORD **)this + 140);
  v13 = 18;
  for ( i = 6; i != 0; --i )
  {
    if ( *v2 != 0 && (*(_DWORD *)*v2 & 0xFFF00000) != 0x11000000 )
      v13 -= 3;
    ++v2;
  }
  v14 = 0;
  if ( *((_DWORD *)this + 136) == 0 )
    return false;
  v16 = *((_DWORD *)this + 139);
  v11 = *((_DWORD *)this + 136);
  v9 = a2;
  do
  {
    if ( *(_DWORD *)v16 != 0 )
    {
      v17 = 0;
      v10 = *(_DWORD *)(*(_DWORD *)v16 + 12);
      if ( v10 != 0 )
      {
        v4 = *((_DWORD *)this + 3);
        do
        {
          v18 = 0;
          if ( v4 != 0 )
          {
            v15 = *((_DWORD *)this + 6);
            do
            {
              if ( *(_DWORD *)(*(_DWORD *)v15 + 40) != 1
                && D3DXShader::IsTextureInst(this: (D3DXShader *)(**(_DWORD **)v15 & 0xFFF00000), a2: v9) == 0 )
              {
                v19 = 0;
                v12 = *(_DWORD *)(v5 + 4);
                if ( v12 != 0 )
                {
                  v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v16 + 16) + 4 * v17);
                  v7 = *(_DWORD **)(v5 + 8);
                  do
                  {
                    if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v7) + 56) == v6 )
                      break;
                    if ( *v7 == v6 )
                      break;
                    ++v19;
                    ++v7;
                  }
                  while ( v19 < v12 );
                }
                if ( v19 != v12 )
                  break;
              }
              ++v18;
              v15 += 4;
            }
            while ( v18 < *((_DWORD *)this + 3) );
          }
          v4 = *((_DWORD *)this + 3);
          if ( v18 != v4 )
            ++v14;
          ++v17;
        }
        while ( v17 < v10 );
      }
    }
    v16 += 4;
    --v11;
  }
  while ( v11 != 0 );
  return v14 > v13;
}

//------------------------------------------------------------------------------
// Address: 0x102075C1
// Name: protected: int D3DXShader::CPSLegacyProgram::IsDependentOnPhase2(class D3DXShader::CInstruction __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::IsDependentOnPhase2(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction *a2)
{
  int result; // eax
  int v4; // edi

  result = 1;
  if ( *((_DWORD *)a2 + 10) == 1 )
  {
    v4 = 0;
    if ( *((_DWORD *)a2 + 5) != 0 )
    {
      while ( D3DXShader::CPSLegacyProgram::IsDependentOnPhase2(
                this,
                a2: *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6)
                                                    + 4 * *(_DWORD *)(*((_DWORD *)a2 + 6) + 4 * v4))) == 0 )
      {
        if ( (unsigned int)++v4 >= *((_DWORD *)a2 + 5) )
          return 0;
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10207608
// Name: protected: long D3DXShader::CPSLegacyProgram::FindConsumers(class D3DXShader::CInstruction __near * __near *,unsigned int,unsigned int,unsigned int __near *,unsigned int,unsigned int __near *,unsigned int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::FindConsumers(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5,
        unsigned int a6,
        unsigned int *a7,
        unsigned int *a8)
{
  struct D3DXShader::CInstruction *v9; // ecx
  unsigned int v10; // esi
  _DWORD *v11; // edx
  int v12; // ebx
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // esi
  int v16; // edx
  unsigned int j; // edi
  unsigned int v19; // [esp+Ch] [ebp-20h]
  struct D3DXShader::CInstruction *v20; // [esp+10h] [ebp-1Ch]
  unsigned int v21; // [esp+14h] [ebp-18h]
  unsigned int v22; // [esp+18h] [ebp-14h]
  unsigned int v24; // [esp+20h] [ebp-Ch]
  unsigned int i; // [esp+24h] [ebp-8h]
  unsigned int v26; // [esp+24h] [ebp-8h]
  int v27; // [esp+28h] [ebp-4h]
  unsigned int v28; // [esp+28h] [ebp-4h]
  unsigned int v29; // [esp+38h] [ebp+Ch]

  while ( 1 )
  {
    v21 = a3;
    if ( a3 >= a4 )
      return 0;
    v9 = a2[a3];
    v20 = v9;
    if ( v9 != nullptr )
    {
      v10 = *(_DWORD *)v9 & 0xFFFFF;
      v22 = v10;
      if ( *(_DWORD *)v9 != 0 )
      {
        v24 = 0;
        v19 = *((_DWORD *)v9 + 1) / v10;
        if ( v19 != 0 )
          break;
      }
    }
LABEL_29:
    a3 = v21 + 1;
  }
  v29 = 0;
  while ( 1 )
  {
    v27 = 0;
    if ( v10 != 0 )
      break;
LABEL_28:
    ++v24;
    v29 += 4 * v10;
    if ( v24 >= v19 )
      goto LABEL_29;
  }
  v11 = (_DWORD *)(v29 + *((_DWORD *)v9 + 2));
  for ( i = v10; i != 0; --i )
  {
    v12 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v11);
    v13 = 0;
    if ( a6 != 0 )
    {
      do
      {
        v14 = a5[v13];
        if ( (*v11 == v14 || *(_DWORD *)(v12 + 56) == v14) && *(_DWORD *)(v12 + 12) == -1 )
          v27 = 1;
        ++v13;
      }
      while ( v13 < a6 );
      v9 = v20;
    }
    ++v11;
  }
  if ( v27 == 0 )
  {
LABEL_27:
    v10 = v22;
    goto LABEL_28;
  }
  v26 = 0;
  v28 = v29;
  while ( 1 )
  {
    v15 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v28 + *((_DWORD *)v9 + 2))) + 56);
    if ( v15 == -1 )
      v15 = *(_DWORD *)(v28 + *((_DWORD *)v9 + 2));
    v16 = *a8;
    for ( j = 0; j < *a8; ++j )
    {
      if ( a7[j] == v15 )
        break;
    }
    if ( j == v16 )
    {
      if ( j == 32 )
        break;
      a7[v16] = v15;
      ++*a8;
    }
    ++v26;
    v28 += 4;
    if ( v26 >= v22 )
      goto LABEL_27;
  }
  D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x12C3u, format: "internal error: arguments not vectorized");
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x10207767
// Name: protected: long D3DXShader::CPSLegacyProgram::FixUpOrigins(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::FixUpOrigins(D3DXShader::CPSLegacyProgram *this)
{
  unsigned int i; // esi
  _DWORD *v2; // eax
  int v3; // edx
  int v4; // edx

  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    v2 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * i);
    v3 = v2[14];
    if ( v3 != -1 )
    {
      v4 = 4 * v3;
      v2[3] = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v4) + 12);
      v2[4] = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v4) + 16);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102077A6
// Name: protected: long D3DXShader::CPSLegacyProgram::AnalizeArgUse(class D3DXShader::CInstruction __near * __near *,unsigned int,unsigned int,unsigned int __near *,unsigned int,unsigned int __near &,int __near &,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::AnalizeArgUse(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5,
        unsigned int a6,
        unsigned int *a7,
        int *a8,
        int *a9)
{
  unsigned int v9; // eax
  struct D3DXShader::CInstruction *v10; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // ebx
  unsigned int v16; // ecx
  unsigned int n; // edx
  int v19; // [esp+4h] [ebp-2Ch]
  unsigned int v20; // [esp+8h] [ebp-28h]
  unsigned int i; // [esp+Ch] [ebp-24h]
  unsigned int j; // [esp+10h] [ebp-20h]
  unsigned int k; // [esp+14h] [ebp-1Ch]
  int m; // [esp+18h] [ebp-18h]
  unsigned int v26; // [esp+20h] [ebp-10h]
  unsigned int v27; // [esp+24h] [ebp-Ch]
  unsigned int *v28; // [esp+28h] [ebp-8h]
  int v29; // [esp+2Ch] [ebp-4h]
  unsigned int v30; // [esp+3Ch] [ebp+Ch]

  *a8 = 0;
  *a9 = 0;
  v9 = a3;
  v27 = 0;
  for ( i = a3; i < a4; ++i )
  {
    v10 = a2[v9];
    if ( v10 != nullptr )
    {
      v11 = *(_DWORD *)v10;
      if ( *(_DWORD *)v10 != 0 )
      {
        v12 = v11 & 0xFFFFF;
        v19 = v11 & 0xFFFFF;
        v26 = 0;
        v20 = *((_DWORD *)v10 + 1) / (v11 & 0xFFFFFu);
        if ( a6 != 0 )
        {
          v28 = a5;
          for ( j = a6; j != 0; --j )
          {
            if ( v20 != 0 )
            {
              v29 = 0;
              for ( k = v20; k != 0; --k )
              {
                v30 = 0;
                if ( v12 != 0 )
                {
                  v13 = v29;
                  for ( m = v12; m != 0; --m )
                  {
                    v14 = *(_DWORD *)(v13 + *((_DWORD *)v10 + 2));
                    v15 = *((_DWORD *)this + 5);
                    if ( *(_DWORD *)(*(_DWORD *)(v15 + 4 * v14) + 56) == *v28 || v14 == *v28 )
                    {
                      ++v30;
                      v16 = ++v26;
                      if ( v26 > v27 )
                        v27 = v16;
                      if ( *((_DWORD *)v10 + 3) == 1
                        && *(_DWORD *)(*(_DWORD *)(v15 + 4 * **((_DWORD **)v10 + 4)) + 16) == 3 )
                      {
                        *a8 = 1;
                      }
                      if ( (*(_DWORD *)v10 & 0xFFF00000) != 0x50000000 )
                      {
                        for ( n = 0; n < *((_DWORD *)v10 + 3); ++n )
                        {
                          if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                     + 4 * *(_DWORD *)(*((_DWORD *)v10 + 4) + 4 * n))
                                         + 16) == 3 )
                            *a8 = 1;
                        }
                      }
                    }
                    v13 += 4;
                  }
                  v12 = v19;
                }
                if ( v30 != v12 && v30 != 0 )
                  *a9 = 1;
                v29 += 4 * v12;
              }
            }
            ++v28;
          }
        }
      }
    }
    v9 = i + 1;
  }
  *a7 = v27;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020791F
// Name: protected: long D3DXShader::CPSLegacyProgram::RemapConstants(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::RemapConstants(D3DXShader::CPSLegacyProgram *this)
{
  unsigned int v2; // ebx
  unsigned int v3; // eax
  int v4; // ebx
  int v5; // edi
  int v6; // edx
  unsigned int v7; // edx
  int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  _DWORD *v11; // ebx
  int v12; // edi
  int v13; // edx
  int v14; // edi
  unsigned int v15; // ecx
  int v16; // edi
  unsigned int v17; // edx
  int v18; // eax
  bool v19; // zf
  unsigned int v20; // eax
  unsigned int *v21; // edx
  int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // eax
  int v25; // edi
  unsigned int v26; // eax
  _DWORD *v27; // edi
  int v28; // eax
  double v29; // st7
  unsigned int v30; // ecx
  unsigned int j; // edx
  unsigned int v32; // edx
  unsigned int v33; // eax
  float *v34; // ecx
  double v35; // st7
  unsigned int v36; // edi
  int v37; // eax
  unsigned int v38; // eax
  int v39; // ecx
  unsigned int v40; // ecx
  int v41; // eax
  unsigned int v42; // eax
  unsigned int i; // ecx
  int v44; // eax
  double v46; // [esp+0h] [ebp-180h]
  float v47[32]; // [esp+14h] [ebp-16Ch] BYREF
  _DWORD v48[32]; // [esp+94h] [ebp-ECh] BYREF
  float v49[12]; // [esp+114h] [ebp-6Ch] BYREF
  _DWORD v50[3]; // [esp+144h] [ebp-3Ch] BYREF
  int v51; // [esp+150h] [ebp-30h]
  unsigned int v52; // [esp+154h] [ebp-2Ch]
  unsigned int v53; // [esp+158h] [ebp-28h]
  unsigned int v54; // [esp+15Ch] [ebp-24h]
  _DWORD *v55; // [esp+160h] [ebp-20h]
  unsigned int v56; // [esp+164h] [ebp-1Ch]
  unsigned int v57; // [esp+168h] [ebp-18h]
  int v58; // [esp+16Ch] [ebp-14h]
  unsigned int v59; // [esp+170h] [ebp-10h]
  unsigned int v60; // [esp+174h] [ebp-Ch]
  unsigned int v61; // [esp+178h] [ebp-8h]
  unsigned int k; // [esp+17Ch] [ebp-4h]

  v2 = *((_DWORD *)this + 2);
  memset(v47, 0, sizeof(v47));
  memset(v48, 0, sizeof(v48));
  memset(v49, 0, 0x20u);
  v57 = v2;
  v3 = D3DXShader::CBaseProgram::AddPool(
         this,
         a2: (char *)&stru_102A6BD8.m_Memory.m_nGrowSize,
         a3: 0x311u,
         a4: 8u,
         a5: 4u);
  v59 = 0;
  v53 = v3;
  if ( v2 != 0 )
  {
    v4 = *((_DWORD *)this + 4);
    v5 = *((_DWORD *)this + 5);
    do
    {
      v6 = *(_DWORD *)(*(_DWORD *)(v4 + 4 * *(_DWORD *)(*(_DWORD *)v5 + 4)) + 4);
      if ( (v6 & 0x200) != 0 && (v6 & 0x180) == 0 )
      {
        v7 = *(_DWORD *)(*(_DWORD *)v5 + 12);
        if ( v7 > *((_DWORD *)this + 14) )
        {
          D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x119Bu, format: "exceeded maximum constant registers");
          return -2147467259;
        }
        v8 = 4 * v7;
        v48[v8] = 1;
        v48[v8 + 1] = 1;
        v48[v8 + 2] = 1;
        v48[v8 + 3] = 1;
        LODWORD(v49[v7]) = 1;
      }
      ++v59;
      v5 += 4;
    }
    while ( v59 < v57 );
  }
  v9 = *((_DWORD *)this + 137);
  v10 = *((_DWORD *)this + 136);
  v60 = 0;
  if ( v10 + v9 == 0 )
  {
LABEL_82:
    for ( i = 0; i < v57; ++i )
    {
      v44 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * i);
      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v44 + 4)) + 5) & 1) != 0 )
        *(_DWORD *)(v44 + 4) = *((_DWORD *)this + 29);
    }
    return 0;
  }
  while ( 1 )
  {
    v11 = v60 >= v10
        ? *(_DWORD **)(*((_DWORD *)this + 140) + 4 * (v60 - v10))
        : *(_DWORD **)(*((_DWORD *)this + 139) + 4 * v60);
    v58 = 0;
    v55 = v11;
    if ( v11 != nullptr && v11[3] != 0 )
    {
      v12 = *(_DWORD *)v11[4];
      if ( v12 != -1 )
      {
        v54 = *v11;
        if ( (v54 & 0xFFF00000) != 0 )
        {
          if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v12) + 16) != 3 && v11[3] != 4 && v60 >= v10 )
          {
            v13 = 1;
            if ( v60 - v10 + 1 < v9 )
            {
              v14 = v60 - v10 + 1;
              v15 = v14;
              do
              {
                v16 = *(_DWORD *)(*((_DWORD *)this + 140) + 4 * v14);
                if ( v16 != 0 && (*(_WORD *)(v16 + 2) & 0xFFF0) != 0 )
                  break;
                ++v13;
                v14 = ++v15;
              }
              while ( v15 < *((_DWORD *)this + 137) );
              v11 = v55;
            }
            v17 = v60 + v13 - v10;
            if ( v17 < *((_DWORD *)this + 137) )
            {
              v18 = *(_DWORD *)(*((_DWORD *)this + 140) + 4 * v17);
              v19 = *(_DWORD *)(v18 + 12) == 1;
              v58 = v18;
              if ( !v19 || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v18 + 16)) + 16) != 3 )
                v58 = 0;
            }
          }
          v56 = v54 & 0xFFFFF;
          v20 = v11[1] / (v54 & 0xFFFFF);
          v54 = 0;
          v52 = v20;
          if ( v20 != 0 )
            break;
        }
      }
    }
LABEL_81:
    v9 = *((_DWORD *)this + 137);
    v10 = *((_DWORD *)this + 136);
    if ( ++v60 >= v10 + v9 )
      goto LABEL_82;
  }
  v59 = 0;
  while ( 1 )
  {
    memset(v50, 0, sizeof(v50));
    v51 = 0;
    v21 = (unsigned int *)(v11[2] + v59);
    v22 = *((_DWORD *)this + 5);
    v11 = v55;
    if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(*(_DWORD *)(v22 + 4 * *v21) + 4)) + 5) & 1) != 0
      && *v21 < v57 )
    {
      break;
    }
LABEL_80:
    ++v54;
    v59 += 4 * v56;
    if ( v54 >= v52 )
      goto LABEL_81;
  }
  v23 = 0;
  v61 = 0;
  if ( v56 != 0 )
  {
    k = *v55 & 0xFFF00000;
    do
    {
      if ( k != 1342177280 )
        v23 = *(_DWORD *)(*(_DWORD *)(v22 + 4 * *(_DWORD *)(v11[4] + 4 * v23)) + 16);
      v24 = v23;
      v49[v24 + 8] = *(double *)(*(_DWORD *)(v22 + 4 * *v21) + 32);
      v50[v24] = 1;
      v23 = v61 + 1;
      ++v21;
      ++v61;
    }
    while ( v61 < v56 );
  }
  v25 = v58;
  if ( v58 != 0 )
  {
    v26 = *(_DWORD *)(v58 + 4);
    if ( v26 != 0 )
    {
      v27 = *(_DWORD **)(v58 + 8);
      k = (unsigned int)v27;
      v61 = v26;
      do
      {
        v28 = *(_DWORD *)(v22 + 4 * *v27);
        if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v28 + 4)) + 5) & 1) != 0
          && *(_DWORD *)k < v57 )
        {
          v29 = *(double *)(v28 + 32);
          v51 = 1;
          v49[11] = v29;
        }
        v27 = (_DWORD *)(k + 4);
        v19 = v61-- == 1;
        k += 4;
      }
      while ( !v19 );
      v25 = v58;
    }
  }
  v30 = 0;
  v61 = 0;
  for ( j = 0; j < 32; j += 4 )
  {
    if ( LODWORD(v49[v61]) == 0 )
    {
      k = 1;
      do
      {
        if ( v50[v30] != 0 && v49[v30 + 8] != v47[j + v30] && v48[j + v30] != 0 )
          k = 0;
        ++v30;
      }
      while ( v30 < 4 );
      v30 = 0;
      if ( k != 0 )
        break;
    }
    ++v61;
  }
  if ( v61 != 8 )
  {
    v32 = 0;
    k = 0;
    do
    {
      if ( v50[v32] != 0 )
      {
        v33 = v32 + 4 * v61;
        v34 = &v49[v32 + 8];
        v35 = *v34;
        v48[v33] = 1;
        v47[v33] = v35;
        if ( *v34 > 1.0 || *v34 < -1.0 )
          k = 1;
      }
      ++v32;
    }
    while ( v32 < 4 );
    if ( k != 0 )
      D3DXShader::CProgram::Warning(
        this,
        a2: (struct D3DXShader::CNode *)v11[15],
        a3: 0x1260u,
        format: "literal values outside range -1 to 1 are clamped on all ps_1_x shading models");
    k = 0;
    if ( v56 != 0 )
    {
      v36 = v59;
      do
      {
        v37 = *((_DWORD *)this + 5);
        v46 = *(double *)(*(_DWORD *)(v37 + 4 * *(_DWORD *)(v36 + v11[2])) + 32);
        if ( (*v11 & 0xFFF00000) == 0x50000000 )
          v38 = D3DXShader::CBaseProgram::AddArgument(this, a2: v53, a3: v61, a4: k, a5: v46);
        else
          v38 = D3DXShader::CBaseProgram::AddArgument(
                  this,
                  a2: v53,
                  a3: v61,
                  a4: *(_DWORD *)(*(_DWORD *)(v37 + 4 * *(_DWORD *)(v11[4] + 4 * k)) + 16),
                  a5: v46);
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v38) + 60) = 0;
        v39 = v11[2];
        ++k;
        *(_DWORD *)(v36 + v39) = v38;
        v36 += 4;
      }
      while ( k < v56 );
      v25 = v58;
    }
    if ( v25 != 0 )
    {
      for ( k = 0; k < *(_DWORD *)(v25 + 4); ++k )
      {
        v40 = *(_DWORD *)(*(_DWORD *)(v25 + 8) + 4 * k);
        v41 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v40);
        if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v41 + 4)) + 5) & 1) != 0 && v40 < v57 )
        {
          v42 = D3DXShader::CBaseProgram::AddArgument(this, a2: v53, a3: v61, a4: 3u, a5: *(double *)(v41 + 32));
          v25 = v58;
          *(_DWORD *)(*(_DWORD *)(v58 + 8) + 4 * k) = v42;
        }
        else
        {
          v25 = v58;
        }
      }
    }
    goto LABEL_80;
  }
  D3DXShader::CProgram::Error(
    this,
    a2: nullptr,
    a3: 0x119Bu,
    format: "program too complex: exceeded available constant registers.");
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x10207E0F
// Name: protected: long D3DXShader::CPSLegacyProgram::NoTexClobber(unsigned int,class D3DXShader::CInstruction __near * __near *,unsigned int,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::NoTexClobber(
        D3DXShader::CPSLegacyProgram *this,
        unsigned int a2,
        struct D3DXShader::CInstruction **a3,
        unsigned int a4,
        unsigned int *a5,
        unsigned int a6)
{
  unsigned int v6; // eax
  struct D3DXShader::CInstruction *v7; // ecx
  int v8; // edi
  int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // esi
  _DWORD *v14; // edx
  struct D3DXShader::CInstruction *v15; // eax
  int v16; // eax
  unsigned int v17; // ebx
  unsigned int v18; // edx
  unsigned int v19; // eax
  unsigned int v20; // edi
  _DWORD *v21; // edx
  struct D3DXShader::CInstruction *v22; // eax
  int v23; // eax
  unsigned int v25; // [esp+Ch] [ebp-14h]
  unsigned int v27; // [esp+14h] [ebp-Ch]
  struct D3DXShader::CInstruction *v28; // [esp+18h] [ebp-8h]
  unsigned int v29; // [esp+18h] [ebp-8h]
  unsigned int v30; // [esp+1Ch] [ebp-4h]

  v6 = 0;
  v30 = 0;
  if ( a4 == 0 )
    return 0;
  while ( 1 )
  {
    v7 = a3[v6];
    v8 = 0;
    v28 = v7;
    if ( v7 == nullptr )
      goto LABEL_41;
    v9 = *(_DWORD *)v7;
    if ( *(_DWORD *)v7 == 0 )
      goto LABEL_41;
    v10 = v9 & 0xFFF00000;
    v11 = v9 & 0xFFFFF;
    if ( v10 == 1610612736
      || v10 == 1615855616
      || v10 == 1621098496
      || v10 == 1626341376
      || v10 == 1927282688
      || v10 == 1617952768 )
    {
      break;
    }
    if ( v10 == 1913651200 )
    {
      v17 = 0;
      goto LABEL_27;
    }
    if ( a6 != 0 )
    {
      v12 = *((_DWORD *)v7 + 1);
      while ( 1 )
      {
        v29 = 0;
        if ( v12 != 0 )
          break;
LABEL_22:
        if ( ++v8 >= a6 )
          goto LABEL_41;
      }
      v13 = a5[v8];
      v14 = *((_DWORD **)v7 + 2);
      while ( 1 )
      {
        if ( *v14 == v13 || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v14) + 56) == v13 )
        {
          v15 = a3[a2];
          if ( v15 != nullptr && a2 < v30 )
          {
            v16 = *(_DWORD *)v15;
            if ( v16 != 0 && (v16 & 0xFFF00000) != 0x11000000 )
              return 1;
          }
        }
        ++v29;
        v12 = *((_DWORD *)v7 + 1);
        ++v14;
        if ( v29 >= v12 )
          goto LABEL_22;
      }
    }
LABEL_41:
    v6 = ++v30;
    if ( v30 >= a4 )
      return 0;
  }
  v17 = v11;
LABEL_27:
  v18 = 0;
  v25 = 0;
  if ( a6 == 0 )
    goto LABEL_41;
  v19 = *((_DWORD *)v7 + 1);
  while ( 1 )
  {
    v27 = v17;
    if ( v17 < v19 )
      break;
LABEL_40:
    v25 = ++v18;
    if ( v18 >= a6 )
      goto LABEL_41;
  }
  v20 = a5[v18];
  v21 = (_DWORD *)(*((_DWORD *)v7 + 2) + 4 * v17);
  while ( 1 )
  {
    if ( *v21 == v20 )
    {
      v22 = a3[a2];
      if ( v22 != nullptr && a2 < v30 && *(_DWORD *)v22 != 0 )
        return 1;
      v7 = v28;
    }
    v23 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v21);
    if ( (*(_BYTE *)(v23 + 62) & 0x1F) != 0 || *(_DWORD *)(v23 + 56) != -1 )
      break;
    ++v27;
    v19 = *((_DWORD *)v7 + 1);
    ++v21;
    if ( v27 >= v19 )
    {
      v18 = v25;
      goto LABEL_40;
    }
  }
  D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x12C6u, format: "internal error: texld alias found");
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x10207FD2
// Name: protected: long D3DXShader::CPSLegacyProgram::UpPropZ(class D3DXShader::CInstruction __near * __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::UpPropZ(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        D3DXShader::CInstruction *a3,
        unsigned int a4)
{
  unsigned int v4; // eax
  struct D3DXShader::CInstruction *v5; // ebx
  struct D3DXShader::CInstruction *v6; // eax
  _DWORD *v7; // ecx
  int v8; // esi
  int v9; // edx
  unsigned int v10; // eax
  unsigned int v12; // esi
  unsigned __int8 *v13; // eax
  int v14; // edi
  unsigned __int8 *v15; // eax
  _DWORD *v16; // eax
  int v17; // ecx
  int v18; // edx
  _DWORD *v19; // eax
  unsigned int *v20; // edi
  int v21; // eax
  int v22; // esi
  unsigned int v23; // eax
  int v24; // [esp+14h] [ebp-30h]
  unsigned int v25; // [esp+18h] [ebp-2Ch]
  unsigned int v26; // [esp+1Ch] [ebp-28h]
  unsigned int v27; // [esp+20h] [ebp-24h]
  unsigned int v28; // [esp+20h] [ebp-24h]
  unsigned int v29; // [esp+20h] [ebp-24h]
  unsigned int v30; // [esp+24h] [ebp-20h]
  unsigned int v31; // [esp+28h] [ebp-1Ch]
  struct D3DXShader::CInstruction **v32; // [esp+28h] [ebp-1Ch]
  unsigned int v33; // [esp+2Ch] [ebp-18h]
  D3DXShader::CInstruction *v34; // [esp+30h] [ebp-14h]
  unsigned int v35; // [esp+34h] [ebp-10h]
  int v36; // [esp+34h] [ebp-10h]
  int v37; // [esp+38h] [ebp-Ch]
  int v38; // [esp+3Ch] [ebp-8h]
  struct D3DXShader::CInstruction **v40; // [esp+4Ch] [ebp+8h]
  D3DXShader::CInstruction *v41; // [esp+50h] [ebp+Ch]

  v4 = 0;
  v5 = nullptr;
  v35 = 0;
  if ( a3 != nullptr )
  {
    while ( 1 )
    {
      v6 = a2[v4];
      if ( v6 != nullptr && (*(_DWORD *)v6 & 0xFFF00000) != 0 && (*(_DWORD *)v6 & 0xFFFFF) != 0 )
      {
        v31 = *((_DWORD *)v6 + 3);
        if ( v31 != 0 )
        {
          v7 = *((_DWORD **)v6 + 4);
          v8 = *((_DWORD *)this + 5);
          v9 = *(_DWORD *)(v8 + 4 * *v7);
          if ( *(_DWORD *)(v9 + 12) == a4 && *(_DWORD *)(v9 + 4) == *((_DWORD *)this + 34) )
          {
            v5 = v6;
            v34 = (D3DXShader::CInstruction *)v35;
            v10 = 0;
            if ( v31 != 0 )
              break;
          }
        }
      }
LABEL_11:
      v4 = ++v35;
      if ( v35 >= (unsigned int)a3 )
      {
        if ( v5 == nullptr )
          goto LABEL_13;
        v12 = *(_DWORD *)v5 & 0xFFFFF;
        v26 = v12;
        if ( (*(_DWORD *)v5 & 0xFFF00000) == 0x50000000 )
        {
          v13 = D3DXShader::CInstruction::operator new(a1: 0x74u);
          if ( v13 != nullptr )
            v41 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v13);
          else
            v41 = nullptr;
          if ( v41 != nullptr )
          {
            v14 = D3DXShader::CInstruction::Initialize(
                    this: v41,
                    a2: *(_DWORD *)v5,
                    a3: *((_DWORD *)v5 + 1),
                    a4: *((_DWORD *)v5 + 3) + 1,
                    a5: 0);
            if ( v14 >= 0 )
            {
              v32 = &a2[(_DWORD)v34];
              v14 = D3DXShader::CInstruction::Instance(this: v41, a2: *v32);
              if ( v14 >= 0 )
              {
                v40 = (struct D3DXShader::CInstruction **)D3DXShader::CBaseProgram::AddArgument(
                                                            this,
                                                            a2: *((_DWORD *)this + 34),
                                                            a3: a4,
                                                            a4: 2u,
                                                            a5: 0.0);
                if ( v40 == (struct D3DXShader::CInstruction **)-1 )
                  goto LABEL_23;
                qmemcpy(*((void **)v41 + 2), *((const void **)v5 + 2), 4 * *((_DWORD *)v41 + 1));
                qmemcpy(*((void **)v41 + 4), *((const void **)v5 + 4), 4 * *((_DWORD *)v5 + 3));
                *(_DWORD *)(*((_DWORD *)v41 + 4) + 4 * *((_DWORD *)v5 + 3)) = v40;
                D3DXShader::CInstruction::Initialize(this: *v32, a2: v41);
LABEL_49:
                D3DXShader::CInstruction::`scalar deleting destructor'(this: v41, a2: 1);
                v41 = nullptr;
                v14 = 0;
              }
            }
            goto LABEL_50;
          }
          return -2147024882;
        }
        else
        {
          v15 = D3DXShader::CInstruction::operator new(a1: 0x74u);
          if ( v15 != nullptr )
            v41 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v15);
          else
            v41 = nullptr;
          if ( v41 == nullptr )
            return -2147024882;
          v25 = *((_DWORD *)v5 + 1) / v12;
          v14 = D3DXShader::CInstruction::Initialize(
                  this: v41,
                  a2: *(_DWORD *)v5 ^ (*(_DWORD *)v5 ^ (v12 + 1)) & 0xFFFFF,
                  a3: v25 + *((_DWORD *)v5 + 1),
                  a4: *((_DWORD *)v5 + 3) + 1,
                  a5: 0);
          if ( v14 >= 0 )
          {
            v14 = D3DXShader::CInstruction::Instance(this: v41, a2: a2[(_DWORD)v34]);
            if ( v14 >= 0 )
            {
              v33 = 0;
              if ( v25 == 0 )
              {
LABEL_48:
                D3DXShader::CInstruction::Initialize(this: a2[(_DWORD)v34], a2: v41);
                goto LABEL_49;
              }
              v37 = 0;
              v38 = 0;
              v24 = 4 * v12 + 4;
              v36 = 4 * v12;
              while ( 1 )
              {
                v27 = 1;
                if ( v12 > 1 )
                {
                  v16 = (_DWORD *)(v38 + *((_DWORD *)v5 + 2));
                  v17 = *((_DWORD *)this + 5);
                  v18 = *(_DWORD *)(*(_DWORD *)(v17 + 4 * *v16) + 16);
                  v19 = v16 + 1;
                  v30 = v12 - 1;
                  do
                  {
                    if ( *(_DWORD *)(*(_DWORD *)(v17 + 4 * *v19) + 16) != v18 )
                      v27 = 0;
                    ++v19;
                    --v30;
                  }
                  while ( v30 != 0 );
                }
                qmemcpy((void *)(v37 + *((_DWORD *)v41 + 2)), (const void *)(v38 + *((_DWORD *)v5 + 2)), 4 * v12);
                v20 = (unsigned int *)this;
                v21 = *((_DWORD *)v41 + 2);
                if ( v27 != 0 )
                {
                  *(_DWORD *)(v36 + v21) = *(_DWORD *)(v38 + *((_DWORD *)v5 + 2));
                }
                else
                {
                  v22 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v37 + v21));
                  v28 = *(_DWORD *)(v22 + 12);
                  v23 = D3DXShader::CBaseProgram::AddArgument(this, a2: *(_DWORD *)(v22 + 4), a3: v28, a4: 2u, a5: 0.0);
                  if ( v23 == -1 )
                    break;
                  *(_DWORD *)(v36 + *((_DWORD *)v41 + 2)) = v23;
                  if ( *(_DWORD *)(v22 + 4) == *((_DWORD *)this + 34) )
                  {
                    v14 = D3DXShader::CPSLegacyProgram::UpPropZ(this, a2, a3: v34, a4: v28);
                    if ( v14 < 0 )
                      goto LABEL_50;
                    v20 = (unsigned int *)this;
                  }
                }
                v29 = D3DXShader::CBaseProgram::AddArgument(
                        this: (D3DXShader::CBaseProgram *)v20,
                        a2: v20[34],
                        a3: a4,
                        a4: 2u,
                        a5: 0.0);
                if ( v29 == -1 )
                  break;
                qmemcpy(*((void **)v41 + 4), *((const void **)v5 + 4), 4 * *((_DWORD *)v5 + 3));
                ++v33;
                *(_DWORD *)(*((_DWORD *)v41 + 4) + 4 * *((_DWORD *)v5 + 3)) = v29;
                v38 += 4 * v26;
                v37 += v24;
                v36 += v24;
                if ( v33 >= v25 )
                  goto LABEL_48;
                v12 = v26;
              }
LABEL_23:
              v14 = -2147024882;
            }
          }
LABEL_50:
          if ( v41 != nullptr )
            D3DXShader::CInstruction::`scalar deleting destructor'(this: v41, a2: 1);
        }
        return v14;
      }
    }
    while ( *(_DWORD *)(*(_DWORD *)(v8 + 4 * *v7) + 16) != 2 )
    {
      ++v10;
      ++v7;
      if ( v10 >= v31 )
        goto LABEL_11;
    }
    return 0;
  }
  else
  {
LABEL_13:
    D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x12D7u, format: "internal error: uppropagation failed");
    return -2147467259;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102083AF
// Name: protected: long D3DXShader::CPSLegacyProgram::InitZs(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::InitZs(D3DXShader::CPSLegacyProgram *this)
{
  int v2; // ebx
  int v3; // eax
  _DWORD *v4; // edx
  int v5; // ecx
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // eax
  int result; // eax

  v2 = 0;
  if ( *((_DWORD *)this + 19) == 0 )
    return 0;
  while ( 1 )
  {
    v3 = *((_DWORD *)this + 140);
    v4 = *(_DWORD **)(v3 + 4 * v2);
    if ( v4 != nullptr )
    {
      v5 = **(_DWORD **)(v3 + 4 * v2);
      v6 = v5 & 0xFFF00000;
      v7 = v5 & 0xFFFFF;
      if ( v6 == 1615855616 || (*v4 & 0xFFF00000) == 0x60000000 )
      {
        v8 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v4[2] + 4 * v7));
        if ( *(_DWORD *)(v8 + 4) == *((_DWORD *)this + 34) )
        {
          result = D3DXShader::CPSLegacyProgram::UpPropZ(
                     this,
                     a2: *((struct D3DXShader::CInstruction ***)this + 139),
                     a3: *((D3DXShader::CInstruction **)this + 136),
                     a4: *(_DWORD *)(v8 + 12));
          if ( result < 0 )
            break;
        }
      }
    }
    if ( (unsigned int)++v2 >= *((_DWORD *)this + 19) )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020842D
// Name: protected: long D3DXShader::CPSLegacyProgram::AllocateRegisters(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::AllocateRegisters(D3DXShader::CPSLegacyProgram *this, int a2, int a3)
{
  unsigned int i; // ecx
  int v5; // eax
  bool v6; // zf
  unsigned int v7; // esi
  _DWORD *v8; // ecx
  unsigned int v9; // eax
  int v10; // eax
  int v11; // edx
  _DWORD *v12; // ecx
  int result; // eax
  struct D3DXShader::CInstruction **v14; // ecx
  struct D3DXShader::CInstruction *v15; // eax
  int v16; // edi
  int v17; // eax
  unsigned int v18; // eax
  struct D3DXShader::CArgument *v19; // ecx
  unsigned int *v20; // edi
  unsigned int v21; // eax
  struct D3DXShader::CArgument *v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // edx
  unsigned int v25; // ecx
  bool v26; // cf
  unsigned int v27; // eax
  int v28; // eax
  D3DXShader::CInstruction *v29; // ecx
  struct D3DXShader::CArgument *v30; // edi
  unsigned int v31; // eax
  unsigned int v32; // edx
  int v33; // ecx
  int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // eax
  struct D3DXShader::CArgument *v37; // edi
  unsigned int v38; // eax
  int v39; // ecx
  int v40; // ecx
  int v41; // esi
  unsigned int v42; // eax
  _DWORD *v43; // eax
  unsigned int v44; // ecx
  int v45; // eax
  int *v46; // edx
  int v47; // eax
  int *v48; // ecx
  int v49; // ecx
  _DWORD *v50; // edx
  _DWORD *v51; // edi
  int v52; // eax
  int v53; // edx
  int v54; // ecx
  _DWORD *v55; // esi
  int v56; // eax
  int v57; // eax
  struct D3DXShader::CInstruction **v58; // ecx
  unsigned int v59; // esi
  struct D3DXShader::CInstruction *v60; // eax
  D3DXShader::CInstruction *v61; // eax
  _DWORD *v62; // eax
  _DWORD *v63; // eax
  int v64; // ecx
  int v65; // edi
  int v66; // edx
  int v67; // ecx
  unsigned int v68; // edi
  unsigned int v69; // eax
  unsigned int v70; // edi
  int *v71; // eax
  int v72; // ecx
  unsigned int v73; // edx
  unsigned int v74; // ecx
  _DWORD *v75; // eax
  int *v76; // eax
  int v77; // ecx
  int v78; // esi
  unsigned int v79; // edx
  unsigned int k; // edi
  unsigned int *v81; // esi
  int v82; // esi
  bool v83; // cc
  unsigned __int8 *v84; // eax
  int v85; // edx
  int v86; // eax
  unsigned int v87; // ecx
  const void *v88; // esi
  struct D3DXShader::CInstruction *v89; // eax
  unsigned int v90; // edi
  unsigned int v91; // ecx
  _DWORD *v92; // esi
  int v93; // eax
  unsigned int v94; // eax
  _DWORD *v95; // eax
  unsigned int v96; // eax
  int *v97; // esi
  int v98; // eax
  unsigned int v99; // ecx
  unsigned int v100; // eax
  unsigned int v101; // edi
  int v102; // eax
  _DWORD *v103; // edx
  _DWORD *v104; // edx
  _DWORD *v105; // eax
  int v106; // eax
  unsigned int v107; // edi
  int v108; // eax
  _DWORD *v109; // edx
  unsigned int v110; // edx
  int *v111; // eax
  int v112; // eax
  unsigned int *v113; // edx
  unsigned int *v114; // eax
  struct D3DXShader::CArgument *v115; // esi
  unsigned int v116; // eax
  unsigned int v117; // eax
  int v118; // edx
  int *v119; // edi
  unsigned int v120; // edx
  unsigned int v121; // edx
  int v122; // esi
  struct D3DXShader::CArgument *v123; // esi
  unsigned int v124; // eax
  unsigned int v125; // edi
  struct D3DXShader::CInstruction **v126; // ecx
  int v127; // eax
  struct D3DXShader::CArgument *v128; // esi
  unsigned int v129; // eax
  unsigned int v130; // eax
  int v131; // edx
  int v132; // eax
  int *v133; // eax
  int v134; // eax
  struct D3DXShader::CInstruction **v135; // [esp-14h] [ebp-290h]
  unsigned int v136; // [esp-Ch] [ebp-288h]
  unsigned int v137; // [esp-Ch] [ebp-288h]
  unsigned int *v138; // [esp-8h] [ebp-284h]
  unsigned int v139; // [esp-8h] [ebp-284h]
  unsigned int *v140; // [esp-8h] [ebp-284h]
  unsigned int *v141; // [esp-8h] [ebp-284h]
  unsigned int v142; // [esp-4h] [ebp-280h]
  unsigned int v143; // [esp-4h] [ebp-280h]
  unsigned int v144; // [esp-4h] [ebp-280h]
  unsigned int v145; // [esp-4h] [ebp-280h]
  unsigned int v146; // [esp-4h] [ebp-280h]
  unsigned int v147[32]; // [esp+14h] [ebp-268h] BYREF
  unsigned int v148[32]; // [esp+94h] [ebp-1E8h] BYREF
  unsigned int v149[8]; // [esp+114h] [ebp-168h] BYREF
  _DWORD v150[30]; // [esp+134h] [ebp-148h] BYREF
  _DWORD v151[24]; // [esp+1ACh] [ebp-D0h] BYREF
  int v152[12]; // [esp+20Ch] [ebp-70h] BYREF
  int v153; // [esp+23Ch] [ebp-40h] BYREF
  int v154; // [esp+240h] [ebp-3Ch] BYREF
  unsigned int v155; // [esp+244h] [ebp-38h]
  unsigned int v156; // [esp+248h] [ebp-34h]
  int v157; // [esp+24Ch] [ebp-30h]
  unsigned int v158; // [esp+250h] [ebp-2Ch]
  unsigned int v159; // [esp+254h] [ebp-28h] BYREF
  unsigned int v160; // [esp+258h] [ebp-24h] BYREF
  unsigned int v161; // [esp+25Ch] [ebp-20h] BYREF
  unsigned int v162; // [esp+260h] [ebp-1Ch] BYREF
  int v163; // [esp+264h] [ebp-18h] BYREF
  unsigned int v164; // [esp+268h] [ebp-14h]
  unsigned int v165; // [esp+26Ch] [ebp-10h]
  unsigned int v166; // [esp+270h] [ebp-Ch]
  struct D3DXShader::CArgument *j; // [esp+274h] [ebp-8h] BYREF
  D3DXShader::CInstruction *v168; // [esp+278h] [ebp-4h]

  memset(v150, 0, 0x60u);
  memset(v152, 0, sizeof(v152));
  memset(v151, 0, sizeof(v151));
  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    v5 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * i);
    if ( *(_DWORD *)(v5 + 4) == *((_DWORD *)this + 34) )
      *(_DWORD *)(v5 + 12) = -1;
  }
  if ( *((_DWORD *)this + 139) != 0 )
  {
    v6 = *((_DWORD *)this + 136) == 0;
    v165 = 0;
    if ( !v6 )
    {
      v7 = 0;
      do
      {
        v8 = *(_DWORD **)(v7 + *((_DWORD *)this + 139));
        if ( v8 == nullptr )
          goto LABEL_80;
        v9 = *v8 & 0xFFF00000;
        if ( v9 == 0 || v9 == 285212672 )
          goto LABEL_80;
        if ( v9 != 1610612736
          && v9 != 1615855616
          && v9 != 1621098496
          && v9 != 1927282688
          && v9 != 1617952768
          && v9 != 1626341376
          && v9 != 1913651200 )
        {
          v10 = v8[3];
          v162 = 0;
          j = nullptr;
          if ( v10 != 0 )
          {
            v11 = *((_DWORD *)this + 5);
            v12 = (_DWORD *)v8[4];
            do
            {
              if ( *(_DWORD *)(*(_DWORD *)(v11 + 4 * *v12) + 12) == -1 )
                v162 = 1;
              else
                j = (struct D3DXShader::CArgument *)1;
              ++v12;
              --v10;
            }
            while ( v10 != 0 );
            if ( j != nullptr )
            {
              if ( v162 == 0 )
                goto LABEL_80;
              D3DXShader::CProgram::Error(
                this,
                a2: nullptr,
                a3: 0x12C8u,
                format: "internal error: unvectorized register found");
              return -2147467259;
            }
          }
          v14 = *((struct D3DXShader::CInstruction ***)this + 139);
          v15 = v14[v7 / 4];
          v161 = 0;
          v142 = *((_DWORD *)v15 + 3);
          v138 = *((unsigned int **)v15 + 4);
          v155 = v165 + 1;
          D3DXShader::CPSLegacyProgram::FindConsumers(
            this,
            a2: v14,
            a3: v165 + 1,
            a4: *((_DWORD *)this + 136),
            a5: v138,
            a6: v142,
            a7: v147,
            a8: &v161);
          v16 = 0;
          D3DXShader::CPSLegacyProgram::FindConsumers(
            this,
            a2: *((struct D3DXShader::CInstruction ***)this + 140),
            a3: 0,
            a4: *((_DWORD *)this + 137),
            a5: *(unsigned int **)(*(_DWORD *)(v7 + *((_DWORD *)this + 139)) + 16),
            a6: *(_DWORD *)(*(_DWORD *)(v7 + *((_DWORD *)this + 139)) + 12),
            a7: v147,
            a8: &v161);
          v17 = *(_DWORD *)(v7 + *((_DWORD *)this + 139));
          if ( *(_DWORD *)(v17 + 12) == 1 )
          {
            v16 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v17 + 16));
            if ( *(_DWORD *)(v16 + 16) != 4 )
              v16 = 0;
          }
          v166 = 0;
          j = (struct D3DXShader::CArgument *)v150;
          while ( 1 )
          {
            result = D3DXShader::CPSLegacyProgram::NoTexClobber(
                       this,
                       a2: v166,
                       a3: *((struct D3DXShader::CInstruction ***)this + 140),
                       a4: *((_DWORD *)this + 137),
                       a5: *(unsigned int **)(*(_DWORD *)(v7 + *((_DWORD *)this + 139)) + 16),
                       a6: *(_DWORD *)(*(_DWORD *)(v7 + *((_DWORD *)this + 139)) + 12));
            if ( result < 0 )
              return result;
            if ( result != 1 )
            {
              v18 = 0;
              if ( v16 != 0 )
              {
                v19 = j;
                while ( *(_DWORD *)v19 > v165 )
                {
                  ++v18;
                  v19 = (struct D3DXShader::CArgument *)((char *)v19 + 4);
                  if ( v18 >= 3 )
                    goto LABEL_40;
                }
                v158 = v18;
LABEL_40:
                if ( v18 != 3 )
                {
LABEL_44:
                  if ( v16 != 0 )
                    *(_DWORD *)(v16 + 16) = v158;
LABEL_46:
                  if ( v166 != 6 )
                  {
                    v164 = 0;
                    v160 = 0;
                    v168 = nullptr;
                    if ( v161 != 0 )
                    {
                      v156 = v166;
                      do
                      {
                        v20 = &v147[(_DWORD)v168];
                        v21 = *v20;
                        v22 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * *v20);
                        *((_DWORD *)v22 + 3) = v166;
                        v139 = *((_DWORD *)this + 136);
                        j = v22;
                        v162 = D3DXShader::CPSLegacyProgram::RegReassign(
                                 this,
                                 a2: *((struct D3DXShader::CInstruction ***)this + 139),
                                 a3: v155,
                                 a4: v139,
                                 a5: v21,
                                 a6: v22,
                                 a7: &v163);
                        v23 = D3DXShader::CPSLegacyProgram::RegReassign(
                                this,
                                a2: *((struct D3DXShader::CInstruction ***)this + 140),
                                a3: 0,
                                a4: *((_DWORD *)this + 137),
                                a5: *v20,
                                a6: j,
                                a7: &v163);
                        if ( v23 > v160 )
                          v160 = v23;
                        if ( v23 >= *((_DWORD *)this + 19) && *((_DWORD *)j + 4) == 3 )
                          v150[v166 + 24] = 1;
                        if ( v163 != 0 )
                          v150[v166 + 24] = 1;
                        if ( v160 != 0 || v163 != 0 )
                          v24 = -1;
                        else
                          v24 = v162;
                        if ( v24 > v164 )
                          v164 = v24;
                        v25 = 4 * v166 + *((_DWORD *)j + 4);
                        v168 = (D3DXShader::CInstruction *)((char *)v168 + 1);
                        v151[v25] = v23;
                        v26 = (unsigned int)v168 < v161;
                        v150[v25] = v24;
                      }
                      while ( v26 );
                    }
                    v27 = v166;
                    v152[v27] = v164;
                    v152[v27 + 6] = v160;
                    D3DXShader::CPSLegacyProgram::FixUpOrigins(this);
                    goto LABEL_80;
                  }
                  if ( a2 == 0 && a3 == 0 )
                  {
                    v56 = *((_DWORD *)this + 139);
                    goto LABEL_125;
                  }
                  return -2147467259;
                }
              }
              else if ( v152[v166] <= v165 )
              {
                goto LABEL_46;
              }
            }
            ++v166;
            j = (struct D3DXShader::CArgument *)((char *)j + 16);
            if ( v166 >= 6 )
              goto LABEL_44;
          }
        }
        v28 = *(_DWORD *)(v7 + *((_DWORD *)this + 139));
        v143 = *(_DWORD *)(v28 + 12);
        v140 = *(unsigned int **)(v28 + 16);
        v136 = *((_DWORD *)this + 137);
        v160 = 0;
        v135 = *((struct D3DXShader::CInstruction ***)this + 140);
        v164 = 0;
        j = nullptr;
        D3DXShader::CPSLegacyProgram::FindConsumers(
          this,
          a2: v135,
          a3: 0,
          a4: v136,
          a5: v140,
          a6: v143,
          a7: v148,
          a8: (unsigned int *)&j);
        v6 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 139) + v7) + 12) == 0;
        v168 = nullptr;
        if ( !v6 )
        {
          v156 = v165;
          do
          {
            v29 = v168;
            v30 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5)
                                                   + 4
                                                   * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 139) + v7)
                                                                           + 16)
                                                               + 4 * (_DWORD)v168));
            *((_DWORD *)v30 + 3) = v165;
            v162 = D3DXShader::CPSLegacyProgram::RegReassign(
                     this,
                     a2: *((struct D3DXShader::CInstruction ***)this + 139),
                     a3: v165 + 1,
                     a4: *((_DWORD *)this + 136),
                     a5: *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 139) + v7) + 16) + 4 * (_DWORD)v29),
                     a6: v30,
                     a7: &v163);
            v31 = D3DXShader::CPSLegacyProgram::RegReassign(
                    this,
                    a2: *((struct D3DXShader::CInstruction ***)this + 140),
                    a3: 0,
                    a4: *((_DWORD *)this + 137),
                    a5: *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 139) + v7) + 16) + 4 * (_DWORD)v168),
                    a6: v30,
                    a7: &v163);
            if ( v31 > v160 )
              v160 = v31;
            if ( v163 != 0 )
              v32 = -1;
            else
              v32 = v162;
            if ( v32 > v164 )
              v164 = v32;
            v33 = v7 + *((_DWORD *)v30 + 4);
            v168 = (D3DXShader::CInstruction *)((char *)v168 + 1);
            v151[v33] = v31;
            v34 = *(_DWORD *)(*((_DWORD *)this + 139) + v7);
            v150[v33] = v32;
          }
          while ( (unsigned int)v168 < *(_DWORD *)(v34 + 12) );
        }
        v168 = nullptr;
        v35 = v156;
        v6 = j == nullptr;
        v152[v35] = v164;
        v152[v35 + 6] = v160;
        if ( !v6 )
        {
          v156 = v165;
          do
          {
            v36 = v148[(_DWORD)v168];
            v37 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v36);
            *((_DWORD *)v37 + 3) = v165;
            v38 = D3DXShader::CPSLegacyProgram::RegReassign(
                    this,
                    a2: *((struct D3DXShader::CInstruction ***)this + 140),
                    a3: 0,
                    a4: *((_DWORD *)this + 137),
                    a5: v36,
                    a6: v37,
                    a7: &v163);
            if ( v38 > v160 )
              v160 = v38;
            v39 = v7 + *((_DWORD *)v37 + 4);
            v168 = (D3DXShader::CInstruction *)((char *)v168 + 1);
            v151[v39] = v38;
          }
          while ( v168 < j );
        }
        v152[v156 + 6] = v160;
LABEL_80:
        ++v165;
        v7 += 4;
      }
      while ( v165 < *((_DWORD *)this + 136) );
    }
  }
  if ( *((_DWORD *)this + 140) == 0 || (v6 = *((_DWORD *)this + 137) == 0, v165 = 0, v6) )
  {
LABEL_267:
    if ( *((_DWORD *)this + 139) == 0 )
      return 0;
    if ( (unsigned __int16)*((_DWORD *)this + 50) != 260 )
      return 0;
    if ( a2 != 0 )
      return 0;
    result = D3DXShader::CPSLegacyProgram::InitZs(this);
    if ( result >= 0 )
      return 0;
    return result;
  }
  while ( 1 )
  {
    v40 = 4 * v165;
    v41 = *(_DWORD *)(4 * v165 + *((_DWORD *)this + 140));
    v158 = 4 * v165;
    if ( v41 != 0 )
    {
      v42 = *(_DWORD *)v41 & 0xFFF00000;
      if ( v42 != 0 && v42 != 285212672 )
      {
        if ( v42 == 1610612736
          || v42 == 1615855616
          || v42 == 1621098496
          || v42 == 1626341376
          || v42 == 1927282688
          || v42 == 1617952768
          || v42 == 1915748352
          || v42 == 1917845504
          || v42 == 1913651200
          || v42 == 1918894080
          || v42 == 1919942656
          || v42 == 1920991232
          || v42 == 1923088384
          || v42 == 1922039808
          || v42 == 1924136960 )
        {
          v120 = 0;
          v6 = *(_DWORD *)(v41 + 12) == 0;
          v166 = 0;
          v168 = nullptr;
          if ( !v6 )
          {
            v121 = v165;
            do
            {
              v122 = *(_DWORD *)(v41 + 16);
              v154 = 4 * (_DWORD)v168;
              v123 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(4 * (_DWORD)v168 + v122));
              if ( (unsigned __int16)*((_DWORD *)this + 50) == 260 )
              {
                *((_DWORD *)v123 + 3) = v121;
                v156 = v121;
              }
              else
              {
                *((_DWORD *)v123 + 3) = v121 + 2;
                v156 = v121 + 2;
              }
              v124 = D3DXShader::CPSLegacyProgram::RegReassign(
                       this,
                       a2: *((struct D3DXShader::CInstruction ***)this + 140),
                       a3: v121 + 1,
                       a4: *((_DWORD *)this + 137),
                       a5: *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v40 + *((_DWORD *)this + 140)) + 16) + v154),
                       a6: v123,
                       a7: &v163);
              if ( v124 > v166 )
                v166 = v124;
              v125 = v156;
              v126 = *((struct D3DXShader::CInstruction ***)this + 140);
              v151[4 * v156 + *((_DWORD *)v123 + 4)] = v124;
              v127 = *(int *)((char *)v126 + v158);
              v145 = *(_DWORD *)(v127 + 12);
              v141 = *(unsigned int **)(v127 + 16);
              v137 = *((_DWORD *)this + 137);
              v162 = 0;
              D3DXShader::CPSLegacyProgram::FindConsumers(
                this,
                a2: v126,
                a3: v165 + 1,
                a4: v137,
                a5: v141,
                a6: v145,
                a7: v148,
                a8: &v162);
              for ( j = nullptr; (unsigned int)j < v162; v151[v131] = v130 )
              {
                v128 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v148[(_DWORD)j]);
                v146 = v148[(_DWORD)j];
                v129 = v165;
                *((_DWORD *)v128 + 3) = v125;
                v130 = D3DXShader::CPSLegacyProgram::RegReassign(
                         this,
                         a2: *((struct D3DXShader::CInstruction ***)this + 140),
                         a3: v129 + 1,
                         a4: *((_DWORD *)this + 137),
                         a5: v146,
                         a6: v128,
                         a7: &v163);
                if ( v130 > v166 )
                  v166 = v130;
                v131 = 4 * v125 + *((_DWORD *)v128 + 4);
                j = (struct D3DXShader::CArgument *)((char *)j + 1);
              }
              D3DXShader::CPSLegacyProgram::FixUpOrigins(this);
              v121 = v165;
              v132 = *((_DWORD *)this + 140);
              v168 = (D3DXShader::CInstruction *)((char *)v168 + 1);
              v40 = 4 * v165;
              v41 = *(_DWORD *)(4 * v165 + v132);
              v26 = (unsigned int)v168 < *(_DWORD *)(v41 + 12);
              v158 = 4 * v165;
            }
            while ( v26 );
            v120 = v166;
          }
          v133 = &v152[v156 + 6];
          if ( *v133 < v120 )
            *v133 = v120;
          goto LABEL_266;
        }
        if ( v42 != 1914699776 && v42 != 1916796928 )
          break;
      }
    }
LABEL_266:
    if ( ++v165 >= *((_DWORD *)this + 137) )
      goto LABEL_267;
  }
  if ( (unsigned __int16)*((_DWORD *)this + 50) == 257 )
  {
    v43 = *(_DWORD **)(v40 + *((_DWORD *)this + 140));
    v44 = *v43 & 0xFFFFF;
    v45 = v43[1] / v44;
    v162 = 0;
    v159 = 0;
    v158 = v45;
    if ( v45 != 0 )
    {
      v46 = *(int **)(v41 + 8);
      v47 = *((_DWORD *)this + 5);
      v157 = 4 * v44;
      v48 = v46;
      v164 = (unsigned int)v46;
      do
      {
        v49 = *v48;
        v161 = 0;
        v50 = *(_DWORD **)(v47 + 4 * v49);
        if ( v159 != 0 )
        {
          j = *(struct D3DXShader::CArgument **)(v41 + 8);
          do
          {
            v51 = *(_DWORD **)(v47 + 4 * *(_DWORD *)j);
            if ( v50[1] == v51[1] && v50[2] == v51[2] && v50[3] == v51[3] )
              break;
            ++v161;
            j = (struct D3DXShader::CArgument *)((char *)j + v157);
          }
          while ( v161 < v159 );
        }
        if ( v159 == v161 && v50[1] == *((_DWORD *)this + 34) && v50[3] >= 2u )
          ++v162;
        v48 = (int *)(v157 + v164);
        ++v159;
        v164 += v157;
      }
      while ( v159 < v158 );
      if ( v162 > 2 )
      {
        if ( a2 != 0 || a3 != 0 )
          return -2147467259;
        v56 = *((_DWORD *)this + 140);
LABEL_125:
        v57 = *(_DWORD *)(v56 + 4 * v165);
        goto LABEL_283;
      }
    }
  }
  v52 = *(_DWORD *)(v41 + 12);
  v53 = 0;
  j = nullptr;
  if ( v52 != 0 )
  {
    v54 = *((_DWORD *)this + 5);
    v55 = *(_DWORD **)(v41 + 16);
    do
    {
      if ( *(_DWORD *)(*(_DWORD *)(v54 + 4 * *v55) + 12) == -1 )
        j = (struct D3DXShader::CArgument *)1;
      else
        v53 = 1;
      ++v55;
      --v52;
    }
    while ( v52 != 0 );
    if ( v53 != 0 )
    {
      if ( j != nullptr )
      {
        D3DXShader::CProgram::Error(
          this,
          a2: nullptr,
          a3: 0x12C9u,
          format: "internal error: unvectorized register found");
        return -2147467259;
      }
      goto LABEL_266;
    }
  }
  v58 = *((struct D3DXShader::CInstruction ***)this + 140);
  v59 = v165;
  v60 = v58[v165];
  v159 = 0;
  D3DXShader::CPSLegacyProgram::FindConsumers(
    this,
    a2: v58,
    a3: v165 + 1,
    a4: *((_DWORD *)this + 137),
    a5: *((unsigned int **)v60 + 4),
    a6: *((_DWORD *)v60 + 3),
    a7: v149,
    a8: &v159);
  v61 = *((D3DXShader::CInstruction **)this + 50);
  v163 = -1;
  v166 = -1;
  v61 = (D3DXShader::CInstruction *)(unsigned __int16)v61;
  v168 = v61;
  if ( (unsigned __int16)v61 == 258 || (unsigned __int16)v61 == 259 )
  {
    v62 = *(_DWORD **)(*((_DWORD *)this + 140) + 4 * v59);
    if ( *v62 == 1342177284 )
    {
      v63 = (_DWORD *)v62[2];
      v64 = *((_DWORD *)this + 5);
      v65 = *(_DWORD *)(v64 + 4 * *v63);
      v66 = *((_DWORD *)this + 34);
      if ( *(_DWORD *)(v65 + 4) == v66 )
        v163 = *(_DWORD *)(v65 + 12);
      v67 = *(_DWORD *)(v64 + 4 * v63[4]);
      if ( *(_DWORD *)(v67 + 4) == v66 )
        v166 = *(_DWORD *)(v67 + 12);
    }
  }
  v157 = 0;
  v161 = 0;
  if ( v159 != 0 )
  {
    do
    {
      v68 = *((_DWORD *)this + 137);
      v69 = v59 + 1;
      if ( v59 + 1 < v68 )
      {
        j = (struct D3DXShader::CArgument *)(*((_DWORD *)this + 140) + 4 * v69);
        v70 = v68 - v69;
        do
        {
          v71 = *(int **)j;
          if ( *(_DWORD *)j != 0 )
          {
            v72 = *v71;
            if ( (*v71 & 0xFFF00000) == 0x70F00000 )
            {
              v73 = v72 & 0xFFFFF;
              if ( (v72 & 0xFFFFF) != 0 )
              {
                v74 = v149[v161];
                v75 = (_DWORD *)v71[2];
                v162 = v73;
                do
                {
                  if ( *v75 == v74 )
                    v157 = 1;
                  ++v75;
                  --v162;
                }
                while ( v162 != 0 );
              }
            }
          }
          j = (struct D3DXShader::CArgument *)((char *)j + 4);
          --v70;
        }
        while ( v70 != 0 );
      }
      ++v161;
    }
    while ( v161 < v159 );
    if ( v157 != 0 )
      goto LABEL_152;
  }
  v6 = *((_DWORD *)this + 275) == 0;
  v164 = 1;
  if ( v6 )
LABEL_152:
    v164 = 0;
  v76 = *(int **)(4 * v59 + *((_DWORD *)this + 140));
  v77 = *v76;
  v78 = *v76 & 0xFFFFF;
  v158 = (unsigned int)v76;
  if ( v78 != 1
    || (v77 & 0xFFF00000) == 0x50000000
    || v159 != 1
    || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v149[0]) + 16) != 3
    || v164 == 0 )
  {
    v79 = v165;
    goto LABEL_165;
  }
  v79 = v165;
  k = 1;
  v161 = 1;
  v81 = &v151[7];
  do
  {
    if ( v152[k + 6] > v165 && *v81 <= v165 )
      break;
    ++k;
    v81 += 4;
    v161 = k;
  }
  while ( k < 6 );
  if ( k == 6 )
  {
LABEL_165:
    for ( k = v164 != 0; ; ++k )
    {
      v161 = k;
      if ( k >= 6 || v152[k + 6] <= v79 && k != v163 && k != v166 )
        break;
    }
    v76 = (int *)v158;
  }
  if ( k != 0 && v164 == 0 && *((_DWORD *)this + 275) != 0 )
  {
    if ( a2 != 0 || a3 != 0 )
      return -2147467259;
    v134 = *((_DWORD *)this + 139);
LABEL_282:
    v57 = *(_DWORD *)(v134 + 4 * v79);
LABEL_283:
    D3DXShader::CProgram::Error(
      this,
      a2: *(struct D3DXShader::CNode **)(v57 + 60),
      a3: 0x11A9u,
      format: "program too complex: out of temporary registers");
    return -2147467259;
  }
  if ( k == 6 )
  {
    if ( (unsigned __int16)*((_DWORD *)this + 50) == 260 && a3 != 0 )
      return -2147467259;
    v134 = *((_DWORD *)this + 140);
    goto LABEL_282;
  }
  v155 = 0;
  if ( (v77 & 0xFFF00000) != 0x50000000 || (unsigned int)v168 >= 0x104 || v76[3] != 1 )
  {
LABEL_242:
    v166 = 0;
    if ( v159 != 0 )
    {
      v168 = nullptr;
      do
      {
        v115 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v149[(_DWORD)v168]);
        v144 = v149[(_DWORD)v168];
        v116 = v165;
        *((_DWORD *)v115 + 3) = k;
        v117 = D3DXShader::CPSLegacyProgram::RegReassign(
                 this,
                 a2: *((struct D3DXShader::CInstruction ***)this + 140),
                 a3: v116 + 1,
                 a4: *((_DWORD *)this + 137),
                 a5: v144,
                 a6: v115,
                 a7: &v163);
        if ( v117 > v166 )
          v166 = v117;
        v118 = 4 * k + *((_DWORD *)v115 + 4);
        v168 = (D3DXShader::CInstruction *)((char *)v168 + 1);
        v151[v118] = v117;
      }
      while ( (unsigned int)v168 < v159 );
      v119 = &v152[k + 6];
      if ( *v119 < v166 )
        *v119 = v166;
      D3DXShader::CPSLegacyProgram::FixUpOrigins(this);
    }
    else
    {
      **(_DWORD **)(4 * v165 + *((_DWORD *)this + 140)) = 0;
    }
    goto LABEL_266;
  }
  v82 = 4 * v165;
  D3DXShader::CPSLegacyProgram::AnalizeArgUse(
    this,
    a2: *((struct D3DXShader::CInstruction ***)this + 140),
    a3: v165 + 1,
    a4: *((_DWORD *)this + 137),
    a5: *(unsigned int **)(*(_DWORD *)(4 * v165 + *((_DWORD *)this + 140)) + 16),
    a6: *(_DWORD *)(*(_DWORD *)(4 * v165 + *((_DWORD *)this + 140)) + 12),
    a7: &v160,
    a8: &v153,
    a9: &v154);
  if ( v153 != 0 )
    v160 = 4;
  v83 = v160 <= 4;
  if ( v160 < 4 )
  {
    v160 = 3;
    v83 = true;
  }
  if ( !v83 )
    v160 = 4;
  v84 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v84 != nullptr )
    v168 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v84);
  else
    v168 = nullptr;
  if ( v168 == nullptr )
    return -2147024882;
  result = D3DXShader::CInstruction::Initialize(
             this: v168,
             a2: **(_DWORD **)(v82 + *((_DWORD *)this + 140)),
             a3: *(_DWORD *)(*(_DWORD *)(v82 + *((_DWORD *)this + 140)) + 4),
             a4: v160,
             a5: 0);
  if ( result >= 0 )
  {
    result = D3DXShader::CInstruction::Instance(
               this: v168,
               a2: *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 140) + v82));
    if ( result >= 0 )
    {
      v85 = 4 * v165;
      qmemcpy(
        *((void **)v168 + 2),
        *(const void **)(*(_DWORD *)(*((_DWORD *)this + 140) + 4 * v165) + 8),
        4 * *((_DWORD *)v168 + 1));
      v86 = *(_DWORD *)(v85 + *((_DWORD *)this + 140));
      v87 = *(_DWORD *)(v86 + 12);
      v88 = *(const void **)(v86 + 16);
      v89 = v168;
      v158 = v87;
      qmemcpy(&v152[2], v88, 4 * v87);
      *(_DWORD *)(v85 + *((_DWORD *)this + 140)) = v89;
      result = D3DXShader::CBaseProgram::AddInstruction(this, a2: v89);
      if ( result >= 0 )
      {
        v90 = 0;
        v91 = 0;
        v166 = 0;
        for ( j = nullptr; (unsigned int)j < v158; j = (struct D3DXShader::CArgument *)((char *)j + 1) )
        {
          v6 = *((_DWORD *)this + 2) == 0;
          v164 = 0;
          if ( !v6 )
          {
            do
            {
              v92 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v164);
              v93 = v152[(_DWORD)j + 2];
              if ( v164 == v93 || v92[14] == v93 )
              {
                if ( v160 != 0 )
                {
                  do
                  {
                    v94 = D3DXShader::CBaseProgram::AddArgument(
                            this,
                            a2: *((_DWORD *)this + 34),
                            a3: v161,
                            a4: v90,
                            a5: 0.0);
                    *(_DWORD *)(*((_DWORD *)v168 + 4) + 4 * v90) = v94;
                    if ( *(_DWORD *)(*((_DWORD *)v168 + 4) + 4 * v90) == -1 )
                      return -2147024882;
                    v95 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v168 + 4) + 4 * v90));
                    v95[18] = v92[18];
                    v95[21] = v92[21];
                    v95[22] = v92[22];
                    v26 = ++v90 < v160;
                    v95[15] = v92[15];
                  }
                  while ( v26 );
                }
                v96 = v165 + 1;
                v163 = v165 + 1;
                while ( v96 < *((_DWORD *)this + 137) )
                {
                  v97 = *(int **)(*((_DWORD *)this + 140) + 4 * v163);
                  if ( v97 != nullptr )
                  {
                    v98 = *v97;
                    if ( *v97 != 0 )
                    {
                      v99 = v98 & 0xFFFFF;
                      v100 = v97[1] / (v98 & 0xFFFFFu);
                      v162 = 0;
                      v155 = v99;
                      v154 = v100;
                      if ( v100 != 0 )
                      {
                        v157 = 0;
                        do
                        {
                          if ( v99 < 3 )
                          {
                            if ( v99 == 1 )
                            {
                              v104 = (_DWORD *)(v97[2] + 4 * v162);
                              if ( *v104 == v164 )
                              {
                                v105 = *((_DWORD **)v168 + 4);
                                v106 = v160 == 4 ? v105[3] : *v105;
                                *v104 = v106;
                                if ( v163 > v166 )
                                  v166 = v163;
                              }
                            }
                            else
                            {
                              v107 = 0;
                              if ( v99 != 0 )
                              {
                                v108 = v157;
                                do
                                {
                                  v109 = (_DWORD *)(v97[2] + v108);
                                  if ( *v109 == v164 )
                                  {
                                    *v109 = *(_DWORD *)(*((_DWORD *)v168 + 4) + 4 * v107);
                                    if ( v163 > v166 )
                                      v166 = v163;
                                  }
                                  v99 = v155;
                                  ++v107;
                                  v108 += 4;
                                }
                                while ( v107 < v155 );
                              }
                            }
                          }
                          else
                          {
                            v101 = 0;
                            v102 = v157;
                            do
                            {
                              v103 = (_DWORD *)(v97[2] + v102);
                              if ( *v103 == v164 )
                              {
                                *v103 = *(_DWORD *)(*((_DWORD *)v168 + 4) + 4 * v101);
                                if ( v163 > v166 )
                                  v166 = v163;
                              }
                              v99 = v155;
                              ++v101;
                              v102 += 4;
                            }
                            while ( v101 < v155 );
                          }
                          ++v162;
                          v157 += 4 * v99;
                        }
                        while ( v162 < v154 );
                      }
                    }
                  }
                  v96 = ++v163;
                }
                v91 = v166;
                v155 = 1;
                v90 = 0;
              }
              ++v164;
            }
            while ( v164 < *((_DWORD *)this + 2) );
          }
        }
        v110 = v161;
        v111 = &v152[v161 + 6];
        if ( *v111 < v91 )
          *v111 = v91;
        v112 = 4 * v110;
        v113 = &v151[4 * v110];
        if ( *v113 < v91 )
          *v113 = v91;
        if ( v151[v112 + 1] < v91 )
          v151[v112 + 1] = v91;
        if ( v151[v112 + 2] < v91 )
          v151[v112 + 2] = v91;
        v114 = &v151[v112 + 3];
        if ( *v114 < v91 )
          *v114 = v91;
        if ( v155 != 0 )
          goto LABEL_266;
        k = v161;
        goto LABEL_242;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102093CE
// Name: protected: class D3DXShader::CInstruction __near * D3DXShader::CPSLegacyProgram::InstSearch(class D3DXShader::CInstruction __near * __near *,unsigned int,unsigned int __near *,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CInstruction *__thiscall D3DXShader::CPSLegacyProgram::InstSearch(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3,
        unsigned int *a4,
        unsigned int a5,
        int a6)
{
  unsigned int v6; // eax
  struct D3DXShader::CInstruction *v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // edx
  int v10; // edi
  unsigned int v11; // ebx
  bool v12; // zf
  _DWORD *v13; // esi
  int *v14; // esi
  int v15; // eax
  unsigned int v18; // [esp+10h] [ebp-14h]
  struct D3DXShader::CInstruction *v19; // [esp+14h] [ebp-10h]
  int v20; // [esp+18h] [ebp-Ch]
  unsigned int v21; // [esp+1Ch] [ebp-8h]
  int v22; // [esp+20h] [ebp-4h]

  v6 = 0;
  v21 = 0;
  if ( a3 == 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = a2[v6];
    v19 = v7;
    if ( v7 != nullptr && *((_DWORD *)v7 + 3) >= a5 )
      break;
LABEL_25:
    v6 = ++v21;
    if ( v21 >= a3 )
      return nullptr;
  }
  v8 = 0;
  v22 = 1;
  v18 = 0;
  if ( a5 == 0 )
    return a2[v21];
  v20 = *((_DWORD *)this + 5);
  do
  {
    v9 = a4[v8];
    v10 = *(_DWORD *)(v20 + 4 * v9);
    v11 = 0;
    if ( a6 != 0 )
    {
      v12 = *((_DWORD *)v7 + 3) == 0;
      if ( *((_DWORD *)v7 + 3) == 0 )
        goto LABEL_21;
      v13 = *((_DWORD **)v7 + 4);
      do
      {
        if ( *v13 == v9 )
          break;
        if ( *v13 == *(_DWORD *)(v10 + 56) )
          break;
        ++v11;
        ++v13;
      }
      while ( v11 < *((_DWORD *)v7 + 3) );
    }
    else
    {
      v12 = *((_DWORD *)v7 + 3) == 0;
      if ( *((_DWORD *)v7 + 3) == 0 )
        goto LABEL_21;
      v14 = *((int **)v7 + 4);
      do
      {
        v15 = *v14;
        if ( *v14 == v9 && *(_DWORD *)(v10 + 60) == 0 )
          break;
        if ( v15 == *(_DWORD *)(v10 + 56) )
        {
          v7 = v19;
          if ( *(_DWORD *)(*(_DWORD *)(v20 + 4 * v15) + 60) == 0 )
            break;
        }
        ++v11;
        ++v14;
      }
      while ( v11 < *((_DWORD *)v7 + 3) );
    }
    v12 = v11 == *((_DWORD *)v7 + 3);
LABEL_21:
    if ( v12 )
      v22 = 0;
    v8 = ++v18;
  }
  while ( v18 < a5 );
  if ( v22 == 0 )
    goto LABEL_25;
  return a2[v21];
}

//------------------------------------------------------------------------------
// Address: 0x102094C6
// Name: protected: long D3DXShader::CPSLegacyProgram::FindTex(class D3DXShader::CInstruction __near * __near *,unsigned int,class D3DXShader::CInstruction __near *,unsigned int __near *,unsigned int __near *,class D3DXShader::CInstruction __near * __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::FindTex(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3,
        struct D3DXShader::CInstruction *a4,
        unsigned int *a5,
        unsigned int *a6,
        struct D3DXShader::CInstruction **a7,
        int a8,
        int a9)
{
  unsigned int v10; // esi
  unsigned int v11; // edi
  int v13; // eax
  unsigned int v14; // edx
  _DWORD *v15; // eax
  struct D3DXShader::CInstruction *v16; // eax
  unsigned int v17; // ecx
  int v18; // eax
  unsigned int v19; // [esp+Ch] [ebp-8h]
  struct D3DXShader::CInstruction *v21; // [esp+24h] [ebp+10h]
  struct D3DXShader::CInstruction *v22; // [esp+24h] [ebp+10h]
  unsigned int v23; // [esp+38h] [ebp+24h]
  int v24; // [esp+38h] [ebp+24h]

  v10 = *(_DWORD *)a4 & 0xFFFFF;
  v11 = 0;
  *a7 = nullptr;
  *a6 = 0;
  *a5 = 0;
  if ( v10 == 0 )
    return -2147467259;
  v13 = *((_DWORD *)a4 + 1) / v10;
  v19 = v13;
  if ( a9 == 0 )
  {
    v23 = 0;
    if ( v13 != 0 )
    {
      v21 = nullptr;
      do
      {
        v14 = 0;
        v15 = (_DWORD *)((char *)v21 + *((_DWORD *)a4 + 2));
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v15) + 16) != v14 )
            return 1;
          ++v14;
          ++v15;
        }
        while ( v14 < v10 );
        v11 = 0;
        ++v23;
        v21 = (struct D3DXShader::CInstruction *)((char *)v21 + 4 * v10);
        v13 = v19;
      }
      while ( v23 < v19 );
    }
  }
  v24 = 0;
  v22 = nullptr;
  if ( v13 == 0 )
    return 0;
  while ( 1 )
  {
    v16 = D3DXShader::CPSLegacyProgram::InstSearch(
            this,
            a2,
            a3,
            a4: (unsigned int *)(*((_DWORD *)a4 + 2) + 4 * v11),
            a5: v10,
            a6: a8);
    if ( v16 != nullptr )
    {
      v17 = *(_DWORD *)v16 & 0xFFF00000;
      if ( a8 != 0 )
        break;
      if ( v17 == 1913651200 )
        goto LABEL_21;
    }
LABEL_26:
    v22 = (struct D3DXShader::CInstruction *)((char *)v22 + 1);
    v11 += v10;
    if ( (unsigned int)v22 >= v19 )
      return 0;
  }
  if ( v17 != 1610612736 && v17 != 1615855616 && v17 != 1621098496 && v17 != 1626341376 )
    goto LABEL_26;
LABEL_21:
  if ( v24 == 0 )
  {
    *a7 = v16;
    v24 = 1;
    *a6 = v11;
    if ( a8 != 0 )
      v18 = *(_DWORD *)(*((_DWORD *)v16 + 2) + 4 * (*(_DWORD *)v16 & 0xFFFFF));
    else
      v18 = **((_DWORD **)v16 + 2);
    *a5 = *(unsigned __int8 *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v18) + 109);
    goto LABEL_26;
  }
  *a6 = 0;
  *a5 = 0;
  *a7 = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10209627
// Name: protected: long D3DXShader::CPSLegacyProgram::MatchDep(class D3DXShader::CInstruction __near * __near *,unsigned int,class D3DXShader::CInstruction __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::MatchDep(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3,
        struct D3DXShader::CInstruction **a4)
{
  int *v5; // edi
  int v6; // ebx
  unsigned int *v7; // ebx
  struct D3DXShader::CInstruction *v8; // eax
  struct D3DXShader::CInstruction *v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  int v12; // ebx
  _DWORD *v13; // eax
  int v14; // ecx
  int v15; // ecx
  unsigned __int8 *v16; // eax
  int v17; // edi
  unsigned int v18; // ebx
  int v19; // edi
  struct D3DXShader::CInstruction *v20; // eax
  int v21; // eax
  int v22; // ecx
  unsigned __int8 *v23; // eax
  unsigned int i; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // edx
  unsigned int v28; // edi
  unsigned int j; // eax
  unsigned int v30; // eax
  D3DXShader::CArgument *v31; // ebx
  unsigned int v32; // eax
  unsigned int v33; // ebx
  unsigned int v34; // ecx
  int v35; // eax
  D3DXShader::CArgument *v36; // edi
  unsigned int v37; // edx
  int v38; // eax
  D3DXShader::CInstruction *v39; // eax
  int v40; // edx
  int v41; // eax
  bool v42; // cf
  struct D3DXShader::CInstruction *v43; // eax
  struct D3DXShader::CInstruction **v45; // [esp-Ch] [ebp-6Ch]
  unsigned int v46; // [esp-8h] [ebp-68h]
  _DWORD v47[2]; // [esp+14h] [ebp-4Ch]
  _DWORD v48[2]; // [esp+1Ch] [ebp-44h]
  unsigned int v49; // [esp+24h] [ebp-3Ch]
  unsigned int v50; // [esp+28h] [ebp-38h]
  int v51; // [esp+2Ch] [ebp-34h]
  struct D3DXShader::CArgument *v52; // [esp+30h] [ebp-30h]
  struct D3DXShader::CInstruction *v53; // [esp+34h] [ebp-2Ch]
  struct D3DXShader::CInstruction *v54; // [esp+38h] [ebp-28h] BYREF
  unsigned int v55; // [esp+3Ch] [ebp-24h] BYREF
  int v56; // [esp+40h] [ebp-20h]
  struct D3DXShader::CInstruction *v57; // [esp+44h] [ebp-1Ch]
  unsigned int v58; // [esp+48h] [ebp-18h]
  unsigned int v59; // [esp+4Ch] [ebp-14h] BYREF
  struct D3DXShader::CInstruction *v60; // [esp+50h] [ebp-10h] BYREF
  unsigned int v61; // [esp+54h] [ebp-Ch]
  struct D3DXShader::CInstruction **v62; // [esp+58h] [ebp-8h]
  D3DXShader::CInstruction *v63; // [esp+5Ch] [ebp-4h]

  v63 = nullptr;
  v61 = 0;
  if ( a3 != 0 )
  {
    v62 = a2;
    do
    {
      v5 = (int *)*v62;
      if ( *v62 != nullptr )
      {
        v56 = *v5;
        v6 = v56 & 0xFFFFF;
        v58 = v56 & 0xFFFFF;
        D3DXShader::CPSLegacyProgram::FindTex(
          this,
          a2: a4,
          a3: 4u,
          a4: (struct D3DXShader::CInstruction *)v5,
          a5: &v59,
          a6: &v55,
          a7: &v60,
          a8: 1,
          a9: 1);
        if ( v60 != nullptr )
        {
          if ( v6 == 2 )
            goto LABEL_68;
        }
        else
        {
          if ( v6 != 2 )
            goto LABEL_68;
          v7 = (unsigned int *)(v5[2] + 8);
          v8 = D3DXShader::CPSLegacyProgram::InstSearch(
                 this,
                 a2: *((struct D3DXShader::CInstruction ***)this + 139),
                 a3: *((_DWORD *)this + 136),
                 a4: v7,
                 a5: 1u,
                 a6: 0);
          v46 = *((_DWORD *)this + 136);
          v45 = *((struct D3DXShader::CInstruction ***)this + 139);
          v57 = v8;
          v9 = D3DXShader::CPSLegacyProgram::InstSearch(this, a2: v45, a3: v46, a4: v7 + 1, a5: 1u, a6: 0);
          v53 = v9;
          if ( v57 == nullptr )
            goto LABEL_68;
          if ( v9 == nullptr )
            goto LABEL_68;
          D3DXShader::CPSLegacyProgram::FindTex(
            this,
            a2: a4,
            a3: 4u,
            a4: v57,
            a5: &v59,
            a6: &v55,
            a7: &v54,
            a8: 1,
            a9: 1);
          if ( v54 == nullptr )
            goto LABEL_68;
          D3DXShader::CPSLegacyProgram::FindTex(
            this,
            a2: a4,
            a3: 4u,
            a4: v53,
            a5: &v59,
            a6: &v55,
            a7: &v60,
            a8: 1,
            a9: 1);
          if ( v54 != v60 )
            goto LABEL_68;
          v6 = v58;
        }
        if ( v60 != nullptr )
        {
          v10 = 0;
          v63 = nullptr;
          if ( v6 == 3 )
          {
            if ( (v56 & 0xFFF00000) != 0x60F00000 && (v56 & 0xFFF00000) != 0x60A00000 )
              goto LABEL_68;
            v11 = v5[2];
            v12 = *((_DWORD *)this + 5);
            v55 = 1;
            v13 = (_DWORD *)(v11 + 12);
            do
            {
              v14 = *(_DWORD *)(v12 + 4 * *v13);
              if ( *(_DWORD *)(v14 + 16) != v10 )
                v55 = 0;
              v15 = *(_DWORD *)(v14 + 60);
              if ( v15 != 0 && v15 != 393216 )
              {
                D3DXShader::CProgram::Error(
                  this,
                  a2: *((struct D3DXShader::CNode **)a2[v61] + 15),
                  a3: 0x11B7u,
                  format: "cannot match to texreg2rgb instruction because can only have input modifier _bx2");
                return -2147467259;
              }
              ++v10;
              ++v13;
            }
            while ( v10 < 3 );
            if ( v55 == 0 )
              goto LABEL_68;
            if ( (unsigned __int16)*((_DWORD *)this + 50) < 0x102u )
            {
              D3DXShader::CProgram::Error(
                this,
                a2: *((struct D3DXShader::CNode **)a2[v61] + 15),
                a3: 0x11B8u,
                format: "expression can only be map to texreg2rgb, but this instruction is not supported on 1_%i",
                (unsigned __int8)*((_DWORD *)this + 50));
              return -2147467259;
            }
            v16 = D3DXShader::CInstruction::operator new(a1: 0x74u);
            if ( v16 != nullptr )
              v63 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v16);
            else
              v63 = nullptr;
            if ( v63 == nullptr )
              goto LABEL_77;
            v17 = D3DXShader::CInstruction::Initialize(this: v63, a2: 0x72600003u, a3: 6u, a4: 4u, a5: 0);
            if ( v17 < 0 )
              goto LABEL_70;
          }
          else
          {
            if ( v6 != 2 || (v56 & 0xFFF00000) != 0x60500000 )
              goto LABEL_68;
            v18 = 0;
            v19 = 1;
            v48[0] = 3;
            v48[1] = 0;
            v47[0] = 1;
            v47[1] = 2;
            v55 = 1;
            do
            {
              v20 = v57;
              if ( v18 != 0 )
                v20 = v53;
              v21 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v20 + 2));
              v22 = *(_DWORD *)(v21 + 16);
              if ( v22 != v48[v18] )
                v55 = 0;
              if ( v22 != v47[v18] )
                v19 = 0;
              if ( *(_DWORD *)(v21 + 60) != 0 )
              {
                D3DXShader::CProgram::Error(
                  this,
                  a2: *((struct D3DXShader::CNode **)a2[v61] + 15),
                  a3: 0x11B7u,
                  format: "cannot match to texreg2ar or texreg2gb instruction because cannot have input modifiers");
                return -2147467259;
              }
              ++v18;
            }
            while ( v18 < 2 );
            if ( v55 == 0 && v19 == 0 )
              goto LABEL_68;
            v23 = D3DXShader::CInstruction::operator new(a1: 0x74u);
            if ( v23 != nullptr )
              v63 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v23);
            else
              v63 = nullptr;
            if ( v63 == nullptr )
              goto LABEL_77;
            v17 = D3DXShader::CInstruction::Initialize(
                    this: v63,
                    a2: v19 != 0 ? 1920991234 : 1919942658,
                    a3: 4u,
                    a4: 4u,
                    a5: 0);
            if ( v17 < 0 )
              goto LABEL_70;
          }
          for ( i = 0; i < 0x10; i += 4 )
            *(_DWORD *)(i + *((_DWORD *)v63 + 4)) = *(_DWORD *)(i + *((_DWORD *)*v62 + 4));
          v25 = *((_DWORD *)this + 5);
          v26 = *(_DWORD *)(v25 + 4 * **((_DWORD **)*v62 + 2));
          v27 = *((_DWORD *)this + 4);
          v52 = *(struct D3DXShader::CArgument **)(v25 + 4 * *(_DWORD *)(*((_DWORD *)v60 + 2) + 12));
          if ( (*(_BYTE *)(*(_DWORD *)(v27 + 4 * *(_DWORD *)(v26 + 4)) + 5) & 8) != 0 )
          {
            v55 = *(_DWORD *)(v26 + 12);
            v28 = v55;
            if ( v55 > 3 || a4[v55] != nullptr )
              goto LABEL_53;
          }
          else
          {
            for ( j = v59; j < 4 && a4[j] != nullptr; ++j )
              ;
            if ( j == 4 )
            {
LABEL_53:
              v17 = -2147467259;
              goto LABEL_70;
            }
            v55 = j;
            *(_DWORD *)(v26 + 12) = j;
            v28 = j;
          }
          v30 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 32), a3: v28, a4: 0, a5: 0.0);
          v50 = v30;
          if ( v30 == -1 )
            goto LABEL_77;
          v31 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v30);
          D3DXShader::CArgument::Initialize(this: v31, a2: v52);
          *((_DWORD *)v31 + 27) = (v28 << 8) | 3;
          v32 = v58;
          *((_DWORD *)v31 + 3) = v28;
          v33 = 0;
          if ( v32 != 0 )
          {
            v56 = 4 * v32;
            while ( 1 )
            {
              v34 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 32), a3: v59, a4: v33, a5: 0.0);
              v49 = v34;
              if ( v34 == -1 )
                break;
              v35 = *((_DWORD *)this + 5);
              v36 = *(D3DXShader::CArgument **)(v35 + 4 * v34);
              v51 = *(_DWORD *)(v35 + 4 * *(_DWORD *)(4 * v58 + *((_DWORD *)*v62 + 2)));
              D3DXShader::CArgument::Initialize(this: v36, a2: v52);
              v37 = v50;
              *((_DWORD *)v36 + 3) = v59;
              v38 = v51;
              *((_DWORD *)v36 + 4) = v33;
              *((_DWORD *)v36 + 15) = *(_DWORD *)(v38 + 60);
              v39 = v63;
              *(_DWORD *)(*((_DWORD *)v63 + 2) + 4 * v33) = v37;
              v40 = v56;
              v41 = *((_DWORD *)v39 + 2);
              v56 += 4;
              v42 = ++v33 < v58;
              *(_DWORD *)(v40 + v41) = v49;
              if ( !v42 )
              {
                v28 = v55;
                goto LABEL_66;
              }
            }
LABEL_77:
            v17 = -2147024882;
            goto LABEL_70;
          }
LABEL_66:
          v43 = v63;
          a4[v28] = v63;
          v17 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v43);
          if ( v17 < 0 )
            goto LABEL_70;
          *v62 = nullptr;
          v63 = nullptr;
        }
      }
LABEL_68:
      ++v61;
      ++v62;
    }
    while ( v61 < a3 );
  }
  v17 = 0;
LABEL_70:
  if ( v63 != nullptr )
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v63, a2: 1);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x10209AFB
// Name: protected: long D3DXShader::CPSLegacyProgram::Match3xM(class D3DXShader::CInstruction __near * __near *,unsigned int,class D3DXShader::CInstruction __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::Match3xM(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3,
        struct D3DXShader::CInstruction **a4,
        unsigned int a5)
{
  struct D3DXShader::CInstruction *v6; // edx
  int v7; // ecx
  int v8; // esi
  struct D3DXShader::CInstruction *v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // eax
  bool v12; // cf
  unsigned int *v13; // esi
  struct D3DXShader::CInstruction *v14; // ecx
  D3DXShader::CArgument *v15; // eax
  bool v16; // zf
  int v17; // edx
  _DWORD *v18; // eax
  unsigned int v19; // esi
  struct D3DXShader::CInstruction *v20; // eax
  int v21; // ecx
  unsigned int v22; // esi
  int v23; // eax
  int v24; // eax
  unsigned __int8 *v25; // eax
  D3DXShader::CInstruction *v26; // ecx
  int v27; // eax
  int v28; // eax
  unsigned int v29; // eax
  int v30; // esi
  D3DXShader::CInstruction *v31; // edi
  unsigned int v32; // eax
  unsigned int v33; // esi
  unsigned int v34; // edx
  int v35; // ecx
  int v36; // eax
  D3DXShader::CArgument *v37; // edx
  int v38; // eax
  unsigned int v39; // eax
  D3DXShader::CArgument *v40; // eax
  unsigned int v41; // ecx
  struct D3DXShader::CInstruction **v42; // edx
  unsigned int j; // eax
  int v44; // eax
  int v45; // eax
  int v46; // esi
  int v47; // ecx
  struct D3DXShader::CInstruction *v48; // ecx
  struct D3DXShader::CInstruction **v49; // edi
  struct D3DXShader::CInstruction *v50; // eax
  unsigned int k; // edi
  D3DXShader::CInstruction *v52; // ecx
  unsigned int v54; // [esp-Ch] [ebp-A4h]
  unsigned int v55; // [esp+0h] [ebp-98h]
  const char *v56; // [esp+0h] [ebp-98h]
  unsigned int v57; // [esp+0h] [ebp-98h]
  const char *v58; // [esp+4h] [ebp-94h]
  struct D3DXShader::CInstruction *v59[3]; // [esp+14h] [ebp-84h] BYREF
  unsigned int v60[12]; // [esp+20h] [ebp-78h] BYREF
  D3DXShader::CInstruction *v61[3]; // [esp+50h] [ebp-48h] BYREF
  struct D3DXShader::CInstruction *v62[4]; // [esp+5Ch] [ebp-3Ch] BYREF
  int v63; // [esp+6Ch] [ebp-2Ch]
  unsigned int v64; // [esp+70h] [ebp-28h]
  D3DXShader::CArgument *v65; // [esp+74h] [ebp-24h]
  unsigned int v66; // [esp+78h] [ebp-20h]
  unsigned int v67; // [esp+7Ch] [ebp-1Ch]
  unsigned int *v68; // [esp+80h] [ebp-18h]
  struct D3DXShader::CInstruction **v69; // [esp+84h] [ebp-14h]
  struct D3DXShader::CInstruction *v70; // [esp+88h] [ebp-10h]
  unsigned int *v71; // [esp+8Ch] [ebp-Ch]
  D3DXShader::CArgument *v72; // [esp+90h] [ebp-8h]
  unsigned int i; // [esp+94h] [ebp-4h]

  v64 = 0;
  memset(v61, 0, sizeof(v61));
  if ( a3 == 0 )
  {
LABEL_83:
    v30 = 0;
    goto LABEL_84;
  }
  v69 = a2;
  while ( 1 )
  {
    v6 = *v69;
    if ( *v69 != nullptr )
    {
      v7 = *(_DWORD *)v6 & 0xFFFFF;
      v8 = v7;
      if ( (*(_DWORD *)v6 & 0xFFF00000) == 0x60000000 )
        v7 = 1;
      if ( v7 == a5 && (*(_DWORD *)v6 & 0xFFF00000) != 0x11000000 )
      {
        v72 = nullptr;
        i = 0;
        if ( a5 == 0 )
          break;
        v71 = (unsigned int *)(*((_DWORD *)v6 + 2) + 4 * v8);
        do
        {
          v9 = D3DXShader::CPSLegacyProgram::InstSearch(
                 this,
                 a2: *((struct D3DXShader::CInstruction ***)this + 139),
                 a3: *((_DWORD *)this + 136),
                 a4: v71,
                 a5: 1u,
                 a6: 0);
          v10 = i;
          v70 = v9;
          v60[i + 9] = (unsigned int)v9;
          if ( v9 != nullptr && *(_DWORD *)v9 == 1342177283 )
          {
            D3DXShader::CPSLegacyProgram::FindTex(
              this,
              a2: *((struct D3DXShader::CInstruction ***)this + 139),
              a3: *((_DWORD *)this + 136),
              a4: v70,
              a5: (unsigned int *)&v62[v10 + 1],
              a6: &v60[v10 + 3],
              a7: &v59[v10],
              a8: 0,
              a9: 0);
            v68 = &v60[v10];
            D3DXShader::CPSLegacyProgram::FindTex(
              this,
              a2: a4,
              a3: 4u,
              a4: v70,
              a5: &v60[v10],
              a6: &v60[v10 + 6],
              a7: v62,
              a8: 1,
              a9: 0);
            if ( v59[v10] == nullptr || *v68 != v60[0] || v62[0] == nullptr )
              v72 = (D3DXShader::CArgument *)1;
          }
          else
          {
            v72 = (D3DXShader::CArgument *)1;
          }
          ++i;
          ++v71;
        }
        while ( i < a5 );
        if ( v72 == nullptr )
          break;
      }
    }
LABEL_82:
    ++v64;
    ++v69;
    if ( v64 >= a3 )
      goto LABEL_83;
  }
  i = 0;
  if ( a5 == 0 )
  {
LABEL_61:
    for ( i = 0; i < a5; ++i )
    {
      v70 = nullptr;
      v31 = v61[i];
      v68 = (unsigned int *)v60[i + 9];
      v71 = (unsigned int *)v59[i];
      v32 = 4 * v60[i + 3];
      v33 = 12;
      v66 = 4 * v60[i + 6];
      v67 = v32;
      do
      {
        v34 = v66;
        *(_DWORD *)(v33 + *((_DWORD *)v31 + 2) - 12) = *(_DWORD *)(v67 + v68[2]);
        *(_DWORD *)(v33 + *((_DWORD *)v31 + 2)) = *(_DWORD *)(v34 + v68[2]);
        v35 = *((_DWORD *)this + 5);
        v36 = *((_DWORD *)v31 + 2);
        v37 = *(D3DXShader::CArgument **)(v35 + 4 * *(_DWORD *)(v36 + v33 - 12));
        v38 = *(_DWORD *)(v35 + 4 * *(_DWORD *)(v33 + v36));
        v54 = *((_DWORD *)this + 32);
        v72 = v37;
        v63 = v38;
        v39 = D3DXShader::CBaseProgram::AddArgument(this, a2: v54, a3: 0, a4: 0, a5: 0.0);
        v65 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v39);
        *(_DWORD *)(v33 + *((_DWORD *)v31 + 2)) = v39;
        D3DXShader::CArgument::Initialize(
          this: v72,
          a2: *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v33 + v71[2] - 12)));
        v63 = *(_DWORD *)(v63 + 60);
        D3DXShader::CArgument::Initialize(
          this: v65,
          a2: *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5)
                                           + 4
                                           * *(_DWORD *)(*((_DWORD *)v62[0] + 2) + 4 * (*(_DWORD *)v62[0] & 0xFFFFF))));
        v40 = v65;
        *((_DWORD *)v65 + 4) = v70;
        *((_DWORD *)v40 + 15) = v63;
        if ( *(_DWORD *)*v69 == 1926234115 && i == a5 - 1 )
          *(_DWORD *)(v33 + *((_DWORD *)v31 + 2) + 12) = *(_DWORD *)(v33 + *((_DWORD *)*v69 + 2) + 12);
        v70 = (struct D3DXShader::CInstruction *)((char *)v70 + 1);
        v67 += 4;
        v66 += 4;
        v33 += 4;
      }
      while ( v33 < 0x18 );
    }
    v41 = v60[a5 + 11];
    v42 = v69;
    for ( j = 0; j < 0x10; j += 4 )
      *(_DWORD *)(j + *(_DWORD *)(v41 + 16)) = *(_DWORD *)(j + *((_DWORD *)*v42 + 4));
    v44 = 0;
    if ( a5 != 0 )
    {
      while ( a4[(_DWORD)v62[v44 + 1]] == nullptr )
      {
        if ( ++v44 >= a5 )
          goto LABEL_73;
      }
      goto LABEL_90;
    }
LABEL_73:
    v45 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)*v42 + 2));
    v46 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v45 + 4));
    v47 = *(_DWORD *)(v46 + 4);
    if ( (v47 & 0x80u) == 0 )
    {
      D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x12CCu, format: "internal error: unexpected argument type");
      goto LABEL_90;
    }
    v16 = (v47 & 0x840) == 0;
    v48 = v62[a5];
    if ( v16 )
    {
      *(_DWORD *)(v45 + 12) = v48;
    }
    else if ( v48 != *(struct D3DXShader::CInstruction **)(v45 + 12) )
    {
      if ( (*(_BYTE *)(v46 + 5) & 8) != 0 )
        v56 = "cannot bind sampler to user specified stage, sampler must be bound to %i";
      else
        v56 = "cannot bind sampler to sampler array, sampler must be bound to %i";
      D3DXShader::CProgram::Error(
        this,
        a2: *((struct D3DXShader::CNode **)a2[v64] + 15),
        a3: 0x11A3u,
        format: v56,
        v62[a5]);
      goto LABEL_90;
    }
    i = 0;
    if ( a5 != 0 )
    {
      while ( 1 )
      {
        v49 = &v61[i];
        v50 = *v49;
        a4[(_DWORD)v62[i + 1]] = *v49;
        v30 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v50);
        if ( v30 < 0 )
          goto LABEL_84;
        *v69 = nullptr;
        *v49 = nullptr;
        if ( ++i >= a5 )
          goto LABEL_82;
      }
    }
    goto LABEL_82;
  }
  while ( 1 )
  {
    v11 = *((_DWORD *)this + 19);
    v12 = v11 < *((_DWORD *)this + 137);
    v67 = v11;
    if ( v12 )
      break;
LABEL_37:
    if ( i != 0 )
    {
      v20 = v62[i];
      if ( (unsigned int)v20 <= v60[0] || v62[i + 1] != (struct D3DXShader::CInstruction *)((char *)v20 + 1) )
      {
        D3DXShader::CProgram::Error(
          this,
          a2: nullptr,
          a3: 0x11ADu,
          format: "unable to match texm* because source inputs are not in appropriate texture coordinates. See ps_1_% assembly re"
          "ference for more information",
          (unsigned __int8)*((_DWORD *)this + 50));
        goto LABEL_90;
      }
    }
    v21 = *((_DWORD *)this + 5);
    v22 = i;
    v23 = *(_DWORD *)(v60[i + 9] + 8);
    if ( *(_DWORD *)(*(_DWORD *)(v21 + 4 * *(_DWORD *)(v23 + 4 * v60[i + 3])) + 60) != 0 )
    {
      v58 = "cannot match to texm* because texm* cannot have source modifiers on input texcoord";
      v57 = 4526;
LABEL_94:
      D3DXShader::CProgram::Error(this, a2: nullptr, a3: v57, format: v58);
      goto LABEL_90;
    }
    v24 = *(_DWORD *)(*(_DWORD *)(v21 + 4 * *(_DWORD *)(v23 + 4 * v60[i + 6])) + 60);
    if ( v24 != 0 && v24 != 393216 )
    {
      v58 = "cannot match to texm* because texm* can only have bx2 modifier on input texload";
      v57 = 4527;
      goto LABEL_94;
    }
    v25 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v25 != nullptr )
      v26 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v25);
    else
      v26 = nullptr;
    v61[v22] = v26;
    if ( v26 == nullptr )
    {
      v30 = -2147024882;
      goto LABEL_84;
    }
    if ( i != a5 - 1 )
    {
      v55 = 0;
      v29 = a5 != 3 ? 1914699779 : 1916796931;
      goto LABEL_58;
    }
    v27 = *(_DWORD *)*v69;
    if ( v27 == 1926234115 )
    {
      if ( a5 != 3 )
        goto LABEL_96;
      v28 = D3DXShader::CInstruction::Initialize(this: v26, a2: 0x72A00003u, a3: 9u, a4: 4u, a5: 0);
      goto LABEL_59;
    }
    if ( v27 == 1925185539 )
    {
      if ( a5 != 3 )
      {
LABEL_96:
        v30 = 1;
        goto LABEL_84;
      }
      v28 = D3DXShader::CInstruction::Initialize(this: v26, a2: 0x72900003u, a3: 6u, a4: 4u, a5: 0);
      goto LABEL_59;
    }
    v55 = 4;
    if ( a5 != 1 )
    {
      v29 = a5 != 3 ? 1915748355 : 1917845507;
LABEL_58:
      v28 = D3DXShader::CInstruction::Initialize(this: v26, a2: v29, a3: 6u, a4: v55, a5: 0);
      goto LABEL_59;
    }
    v28 = D3DXShader::CInstruction::Initialize(this: v26, a2: 0x72B00003u, a3: 6u, a4: 4u, a5: 0);
LABEL_59:
    v30 = v28;
    if ( v28 < 0 )
      goto LABEL_84;
    if ( ++i >= a5 )
      goto LABEL_61;
  }
  v70 = (struct D3DXShader::CInstruction *)(*((_DWORD *)this + 140) + 4 * v11);
  while ( 1 )
  {
    v13 = *(unsigned int **)v70;
    v71 = *(unsigned int **)v70;
    if ( v71 != nullptr )
    {
      v14 = *v69;
      if ( *v69 == nullptr || *v13 == 0 )
        goto LABEL_36;
      v15 = (D3DXShader::CArgument *)(*(_DWORD *)v14 & 0xFFFFF);
      v16 = *(_DWORD *)v14 == 1926234115;
      v66 = *((_DWORD *)v14 + 1);
      if ( v16 )
        v66 = 6;
      v72 = v15;
      if ( (unsigned int)v15 < v66 )
        break;
LABEL_35:
      v11 = v67;
    }
LABEL_36:
    v70 = (struct D3DXShader::CInstruction *)((char *)v70 + 4);
    v12 = ++v11 < *((_DWORD *)this + 137);
    v67 = v11;
    if ( !v12 )
      goto LABEL_37;
  }
  v68 = (unsigned int *)v13[1];
  while ( 1 )
  {
    v65 = nullptr;
    if ( v68 != nullptr )
      break;
LABEL_34:
    v72 = (D3DXShader::CArgument *)((char *)v72 + 1);
    if ( (unsigned int)v72 >= v66 )
      goto LABEL_35;
  }
  v17 = *(_DWORD *)(*((_DWORD *)v14 + 2) + 4 * (_DWORD)v72);
  v18 = (_DWORD *)v13[2];
  while ( *v18 != v17 )
  {
    v13 = v71;
    if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v18) + 56) == v17 )
      break;
    v19 = v71[1];
    v65 = (D3DXShader::CArgument *)((char *)v65 + 1);
    ++v18;
    v12 = (unsigned int)v65 < v19;
    v68 = (unsigned int *)v19;
    v13 = v71;
    if ( !v12 )
      goto LABEL_34;
  }
  D3DXShader::CProgram::Error(
    this,
    a2: (struct D3DXShader::CNode *)v13[15],
    a3: 0x11ACu,
    format: "unable to match texm because computed texcoord is used in shader");
LABEL_90:
  v30 = -2147467259;
LABEL_84:
  for ( k = 0; k < 3; ++k )
  {
    v52 = v61[k];
    if ( v52 != nullptr )
      D3DXShader::CInstruction::`scalar deleting destructor'(this: v52, a2: 1);
  }
  return v30;
}

//------------------------------------------------------------------------------
// Address: 0x1020A127
// Name: protected: virtual long D3DXShader::CPSLegacyProgram::ValidateOutput(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CPSLegacyProgram::ValidateOutput(D3DXShader::CPSLegacyProgram *this)
{
  int v2; // esi
  int v3; // edx
  bool v4; // zf
  int v5; // esi
  int v6; // edi
  int v7; // eax
  unsigned int v8; // eax
  char *v9; // eax
  int v10; // esi
  unsigned int i; // eax
  struct D3DXShader::CNode *v13[4]; // [esp+Ch] [ebp-20h] BYREF
  struct D3DXShader::CNode *v14; // [esp+1Ch] [ebp-10h]
  int v15; // [esp+20h] [ebp-Ch]
  int v16; // [esp+24h] [ebp-8h]
  int v17; // [esp+28h] [ebp-4h]

  memset(v13, 0, sizeof(v13));
  *((_DWORD *)this + 134) = 0;
  *((_DWORD *)this + 135) = 0;
  v2 = 0;
  v3 = 0;
  memset((char *)this + 504, 0, 0x20u);
  v4 = *((_DWORD *)this + 2) == 0;
  v16 = 0;
  v15 = 0;
  v14 = nullptr;
  v17 = 0;
  if ( !v4 )
  {
    while ( 1 )
    {
      v5 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v17);
      v6 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v5 + 4));
      if ( *(_DWORD *)(v5 + 8) != -1 && v16 == 0 )
      {
        D3DXShader::CProgram::Error(
          this,
          a2: *(struct D3DXShader::CNode **)(v5 + 96),
          a3: 0x119Fu,
          format: "relative addressing not supported in ps_1_x");
        v16 = 1;
        v3 = 1;
      }
      v7 = *(_DWORD *)(v6 + 4);
      if ( (v7 & 0x20) != 0 )
      {
        if ( *(unsigned __int8 *)(v5 + 109) > 3u )
          goto LABEL_26;
        if ( (unsigned __int8)*(_DWORD *)(v5 + 108) == 1 )
        {
          if ( *(_BYTE *)(v5 + 109) == 0 )
          {
            v13[*(_DWORD *)(v5 + 16)] = (struct D3DXShader::CNode *)1;
            v14 = *(struct D3DXShader::CNode **)(v5 + 96);
          }
        }
        else if ( (unsigned __int8)*(_DWORD *)(v5 + 108) == 2
               && *(_BYTE *)(v5 + 109) == 0
               && *(_DWORD *)(v5 + 16) != 0
               && v15 == 0 )
        {
          D3DXShader::CProgram::Error(
            this,
            a2: *(struct D3DXShader::CNode **)(v5 + 96),
            a3: 0x11B0u,
            format: "DEPTH must be a scalar");
          v15 = 1;
          v3 = 1;
        }
        goto LABEL_25;
      }
      if ( (v7 & 0x10) != 0 && (v7 & 0x200) == 0 )
      {
        v8 = *(unsigned __int8 *)(v5 + 109);
        if ( (unsigned __int8)*(_DWORD *)(v5 + 108) == 1 )
        {
          if ( v8 < 2 )
          {
            v9 = (char *)this + 4 * v8 + 536;
LABEL_23:
            v10 = *(_DWORD *)(v5 + 16);
            if ( *(_DWORD *)v9 < (unsigned int)(v10 + 1) )
              *(_DWORD *)v9 = v10 + 1;
          }
        }
        else if ( (unsigned __int8)*(_DWORD *)(v5 + 108) == 3 && v8 < 8 )
        {
          v9 = (char *)this + 4 * v8 + 504;
          goto LABEL_23;
        }
      }
LABEL_25:
      if ( (unsigned int)++v17 >= *((_DWORD *)this + 2) )
      {
LABEL_26:
        v2 = 0;
        break;
      }
    }
  }
  for ( i = 0; i < 4; ++i )
    v2 += v13[i] != nullptr;
  if ( v2 != 4 )
  {
    D3DXShader::CProgram::Error(
      this,
      a2: v14,
      a3: 0x11B2u,
      format: "pixel shader must minimally write all four components of COLOR0");
    v3 = 1;
  }
  return v3 != 0 ? 0x80004005 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020A2AE
// Name: protected: long D3DXShader::CPSLegacyProgram::EmitDP4(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EmitDP4(D3DXShader::CPSLegacyProgram *this)
{
  _DWORD *v2; // ecx
  unsigned int *v3; // edi
  unsigned int i; // eax
  int v5; // eax
  int result; // eax
  unsigned int j; // eax
  unsigned int v8; // eax
  int v9; // ecx
  _DWORD *v10; // eax
  unsigned int v11[4]; // [esp+14h] [ebp-44h] BYREF
  unsigned int v12[4]; // [esp+24h] [ebp-34h] BYREF
  unsigned int v13[4]; // [esp+34h] [ebp-24h] BYREF
  unsigned int *v14; // [esp+44h] [ebp-14h]
  char *v15; // [esp+48h] [ebp-10h]
  unsigned int v16; // [esp+4Ch] [ebp-Ch]
  unsigned int *v17; // [esp+50h] [ebp-8h]
  unsigned int v18; // [esp+54h] [ebp-4h]

  v2 = *((_DWORD **)this + 64);
  v3 = (unsigned int *)v2[4];
  v18 = v2[3];
  v14 = v3;
  for ( i = 0; i < 4; ++i )
  {
    v11[i] = *(_DWORD *)(v2[2] + 12);
    v12[i] = *(_DWORD *)(v2[2] + 28);
  }
  v5 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v3);
  if ( *(_DWORD *)(v5 + 4) == *((_DWORD *)this + 33) )
  {
    if ( *(_DWORD *)(v5 + 108) != 1 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x12CDu,
        format: "internal error: unexpected output register");
      return -2147467259;
    }
    for ( j = v18; j != 0; *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v3) + 4) = *((_DWORD *)this + 34) )
    {
      --j;
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v3) + 12) = 0;
    }
  }
  if ( v18 != 0 )
  {
    v17 = v3;
    v15 = (char *)((char *)v13 - (char *)v3);
    v16 = v18;
    while ( 1 )
    {
      v8 = D3DXShader::CBaseProgram::AddArgument(this, a2: 0, a3: 0, a4: 0, a5: 0.0);
      ++v17;
      *(unsigned int *)((char *)v3 + (_DWORD)v15) = v8;
      v9 = *((_DWORD *)this + 5);
      v10 = *(_DWORD **)(v9 + 4 * v8);
      qmemcpy(v10, *(const void **)(v9 + 4 * *v3), 0x80u);
      v10[15] = 0;
      if ( --v16 == 0 )
        break;
      v3 = v17;
    }
    v3 = v14;
  }
  result = D3DXShader::CShaderProgram::EmitInstComplex(
             this,
             a2: 8u,
             a3: v13,
             a4: v18,
             a5: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
             a6: (unsigned int *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 16),
             a7: nullptr,
             a8: 2u,
             a9: 0,
             a10: 0,
             a11: 0,
             a12: 0);
  if ( result >= 0 )
    return D3DXShader::CShaderProgram::EmitInstComplex(
             this,
             a2: 4u,
             a3: v3,
             a4: v18,
             a5: v11,
             a6: v12,
             a7: v13,
             a8: v18,
             a9: 0,
             a10: 0,
             a11: 0,
             a12: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A3FB
// Name: protected: long D3DXShader::CPSLegacyProgram::EmitSpecialTex(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EmitSpecialTex(D3DXShader::CPSLegacyProgram *this, unsigned int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  int v5; // ebx
  _DWORD *v6; // edi
  int result; // eax
  int v8; // edx
  _DWORD *v9; // [esp+Ch] [ebp-10h]
  _DWORD *v10; // [esp+10h] [ebp-Ch]
  int v11; // [esp+14h] [ebp-8h] BYREF
  unsigned int v12; // [esp+18h] [ebp-4h] BYREF

  v3 = *((_DWORD **)this + 64);
  v4 = (_DWORD *)v3[2];
  v5 = *v3 & 0xFFFFF;
  v6 = v5 != v3[1] ? &v4[v5] : nullptr;
  v10 = v4;
  v9 = (unsigned int)(2 * v5) < v3[1] ? &v4[2 * v5] : nullptr;
  result = D3DXShader::CShaderProgram::EmitInst(this, a2);
  if ( result >= 0 )
  {
    v8 = *(_DWORD *)this;
    a2 = *(unsigned __int8 *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v10) + 109);
    v12 = a2 | 0xB0000000;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, unsigned int, int, _DWORD))(v8 + 100))(
               a1: this,
               a2: a2 | 0xB0000000,
               a3: 983040,
               a4: 0);
    if ( result >= 0
      && (v6 == nullptr
       || (result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD, unsigned int *, unsigned int *))(*(_DWORD *)this + 116))(
                      a1: this,
                      a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v6),
                      a3: &v12,
                      a4: &a2)) >= 0
       && (result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD *, int, int, int *))(*(_DWORD *)this + 120))(
                      a1: this,
                      a2: v6,
                      a3: v5,
                      a4: 983040,
                      a5: &v11)) >= 0
       && (result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, unsigned int, int, unsigned int))(*(_DWORD *)this + 104))(
                      a1: this,
                      a2: v12,
                      a3: v11,
                      a4: a2)) >= 0)
      && (v9 == nullptr
       || (result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD, unsigned int *, unsigned int *))(*(_DWORD *)this + 116))(
                      a1: this,
                      a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v9),
                      a3: &v12,
                      a4: &a2)) >= 0
       && (result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD *, int, int, int *))(*(_DWORD *)this + 120))(
                      a1: this,
                      a2: v9,
                      a3: v5,
                      a4: 983040,
                      a5: &v11)) >= 0
       && (result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, unsigned int, int, unsigned int))(*(_DWORD *)this + 104))(
                      a1: this,
                      a2: v12,
                      a3: v11,
                      a4: a2)) >= 0) )
    {
      result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *))(*(_DWORD *)this + 96))(a1: this);
      if ( result >= 0 )
      {
        result = D3DXShader::CShaderProgram::ValidateInst(this);
        if ( result >= 0 )
          return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A540
// Name: protected: long D3DXShader::CPSLegacyProgram::EmitTEXLDPR(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EmitTEXLDPR(D3DXShader::CPSLegacyProgram *this)
{
  int v2; // edi
  int result; // eax
  _DWORD *v4; // ebx
  int v5; // [esp+Ch] [ebp-Ch] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  int v7; // [esp+14h] [ebp-4h] BYREF

  v2 = **((_DWORD **)this + 64) & 0xFFFFF;
  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x42u);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD, int *, _DWORD, _DWORD))(*(_DWORD *)this + 108))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)),
               a3: &v7,
               a4: 0,
               a5: 0);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, int, _DWORD))(*(_DWORD *)this + 100))(
                 a1: this,
                 a2: v7,
                 a3: 983040,
                 a4: 0);
      if ( result >= 0 )
      {
        v4 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4 * v2);
        result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                   a1: this,
                   a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v4),
                   a3: &v7,
                   a4: &v6);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD *, int, int, int *))(*(_DWORD *)this + 120))(
                     a1: this,
                     a2: v4,
                     a3: v2,
                     a4: 983040,
                     a5: &v5);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, int, int))(*(_DWORD *)this + 104))(
                       a1: this,
                       a2: v7,
                       a3: v5 | 0x9000000,
                       a4: v6);
            if ( result >= 0 )
            {
              result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *))(*(_DWORD *)this + 96))(a1: this);
              if ( result >= 0 )
              {
                result = D3DXShader::CShaderProgram::ValidateInst(this);
                if ( result >= 0 )
                  return 0;
              }
            }
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A61B
// Name: protected: long D3DXShader::CPSLegacyProgram::EmitTEXLDPT(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EmitTEXLDPT(D3DXShader::CPSLegacyProgram *this)
{
  int v2; // edi
  int result; // eax
  _DWORD *v4; // ebx
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  int v7; // [esp+14h] [ebp-4h] BYREF

  v2 = **((_DWORD **)this + 64) & 0xFFFFF;
  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x42u);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD, int *, _DWORD, _DWORD))(*(_DWORD *)this + 108))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)),
               a3: &v7,
               a4: 0,
               a5: 0);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, int, _DWORD))(*(_DWORD *)this + 100))(
                 a1: this,
                 a2: v7,
                 a3: 983040,
                 a4: 0);
      if ( result >= 0 )
      {
        v4 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4 * v2);
        result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                   a1: this,
                   a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v4),
                   a3: &v7,
                   a4: &v6);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD *, int, int, _BYTE *))(*(_DWORD *)this + 120))(
                     a1: this,
                     a2: v4,
                     a3: v2,
                     a4: 983040,
                     a5: v5);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, int, int))(*(_DWORD *)this + 104))(
                       a1: this,
                       a2: v7,
                       a3: 183762944,
                       a4: v6);
            if ( result >= 0 )
            {
              result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *))(*(_DWORD *)this + 96))(a1: this);
              if ( result >= 0 )
              {
                result = D3DXShader::CShaderProgram::ValidateInst(this);
                if ( result >= 0 )
                  return 0;
              }
            }
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A6ED
// Name: protected: long D3DXShader::CPSLegacyProgram::EmitTEXLDD(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EmitTEXLDD(D3DXShader::CPSLegacyProgram *this)
{
  int v2; // edi
  int v3; // eax
  int result; // eax
  _DWORD *v5; // edi
  int v6; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-Ch] BYREF
  int v8; // [esp+14h] [ebp-8h]
  int v9; // [esp+18h] [ebp-4h] BYREF

  v2 = **((_DWORD **)this + 64) & 0xFFFFF;
  v3 = (unsigned __int16)*((_DWORD *)this + 50);
  v8 = v2;
  if ( v3 == 260 )
  {
    result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x42u);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD, int *, _DWORD, _DWORD))(*(_DWORD *)this + 108))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)),
               a3: &v9,
               a4: 0,
               a5: 0);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, int, _DWORD))(*(_DWORD *)this + 100))(
               a1: this,
               a2: v9,
               a3: 983040,
               a4: 0);
    if ( result < 0 )
      return result;
    v5 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4 * v2);
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v5),
               a3: &v9,
               a4: &v7);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD *, int, int, int *))(*(_DWORD *)this + 120))(
               a1: this,
               a2: v5,
               a3: v8,
               a4: 983040,
               a5: &v6);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, int, int))(*(_DWORD *)this + 104))(
               a1: this,
               a2: v9,
               a3: v6,
               a4: v7);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *))(*(_DWORD *)this + 96))(a1: this);
    if ( result < 0 )
      return result;
    result = D3DXShader::CShaderProgram::ValidateInst(this);
    if ( result < 0 )
      return result;
    return 0;
  }
  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x42u);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD, int *, _DWORD, _DWORD))(*(_DWORD *)this + 108))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)),
               a3: &v9,
               a4: 0,
               a5: 0);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, int, _DWORD))(*(_DWORD *)this + 100))(
                 a1: this,
                 a2: v9,
                 a3: 983040,
                 a4: 0);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *))(*(_DWORD *)this + 96))(a1: this);
        if ( result >= 0 )
        {
          result = D3DXShader::CShaderProgram::ValidateInst(this);
          if ( result >= 0 )
            return 0;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A83E
// Name: protected: long D3DXShader::CPSLegacyProgram::EmitTEXCRD(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EmitTEXCRD(D3DXShader::CPSLegacyProgram *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  int result; // eax
  _DWORD *v6; // edi
  _BYTE v7[4]; // [esp+Ch] [ebp-14h] BYREF
  int v8; // [esp+10h] [ebp-10h] BYREF
  int v9; // [esp+14h] [ebp-Ch] BYREF
  int v10; // [esp+18h] [ebp-8h] BYREF
  int v11; // [esp+1Ch] [ebp-4h] BYREF

  v2 = *((_DWORD *)this + 64);
  v3 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v2 + 16));
  v4 = *(_DWORD *)v2 & 0xFFFFF;
  if ( (unsigned __int16)*((_DWORD *)this + 50) == 260 )
  {
    result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x40u);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, int *, _DWORD, int *))(*(_DWORD *)this + 108))(
               a1: this,
               a2: v3,
               a3: &v11,
               a4: 0,
               a5: &v10);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD, int, int *, int))(*(_DWORD *)this + 112))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 64) + 16),
               a3: v4,
               a4: &v9,
               a5: v10);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, int, _DWORD))(*(_DWORD *)this + 100))(
               a1: this,
               a2: v11,
               a3: 458752,
               a4: 0);
    if ( result < 0 )
      return result;
    v6 = *(_DWORD **)(*((_DWORD *)this + 64) + 8);
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v6),
               a3: &v11,
               a4: &v8);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD *, int, int, _BYTE *))(*(_DWORD *)this + 120))(
               a1: this,
               a2: v6,
               a3: v4,
               a4: v9,
               a5: v7);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, int, int))(*(_DWORD *)this + 104))(
               a1: this,
               a2: v11,
               a3: 14942208,
               a4: v8);
  }
  else
  {
    result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x40u);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, int *, _DWORD, int *))(*(_DWORD *)this + 108))(
               a1: this,
               a2: v3,
               a3: &v11,
               a4: 0,
               a5: &v10);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, _DWORD, int, int *, int))(*(_DWORD *)this + 112))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 64) + 16),
               a3: v4,
               a4: &v9,
               a5: v10);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, int, _DWORD))(*(_DWORD *)this + 100))(
               a1: this,
               a2: v11,
               a3: 983040,
               a4: 0);
  }
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *))(*(_DWORD *)this + 96))(a1: this);
    if ( result >= 0 )
    {
      result = D3DXShader::CShaderProgram::ValidateInst(this);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A98F
// Name: protected: virtual unsigned long D3DXShader::CPSLegacyProgram::CoIssue(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CPSLegacyProgram::CoIssue(D3DXShader::CPSLegacyProgram *this, unsigned int a2)
{
  unsigned int result; // eax

  result = a2;
  if ( *(_DWORD *)(*((_DWORD *)this + 64) + 36) == 1 )
    return a2 | 0x40000000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A9AC
// Name: protected: virtual long D3DXShader::CPSLegacyProgram::EmitVersion(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EmitVersion(D3DXShader::CPSLegacyProgram *this)
{
  int result; // eax

  result = D3DXShader::CShaderProgram::Emit(this, a2: *((_DWORD *)this + 50));
  if ( result >= 0 )
  {
    result = D3DXShader::CShaderProgram::ValidateInst(this);
    if ( result >= 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A9CF
// Name: protected: virtual long D3DXShader::CPSLegacyProgram::EmitDCL(class D3DXShader::CArgument __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EmitDCL(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3)
{
  unsigned int v3; // edx
  int v4; // eax

  v3 = *((unsigned __int8 *)a2 + 109);
  v4 = (unsigned __int8)*((_DWORD *)a2 + 27);
  switch ( v4 )
  {
    case 1:
      if ( v3 < *((_DWORD *)this + 10) )
      {
LABEL_3:
        *a3 = v3;
        return 0;
      }
      break;
    case 3:
      if ( v3 < *((_DWORD *)this + 15) )
      {
        v3 += 2;
        goto LABEL_3;
      }
      break;
    case 5:
      *a3 = 12;
      return 0;
    default:
      break;
  }
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x1020AA1E
// Name: protected: virtual long D3DXShader::CPSLegacyProgram::FindInput(class D3DXShader::CArgument __near *,unsigned long __near &,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::FindInput(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3,
        unsigned int *a4)
{
  int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  bool v7; // cf

  v4 = *((_DWORD *)a2 + 27);
  v5 = *((unsigned __int8 *)a2 + 109);
  *a3 = v5;
  v6 = 1;
  if ( (unsigned __int8)v4 == 1 )
  {
    v7 = v5 < *((_DWORD *)this + 10);
  }
  else
  {
    v6 = 3;
    if ( (unsigned __int8)v4 != 3 )
      return -2147467259;
    v7 = v5 < *((_DWORD *)this + 15);
  }
  if ( v7 )
  {
    *a4 = v6;
    return 0;
  }
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x1020AA63
// Name: public: virtual long D3DXShader::CPSLegacyProgram::IndexSemantic(class D3DXShader::CArgument __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CPSLegacyProgram::IndexSemantic(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CArgument *a2,
        int a3)
{
  int v3; // esi
  const char *v4; // ebx
  char v5; // al
  int v6; // edx
  int v7; // esi
  int v8; // eax
  unsigned int v9; // eax
  bool v10; // cf
  D3DXShader::CPSLegacyProgram *v11; // edx
  unsigned int *v12; // ebx
  unsigned int v13; // ebx
  int v15; // [esp-4h] [ebp-4Ch]
  int v16; // [esp-4h] [ebp-4Ch]
  int v17; // [esp+Ch] [ebp-3Ch]
  const char *ArgumentType; // [esp+10h] [ebp-38h]
  unsigned __int8 *v19; // [esp+14h] [ebp-34h]
  int v21; // [esp+1Ch] [ebp-2Ch]
  int v22; // [esp+20h] [ebp-28h]
  unsigned int v23; // [esp+20h] [ebp-28h]
  unsigned __int8 dest[32]; // [esp+24h] [ebp-24h] BYREF

  v19 = *(unsigned __int8 **)(*((_DWORD *)a2 + 26) + 24);
  v3 = 0;
  v17 = 0;
  LOBYTE(v21) = 0;
  strncpy(dest, source: v19, count: 0x1Fu);
  dest[31] = 0;
  v4 = (const char *)dest;
  if ( dest[0] == 0 )
    goto LABEL_6;
  do
  {
    if ( isalpha(c: *v4) == 0 )
      break;
    ++v4;
  }
  while ( *v4 != 0 );
  if ( *v4 != 0 )
    v22 = atoi(nptr: v4);
  else
LABEL_6:
    v22 = 0;
  if ( *v4 != 0 )
    *v4++ = 0;
  v5 = *v4;
  if ( *v4 == 0 )
    goto LABEL_14;
  do
  {
    if ( isdigit(c: v5) == 0 )
      break;
    v5 = *++v4;
  }
  while ( *v4 != 0 );
  if ( *v4 != 0 )
    v23 = -1;
  else
LABEL_14:
    v23 = (*((_DWORD *)a2 + 28) >> 2) + v22;
  if ( *((_DWORD *)a2 + 27) == -1 )
  {
    v7 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)a2 + 1));
    ArgumentType = D3DXShader::CBaseProgram::GetArgumentType(this, a2);
    v8 = *(_DWORD *)(v7 + 4);
    if ( (v8 & 0x10) != 0 && (v8 & 0x200) == 0 )
    {
      if ( _stricmp(dst: (const char *)dest, src: "color") == 0 )
      {
        v21 = 1;
        if ( a3 == 0 )
        {
          v9 = *((_DWORD *)this + 10);
LABEL_26:
          v10 = v23 < v9;
          goto LABEL_36;
        }
        v15 = 2;
      }
      else
      {
        if ( _stricmp(dst: (const char *)dest, src: "texcoord") != 0 )
        {
          if ( _stricmp(dst: (const char *)dest, src: "position") != 0
            && _stricmp(dst: (const char *)dest, src: "fog") != 0
            && _stricmp(dst: (const char *)dest, src: "psize") != 0 )
          {
            if ( _stricmp(dst: (const char *)dest, src: "diffuse") == 0 )
            {
              v21 = 1;
              v3 = v23 != 0;
              v17 = 1;
              if ( v23 == 0 )
                v23 = 0;
            }
            else if ( _stricmp(dst: (const char *)dest, src: "specular") == 0 )
            {
              v21 = 1;
              v3 = v23 != 0;
              v17 = 1;
              if ( v23 == 0 )
                v23 = 1;
            }
            else
            {
              v21 = 0;
              v3 = 1;
            }
            goto LABEL_44;
          }
          v10 = v23 == 0;
          v21 = 4;
LABEL_36:
          v3 = 1 - v10;
LABEL_44:
          if ( a3 == 0 || *((_DWORD *)a2 + 4) == 0 )
          {
            if ( v3 != 0 )
            {
              D3DXShader::CProgram::Error(
                this,
                a2: *((struct D3DXShader::CNode **)a2 + 26),
                a3: 0x1196u,
                format: "invalid %s semantic '%s'",
                ArgumentType,
                (const char *)v19);
            }
            else if ( v17 != 0 )
            {
              D3DXShader::CProgram::Warning(
                this,
                a2: *((struct D3DXShader::CNode **)a2 + 26),
                a3: 0x1261u,
                format: "%s semantic '%s' has been deprecated; use '%s%d' instead",
                ArgumentType,
                (const char *)v19,
                *((const char **)&off_10336698 + v21),
                v23);
            }
          }
          if ( (v21 == 4 || v3 != 0) && *((_DWORD *)this + 274) == 0 && a3 == 0 )
          {
            *((_DWORD *)this + 274) = 1;
            D3DXShader::CProgram::Error(
              this,
              a2: *((struct D3DXShader::CNode **)a2 + 26),
              a3: 0x1196u,
              format: "invalid reference to %s semantic '%s'",
              ArgumentType,
              (const char *)v19);
            v3 = 1;
          }
          goto LABEL_68;
        }
        v21 = 3;
        if ( a3 == 0 )
        {
          v9 = *((_DWORD *)this + 15);
          goto LABEL_26;
        }
        v15 = 8;
      }
      v9 = v15;
      goto LABEL_26;
    }
    if ( (v8 & 0x20) == 0 )
    {
LABEL_86:
      v3 = 1;
      goto LABEL_87;
    }
    if ( _stricmp(dst: (const char *)dest, src: "color") == 0 )
    {
      v21 = 1;
      v3 = v23 >= *((_DWORD *)this + 18);
    }
    else
    {
      if ( _stricmp(dst: (const char *)dest, src: "depth") == 0 )
      {
        v21 = 4;
        v3 = 1;
LABEL_62:
        if ( a3 == 0 || *((_DWORD *)a2 + 4) == 0 )
          D3DXShader::CProgram::Error(
            this,
            a2: *((struct D3DXShader::CNode **)a2 + 26),
            a3: 0x1196u,
            format: "invalid %s semantic '%s'",
            ArgumentType,
            (const char *)v19);
LABEL_65:
        if ( v21 == 4 )
        {
          if ( a3 != 0 )
            goto LABEL_87;
          D3DXShader::CProgram::Error(
            this,
            a2: *((struct D3DXShader::CNode **)a2 + 26),
            a3: 0x1196u,
            format: "%s semantic '%s' not yet implemented in ps_1_x",
            ArgumentType,
            v19);
        }
        goto LABEL_68;
      }
      v21 = 0;
      v3 = 1;
    }
    if ( v3 == 0 )
      goto LABEL_65;
    goto LABEL_62;
  }
  v6 = *((unsigned __int8 *)a2 + 109);
  v21 = (unsigned __int8)*((_DWORD *)a2 + 27);
  v23 = (unsigned __int8)v6;
  if ( v21 == 4 )
  {
    if ( *((_DWORD *)this + 274) != 0 || a3 != 0 )
      goto LABEL_87;
    v3 = 1;
    *((_DWORD *)this + 274) = 1;
    D3DXShader::CProgram::Error(
      this,
      a2: *((struct D3DXShader::CNode **)a2 + 26),
      a3: 0x1196u,
      format: "invalid reference to input semantic '%s%d'",
      dest,
      v6);
  }
LABEL_68:
  if ( v21 != 3 )
  {
LABEL_83:
    if ( v21 == 1 )
    {
      *(_WORD *)a2 |= 0x114u;
      *((double *)a2 + 4) = 0.0;
      *((double *)a2 + 5) = 1.0;
    }
    if ( v21 != 0 )
      goto LABEL_87;
    goto LABEL_86;
  }
  if ( v23 == 0 || v23 >= 4 || *((_DWORD *)a2 + 4) != 3 )
  {
    v11 = this;
LABEL_79:
    if ( v23 < *((_DWORD *)v11 + 15) || a3 != 0 || *((_DWORD *)v11 + 274) != 0 )
      goto LABEL_87;
    v16 = *((_DWORD *)v11 + 15);
    v3 = 1;
    *((_DWORD *)v11 + 274) = 1;
    D3DXShader::CProgram::Error(
      this: v11,
      a2: *((struct D3DXShader::CNode **)a2 + 26),
      a3: 0x1196u,
      format: "'texcoord' reference exceeds valid range for this shader model (max: %i)",
      v16);
    goto LABEL_83;
  }
  v11 = this;
  if ( (unsigned __int16)*((_DWORD *)this + 50) >= 0x104u )
    goto LABEL_79;
  v12 = (unsigned int *)((char *)this + 1084);
  if ( *((_DWORD *)this + 271) == -1 )
    *v12 = D3DXShader::CBaseProgram::AddPool(this, a2: "spec", a3: 0x51u, a4: 0xFFFFFFFF, a5: 4u);
  v13 = *v12;
  if ( v13 == -1 )
    return -2147024882;
  *((_DWORD *)a2 + 3) = 0;
  LOBYTE(v21) = 5;
  *((_DWORD *)a2 + 1) = v13;
  *((_DWORD *)a2 + 4) = v23 - 1;
LABEL_87:
  if ( v23 > 0xFFFF )
    v3 = 1;
  *((_DWORD *)a2 + 27) = (v23 << 8) | (unsigned __int8)v21;
  return v3 != 0 ? 0x80004005 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020AEE6
// Name: protected: virtual long D3DXShader::CPSLegacyProgram::FindOutput(class D3DXShader::CArgument __near *,unsigned long __near &,unsigned long __near &,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::FindOutput(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3,
        unsigned int *a4,
        int *a5)
{
  int v5; // eax
  unsigned int v6; // ecx

  v5 = *((_DWORD *)a2 + 27);
  v6 = *((unsigned __int8 *)a2 + 109);
  *a3 = v6;
  if ( (unsigned __int8)v5 == 1 )
  {
    if ( v6 == 0 )
    {
      *a4 = 0;
      if ( a5 != nullptr )
        *a5 = 0;
      return 0;
    }
  }
  else if ( (unsigned __int8)v5 == 2 && v6 == 0 )
  {
    *a4 = 9;
    if ( a5 != nullptr )
      *a5 = 1;
    return 0;
  }
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x1020AF44
// Name: protected: virtual int D3DXShader::CPSLegacyProgram::ViolatesPortConstraints(class D3DXShader::CInstruction __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::ViolatesPortConstraints(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction *a2,
        unsigned int *a3)
{
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  unsigned int v9; // ebx
  bool v10; // zf
  _DWORD *v11; // eax
  int v12; // edx
  unsigned int v13; // edi
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // esi
  unsigned int v17; // ebx
  unsigned int v18; // eax
  int v19; // eax
  int v20; // edx
  unsigned int v21; // esi
  _DWORD *v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // edx
  _DWORD *v25; // eax
  _DWORD v26[36]; // [esp+4h] [ebp-ACh] BYREF
  _DWORD *v27; // [esp+94h] [ebp-1Ch]
  unsigned int v28; // [esp+98h] [ebp-18h]
  int v29; // [esp+9Ch] [ebp-14h]
  _DWORD *v30; // [esp+A0h] [ebp-10h]
  struct D3DXShader::CInstruction *v31; // [esp+A4h] [ebp-Ch]
  int v32; // [esp+A8h] [ebp-8h]
  int v33; // [esp+ACh] [ebp-4h]
  struct D3DXShader::CInstruction *v34; // [esp+B8h] [ebp+8h]

  if ( a2 == nullptr )
    return 1;
  v4 = *(_DWORD *)a2;
  if ( (*(_DWORD *)a2 & 0xFFF00000) == 0 || (*(_DWORD *)a2 & 0xFFF00000) == 0x20700000 )
    return 0;
  v32 = v4 & 0xFFFFF;
  v28 = *((_DWORD *)a2 + 1) / (v4 & 0xFFFFFu);
  if ( v28 <= 1 )
    return 0;
  v5 = *((_DWORD *)this + 32);
  v6 = *((_DWORD *)this + 34);
  v7 = *((_DWORD *)this + 31);
  v8 = *((_DWORD *)this + 37);
  v33 = 0;
  v5 *= 4;
  *(_DWORD *)((char *)&v26[18] + v5) = 0;
  v6 *= 4;
  *(_DWORD *)((char *)&v26[18] + v6) = 0;
  v7 *= 4;
  v8 *= 4;
  *(_DWORD *)((char *)&v26[18] + v7) = 0;
  *(_DWORD *)((char *)&v26[18] + v8) = 0;
  *(_DWORD *)((char *)v26 + v5) = 2;
  *(_DWORD *)((char *)v26 + v6) = 3;
  *(_DWORD *)((char *)v26 + v7) = 2;
  v9 = 0;
  v10 = v28 == 0;
  *(_DWORD *)((char *)v26 + v8) = 1;
  v31 = nullptr;
  if ( v10 )
    return 0;
  v11 = *((_DWORD **)a2 + 2);
  v27 = v11;
  v29 = 4 * v32;
  v30 = v11;
  while ( 1 )
  {
    v12 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v11);
    v34 = nullptr;
    v13 = *(_DWORD *)(v12 + 4);
    if ( v9 != 0 )
    {
      v14 = v27;
      v32 = (int)v27;
      do
      {
        v15 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v14);
        if ( v13 == *(_DWORD *)(v15 + 4)
          && *(_DWORD *)(v12 + 8) == *(_DWORD *)(v15 + 8)
          && *(_DWORD *)(v12 + 12) == *(_DWORD *)(v15 + 12) )
        {
          v16 = *((_DWORD *)this + 4);
          if ( (*(_BYTE *)(*(_DWORD *)(v16 + 4 * v13) + 5) & 1) == 0
            || (*(_BYTE *)(*(_DWORD *)(v16 + 4 * *(_DWORD *)(v15 + 4)) + 5) & 1) == 0
            || *(double *)(v12 + 32) == *(double *)(v15 + 32) )
          {
            break;
          }
        }
        v34 = (struct D3DXShader::CInstruction *)((char *)v34 + 1);
        v14 = (_DWORD *)(v29 + v32);
        v32 += v29;
      }
      while ( v34 < v31 );
    }
    v17 = (unsigned int)v31;
    if ( v34 != v31 )
      goto LABEL_44;
    v18 = *((_DWORD *)this + 32);
    if ( v13 == v18 )
    {
      if ( *(_BYTE *)(v12 + 108) == 3 )
      {
        if ( (unsigned __int16)*((_DWORD *)this + 50) == 257 && (unsigned int)++v33 > 2 && a3 == nullptr )
          return 1;
        v18 = *((_DWORD *)this + 34);
      }
    }
    else
    {
      v19 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v13) + 4);
      if ( (v19 & 0x200) == 0 )
      {
        if ( (v19 & 0x80u) == 0 )
        {
          v18 = v13;
          goto LABEL_31;
        }
LABEL_29:
        v18 = *((_DWORD *)this + 37);
        goto LABEL_31;
      }
      if ( (v19 & 0x80u) != 0 )
        goto LABEL_29;
      v18 = *((_DWORD *)this + 31);
    }
LABEL_31:
    v20 = *(_DWORD *)(v12 + 72);
    if ( v20 != -1 )
    {
      v21 = *((_DWORD *)this + 34);
      if ( v13 == v21 && (unsigned __int16)*((_DWORD *)this + 50) == 257 )
      {
        v22 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v20);
        if ( v22 != nullptr )
        {
          v23 = *v22 & 0xFFF00000;
          if ( (v23 == 1626341376 || v23 == 1615855616 || v23 == 1621098496 || v23 == 1610612736)
            && (unsigned int)++v33 > 2
            && a3 == nullptr )
          {
            return 1;
          }
        }
        v18 = v21;
      }
    }
    if ( v18 < 0x12 )
    {
      v24 = v18;
      v25 = &v26[v18 + 18];
      if ( ++*v25 > v26[v24] )
        break;
    }
LABEL_44:
    v11 = &v30[v29 / 4u];
    v9 = v17 + 1;
    v31 = (struct D3DXShader::CInstruction *)v9;
    v30 = (_DWORD *)((char *)v30 + v29);
    if ( v9 >= v28 )
      return 0;
  }
  if ( a3 != nullptr )
    *a3 = v17;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1020B1A6
// Name: protected: long D3DXShader::CPSLegacyProgram::MarkCoIssues(class D3DXShader::CInstruction __near * __near *,unsigned int,unsigned int,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::MarkCoIssues(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5)
{
  unsigned int *v5; // edi
  unsigned int v6; // esi
  unsigned int i; // ecx
  struct D3DXShader::CInstruction *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ebx
  struct D3DXShader::CInstruction *v11; // edi
  struct D3DXShader::CInstruction *v12; // esi
  int v13; // eax
  struct D3DXShader::CInstruction *v14; // eax
  unsigned int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  _DWORD *v19; // eax
  int v21; // [esp+8h] [ebp-20h]
  int v22; // [esp+Ch] [ebp-1Ch]
  unsigned int v23; // [esp+10h] [ebp-18h]
  int v24; // [esp+14h] [ebp-14h]
  int v25; // [esp+14h] [ebp-14h]
  int v26; // [esp+18h] [ebp-10h]
  int v27; // [esp+1Ch] [ebp-Ch]
  int *v28; // [esp+20h] [ebp-8h]
  _DWORD *v30; // [esp+34h] [ebp+Ch]
  unsigned int j; // [esp+34h] [ebp+Ch]

  v5 = a5;
  if ( a5 != nullptr )
    *a5 = 0;
  v6 = a4;
  if ( a4 != 0 )
  {
    if ( a5 == nullptr )
    {
      for ( i = a3; i < a4; ++i )
      {
        v8 = a2[i];
        if ( v8 != nullptr )
          *((_DWORD *)v8 + 9) = 0;
      }
    }
    v9 = a4 - 1;
    v10 = a3;
    if ( a3 < a4 - 1 )
    {
      while ( 1 )
      {
        v11 = a2[v10];
        if ( v11 != nullptr )
          break;
LABEL_65:
        ++v10;
        v9 = v6 - 1;
        if ( v10 >= v6 - 1 )
        {
          v5 = a5;
          goto LABEL_67;
        }
      }
      v12 = nullptr;
      if ( a5 != nullptr )
        ++*a5;
      do
      {
        if ( v10 >= v9 )
          break;
        v12 = a2[++v10];
      }
      while ( v12 == nullptr );
      v22 = 0;
      v23 = --v10;
      if ( v12 != nullptr )
      {
        v21 = 0;
        if ( a5 == nullptr )
        {
          *((_DWORD *)v11 + 9) = 0;
          *((_DWORD *)v12 + 9) = 0;
        }
        v13 = *(_DWORD *)v11 & 0xFFFFF;
        if ( v13 == 1 && (*(_DWORD *)v12 & 0xFFFFFu) < 4 )
        {
          v14 = v11;
          v11 = v12;
          v12 = v14;
          v21 = 1;
LABEL_23:
          if ( (unsigned __int16)*((_DWORD *)this + 50) == 260
            || (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, struct D3DXShader::CInstruction *, struct D3DXShader::CInstruction *))(*(_DWORD *)this + 164))(
                 a1: this,
                 a2: v11,
                 a3: v12) == 0 )
          {
            v15 = *(_DWORD *)v11 & 0xFFF00000;
            if ( v15 != 1913651200
              && v15 != 1912602624
              && v15 != 1927282688
              && v15 != 1617952768
              && v15 != 1615855616
              && v15 != 1621098496
              && v15 != 1610612736
              && v15 != 1626341376
              && v15 != 285212672
              && v15 != 0 )
            {
              v27 = 0;
              if ( *((_DWORD *)v11 + 3) != 0 )
              {
                v16 = *((_DWORD *)this + 5);
                v28 = *((int **)v11 + 4);
                v24 = *((_DWORD *)v11 + 3);
                do
                {
                  v17 = *v28;
                  if ( *(_DWORD *)(*(_DWORD *)(v16 + 4 * *v28) + 16) == 3 )
                    v22 = 1;
                  if ( *((_DWORD *)v12 + 1) != 0 )
                  {
                    v30 = *((_DWORD **)v12 + 2);
                    v26 = *((_DWORD *)v12 + 1);
                    do
                    {
                      if ( *(_DWORD *)(*(_DWORD *)(v16 + 4 * *v30) + 56) == v17 || *v30 == v17 )
                        v27 = 1;
                      ++v30;
                      --v26;
                    }
                    while ( v26 != 0 );
                    v10 = v23;
                  }
                  ++v28;
                  --v24;
                }
                while ( v24 != 0 );
              }
              for ( j = 0; j < *((_DWORD *)v12 + 3); ++j )
              {
                if ( *((_DWORD *)v11 + 1) != 0 )
                {
                  v18 = *(_DWORD *)(*((_DWORD *)v12 + 4) + 4 * j);
                  v19 = *((_DWORD **)v11 + 2);
                  v25 = *((_DWORD *)v11 + 1);
                  do
                  {
                    if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v19) + 56) == v18 || *v19 == v18 )
                      v27 = 1;
                    ++v19;
                    --v25;
                  }
                  while ( v25 != 0 );
                  v10 = v23;
                }
              }
              if ( v27 == 0
                && v22 == 0
                && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v12 + 4)) + 16) == 3 )
              {
                if ( a5 == nullptr )
                {
                  if ( v21 != 0 )
                    *((_DWORD *)v11 + 9) = 1;
                  else
                    *((_DWORD *)v12 + 9) = 1;
                }
                ++v10;
              }
            }
          }
          goto LABEL_64;
        }
        if ( v13 != 4 && (*(_DWORD *)v12 & 0xFFFFF) == 1 )
          goto LABEL_23;
      }
LABEL_64:
      v6 = a4;
      goto LABEL_65;
    }
LABEL_67:
    if ( v10 != v6 && v5 != nullptr )
      ++*v5;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020B438
// Name: protected: virtual int D3DXShader::CPSLegacyProgram::ViolatesPortConstraintsCoIssue(class D3DXShader::CInstruction __near *,class D3DXShader::CInstruction __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::ViolatesPortConstraintsCoIssue(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction *a2,
        struct D3DXShader::CInstruction *a3)
{
  int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ebx
  unsigned int v11; // edx
  int v12; // eax
  int v13; // edi
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  unsigned int v17; // edx
  struct D3DXShader::CInstruction *v18; // edx
  int v19; // esi
  _DWORD *v20; // esi
  int v21; // esi
  int v22; // eax
  _DWORD *v23; // edi
  bool v24; // cc
  int v25; // eax
  int v26; // edi
  _DWORD v27[36]; // [esp+4h] [ebp-C8h] BYREF
  int v28; // [esp+94h] [ebp-38h]
  unsigned int v29; // [esp+98h] [ebp-34h]
  int v30; // [esp+9Ch] [ebp-30h]
  int v31; // [esp+A0h] [ebp-2Ch]
  int v32; // [esp+A4h] [ebp-28h]
  int v33; // [esp+A8h] [ebp-24h]
  int v34; // [esp+ACh] [ebp-20h]
  unsigned int v35; // [esp+B0h] [ebp-1Ch]
  int v36; // [esp+B4h] [ebp-18h]
  int v37; // [esp+B8h] [ebp-14h]
  unsigned int v38; // [esp+BCh] [ebp-10h]
  int v39; // [esp+C0h] [ebp-Ch]
  int v40; // [esp+C4h] [ebp-8h]
  unsigned int v41; // [esp+C8h] [ebp-4h]

  if ( a2 == nullptr )
    return 1;
  v4 = *(_DWORD *)a2;
  if ( (*(_DWORD *)a2 & 0xFFF00000) == 0 )
    return 0;
  v39 = v4 & 0xFFFFF;
  v5 = *((_DWORD *)a2 + 1) / (v4 & 0xFFFFFu);
  v41 = 0;
  v40 = 0;
  v36 = 0;
  v35 = v5;
  v6 = *(_DWORD *)a3 & 0xFFFFF;
  v7 = *((_DWORD *)a3 + 1) / v6;
  v8 = *((_DWORD *)this + 34);
  v9 = *((_DWORD *)this + 32);
  v27[v9 + 18] = 0;
  v8 *= 4;
  *(_DWORD *)((char *)&v27[18] + v8) = 0;
  v10 = *((_DWORD *)this + 31);
  v27[v10 + 18] = 0;
  v27[v9] = 2;
  v11 = v35;
  *(_DWORD *)((char *)v27 + v8) = 5;
  v27[v10] = 3;
  v29 = v11 + v7;
  if ( v11 + v7 != 0 )
  {
    v37 = 0;
    v33 = 4 * v39;
    v31 = 4 * v6;
    v12 = -4 * v11 * v6;
    v28 = v12;
    v32 = v12;
    do
    {
      v13 = *((_DWORD *)this + 5);
      if ( v41 >= v35 )
        v14 = *(_DWORD *)(v12 + *((_DWORD *)a3 + 2));
      else
        v14 = *(_DWORD *)(v37 + *((_DWORD *)a2 + 2));
      v15 = *(_DWORD *)(v13 + 4 * v14);
      v16 = *(_DWORD *)(v15 + 4);
      v30 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v16);
      v17 = 0;
      v38 = 0;
      if ( v41 != 0 )
      {
        v39 = 0;
        v34 = v28;
        do
        {
          if ( v17 >= v35 )
          {
            v18 = a3;
            v19 = v34;
          }
          else
          {
            v18 = a2;
            v19 = v39;
          }
          v20 = *(_DWORD **)(v13 + 4 * *(_DWORD *)(v19 + *((_DWORD *)v18 + 2)));
          if ( v16 == v20[1] && *(_DWORD *)(v15 + 8) == v20[2] && *(_DWORD *)(v15 + 12) == v20[3] )
            break;
          v34 += v31;
          ++v38;
          v39 += v33;
          v17 = v38;
        }
        while ( v38 < v41 );
      }
      if ( v38 == v41 )
      {
        v21 = *((_DWORD *)this + 34);
        if ( v16 == v21 && *(_DWORD *)(v15 + 12) > 1u && (unsigned int)++v40 > 3 )
          return 1;
        if ( v16 == *((_DWORD *)this + 32) )
        {
          if ( *(_BYTE *)(v15 + 108) == 3 )
          {
            if ( (unsigned __int16)*((_DWORD *)this + 50) == 257 && (unsigned int)++v40 > 3 )
              return 1;
            v22 = v21;
          }
          else
          {
            v22 = *((_DWORD *)this + 32);
          }
          v23 = &v27[v22 + 18];
          v24 = ++*v23 <= v27[v22];
        }
        else
        {
          v25 = *(_DWORD *)(v30 + 4);
          if ( (v25 & 0x80u) != 0 )
            return 0;
          if ( (v25 & 0x200) != 0 )
          {
            v24 = (unsigned int)++v36 <= 3;
          }
          else
          {
            v26 = *(_DWORD *)(v15 + 4);
            v24 = ++v27[v26 + 18] <= v27[v26];
          }
        }
        if ( !v24 )
          return 1;
      }
      ++v41;
      v37 += v33;
      v12 = v31 + v32;
      v32 += v31;
    }
    while ( v41 < v29 );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020B664
// Name: protected: virtual long D3DXShader::CPSLegacyProgram::SrcSwizzle(unsigned int __near *,unsigned int,unsigned long,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::SrcSwizzle(
        D3DXShader::CPSLegacyProgram *this,
        unsigned int *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5)
{
  D3DXShader::CPSProgram *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // ecx
  int v9; // edx
  int v10; // ebx
  unsigned int v11; // edi
  unsigned int v12; // esi
  unsigned int *v13; // ebx
  unsigned int *v14; // esi
  unsigned int v16; // edx
  unsigned int v17; // ecx
  unsigned int *v18; // eax
  unsigned int v19; // esi
  unsigned int v20[4]; // [esp+Ch] [ebp-24h] BYREF
  _DWORD v21[4]; // [esp+1Ch] [ebp-14h] BYREF
  D3DXShader::CPSProgram *v22; // [esp+2Ch] [ebp-4h]

  v5 = this;
  v6 = 0;
  v22 = this;
  if ( (a4 & 0x10000) != 0 )
  {
    v21[0] = 0;
    v6 = 1;
  }
  if ( (a4 & 0x20000) != 0 )
    v21[v6++] = 1;
  if ( (a4 & 0x40000) != 0 )
    v21[v6++] = 2;
  if ( (a4 & 0x80000) != 0 )
    v21[v6++] = 3;
  v7 = a3;
  if ( a3 > v6 )
    v7 = v6;
  memset(v20, 255, sizeof(v20));
  v8 = 0;
  if ( v7 != 0 )
  {
    v9 = *((_DWORD *)v5 + 5);
    do
    {
      v10 = v21[v8];
      v11 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)((char *)&v21[v8++] + (char *)a2 - (char *)v21)) + 16);
      v20[v10] = v11;
    }
    while ( v8 < v7 );
    v5 = v22;
  }
  if ( (unsigned __int16)*((_DWORD *)v5 + 50) == 260 )
  {
    v12 = 0;
    v13 = D3DXShader::g_LegacySwizzle;
    while ( D3DXShader::CPSProgram::ValidSwizzle(this: v22, a2: v20, a3: v13) == 0 )
    {
      ++v12;
      v13 += 4;
      if ( v12 >= 5 )
        goto LABEL_21;
    }
    v14 = &D3DXShader::g_LegacySwizzle[4 * v12];
    if ( v14 != nullptr )
      goto LABEL_27;
LABEL_21:
    D3DXShader::CProgram::Error(
      this: v22,
      a2: *(struct D3DXShader::CNode **)(*((_DWORD *)v22 + 64) + 60),
      a3: 0x11B5u,
      format: "cannot map swizzle to ps_1_4");
    return -2147467259;
  }
  else
  {
    v14 = &dword_10336710;
    if ( D3DXShader::CPSProgram::ValidSwizzle(this: v5, a2: v20, a3: &dword_10336710) == 0 )
    {
      v14 = &dword_10336720;
      if ( D3DXShader::CPSProgram::ValidSwizzle(this: v5, a2: v20, a3: &dword_10336720) == 0
        && D3DXShader::CPSProgram::ValidSwizzle(this: v5, a2: v20, a3: &dword_10336700) != 0
        && (a4 & 0xF0000) == 0x80000 )
      {
        v14 = &dword_10336700;
      }
    }
LABEL_27:
    v16 = 0;
    v17 = 16;
    v18 = v14;
    do
    {
      v19 = *v18++ << v17;
      v16 |= v19;
      v17 += 2;
    }
    while ( v17 < 0x18 );
    *a5 = v16;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B7D2
// Name: public: virtual D3DXShader::CPSLegacyProgram::~CPSLegacyProgram(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPSLegacyProgram::~CPSLegacyProgram(D3DXShader::CPSLegacyProgram *this)
{
  unsigned int v2; // edi
  D3DXShader::CInstruction *v3; // ecx
  unsigned int v4; // edi
  D3DXShader::CArgument *v5; // ecx
  D3DXShader::CInstruction **v6; // edi
  int i; // ebx
  void *v8; // [esp-4h] [ebp-10h]

  v8 = *((void **)this + 139);
  *(_DWORD *)this = &D3DXShader::CPSLegacyProgram::`vftable';
  free(pMem: v8);
  free(pMem: *((void **)this + 140));
  v2 = 0;
  if ( *((_DWORD *)this + 173) != 0 && *((_DWORD *)this + 176) != 0 )
  {
    do
    {
      v3 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 173) + 4 * v2);
      if ( v3 != nullptr )
        D3DXShader::CInstruction::`scalar deleting destructor'(this: v3, a2: 1);
      ++v2;
    }
    while ( v2 < *((_DWORD *)this + 176) );
  }
  v4 = 0;
  if ( *((_DWORD *)this + 174) != 0 && *((_DWORD *)this + 175) != 0 )
  {
    do
    {
      v5 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 174) + 4 * v4);
      if ( v5 != nullptr )
        D3DXShader::CArgument::`scalar deleting destructor'(this: v5, a2: 1);
      ++v4;
    }
    while ( v4 < *((_DWORD *)this + 175) );
  }
  v6 = (D3DXShader::CInstruction **)((char *)this + 708);
  for ( i = 16; i != 0; --i )
  {
    if ( *v6 != nullptr )
      D3DXShader::CInstruction::`scalar deleting destructor'(this: *v6, a2: 1);
    *v6++ = nullptr;
  }
  free(pMem: *((void **)this + 173));
  free(pMem: *((void **)this + 174));
  D3DXShader::CShaderProgram::~CShaderProgram(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020B896
// Name: protected: virtual long D3DXShader::CPSLegacyProgram::Translate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::Translate(D3DXShader::CPSLegacyProgram *this)
{
  int v2; // edi
  int v3; // eax
  _DWORD *v4; // eax
  int result; // eax
  int v6; // edi
  int v7; // eax
  _DWORD *v8; // eax

  v2 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    while ( 1 )
    {
      v3 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v2;
      v4 = *(_DWORD **)(v3 + 4 * v2);
      *((_DWORD *)this + 64) = v4;
      if ( (*v4 & 0xFFF00000) == 0x11000000 )
      {
        result = D3DXShader::CPSLegacyProgram::CleanUpClip(this);
        if ( result < 0 )
          break;
      }
      if ( (unsigned int)++v2 >= *((_DWORD *)this + 3) )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    D3DXShader::CShaderProgram::Reset(this);
    v6 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      while ( 1 )
      {
        v7 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v6;
        v8 = *(_DWORD **)(v7 + 4 * v6);
        *((_DWORD *)this + 64) = v8;
        if ( (*v8 & 0xFFF00000) == 0x11000000 )
        {
          result = D3DXShader::CPSLegacyProgram::MatchClip(this);
          if ( result < 0 )
            break;
        }
        if ( (unsigned int)++v6 >= *((_DWORD *)this + 3) )
          goto LABEL_9;
      }
    }
    else
    {
LABEL_9:
      D3DXShader::CShaderProgram::Reset(this);
      result = D3DXShader::CProgram::RemoveDeadCode(this);
      if ( result >= 0 )
      {
        result = D3DXShader::CProgram::RemoveDuplicateArguments(this);
        if ( result >= 0 )
        {
          result = D3DXShader::CProgram::CompactInstructions(this);
          if ( result >= 0 )
          {
            result = D3DXShader::CProgram::CompactArguments(this);
            if ( result >= 0 )
            {
              D3DXShader::CShaderProgram::Reset(this);
              return 0;
            }
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020B953
// Name: protected: long D3DXShader::CPSLegacyProgram::EmmulateWriteMasksX(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EmmulateWriteMasksX(D3DXShader::CPSLegacyProgram *this)
{
  unsigned int v1; // edx
  unsigned int v3; // ecx
  bool v4; // zf
  _DWORD *v5; // eax
  int v6; // edi
  unsigned int i; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  unsigned int v10; // eax
  unsigned __int8 *v11; // eax
  struct D3DXShader::CInstruction *v12; // ebx
  int v13; // edx
  unsigned int v14; // edx
  unsigned int *v15; // eax
  unsigned int v16; // ebx
  D3DXShader::CArgument *v17; // edi
  int v18; // eax
  unsigned __int8 *v19; // eax
  D3DXShader::CInstruction *v20; // edi
  struct D3DXShader::CInstruction *v21; // eax
  unsigned int v22; // eax
  int v23; // ecx
  int v24; // edx
  _DWORD *v25; // eax
  D3DXShader::CInstruction *v26; // eax
  unsigned int v27; // eax
  int v28; // edx
  unsigned int v29; // edi
  int v30; // ecx
  int v31; // eax
  int v32; // eax
  int v33; // edi
  int v34; // eax
  unsigned int v35; // ecx
  int v36; // eax
  _DWORD *v37; // edi
  unsigned int v38; // eax
  int v39; // ecx
  int v40; // eax
  D3DXShader::CInstruction *m; // ecx
  unsigned int *v42; // eax
  unsigned int v43; // edi
  int v44; // eax
  unsigned __int8 *v45; // eax
  D3DXShader::CInstruction *v46; // eax
  struct D3DXShader::CArgument *v47; // eax
  int v48; // ebx
  unsigned int *v49; // edi
  unsigned int v50; // eax
  unsigned int v51; // ecx
  unsigned int n; // edi
  unsigned int *v53; // edx
  D3DXShader::CInstruction *v54; // ecx
  int v55; // ebx
  int v56; // ecx
  int v57; // edx
  unsigned int *v58; // edi
  unsigned int v59; // eax
  unsigned int v60; // ecx
  int v61; // ecx
  unsigned int v62; // edx
  unsigned int *v63; // ecx
  D3DXShader::CInstruction *v64; // ecx
  int v65; // ecx
  D3DXShader::CInstruction *v66; // ebx
  int v67; // eax
  int v68; // edi
  unsigned int v69; // eax
  _DWORD *v70; // ecx
  int v71; // edx
  int v72; // eax
  int v73; // edi
  unsigned int v74; // eax
  _DWORD *v75; // ecx
  unsigned int v76; // edx
  unsigned int v77; // eax
  int v78; // ecx
  int v79; // eax
  int v80; // edx
  bool v81; // cf
  unsigned int v82; // eax
  unsigned int v83; // ecx
  int v84; // edi
  unsigned int j; // eax
  D3DXShader::CInstruction *v86; // ecx
  unsigned int *v88; // [esp-8h] [ebp-120h]
  unsigned int v89[40]; // [esp+14h] [ebp-104h] BYREF
  _DWORD v90[4]; // [esp+B4h] [ebp-64h] BYREF
  int v91[4]; // [esp+C4h] [ebp-54h] BYREF
  int v92; // [esp+D4h] [ebp-44h] BYREF
  unsigned int v93; // [esp+D8h] [ebp-40h]
  int v94; // [esp+DCh] [ebp-3Ch]
  int v95; // [esp+E0h] [ebp-38h] BYREF
  int v96; // [esp+E4h] [ebp-34h]
  int v97; // [esp+E8h] [ebp-30h]
  unsigned int v98; // [esp+ECh] [ebp-2Ch]
  unsigned int v99; // [esp+F0h] [ebp-28h] BYREF
  unsigned int v100; // [esp+F4h] [ebp-24h]
  D3DXShader::CInstruction *v101; // [esp+F8h] [ebp-20h]
  struct D3DXShader::CArgument *v102; // [esp+FCh] [ebp-1Ch]
  D3DXShader::CInstruction *v103; // [esp+100h] [ebp-18h]
  signed int k; // [esp+104h] [ebp-14h]
  struct D3DXShader::CInstruction *v105; // [esp+108h] [ebp-10h]
  unsigned int v106; // [esp+10Ch] [ebp-Ch] BYREF
  unsigned int v107; // [esp+110h] [ebp-8h]
  int v108; // [esp+114h] [ebp-4h]

  v1 = 0;
  v3 = 0;
  v4 = *((_DWORD *)this + 2) == 0;
  v101 = nullptr;
  v103 = nullptr;
  if ( !v4 )
  {
    do
    {
      v5 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v3);
      v6 = v5[1];
      v5[12] = 0;
      if ( v6 == *((_DWORD *)this + 34) )
        v5[3] = -1;
      ++v3;
    }
    while ( v3 < *((_DWORD *)this + 2) );
  }
  for ( i = *((_DWORD *)this + 19); i < *((_DWORD *)this + 137); ++i )
  {
    v8 = *(_DWORD **)(*((_DWORD *)this + 140) + 4 * i);
    if ( v8 != nullptr && *v8 != 0 && v8[3] != 0 )
    {
      do
      {
        v9 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v8[4] + 4 * v1++));
        *(_DWORD *)(v9 + 72) = i;
      }
      while ( v1 < v8[3] );
      v1 = 0;
    }
  }
  v10 = *((_DWORD *)this + 19);
  v98 = *((_DWORD *)this + 137);
  v100 = v10;
  if ( v10 >= v98 )
  {
LABEL_137:
    for ( j = *((_DWORD *)this + 19); j < v98; ++j )
      **(_DWORD **)(*((_DWORD *)this + 140) + 4 * j) = 0;
    k = 0;
    goto LABEL_146;
  }
  while ( 1 )
  {
    v105 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 140) + 4 * v100);
    if ( v105 != nullptr && *(_DWORD *)v105 != 0 )
      break;
LABEL_136:
    if ( ++v100 >= v98 )
      goto LABEL_137;
  }
  v11 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v11 != nullptr )
    v103 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v11);
  else
    v103 = nullptr;
  if ( v103 == nullptr )
    goto LABEL_142;
  k = D3DXShader::CInstruction::Initialize(this: v103, a2: v105);
  if ( k < 0 )
    goto LABEL_148;
  if ( *((_DWORD *)this + 137) >= 0x200u )
    goto LABEL_142;
  v12 = v105;
  v13 = *(_DWORD *)v105;
  v97 = 0;
  v94 = 0;
  v14 = v13 & 0xFFF00000;
  if ( v14 == 1342177280 && *((_DWORD *)v105 + 3) == 1 )
  {
    v15 = *((unsigned int **)v105 + 4);
    v4 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v15) + 16) == 3;
    v102 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * *v15);
    if ( v4 )
    {
      D3DXShader::CPSLegacyProgram::AnalizeArgUse(
        this,
        a2: *((struct D3DXShader::CInstruction ***)this + 140),
        a3: v100,
        a4: v98,
        a5: v15,
        a6: 1u,
        a7: &v99,
        a8: &v95,
        a9: &v92);
      if ( v92 != 0 )
      {
        v16 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: 0, a4: 3u, a5: 0.0);
        if ( v16 == -1 )
          goto LABEL_142;
        v17 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v16);
        D3DXShader::CArgument::Initialize(this: v17, a2: v102);
        v18 = *((_DWORD *)this + 34);
        *((_DWORD *)v17 + 15) = 0;
        *((_DWORD *)v17 + 1) = v18;
        *((_DWORD *)v17 + 4) = 3;
        v19 = D3DXShader::CInstruction::operator new(a1: 0x74u);
        v20 = v19 != nullptr
            ? (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v19)
            : nullptr;
        if ( v20 == nullptr )
          goto LABEL_142;
        k = D3DXShader::CInstruction::Initialize(this: v20, a2: 0x10000001u, a3: 1u, a4: 1u, a5: 0);
        if ( k < 0 || (k = D3DXShader::CInstruction::Instance(this: v20, a2: v105)) < 0 )
        {
          v86 = v20;
          goto LABEL_147;
        }
        **((_DWORD **)v20 + 4) = **((_DWORD **)v105 + 4);
        **((_DWORD **)v20 + 2) = v16;
        v21 = v103;
        **((_DWORD **)v103 + 4) = v16;
        *(_DWORD *)(*((_DWORD *)this + 140) + 4 * (*((_DWORD *)this + 137))++) = v21;
        v99 = (unsigned int)v21;
        if ( (D3DXShader::CBaseProgram::AddInstruction(this, a2: v21) & 0x80000000) != 0 )
          goto LABEL_142;
        v22 = *((_DWORD *)this + 137);
        if ( v22 >= 0x200 )
          goto LABEL_142;
        *(_DWORD *)(*((_DWORD *)this + 140) + 4 * v22) = v20;
        ++*((_DWORD *)this + 137);
        if ( (D3DXShader::CBaseProgram::AddInstruction(this, a2: v20) & 0x80000000) != 0 )
          goto LABEL_142;
        goto LABEL_36;
      }
LABEL_45:
      if ( (D3DXShader::CBaseProgram::AddInstruction(this, a2: v103) & 0x80000000) != 0 )
        goto LABEL_142;
      v26 = v103;
      *(_DWORD *)(*((_DWORD *)this + 140) + 4 * (*((_DWORD *)this + 137))++) = v103;
      v99 = (unsigned int)v26;
LABEL_36:
      v12 = v105;
      goto LABEL_48;
    }
  }
  if ( v14 != 0x10000000 || D3DXShader::CPSLegacyProgram::HasWriteMask(this, a2: v105) == 0 )
    goto LABEL_45;
  v23 = *((_DWORD *)v12 + 3);
  v97 = 1;
  if ( v23 != 0 )
  {
    v24 = *((_DWORD *)this + 5);
    v25 = *((_DWORD **)v12 + 4);
    do
    {
      if ( *(_DWORD *)(*(_DWORD *)(v24 + 4 * *v25) + 60) != 0 )
        v97 = 0;
      ++v25;
      --v23;
    }
    while ( v23 != 0 );
    if ( v97 == 0 )
      goto LABEL_45;
  }
  D3DXShader::CInstruction::`scalar deleting destructor'(this: v103, a2: 1);
  v99 = 0;
LABEL_48:
  v103 = nullptr;
  if ( D3DXShader::CPSLegacyProgram::HasWriteMask(this, a2: v12) == 0 )
    goto LABEL_133;
  v102 = nullptr;
  v106 = 0;
  memset(v91, 255, sizeof(v91));
  v27 = *((_DWORD *)v12 + 3);
  if ( v27 != 0 )
  {
    v28 = *((_DWORD *)this + 5);
    do
    {
      v29 = 4 * v106;
      v30 = *(_DWORD *)(4 * v106 + *((_DWORD *)v12 + 4));
      v31 = *(_DWORD *)(v28 + 4 * v30);
      if ( *(_DWORD *)(v31 + 48) != 0 )
      {
        v32 = *(_DWORD *)(v31 + 16);
        v91[v32] = v30;
        v89[v32 + 32] = *(_DWORD *)(v29 + *((_DWORD *)v12 + 2));
        v102 = (struct D3DXShader::CArgument *)1;
      }
      v27 = *((_DWORD *)v12 + 3);
      ++v106;
    }
    while ( v106 < v27 );
  }
  v88 = *((unsigned int **)v12 + 4);
  v33 = 0;
  v106 = 0;
  D3DXShader::CPSLegacyProgram::FindConsumers(
    this,
    a2: *((struct D3DXShader::CInstruction ***)this + 140),
    a3: v100,
    a4: v98,
    a5: v88,
    a6: v27,
    a7: v89,
    a8: &v106);
  if ( v102 == nullptr )
  {
    if ( v106 != 0 )
    {
      do
      {
        v78 = *((_DWORD *)this + 5);
        v79 = *(_DWORD *)(v78 + 4 * v89[v33]);
        v80 = *(_DWORD *)(v79 + 56);
        if ( v80 != -1 )
          v79 = *(_DWORD *)(v78 + 4 * v80);
        v81 = ++v33 < v106;
        *(_DWORD *)(v79 + 48) = 1;
      }
      while ( v81 );
    }
LABEL_133:
    v82 = v99;
    v83 = 0;
    if ( v99 != 0 && *(_DWORD *)(v99 + 12) != 0 )
    {
      do
      {
        v84 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v82 + 16) + 4 * v83++));
        *(_DWORD *)(v84 + 72) = *((_DWORD *)this + 137) - 1;
      }
      while ( v83 < *(_DWORD *)(v82 + 12) );
    }
    goto LABEL_136;
  }
  memset(v90, 255, sizeof(v90));
  v34 = 0;
  for ( k = 0; k < v106; ++k )
  {
    v35 = v89[v34];
    v36 = *((_DWORD *)this + 5);
    v37 = *(_DWORD **)(v36 + 4 * v35);
    v4 = v37[14] == -1;
    v107 = v35;
    if ( !v4 )
    {
      v107 = v37[14];
      v37 = *(_DWORD **)(v36 + 4 * v107);
    }
    v38 = v37[18];
    if ( (v38 >= v98 || v38 < v100) && v38 != -1 )
    {
      v39 = *((_DWORD *)this + 140);
      v108 = 4 * v38;
      v102 = *(struct D3DXShader::CArgument **)(4 * v38 + v39);
      if ( D3DXShader::CPSLegacyProgram::HasWriteMask(this, a2: v102) != 0 )
      {
        if ( (*(_DWORD *)v102 & 0xFFF00000) == 0x10000000 && v37[14] == -1 )
        {
          v40 = 0;
          if ( *((_DWORD *)v102 + 3) != 0 )
          {
            for ( m = *((D3DXShader::CInstruction **)v102 + 4); v107 != *(_DWORD *)m; m = v101 )
            {
              v101 = (D3DXShader::CInstruction *)((char *)m + 4);
              if ( (unsigned int)++v40 >= *(_DWORD *)(*(_DWORD *)(v108 + *((_DWORD *)this + 140)) + 12) )
                goto LABEL_71;
            }
            v89[v37[4] + 36] = *(_DWORD *)(*((_DWORD *)v102 + 2) + 4 * v40);
            v94 = 1;
          }
        }
LABEL_71:
        v42 = &v90[v37[4]];
        if ( *v42 == -1 )
        {
          *v42 = v107;
        }
        else if ( *v42 != v107 )
        {
LABEL_139:
          D3DXShader::CProgram::Error(
            this,
            a2: *((struct D3DXShader::CNode **)v12 + 15),
            a3: 0x11B9u,
            format: "unable to emmulate write masks for ps_1_%i shader model",
            (unsigned __int8)*((_DWORD *)this + 50));
          return -2147467259;
        }
      }
    }
    v34 = k + 1;
  }
  v43 = 0;
  v44 = 0;
  v106 = 0;
  while ( 2 )
  {
    if ( v90[v44] == -1 )
    {
      if ( v91[v44] != -1 )
        goto LABEL_80;
    }
    else
    {
      if ( v91[v44] != -1 )
        goto LABEL_139;
LABEL_80:
      v106 = ++v43;
    }
    if ( (unsigned int)++v44 < 4 )
      continue;
    break;
  }
  v45 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v45 != nullptr )
    v46 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v45);
  else
    v46 = nullptr;
  v101 = v46;
  if ( v46 == nullptr )
    return -2147024882;
  k = D3DXShader::CInstruction::Initialize(this: v46, a2: v43 & 0xFFFFF | 0x70100000, a3: 3 * v43, a4: v43, a5: 0);
  if ( k < 0 )
    goto LABEL_146;
  k = D3DXShader::CInstruction::Instance(this: v101, a2: v105);
  if ( k < 0 )
    goto LABEL_146;
  v108 = 0;
  v102 = nullptr;
  v107 = 4 * v106;
  v47 = nullptr;
  while ( 2 )
  {
    v48 = *(int *)((char *)v91 + (_DWORD)v47);
    if ( v48 != -1 )
    {
      v4 = v97 == 0;
      *(_DWORD *)(*((_DWORD *)v101 + 4) + 4 * v108) = v48;
      if ( v4 )
      {
        v49 = *(unsigned int **)(*((_DWORD *)this + 5) + 4 * v48);
        v50 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: 0, a4: v49[4], a5: 0.0);
        if ( v50 == -1 )
          goto LABEL_142;
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v50) + 60) = v49[15];
        v49[15] = 0;
        v49[18] = *((_DWORD *)this + 137);
        v51 = v99;
        for ( n = 0; n < *(_DWORD *)(v51 + 12); ++n )
        {
          v53 = (unsigned int *)(*(_DWORD *)(v51 + 16) + 4 * n);
          if ( *v53 == v48 )
            *v53 = v50;
        }
      }
      else
      {
        v50 = *(unsigned int *)((char *)&v89[32] + (_DWORD)v47);
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v48) + 72) = *((_DWORD *)this + 137);
      }
      v54 = v101;
      *(_DWORD *)(v107 + *((_DWORD *)v101 + 2)) = v50;
      v93 = v50;
      *(_DWORD *)(*((_DWORD *)v54 + 2) + 4 * v108) = *((_DWORD *)this + 273);
      goto LABEL_111;
    }
    v55 = *(_DWORD *)((char *)v90 + (_DWORD)v47);
    if ( v55 != -1 )
    {
      v56 = *((_DWORD *)v101 + 4);
      v57 = 4 * v108;
      v4 = v94 == 0;
      v96 = v57;
      *(_DWORD *)(v57 + v56) = v55;
      if ( v4 )
      {
        v58 = *(unsigned int **)(*((_DWORD *)this + 5) + 4 * v55);
        v59 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: 0, a4: v58[4], a5: 0.0);
        if ( v59 == -1 )
          goto LABEL_142;
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v59) + 60) = v58[15];
        v60 = v58[18];
        v58[15] = 0;
        if ( v60 == -1 || v60 == *((_DWORD *)this + 137) )
        {
          D3DXShader::CProgram::Error(
            this,
            a2: *((struct D3DXShader::CNode **)v105 + 15),
            a3: 0x12CAu,
            format: "internal error: illformed write field");
          goto LABEL_146;
        }
        v61 = *(_DWORD *)(*((_DWORD *)this + 140) + 4 * v60);
        v62 = 0;
        v4 = *(_DWORD *)(v61 + 12) == 0;
        v95 = v61;
        if ( !v4 )
        {
          do
          {
            v63 = (unsigned int *)(*(_DWORD *)(v61 + 16) + 4 * v62);
            if ( *v63 == v55 )
              *v63 = v59;
            v61 = v95;
            ++v62;
          }
          while ( v62 < *(_DWORD *)(v95 + 12) );
        }
        v57 = v96;
        v58[18] = *((_DWORD *)this + 137);
      }
      else
      {
        v59 = *(unsigned int *)((char *)&v89[36] + (_DWORD)v47);
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v55) + 72) = *((_DWORD *)this + 137);
      }
      v64 = v101;
      *(_DWORD *)(v57 + *((_DWORD *)v101 + 2)) = *((_DWORD *)this + 272);
      v65 = *((_DWORD *)v64 + 2);
      v96 = v59;
      *(_DWORD *)(v65 + 4 * (v108 + 2 * v106)) = v59;
LABEL_111:
      ++v108;
      v107 += 4;
      v47 = v102;
    }
    v47 = (struct D3DXShader::CArgument *)((char *)v47 + 4);
    v102 = v47;
    if ( (unsigned int)v47 < 0x10 )
      continue;
    break;
  }
  v108 = 0;
  v66 = v101;
  v105 = nullptr;
  v107 = 4 * v106;
  while ( 2 )
  {
    v67 = *(int *)((char *)v91 + (_DWORD)v105);
    if ( v67 != -1 )
    {
      v68 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v67);
      v69 = D3DXShader::CBaseProgram::AddArgument(
              this,
              a2: *((_DWORD *)this + 34),
              a3: 0,
              a4: *(_DWORD *)(v68 + 16),
              a5: 0.0);
      if ( v69 == -1 )
        goto LABEL_142;
      v70 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v69);
      v71 = v96;
      v4 = v96 == -1;
      v70[14] = v96;
      v70[15] = *(_DWORD *)(v68 + 60);
      if ( !v4 )
        v70[1] = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v71) + 4);
      *(_DWORD *)(*((_DWORD *)v66 + 2) + 4 * (v108 + 2 * v106)) = v69;
      goto LABEL_124;
    }
    v72 = *(_DWORD *)((char *)v90 + (_DWORD)v105);
    if ( v72 != -1 )
    {
      v73 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v72);
      v74 = D3DXShader::CBaseProgram::AddArgument(
              this,
              a2: *((_DWORD *)this + 34),
              a3: 0,
              a4: *(_DWORD *)(v73 + 16),
              a5: 0.0);
      if ( v74 == -1 )
        goto LABEL_142;
      v75 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v74);
      v76 = v93;
      v4 = v93 == -1;
      v75[14] = v93;
      v75[15] = *(_DWORD *)(v73 + 60);
      if ( !v4 )
        v75[1] = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v76) + 4);
      *(_DWORD *)(v107 + *((_DWORD *)v66 + 2)) = v74;
LABEL_124:
      ++v108;
      v107 += 4;
    }
    v105 = (struct D3DXShader::CInstruction *)((char *)v105 + 4);
    if ( (unsigned int)v105 < 0x10 )
      continue;
    break;
  }
  v77 = *((_DWORD *)this + 137);
  if ( v77 < 0x200 )
  {
    *(_DWORD *)(*((_DWORD *)this + 140) + 4 * v77) = v66;
    ++*((_DWORD *)this + 137);
    if ( (D3DXShader::CBaseProgram::AddInstruction(this, a2: v66) & 0x80000000) == 0 )
    {
      v101 = nullptr;
      goto LABEL_133;
    }
  }
LABEL_142:
  k = -2147024882;
LABEL_146:
  v86 = v101;
  if ( v101 != nullptr )
LABEL_147:
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v86, a2: 1);
LABEL_148:
  if ( v103 != nullptr )
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v103, a2: 1);
  return k;
}

//------------------------------------------------------------------------------
// Address: 0x1020C261
// Name: protected: long D3DXShader::CPSLegacyProgram::GreedyPullUp(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::GreedyPullUp(D3DXShader::CPSLegacyProgram *this)
{
  unsigned int i; // eax
  unsigned int j; // edi
  struct D3DXShader::CInstruction *v4; // eax
  int v5; // eax
  unsigned int k; // edi
  int v7; // edx
  int v8; // ecx
  unsigned int v9; // ecx
  _DWORD *v10; // ecx
  int v11; // eax
  int result; // eax
  unsigned int v13; // edi
  unsigned int m; // ebx
  _DWORD *v15; // edx
  int v16; // eax
  struct D3DXShader::CInstruction *v17; // edx
  int v18; // ecx
  struct D3DXShader::CInstruction *v19; // edi
  unsigned int v20; // edx
  int v21; // ecx
  bool v22; // zf
  _DWORD *v23; // eax
  unsigned int v24; // ecx
  bool v25; // zf
  _DWORD *v26; // eax
  D3DXShader::CPSLegacyProgram *v27; // ecx
  unsigned int v28; // eax
  int v29; // edi
  _DWORD *v30; // edx
  int v31; // eax
  struct D3DXShader::CInstruction *v32; // edx
  int v33; // ecx
  int v34; // ebx
  _DWORD *v35; // ecx
  unsigned int v36; // edi
  int v37; // edx
  int v38; // ecx
  unsigned int v39; // [esp+0h] [ebp-20h]
  unsigned int v40; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v41; // [esp+10h] [ebp-10h] BYREF
  int v42; // [esp+14h] [ebp-Ch]
  int v43; // [esp+18h] [ebp-8h]
  unsigned int v44; // [esp+1Ch] [ebp-4h] BYREF

  for ( i = 0; i < *((_DWORD *)this + 3); ++i )
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * i) + 40) = 0;
  for ( j = 0; j < 0x18; j += 4 )
  {
    v4 = *(struct D3DXShader::CInstruction **)(j + *((_DWORD *)this + 140));
    if ( v4 != nullptr )
    {
      D3DXShader::CShaderProgram::ColorParents2(
        this,
        a2: *((struct D3DXShader::CInstruction ***)this + 6),
        a3: v4,
        a4: 1u);
      D3DXShader::CShaderProgram::ColorChildren2(
        this,
        a2: *((struct D3DXShader::CInstruction ***)this + 6),
        a3: *(struct D3DXShader::CInstruction **)(j + *((_DWORD *)this + 140)),
        a4: 2u);
    }
    v5 = *(_DWORD *)(j + *((_DWORD *)this + 139));
    if ( v5 != 0 )
      *(_DWORD *)(v5 + 40) = 1;
  }
  for ( k = 0; k < *((_DWORD *)this + 3); ++k )
  {
    if ( D3DXShader::IsTextureInst(
           this: (D3DXShader *)(**(_DWORD **)(*((_DWORD *)this + 6) + 4 * k) & 0xFFF00000),
           a2: v39) == 0
      && v8 != 1913651200
      && v8 != 285212672 )
    {
      v9 = *((_DWORD *)this + 136);
      if ( v9 >= 0x200 )
        return -2147467259;
      if ( *(_DWORD *)(v7 + 40) == 1 )
      {
        *(_DWORD *)(*((_DWORD *)this + 139) + 4 * v9) = v7;
        ++*((_DWORD *)this + 136);
      }
    }
  }
  v10 = *((_DWORD **)this + 139);
  v42 = 1;
  if ( v10 != nullptr && *((_DWORD *)this + 136) != 0 )
  {
    v11 = *((_DWORD *)this + 136);
    do
    {
      if ( *v10 != 0 )
        v42 = 0;
      ++v10;
      --v11;
    }
    while ( v11 != 0 );
  }
  v43 = 0;
LABEL_24:
  v44 = 0;
  result = D3DXShader::CPSLegacyProgram::AddPhaseLinkage(this, a2: &v44);
  if ( result < 0 )
    return result;
  D3DXShader::CPSLegacyProgram::MarkCoIssues(
    this,
    a2: *((struct D3DXShader::CInstruction ***)this + 139),
    a3: 6u,
    a4: *((_DWORD *)this + 136),
    a5: &v41);
  v13 = 0;
  for ( m = 0; v13 < *((_DWORD *)this + 3); ++v13 )
  {
    v15 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v13);
    if ( v15 != nullptr )
    {
      v16 = v15[10];
      if ( (v16 == 2 || v16 == 0)
        && D3DXShader::IsTextureInst(this: (D3DXShader *)(*v15 & 0xFFF00000), a2: v39) == 0
        && v18 != 285212672
        && v18 != 1913651200 )
      {
        *(&dword_1035BDC0 + m++) = v17;
      }
      if ( m >= 0x200 )
        return -2147024882;
    }
  }
  do
  {
LABEL_35:
    D3DXShader::CPSLegacyProgram::MarkCoIssues(this, a2: &dword_1035BDC0, a3: 0, a4: m, a5: &v40);
    if ( v40 + v44 < 8 && (v40 <= v41 || v43 != 0 || v42 != 0) )
    {
LABEL_77:
      if ( (unsigned int)++v43 >= 2 )
      {
        v34 = 0;
        if ( *((_DWORD *)this + 3) == 0 )
          return 0;
        while ( 1 )
        {
          v35 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v34);
          if ( v35[10] == 0 )
            v35[10] = 2;
          v36 = *((_DWORD *)this + 137);
          if ( v36 >= 0x200 )
            break;
          if ( v35[10] == 2
            && D3DXShader::IsTextureInst(this: (D3DXShader *)(*v35 & 0xFFF00000), a2: v39) == 0
            && v37 != 285212672
            && v37 != 1913651200 )
          {
            *(_DWORD *)(*((_DWORD *)this + 140) + 4 * v36) = v38;
            ++*((_DWORD *)this + 137);
          }
          if ( (unsigned int)++v34 >= *((_DWORD *)this + 3) )
            return 0;
        }
        return -2147467259;
      }
      goto LABEL_24;
    }
    v44 = 0;
    if ( *((_DWORD *)this + 3) == 0 )
      goto LABEL_64;
    while ( 1 )
    {
      v19 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v44);
      if ( *((_DWORD *)v19 + 10) != 0
        || D3DXShader::IsTextureInst(this: (D3DXShader *)(*(_DWORD *)v19 & 0xFFF00000), a2: v39) != 0
        || v21 == 1913651200 )
      {
        goto LABEL_60;
      }
      v22 = v20 == *((_DWORD *)v19 + 1);
      if ( v20 < *((_DWORD *)v19 + 1) )
      {
        v23 = *((_DWORD **)v19 + 2);
        do
        {
          if ( *(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v23) + 108) == 1 )
            break;
          ++v20;
          ++v23;
        }
        while ( v20 < *((_DWORD *)v19 + 1) );
        v22 = v20 == *((_DWORD *)v19 + 1);
      }
      if ( v22 )
      {
        v24 = 0;
        if ( v43 != 0 )
          goto LABEL_56;
        v25 = *((_DWORD *)v19 + 3) == 0;
        if ( *((_DWORD *)v19 + 3) != 0 )
        {
          v26 = *((_DWORD **)v19 + 4);
          do
          {
            if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v26) + 16) == 3 )
              break;
            ++v24;
            ++v26;
          }
          while ( v24 < *((_DWORD *)v19 + 3) );
          v25 = v24 == *((_DWORD *)v19 + 3);
        }
        if ( v25 )
        {
LABEL_56:
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                     + 4
                                     * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v19 + 4)) + 4))
                         + 4)
              & 0x20) == 0 )
          {
            *((_DWORD *)v19 + 10) = 1;
            if ( !D3DXShader::CPSLegacyProgram::ViolatesPhaseLinkage(this, a2: (unsigned int)v19)
              && D3DXShader::CPSLegacyProgram::IsDependentOnPhase2(this: v27, a2: v19) == 0 )
            {
              break;
            }
            *((_DWORD *)v19 + 10) = 0;
          }
        }
      }
LABEL_60:
      if ( ++v44 >= *((_DWORD *)this + 3) )
        goto LABEL_64;
    }
    v28 = *((_DWORD *)this + 136);
    if ( v28 >= 0x200 )
      return -2147024882;
    *(_DWORD *)(*((_DWORD *)this + 139) + 4 * v28) = v19;
    ++*((_DWORD *)this + 136);
LABEL_64:
    if ( v44 == *((_DWORD *)this + 3) )
      goto LABEL_77;
    v44 = 0;
    result = D3DXShader::CPSLegacyProgram::AddPhaseLinkage(this, a2: &v44);
    if ( result < 0 )
      return result;
    D3DXShader::CPSLegacyProgram::MarkCoIssues(
      this,
      a2: *((struct D3DXShader::CInstruction ***)this + 139),
      a3: 6u,
      a4: *((_DWORD *)this + 136),
      a5: &v41);
    v29 = 0;
    m = 0;
  }
  while ( *((_DWORD *)this + 3) == 0 );
  while ( 1 )
  {
    v30 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v29);
    if ( v30 != nullptr )
    {
      v31 = v30[10];
      if ( (v31 == 2 || v31 == 0)
        && D3DXShader::IsTextureInst(this: (D3DXShader *)(*v30 & 0xFFF00000), a2: v39) == 0
        && v33 != 285212672
        && v33 != 1913651200 )
      {
        *(&dword_1035BDC0 + m++) = v32;
      }
      if ( m >= 0x200 )
        return -2147024882;
    }
    if ( (unsigned int)++v29 >= *((_DWORD *)this + 3) )
      goto LABEL_35;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C644
// Name: protected: long D3DXShader::CPSLegacyProgram::MatchPhase1(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::MatchPhase1(D3DXShader::CPSLegacyProgram *this)
{
  bool v2; // zf
  struct D3DXShader::CInstruction **v4; // eax
  struct D3DXShader::CInstruction *v5; // edx
  int v6; // ebx
  struct D3DXShader::CInstruction *v7; // ecx
  unsigned int v8; // edx
  unsigned int i; // edx
  struct D3DXShader::CInstruction **v10; // eax
  int v11; // ecx
  struct D3DXShader::CInstruction **v12; // ecx
  int matched; // edi
  struct D3DXShader::CInstruction *v14; // eax
  unsigned int j; // eax
  struct D3DXShader::CInstruction *v16[4]; // [esp+8h] [ebp-2Ch] BYREF
  struct D3DXShader::CInstruction *v17[4]; // [esp+18h] [ebp-1Ch] BYREF
  int v18; // [esp+28h] [ebp-Ch]
  unsigned int v19; // [esp+2Ch] [ebp-8h]
  unsigned int v20; // [esp+30h] [ebp-4h]

  v2 = *((_DWORD *)this + 19) == 4;
  v18 = 0;
  if ( !v2 )
    return -2147467259;
  memset(v17, 0, sizeof(v17));
  memset(v16, 0, sizeof(v16));
  v20 = 0;
  v19 = 0;
  do
  {
    v4 = (struct D3DXShader::CInstruction **)(*((_DWORD *)this + 140) + 4 * v19);
    v5 = *v4;
    if ( *v4 != nullptr && *(_DWORD *)v5 != 0 )
    {
      if ( (*(_DWORD *)v5 & 0xFFF00000) == 0x72100000 )
      {
        v7 = *v4;
      }
      else
      {
        v6 = 0;
        if ( (*(_DWORD *)v5 & 0xFFF00000) != 0x11000000 )
          v6 = *(_DWORD *)v5 & 0xFFFFF;
        v7 = *v4;
        if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v5 + 2) + 4 * v6)) + 4) == *((_DWORD *)this + 34) )
        {
          v8 = v20++;
          v16[v8] = v7;
LABEL_13:
          *v4 = nullptr;
          goto LABEL_14;
        }
      }
      v17[v19] = v7;
      goto LABEL_13;
    }
LABEL_14:
    ++v19;
  }
  while ( v19 < *((_DWORD *)this + 19) );
  for ( i = 0; i < *((_DWORD *)this + 19); ++i )
  {
    v10 = (struct D3DXShader::CInstruction **)(*((_DWORD *)this + 139) + 4 * i);
    if ( *v10 != nullptr )
    {
      v11 = *(_DWORD *)*v10;
      if ( v11 != 0 && (v11 & 0xFFF00000) != 0x72100000 )
      {
        v12 = &v17[i];
        if ( *v12 != nullptr )
        {
          matched = -2147467259;
          goto LABEL_36;
        }
        *v12 = *v10;
        *v10 = nullptr;
      }
    }
  }
  if ( (unsigned __int16)*((_DWORD *)this + 50) > 0x101u )
  {
    matched = D3DXShader::CPSLegacyProgram::Match3xM(this, a2: v16, a3: v20, a4: v17, a5: 1u);
    if ( matched < 0 )
      goto LABEL_36;
  }
  matched = D3DXShader::CPSLegacyProgram::Match3xM(this, a2: v16, a3: v20, a4: v17, a5: 2u);
  if ( matched < 0 )
    goto LABEL_36;
  matched = D3DXShader::CPSLegacyProgram::Match3xM(this, a2: v16, a3: v20, a4: v17, a5: 3u);
  if ( matched < 0 )
    goto LABEL_36;
  matched = D3DXShader::CPSLegacyProgram::MatchDep(this, a2: v16, a3: v20, a4: v17);
  if ( matched < 0 )
    goto LABEL_36;
  v2 = *((_DWORD *)this + 19) == 0;
  v19 = 0;
  if ( !v2 )
  {
    do
    {
      v14 = v16[v19];
      if ( v14 != nullptr )
      {
        matched = -2147467259;
        D3DXShader::CProgram::Error(
          this,
          a2: *((struct D3DXShader::CNode **)v14 + 15),
          a3: 0x11ABu,
          format: "cannot map this dependent texture read to ps_1_%i",
          (unsigned __int8)*((_DWORD *)this + 50));
        v18 = 1;
      }
      ++v19;
    }
    while ( v19 < *((_DWORD *)this + 19) );
  }
  if ( matched != -2147467259 )
  {
    for ( j = 0; j < *((_DWORD *)this + 19); ++j )
      *(_DWORD *)(*((_DWORD *)this + 140) + 4 * j) = v17[j];
    free(pMem: *((void **)this + 139));
    *((_DWORD *)this + 139) = 0;
    *((_DWORD *)this + 136) = 0;
    matched = 0;
  }
  if ( matched < 0 )
  {
LABEL_36:
    if ( v18 == 0 )
      D3DXShader::CProgram::Error(
        this,
        a2: nullptr,
        a3: 0x11ABu,
        format: "shader cannot compile to a ps_1_%i shader because this model can't match all the dependent texture read(s) this shader requires",
        (unsigned __int8)*((_DWORD *)this + 50));
  }
  return matched;
}

//------------------------------------------------------------------------------
// Address: 0x1020C88E
// Name: protected: long D3DXShader::CPSLegacyProgram::EmitPhase(class D3DXShader::CInstruction __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EmitPhase(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3)
{
  unsigned int i; // ebx
  struct D3DXShader::CInstruction *v5; // eax
  int v6; // eax
  int *v7; // edi
  int v8; // ecx
  int v9; // edx
  void *v10; // eax
  int result; // eax
  int v12; // ecx
  int v13; // eax
  _DWORD *v14; // ecx
  _DWORD *v15; // eax
  int v16; // edi
  int v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  bool v21; // zf

  for ( i = 0; i < a3; ++i )
  {
    *((_DWORD *)this + 63) = i;
    v5 = a2[i];
    *((_DWORD *)this + 64) = v5;
    if ( v5 == nullptr )
      continue;
    v6 = *((_DWORD *)v5 + 15);
    if ( v6 != 0 && *(_DWORD *)(v6 + 4) == 13 )
      *((_DWORD *)this + 65) = v6 + 48;
    v7 = *((int **)this + 64);
    v8 = *v7;
    if ( *v7 == 0 )
      continue;
    v9 = *((_DWORD *)this + 5);
    if ( *(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)v7[2]) + 8) != -1 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x119Fu,
        format: "relative addressing not allowed for pixel shaders");
      return -2147467259;
    }
    v10 = (void *)(v8 & 0xFFF00000);
    if ( (v8 & 0xFFF00000) > 0x70300000 )
    {
      if ( (unsigned int)v10 > 0x72600000 )
      {
        if ( v10 == (void *)1919942656 )
        {
          result = D3DXShader::CPSLegacyProgram::EmitSpecialTex(this, a2: 0x45u);
        }
        else if ( v10 == (void *)1920991232 )
        {
          result = D3DXShader::CPSLegacyProgram::EmitSpecialTex(this, a2: 0x46u);
        }
        else if ( v10 == (void *)1922039808 )
        {
          result = D3DXShader::CPSLegacyProgram::EmitSpecialTex(this, a2: 0x4Du);
        }
        else if ( v10 == (void *)1923088384 )
        {
          result = D3DXShader::CPSLegacyProgram::EmitSpecialTex(this, a2: 0x4Cu);
        }
        else if ( v10 == (void *)1924136960 )
        {
          result = D3DXShader::CPSLegacyProgram::EmitSpecialTex(this, a2: 0x53u);
        }
        else
        {
          if ( v10 != (void *)1927282688 )
            goto LABEL_90;
          result = D3DXShader::CPSLegacyProgram::EmitTEXLDPR(this);
        }
        goto LABEL_84;
      }
      if ( v10 == (void *)1918894080 )
      {
        result = D3DXShader::CPSLegacyProgram::EmitSpecialTex(this, a2: 0x52u);
        goto LABEL_84;
      }
      if ( v10 != (void *)1883242496 )
      {
        if ( v10 == (void *)1894776832 )
        {
          result = D3DXShader::CShaderProgram::EmitCND(this);
        }
        else if ( v10 == (void *)1913651200 )
        {
          result = D3DXShader::CPSLegacyProgram::EmitTEXCRD(this);
        }
        else if ( v10 == (void *)1914699776 )
        {
          result = D3DXShader::CPSLegacyProgram::EmitSpecialTex(this, a2: 0x47u);
        }
        else if ( v10 == (void *)1915748352 )
        {
          result = D3DXShader::CPSLegacyProgram::EmitSpecialTex(this, a2: 0x48u);
        }
        else if ( v10 == (void *)1916796928 )
        {
          result = D3DXShader::CPSLegacyProgram::EmitSpecialTex(this, a2: 0x49u);
        }
        else
        {
          if ( v10 != (void *)1917845504 )
            goto LABEL_90;
          result = D3DXShader::CPSLegacyProgram::EmitSpecialTex(this, a2: 0x4Au);
        }
        goto LABEL_84;
      }
LABEL_70:
      result = D3DXShader::CShaderProgram::EmitMAD(this);
      goto LABEL_84;
    }
    if ( (v8 & 0xFFF00000) == 0x70300000 )
      goto LABEL_70;
    if ( (unsigned int)v10 > 0x50000000 )
    {
      if ( v10 == (void *)1610612736 || v10 == (void *)1615855616 )
        goto LABEL_54;
      if ( v10 != (void *)1617952768 )
      {
        if ( v10 != (void *)1621098496 && v10 != (void *)1626341376 )
        {
          if ( v10 != (void *)1880096768 )
            goto LABEL_90;
          result = D3DXShader::CShaderProgram::EmitLRP(this);
          goto LABEL_84;
        }
LABEL_54:
        result = D3DXShader::CPSLegacyProgram::EmitTEXLDD(this);
        goto LABEL_84;
      }
      result = D3DXShader::CPSLegacyProgram::EmitTEXLDPT(this);
    }
    else
    {
      if ( v10 == (void *)1342177280 )
      {
        v12 = v8 & 0xFFFFF;
        if ( v12 == 2 )
          goto LABEL_90;
        if ( v12 != 4 || (unsigned __int16)*((_DWORD *)this + 50) != 257 )
        {
          v13 = (unsigned __int16)*((_DWORD *)this + 50);
          if ( v13 != 258 && v13 != 259 || v12 != 4 )
          {
LABEL_93:
            result = D3DXShader::CShaderProgram::EmitDOT(this);
            goto LABEL_84;
          }
          v14 = *(_DWORD **)(v9 + 4 * *(_DWORD *)v7[4]);
          v15 = (_DWORD *)v7[2];
          v16 = *(_DWORD *)(v9 + 4 * *v15);
          v17 = *(_DWORD *)(v9 + 4 * v15[4]);
          v18 = v14[1];
          if ( v18 == *((_DWORD *)this + 33) )
          {
            v19 = *((_DWORD *)this + 34);
            v20 = (unsigned __int8)v14[27];
            if ( (*(_DWORD *)(v16 + 4) != v19 || *(_DWORD *)(v16 + 12) != 0)
              && (*(_DWORD *)(v17 + 4) != v19 || *(_DWORD *)(v17 + 12) != 0) )
            {
              goto LABEL_93;
            }
            v21 = v20 == 1;
LABEL_43:
            if ( !v21 )
              goto LABEL_93;
          }
          else if ( *(_DWORD *)(v16 + 4) != v18 || *(_DWORD *)(v16 + 12) != v14[3] )
          {
            if ( *(_DWORD *)(v17 + 4) != v18 )
              goto LABEL_93;
            v21 = *(_DWORD *)(v17 + 12) == v14[3];
            goto LABEL_43;
          }
        }
        result = D3DXShader::CPSLegacyProgram::EmitDP4(this);
        goto LABEL_84;
      }
      if ( v10 == nullptr )
        continue;
      if ( v10 == (void *)0x10000000 )
      {
        result = D3DXShader::CShaderProgram::EmitMOV(this);
      }
      else if ( v10 == &loc_10100000 )
      {
        result = D3DXShader::CShaderProgram::EmitNEG(this);
      }
      else if ( v10 == (void *)285212672 )
      {
        result = D3DXShader::CShaderProgram::EmitCLIP(this);
      }
      else if ( v10 == (void *)541065216 )
      {
        result = D3DXShader::CShaderProgram::EmitADD(this);
      }
      else if ( v10 == (void *)542113792 )
      {
        result = D3DXShader::CShaderProgram::EmitMUL(this);
      }
      else
      {
        if ( v10 != (void *)805306368 )
          goto LABEL_90;
        if ( (unsigned __int16)*((_DWORD *)this + 50) == 260 )
          result = D3DXShader::CShaderProgram::EmitCMP(this);
        else
          result = -2147467263;
      }
    }
LABEL_84:
    if ( result == -2147467263 )
    {
LABEL_90:
      D3DXShader::CProgram::Error(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x11B4u,
        format: "cannot map expression to pixel shader instruction set");
      return -2147467263;
    }
    if ( result < 0 )
      return result;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020CBF1
// Name: protected: virtual long D3DXShader::CPSLegacyProgram::EmitInstructions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EmitInstructions(D3DXShader::CPSLegacyProgram *this)
{
  struct D3DXShader::CInstruction **v2; // ecx
  int result; // eax

  v2 = *((struct D3DXShader::CInstruction ***)this + 139);
  if ( v2 == nullptr || *((_DWORD *)this + 136) == 0 )
    return D3DXShader::CPSLegacyProgram::EmitPhase(
             this,
             a2: *((struct D3DXShader::CInstruction ***)this + 140),
             a3: *((_DWORD *)this + 137));
  if ( (unsigned __int16)*((_DWORD *)this + 50) != 260 )
    return -2147467259;
  D3DXShader::CPSLegacyProgram::EmitPhase(this, a2: v2, a3: *((_DWORD *)this + 136));
  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0xFFFDu);
  if ( result >= 0 )
  {
    result = D3DXShader::CShaderProgram::ValidateInst(this);
    if ( result >= 0 )
      return D3DXShader::CPSLegacyProgram::EmitPhase(
               this,
               a2: *((struct D3DXShader::CInstruction ***)this + 140),
               a3: *((_DWORD *)this + 137));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020CC7F
// Name: protected: virtual long D3DXShader::CPSLegacyProgram::PatternMatch(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::PatternMatch(D3DXShader::CPSLegacyProgram *this)
{
  unsigned int v2; // ebx
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  _DWORD *v6; // eax
  signed int matched; // edi
  bool v8; // zf
  _DWORD *v9; // eax
  _DWORD *v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // eax
  unsigned int v14; // ecx
  unsigned int i; // ecx
  int v16; // eax
  int v17; // eax
  unsigned int j; // ecx
  int v19; // eax
  _DWORD *v20; // eax
  unsigned int v21; // edx
  unsigned int v22; // edx
  int v23; // ebx
  int v24; // eax
  _DWORD *v25; // eax
  unsigned int v26; // eax
  int v27; // ebx
  int v28; // eax
  _DWORD *v29; // eax
  void *v30; // eax
  int fixed; // eax
  int v32; // ebx
  int v33; // eax
  _DWORD *v34; // eax
  void *v35; // eax
  int v36; // eax
  int v37; // ebx
  int v38; // eax
  _DWORD *v39; // eax
  unsigned int v40; // eax
  int v41; // ebx
  int v42; // eax
  _DWORD *v43; // eax
  int v44; // ebx
  int v45; // eax
  _DWORD *v46; // eax
  int v47; // ebx
  int v48; // eax
  _DWORD *v49; // eax
  int v50; // ebx
  int v51; // eax
  int v52; // eax
  void *v53; // eax
  void *v54; // eax
  void *v56; // edi
  unsigned int *v57; // edi
  unsigned int v58; // eax
  int v59; // eax
  bool v60; // cf
  D3DXShader::CInstruction **v61; // edi
  int v62; // eax
  _DWORD *v63; // eax
  int v64; // ecx
  int v65; // edx
  int v66; // ecx
  unsigned int v67; // edi
  unsigned int v68; // eax
  D3DXShader::CInstruction **v69; // edi
  _DWORD *v70; // eax
  unsigned int jj; // ecx
  D3DXShader::CPSLegacyProgram *v72; // ecx
  struct D3DXShader::CNode *v73; // [esp-8h] [ebp-3Ch]
  unsigned int v74; // [esp+0h] [ebp-34h]
  int v75; // [esp+4h] [ebp-30h]
  const char *v76; // [esp+4h] [ebp-30h]
  unsigned int v77; // [esp+14h] [ebp-20h]
  unsigned int v78; // [esp+14h] [ebp-20h]
  int ii; // [esp+14h] [ebp-20h]
  unsigned int v80; // [esp+18h] [ebp-1Ch]
  unsigned int v81; // [esp+1Ch] [ebp-18h] BYREF
  unsigned int n; // [esp+20h] [ebp-14h]
  unsigned int v83; // [esp+24h] [ebp-10h]
  unsigned int v84; // [esp+28h] [ebp-Ch] BYREF
  unsigned int m; // [esp+2Ch] [ebp-8h]
  unsigned int k; // [esp+30h] [ebp-4h]

  v2 = D3DXShader::CBaseProgram::AddPool(
         this,
         a2: (char *)&stru_102A6BD8.m_Memory.m_nGrowSize,
         a3: 0x311u,
         a4: 1u,
         a5: 4u);
  *((_DWORD *)this + 272) = D3DXShader::CBaseProgram::AddArgument(this, a2: v2, a3: 0, a4: 0, a5: 0.0);
  *((_DWORD *)this + 273) = D3DXShader::CBaseProgram::AddArgument(this, a2: v2, a3: 0, a4: 1u, a5: 1.0);
  v3 = (unsigned __int16)*((_DWORD *)this + 50);
  *((_DWORD *)this + 275) = 0;
  if ( v3 == 260 )
  {
    v4 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      do
      {
        v5 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v4;
        v6 = *(_DWORD **)(v5 + 4 * v4);
        *((_DWORD *)this + 64) = v6;
        if ( (*v6 & 0xFFF00000) == 0x60700000 )
        {
          matched = D3DXShader::CPSLegacyProgram::MatchTexldPR(this);
          if ( matched < 0 )
            return matched;
        }
      }
      while ( (unsigned int)++v4 < *((_DWORD *)this + 3) );
    }
    D3DXShader::CShaderProgram::Reset(this);
    D3DXShader::CProgram::RemoveDeadCode(this);
  }
  v8 = *((_DWORD *)this + 3) == 0;
  v84 = 0;
  m = 0;
  if ( !v8 )
  {
    do
    {
      v9 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * m);
      *((_DWORD *)this + 64) = v9;
      v8 = v9[1] == 0;
      k = 0;
      if ( !v8 )
      {
        v10 = (_DWORD *)v9[2];
        while ( 1 )
        {
          v11 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v10);
          v12 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v11 + 4)) + 4);
          if ( (v12 & 0x10) != 0
            && (v12 & 0x200) == 0
            && *(_DWORD *)(v11 + 16) == 3
            && *(_BYTE *)(v11 + 108) == 3
            && ((*v9 & 0xFFF00000) != 0x60700000 || k != 7) )
          {
            break;
          }
          ++k;
          ++v10;
          if ( k >= *(_DWORD *)(*((_DWORD *)this + 64) + 4) )
            goto LABEL_19;
        }
        v75 = (unsigned __int8)*((_DWORD *)this + 50);
        v73 = (struct D3DXShader::CNode *)v9[15];
        v84 = 1;
        D3DXShader::CProgram::Error(
          this,
          a2: v73,
          a3: 0x11A0u,
          format: "cannot access texture coordinate w-component in a general way in ps_1_%i",
          v75);
      }
LABEL_19:
      v13 = *((_DWORD *)this + 64);
      v14 = *(_DWORD *)v13 & 0xFFF00000;
      if ( v14 == 1616904192 || v14 == 1622147072 || v14 == 1611661312 || v14 == 1627389952 )
      {
        D3DXShader::CProgram::Error(
          this,
          a2: *(struct D3DXShader::CNode **)(v13 + 60),
          a3: 0x11B4u,
          format: "cannot map expression to pixel shader instruction set");
        v84 = 1;
      }
      ++m;
    }
    while ( m < *((_DWORD *)this + 3) );
    if ( v84 != 0 )
      return -2147467259;
  }
  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * i) + 56) = -1;
    v16 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * i);
    if ( *(_DWORD *)(v16 + 4) == *((_DWORD *)this + 32) )
    {
      if ( *(_BYTE *)(v16 + 108) == 1 )
        *(_DWORD *)v16 = 20;
      if ( (unsigned __int16)*((_DWORD *)this + 50) < 0x104u )
      {
        v17 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * i);
        if ( *(_BYTE *)(v17 + 108) == 3 )
          *(_DWORD *)v17 = 20;
      }
    }
  }
  for ( j = 0; j < *((_DWORD *)this + 3); *(_DWORD *)(*((_DWORD *)this + 64) + 36) = 0 )
  {
    v19 = *((_DWORD *)this + 6);
    *((_DWORD *)this + 63) = j;
    v20 = *(_DWORD **)(v19 + 4 * j);
    *((_DWORD *)this + 64) = v20;
    v21 = *v20 & 0xFFF00000;
    if ( v21 == 1610612736 || v21 == 1615855616 || v21 == 1621098496 || v21 == 1626341376 )
    {
      v22 = 0;
      if ( v20[3] != 0 )
      {
        do
          **(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 16) + 4 * v22++)) = 20;
        while ( v22 < *(_DWORD *)(*((_DWORD *)this + 64) + 12) );
      }
    }
    ++j;
  }
  v23 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    do
    {
      v24 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v23;
      v25 = *(_DWORD **)(v24 + 4 * v23);
      *((_DWORD *)this + 64) = v25;
      v26 = *v25 & 0xFFF00000;
      if ( v26 == 0x20000000 || v26 == 537919488 || v26 == 805306368 )
      {
        matched = D3DXShader::CShaderProgram::MatchSatModifier(this);
        if ( matched < 0 )
          return matched;
      }
    }
    while ( (unsigned int)++v23 < *((_DWORD *)this + 3) );
  }
  v27 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    while ( 1 )
    {
      v28 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v27;
      v29 = *(_DWORD **)(v28 + 4 * v27);
      *((_DWORD *)this + 64) = v29;
      v30 = (void *)(*v29 & 0xFFF00000);
      if ( v30 == (void *)0x10000000 )
        break;
      if ( v30 == &loc_10100000 )
      {
        fixed = D3DXShader::CPSLegacyProgram::FixNeg(this);
        goto LABEL_54;
      }
LABEL_55:
      if ( (unsigned int)++v27 >= *((_DWORD *)this + 3) )
        goto LABEL_56;
    }
    fixed = D3DXShader::CPSLegacyProgram::FixSatTex(this);
LABEL_54:
    matched = fixed;
    if ( fixed < 0 )
      return matched;
    goto LABEL_55;
  }
LABEL_56:
  D3DXShader::CShaderProgram::Reset(this);
  v32 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    while ( 1 )
    {
      v33 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v32;
      v34 = *(_DWORD **)(v33 + 4 * v32);
      *((_DWORD *)this + 64) = v34;
      v35 = (void *)(*v34 & 0xFFF00000);
      if ( v35 == &loc_10100000 )
        break;
      if ( v35 == (void *)541065216 )
      {
        D3DXShader::CShaderProgram::MatchComplexBX2(this);
        D3DXShader::CShaderProgram::MatchBiasModifier(this);
        D3DXShader::CShaderProgram::MatchCompModifier(this, a2: nullptr);
        v36 = D3DXShader::CShaderProgram::MatchX2Modifier(this);
        goto LABEL_66;
      }
      if ( v35 == (void *)542113792 )
      {
        D3DXShader::CShaderProgram::MatchX2Modifier(this);
        goto LABEL_65;
      }
      if ( v35 == (void *)1342177280 )
      {
        v36 = D3DXShader::CShaderProgram::MatchRepMov(this);
        goto LABEL_66;
      }
LABEL_67:
      if ( (unsigned int)++v32 >= *((_DWORD *)this + 3) )
        goto LABEL_68;
    }
    D3DXShader::CShaderProgram::MatchNEG(this, a2: 0);
LABEL_65:
    v36 = D3DXShader::CShaderProgram::MatchComplexComp(this);
LABEL_66:
    matched = v36;
    if ( v36 < 0 )
      return matched;
    goto LABEL_67;
  }
LABEL_68:
  D3DXShader::CShaderProgram::Reset(this);
  v37 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    do
    {
      v38 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v37;
      v39 = *(_DWORD **)(v38 + 4 * v37);
      *((_DWORD *)this + 64) = v39;
      v40 = *v39 & 0xFFF00000;
      if ( v40 == 541065216 || v40 == 542113792 )
      {
        matched = D3DXShader::CPSLegacyProgram::MatchOutputModifier(this);
        if ( matched < 0 )
          return matched;
      }
    }
    while ( (unsigned int)++v37 < *((_DWORD *)this + 3) );
  }
  D3DXShader::CShaderProgram::Reset(this);
  v41 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    do
    {
      v42 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v41;
      v43 = *(_DWORD **)(v42 + 4 * v41);
      *((_DWORD *)this + 64) = v43;
      if ( (*v43 & 0xFFF00000) == 0x60F00000 )
      {
        matched = D3DXShader::CPSLegacyProgram::MatchTexReflect(this, a2: 1);
        if ( matched < 0 )
          return matched;
        matched = D3DXShader::CPSLegacyProgram::MatchTexReflect(this, a2: 0);
        if ( matched < 0 )
          return matched;
      }
    }
    while ( (unsigned int)++v41 < *((_DWORD *)this + 3) );
  }
  D3DXShader::CShaderProgram::Reset(this);
  v44 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    do
    {
      v45 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v44;
      v46 = *(_DWORD **)(v45 + 4 * v44);
      *((_DWORD *)this + 64) = v46;
      if ( (*v46 & 0xFFF00000) == 0x20400000 )
      {
        matched = D3DXShader::CPSLegacyProgram::MatchComplexAdd(this);
        if ( matched < 0 )
          return matched;
      }
    }
    while ( (unsigned int)++v44 < *((_DWORD *)this + 3) );
  }
  D3DXShader::CShaderProgram::Reset(this);
  v47 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    do
    {
      v48 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v47;
      v49 = *(_DWORD **)(v48 + 4 * v47);
      *((_DWORD *)this + 64) = v49;
      if ( (*v49 & 0xFFF00000) == 0x70300000 )
      {
        D3DXShader::CShaderProgram::MatchLRP(this);
        matched = D3DXShader::CShaderProgram::MatchLRP2((struct D3DXShader::CInstruction **)this, a2: 0);
        if ( matched < 0 )
          return matched;
      }
    }
    while ( (unsigned int)++v47 < *((_DWORD *)this + 3) );
  }
  v50 = 0;
  v77 = *((_DWORD *)this + 3);
  if ( v77 != 0 )
  {
    do
    {
      v51 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v50;
      *((_DWORD *)this + 64) = *(_DWORD *)(v51 + 4 * v50);
      matched = D3DXShader::CPSLegacyProgram::DeSwizzle(this);
      if ( matched < 0 )
        return matched;
    }
    while ( ++v50 < v77 );
  }
  D3DXShader::CShaderProgram::Reset(this);
  matched = D3DXShader::CShaderProgram::Reschedule(this);
  if ( matched >= 0 )
  {
    matched = D3DXShader::CPSLegacyProgram::ValidateInstructions(this);
    if ( matched >= 0 )
    {
      matched = D3DXShader::CPSLegacyProgram::CheckDegenShader(this);
      if ( matched >= 0 )
      {
        v52 = *((_DWORD *)this + 50);
        if ( (unsigned __int16)v52 != 260 )
        {
          if ( *((_DWORD *)this + 3) <= 0x80u )
          {
            matched = D3DXShader::CPSLegacyProgram::GroupTexLoads(this);
            if ( matched < 0 )
              return matched;
            if ( *((_DWORD *)this + 139) != 0 )
            {
              matched = D3DXShader::CPSLegacyProgram::MovConsts(this);
              if ( matched < 0 )
                return matched;
              if ( *((_DWORD *)this + 139) != 0 && (unsigned __int16)*((_DWORD *)this + 50) != 260 )
              {
                matched = D3DXShader::CPSLegacyProgram::MatchPhase1(this);
                if ( matched < 0 )
                  return matched;
              }
            }
            if ( *((_DWORD *)this + 140) != 0 && (unsigned __int16)*((_DWORD *)this + 50) != 260 )
            {
              matched = D3DXShader::CPSLegacyProgram::EmmulateReplicate(this);
              if ( matched < 0 )
                return matched;
              matched = D3DXShader::CPSLegacyProgram::EmmulateWriteMasksX(this);
              if ( matched < 0 )
                return matched;
              matched = D3DXShader::CPSLegacyProgram::FixPortConstraintsAndFixCMP(this);
              if ( matched < 0 )
                return matched;
            }
            *((_DWORD *)this + 55) = 0;
            matched = D3DXShader::CPSLegacyProgram::AllocateRegisters(this, a2: 0, a3: 0);
            if ( matched < 0 )
              return matched;
            goto LABEL_162;
          }
          D3DXShader::CProgram::Error(
            this,
            a2: nullptr,
            a3: 0x1194u,
            format: "program is order of magnitude too large to compile to ps_1_%i",
            (unsigned __int8)v52);
          return -2147467259;
        }
        v53 = MemAlloc_Alloc(nSize: 0x800u);
        *((_DWORD *)this + 139) = v53;
        if ( v53 == nullptr )
          return -2147024882;
        v54 = MemAlloc_Alloc(nSize: 0x800u);
        *((_DWORD *)this + 140) = v54;
        if ( v54 == nullptr )
          return -2147024882;
        v56 = *((void **)this + 139);
        *((_DWORD *)this + 137) = 0;
        *((_DWORD *)this + 136) = 0;
        memset(v56, 0, 0x800u);
        memset(*((void **)this + 140), 0, 0x800u);
        matched = D3DXShader::CPSLegacyProgram::CreateTexLoads(this);
        if ( matched >= 0 )
        {
          matched = D3DXShader::CPSLegacyProgram::SetupDependency(this, a2: matched);
          if ( matched >= 0 )
          {
            if ( D3DXShader::CPSLegacyProgram::TrivialReject(this) == 0 )
            {
              v78 = D3DXShader::CPSLegacyProgram::EnumerateCombos(this);
              if ( v78 == -1 )
              {
                v76 = "shader too complex. Try reducing number of texture loads used";
LABEL_101:
                matched = -2147467259;
                D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x1194u, format: v76);
                return matched;
              }
              D3DXShader::CPSLegacyProgram::Save(this);
              v84 = 0;
              v57 = (unsigned int *)((char *)this + 772);
              do
              {
                v58 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: 0, a4: 0, a5: 0.0);
                *v57 = v58;
                if ( v58 == -1 )
                  return -2147024882;
                v59 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v58);
                ++v84;
                ++v57;
                v60 = v84 < 0x40;
                *(_DWORD *)(v59 + 60) = 0;
              }
              while ( v60 );
              v83 = -1;
              v80 = -1;
              memset((char *)this + 708, 0, 0x40u);
              for ( k = 0; k < v78; ++k )
              {
                memset(*((void **)this + 139), 0, 0x800u);
                memset(*((void **)this + 140), 0, 0x800u);
                v74 = k;
                *((_DWORD *)this + 136) = 0;
                *((_DWORD *)this + 137) = 0;
                if ( D3DXShader::CPSLegacyProgram::InitialCluster(this, a2: v74, a3: 1) != 0 )
                {
                  *((_DWORD *)this + 258) = 0;
                  *((_DWORD *)this + 257) = 0;
                  D3DXShader::CPSLegacyProgram::Restore(this);
                  D3DXShader::CPSLegacyProgram::MarkCoIssues(
                    this,
                    a2: *((struct D3DXShader::CInstruction ***)this + 139),
                    a3: 6u,
                    a4: *((_DWORD *)this + 136),
                    a5: &v81);
                  D3DXShader::CPSLegacyProgram::MarkCoIssues(
                    this,
                    a2: *((struct D3DXShader::CInstruction ***)this + 140),
                    a3: 6u,
                    a4: *((_DWORD *)this + 137),
                    a5: &v84);
                  v61 = (D3DXShader::CInstruction **)((char *)this + 708);
                  for ( m = 16; m != 0; --m )
                  {
                    if ( *v61 != nullptr )
                      D3DXShader::CInstruction::`scalar deleting destructor'(this: *v61, a2: 1);
                    *v61++ = nullptr;
                  }
                  v62 = D3DXShader::CPSLegacyProgram::GreedyPullUp(this);
                  matched = v62;
                  if ( v62 < 0 )
                    return matched;
                  if ( v62 != 1
                    && D3DXShader::CPSLegacyProgram::AddPhaseLinkage(this, a2: nullptr) >= 0
                    && D3DXShader::CPSLegacyProgram::AllocateRegisters(this, a2: 1, a3: 1) >= 0 )
                  {
                    D3DXShader::CPSLegacyProgram::MarkCoIssues(
                      this,
                      a2: *((struct D3DXShader::CInstruction ***)this + 139),
                      a3: 6u,
                      a4: *((_DWORD *)this + 136),
                      a5: &v81);
                    D3DXShader::CPSLegacyProgram::MarkCoIssues(
                      this,
                      a2: *((struct D3DXShader::CInstruction ***)this + 140),
                      a3: 6u,
                      a4: *((_DWORD *)this + 137),
                      a5: &v84);
                    v63 = *((_DWORD **)this + 140);
                    v64 = *((_DWORD *)this + 139);
                    v65 = 0;
                    m = 0;
                    v66 = v64 - (_DWORD)v63;
                    for ( n = 6; n != 0; --n )
                    {
                      if ( *(_DWORD *)((char *)v63 + v66) != 0 )
                        ++v65;
                      if ( *v63 != 0 )
                        ++m;
                      ++v63;
                    }
                    n = v81;
                    if ( v81 <= 2 * v65 )
                      n = 2 * v65;
                    v67 = v84;
                    if ( v84 <= 2 * m )
                      v67 = 2 * m;
                    v68 = n + v67 + (v65 + v81 != 0 ? 0xA : 0);
                    if ( v81 > 8 )
                      v68 += 20;
                    if ( v84 > 8 )
                      v68 += 20;
                    if ( v68 < v80 )
                    {
                      v83 = k;
                      v80 = v68;
                    }
                    *((_DWORD *)this + 257) = 0;
                  }
                }
              }
              memset(*((void **)this + 139), 0, 0x800u);
              memset(*((void **)this + 140), 0, 0x800u);
              *((_DWORD *)this + 136) = 0;
              *((_DWORD *)this + 137) = 0;
              v69 = (D3DXShader::CInstruction **)((char *)this + 708);
              for ( ii = 12; ii != 0; --ii )
              {
                if ( *v69 != nullptr )
                  D3DXShader::CInstruction::`scalar deleting destructor'(this: *v69, a2: 1);
                *v69++ = nullptr;
              }
              if ( v83 == -1 )
              {
                v76 = "program too complex to compile to ps_1_4";
                goto LABEL_101;
              }
              D3DXShader::CPSLegacyProgram::InitialCluster(this, a2: v83, a3: 0);
              D3DXShader::CPSLegacyProgram::Restore(this);
              D3DXShader::CPSLegacyProgram::GreedyPullUp(this);
              matched = D3DXShader::CPSLegacyProgram::AddPhaseLinkage(this, a2: nullptr);
              if ( matched < 0 )
                return matched;
              matched = D3DXShader::CPSLegacyProgram::AllocateRegisters(this, a2: 0, a3: 0);
              if ( matched < 0 )
                return matched;
              v70 = *((_DWORD **)this + 139);
              for ( jj = 0; jj < 6; ++jj )
              {
                if ( *v70 != 0 )
                  break;
                ++v70;
              }
              if ( *((_DWORD *)this + 136) == 6 && jj == 6 )
                *((_DWORD *)this + 136) = 0;
LABEL_162:
              *((_DWORD *)this + 55) = 1;
              matched = D3DXShader::CPSLegacyProgram::RemapConstants(this);
              if ( matched >= 0 )
              {
                matched = D3DXShader::CPSLegacyProgram::MarkCoIssues(
                            this,
                            a2: *((struct D3DXShader::CInstruction ***)this + 139),
                            a3: 0,
                            a4: *((_DWORD *)this + 136),
                            a5: nullptr);
                if ( matched >= 0 )
                {
                  matched = D3DXShader::CPSLegacyProgram::MarkCoIssues(
                              this,
                              a2: *((struct D3DXShader::CInstruction ***)this + 140),
                              a3: 0,
                              a4: *((_DWORD *)this + 137),
                              a5: nullptr);
                  if ( matched >= 0 )
                  {
                    matched = D3DXShader::CPSLegacyProgram::PackOutput(this);
                    if ( matched >= 0 )
                    {
                      if ( *((_DWORD *)this + 140) == 0 )
                        return 0;
                      if ( (unsigned __int16)*((_DWORD *)this + 50) == 260 )
                        return 0;
                      matched = D3DXShader::CPSLegacyProgram::ValidateTexSat(this: v72);
                      if ( matched >= 0 )
                        return 0;
                    }
                  }
                }
              }
              return matched;
            }
            return -2147467259;
          }
        }
      }
    }
  }
  return matched;
}

//------------------------------------------------------------------------------
// Address: 0x1020D722
// Name: public: D3DXShader::CPSProgram::CPSProgram(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CPSProgram *__thiscall D3DXShader::CPSProgram::CPSProgram(D3DXShader::CPSProgram *this, int a2)
{
  D3DXShader::CShaderProgram::CShaderProgram(this);
  *((_DWORD *)this + 138) = 0;
  *((_DWORD *)this + 86) = a2;
  *(_DWORD *)this = &D3DXShader::CPSProgram::`vftable';
  *((_DWORD *)this + 61) = &D3DXShader::g_20InputOutput;
  *((_DWORD *)this + 62) = &D3DXShader::g_20PSOutput;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020D760
// Name: public: virtual long D3DXShader::CPSProgram::GenerateCode(struct ID3DXBuffer __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::GenerateCode(D3DXShader::CPSProgram *this, struct ID3DXBuffer **a2)
{
  memset((char *)this + 504, 0, 0x20u);
  *((_DWORD *)this + 134) = 0;
  *((_DWORD *)this + 135) = 0;
  return D3DXShader::CShaderProgram::GenerateCode(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1020D786
// Name: protected: virtual long D3DXShader::CPSProgram::InitCaps(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::InitCaps(D3DXShader::CPSProgram *this)
{
  int v1; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  int v5; // eax

  v1 = *((_DWORD *)this + 50);
  *((_DWORD *)this + 66) = v1;
  switch ( v1 )
  {
    case -65024:
      *((_DWORD *)this + 11) = 12;
      goto LABEL_10;
    case -65022:
      v4 = *((_DWORD *)this + 28) & 0xFFFFFFCE | 0x11;
      *((_DWORD *)this + 27) |= 0x48000100u;
      *((_DWORD *)this + 11) = 22;
      *((_DWORD *)this + 28) = v4;
      *((_DWORD *)this + 50) = -65023;
      goto LABEL_11;
    case -65021:
      *((_DWORD *)this + 11) = 32;
      *((_DWORD *)this + 50) = -65023;
LABEL_10:
      *((_DWORD *)this + 28) |= 0xAu;
      *((_DWORD *)this + 27) |= 0x4000102u;
      goto LABEL_11;
    default:
      break;
  }
  if ( v1 != -64769 )
  {
    D3DXShader::CProgram::Error(
      this,
      a2: nullptr,
      a3: 0,
      format: "internal error: no profile exists for this pixel shader version");
    return -2147467259;
  }
  v3 = *((_DWORD *)this + 28) & 0xFFFFFFCF | 0x10;
  *((_DWORD *)this + 27) |= 0x40000100u;
  *((_DWORD *)this + 11) = 32;
  *((_DWORD *)this + 24) = 2048;
  *((_DWORD *)this + 28) = v3;
LABEL_11:
  v5 = *((_DWORD *)this + 11);
  *((_DWORD *)this + 27) |= 0x2000A1u;
  *((_DWORD *)this + 116) = v5;
  *((_DWORD *)this + 10) = 2;
  *((_DWORD *)this + 17) = 10;
  *((_DWORD *)this + 14) = 0x2000;
  *((_DWORD *)this + 18) = 4;
  *((_DWORD *)this + 19) = 16;
  *((_DWORD *)this + 25) = 1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020D873
// Name: protected: virtual long D3DXShader::CPSProgram::Translate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::Translate(D3DXShader::CPSProgram *this)
{
  unsigned int v2; // edi
  int v3; // eax
  _DWORD *v4; // eax
  int v5; // ebx
  int v6; // eax
  _DWORD *v7; // eax
  void *v8; // eax
  int matched; // edi
  unsigned int i; // ebx
  int v11; // eax
  _DWORD *v12; // eax
  int v13; // ebx
  int v14; // eax
  _DWORD *v15; // eax
  unsigned int v16; // eax
  int v17; // ebx
  int v18; // eax
  _DWORD *v19; // eax
  unsigned int v20; // eax
  int v21; // eax
  int v22; // ebx
  int v23; // eax
  _DWORD *v24; // eax
  unsigned int v25; // eax
  int v26; // eax
  unsigned int j; // edi
  int v28; // eax
  _DWORD *v29; // eax
  int v30; // ebx
  int v31; // eax
  _DWORD *v32; // eax
  unsigned int v33; // eax
  int v34; // eax
  int v35; // ebx
  int v36; // eax
  _DWORD *v37; // eax
  int v39; // [esp+Ch] [ebp-4h]

  v2 = 0;
  if ( (*((_BYTE *)this + 204) & 4) != 0 )
  {
    D3DXShader::CProgram::IdentityRemap(this);
    if ( *((_DWORD *)this + 3) != 0 )
    {
      do
      {
        v3 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v2;
        v4 = *(_DWORD **)(v3 + 4 * v2);
        *((_DWORD *)this + 64) = v4;
        if ( (*v4 & 0xFFF00000) == 0x10000000 )
          D3DXShader::CShaderProgram::RemapSamplerMove(this);
        ++v2;
      }
      while ( v2 < *((_DWORD *)this + 3) );
    }
    D3DXShader::CProgram::RemapArguments(this);
    if ( (*((_BYTE *)this + 204) & 4) != 0 )
      goto LABEL_72;
  }
  v5 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    while ( 1 )
    {
      v6 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v5;
      v7 = *(_DWORD **)(v6 + 4 * v5);
      *((_DWORD *)this + 64) = v7;
      v8 = (void *)(*v7 & 0xFFF00000);
      if ( v8 == &loc_10100000 )
        break;
      if ( v8 == (void *)0x20000000 || v8 == (void *)537919488 || v8 == (void *)805306368 )
      {
        matched = D3DXShader::CShaderProgram::MatchSatModifier(this);
        D3DXShader::CShaderProgram::Reset(this);
        goto LABEL_15;
      }
      matched = 1;
LABEL_16:
      if ( (unsigned int)++v5 >= *((_DWORD *)this + 3) )
        goto LABEL_19;
    }
    matched = D3DXShader::CShaderProgram::MatchNEG(this, a2: 1);
LABEL_15:
    if ( matched < 0 )
      return matched;
    goto LABEL_16;
  }
  matched = v39;
LABEL_19:
  for ( i = 0; i < *((_DWORD *)this + 3); ++i )
  {
    v11 = *((_DWORD *)this + 6);
    *((_DWORD *)this + 63) = i;
    v12 = *(_DWORD **)(v11 + 4 * i);
    *((_DWORD *)this + 64) = v12;
    if ( (*v12 & 0xFFF00000) == 0x30000000 )
    {
      if ( matched < 0 )
        return matched;
      matched = D3DXShader::CShaderProgram::MatchMinMax(this, a2: nullptr, a3: nullptr, a4: nullptr);
      if ( matched < 0 )
        return matched;
      matched = D3DXShader::CShaderProgram::MatchMinMax2(this, a2: nullptr, a3: nullptr, a4: nullptr);
      if ( matched < 0 )
        return matched;
    }
    else
    {
      matched = 1;
    }
  }
  matched = D3DXShader::CProgram::RemoveDeadCode(this);
  if ( matched >= 0 )
  {
    D3DXShader::CShaderProgram::Reset(this);
    v13 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      do
      {
        v14 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v13;
        v15 = *(_DWORD **)(v14 + 4 * v13);
        *((_DWORD *)this + 64) = v15;
        v16 = *v15 & 0xFFF00000;
        if ( v16 == 0x20000000 || v16 == 1890582528 )
        {
          matched = D3DXShader::CShaderProgram::MatchSatModifier(this);
          D3DXShader::CShaderProgram::Reset(this);
          if ( matched < 0 )
            return matched;
        }
      }
      while ( (unsigned int)++v13 < *((_DWORD *)this + 3) );
    }
    v17 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      while ( 1 )
      {
        v18 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v17;
        v19 = *(_DWORD **)(v18 + 4 * v17);
        *((_DWORD *)this + 64) = v19;
        v20 = *v19 & 0xFFF00000;
        if ( v20 == 273678336 )
          break;
        if ( v20 == 284164096 )
        {
          v21 = D3DXShader::CShaderProgram::MatchIF(this);
          goto LABEL_43;
        }
        if ( v20 == 541065216 )
        {
          if ( D3DXShader::CShaderProgram::MatchDP2Add(this) != 0 )
          {
            v21 = D3DXShader::CShaderProgram::MatchComplexMad(this, a2: 1);
            goto LABEL_43;
          }
        }
        else if ( v20 == 805306368 && D3DXShader::CShaderProgram::MatchABS(this) != 0 )
        {
          v21 = D3DXShader::CShaderProgram::MatchABS2(this);
          goto LABEL_43;
        }
LABEL_44:
        if ( (unsigned int)++v17 >= *((_DWORD *)this + 3) )
          goto LABEL_45;
      }
      v21 = D3DXShader::CShaderProgram::MatchPOW(this);
LABEL_43:
      matched = v21;
      if ( v21 < 0 )
        return matched;
      goto LABEL_44;
    }
LABEL_45:
    matched = D3DXShader::CProgram::RemoveDeadCode(this);
    if ( matched < 0 )
      return matched;
    D3DXShader::CShaderProgram::Reset(this);
    v22 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      while ( 1 )
      {
        v23 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v22;
        v24 = *(_DWORD **)(v23 + 4 * v22);
        *((_DWORD *)this + 64) = v24;
        v25 = *v24 & 0xFFF00000;
        if ( v25 == 542113792 )
          break;
        switch ( v25 )
        {
          case 0x50000000u:
            v26 = D3DXShader::CShaderProgram::ConvertDP2(this);
            goto LABEL_56;
          case 0x70300000u:
            v26 = D3DXShader::CShaderProgram::MatchLRP2((struct D3DXShader::CInstruction **)this, a2: 0);
            goto LABEL_56;
          case 0x73500000u:
          case 0x73600000u:
            v26 = D3DXShader::CShaderProgram::MatchNEEQ(this);
            goto LABEL_56;
          default:
            break;
        }
LABEL_57:
        if ( (unsigned int)++v22 >= *((_DWORD *)this + 3) )
          goto LABEL_58;
      }
      v26 = D3DXShader::CShaderProgram::MatchNRM(this);
LABEL_56:
      matched = v26;
      if ( v26 < 0 )
        return matched;
      goto LABEL_57;
    }
LABEL_58:
    D3DXShader::CShaderProgram::Reset(this);
    for ( j = 0; j < *((_DWORD *)this + 3); ++j )
    {
      v28 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = j;
      v29 = *(_DWORD **)(v28 + 4 * j);
      *((_DWORD *)this + 64) = v29;
      if ( (*v29 & 0xFFF00000) == 0x70300000 )
        D3DXShader::CShaderProgram::MatchLRP(this);
    }
    D3DXShader::CShaderProgram::Reset(this);
    v30 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      while ( 1 )
      {
        v31 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v30;
        v32 = *(_DWORD **)(v31 + 4 * v30);
        *((_DWORD *)this + 64) = v32;
        v33 = *v32 & 0xFFF00000;
        if ( v33 == 1882193920 )
          break;
        if ( v33 == 1934622720 || v33 == 1935671296 || v33 == 1936719872 || v33 == 1937768448 )
        {
          v34 = D3DXShader::CShaderProgram::MatchIFCOND(this);
          goto LABEL_70;
        }
LABEL_71:
        if ( (unsigned int)++v30 >= *((_DWORD *)this + 3) )
          goto LABEL_72;
      }
      v34 = D3DXShader::CShaderProgram::MatchLRP2((struct D3DXShader::CInstruction **)this, a2: 0);
LABEL_70:
      matched = v34;
      if ( v34 < 0 )
        return matched;
      goto LABEL_71;
    }
LABEL_72:
    v35 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      while ( 1 )
      {
        v36 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v35;
        v37 = *(_DWORD **)(v36 + 4 * v35);
        *((_DWORD *)this + 64) = v37;
        if ( (*v37 & 0xFFF00000) == 0x50300000 )
        {
          matched = D3DXShader::CShaderProgram::MatchSINCOS(this);
          if ( matched < 0 )
            break;
        }
        if ( (unsigned int)++v35 >= *((_DWORD *)this + 3) )
          goto LABEL_76;
      }
    }
    else
    {
LABEL_76:
      matched = D3DXShader::CProgram::RemoveDeadCode(this);
      if ( matched >= 0 )
      {
        matched = D3DXShader::CProgram::RemoveDuplicateArguments(this);
        if ( matched >= 0 )
        {
          matched = D3DXShader::CProgram::CompactInstructions(this);
          if ( matched >= 0 )
          {
            matched = D3DXShader::CProgram::CompactArguments(this);
            if ( matched >= 0 )
            {
              D3DXShader::CShaderProgram::Reset(this);
              return 0;
            }
          }
        }
      }
    }
  }
  return matched;
}

//------------------------------------------------------------------------------
// Address: 0x1020DC51
// Name: protected: virtual long D3DXShader::CPSProgram::PatternMatch(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::PatternMatch(D3DXShader::CPSProgram *this)
{
  unsigned int v2; // edi
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  unsigned int v5; // eax
  int v6; // edi
  int v7; // eax
  int *v8; // eax
  int v9; // eax
  unsigned int v10; // ecx
  unsigned int j; // ecx
  int v12; // eax
  unsigned int v14; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  *((_DWORD *)this + 136) = -1;
  *((_DWORD *)this + 137) = -1;
  v2 = 0;
  for ( i = 0; v2 < *((_DWORD *)this + 3); ++v2 )
  {
    v3 = (_DWORD *)(*((_DWORD *)this + 6) + 4 * v2);
    *((_DWORD *)this + 63) = v2;
    *((_DWORD *)this + 64) = *v3;
    *((_DWORD *)this + 63) = v2;
    v4 = (_DWORD *)*v3;
    *((_DWORD *)this + 64) = v4;
    v5 = *v4 & 0xFFF00000;
    if ( (v5 == 540016640 || v5 == 538968064) && *((_DWORD *)this + 136) == -1 )
    {
      v14 = D3DXShader::CBaseProgram::AddPool(
              this,
              a2: (char *)&stru_102A6BD8.m_Memory.m_nGrowSize,
              a3: 0x311u,
              a4: 1u,
              a5: 4u);
      *((_DWORD *)this + 136) = D3DXShader::CBaseProgram::AddArgument(this, a2: v14, a3: 0, a4: 0, a5: 0.0);
      *((_DWORD *)this + 137) = D3DXShader::CBaseProgram::AddArgument(this, a2: v14, a3: 0, a4: 1u, a5: 1.0);
    }
  }
  D3DXShader::CShaderProgram::Reset(this);
  if ( (*((_BYTE *)this + 204) & 4) == 0 )
  {
    v6 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      while ( 1 )
      {
        v7 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v6;
        v8 = *(int **)(v7 + 4 * v6);
        *((_DWORD *)this + 64) = v8;
        v9 = *v8;
        v10 = v9 & 0xFFF00000;
        if ( (_UNKNOWN *)(v9 & 0xFFF00000) == &unk_10300000 || v10 == 273678336 || v10 == 274726912 || v10 == 275775488 )
          goto LABEL_16;
        if ( v10 == 1342177280 )
          break;
        i = 1;
LABEL_18:
        if ( (unsigned int)++v6 >= *((_DWORD *)this + 3) )
          goto LABEL_19;
      }
      if ( (v9 & 0xFFFFFu) > 2 )
LABEL_16:
        i = D3DXShader::CShaderProgram::MatchRepMov(this);
      if ( i < 0 )
        return i;
      goto LABEL_18;
    }
  }
LABEL_19:
  D3DXShader::CShaderProgram::Reset(this);
  for ( j = 0; j < *((_DWORD *)this + 2); ++j )
  {
    v12 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * j);
    if ( *(_DWORD *)(v12 + 84) == -1
      && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v12 + 4)) + 5) & 1) != 0
      && *((_DWORD *)this + 137) != j
      && *((_DWORD *)this + 136) != j )
    {
      *(_DWORD *)(v12 + 4) = *((_DWORD *)this + 29);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020DDE2
// Name: protected: virtual long D3DXShader::CPSProgram::DestMask(unsigned int __near *,unsigned int,unsigned long __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::DestMask(
        D3DXShader::CPSProgram *this,
        unsigned int *a2,
        unsigned int a3,
        unsigned int *a4,
        int a5)
{
  unsigned int v5; // edi
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  unsigned int v11; // ecx
  bool v12; // zf
  int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // edi
  unsigned int v16; // eax
  unsigned int v18; // [esp+Ch] [ebp-4h]

  v5 = 0;
  v18 = 0;
  if ( a5 != 0 )
  {
    v18 = 983040;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *a2) + 61) & 2) != 0 )
      v18 = 0x100000;
    if ( a3 != 0 )
    {
      do
      {
        v7 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a2[v5]) + 16);
        v8 = 0;
        if ( v7 != 0 )
        {
          v9 = v7 - 1;
          if ( v9 != 0 )
          {
            v10 = v9 - 1;
            if ( v10 != 0 )
            {
              if ( v10 == 1 )
                v8 = 0x80000;
            }
            else
            {
              v8 = 0x40000;
            }
          }
          else
          {
            v8 = 0x20000;
          }
        }
        else
        {
          v8 = 0x10000;
        }
        if ( (v8 & v18) != 0 )
          D3DXShader::CProgram::Error(
            this,
            a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
            a3: 0x12D5u,
            format: "internal error: overlapping output writes");
        v18 |= v8;
        ++v5;
      }
      while ( v5 < a3 );
    }
  }
  if ( (*((_DWORD *)this + 51) & 0x20) != 0 )
    goto LABEL_26;
  v11 = 0;
  v12 = a3 == 0;
  if ( a3 != 0 )
  {
    do
    {
      v13 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * a2[v11]);
      if ( (*(_BYTE *)(v13 + 3) & 2) == 0
        && ((*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v13 + 4)) + 4) & 1) == 0
         || *(_DWORD *)(v13 + 72) == -1
         || *(_DWORD *)(v13 + 84) != -1) )
      {
        break;
      }
      ++v11;
    }
    while ( v11 < a3 );
    v12 = v11 == a3;
  }
  if ( v12 )
LABEL_26:
    BYTE2(v18) |= 0x20u;
  if ( (*((_BYTE *)this + 204) & 1) != 0 )
  {
    v14 = 0;
    if ( *((_DWORD *)this + 73) != 0 && a3 != 0 )
    {
      do
      {
        v15 = a2[v14];
        v16 = v14 + 6 * *((_DWORD *)this + 74);
        ++v14;
        *(_DWORD *)(*((_DWORD *)this + 73) + 4 * v16 - 16) = v15;
      }
      while ( v14 < a3 );
    }
  }
  *a4 = v18;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020DF1C
// Name: protected: virtual long D3DXShader::CPSProgram::ValidateOutput(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CPSProgram::ValidateOutput(D3DXShader::CPSProgram *this)
{
  unsigned int result; // eax
  bool v3; // zf
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // eax
  int v9; // ebx
  unsigned int v10; // eax
  char *v11; // eax
  int v12; // edi
  unsigned int i; // edi
  int v14; // ecx
  _DWORD *v15; // eax
  int v16; // edx
  _DWORD v17[16]; // [esp+4h] [ebp-60h] BYREF
  struct D3DXShader::CNode *v18[4]; // [esp+44h] [ebp-20h] BYREF
  int v19; // [esp+54h] [ebp-10h]
  int j; // [esp+58h] [ebp-Ch]
  unsigned int v21; // [esp+5Ch] [ebp-8h]
  int v22; // [esp+60h] [ebp-4h]

  result = 0;
  if ( *((_DWORD *)this + 86) == 0 )
  {
    memset(v17, 0, sizeof(v17));
    memset(v18, 0, sizeof(v18));
    *((_DWORD *)this + 134) = 0;
    *((_DWORD *)this + 135) = 0;
    memset((char *)this + 504, 0, 0x20u);
    v3 = *((_DWORD *)this + 2) == 0;
    v22 = 0;
    j = 0;
    v21 = 0;
    if ( !v3 )
    {
      do
      {
        v4 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v21);
        v5 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v4 + 4)) + 4);
        if ( (v5 & 0x20) != 0 )
        {
          v6 = (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD))(*(_DWORD *)this + 84))(
                 a1: this,
                 a2: *(_DWORD *)(v4 + 108));
          v7 = (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD))(*(_DWORD *)this + 88))(
                 a1: this,
                 a2: *(_DWORD *)(v4 + 108));
          if ( v6 == 11 )
          {
            if ( v7 < 4 )
            {
              v8 = v7;
              v17[v8 * 4 + *(_DWORD *)(v4 + 16)] = 1;
              v18[v8] = *(struct D3DXShader::CNode **)(v4 + 96);
            }
          }
          else if ( v6 == 13 && v7 == 0 && *(_DWORD *)(v4 + 16) != 0 && j == 0 )
          {
            D3DXShader::CProgram::Error(
              this,
              a2: *(struct D3DXShader::CNode **)(v4 + 96),
              a3: 0x11B0u,
              format: "DEPTH must be a scalar");
            j = 1;
            v22 = 1;
          }
        }
        else if ( (v5 & 0x10) != 0 && (v5 & 0x200) == 0 )
        {
          v9 = (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD))(*(_DWORD *)this + 84))(
                 a1: this,
                 a2: *(_DWORD *)(v4 + 108));
          v10 = (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD))(*(_DWORD *)this + 88))(
                  a1: this,
                  a2: *(_DWORD *)(v4 + 108));
          if ( v9 == 6 )
          {
            if ( v10 < 8 )
            {
              v11 = (char *)this + 4 * v10 + 504;
LABEL_20:
              v12 = *(_DWORD *)(v4 + 16);
              if ( *(_DWORD *)v11 < (unsigned int)(v12 + 1) )
                *(_DWORD *)v11 = v12 + 1;
            }
          }
          else if ( v9 == 11 && v10 < 2 )
          {
            v11 = (char *)this + 4 * v10 + 536;
            goto LABEL_20;
          }
        }
        ++v21;
      }
      while ( v21 < *((_DWORD *)this + 2) );
    }
    v21 = 0;
    v19 = 1;
    for ( i = 0; i < 4; ++i )
    {
      v14 = 0;
      v15 = &v17[4 * i];
      for ( j = 4; j != 0; --j )
      {
        v16 = *v15++ != 0;
        v14 += v16;
      }
      if ( v14 != 0 )
      {
        if ( v14 != 4 )
        {
          D3DXShader::CProgram::Error(
            this,
            a2: v18[i],
            a3: 0x11B1u,
            format: "COLOR%d must be a four-component vector",
            i);
          v22 = 1;
        }
        if ( v21 != 0 )
          v19 = 0;
      }
      else
      {
        if ( i == 0 )
        {
          D3DXShader::CProgram::Error(
            this,
            a2: v18[0],
            a3: 0x11B2u,
            format: "pixel shader must minimally write all four components of COLOR0");
          v22 = 1;
        }
        v21 = 1;
      }
    }
    if ( v19 == 0 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: nullptr,
        a3: 0x11BAu,
        format: "COLOR outputs must be contiguous from COLOR0 to COLORn");
      v22 = 1;
    }
    return v22 != 0 ? 0x80004005 : 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020E11B
// Name: protected: long D3DXShader::CPSProgram::PSEmitGE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::PSEmitGE(D3DXShader::CPSProgram *this)
{
  int *v2; // eax
  int v3; // edi
  unsigned int *v4; // ecx
  unsigned int *v5; // eax
  unsigned int v6; // edi
  int result; // eax
  unsigned int v8; // eax
  bool v9; // cf
  int v10; // [esp-14h] [ebp-70h]
  unsigned int v11[4]; // [esp+Ch] [ebp-50h] BYREF
  unsigned int v12[4]; // [esp+1Ch] [ebp-40h] BYREF
  unsigned int v13[4]; // [esp+2Ch] [ebp-30h] BYREF
  unsigned int v14[4]; // [esp+3Ch] [ebp-20h] BYREF
  unsigned int *v15; // [esp+4Ch] [ebp-10h]
  unsigned int *v16; // [esp+50h] [ebp-Ch]
  unsigned int v17; // [esp+54h] [ebp-8h]
  unsigned int i; // [esp+58h] [ebp-4h]

  v2 = *((int **)this + 64);
  v3 = *v2;
  v17 = v2[3];
  v4 = (unsigned int *)v2[4];
  v5 = (unsigned int *)v2[2];
  v15 = v4;
  v10 = *((_DWORD *)this + 63);
  v16 = v5;
  v6 = v3 & 0xFFFFF;
  result = (*(int (__thiscall **)(D3DXShader::CPSProgram *, int, unsigned int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             a1: this,
             a2: v10,
             a3: v13,
             a4: 4,
             a5: 0,
             a6: 0);
  if ( result >= 0 )
  {
    for ( i = 0; i < 4; ++i )
    {
      v8 = i;
      v9 = i < v17;
      v12[v8] = *((_DWORD *)this + 136);
      v11[v8] = *((_DWORD *)this + 137);
      if ( v9 )
        v14[v8] = v13[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v15[v8]) + 16)];
    }
    D3DXShader::CShaderProgram::EmitInstComplex(
      this,
      a2: 2u,
      a3: v14,
      a4: v17,
      a5: v16,
      a6: &v16[v6],
      a7: nullptr,
      a8: v6,
      a9: 0,
      a10: 0x1000000u,
      a11: 0,
      a12: 0);
    return D3DXShader::CShaderProgram::EmitInstComplex(
             this,
             a2: 0x58u,
             a3: v15,
             a4: v17,
             a5: v14,
             a6: v11,
             a7: v12,
             a8: v6,
             a9: 0,
             a10: 0,
             a11: 0,
             a12: 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020E1F7
// Name: protected: long D3DXShader::CPSProgram::PSEmitLT(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::PSEmitLT(D3DXShader::CPSProgram *this)
{
  int *v2; // eax
  int v3; // edi
  unsigned int *v4; // ecx
  unsigned int *v5; // eax
  unsigned int v6; // edi
  int result; // eax
  unsigned int v8; // eax
  bool v9; // cf
  int v10; // [esp-14h] [ebp-70h]
  unsigned int v11[4]; // [esp+Ch] [ebp-50h] BYREF
  unsigned int v12[4]; // [esp+1Ch] [ebp-40h] BYREF
  unsigned int v13[4]; // [esp+2Ch] [ebp-30h] BYREF
  unsigned int v14[4]; // [esp+3Ch] [ebp-20h] BYREF
  unsigned int *v15; // [esp+4Ch] [ebp-10h]
  unsigned int *v16; // [esp+50h] [ebp-Ch]
  unsigned int v17; // [esp+54h] [ebp-8h]
  unsigned int i; // [esp+58h] [ebp-4h]

  v2 = *((int **)this + 64);
  v3 = *v2;
  v17 = v2[3];
  v4 = (unsigned int *)v2[4];
  v5 = (unsigned int *)v2[2];
  v15 = v4;
  v10 = *((_DWORD *)this + 63);
  v16 = v5;
  v6 = v3 & 0xFFFFF;
  result = (*(int (__thiscall **)(D3DXShader::CPSProgram *, int, unsigned int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             a1: this,
             a2: v10,
             a3: v13,
             a4: 4,
             a5: 0,
             a6: 0);
  if ( result >= 0 )
  {
    for ( i = 0; i < 4; ++i )
    {
      v8 = i;
      v9 = i < v17;
      v11[v8] = *((_DWORD *)this + 136);
      v12[v8] = *((_DWORD *)this + 137);
      if ( v9 )
        v14[v8] = v13[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v15[v8]) + 16)];
    }
    D3DXShader::CShaderProgram::EmitInstComplex(
      this,
      a2: 2u,
      a3: v14,
      a4: v17,
      a5: v16,
      a6: &v16[v6],
      a7: nullptr,
      a8: v6,
      a9: 0,
      a10: 0x1000000u,
      a11: 0,
      a12: 0);
    return D3DXShader::CShaderProgram::EmitInstComplex(
             this,
             a2: 0x58u,
             a3: v15,
             a4: v17,
             a5: v14,
             a6: v11,
             a7: v12,
             a8: v6,
             a9: 0,
             a10: 0,
             a11: 0,
             a12: 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020E2D3
// Name: protected: long D3DXShader::CPSProgram::PSEmitMax(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::PSEmitMax(D3DXShader::CPSProgram *this)
{
  int *v2; // eax
  int v3; // esi
  unsigned int *v4; // ebx
  unsigned int v5; // edx
  unsigned int *v6; // ecx
  unsigned int v7; // esi
  int v8; // eax
  unsigned int v9; // edx
  int v10; // ecx
  int result; // eax
  int v12; // eax
  int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned int v16[4]; // [esp+Ch] [ebp-34h] BYREF
  unsigned int v17[4]; // [esp+1Ch] [ebp-24h] BYREF
  int i; // [esp+2Ch] [ebp-14h]
  unsigned int *v19; // [esp+30h] [ebp-10h]
  unsigned int *v20; // [esp+34h] [ebp-Ch]
  unsigned int v21; // [esp+38h] [ebp-8h]
  unsigned int v22; // [esp+3Ch] [ebp-4h]

  v2 = *((int **)this + 64);
  v3 = *v2;
  v4 = (unsigned int *)v2[2];
  v5 = *v4;
  v22 = v2[3];
  v6 = (unsigned int *)v2[4];
  v7 = v3 & 0xFFFFF;
  v20 = &v4[v7];
  v8 = *((_DWORD *)this + 5);
  v21 = *(_DWORD *)(v8 + 4 * v5);
  v9 = *v20;
  v19 = v6;
  v10 = *(_DWORD *)(v8 + 4 * *v6);
  i = *(_DWORD *)(v8 + 4 * v9);
  if ( (*(_DWORD *)(v10 + 4) != *(_DWORD *)(v21 + 4) || *(_DWORD *)(v10 + 12) != *(_DWORD *)(v21 + 12))
    && (*(_DWORD *)(v10 + 4) != *(_DWORD *)(i + 4) || *(_DWORD *)(v10 + 12) != *(_DWORD *)(i + 12)) )
  {
    return D3DXShader::CShaderProgram::EmitInstComplex(
             this,
             a2: 0xBu,
             a3: v19,
             a4: v22,
             a5: v4,
             a6: v20,
             a7: nullptr,
             a8: v7,
             a9: 0,
             a10: 0,
             a11: 0,
             a12: 0);
  }
  result = (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD, unsigned int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             a1: this,
             a2: *((_DWORD *)this + 63),
             a3: v16,
             a4: 4,
             a5: 0,
             a6: 0);
  if ( result >= 0 )
  {
    v21 = 0;
    if ( v22 != 0 )
    {
      v12 = *((_DWORD *)this + 5);
      v13 = (char *)v19 - (char *)v17;
      for ( i = (char *)v19 - (char *)v17; ; v13 = i )
      {
        v14 = v21;
        v15 = v16[*(_DWORD *)(*(_DWORD *)(v12 + 4 * *(unsigned int *)((char *)&v17[v21++] + v13)) + 16)];
        v17[v14] = v15;
        if ( v21 >= v22 )
          break;
      }
    }
    D3DXShader::CShaderProgram::EmitInstComplex(
      this,
      a2: 2u,
      a3: v17,
      a4: v22,
      a5: v4,
      a6: v20,
      a7: nullptr,
      a8: v7,
      a9: 0,
      a10: 0x1000000u,
      a11: 0,
      a12: 0);
    return D3DXShader::CShaderProgram::EmitInstComplex(
             this,
             a2: 0x58u,
             a3: v19,
             a4: v22,
             a5: v17,
             a6: v4,
             a7: v20,
             a8: v7,
             a9: 0,
             a10: 0,
             a11: 0,
             a12: 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020E409
// Name: protected: long D3DXShader::CPSProgram::PSEmitMin(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::PSEmitMin(D3DXShader::CPSProgram *this)
{
  int *v2; // eax
  int v3; // esi
  unsigned int *v4; // ebx
  unsigned int v5; // edx
  unsigned int *v6; // ecx
  unsigned int v7; // esi
  int v8; // eax
  unsigned int v9; // edx
  int v10; // ecx
  int result; // eax
  int v12; // eax
  int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned int v16[4]; // [esp+Ch] [ebp-34h] BYREF
  unsigned int v17[4]; // [esp+1Ch] [ebp-24h] BYREF
  int i; // [esp+2Ch] [ebp-14h]
  unsigned int *v19; // [esp+30h] [ebp-10h]
  unsigned int *v20; // [esp+34h] [ebp-Ch]
  unsigned int v21; // [esp+38h] [ebp-8h]
  unsigned int v22; // [esp+3Ch] [ebp-4h]

  v2 = *((int **)this + 64);
  v3 = *v2;
  v4 = (unsigned int *)v2[2];
  v5 = *v4;
  v22 = v2[3];
  v6 = (unsigned int *)v2[4];
  v7 = v3 & 0xFFFFF;
  v20 = &v4[v7];
  v8 = *((_DWORD *)this + 5);
  v21 = *(_DWORD *)(v8 + 4 * v5);
  v9 = *v20;
  v19 = v6;
  v10 = *(_DWORD *)(v8 + 4 * *v6);
  i = *(_DWORD *)(v8 + 4 * v9);
  if ( (*(_DWORD *)(v10 + 4) != *(_DWORD *)(v21 + 4) || *(_DWORD *)(v10 + 12) != *(_DWORD *)(v21 + 12))
    && (*(_DWORD *)(v10 + 4) != *(_DWORD *)(i + 4) || *(_DWORD *)(v10 + 12) != *(_DWORD *)(i + 12)) )
  {
    return D3DXShader::CShaderProgram::EmitInstComplex(
             this,
             a2: 0xAu,
             a3: v19,
             a4: v22,
             a5: v4,
             a6: v20,
             a7: nullptr,
             a8: v7,
             a9: 0,
             a10: 0,
             a11: 0,
             a12: 0);
  }
  result = (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD, unsigned int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             a1: this,
             a2: *((_DWORD *)this + 63),
             a3: v16,
             a4: 4,
             a5: 0,
             a6: 0);
  if ( result >= 0 )
  {
    v21 = 0;
    if ( v22 != 0 )
    {
      v12 = *((_DWORD *)this + 5);
      v13 = (char *)v19 - (char *)v17;
      for ( i = (char *)v19 - (char *)v17; ; v13 = i )
      {
        v14 = v21;
        v15 = v16[*(_DWORD *)(*(_DWORD *)(v12 + 4 * *(unsigned int *)((char *)&v17[v21++] + v13)) + 16)];
        v17[v14] = v15;
        if ( v21 >= v22 )
          break;
      }
    }
    D3DXShader::CShaderProgram::EmitInstComplex(
      this,
      a2: 2u,
      a3: v17,
      a4: v22,
      a5: v4,
      a6: v20,
      a7: nullptr,
      a8: v7,
      a9: 0,
      a10: 0x1000000u,
      a11: 0,
      a12: 0);
    return D3DXShader::CShaderProgram::EmitInstComplex(
             this,
             a2: 0x58u,
             a3: v19,
             a4: v22,
             a5: v17,
             a6: v20,
             a7: v4,
             a8: v7,
             a9: 0,
             a10: 0,
             a11: 0,
             a12: 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020E53F
// Name: protected: virtual long D3DXShader::C30Program::EmitObjectDCL(class D3DXShader::CArgument __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::EmitObjectDCL(D3DXShader::C30Program *this, struct D3DXShader::CArgument *a2)
{
  int result; // eax
  int v4; // eax

  if ( *((_DWORD *)this + 86) != 0 )
    return 0;
  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x200001Fu);
  if ( result >= 0 )
  {
    v4 = *((_DWORD *)a2 + 15);
    switch ( v4 )
    {
      case 0x200000:
        result = D3DXShader::CShaderProgram::Emit(this, a2: 0x90000000);
        break;
      case 0x400000:
        result = D3DXShader::CShaderProgram::Emit(this, a2: 0xA0000000);
        break;
      case 0x800000:
        result = D3DXShader::CShaderProgram::Emit(this, a2: 0x98000000);
        break;
      default:
        D3DXShader::CProgram::Error(
          this,
          a2: nullptr,
          a3: 0x12CEu,
          format: "internal error: unexpected Alias on texture declaration");
        return -2147467259;
    }
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::C30Program *, unsigned int, int, _DWORD))(*(_DWORD *)this + 100))(
                 a1: this,
                 a2: *((_DWORD *)a2 + 3) & 0x7FF | 0xA0000800,
                 a3: 983040,
                 a4: 0);
      if ( result >= 0 )
      {
        result = D3DXShader::CShaderProgram::ValidateInst(this);
        if ( result >= 0 )
          return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020E5F6
// Name: protected: virtual long D3DXShader::CPSProgram::EmitDCL(class D3DXShader::CArgument __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::EmitDCL(
        struct D3DXShader::D3DX_SEMANTIC **this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // edi
  struct D3DXShader::D3DX_SEMANTIC *Semantic; // eax
  int result; // eax
  int v10; // eax
  int v11; // edi
  void *v12; // eax
  int v13; // edi
  unsigned int v14; // eax
  bool v15; // zf
  int v16; // edi
  int v17; // ecx
  _DWORD *v18; // eax
  int v19; // edx
  unsigned int i; // ecx
  unsigned int v21; // eax
  unsigned int v22; // [esp-8h] [ebp-50h]
  int v23; // [esp-4h] [ebp-4Ch]
  int v24; // [esp-4h] [ebp-4Ch]
  __int16 v25; // [esp+Ch] [ebp-3Ch]
  int v26; // [esp+10h] [ebp-38h] BYREF
  int v27; // [esp+14h] [ebp-34h]
  void *pMem; // [esp+18h] [ebp-30h]
  unsigned int v29; // [esp+1Ch] [ebp-2Ch]
  unsigned int *v30; // [esp+20h] [ebp-28h]
  char string[16]; // [esp+24h] [ebp-24h] BYREF
  unsigned int v32[4]; // [esp+34h] [ebp-14h] BYREF

  v23 = *((_DWORD *)a2 + 27);
  v30 = a3;
  v4 = (*((int (__thiscall **)(struct D3DXShader::D3DX_SEMANTIC **, int))*this + 21))(a1: this, a2: v23);
  v24 = *((_DWORD *)a2 + 27);
  v29 = v4;
  v5 = (*((int (__thiscall **)(struct D3DXShader::D3DX_SEMANTIC **, int))*this + 22))(a1: this, a2: v24);
  v6 = 0;
  v7 = v5;
  v25 = v5;
  if ( *(this + 86) != nullptr )
  {
    if ( *((_DWORD *)a2 + 27) != -1 )
    {
      if ( v29 != 0xFFFF )
      {
        Semantic = D3DXShader::CShaderProgram::FindSemantic(this, a2: (struct D3DXShader::D3DX_SEMANTIC *)v29);
        _snprintf(string, count: 0x20u, format: "v_%s%d", *(const char **)Semantic, v7);
        v22 = *((_DWORD *)a2 + 3);
        HIBYTE(v32[3]) = 0;
        result = D3DXShader::CFragmentRegisterAllocator::AddElement(
                   this: this + 117,
                   a2: (D3DXShader *)string,
                   a3: v22,
                   a4: 1u);
        if ( result < 0 )
          return result;
        *(this + 124) = (struct D3DXShader::D3DX_SEMANTIC *)((char *)*(this + 124) + 1);
        if ( (*(_BYTE *)(this + 51) & 1) != 0 )
        {
          v10 = *((_DWORD *)a2 + 24);
          if ( v10 != 0 && *(_DWORD *)(v10 + 4) == 6 )
          {
            v11 = *(_DWORD *)(v10 + 20);
            if ( *(_DWORD *)(v11 + 4) == 3 )
            {
              v12 = MemAlloc_Alloc(nSize: strlen(*(const char **)(v11 + 24)) + 3);
              pMem = v12;
              if ( v12 == nullptr )
                return -2147024882;
              sprintf(string: (char *)v12, format: "n_%s", *(const char **)(v11 + 24));
              v13 = D3DXShader::CFragmentRegisterAllocator::AddElement(
                      this: this + 117,
                      a2: (D3DXShader *)pMem,
                      a3: *((_DWORD *)a2 + 3),
                      a4: 1u);
              free(pMem);
              if ( v13 < 0 )
                return v13;
              *(this + 124) = (struct D3DXShader::D3DX_SEMANTIC *)((char *)*(this + 124) + 1);
            }
          }
        }
      }
      if ( v30 != nullptr )
        *v30 = *((_DWORD *)a2 + 27);
    }
    return 0;
  }
  if ( v29 == 11 )
  {
    if ( v5 < (unsigned int)*(this + 10) )
    {
      *v30 = v5;
      v14 = (unsigned int)*(this + v5 + 134);
      pMem = (void *)1;
      goto LABEL_22;
    }
    return -2147467259;
  }
  if ( v29 != 6 || v5 >= 8 )
    return -2147467259;
  *v30 = v5 + 2;
  v14 = (unsigned int)*(this + v5 + 126);
  pMem = (void *)3;
LABEL_22:
  v30 = nullptr;
  if ( v14 != 0 )
  {
    do
    {
      if ( v6 != 0 )
      {
        switch ( v6 )
        {
          case 1u:
            BYTE2(v30) |= 2u;
            break;
          case 2u:
            BYTE2(v30) |= 4u;
            break;
          case 3u:
            BYTE2(v30) |= 8u;
            break;
          default:
            break;
        }
      }
      else
      {
        BYTE2(v30) |= 1u;
      }
      ++v6;
    }
    while ( v6 < v14 );
  }
  if ( pMem != (void *)1 && ((*(_BYTE *)(this + 51) & 0x20) != 0 || v29 == 6 && (*((_BYTE *)a2 + 3) & 2) != 0) )
    BYTE2(v30) |= 0x20u;
  v27 = 0;
  if ( (*((_BYTE *)a2 + 3) & 1) != 0 )
    v27 = 0x400000;
  result = D3DXShader::CShaderProgram::EmitInst((D3DXShader::CShaderProgram *)this, a2: 0x200001Fu);
  if ( result >= 0 )
  {
    result = D3DXShader::CShaderProgram::Emit((D3DXShader::CShaderProgram *)this, a2: 0x80000000);
    if ( result >= 0 )
    {
      if ( (*(_BYTE *)(this + 51) & 1) != 0 )
      {
        v26 = 0;
        v29 = 0;
        v15 = *(this + 2) == nullptr;
        memset(v32, 255, sizeof(v32));
        if ( !v15 )
        {
          v16 = *((_DWORD *)a2 + 1);
          v17 = (int)*(this + 5);
          do
          {
            v18 = *(_DWORD **)v17;
            if ( v16 == *(_DWORD *)(*(_DWORD *)v17 + 4)
              && *((_DWORD *)a2 + 2) == v18[2]
              && *((_DWORD *)a2 + 3) == v18[3] )
            {
              v32[v18[4]] = v29;
            }
            ++v29;
            v17 += 4;
          }
          while ( v29 < (unsigned int)*(this + 2) );
        }
        v19 = v26;
        for ( i = 0; i < 4; ++i )
        {
          v21 = v32[i];
          if ( v21 != -1 )
            v32[v19++] = v21;
        }
        result = (*((int (__thiscall **)(struct D3DXShader::D3DX_SEMANTIC **, unsigned int *, int, int *, int))*this + 28))(
                   a1: this,
                   a2: v32,
                   a3: v19,
                   a4: &v26,
                   a5: 1);
        if ( result < 0 )
          return result;
        LOWORD(v7) = v25;
      }
      result = (*((int (__thiscall **)(struct D3DXShader::D3DX_SEMANTIC **, unsigned int, unsigned int *, _DWORD))*this
                + 25))(
                 a1: this,
                 a2: v27 | v7 & 0x7FF | (((unsigned __int8)pMem & 0x18 | (((unsigned __int8)pMem | 0xFFFFFFF8) << 20)) << 8),
                 a3: v30,
                 a4: 0);
      if ( result >= 0 )
      {
        result = D3DXShader::CShaderProgram::ValidateInst((D3DXShader::CShaderProgram *)this);
        if ( result >= 0 )
          return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020E8EC
// Name: protected: virtual long D3DXShader::CPSProgram::FindInput(class D3DXShader::CArgument __near *,unsigned long __near &,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::FindInput(
        D3DXShader::CPSProgram *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3,
        unsigned int *a4)
{
  int v5; // ebx
  unsigned int v6; // eax

  v5 = (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD))(*(_DWORD *)this + 84))(
         a1: this,
         a2: *((_DWORD *)a2 + 27));
  v6 = (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD))(*(_DWORD *)this + 88))(
         a1: this,
         a2: *((_DWORD *)a2 + 27));
  *a3 = v6;
  switch ( v5 )
  {
    case 0xB:
      if ( v6 < *((_DWORD *)this + 10) )
      {
        *a4 = 1;
        return 0;
      }
      break;
    case 6:
      if ( v6 < 8 )
      {
        *a4 = 3;
        return 0;
      }
      break;
    case 0xFFFF:
      *a4 = 0;
      return 0;
    default:
      break;
  }
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x1020E95A
// Name: protected: virtual long D3DXShader::CPSProgram::FindOutput(class D3DXShader::CArgument __near *,unsigned long __near &,unsigned long __near &,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::FindOutput(
        D3DXShader::CPSProgram *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3,
        unsigned int *a4,
        int *a5)
{
  int v6; // ebx
  unsigned int v7; // eax
  int v9; // [esp+Ch] [ebp-4h]

  v9 = 1;
  v6 = (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD))(*(_DWORD *)this + 84))(
         a1: this,
         a2: *((_DWORD *)a2 + 27));
  v7 = (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD))(*(_DWORD *)this + 88))(
         a1: this,
         a2: *((_DWORD *)a2 + 27));
  *a3 = v7;
  if ( v6 != 11 )
  {
    if ( v6 == 13 )
    {
      if ( v7 == 0 )
      {
        *a4 = 9;
        goto LABEL_9;
      }
    }
    else if ( v6 == 0xFFFF )
    {
      *a4 = 0;
      v9 = 0;
      goto LABEL_9;
    }
    return -2147467259;
  }
  if ( v7 >= 4 )
    return -2147467259;
  *a4 = 8;
LABEL_9:
  if ( a5 != nullptr )
    *a5 = v9;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020E9DF
// Name: int D3DXShader::IsValidSwizzle(unsigned int __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::IsValidSwizzle(D3DXShader *this, unsigned int *a2, unsigned int *a3)
{
  int v3; // edx
  unsigned int *v4; // ecx
  unsigned int *v5; // eax
  int v6; // edi
  int i; // esi
  D3DXShader *thisa; // [esp+14h] [ebp+8h]

  v3 = this - (D3DXShader *)a2;
  thisa = nullptr;
  v4 = &D3DXShader::g_Swizzle;
  while ( 1 )
  {
    v5 = a2;
    v6 = 1;
    for ( i = 4; i != 0; --i )
    {
      if ( *(unsigned int *)((char *)v5 + v3) != *v4 && *v5 != -1 )
        v6 = 0;
      ++v4;
      ++v5;
    }
    if ( v6 != 0 )
      break;
    thisa = (D3DXShader *)((char *)thisa + 16);
    if ( (unsigned int)thisa >= 0x80 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1020EA35
// Name: protected: long D3DXShader::CPSProgram::RemapInput(class D3DXShader::CInstruction __near * __near &,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::RemapInput(
        D3DXShader::CPSProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3,
        unsigned int a4)
{
  unsigned int v5; // ecx
  bool v6; // zf
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // edx
  unsigned int v11; // edx
  unsigned int v12; // ecx
  unsigned int v13; // ebx
  int v14; // eax
  unsigned int j; // eax
  int result; // eax
  unsigned __int8 *v17; // eax
  struct D3DXShader::CInstruction *v18; // eax
  int v19; // eax
  unsigned int k; // ecx
  unsigned int m; // eax
  _DWORD *v22; // ecx
  _DWORD v23[8]; // [esp+Ch] [ebp-2Ch] BYREF
  int v24; // [esp+2Ch] [ebp-Ch]
  int v25; // [esp+30h] [ebp-8h]
  int v26; // [esp+34h] [ebp-4h]
  unsigned int i; // [esp+48h] [ebp+10h]

  v5 = 0;
  v6 = a4 == 0;
  if ( a4 != 0 )
  {
    v7 = *((_DWORD *)this + 64);
    v8 = *(_DWORD *)(v7 + 8);
    v9 = **(_DWORD **)(v7 + 16);
    v25 = v8;
    v10 = *((_DWORD *)this + 5);
    v24 = *(_DWORD *)(*(_DWORD *)(v10 + 4 * v9) + 4);
    v26 = 0;
    do
    {
      if ( v24 == *(_DWORD *)(*(_DWORD *)(v10 + 4 * *(_DWORD *)(v26 + v25)) + 4)
        && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)) + 12) == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v26 + *(_DWORD *)(*((_DWORD *)this + 64) + 8))) + 12) )
      {
        break;
      }
      v26 += 4 * a3;
      ++v5;
    }
    while ( v5 < a4 );
    v6 = v5 == a4;
  }
  if ( v6 )
    return 0;
  v11 = *(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4 * a3 * v5;
  memset(&v23[4], 255, 16);
  v12 = 0;
  v13 = 0;
  for ( i = v11; v12 < a3; v23[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v14) + 16) + 4] = v14 )
    v14 = *(_DWORD *)(v11 + 4 * v12++);
  for ( j = 0; j < 4; ++j )
    v13 += v23[j + 4] != -1;
  result = (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD, _DWORD *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             a1: this,
             a2: *((_DWORD *)this + 63),
             a3: v23,
             a4: 4,
             a5: 0,
             a6: 0);
  if ( result >= 0 )
  {
    v17 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v17 != nullptr )
      v18 = (struct D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v17);
    else
      v18 = nullptr;
    *a2 = v18;
    if ( v18 == nullptr )
      return -2147024882;
    result = D3DXShader::CInstruction::Initialize(this: v18, a2: v13 & 0xFFFFF | 0x10000000, a3: v13, a4: v13, a5: 0);
    if ( result >= 0 )
    {
      result = D3DXShader::CInstruction::Instance(this: *a2, a2: *((struct D3DXShader::CInstruction **)this + 64));
      if ( result >= 0 )
      {
        v19 = 0;
        for ( k = 0; k < 4; ++k )
        {
          if ( v23[k + 4] != -1 )
          {
            *(_DWORD *)(v19 + *((_DWORD *)*a2 + 4)) = v23[k];
            *(_DWORD *)(v19 + *((_DWORD *)*a2 + 2)) = v23[k + 4];
            v19 += 4;
          }
        }
        for ( m = 0; m < a3; *v22 = v23[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v22) + 16)] )
          v22 = (_DWORD *)(i + 4 * m++);
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020EBDD
// Name: protected: long D3DXShader::CPSProgram::RemapOutputMov(class D3DXShader::CInstruction __near * __near &,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::RemapOutputMov(
        D3DXShader::CPSProgram *this,
        struct D3DXShader::CInstruction **a2,
        unsigned int a3)
{
  int v4; // eax
  unsigned int v5; // ebx
  int v6; // edx
  int v7; // ecx
  int i; // edi
  unsigned int v9; // eax
  unsigned int j; // edi
  unsigned int v11; // eax
  unsigned __int8 *v12; // eax
  struct D3DXShader::CInstruction *v13; // eax
  int v16; // eax
  D3DXShader::CInstruction *v17; // ecx
  char *v18; // eax
  unsigned int v19; // eax
  int v20; // ecx
  _DWORD v21[4]; // [esp+14h] [ebp-10h]
  struct D3DXShader::CInstruction **v22; // [esp+2Ch] [ebp+8h]
  struct D3DXShader::CInstruction **k; // [esp+2Ch] [ebp+8h]

  v4 = *((_DWORD *)this + 2);
  v5 = 0;
  if ( v4 != 0 )
  {
    v6 = *((_DWORD *)this + 34);
    v7 = *((_DWORD *)this + 5);
    for ( i = v4; i != 0; --i )
    {
      if ( v6 == *(_DWORD *)(*(_DWORD *)v7 + 4) )
      {
        v9 = *(_DWORD *)(*(_DWORD *)v7 + 12);
        if ( v9 >= v5 )
          v5 = v9 + 1;
      }
      v7 += 4;
    }
  }
  for ( j = 0; j < 4; ++j )
  {
    v11 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: v5, a4: j, a5: 0.0);
    v21[j] = v11;
    if ( v11 == -1 )
      return -2147024882;
  }
  v12 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v12 != nullptr )
    v13 = (struct D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v12);
  else
    v13 = nullptr;
  *a2 = v13;
  if ( v13 == nullptr )
    return -2147024882;
  v16 = D3DXShader::CInstruction::Initialize(this: v13, a2: a3 & 0xFFFFF | 0x10000000, a3, a4: a3, a5: 0);
  v17 = *a2;
  v22 = (struct D3DXShader::CInstruction **)v16;
  if ( v16 < 0 )
    goto LABEL_18;
  v22 = (struct D3DXShader::CInstruction **)D3DXShader::CInstruction::Instance(
                                              this: v17,
                                              a2: *((struct D3DXShader::CInstruction **)this + 64));
  if ( (int)v22 < 0 )
  {
    v17 = *a2;
LABEL_18:
    if ( v17 != nullptr )
      D3DXShader::CInstruction::`scalar deleting destructor'(this: v17, a2: 1);
    return (int)v22;
  }
  v18 = nullptr;
  for ( k = nullptr; (unsigned int)k < a3; k = (struct D3DXShader::CInstruction **)((char *)k + 1) )
  {
    v19 = 4 * (_DWORD)v18;
    v20 = v21[v19 / 4];
    *(_DWORD *)(v19 + *((_DWORD *)*a2 + 2)) = v20;
    *(_DWORD *)(v19 + *((_DWORD *)*a2 + 4)) = *(_DWORD *)(v19 + *(_DWORD *)(*((_DWORD *)this + 64) + 16));
    *(_DWORD *)(v19 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)) = v20;
    v18 = (char *)k + 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020ECFC
// Name: protected: long D3DXShader::CPSProgram::Unswizzle(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall D3DXShader::CPSProgram::Unswizzle@<eax>(D3DXShader::CPSProgram *this@<ecx>, unsigned int *a2@<esi>)
{
  int *v4; // eax
  int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // esi
  BOOL v8; // ecx
  _DWORD *v9; // edi
  bool v10; // zf
  int v11; // eax
  unsigned int v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  _DWORD *v16; // eax
  int v17; // edi
  unsigned int v18; // esi
  int v19; // eax
  int v20; // ecx
  D3DXShader *v21; // eax
  BOOL v22; // eax
  unsigned int v23; // esi
  unsigned int *v24; // edi
  int v25; // edi
  unsigned int *v26; // edi
  unsigned int v27; // esi
  _DWORD *v28; // eax
  unsigned int v29; // ecx
  int v30; // edx
  int v31; // esi
  int v32; // ecx
  _DWORD *v33; // eax
  unsigned int v34; // esi
  int v35; // edi
  unsigned int v36; // eax
  unsigned int j; // edi
  unsigned int v38; // eax
  unsigned __int8 *v39; // eax
  void **v40; // edx
  unsigned int ii; // esi
  unsigned int v42; // eax
  unsigned int *v43; // edi
  unsigned int v44; // esi
  unsigned int v45; // ecx
  unsigned int *v46; // edi
  int v47; // eax
  D3DXShader *v48; // eax
  int v49; // eax
  unsigned int k; // eax
  unsigned int n; // esi
  int v52; // ecx
  unsigned int v53; // edi
  unsigned int v54; // edx
  int v55; // esi
  int v56; // ecx
  unsigned int *v57; // edx
  unsigned int *v58; // edi
  _DWORD *v59; // eax
  unsigned int *v60; // edi
  unsigned __int8 *v61; // eax
  D3DXShader::CInstruction *v62; // esi
  int v63; // eax
  int v64; // ecx
  int v65; // edx
  unsigned int v66; // eax
  unsigned int v67; // edx
  unsigned __int8 *v68; // eax
  D3DXShader::CInstruction *v69; // esi
  unsigned int v70; // eax
  unsigned int v71; // edi
  unsigned int v72; // eax
  unsigned int v73; // [esp+0h] [ebp-E4h]
  int v74; // [esp+4h] [ebp-E0h]
  unsigned int v75; // [esp+4h] [ebp-E0h]
  unsigned int *v76; // [esp+8h] [ebp-DCh]
  unsigned int *v77; // [esp+8h] [ebp-DCh]
  unsigned int v78[16]; // [esp+14h] [ebp-D0h] BYREF
  unsigned int v79[4]; // [esp+54h] [ebp-90h] BYREF
  unsigned int v80; // [esp+64h] [ebp-80h] BYREF
  unsigned int v81; // [esp+68h] [ebp-7Ch]
  unsigned int v82; // [esp+6Ch] [ebp-78h]
  unsigned int v83; // [esp+70h] [ebp-74h]
  unsigned int v84[4]; // [esp+74h] [ebp-70h] BYREF
  unsigned int v85[4]; // [esp+84h] [ebp-60h] BYREF
  unsigned int v86[4]; // [esp+94h] [ebp-50h] BYREF
  unsigned int v87[4]; // [esp+A4h] [ebp-40h] BYREF
  unsigned int IsValidSwizzle; // [esp+B4h] [ebp-30h]
  D3DXShader::CInstruction *v89; // [esp+B8h] [ebp-2Ch] BYREF
  int v90; // [esp+BCh] [ebp-28h]
  D3DXShader::CInstruction *v91; // [esp+C0h] [ebp-24h] BYREF
  unsigned int v92; // [esp+C4h] [ebp-20h]
  int i; // [esp+C8h] [ebp-1Ch]
  unsigned int m; // [esp+CCh] [ebp-18h]
  D3DXShader *v95; // [esp+D0h] [ebp-14h]
  unsigned int jj; // [esp+D4h] [ebp-10h]
  unsigned int v97; // [esp+D8h] [ebp-Ch]
  unsigned int v98; // [esp+DCh] [ebp-8h]
  unsigned int *v99; // [esp+E0h] [ebp-4h]

  v89 = nullptr;
  v91 = nullptr;
  jj = **((_DWORD **)this + 64) & 0xFFF00000;
  if ( jj == 0 )
    return 0;
  v4 = *((int **)this + 64);
  v5 = *v4;
  v6 = v4[1];
  v76 = a2;
  v7 = v5 & 0xFFFFF;
  v92 = v5 & 0xFFFFF;
  IsValidSwizzle = v6 % (v5 & 0xFFFFFu);
  v97 = v6 / (v5 & 0xFFFFFu);
  v8 = (v5 & 0xFFF00000) == 0x50000000 || jj == 1344274432 || jj == 1887436800;
  v99 = nullptr;
  if ( jj == 1615855616 || jj == 1621098496 || jj == 1626341376 || jj == 285212672 )
  {
    v25 = D3DXShader::CBaseProgram::CopyInstruction(this, a2: *((struct D3DXShader::CInstruction **)this + 64));
    if ( v25 >= 0 )
    {
      **((_DWORD **)this + 64) = 0;
      goto LABEL_201;
    }
    return v25;
  }
  if ( v8 )
  {
    if ( jj == 1344274432 || jj == 1887436800 )
    {
      v25 = D3DXShader::CBaseProgram::CopyInstruction(this, a2: *((struct D3DXShader::CInstruction **)this + 64));
      if ( v25 >= 0 )
        **((_DWORD **)this + 64) = 0;
      return v25;
    }
    if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)) + 4) == *((_DWORD *)this + 33) )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x12D1u,
        format: "internal error: write to output with instruction other than mov");
      return -2147467259;
    }
    v98 = 0;
    if ( v97 == 0 )
      goto LABEL_167;
    v90 = 0;
    v99 = v78;
    jj = 4 * v7;
    while ( 1 )
    {
      v57 = v99;
      v58 = v99;
      *v99 = -1;
      *++v58 = -1;
      *++v58 = -1;
      v58[1] = -1;
      if ( v7 != 0 )
      {
        v59 = (_DWORD *)(v90 + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
        for ( i = v7; i != 0; --i )
          *v57++ = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v59++) + 16);
      }
      v95 = nullptr;
      v60 = &D3DXShader::g_Swizzle;
      while ( D3DXShader::CPSProgram::ValidSwizzle(this, a2: v99, a3: v60) == 0 )
      {
        v95 = (D3DXShader *)((char *)v95 + 16);
        v60 += 4;
        if ( (unsigned int)v95 >= 0x80 )
        {
          if ( (*((_BYTE *)this + 108) & 2) != 0 )
          {
            v25 = D3DXShader::CPSProgram::RemapInput(this, a2: &v91, a3: v7, a4: v97);
            if ( v25 < 0 )
              goto LABEL_203;
            if ( v91 != nullptr )
            {
              v25 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v91);
              if ( v25 < 0 )
                goto LABEL_203;
              v91 = nullptr;
            }
            v61 = D3DXShader::CInstruction::operator new(a1: 0x74u);
            if ( v61 != nullptr )
              v62 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v61);
            else
              v62 = nullptr;
            if ( v62 == nullptr )
              goto LABEL_192;
            v63 = *((_DWORD *)this + 2);
            v99 = nullptr;
            if ( v63 != 0 )
            {
              v64 = *((_DWORD *)this + 5);
              for ( i = v63; i != 0; --i )
              {
                v65 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(*(_DWORD *)v64 + 4)) + 4);
                if ( (v65 & 1) != 0 && (v65 & 2) != 0 && (unsigned int)v99 < *(_DWORD *)(*(_DWORD *)v64 + 12) + 1 )
                  v99 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)v64 + 12) + 1);
                v64 += 4;
              }
            }
            v25 = D3DXShader::CInstruction::Initialize(this: v62, a2: 0x20500001u, a3: 2u, a4: 1u, a5: 0);
            if ( v25 < 0 )
              goto LABEL_203;
            v25 = D3DXShader::CInstruction::Instance(this: v62, a2: *((struct D3DXShader::CInstruction **)this + 64));
            if ( v25 < 0 )
              goto LABEL_203;
            v66 = D3DXShader::CBaseProgram::AddArgument(
                    this,
                    a2: *((_DWORD *)this + 34),
                    a3: (unsigned int)v99,
                    a4: 0,
                    a5: 0.0);
            v99 = (unsigned int *)((char *)v99 + 1);
            i = v66;
            if ( v66 == -1 )
              goto LABEL_192;
            v67 = jj;
            **((_DWORD **)v62 + 4) = v66;
            **((_DWORD **)v62 + 2) = **(_DWORD **)(*((_DWORD *)this + 64) + 8);
            *(_DWORD *)(*((_DWORD *)v62 + 2) + 4) = *(_DWORD *)(v67 + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
            v25 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v62);
            if ( v25 < 0 )
              goto LABEL_203;
            m = 1;
            if ( v92 > 1 )
            {
              jj += 4;
              while ( 1 )
              {
                v68 = D3DXShader::CInstruction::operator new(a1: 0x74u);
                v69 = v68 != nullptr
                    ? (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v68)
                    : nullptr;
                if ( v69 == nullptr )
                  break;
                v25 = D3DXShader::CInstruction::Initialize(this: v69, a2: 0x70300001u, a3: 3u, a4: 1u, a5: 0);
                if ( v25 < 0 )
                  goto LABEL_203;
                v25 = D3DXShader::CInstruction::Instance(
                        this: v69,
                        a2: *((struct D3DXShader::CInstruction **)this + 64));
                if ( v25 < 0 )
                  goto LABEL_203;
                v70 = m;
                v71 = jj;
                **((_DWORD **)v69 + 2) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4 * m);
                *(_DWORD *)(*((_DWORD *)v69 + 2) + 4) = *(_DWORD *)(v71 + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
                *(_DWORD *)(*((_DWORD *)v69 + 2) + 8) = i;
                if ( v70 == v92 - 1 )
                {
                  v72 = **(_DWORD **)(*((_DWORD *)this + 64) + 16);
                }
                else
                {
                  v72 = D3DXShader::CBaseProgram::AddArgument(
                          this,
                          a2: *((_DWORD *)this + 34),
                          a3: (unsigned int)v99,
                          a4: 0,
                          a5: 0.0);
                  v99 = (unsigned int *)((char *)v99 + 1);
                  i = v72;
                  if ( v72 == -1 )
                    break;
                }
                **((_DWORD **)v69 + 4) = v72;
                v25 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v69);
                if ( v25 < 0 )
                  goto LABEL_203;
                ++m;
                jj += 4;
                if ( m >= v92 )
                  goto LABEL_168;
              }
LABEL_192:
              v25 = -2147024882;
              goto LABEL_203;
            }
LABEL_168:
            **((_DWORD **)this + 64) = 0;
            v25 = 0;
            goto LABEL_201;
          }
LABEL_167:
          v25 = D3DXShader::CBaseProgram::CopyInstruction(this, a2: *((struct D3DXShader::CInstruction **)this + 64));
          if ( v25 < 0 )
            return v25;
          goto LABEL_168;
        }
      }
      ++v98;
      v90 += jj;
      v99 += 4;
      if ( v98 >= v97 )
        goto LABEL_167;
    }
  }
  v98 = 0;
  if ( v97 != 0 )
  {
    v95 = nullptr;
    v90 = (int)v78;
    do
    {
      v9 = (_DWORD *)v90;
      v10 = v92 == 0;
      *(_DWORD *)v90 = -1;
      *++v9 = -1;
      *++v9 = -1;
      v9[1] = -1;
      if ( !v10 )
      {
        v11 = *((_DWORD *)this + 64);
        v12 = *(_DWORD *)(v11 + 16);
        v13 = *(_DWORD *)(v11 + 8);
        v14 = *((_DWORD *)this + 5);
        m = v12;
        v15 = 4 * v98;
        v16 = (_DWORD *)((char *)v95 + v13);
        jj = v92;
        do
        {
          v17 = *(_DWORD *)(*(_DWORD *)(v14 + 4 * *(_DWORD *)m) + 16);
          v18 = *(_DWORD *)(*(_DWORD *)(v14 + 4 * *v16) + 16);
          m += 4;
          ++v16;
          v10 = jj-- == 1;
          v78[v15 + v17] = v18;
        }
        while ( !v10 );
      }
      ++v98;
      v90 += 16;
      v95 = (D3DXShader *)((char *)v95 + 4 * v92);
    }
    while ( v98 < v97 );
  }
  if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                             + 4
                             * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                     + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16))
                                         + 4))
                 + 4)
      & 0x20) == 0 )
  {
    v98 = 0;
    if ( v97 != 0 )
    {
      v95 = (D3DXShader *)v78;
      do
      {
        v26 = &D3DXShader::g_Swizzle;
        v27 = 0;
        while ( D3DXShader::CPSProgram::ValidSwizzle(this, a2: (unsigned int *)v95, a3: v26) == 0 )
        {
          v27 += 16;
          v26 += 4;
          if ( v27 >= 0x80 )
          {
            v99 = (unsigned int *)1;
            goto LABEL_46;
          }
        }
        ++v98;
        v95 = (D3DXShader *)((char *)v95 + 16);
      }
      while ( v98 < v97 );
    }
    goto LABEL_46;
  }
  v19 = *((_DWORD *)this + 64);
  v20 = *((_DWORD *)this + 5);
  v74 = *(_DWORD *)(*(_DWORD *)(v20 + 4 * **(_DWORD **)(v19 + 16)) + 108);
  i = *(_DWORD *)(v20 + 4 * **(_DWORD **)(v19 + 8));
  v21 = (D3DXShader *)(*(int (__thiscall **)(D3DXShader::CPSProgram *, int))(*(_DWORD *)this + 84))(a1: this, a2: v74);
  v95 = v21;
  if ( v21 != (D3DXShader *)0xFFFF )
  {
    if ( v21 == (D3DXShader *)11 )
    {
      v22 = D3DXShader::CPSProgram::ValidSwizzle(this, a2: v78, a3: &dword_10336968) == 0;
      v99 = (unsigned int *)v22;
    }
    else
    {
      if ( v21 != (D3DXShader *)13 )
        goto LABEL_31;
      v23 = 0;
      jj = 0;
      v24 = &D3DXShader::g_Swizzle;
      while ( D3DXShader::CPSProgram::ValidSwizzle(this, a2: v78, a3: v24) == 0 )
      {
        v23 += 16;
        v24 += 4;
        if ( v23 >= 0x40 )
          goto LABEL_29;
      }
      jj = 1;
LABEL_29:
      v22 = jj == 0;
      v99 = (unsigned int *)v22;
    }
    if ( v22 )
    {
LABEL_32:
      v25 = D3DXShader::CPSProgram::RemapOutputMov(this, a2: &v89, a3: v92);
      if ( v25 < 0 )
        goto LABEL_201;
LABEL_33:
      v80 = 0;
      v81 = 0;
      v82 = 0;
      v83 = 0;
      if ( D3DXShader::IsValidSwizzle(this: (D3DXShader *)v78, a2: &v80, a3: v76) != 0
        || v95 == (D3DXShader *)13 && v78[0] == 0 )
      {
        v25 = D3DXShader::CShaderProgram::BuildInstruction(this, a2: &v80, a3: v97, a4: v92);
        if ( v25 < 0 )
          goto LABEL_201;
        **((_DWORD **)this + 64) = 0;
        if ( v89 != nullptr )
        {
          v25 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v89);
          if ( v25 < 0 )
            goto LABEL_201;
        }
        return v25;
      }
      goto LABEL_46;
    }
LABEL_31:
    if ( (*(_BYTE *)(i + 62) & 0x1F) == 0 )
      goto LABEL_33;
    goto LABEL_32;
  }
LABEL_46:
  v28 = *((_DWORD **)this + 64);
  v29 = *v28 & 0xFFF00000;
  if ( v29 == 282066944 || v29 == 283115520 )
  {
    v30 = v28[1];
    v31 = 0;
    if ( v30 != 0 )
    {
      v32 = *((_DWORD *)this + 5);
      v33 = (_DWORD *)v28[2];
      do
      {
        if ( (*(_BYTE *)(*(_DWORD *)(v32 + 4 * *v33) + 62) & 0x1F) != 0 )
          v31 = 1;
        ++v33;
        --v30;
      }
      while ( v30 != 0 );
      if ( v31 != 0 )
      {
        v34 = 0;
        if ( *((_DWORD *)this + 2) != 0 )
        {
          v35 = *((_DWORD *)this + 2);
          do
          {
            if ( *((_DWORD *)this + 34) == *(_DWORD *)(*(_DWORD *)v32 + 4) )
            {
              v36 = *(_DWORD *)(*(_DWORD *)v32 + 12);
              if ( v36 >= v34 )
                v34 = v36 + 1;
            }
            v32 += 4;
            --v35;
          }
          while ( v35 != 0 );
        }
        for ( j = 0; j < 4; ++j )
        {
          v38 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: v34, a4: j, a5: 0.0);
          v79[j] = v38;
          if ( v38 == -1 )
            goto LABEL_67;
        }
        v39 = D3DXShader::CInstruction::operator new(a1: 0x74u);
        if ( v39 != nullptr )
          v91 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v39);
        else
          v91 = nullptr;
        if ( v91 == nullptr )
        {
LABEL_67:
          v25 = -2147024882;
          goto LABEL_201;
        }
        v25 = D3DXShader::CInstruction::Initialize(
                this: v91,
                a2: *(_DWORD *)(*((_DWORD *)this + 64) + 4) & 0xFFFFF | 0x10000000,
                a3: *(_DWORD *)(*((_DWORD *)this + 64) + 4),
                a4: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                a5: 0);
        if ( v25 < 0 )
          goto LABEL_201;
        v25 = D3DXShader::CInstruction::Instance(this: v91, a2: *((struct D3DXShader::CInstruction **)this + 64));
        if ( v25 < 0 )
          goto LABEL_201;
        v40 = (void **)v91;
        qmemcpy(*((void **)v91 + 4), v79, 4 * *(_DWORD *)(*((_DWORD *)this + 64) + 12));
        qmemcpy(v40[2], *(const void **)(*((_DWORD *)this + 64) + 8), 4 * *(_DWORD *)(*((_DWORD *)this + 64) + 4));
        qmemcpy(*(void **)(*((_DWORD *)this + 64) + 8), v79, 4 * *(_DWORD *)(*((_DWORD *)this + 64) + 4));
        v25 = D3DXShader::CBaseProgram::AddInstruction(this, a2: (struct D3DXShader::CInstruction *)v40);
        if ( v25 < 0 )
          goto LABEL_201;
        v91 = nullptr;
      }
    }
  }
  if ( v99 == nullptr || (*((_BYTE *)this + 108) & 2) == 0 )
  {
    v25 = D3DXShader::CBaseProgram::CopyInstruction(this, a2: *((struct D3DXShader::CInstruction **)this + 64));
    if ( v25 < 0 )
      goto LABEL_201;
    goto LABEL_168;
  }
  v99 = nullptr;
  i = 0;
  if ( v92 != 4 )
  {
    if ( v92 != 3 )
      goto LABEL_139;
    i = -1;
    for ( k = 0; k < 4; ++k )
    {
      if ( v78[k] == -1 )
        i = k;
    }
    for ( m = 0; m < 4; ++m )
    {
      if ( v99 != nullptr )
        goto LABEL_135;
      for ( n = 0; n < 4; ++n )
      {
        if ( v99 != nullptr )
          break;
        if ( n != m )
        {
          v52 = i;
          if ( n != i && m != i )
          {
            v80 = -1;
            v81 = -1;
            v82 = -1;
            v83 = -1;
            memset(v84, 0, sizeof(v84));
            v53 = 0;
            v54 = m;
            *(unsigned int *)((char *)&v80 + v54 * 4) = 0;
            *(&v80 + n) = 0;
            v84[v54] = -1;
            v84[n] = -1;
            v84[v52] = -1;
            v98 = 0;
            if ( v97 == 0 )
              goto LABEL_131;
            v95 = (D3DXShader *)v78;
            do
            {
              if ( v98 != 0 )
                goto LABEL_132;
              v98 = D3DXShader::IsValidSwizzle(this: v95, a2: &v80, a3: v76) == 0;
              v95 = (D3DXShader *)((char *)v95 + 16);
              ++v53;
            }
            while ( v53 < v97 );
            if ( v98 == 0 )
LABEL_131:
              v99 = (unsigned int *)1;
          }
        }
LABEL_132:
        ;
      }
    }
    if ( v99 == nullptr )
      goto LABEL_139;
LABEL_135:
    v25 = D3DXShader::CShaderProgram::BuildInstruction(this, a2: &v80, a3: v97, a4: 3u);
    if ( v25 < 0 )
      goto LABEL_201;
    v49 = D3DXShader::CShaderProgram::BuildInstruction(this, a2: v84, a3: v97, a4: 3u);
    goto LABEL_137;
  }
  v98 = 1;
  for ( ii = 0; ii < 4; ++ii )
  {
    v80 = 0;
    v81 = 0;
    v82 = 0;
    v83 = 0;
    memset(v84, 255, sizeof(v84));
    v42 = v97;
    *(&v80 + ii) = -1;
    v84[ii] = 0;
    v98 = 0;
    if ( v42 == 0 )
      goto LABEL_89;
    v43 = v78;
    for ( jj = v42; jj != 0; --jj )
    {
      if ( D3DXShader::IsValidSwizzle(this: (D3DXShader *)v43, a2: &v80, a3: v76) == 0
        || D3DXShader::IsValidSwizzle(this: (D3DXShader *)v43, a2: &v80, a3: v76) == 0 )
      {
        v98 = 1;
      }
      v43 += 4;
    }
    if ( v98 == 0 )
    {
LABEL_89:
      v25 = D3DXShader::CShaderProgram::BuildInstruction(this, a2: &v80, a3: v97, a4: 4u);
      if ( v25 < 0 )
        goto LABEL_201;
      v25 = D3DXShader::CShaderProgram::BuildInstruction(this, a2: v84, a3: v97, a4: 4u);
      if ( v25 < 0 )
        goto LABEL_201;
      goto LABEL_142;
    }
  }
  m = 0;
  v98 = 1;
  do
  {
    if ( v98 == 0 )
      break;
    v44 = 0;
    v95 = nullptr;
    do
    {
      v45 = m;
      if ( v44 == m )
        goto LABEL_103;
      v80 = 0;
      v81 = 0;
      v82 = 0;
      v83 = 0;
      memset(v84, 255, sizeof(v84));
      *(&v80 + m) = -1;
      *(&v80 + v44) = -1;
      v10 = v97 == 0;
      v84[v45] = 0;
      v84[v44] = 0;
      v98 = 0;
      v90 = 0;
      if ( v10 )
      {
LABEL_105:
        v99 = (unsigned int *)1;
        break;
      }
      v46 = v78;
      jj = v97;
      do
      {
        IsValidSwizzle = D3DXShader::IsValidSwizzle(this: (D3DXShader *)v46, a2: &v80, a3: v76);
        v47 = D3DXShader::IsValidSwizzle(this: (D3DXShader *)v46, a2: v84, a3: v77);
        if ( IsValidSwizzle != 0 )
        {
          if ( v47 != 0 )
            goto LABEL_99;
        }
        else
        {
          v90 = 1;
        }
        v98 = 1;
LABEL_99:
        v46 += 4;
        --jj;
      }
      while ( jj != 0 );
      if ( v98 == 0 )
        goto LABEL_105;
      if ( v90 == 0 )
      {
        v85[0] = v80;
        v85[1] = v81;
        v85[2] = v82;
        v85[3] = v83;
        memset(v86, 255, sizeof(v86));
        memset(v87, 255, sizeof(v87));
        v86[m] = 0;
        v48 = v95;
        v87[(_DWORD)v95] = 0;
        i = 1;
        v44 = (unsigned int)v48;
      }
LABEL_103:
      v95 = (D3DXShader *)++v44;
    }
    while ( v44 < 4 );
    ++m;
  }
  while ( m < 4 );
  if ( v99 == nullptr )
  {
    if ( i == 0 )
      goto LABEL_139;
    v99 = (unsigned int *)1;
    v25 = D3DXShader::CShaderProgram::BuildInstruction(this, a2: v85, a3: v97, a4: 4u);
    if ( v25 < 0 )
      goto LABEL_201;
    v25 = D3DXShader::CShaderProgram::BuildInstruction(this, a2: v86, a3: v97, a4: 4u);
    if ( v25 < 0 )
      goto LABEL_201;
    v49 = D3DXShader::CShaderProgram::BuildInstruction(this, a2: v87, a3: v97, a4: 4u);
LABEL_137:
    v25 = v49;
    if ( v49 < 0 )
      goto LABEL_201;
    if ( v99 == nullptr )
    {
LABEL_139:
      v55 = 0;
      if ( v92 != 0 )
      {
        do
        {
          v56 = *((_DWORD *)this + 5);
          v75 = v92;
          v73 = v97;
          v80 = -1;
          v81 = -1;
          v82 = -1;
          v83 = -1;
          *(&v80
          + *(_DWORD *)(*(_DWORD *)(v56 + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 16) + 4 * v55)) + 16)) = 0;
          v25 = D3DXShader::CShaderProgram::BuildInstruction(this, a2: &v80, a3: v73, a4: v75);
          if ( v25 < 0 )
            goto LABEL_201;
        }
        while ( ++v55 < v92 );
      }
    }
LABEL_142:
    if ( v89 != nullptr )
    {
      v25 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v89);
      if ( v25 < 0 )
        goto LABEL_201;
      v89 = nullptr;
    }
    goto LABEL_168;
  }
  v25 = D3DXShader::CShaderProgram::BuildInstruction(this, a2: &v80, a3: v97, a4: 4u);
  if ( v25 >= 0 )
  {
    v49 = D3DXShader::CShaderProgram::BuildInstruction(this, a2: v84, a3: v97, a4: 4u);
    goto LABEL_137;
  }
LABEL_201:
  if ( v89 != nullptr )
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v89, a2: 1);
LABEL_203:
  if ( v91 != nullptr )
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v91, a2: 1);
  return v25;
}

//------------------------------------------------------------------------------
// Address: 0x1020F925
// Name: protected: virtual long D3DXShader::CPSProgram::SrcSwizzle(unsigned int __near *,unsigned int,unsigned long,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::SrcSwizzle(
        D3DXShader::CPSProgram *this,
        unsigned int *a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned int *a5)
{
  int v6; // esi
  unsigned int v7; // eax
  int v8; // edx
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // eax
  unsigned int i; // eax
  unsigned int v15; // eax
  int v16; // edi
  unsigned int v17; // edx
  int v18; // esi
  unsigned int *v19; // eax
  unsigned int v21; // edx
  unsigned int j; // ecx
  unsigned int v23; // esi
  unsigned int v24[4]; // [esp+Ch] [ebp-24h] BYREF
  _DWORD v25[4]; // [esp+1Ch] [ebp-14h] BYREF
  int v26; // [esp+2Ch] [ebp-4h]
  unsigned int *v27; // [esp+3Ch] [ebp+Ch]
  unsigned int v28; // [esp+40h] [ebp+10h]

  v6 = *((_DWORD *)this + 5);
  v7 = 4 * *a2;
  v26 = *(_DWORD *)(v6 + v7);
  v8 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v26 + 4));
  v9 = 0;
  if ( *(char *)(v8 + 4) < 0 )
  {
    *a5 = 14942208;
    return 0;
  }
  if ( (a4 & 0x10000) != 0 )
  {
    v25[0] = 0;
    v9 = 1;
  }
  if ( (a4 & 0x20000) != 0 )
    v25[v9++] = 1;
  if ( (a4 & 0x40000) != 0 )
    v25[v9++] = 2;
  if ( (a4 & 0x80000) != 0 )
    v25[v9++] = 3;
  if ( (unsigned int)a3 > v9 )
    a3 = (unsigned int *)v9;
  v28 = (int)(*((_DWORD *)this + 27) << 30) >> 31;
  if ( (*((_DWORD *)this + 27) & 2) != 0 )
  {
    v10 = -1;
LABEL_24:
    v24[0] = v10;
    v24[1] = v10;
    v24[2] = v10;
    v24[3] = v10;
    goto LABEL_25;
  }
  v11 = 0;
  if ( a3 != nullptr )
  {
    v12 = *((_DWORD *)this + 5);
    v13 = *(_DWORD *)(*(_DWORD *)(v12 + v7) + 16);
    do
    {
      if ( v13 != *(_DWORD *)(*(_DWORD *)(v12 + 4 * a2[v11]) + 16) )
        break;
      ++v11;
    }
    while ( v11 < (unsigned int)a3 );
    if ( v11 < (unsigned int)a3 )
    {
      for ( i = 0; i < 4; ++i )
        v24[i] = i;
LABEL_25:
      v15 = 0;
      if ( a3 != nullptr )
      {
        do
        {
          v16 = v25[v15];
          v17 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * *(_DWORD *)((char *)&v25[v15++] + (char *)a2 - (char *)v25)) + 16);
          v24[v16] = v17;
        }
        while ( v15 < (unsigned int)a3 );
      }
      v18 = 0;
      if ( v28 == 0 )
      {
        v19 = v24;
LABEL_35:
        v21 = 0;
        for ( j = 16; j < 0x18; j += 2 )
        {
          v23 = *v19++ << j;
          v21 |= v23;
        }
        *a5 = v21;
        return 0;
      }
      v27 = D3DXShader::g_Swizzle;
      while ( D3DXShader::CPSProgram::ValidSwizzle(this, a2: v24, a3: v27) == 0 )
      {
        v27 += 4;
        if ( (unsigned int)++v18 >= 8 )
          goto LABEL_33;
      }
      v19 = &D3DXShader::g_Swizzle[4 * v18];
      if ( v19 != nullptr )
        goto LABEL_35;
LABEL_33:
      D3DXShader::CProgram::Error(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x12D2u,
        format: "internal error: invalid swizzle found");
      return -2147467259;
    }
  }
  v10 = *(_DWORD *)(v26 + 16);
  goto LABEL_24;
}

//------------------------------------------------------------------------------
// Address: 0x1020FAD4
// Name: protected: virtual long D3DXShader::CPSProgram::Constrain(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::Constrain(D3DXShader::CPSProgram *this)
{
  int result; // eax
  unsigned int v3; // ebx
  int v4; // edi
  int v5; // eax

  result = D3DXShader::CShaderProgram::ConstrainPorts(this);
  if ( result >= 0 )
  {
    D3DXShader::CShaderProgram::Reset(this);
    v3 = *((_DWORD *)this + 3);
    v4 = 0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v5 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v4);
        *((_DWORD *)this + 64) = v5;
        *((_DWORD *)this + 63) = v4;
        if ( (*(_WORD *)(v5 + 2) & 0xFFF0) != 0 )
        {
          result = D3DXShader::CPSProgram::Unswizzle(this, a2: (unsigned int *)this);
          if ( result < 0 )
            break;
        }
        if ( ++v4 >= v3 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      result = D3DXShader::CProgram::RemoveDeadCode(this);
      if ( result >= 0 )
      {
        result = D3DXShader::CProgram::CompactArguments(this);
        if ( result >= 0 )
        {
          result = D3DXShader::CProgram::CompactInstructions(this);
          if ( result >= 0 )
          {
            D3DXShader::CShaderProgram::Reset(this);
            return 0;
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020FB4C
// Name: protected: virtual int D3DXShader::CPSProgram::IsDPNoSwizzle(class D3DXShader::CInstruction __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::IsDPNoSwizzle(D3DXShader::CPSProgram *this, struct D3DXShader::CInstruction *a2)
{
  unsigned int v2; // ebx
  int v4; // eax
  int v5; // esi
  unsigned int v6; // ecx
  int v7; // edx
  _DWORD *v8; // eax
  unsigned int v9; // edi
  unsigned int v10[4]; // [esp+4h] [ebp-24h] BYREF
  unsigned int v11; // [esp+14h] [ebp-14h]
  D3DXShader::CPSProgram *v12; // [esp+18h] [ebp-10h]
  unsigned int v13; // [esp+1Ch] [ebp-Ch]
  int v14; // [esp+20h] [ebp-8h]
  unsigned int *v15; // [esp+24h] [ebp-4h]

  v2 = *(_DWORD *)a2 & 0xFFFFF;
  v12 = this;
  if ( v2 == 0 )
    return 1;
  v4 = *((_DWORD *)a2 + 1) / v2;
  v13 = 0;
  v11 = v4;
  if ( v4 == 0 )
    return 0;
  v5 = (int)(*((_DWORD *)this + 27) << 30) >> 31;
  v14 = 0;
  while ( 1 )
  {
    memset(v10, 255, sizeof(v10));
    v6 = 0;
    v7 = *((_DWORD *)v12 + 5);
    v8 = (_DWORD *)(v14 + *((_DWORD *)a2 + 2));
    do
      v10[v6++] = *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v8++) + 16);
    while ( v6 < v2 );
    if ( v5 != 0 )
    {
      v9 = 0;
      v15 = D3DXShader::g_Swizzle;
      do
      {
        if ( D3DXShader::CPSProgram::ValidSwizzle(this: v12, a2: v10, a3: v15) != 0 )
          break;
        v15 += 4;
        ++v9;
      }
      while ( v9 < 8 );
      if ( v9 == 8 )
        break;
    }
    ++v13;
    v14 += 4 * v2;
    if ( v13 >= v11 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1020FC15
// Name: protected: virtual long D3DXShader::CPSProgram::EmitInstructions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::EmitInstructions(D3DXShader::CPSProgram *this)
{
  unsigned int v2; // esi
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  struct D3DXShader::CInstruction *v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // eax
  unsigned int v11; // esi
  int v12; // edi
  int v13; // eax
  int v14; // ecx
  unsigned __int8 *v16; // eax
  D3DXShader::CInstruction *v17; // esi
  unsigned __int8 *v18; // eax
  D3DXShader::CInstruction *v19; // esi
  int v20; // eax
  D3DXShader::CInstruction *v21; // ecx
  unsigned int i; // eax
  int v23; // eax
  int v24; // ecx
  const void *v25; // esi
  unsigned int v26; // eax
  D3DXShader::CInstruction *v27; // ecx
  unsigned __int8 *v28; // eax
  int v29; // ecx
  int v30; // edx
  int v31; // edi
  unsigned int v32; // eax
  int v33; // esi
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // ecx
  void *v38; // eax
  int v39; // eax
  _DWORD v41[4]; // [esp+Ch] [ebp-34h] BYREF
  _DWORD v42[4]; // [esp+1Ch] [ebp-24h] BYREF
  unsigned int v43; // [esp+2Ch] [ebp-14h]
  unsigned int v44; // [esp+30h] [ebp-10h]
  int v45; // [esp+34h] [ebp-Ch]
  unsigned int v46; // [esp+38h] [ebp-8h]
  D3DXShader::CInstruction *v47; // [esp+3Ch] [ebp-4h]

  v2 = 0;
  v3 = 0;
  v43 = *((_DWORD *)this + 3);
  v47 = nullptr;
  if ( v43 != 0 )
  {
    do
    {
      v4 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v2;
      *((_DWORD *)this + 64) = *(_DWORD *)(v4 + 4 * v2);
      D3DXShader::CShaderProgram::SortInstruction(this);
      ++v2;
    }
    while ( v2 < *((_DWORD *)this + 3) );
  }
  v5 = 0;
  v44 = 0;
  if ( v43 == 0 )
  {
LABEL_66:
    D3DXShader::CShaderProgram::Reset(this);
    v33 = 0;
    v43 = *((_DWORD *)this + 3);
    if ( v43 == 0 )
      return 0;
    while ( 1 )
    {
      v34 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v33;
      v35 = *(_DWORD *)(v34 + 4 * v33);
      *((_DWORD *)this + 64) = v35;
      v36 = *(_DWORD *)(v35 + 60);
      if ( v36 != 0 && *(_DWORD *)(v36 + 4) == 13 )
        *((_DWORD *)this + 65) = v36 + 48;
      v37 = *((_DWORD *)this + 64);
      v38 = (void *)(*(_DWORD *)v37 & 0xFFF00000);
      if ( v38 != nullptr
        && *(_DWORD *)(v37 + 4) != 0
        && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v37 + 8)) + 8) != -1 )
      {
        D3DXShader::CProgram::Error(
          this,
          a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
          a3: 0x119Fu,
          format: "relative addressing not allowed for pixel shaders");
        return 0;
      }
      if ( (unsigned int)v38 > 0x60500000 )
        break;
      if ( v38 == (void *)1615855616 )
        goto LABEL_150;
      if ( (unsigned int)v38 > 0x20100000 )
      {
        if ( (unsigned int)v38 <= 0x50000000 )
        {
          if ( v38 == (void *)1342177280 )
          {
            v39 = D3DXShader::CShaderProgram::EmitDOT(this);
          }
          else if ( v38 == (void *)538968064 )
          {
            v39 = D3DXShader::CPSProgram::PSEmitLT(this);
          }
          else if ( v38 == (void *)540016640 )
          {
            v39 = D3DXShader::CPSProgram::PSEmitGE(this);
          }
          else if ( v38 == (void *)541065216 )
          {
            v39 = D3DXShader::CShaderProgram::EmitADD(this);
          }
          else if ( v38 == (void *)542113792 )
          {
            v39 = D3DXShader::CShaderProgram::EmitMUL(this);
          }
          else if ( v38 == (void *)544210944 )
          {
            v39 = D3DXShader::CShaderProgram::EmitENDIF(this);
          }
          else
          {
            if ( v38 != (void *)805306368 )
              goto LABEL_180;
            v39 = D3DXShader::CShaderProgram::EmitCMP(this);
          }
          goto LABEL_173;
        }
        if ( v38 != (void *)1345323008 )
        {
          if ( v38 == (void *)1610612736 )
            goto LABEL_150;
          if ( v38 != (void *)1611661312 )
          {
            if ( v38 == (void *)1612709888 )
              goto LABEL_149;
            if ( v38 != (void *)1613758464 )
            {
              if ( v38 != (void *)1614807040 )
                goto LABEL_180;
LABEL_128:
              if ( (*((_BYTE *)this + 112) & 0x20) == 0 )
              {
                D3DXShader::CProgram::Error(
                  this,
                  a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
                  a3: 0x11B4u,
                  format: "texlod not supported on this target");
                return 0;
              }
              v39 = D3DXShader::CShaderProgram::EmitTEXLOD(this);
              goto LABEL_173;
            }
LABEL_148:
            v39 = D3DXShader::CShaderProgram::EmitTEXBias(this);
            goto LABEL_173;
          }
LABEL_141:
          v39 = D3DXShader::CShaderProgram::EmitTEXDD(this);
          goto LABEL_173;
        }
        v39 = D3DXShader::CShaderProgram::EmitSINCOS(this);
      }
      else
      {
        if ( v38 == (void *)537919488 )
          goto LABEL_172;
        if ( (unsigned int)v38 <= 0x10600000 )
        {
          if ( v38 == (void *)274726912 )
          {
            v39 = D3DXShader::CShaderProgram::EmitLOG(this);
          }
          else
          {
            if ( v38 == nullptr )
              goto LABEL_174;
            if ( v38 == (void *)0x10000000 )
            {
              v39 = D3DXShader::CShaderProgram::EmitMOV(this);
            }
            else if ( v38 == &loc_10100000 )
            {
              v39 = D3DXShader::CShaderProgram::EmitNEG(this);
            }
            else if ( v38 == &unk_10300000 )
            {
              v39 = D3DXShader::CShaderProgram::EmitRCP(this);
            }
            else if ( v38 == (void *)272629760 )
            {
              v39 = D3DXShader::CShaderProgram::EmitFRC(this);
            }
            else
            {
              if ( v38 != (void *)273678336 )
                goto LABEL_180;
              v39 = D3DXShader::CShaderProgram::EmitEXP(this);
            }
          }
          goto LABEL_173;
        }
        if ( v38 == (void *)275775488 )
        {
          v39 = D3DXShader::CShaderProgram::EmitRSQ(this);
          goto LABEL_173;
        }
        if ( v38 == (void *)282066944 )
        {
          if ( (*((_BYTE *)this + 112) & 0x10) == 0 )
          {
LABEL_103:
            v3 = -2147467263;
            goto LABEL_174;
          }
          v39 = D3DXShader::CShaderProgram::EmitDSX(this);
        }
        else
        {
          if ( v38 != (void *)283115520 )
          {
            if ( v38 == (void *)284164096 )
              goto LABEL_170;
            if ( v38 == (void *)285212672 )
            {
              v39 = D3DXShader::CShaderProgram::EmitCLIP(this);
              goto LABEL_173;
            }
            if ( v38 != (void *)0x20000000 )
              goto LABEL_180;
            goto LABEL_99;
          }
          if ( (*((_BYTE *)this + 112) & 0x10) == 0 )
            goto LABEL_103;
          v39 = D3DXShader::CShaderProgram::EmitDSY(this);
        }
      }
LABEL_173:
      v3 = v39;
LABEL_174:
      if ( v3 == -2147467263 )
        goto LABEL_180;
      if ( ++v33 >= v43 )
        return 0;
    }
    if ( (unsigned int)v38 <= 0x61300000 )
    {
      if ( v38 == (void *)1630535680 )
        goto LABEL_128;
      if ( (unsigned int)v38 > 0x60C00000 )
      {
        if ( v38 == (void *)1624244224 )
          goto LABEL_148;
        if ( v38 == (void *)1625292800 )
          goto LABEL_128;
        if ( v38 == (void *)1626341376 )
        {
LABEL_150:
          v39 = D3DXShader::CShaderProgram::EmitTEX(this);
          goto LABEL_173;
        }
        if ( v38 != (void *)1627389952 )
        {
          if ( v38 == (void *)1628438528 )
          {
LABEL_149:
            v39 = D3DXShader::CShaderProgram::EmitTEXProj(this);
            goto LABEL_173;
          }
          if ( v38 != (void *)1629487104 )
            goto LABEL_180;
          goto LABEL_148;
        }
      }
      else
      {
        if ( v38 == (void *)1623195648 )
          goto LABEL_149;
        if ( v38 != (void *)1616904192 )
        {
          if ( v38 == (void *)1617952768 )
            goto LABEL_149;
          if ( v38 == (void *)1619001344 )
            goto LABEL_148;
          if ( v38 == (void *)1620049920 )
            goto LABEL_128;
          if ( v38 == (void *)1621098496 )
            goto LABEL_150;
          if ( v38 != (void *)1622147072 )
            goto LABEL_180;
        }
      }
      goto LABEL_141;
    }
    if ( (unsigned int)v38 > 0x70B00000 )
    {
      if ( v38 == (void *)1891631104 )
      {
LABEL_172:
        v39 = D3DXShader::CPSProgram::PSEmitMax(this);
        goto LABEL_173;
      }
      if ( v38 == (void *)1892679680 )
      {
        v39 = D3DXShader::CShaderProgram::EmitPOW(this);
        goto LABEL_173;
      }
      if ( v38 != (void *)1934622720
        && v38 != (void *)1935671296
        && v38 != (void *)1936719872
        && v38 != (void *)1937768448 )
      {
LABEL_180:
        D3DXShader::CProgram::Error(
          this,
          a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
          a3: 0x11B4u,
          format: "cannot map expression to pixel shader instruction set");
        goto LABEL_181;
      }
LABEL_170:
      v39 = D3DXShader::CShaderProgram::EmitIF(this);
      goto LABEL_173;
    }
    if ( v38 != (void *)1890582528 )
    {
      if ( v38 == (void *)1879048192 )
      {
        v39 = D3DXShader::CShaderProgram::EmitABS(this);
      }
      else if ( v38 == (void *)1880096768 )
      {
        v39 = D3DXShader::CShaderProgram::EmitLRP(this);
      }
      else if ( v38 == (void *)1881145344 )
      {
        v39 = D3DXShader::CShaderProgram::EmitNRM(this);
      }
      else if ( v38 == (void *)1882193920 || v38 == (void *)1883242496 )
      {
        v39 = D3DXShader::CShaderProgram::EmitMAD(this);
      }
      else
      {
        if ( v38 != (void *)1887436800 )
          goto LABEL_180;
        v39 = D3DXShader::CShaderProgram::EmitDP2ADD(this);
      }
      goto LABEL_173;
    }
LABEL_99:
    v39 = D3DXShader::CPSProgram::PSEmitMin(this);
    goto LABEL_173;
  }
  while ( 1 )
  {
    v6 = *((_DWORD *)this + 6);
    *((_DWORD *)this + 63) = v5;
    v7 = *(struct D3DXShader::CInstruction **)(v6 + 4 * v5);
    *((_DWORD *)this + 64) = v7;
    v8 = *(_DWORD *)v7 & 0xFFF00000;
    if ( v8 == 1615855616
      || v8 == 1626341376
      || v8 == 1621098496
      || v8 == 1612709888
      || v8 == 1617952768
      || v8 == 1623195648
      || v8 == 1628438528
      || v8 == 1613758464
      || v8 == 1619001344
      || v8 == 1624244224
      || v8 == 1629487104
      || v8 == 1610612736
      || v8 == 285212672 )
    {
      break;
    }
    v9 = D3DXShader::CBaseProgram::CopyInstruction(this, a2: v7);
LABEL_64:
    v3 = v9;
    if ( v9 < 0 )
      return 0;
    **((_DWORD **)this + 64) = 0;
    v5 = ++v44;
    if ( v44 >= v43 )
      goto LABEL_66;
  }
  v10 = *(_DWORD *)v7;
  v11 = v10 & 0xFFFFF;
  v45 = v10 & 0xFFFFF;
  if ( (v10 & 0xFFF00000) == 0x11000000 )
    v45 = 0;
  v46 = 0;
  if ( v11 != 0 )
  {
    v12 = 4 * v45;
    do
    {
      v13 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v12 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)));
      if ( *(_DWORD *)(v13 + 16) != v46 || (*(_BYTE *)(v13 + 62) & 0x1F) != 0 )
        break;
      v14 = *(_DWORD *)(v13 + 4);
      if ( !(v14 == *((_DWORD *)this + 32)
           ? (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD))(*(_DWORD *)this + 84))(
               a1: this,
               a2: *(_DWORD *)(v13 + 108)) == 6
           : v14 == *((_DWORD *)this + 34)) )
        break;
      ++v46;
      v12 += 4;
    }
    while ( v46 < v11 );
  }
  if ( (**((_DWORD **)this + 64) & 0xFFF00000) == 0x60000000 && v11 == 1 )
  {
    if ( (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD, _DWORD *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
           a1: this,
           a2: *((_DWORD *)this + 63),
           a3: v42,
           a4: 4,
           a5: 0,
           a6: 0) < 0 )
      return 0;
    v16 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v16 != nullptr )
      v17 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v16);
    else
      v17 = nullptr;
    v47 = v17;
    if ( v17 == nullptr )
      return -2147024882;
    if ( D3DXShader::CInstruction::Initialize(this: v17, a2: 0x10000002u, a3: 2u, a4: 2u, a5: 0) < 0 )
      goto LABEL_181;
    if ( D3DXShader::CInstruction::Instance(this: v17, a2: *((struct D3DXShader::CInstruction **)this + 64)) < 0 )
      goto LABEL_181;
    **((_DWORD **)v17 + 2) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4);
    *(_DWORD *)(*((_DWORD *)v17 + 2) + 4) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4);
    **((_DWORD **)v17 + 4) = v42[0];
    *(_DWORD *)(*((_DWORD *)v17 + 4) + 4) = v42[1];
    if ( (D3DXShader::CBaseProgram::AddInstruction(this, a2: v17) & 0x80000000) != 0 )
      goto LABEL_181;
    v18 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v18 != nullptr )
      v19 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v18);
    else
      v19 = nullptr;
    v46 = (unsigned int)v19;
    if ( v19 == nullptr )
      return 0;
    v20 = D3DXShader::CInstruction::Initialize(
            this: v19,
            a2: 0x60500002u,
            a3: 4u,
            a4: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
            a5: 0);
    v21 = v19;
    if ( v20 < 0 )
      goto LABEL_182;
    if ( D3DXShader::CInstruction::Instance(this: v19, a2: *((struct D3DXShader::CInstruction **)this + 64)) < 0 )
    {
      v21 = v19;
      goto LABEL_182;
    }
    for ( i = 2; i < 4; ++i )
    {
      *(_DWORD *)(i * 4 + *((_DWORD *)v19 + 2) - 8) = **(_DWORD **)(*((_DWORD *)this + 64) + 8);
      *(_DWORD *)(i * 4 + *((_DWORD *)v19 + 2)) = v41[i + 2];
    }
    v23 = *((_DWORD *)this + 64);
    v24 = *(_DWORD *)(v23 + 12);
    v25 = *(const void **)(v23 + 16);
    v26 = v46;
    qmemcpy(*(void **)(v46 + 16), v25, 4 * v24);
    v27 = *((D3DXShader::CInstruction **)this + 64);
    if ( v27 != nullptr )
    {
      D3DXShader::CInstruction::`scalar deleting destructor'(this: v27, a2: 1);
      v26 = v46;
    }
    *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v44) = v26;
    *((_DWORD *)this + 64) = v26;
    goto LABEL_62;
  }
  if ( v46 == v11 )
  {
LABEL_63:
    v9 = D3DXShader::CBaseProgram::CopyInstruction(this, a2: *((struct D3DXShader::CInstruction **)this + 64));
    goto LABEL_64;
  }
  if ( (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD, _DWORD *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
         a1: this,
         a2: *((_DWORD *)this + 63),
         a3: v41,
         a4: 4,
         a5: 0,
         a6: 0) < 0 )
    return 0;
  v28 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v28 != nullptr )
    v47 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v28);
  else
    v47 = nullptr;
  if ( v47 == nullptr )
    return -2147024882;
  if ( D3DXShader::CInstruction::Initialize(this: v47, a2: v11 & 0xFFFFF | 0x10000000, a3: v11, a4: v11, a5: 0) >= 0
    && D3DXShader::CInstruction::Instance(this: v47, a2: *((struct D3DXShader::CInstruction **)this + 64)) >= 0 )
  {
    v46 = 0;
    if ( v11 != 0 )
    {
      v29 = 4 * v45;
      do
      {
        v30 = *(_DWORD *)(v29 + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
        v31 = *((_DWORD *)v47 + 2);
        v32 = 4 * v46++;
        *(_DWORD *)(v32 + v31) = v30;
        *(_DWORD *)(v32 + *((_DWORD *)v47 + 4)) = v41[v32 / 4];
        *(_DWORD *)(v29 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)) = *(_DWORD *)(v32 + *((_DWORD *)v47 + 4));
        v29 += 4;
      }
      while ( v46 < v11 );
    }
    if ( (D3DXShader::CBaseProgram::AddInstruction(this, a2: v47) & 0x80000000) == 0 )
    {
LABEL_62:
      v47 = nullptr;
      goto LABEL_63;
    }
  }
LABEL_181:
  v21 = v47;
  if ( v47 == nullptr )
    return 0;
LABEL_182:
  D3DXShader::CInstruction::`scalar deleting destructor'(this: v21, a2: 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10210487
// Name: protected: virtual int D3DXShader::CPSProgram::ViolatesPortConstraints(class D3DXShader::CInstruction __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::ViolatesPortConstraints(
        D3DXShader::CPSProgram *this,
        struct D3DXShader::CInstruction *a2,
        unsigned int *a3)
{
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // edi
  int v10; // eax
  bool v11; // zf
  _DWORD *v12; // edi
  int v13; // eax
  unsigned int v14; // eax
  int v15; // edx
  _DWORD *v16; // ecx
  _DWORD *v17; // eax
  unsigned int v18; // edx
  unsigned int v19; // ecx
  _DWORD *v20; // eax
  _DWORD v21[36]; // [esp+8h] [ebp-B0h] BYREF
  int v22; // [esp+98h] [ebp-20h]
  unsigned int v23; // [esp+9Ch] [ebp-1Ch]
  int v24; // [esp+A0h] [ebp-18h]
  int v25; // [esp+A4h] [ebp-14h]
  int v26; // [esp+A8h] [ebp-10h]
  unsigned int v27; // [esp+ACh] [ebp-Ch]
  unsigned int v28; // [esp+B0h] [ebp-8h]
  unsigned int v29; // [esp+B4h] [ebp-4h]

  if ( a2 == nullptr )
    return 1;
  v5 = *(_DWORD *)a2;
  if ( (*(_DWORD *)a2 & 0xFFF00000) == 0 || (*(_DWORD *)a2 & 0xFFF00000) == 0x20700000 )
    return 0;
  v29 = v5 & 0xFFFFF;
  v23 = *((_DWORD *)a2 + 1) / (v5 & 0xFFFFFu);
  if ( v23 <= 1 )
    return 0;
  v6 = *((_DWORD *)this + 34);
  v7 = *((_DWORD *)this + 31);
  v8 = *((_DWORD *)this + 32);
  v21[v8 + 18] = 0;
  v6 *= 4;
  *(_DWORD *)((char *)&v21[18] + v6) = 0;
  v7 *= 4;
  *(_DWORD *)((char *)&v21[18] + v7) = 0;
  v9 = *((_DWORD *)this + 37);
  v21[v8] = 1;
  v9 *= 4;
  *(_DWORD *)((char *)&v21[18] + v9) = 0;
  v10 = 0;
  v11 = v23 == 0;
  *(_DWORD *)((char *)v21 + v6) = 3;
  *(_DWORD *)((char *)v21 + v7) = 1;
  *(_DWORD *)((char *)v21 + v9) = 1;
  v26 = 0;
  v27 = 0;
  if ( v11 )
    return 0;
  v24 = 0;
  v25 = 4 * v29;
  while ( 1 )
  {
    v12 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v10 + *((_DWORD *)a2 + 2)));
    v22 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v12[1]);
    v13 = *(_DWORD *)(v22 + 4);
    if ( (v13 & 0x200) != 0 )
    {
      if ( (v13 & 0x80u) == 0 )
      {
        v14 = *((_DWORD *)this + 31);
        goto LABEL_18;
      }
LABEL_13:
      v14 = *((_DWORD *)this + 37);
      goto LABEL_18;
    }
    if ( (v13 & 0x80u) != 0 )
      goto LABEL_13;
    v14 = (v13 & 0x10) == 0
       || (*(int (__thiscall **)(D3DXShader::CPSProgram *, _DWORD))(*(_DWORD *)this + 84))(a1: this, a2: v12[27]) == 0xFFFF
        ? *((_DWORD *)this + 34)
        : *((_DWORD *)this + 32);
LABEL_18:
    v29 = 0;
    v28 = v14;
    if ( v27 != 0 )
    {
      v15 = *((_DWORD *)this + 5);
      v16 = *((_DWORD **)a2 + 2);
      do
      {
        v17 = *(_DWORD **)(v15 + 4 * *v16);
        if ( v12[1] == v17[1] && v12[2] == v17[2] && v12[3] == v17[3] )
          break;
        ++v29;
        v16 = (_DWORD *)((char *)v16 + v25);
      }
      while ( v29 < v27 );
    }
    v18 = v27;
    if ( v29 == v27 && v28 < 0x12 )
    {
      v19 = v28;
      v20 = &v21[v28 + 18];
      if ( ++*v20 > v21[v19] )
        break;
    }
    if ( (*(_BYTE *)(v22 + 5) & 2) != 0 && (unsigned int)++v26 > 2 )
      break;
    v10 = v25 + v24;
    v27 = v18 + 1;
    v24 += v25;
    if ( v18 + 1 >= v23 )
      return 0;
  }
  if ( a3 != nullptr )
    *a3 = v18;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021065C
// Name: public: D3DXShader::CVSProgram::CVSProgram(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CVSProgram *__thiscall D3DXShader::CVSProgram::CVSProgram(D3DXShader::CVSProgram *this, int a2)
{
  D3DXShader::CShaderProgram::CShaderProgram(this);
  *((_DWORD *)this + 86) = a2;
  *(_DWORD *)this = &D3DXShader::CVSProgram::`vftable';
  *((_DWORD *)this + 60) = &D3DXShader::g_VS20InputSemantic;
  *((_DWORD *)this + 61) = &D3DXShader::g_VS20OutputSemantic;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10210693
// Name: protected: virtual long D3DXShader::CVSProgram::InitCaps(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::InitCaps(D3DXShader::CVSProgram *this)
{
  int v1; // edx
  int v2; // eax
  int v4; // eax
  int v5; // eax

  v1 = *((_DWORD *)this + 50);
  *((_DWORD *)this + 28) |= 0x40u;
  v2 = *((_DWORD *)this + 28);
  *((_DWORD *)this + 66) = v1;
  switch ( v1 )
  {
    case -130815:
      *((_BYTE *)this + 111) |= 1u;
      *((_DWORD *)this + 25) = 10;
      v4 = v2 | 0x2002;
      goto LABEL_10;
    case -130560:
      v4 = v2 | 2;
      *((_DWORD *)this + 27) |= 0x200100u;
      *((_DWORD *)this + 12) = 1;
      *((_DWORD *)this + 24) = 16;
      *((_DWORD *)this + 16) = 16;
      *((_DWORD *)this + 26) = 255;
      *((_DWORD *)this + 25) = 1;
      *((_DWORD *)this + 21) = 8;
      *((_DWORD *)this + 23) = 1;
LABEL_10:
      *((_DWORD *)this + 11) = 12;
      break;
    case -130558:
      v4 = v2 | 4;
      *((_DWORD *)this + 27) |= 0x40200100u;
      *((_DWORD *)this + 11) = 13;
      *((_DWORD *)this + 12) = 1;
      *((_DWORD *)this + 24) = 16;
      *((_DWORD *)this + 16) = 16;
      *((_DWORD *)this + 26) = 255;
      *((_DWORD *)this + 25) = 1;
      *((_DWORD *)this + 21) = 8;
      *((_DWORD *)this + 22) = 24;
      *((_DWORD *)this + 23) = 1;
      *((_DWORD *)this + 50) = -130559;
      break;
    case -130305:
      v4 = v2 | 4;
      *((_DWORD *)this + 27) |= 0x40200100u;
      *((_DWORD *)this + 11) = 32;
      *((_DWORD *)this + 12) = 1;
      *((_DWORD *)this + 24) = 2048;
      *((_DWORD *)this + 16) = 2048;
      *((_DWORD *)this + 26) = 255;
      *((_DWORD *)this + 25) = 1;
      *((_DWORD *)this + 21) = 16;
      *((_DWORD *)this + 22) = 24;
      *((_DWORD *)this + 23) = 4;
      break;
    default:
      D3DXShader::CProgram::Error(
        this,
        a2: nullptr,
        a3: 0,
        format: "internal error: no profile exists for this vertex shader version");
      return -2147467259;
  }
  *((_DWORD *)this + 27) |= 0x40u;
  *((_DWORD *)this + 28) = v4;
  v5 = *((_DWORD *)this + 11);
  *((_BYTE *)this + 113) |= 3u;
  *((_DWORD *)this + 116) = v5;
  *((_DWORD *)this + 10) = 16;
  *((_DWORD *)this + 14) = 0x2000;
  *((_DWORD *)this + 17) = 16;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102107E5
// Name: protected: virtual long D3DXShader::CVSProgram::ValidateOutput(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CVSProgram::ValidateOutput(D3DXShader::CVSProgram *this)
{
  unsigned int result; // eax
  bool v3; // zf
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  unsigned int i; // eax
  int v9; // [esp-Ch] [ebp-38h]
  _DWORD v10[4]; // [esp+4h] [ebp-28h] BYREF
  int v11; // [esp+14h] [ebp-18h]
  struct D3DXShader::CNode *v12; // [esp+18h] [ebp-14h]
  int v13; // [esp+1Ch] [ebp-10h]
  int v14; // [esp+20h] [ebp-Ch]
  int v15; // [esp+24h] [ebp-8h]
  unsigned int v16; // [esp+28h] [ebp-4h]

  result = 0;
  if ( *((_DWORD *)this + 86) == 0 )
  {
    v3 = *((_DWORD *)this + 2) == 0;
    memset(v10, 0, sizeof(v10));
    v14 = 0;
    v13 = 0;
    v15 = 0;
    v12 = nullptr;
    v16 = 0;
    if ( !v3 )
    {
      do
      {
        v4 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v16);
        if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v4 + 4)) + 4) & 0x20) != 0 )
        {
          v5 = (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD))(*(_DWORD *)this + 84))(
                 a1: this,
                 a2: *(_DWORD *)(v4 + 108));
          v9 = *(_DWORD *)(v4 + 108);
          v11 = v5;
          v6 = (*(int (__thiscall **)(D3DXShader::CVSProgram *, int))(*(_DWORD *)this + 88))(a1: this, a2: v9);
          if ( v11 == 1 )
          {
            if ( v6 == 0 )
            {
              v10[*(_DWORD *)(v4 + 16)] = 1;
              v12 = *(struct D3DXShader::CNode **)(v4 + 96);
            }
            goto LABEL_18;
          }
          if ( v11 == 5 )
          {
            if ( v6 != 0 || *(_DWORD *)(v4 + 16) == 0 || v13 != 0 )
              goto LABEL_18;
            D3DXShader::CProgram::Error(
              this,
              a2: *(struct D3DXShader::CNode **)(v4 + 96),
              a3: 0x11BCu,
              format: "PSIZE must be a scalar");
            v13 = 1;
          }
          else
          {
            if ( v11 != 12 || v6 != 0 || *(_DWORD *)(v4 + 16) == 0 || v14 != 0 )
              goto LABEL_18;
            D3DXShader::CProgram::Error(
              this,
              a2: *(struct D3DXShader::CNode **)(v4 + 96),
              a3: 0x11BCu,
              format: "FOG must be a scalar");
            v14 = 1;
          }
          v15 = 1;
        }
LABEL_18:
        ++v16;
      }
      while ( v16 < *((_DWORD *)this + 2) );
    }
    v7 = 0;
    for ( i = 0; i < 4; ++i )
    {
      if ( v10[i] != 0 )
        ++v7;
    }
    if ( v7 != 4 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: v12,
        a3: 0x11BDu,
        format: "vertex shader must minimally write all four components of POSITION");
      v15 = 1;
    }
    return v15 != 0 ? 0x80004005 : 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10210926
// Name: protected: virtual long D3DXShader::CVSProgram::FindOutput(class D3DXShader::CArgument __near *,unsigned long __near &,unsigned long __near &,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::FindOutput(
        D3DXShader::CVSProgram *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3,
        unsigned int *a4,
        int *a5)
{
  int v6; // ebx

  v6 = (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD))(*(_DWORD *)this + 84))(
         a1: this,
         a2: *((_DWORD *)a2 + 27));
  *a3 = (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD))(*(_DWORD *)this + 88))(
          a1: this,
          a2: *((_DWORD *)a2 + 27));
  if ( a5 != nullptr )
    *a5 = 0;
  switch ( v6 )
  {
    case 1:
      if ( *a3 == 0 )
      {
        *a4 = 4;
        *a3 = 0;
        return 0;
      }
      return -2147467259;
    case 5:
      if ( *a3 != 0 )
        return -2147467259;
      *a4 = 4;
      *a3 = 2;
LABEL_9:
      if ( a5 != nullptr )
        *a5 = 1;
      return 0;
    case 0xC:
      if ( *a3 != 0 )
        return -2147467259;
      *a4 = 4;
      *a3 = 1;
      goto LABEL_9;
    case 0xB:
      if ( *a3 < 2 )
      {
        *a4 = 5;
        return 0;
      }
      break;
    case 6:
      if ( *a3 < 8 )
      {
        *a4 = 6;
        return 0;
      }
      break;
    case 0xFFFF:
      *a4 = 0;
      return 0;
    default:
      break;
  }
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x102109E8
// Name: protected: virtual long D3DXShader::CVSProgram::FindInput(class D3DXShader::CArgument __near *,unsigned long __near &,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::FindInput(
        D3DXShader::CVSProgram *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3,
        unsigned int *a4)
{
  unsigned int v5; // eax

  if ( (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD))(*(_DWORD *)this + 84))(
         a1: this,
         a2: *((_DWORD *)a2 + 27)) == 0xFFFF )
  {
    *a4 = 0;
    v5 = (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD))(*(_DWORD *)this + 88))(
           a1: this,
           a2: *((_DWORD *)a2 + 27));
  }
  else
  {
    *a4 = 1;
    v5 = *((_DWORD *)a2 + 3);
  }
  *a3 = v5;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10210A2B
// Name: public: virtual long D3DXShader::CVSProgram::GenerateCode(struct ID3DXBuffer __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::GenerateCode(D3DXShader::CVSProgram *this, struct ID3DXBuffer **a2)
{
  *((_DWORD *)this + 85) = (unsigned __int16)*((_DWORD *)this + 50) > 0x100u;
  return D3DXShader::CShaderProgram::GenerateCode(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10210A52
// Name: protected: virtual long D3DXShader::CVSProgram::Translate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::Translate(D3DXShader::CVSProgram *this)
{
  int v2; // edi
  int v3; // eax
  int *v4; // ecx
  unsigned int v5; // eax
  int result; // eax
  int v7; // edi
  int v8; // eax
  _DWORD *v9; // eax
  void *v10; // eax
  int v11; // edi
  int v12; // eax
  _DWORD *v13; // eax
  unsigned int v14; // eax
  unsigned int j; // edi
  int v16; // eax
  _DWORD *v17; // eax
  unsigned int v18; // eax
  int v19; // edi
  int v20; // eax
  _DWORD *v21; // eax
  int v22; // edi
  int v23; // eax
  _DWORD *v24; // eax
  unsigned int v25; // eax
  unsigned int i; // edi
  int v27; // eax
  _DWORD *v28; // eax
  unsigned int v29; // eax
  int v30; // edi
  int v31; // eax
  _DWORD *v32; // eax
  int v33; // edi
  int v34; // eax
  _DWORD *v35; // eax
  int v36; // edi
  int v37; // eax
  _DWORD *v38; // eax
  int v39; // edi
  int v40; // eax
  _DWORD *v41; // eax
  void *v42; // eax
  int v43; // edi
  int v44; // eax
  _DWORD *v45; // eax

  v2 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    while ( 1 )
    {
      v3 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v2;
      v4 = *(int **)(v3 + 4 * v2);
      *((_DWORD *)this + 64) = v4;
      v5 = *v4 & 0xFFF00000;
      if ( v5 == 272629760 )
        break;
      if ( v5 == 289406976 )
      {
        result = D3DXShader::CShaderProgram::MatchBREAK(this);
        goto LABEL_8;
      }
LABEL_9:
      if ( (unsigned int)++v2 >= *((_DWORD *)this + 3) )
        goto LABEL_10;
    }
    if ( (*((_BYTE *)this + 113) & 0x20) != 0 )
      *v4 = v4[3] & 0xFFFFF | 0x71000000;
    result = 0;
LABEL_8:
    if ( result < 0 )
      return result;
    goto LABEL_9;
  }
LABEL_10:
  if ( (*((_BYTE *)this + 204) & 4) != 0 )
  {
LABEL_66:
    D3DXShader::CShaderProgram::Reset(this);
    v22 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      do
      {
        v23 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v22;
        v24 = *(_DWORD **)(v23 + 4 * v22);
        *((_DWORD *)this + 64) = v24;
        v25 = *v24 & 0xFFF00000;
        if ( v25 == 1952448512 || v25 == 1953497088 )
        {
          result = D3DXShader::CShaderProgram::MatchBREAK_NEEQ(this);
          if ( result < 0 )
            return result;
          result = D3DXShader::CShaderProgram::MatchBREAK_NEEQ2(this);
          if ( result < 0 )
            return result;
        }
      }
      while ( (unsigned int)++v22 < *((_DWORD *)this + 3) );
    }
    for ( i = 0; i < *((_DWORD *)this + 3); ++i )
    {
      v27 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = i;
      v28 = *(_DWORD **)(v27 + 4 * i);
      *((_DWORD *)this + 64) = v28;
      v29 = *v28 & 0xFFF00000;
      if ( v29 == 1950351360 || v29 == 1951399936 || v29 == 1952448512 || v29 == 1953497088 )
        D3DXShader::CShaderProgram::MatchBREAK_COND(this);
    }
    v30 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      do
      {
        v31 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v30;
        v32 = *(_DWORD **)(v31 + 4 * v30);
        *((_DWORD *)this + 64) = v32;
        if ( (*v32 & 0xFFF00000) == 0x20900000 )
        {
          result = D3DXShader::CShaderProgram::FoldBreak(this);
          if ( result < 0 )
            return result;
        }
      }
      while ( (unsigned int)++v30 < *((_DWORD *)this + 3) );
    }
    v33 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      do
      {
        v34 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v33;
        v35 = *(_DWORD **)(v34 + 4 * v33);
        *((_DWORD *)this + 64) = v35;
        if ( (*v35 & 0xFFF00000) == 0x11400000 )
        {
          result = D3DXShader::CShaderProgram::MatchBREAK2(this);
          if ( result < 0 )
            return result;
        }
      }
      while ( (unsigned int)++v33 < *((_DWORD *)this + 3) );
    }
    v36 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      do
      {
        v37 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v36;
        v38 = *(_DWORD **)(v37 + 4 * v36);
        *((_DWORD *)this + 64) = v38;
        if ( (*v38 & 0xFFF00000) == 0x70300000 )
        {
          result = (unsigned __int16)*((_DWORD *)this + 50) < 0x200u
                 ? 1
                 : D3DXShader::CShaderProgram::MatchLRP2((struct D3DXShader::CInstruction **)this, a2: 0);
          if ( result < 0 )
            return result;
        }
      }
      while ( (unsigned int)++v36 < *((_DWORD *)this + 3) );
    }
    D3DXShader::CShaderProgram::Reset(this);
    v39 = 0;
    if ( *((_DWORD *)this + 3) == 0 )
    {
LABEL_107:
      D3DXShader::CShaderProgram::Reset(this);
      v43 = 0;
      if ( *((_DWORD *)this + 3) != 0 )
      {
        while ( 1 )
        {
          v44 = *((_DWORD *)this + 6);
          *((_DWORD *)this + 63) = v43;
          v45 = *(_DWORD **)(v44 + 4 * v43);
          *((_DWORD *)this + 64) = v45;
          if ( (*v45 & 0xFFF00000) == 0x50300000 )
          {
            result = D3DXShader::CShaderProgram::MatchSINCOS(this);
            if ( result < 0 )
              break;
          }
          if ( (unsigned int)++v43 >= *((_DWORD *)this + 3) )
            goto LABEL_111;
        }
      }
      else
      {
LABEL_111:
        result = D3DXShader::CProgram::RemoveDeadCode(this);
        if ( result >= 0 )
        {
          result = D3DXShader::CProgram::RemoveDuplicateArguments(this);
          if ( result >= 0 )
          {
            result = D3DXShader::CProgram::CompactInstructions(this);
            if ( result >= 0 )
            {
              result = D3DXShader::CProgram::CompactArguments(this);
              if ( result >= 0 )
              {
                D3DXShader::CShaderProgram::Reset(this);
                return 0;
              }
            }
          }
        }
      }
      return result;
    }
    while ( 1 )
    {
      v40 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v39;
      v41 = *(_DWORD **)(v40 + 4 * v39);
      *((_DWORD *)this + 64) = v41;
      v42 = (void *)(*v41 & 0xFFF00000);
      if ( v42 == &unk_10300000
        || v42 == (void *)273678336
        || v42 == (void *)274726912
        || v42 == (void *)275775488
        || v42 == (void *)1342177280 )
      {
        break;
      }
      if ( v42 == (void *)1882193920 )
      {
        if ( (unsigned __int16)*((_DWORD *)this + 50) < 0x200u )
          result = 1;
        else
          result = D3DXShader::CShaderProgram::MatchLRP(this);
LABEL_105:
        if ( result < 0 )
          return result;
      }
      if ( (unsigned int)++v39 >= *((_DWORD *)this + 3) )
        goto LABEL_107;
    }
    result = D3DXShader::CShaderProgram::MatchRepMov(this);
    goto LABEL_105;
  }
  v7 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    while ( 1 )
    {
      v8 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v7;
      v9 = *(_DWORD **)(v8 + 4 * v7);
      *((_DWORD *)this + 64) = v9;
      v10 = (void *)(*v9 & 0xFFF00000);
      if ( v10 == &loc_10100000 )
      {
        result = D3DXShader::CShaderProgram::MatchNEG(this, a2: 1);
        goto LABEL_27;
      }
      if ( v10 == (void *)273678336 )
        break;
      if ( v10 == (void *)284164096 )
      {
        result = D3DXShader::CShaderProgram::MatchIF2((struct D3DXShader::CInstruction **)this);
        goto LABEL_27;
      }
      if ( v10 == (void *)289406976 )
      {
        result = D3DXShader::CShaderProgram::MatchBREAK(this);
        goto LABEL_27;
      }
      if ( v10 == (void *)537919488 )
      {
        if ( (unsigned __int16)*((_DWORD *)this + 50) < 0x200u )
          result = 1;
        else
          result = D3DXShader::CShaderProgram::MatchMAX(this);
        goto LABEL_27;
      }
      if ( v10 == (void *)541065216 )
      {
        result = D3DXShader::CShaderProgram::MatchComplexMad(this, a2: 1);
        goto LABEL_27;
      }
LABEL_28:
      if ( (unsigned int)++v7 >= *((_DWORD *)this + 3) )
        goto LABEL_29;
    }
    if ( (unsigned __int16)*((_DWORD *)this + 50) < 0x200u )
      result = 1;
    else
      result = D3DXShader::CShaderProgram::MatchPOW(this);
LABEL_27:
    if ( result < 0 )
      return result;
    goto LABEL_28;
  }
LABEL_29:
  result = D3DXShader::CProgram::RemoveDeadCode(this);
  if ( result >= 0 )
  {
    D3DXShader::CShaderProgram::Reset(this);
    v11 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      while ( 1 )
      {
        v12 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v11;
        v13 = *(_DWORD **)(v12 + 4 * v11);
        *((_DWORD *)this + 64) = v13;
        v14 = *v13 & 0xFFF00000;
        if ( v14 == 542113792 )
        {
          if ( (unsigned __int16)*((_DWORD *)this + 50) < 0x200u )
            result = 1;
          else
            result = D3DXShader::CShaderProgram::MatchNRM(this);
          goto LABEL_46;
        }
        if ( v14 == 1882193920 )
        {
          if ( (unsigned __int16)*((_DWORD *)this + 50) < 0x200u )
            result = 1;
          else
            result = D3DXShader::CShaderProgram::MatchLRP2((struct D3DXShader::CInstruction **)this, a2: 1);
          goto LABEL_46;
        }
        if ( v14 == 1934622720 || v14 == 1935671296 )
          break;
        if ( v14 == 1952448512 || v14 == 1953497088 )
        {
          result = D3DXShader::CShaderProgram::MatchBREAK_NEEQ(this);
          if ( result < 0 )
            return result;
          result = D3DXShader::CShaderProgram::MatchBREAK_NEEQ2(this);
          goto LABEL_46;
        }
LABEL_47:
        if ( (unsigned int)++v11 >= *((_DWORD *)this + 3) )
          goto LABEL_48;
      }
      result = D3DXShader::CShaderProgram::MatchNEEQ(this);
      if ( result < 0 )
        return result;
      result = D3DXShader::CShaderProgram::MatchNEEQ2(this);
LABEL_46:
      if ( result < 0 )
        return result;
      goto LABEL_47;
    }
LABEL_48:
    for ( j = 0; j < *((_DWORD *)this + 3); ++j )
    {
      v16 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = j;
      v17 = *(_DWORD **)(v16 + 4 * j);
      *((_DWORD *)this + 64) = v17;
      v18 = *v17 & 0xFFF00000;
      if ( v18 > 0x74400000 )
      {
        if ( v18 == 1951399936 || v18 == 1952448512 || v18 == 1953497088 )
        {
LABEL_59:
          result = D3DXShader::CShaderProgram::MatchBREAK_COND(this);
LABEL_60:
          if ( result < 0 )
            return result;
        }
      }
      else
      {
        if ( v18 == 1950351360 )
          goto LABEL_59;
        if ( v18 == 1934622720 || v18 == 1935671296 || v18 == 1936719872 || v18 == 1937768448 )
        {
          result = D3DXShader::CShaderProgram::MatchIFCOND(this);
          goto LABEL_60;
        }
      }
    }
    v19 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      while ( 1 )
      {
        v20 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v19;
        v21 = *(_DWORD **)(v20 + 4 * v19);
        *((_DWORD *)this + 64) = v21;
        if ( (*v21 & 0xFFF00000) == 0x73700000 )
        {
          result = D3DXShader::CShaderProgram::MatchNEZero(this);
          if ( result < 0 )
            return result;
        }
        if ( (unsigned int)++v19 >= *((_DWORD *)this + 3) )
          goto LABEL_66;
      }
    }
    goto LABEL_66;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10210F64
// Name: protected: virtual long D3DXShader::C30Program::Constrain(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::Constrain(D3DXShader::C30Program *this)
{
  int result; // eax

  result = D3DXShader::CShaderProgram::ConstrainPorts(this);
  if ( result >= 0 )
  {
    result = D3DXShader::CProgram::RemoveDeadCode(this);
    if ( result >= 0 )
    {
      result = D3DXShader::CProgram::CompactArguments(this);
      if ( result >= 0 )
      {
        result = D3DXShader::CProgram::CompactInstructions(this);
        if ( result >= 0 )
        {
          D3DXShader::CShaderProgram::Reset(this);
          return 0;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10210F9E
// Name: protected: virtual long D3DXShader::CVSProgram::EmitSize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::EmitSize(D3DXShader::CVSProgram *this)
{
  if ( (unsigned __int16)*((_DWORD *)this + 50) >= 0x200u )
    *(_DWORD *)(*((_DWORD *)this + 67) + 4 * *((_DWORD *)this + 70)) |= (*((_DWORD *)this + 68)
                                                                       - *((_DWORD *)this + 70)
                                                                       - 1) << 24;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10210FD0
// Name: protected: long D3DXShader::CVSProgram::VSMatchDOT(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::VSMatchDOT(D3DXShader::CVSProgram *this)
{
  int v1; // edi
  unsigned int v2; // esi
  struct D3DXShader::CInstruction *Match; // ebx
  int v4; // edx
  int v5; // eax
  _DWORD *v6; // ecx
  unsigned __int8 *v7; // eax
  int v8; // esi
  D3DXShader::CInstruction *v9; // edi
  int v10; // ecx
  char *v11; // edi
  char *v12; // esi
  char v13; // al
  unsigned int v14; // ecx
  char *v15; // edi
  char *v16; // esi
  D3DXShader::CInstruction *v17; // eax
  D3DXShader::CShaderProgram *v18; // esi
  D3DXShader::CInstruction *v19; // ecx
  int result; // eax
  int v21; // eax
  bool v22; // zf
  unsigned int **v23; // esi
  struct D3DXShader::CInstruction *v24; // ebx
  _DWORD *v25; // edi
  D3DXShader::CInstruction *v26; // eax
  int v27; // esi
  int v28; // ecx
  unsigned int v29; // eax
  unsigned int v30; // ecx
  _DWORD *v31; // edx
  unsigned __int8 *v32; // eax
  void **v33; // edi
  D3DXShader::CInstruction *v34; // eax
  D3DXShader::CShaderProgram *v35; // esi
  D3DXShader::CInstruction *v36; // ecx
  struct D3DXShader::CInstruction *v37; // [esp-4h] [ebp-34h]
  unsigned int **v38; // [esp+Ch] [ebp-24h]
  int v39; // [esp+10h] [ebp-20h]
  int v40; // [esp+14h] [ebp-1Ch]
  int i; // [esp+18h] [ebp-18h]
  unsigned int v42; // [esp+18h] [ebp-18h]
  unsigned int v43; // [esp+1Ch] [ebp-14h]
  unsigned int v44; // [esp+1Ch] [ebp-14h]
  unsigned int v45; // [esp+20h] [ebp-10h] BYREF
  int v46; // [esp+24h] [ebp-Ch]
  D3DXShader::CInstruction *v47; // [esp+28h] [ebp-8h]
  D3DXShader::CShaderProgram *v48; // [esp+2Ch] [ebp-4h]

  v1 = *((_DWORD *)this + 64);
  v2 = *(_DWORD *)v1 & 0xFFFFF;
  v48 = this;
  v46 = v1;
  if ( v2 < 3 )
    return 0;
  Match = D3DXShader::CShaderProgram::FindMatch(
            this,
            a2: 0x10000002u,
            a3: (unsigned int **)v1,
            a4: nullptr,
            a5: 2u,
            a6: 1u);
  if ( Match != nullptr
    || (Match = D3DXShader::CShaderProgram::FindMatch(
                  this: v48,
                  a2: 0x10000003u,
                  a3: (unsigned int **)v1,
                  a4: nullptr,
                  a5: 2u,
                  a6: 1u)) != nullptr
    || (Match = D3DXShader::CShaderProgram::FindMatch(
                  this: v48,
                  a2: 0x10000004u,
                  a3: (unsigned int **)v1,
                  a4: nullptr,
                  a5: 2u,
                  a6: 1u)) != nullptr )
  {
    v4 = **((_DWORD **)Match + 4);
    v47 = *((D3DXShader::CInstruction **)v48 + 5);
    if ( *(_DWORD *)(*((_DWORD *)v47 + v4) + 4) == *((_DWORD *)v48 + 33) )
    {
      v5 = *(_DWORD *)Match & 0xFFFFF;
      v43 = 1;
      if ( v5 == 0 )
        goto LABEL_13;
      v45 = **(_DWORD **)(v1 + 16);
      v6 = *((_DWORD **)Match + 2);
      for ( i = v5; i != 0; --i )
      {
        if ( *v6 != v45 || (*(_DWORD *)(*((_DWORD *)v47 + *v6) + 52) & 0x1FFE00) != 0 )
          v43 = 0;
        ++v6;
      }
      if ( v43 != 0 )
      {
LABEL_13:
        v7 = D3DXShader::CInstruction::operator new(a1: 0x74u);
        if ( v7 != nullptr )
          v47 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v7);
        else
          v47 = nullptr;
        if ( v47 != nullptr )
        {
          v8 = D3DXShader::CInstruction::Initialize(
                 this: v47,
                 a2: v2 & 0xFFFFF | 0x50000000,
                 a3: *(_DWORD *)(v1 + 4),
                 a4: *((_DWORD *)Match + 3),
                 a5: 0);
          if ( v8 < 0 )
          {
            v9 = v47;
          }
          else
          {
            v37 = (struct D3DXShader::CInstruction *)v1;
            v9 = v47;
            v8 = D3DXShader::CInstruction::Instance(this: v47, a2: v37);
            if ( v8 >= 0 )
            {
              v10 = *((_DWORD *)v47 + 3);
              v11 = *((char **)v47 + 4);
              v12 = *((char **)Match + 4);
              v13 = 4 * v10;
              v14 = (unsigned int)(4 * v10) >> 2;
              qmemcpy(v11, v12, 4 * v14);
              v16 = &v12[4 * v14];
              v15 = &v11[4 * v14];
              LOBYTE(v14) = v13;
              v17 = v47;
              qmemcpy(v15, v16, v14 & 3);
              qmemcpy(*((void **)v47 + 2), *(const void **)(v46 + 8), 4 * *((_DWORD *)v47 + 1));
              *(_DWORD *)Match = 0;
              v18 = v48;
              v19 = *((D3DXShader::CInstruction **)v48 + 64);
              if ( v19 != nullptr )
              {
                D3DXShader::CInstruction::`scalar deleting destructor'(this: v19, a2: 1);
                v17 = v47;
              }
              *(_DWORD *)(*((_DWORD *)v48 + 6) + 4 * *((_DWORD *)v48 + 63)) = v17;
              *((_DWORD *)v18 + 64) = v17;
              return 0;
            }
          }
          D3DXShader::CInstruction::`scalar deleting destructor'(this: v9, a2: 1);
          return v8;
        }
        return -2147024882;
      }
    }
  }
  if ( v2 != 3 )
    return 0;
  if ( (unsigned __int16)*((_DWORD *)v48 + 50) < 0x200u )
    return 0;
  v21 = *((_DWORD *)v48 + 64);
  v22 = memcmp(*(const void **)(v21 + 8), (const void *)(*(_DWORD *)(v21 + 8) + 12), 0xCu) == 0;
  v46 = v21;
  if ( !v22 )
    return 0;
  v23 = (unsigned int **)D3DXShader::CShaderProgram::FindMatch(
                           this: v48,
                           a2: 0x10700001u,
                           a3: (unsigned int **)v21,
                           a4: nullptr,
                           a5: 2u,
                           a6: 1u);
  v38 = v23;
  if ( v23 == nullptr )
    return 0;
  v24 = D3DXShader::CShaderProgram::FindMatch(this: v48, a2: 0x20500003u, a3: v23, a4: &v45, a5: 2u, a6: 1u);
  if ( v24 == nullptr )
  {
    v24 = D3DXShader::CShaderProgram::FindMatch(this: v48, a2: 0x20500004u, a3: v23, a4: &v45, a5: 2u, a6: 1u);
    if ( v24 == nullptr )
      return 0;
  }
  v25 = *(_DWORD **)(v46 + 8);
  v26 = *((D3DXShader::CInstruction **)v48 + 5);
  v27 = *((_DWORD *)v24 + 2);
  v40 = *((_DWORD *)v26 + *v25);
  v28 = **((_DWORD **)v24 + 4);
  v47 = v26;
  v39 = *((_DWORD *)v26 + v28);
  v29 = *(_DWORD *)v24 & 0xFFFFF;
  v42 = 4 * v29;
  v44 = v29;
  if ( memcmp((const void *)(4 * v29 + v27), v25, 0xCu) != 0 )
    return 0;
  v30 = 0;
  if ( v29 != 0 )
  {
    v31 = *((_DWORD **)v24 + 4);
    while ( *(_DWORD *)(*((_DWORD *)v47 + *v31) + 16) == v30 )
    {
      ++v30;
      ++v31;
      if ( v30 >= v29 )
        goto LABEL_35;
    }
    return 0;
  }
LABEL_35:
  if ( *(_DWORD *)(v40 + 4) == *(_DWORD *)(v39 + 4) && *(_DWORD *)(v40 + 12) == *(_DWORD *)(v39 + 12) )
    return 0;
  v32 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v32 != nullptr )
  {
    v33 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v32);
    v47 = (D3DXShader::CInstruction *)v33;
  }
  else
  {
    v47 = nullptr;
    v33 = nullptr;
  }
  if ( v33 == nullptr )
    return -2147024882;
  result = D3DXShader::CInstruction::Initialize(
             this: (D3DXShader::CInstruction *)v33,
             a2: v44 & 0xFFFFF | 0x70200000,
             a3: v44,
             a4: v44,
             a5: 0);
  if ( result >= 0 )
  {
    result = D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)v33, a2: v24);
    if ( result >= 0 )
    {
      qmemcpy(v33[4], *((const void **)v24 + 4), v42);
      v34 = v47;
      qmemcpy(*((void **)v47 + 2), (const void *)(v42 + *((_DWORD *)v24 + 2)), v42);
      v35 = v48;
      if ( (*(int (__thiscall **)(D3DXShader::CShaderProgram *, D3DXShader::CInstruction *, _DWORD))(*(_DWORD *)v48 + 32))(
             a1: v48,
             a2: v34,
             a3: 0) == 0 )
      {
        *(_DWORD *)v46 = 0;
        *v38 = nullptr;
        *(_DWORD *)v24 = 0;
        if ( (*(int (__thiscall **)(D3DXShader::CShaderProgram *, D3DXShader::CInstruction *, unsigned int))(*(_DWORD *)v35 + 52))(
               a1: v35,
               a2: v47,
               a3: v45) == 0 )
        {
          v36 = *(D3DXShader::CInstruction **)(*((_DWORD *)v35 + 6) + 4 * v45);
          if ( v36 != nullptr )
            D3DXShader::CInstruction::`scalar deleting destructor'(this: v36, a2: 1);
          *(_DWORD *)(*((_DWORD *)v35 + 6) + 4 * v45) = v47;
          return 0;
        }
        *(_DWORD *)v46 = 1342177283;
        *v38 = (unsigned int *)275775489;
        *(_DWORD *)v24 = v44 | 0x20500000;
      }
      D3DXShader::CInstruction::`scalar deleting destructor'(this: v47, a2: 1);
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102113B5
// Name: protected: virtual long D3DXShader::CPSProgram::EmitVersion(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::EmitVersion(D3DXShader::CPSProgram *this)
{
  int result; // eax

  if ( *((_DWORD *)this + 86) != 0 )
    result = D3DXShader::CShaderProgram::Emit(this, a2: *((_DWORD *)this + 50) & 0x7FFFFFFF);
  else
    result = D3DXShader::CShaderProgram::Emit(this, a2: *((_DWORD *)this + 50));
  if ( result >= 0 )
  {
    result = D3DXShader::CShaderProgram::ValidateInst(this);
    if ( result >= 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102113EF
// Name: protected: virtual long D3DXShader::CVSProgram::EmitDCL(class D3DXShader::CArgument __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::EmitDCL(
        struct D3DXShader::CRegisterEntryNode **this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3)
{
  void *v4; // eax
  unsigned int v5; // edi
  struct D3DXShader::D3DX_SEMANTIC *Semantic; // eax
  int result; // eax
  int v8; // eax
  int v9; // edi
  void *v10; // eax
  int v11; // edi
  unsigned int *v12; // eax
  unsigned int v13; // ecx
  bool v14; // zf
  int v15; // edi
  int v16; // ecx
  _DWORD *v17; // eax
  int v18; // edx
  unsigned int i; // ecx
  unsigned int v20; // eax
  unsigned int v21; // [esp-8h] [ebp-50h]
  int v22; // [esp-4h] [ebp-4Ch]
  int v23; // [esp-4h] [ebp-4Ch]
  int v24; // [esp+Ch] [ebp-3Ch] BYREF
  int v25; // [esp+10h] [ebp-38h] BYREF
  unsigned int *v26; // [esp+14h] [ebp-34h]
  int v27; // [esp+18h] [ebp-30h] BYREF
  void *pMem; // [esp+1Ch] [ebp-2Ch]
  unsigned int v29; // [esp+20h] [ebp-28h]
  char string[16]; // [esp+24h] [ebp-24h] BYREF
  unsigned int v31[4]; // [esp+34h] [ebp-14h] BYREF

  v22 = *((_DWORD *)a2 + 27);
  v26 = a3;
  v4 = (void *)(*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, int))*this + 21))(a1: this, a2: v22);
  v23 = *((_DWORD *)a2 + 27);
  pMem = v4;
  v5 = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, int))*this + 22))(a1: this, a2: v23);
  if ( *(this + 86) == nullptr )
  {
    switch ( (unsigned int)pMem )
    {
      case 0u:
        return 1;
      case 1u:
        v29 = 0;
        goto LABEL_18;
      case 2u:
        v29 = 1;
        goto LABEL_18;
      case 3u:
        v29 = 2;
        goto LABEL_18;
      case 4u:
        v29 = 3;
        goto LABEL_18;
      case 5u:
        v29 = 4;
        goto LABEL_18;
      case 6u:
        v29 = 5;
        goto LABEL_18;
      case 7u:
        v29 = 6;
        goto LABEL_18;
      case 8u:
        v29 = 7;
        goto LABEL_18;
      case 9u:
        v29 = 8;
        if ( v5 != 0 )
          return -2147467259;
        goto LABEL_19;
      case 0xAu:
        v29 = 9;
        goto LABEL_18;
      case 0xBu:
        v29 = 10;
        goto LABEL_18;
      case 0xCu:
        v29 = 11;
        goto LABEL_18;
      case 0xDu:
        v29 = 12;
        goto LABEL_18;
      case 0xEu:
        v29 = 13;
LABEL_18:
        if ( v5 > 0xF )
          return -2147467259;
LABEL_19:
        v29 |= (v5 | 0xFFFF8000) << 16;
        result = D3DXShader::CShaderProgram::EmitInst((D3DXShader::CShaderProgram *)this, a2: 0x1Fu);
        if ( result < 0 )
          return result;
        result = D3DXShader::CShaderProgram::Emit((D3DXShader::CShaderProgram *)this, a2: v29);
        if ( result < 0 )
          return result;
        if ( (*(_BYTE *)(this + 51) & 1) != 0 )
        {
          v27 = 0;
          pMem = nullptr;
          v14 = *(this + 2) == nullptr;
          memset(v31, 255, sizeof(v31));
          if ( !v14 )
          {
            v15 = *((_DWORD *)a2 + 1);
            v16 = (int)*(this + 5);
            do
            {
              v17 = *(_DWORD **)v16;
              if ( v15 == *(_DWORD *)(*(_DWORD *)v16 + 4)
                && *((_DWORD *)a2 + 2) == v17[2]
                && *((_DWORD *)a2 + 3) == v17[3] )
              {
                v31[v17[4]] = (unsigned int)pMem;
              }
              pMem = (char *)pMem + 1;
              v16 += 4;
            }
            while ( pMem < *(this + 2) );
          }
          v18 = v27;
          for ( i = 0; i < 4; ++i )
          {
            v20 = v31[i];
            if ( v20 != -1 )
              v31[v18++] = v20;
          }
          result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, unsigned int *, int, int *, int))*this
                    + 28))(
                     a1: this,
                     a2: v31,
                     a3: v18,
                     a4: &v27,
                     a5: 1);
          if ( result < 0 )
            return result;
        }
        result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, struct D3DXShader::CArgument *, int *, int *))*this
                  + 34))(
                   a1: this,
                   a2,
                   a3: &v25,
                   a4: &v24);
        if ( result < 0 )
          return result;
        result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, unsigned int, int, _DWORD))*this + 25))(
                   a1: this,
                   a2: v25 & 0x7FF | ((v24 & 0x18 | ((v24 | 0xFFFFFFF8) << 20)) << 8),
                   a3: 983040,
                   a4: 0);
        if ( result < 0 )
          return result;
        result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **))*this + 24))(a1: this);
        if ( result < 0 )
          return result;
        result = D3DXShader::CShaderProgram::ValidateInst((D3DXShader::CShaderProgram *)this);
        if ( result < 0 )
          return result;
        v12 = v26;
        if ( v26 == nullptr )
          return 0;
        v13 = v29;
        break;
      default:
        return -2147467259;
    }
    goto LABEL_40;
  }
  if ( *((_DWORD *)a2 + 27) == -1 )
    return 0;
  if ( pMem == (void *)0xFFFF )
  {
LABEL_14:
    v12 = v26;
    if ( v26 != nullptr )
    {
      v13 = *((_DWORD *)a2 + 27);
LABEL_40:
      *v12 = v13;
      return 0;
    }
    return 0;
  }
  Semantic = D3DXShader::CShaderProgram::FindSemantic(this, a2: (struct D3DXShader::D3DX_SEMANTIC *)pMem);
  _snprintf(string, count: 0x20u, format: "v_%s%d", *(const char **)Semantic, v5);
  v21 = *((_DWORD *)a2 + 3);
  HIBYTE(v31[3]) = 0;
  result = D3DXShader::CFragmentRegisterAllocator::AddElement(
             this: this + 117,
             a2: (D3DXShader *)string,
             a3: v21,
             a4: 1u);
  if ( result >= 0 )
  {
    *(this + 124) = (struct D3DXShader::CRegisterEntryNode *)((char *)*(this + 124) + 1);
    if ( (*(_BYTE *)(this + 51) & 1) != 0 )
    {
      v8 = *((_DWORD *)a2 + 24);
      if ( v8 != 0 && *(_DWORD *)(v8 + 4) == 6 )
      {
        v9 = *(_DWORD *)(v8 + 20);
        if ( *(_DWORD *)(v9 + 4) == 3 )
        {
          v10 = MemAlloc_Alloc(nSize: strlen(*(const char **)(v9 + 24)) + 3);
          pMem = v10;
          if ( v10 == nullptr )
            return -2147024882;
          sprintf(string: (char *)v10, format: "n_%s", *(const char **)(v9 + 24));
          v11 = D3DXShader::CFragmentRegisterAllocator::AddElement(
                  this: this + 117,
                  a2: (D3DXShader *)pMem,
                  a3: *((_DWORD *)a2 + 3),
                  a4: 1u);
          free(pMem);
          if ( v11 < 0 )
            return v11;
          *(this + 124) = (struct D3DXShader::CRegisterEntryNode *)((char *)*(this + 124) + 1);
        }
      }
    }
    goto LABEL_14;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10211777
// Name: protected: long D3DXShader::CVSProgram::VSEmitFRC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::VSEmitFRC(D3DXShader::CVSProgram *this)
{
  bool v2; // cc
  int result; // eax
  int v4; // eax
  unsigned int i; // ecx
  int v6; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  _DWORD *v9; // eax
  unsigned int v10; // [esp+Ch] [ebp-2Ch] BYREF
  unsigned int v11[3]; // [esp+10h] [ebp-28h] BYREF
  int v12; // [esp+1Ch] [ebp-1Ch]
  unsigned int v13; // [esp+20h] [ebp-18h]
  int v14; // [esp+24h] [ebp-14h]
  int v15; // [esp+28h] [ebp-10h]
  unsigned int v16; // [esp+2Ch] [ebp-Ch]
  unsigned int v17; // [esp+30h] [ebp-8h]
  unsigned int v18; // [esp+34h] [ebp-4h]

  v2 = *(_DWORD *)(*((_DWORD *)this + 64) + 12) <= *(_DWORD *)(*((_DWORD *)this + 64) + 4);
  v14 = 0;
  if ( v2 )
  {
    v15 = 0;
    while ( 1 )
    {
      v6 = *((_DWORD *)this + 64);
      v7 = *(_DWORD *)(v6 + 12);
      v18 = 0;
      v13 = v7;
      if ( v7 != 0 )
        break;
LABEL_37:
      if ( (unsigned int)++v15 >= 2 )
        return 0;
    }
    v16 = 1;
    v17 = 2;
    while ( 1 )
    {
      v8 = 4 * v18;
      v9 = (_DWORD *)(4 * v18 + *(_DWORD *)(v6 + 16));
      v12 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v9) + 16);
      if ( v12 == 1 && v17 < v13 )
      {
        if ( v15 == 1 )
        {
          result = D3DXShader::CShaderProgram::EmitInstComplex(
                     this,
                     a2: 0x4Eu,
                     a3: (unsigned int *)(v8 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)),
                     a4: 1u,
                     a5: (unsigned int *)(v8 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)),
                     a6: nullptr,
                     a7: nullptr,
                     a8: 1u,
                     a9: 0,
                     a10: 0,
                     a11: 0,
                     a12: 0);
LABEL_22:
          if ( result < 0 )
            return result;
        }
      }
      else
      {
        if ( v16 < v13 )
        {
          if ( v12 != 0 || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v9[1]) + 16) != 1 )
          {
            if ( v15 == 0 )
            {
              if ( v14 == 0 )
              {
                result = (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD, unsigned int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
                           a1: this,
                           a2: *((_DWORD *)this + 63),
                           a3: &v10,
                           a4: 4,
                           a5: 0,
                           a6: 0);
                if ( result < 0 )
                  return result;
                v14 = 1;
              }
              result = D3DXShader::CShaderProgram::EmitInstComplex(
                         this,
                         a2: 0x13u,
                         a3: &v10,
                         a4: 2u,
                         a5: (unsigned int *)(v8 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)),
                         a6: nullptr,
                         a7: nullptr,
                         a8: 2u,
                         a9: 0,
                         a10: 0,
                         a11: 0,
                         a12: 0);
              if ( result < 0 )
                return result;
              result = D3DXShader::CShaderProgram::EmitInstComplex(
                         this,
                         a2: 1u,
                         a3: (unsigned int *)(v8 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)),
                         a4: 2u,
                         a5: &v10,
                         a6: nullptr,
                         a7: nullptr,
                         a8: 2u,
                         a9: 0,
                         a10: 0,
                         a11: 0,
                         a12: 0);
LABEL_34:
              if ( result < 0 )
                return result;
            }
          }
          else if ( v15 == 1 )
          {
            result = D3DXShader::CShaderProgram::EmitInstComplex(
                       this,
                       a2: 0x13u,
                       a3: (unsigned int *)(v8 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)),
                       a4: 2u,
                       a5: (unsigned int *)(v8 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)),
                       a6: nullptr,
                       a7: nullptr,
                       a8: 2u,
                       a9: 0,
                       a10: 0,
                       a11: 0,
                       a12: 0);
            goto LABEL_34;
          }
          v17 += 2;
          v18 += 2;
          v16 += 2;
          goto LABEL_36;
        }
        if ( v15 == 0 )
        {
          if ( v14 == 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD, unsigned int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
                       a1: this,
                       a2: *((_DWORD *)this + 63),
                       a3: &v10,
                       a4: 4,
                       a5: 0,
                       a6: 0);
            if ( result < 0 )
              return result;
            v14 = 1;
          }
          result = D3DXShader::CShaderProgram::EmitInstComplex(
                     this,
                     a2: 0x4Eu,
                     a3: v11,
                     a4: 1u,
                     a5: (unsigned int *)(v8 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)),
                     a6: nullptr,
                     a7: nullptr,
                     a8: 1u,
                     a9: 0,
                     a10: 0,
                     a11: 0,
                     a12: 0);
          if ( result < 0 )
            return result;
          result = D3DXShader::CShaderProgram::EmitInstComplex(
                     this,
                     a2: 1u,
                     a3: (unsigned int *)(v8 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)),
                     a4: 1u,
                     a5: v11,
                     a6: nullptr,
                     a7: nullptr,
                     a8: 1u,
                     a9: 0,
                     a10: 0,
                     a11: 0,
                     a12: 0);
          goto LABEL_22;
        }
      }
      ++v18;
      ++v17;
      ++v16;
LABEL_36:
      v6 = *((_DWORD *)this + 64);
      v13 = *(_DWORD *)(v6 + 12);
      if ( v18 >= v13 )
        goto LABEL_37;
    }
  }
  result = (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD, unsigned int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             a1: this,
             a2: *((_DWORD *)this + 63),
             a3: &v10,
             a4: 4,
             a5: 0,
             a6: 0);
  if ( result >= 0 )
  {
    result = D3DXShader::CShaderProgram::EmitInstComplex(
               this,
               a2: 0x4Eu,
               a3: v11,
               a4: 1u,
               a5: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
               a6: nullptr,
               a7: nullptr,
               a8: 1u,
               a9: 0,
               a10: 0,
               a11: 0,
               a12: 0);
    if ( result >= 0 )
    {
      v4 = *((_DWORD *)this + 64);
      for ( i = 0; i < *(_DWORD *)(v4 + 12); ++i )
        v11[i - 1] = v11[0];
      result = D3DXShader::CShaderProgram::EmitInstComplex(
                 this,
                 a2: 1u,
                 a3: *(unsigned int **)(*((_DWORD *)this + 64) + 16),
                 a4: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                 a5: &v10,
                 a6: nullptr,
                 a7: nullptr,
                 a8: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                 a9: 0,
                 a10: 0,
                 a11: 0,
                 a12: 0);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10211A3D
// Name: protected: long D3DXShader::CVSProgram::VSEmitEXP(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::VSEmitEXP(D3DXShader::CVSProgram *this)
{
  int v2; // eax
  unsigned int v3; // ecx
  int v4; // edx
  _DWORD *v5; // eax
  int result; // eax
  int v7; // eax
  bool v8; // cc
  int v9; // eax
  unsigned int i; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // ebx
  int v14; // edx
  _BYTE *v15; // ecx
  int v16; // ecx
  unsigned int v17[2]; // [esp+Ch] [ebp-18h] BYREF
  unsigned int v18[2]; // [esp+14h] [ebp-10h] BYREF
  int v19; // [esp+1Ch] [ebp-8h]
  unsigned int v20; // [esp+20h] [ebp-4h]

  v2 = *((_DWORD *)this + 64);
  v3 = *(_DWORD *)(v2 + 12);
  v20 = 0;
  if ( v3 != 0 )
  {
    v4 = *((_DWORD *)this + 5);
    v5 = *(_DWORD **)(v2 + 16);
    do
    {
      if ( (*(_BYTE *)(*(_DWORD *)(v4 + 4 * *v5) + 3) & 2) == 0 )
        break;
      ++v20;
      ++v5;
    }
    while ( v20 < v3 );
  }
  if ( v20 < v3 )
    return D3DXShader::CShaderProgram::EmitInstScalar(
             this,
             a2: 0xEu,
             a3: *(unsigned int **)(*((_DWORD *)this + 64) + 16),
             a4: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
             a5: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
             a6: *(_DWORD *)(*((_DWORD *)this + 64) + 4),
             a7: 0,
             a8: 0);
  v7 = *((_DWORD *)this + 64);
  if ( (unsigned __int16)*((_DWORD *)this + 50) >= 0x200u )
    return D3DXShader::CShaderProgram::EmitInstScalar(
             this,
             a2: 0x4Eu,
             a3: *(unsigned int **)(v7 + 16),
             a4: *(unsigned int **)(v7 + 8),
             a5: *(_DWORD *)(v7 + 12),
             a6: *(_DWORD *)(v7 + 4),
             a7: 0,
             a8: 0);
  v8 = *(_DWORD *)(v7 + 12) <= *(_DWORD *)(v7 + 4);
  v19 = 0;
  if ( v8 )
  {
    v20 = 0;
    if ( v3 != 0 )
    {
      do
      {
        v11 = *((_DWORD *)this + 64);
        v12 = *((_DWORD *)this + 5);
        v13 = 4 * v20;
        v14 = *(_DWORD *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(4 * v20 + *(_DWORD *)(v11 + 16))) + 16);
        v15 = *(_BYTE **)(v12 + 4 * *(_DWORD *)(4 * v20 + *(_DWORD *)(v11 + 8)));
        if ( v14 == 0 && (*v15 & 2) != 0 || v14 == 2 || v14 == 3 && ((v16 = *(_DWORD *)v15) & 4) != 0 && (v16 & 8) != 0 )
        {
          result = D3DXShader::CShaderProgram::EmitInstComplex(
                     this,
                     a2: 0x4Eu,
                     a3: (unsigned int *)(v13 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)),
                     a4: 1u,
                     a5: (unsigned int *)(v13 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)),
                     a6: nullptr,
                     a7: nullptr,
                     a8: 1u,
                     a9: 0,
                     a10: 0,
                     a11: 0,
                     a12: 0);
        }
        else
        {
          if ( v19 == 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD, unsigned int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
                       a1: this,
                       a2: *((_DWORD *)this + 63),
                       a3: v17,
                       a4: 4,
                       a5: 0,
                       a6: 0);
            if ( result < 0 )
              return result;
            v19 = 1;
          }
          result = D3DXShader::CShaderProgram::EmitInstComplex(
                     this,
                     a2: 0x4Eu,
                     a3: v18,
                     a4: 1u,
                     a5: (unsigned int *)(v13 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)),
                     a6: nullptr,
                     a7: nullptr,
                     a8: 1u,
                     a9: 0,
                     a10: 0,
                     a11: 0,
                     a12: 0);
          if ( result < 0 )
            return result;
          result = D3DXShader::CShaderProgram::EmitInstComplex(
                     this,
                     a2: 1u,
                     a3: (unsigned int *)(v13 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)),
                     a4: 1u,
                     a5: v18,
                     a6: nullptr,
                     a7: nullptr,
                     a8: 1u,
                     a9: 0,
                     a10: 0,
                     a11: 0,
                     a12: 0);
        }
        if ( result < 0 )
          return result;
        ++v20;
      }
      while ( v20 < *(_DWORD *)(*((_DWORD *)this + 64) + 12) );
    }
    return 0;
  }
  result = (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD, unsigned int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             a1: this,
             a2: *((_DWORD *)this + 63),
             a3: v17,
             a4: 4,
             a5: 0,
             a6: 0);
  if ( result >= 0 )
  {
    result = D3DXShader::CShaderProgram::EmitInstComplex(
               this,
               a2: 0x4Eu,
               a3: v18,
               a4: 1u,
               a5: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
               a6: nullptr,
               a7: nullptr,
               a8: 1u,
               a9: 0,
               a10: 0,
               a11: 0,
               a12: 0);
    if ( result >= 0 )
    {
      v9 = *((_DWORD *)this + 64);
      for ( i = 0; i < *(_DWORD *)(v9 + 12); ++i )
        v17[i] = v18[0];
      result = D3DXShader::CShaderProgram::EmitInstComplex(
                 this,
                 a2: 1u,
                 a3: *(unsigned int **)(*((_DWORD *)this + 64) + 16),
                 a4: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                 a5: v17,
                 a6: nullptr,
                 a7: nullptr,
                 a8: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                 a9: 0,
                 a10: 0,
                 a11: 0,
                 a12: 0);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10211C74
// Name: protected: long D3DXShader::CVSProgram::VSEmitLOG(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::VSEmitLOG(D3DXShader::CVSProgram *this)
{
  int v2; // eax
  unsigned int v3; // ecx
  int v4; // edx
  _DWORD *v5; // eax
  int result; // eax
  int v7; // eax
  bool v8; // cc
  int v9; // eax
  unsigned int i; // ecx
  unsigned int v11[2]; // [esp+Ch] [ebp-18h] BYREF
  unsigned int v12[2]; // [esp+14h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-8h]
  unsigned int v14; // [esp+20h] [ebp-4h]

  v2 = *((_DWORD *)this + 64);
  v3 = *(_DWORD *)(v2 + 12);
  v14 = 0;
  if ( v3 != 0 )
  {
    v4 = *((_DWORD *)this + 5);
    v5 = *(_DWORD **)(v2 + 16);
    do
    {
      if ( (*(_BYTE *)(*(_DWORD *)(v4 + 4 * *v5) + 3) & 2) == 0 )
        break;
      ++v14;
      ++v5;
    }
    while ( v14 < v3 );
  }
  if ( v14 < v3 )
    return D3DXShader::CShaderProgram::EmitInstScalar(
             this,
             a2: 0xFu,
             a3: *(unsigned int **)(*((_DWORD *)this + 64) + 16),
             a4: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
             a5: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
             a6: *(_DWORD *)(*((_DWORD *)this + 64) + 4),
             a7: 0,
             a8: 0);
  v7 = *((_DWORD *)this + 64);
  if ( (unsigned __int16)*((_DWORD *)this + 50) >= 0x200u )
    return D3DXShader::CShaderProgram::EmitInstScalar(
             this,
             a2: 0x4Fu,
             a3: *(unsigned int **)(v7 + 16),
             a4: *(unsigned int **)(v7 + 8),
             a5: *(_DWORD *)(v7 + 12),
             a6: *(_DWORD *)(v7 + 4),
             a7: 0,
             a8: 0);
  v8 = *(_DWORD *)(v7 + 12) <= *(_DWORD *)(v7 + 4);
  v13 = 0;
  if ( v8 )
  {
    v14 = 0;
    if ( v3 != 0 )
    {
      do
      {
        if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                   + 4 * *(_DWORD *)(4 * v14 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)))
                       + 16) == 2 )
        {
          result = D3DXShader::CShaderProgram::EmitInstComplex(
                     this,
                     a2: 0x4Fu,
                     a3: (unsigned int *)(4 * v14 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)),
                     a4: 1u,
                     a5: (unsigned int *)(4 * v14 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)),
                     a6: nullptr,
                     a7: nullptr,
                     a8: 1u,
                     a9: 0,
                     a10: 0,
                     a11: 0,
                     a12: 0);
        }
        else
        {
          if ( v13 == 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD, unsigned int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
                       a1: this,
                       a2: *((_DWORD *)this + 63),
                       a3: v11,
                       a4: 4,
                       a5: 0,
                       a6: 0);
            if ( result < 0 )
              return result;
            v13 = 1;
          }
          result = D3DXShader::CShaderProgram::EmitInstComplex(
                     this,
                     a2: 0x4Fu,
                     a3: v12,
                     a4: 1u,
                     a5: (unsigned int *)(4 * v14 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)),
                     a6: nullptr,
                     a7: nullptr,
                     a8: 1u,
                     a9: 0,
                     a10: 0,
                     a11: 0,
                     a12: 0);
          if ( result < 0 )
            return result;
          result = D3DXShader::CShaderProgram::EmitInstComplex(
                     this,
                     a2: 1u,
                     a3: (unsigned int *)(4 * v14 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)),
                     a4: 1u,
                     a5: v12,
                     a6: nullptr,
                     a7: nullptr,
                     a8: 1u,
                     a9: 0,
                     a10: 0,
                     a11: 0,
                     a12: 0);
        }
        if ( result < 0 )
          return result;
        ++v14;
      }
      while ( v14 < *(_DWORD *)(*((_DWORD *)this + 64) + 12) );
    }
    return 0;
  }
  result = (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD, unsigned int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             a1: this,
             a2: *((_DWORD *)this + 63),
             a3: v11,
             a4: 4,
             a5: 0,
             a6: 0);
  if ( result >= 0 )
  {
    result = D3DXShader::CShaderProgram::EmitInstComplex(
               this,
               a2: 0x4Fu,
               a3: v12,
               a4: 1u,
               a5: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
               a6: nullptr,
               a7: nullptr,
               a8: 1u,
               a9: 0,
               a10: 0,
               a11: 0,
               a12: 0);
    if ( result >= 0 )
    {
      v9 = *((_DWORD *)this + 64);
      for ( i = 0; i < *(_DWORD *)(v9 + 12); ++i )
        v11[i] = v12[0];
      result = D3DXShader::CShaderProgram::EmitInstComplex(
                 this,
                 a2: 1u,
                 a3: *(unsigned int **)(*((_DWORD *)this + 64) + 16),
                 a4: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                 a5: v11,
                 a6: nullptr,
                 a7: nullptr,
                 a8: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                 a9: 0,
                 a10: 0,
                 a11: 0,
                 a12: 0);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10211E7E
// Name: protected: long D3DXShader::C30Program::EmitAddress(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::EmitAddress(D3DXShader::C30Program *this, unsigned int a2)
{
  int v3; // ebx
  int result; // eax
  int v5; // [esp+8h] [ebp-Ch] BYREF
  int v6; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  v3 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * a2);
  if ( (unsigned __int16)*((_DWORD *)this + 50) > 0x100u )
  {
    if ( *(_DWORD *)(v3 + 8) == -1 || (result = D3DXShader::C30Program::EmitAddress(this, a2: *(_DWORD *)(v3 + 8))) >= 0 )
    {
      if ( *((_DWORD *)this + 78) == a2 )
      {
        return 0;
      }
      else
      {
        result = D3DXShader::CShaderProgram::EmitInst(this, a2: 1u);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(D3DXShader::C30Program *, int, int, _DWORD))(*(_DWORD *)this + 100))(
                     a1: this,
                     a2: -1342177280,
                     a3: 0x10000,
                     a4: 0);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::C30Program *, int, int *, int *))(*(_DWORD *)this + 116))(
                       a1: this,
                       a2: v3,
                       a3: &v5,
                       a4: &v7);
            if ( result >= 0 )
            {
              result = (*(int (__thiscall **)(D3DXShader::C30Program *, unsigned int *, int, int, int *))(*(_DWORD *)this + 120))(
                         a1: this,
                         &a2,
                         a3: 1,
                         a4: 0x10000,
                         a5: &v6);
              if ( result >= 0 )
              {
                result = (*(int (__thiscall **)(D3DXShader::C30Program *, int, int, int))(*(_DWORD *)this + 104))(
                           a1: this,
                           a2: v5,
                           a3: v6,
                           a4: v7);
                if ( result >= 0 )
                {
                  result = (*(int (__thiscall **)(D3DXShader::C30Program *))(*(_DWORD *)this + 96))(a1: this);
                  if ( result >= 0 )
                  {
                    result = D3DXShader::CShaderProgram::ValidateInst(this);
                    if ( result >= 0 )
                    {
                      *((_DWORD *)this + 78) = a2;
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    D3DXShader::CProgram::Error(
      this,
      a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
      a3: 0x119Fu,
      format: "relative addressing not supported in vs_1_0 instruction set");
    return -2147467263;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10211FA8
// Name: protected: long D3DXShader::CVSProgram::VSMatchDST(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::VSMatchDST(D3DXShader::CVSProgram *this)
{
  D3DXShader::CProgram *v1; // ebx
  _DWORD *v2; // eax
  unsigned int v3; // ecx
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  int v10; // edx
  int v11; // edx
  int v12; // eax
  unsigned int v13; // edx
  _DWORD *v14; // edi
  int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  _DWORD *v19; // edx
  int v20; // eax
  unsigned int v21; // edx
  _DWORD *v22; // edi
  int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // ecx
  unsigned int v26; // eax
  _DWORD *v27; // edx
  int v28; // eax
  unsigned int v29; // edx
  BOOL v30; // ecx
  _DWORD *v31; // eax
  _DWORD *v32; // eax
  int *v33; // eax
  int v34; // edx
  unsigned int v35; // edx
  int v36; // eax
  int v37; // edx
  unsigned int v38; // esi
  _DWORD *v39; // eax
  _DWORD *v40; // ecx
  int v41; // eax
  int v42; // eax
  int v43; // ecx
  int v44; // edx
  _DWORD *v45; // eax
  int j; // edi
  int v47; // ecx
  unsigned int v48; // esi
  unsigned int v49; // edi
  unsigned __int8 *v50; // eax
  D3DXShader::CInstruction *v51; // esi
  int v52; // eax
  int v53; // edi
  unsigned int v54; // ecx
  int v55; // eax
  int v56; // edx
  int v57; // edx
  unsigned int v58; // edi
  int v59; // eax
  int v60; // ecx
  unsigned int v61; // eax
  int v62; // eax
  int v63; // ecx
  int v64; // edi
  int v65; // ecx
  int v66; // eax
  unsigned int *v67; // edx
  unsigned int v68; // ebx
  unsigned int k; // ecx
  int v70; // eax
  _DWORD *v71; // ecx
  _DWORD *v72; // eax
  _DWORD *v73; // ecx
  _DWORD *v74; // eax
  int v75; // edx
  int v76; // edi
  D3DXShader::CInstruction *v77; // ecx
  _DWORD v78[4]; // [esp+4h] [ebp-60h]
  _DWORD v79[4]; // [esp+14h] [ebp-50h] BYREF
  unsigned int v80; // [esp+24h] [ebp-40h]
  unsigned int v81; // [esp+28h] [ebp-3Ch]
  unsigned int v82; // [esp+2Ch] [ebp-38h]
  unsigned int v83; // [esp+30h] [ebp-34h]
  unsigned int v84; // [esp+34h] [ebp-30h]
  unsigned int i; // [esp+38h] [ebp-2Ch]
  _DWORD *v86; // [esp+3Ch] [ebp-28h]
  _DWORD *v87; // [esp+40h] [ebp-24h]
  D3DXShader::CProgram *v88; // [esp+44h] [ebp-20h]
  unsigned int v89; // [esp+48h] [ebp-1Ch]
  _DWORD *v90; // [esp+4Ch] [ebp-18h]
  int v91; // [esp+50h] [ebp-14h]
  unsigned int v92; // [esp+54h] [ebp-10h]
  int v93; // [esp+58h] [ebp-Ch]
  int v94; // [esp+5Ch] [ebp-8h]
  unsigned int v95; // [esp+60h] [ebp-4h]

  v1 = this;
  v2 = *((_DWORD **)this + 64);
  v3 = *v2 & 0xFFFFF;
  v88 = v1;
  v92 = v3;
  if ( v3 == 0 )
    return 1;
  v5 = v2[1] / v3;
  v81 = 0;
  v80 = v5;
  if ( v5 == 0 )
    return 1;
  v84 = 0;
  while ( 1 )
  {
    v6 = -1;
    memset(v79, 255, sizeof(v79));
    v95 = 0;
    v89 = 0;
    v90 = nullptr;
    v87 = nullptr;
    v86 = nullptr;
    v93 = -1;
    v94 = -1;
    if ( v92 != 0 )
    {
      i = v84 + *(_DWORD *)(*((_DWORD *)v1 + 64) + 8);
      v82 = v92;
      while ( 1 )
      {
        v7 = *(_DWORD *)i;
        v8 = *(_DWORD *)(*((_DWORD *)v1 + 5) + 4 * *(_DWORD *)i);
        v9 = *(_DWORD *)(v8 + 16);
        if ( v9 == 0 )
          break;
        v10 = v9 - 1;
        if ( v10 == 0 )
        {
          if ( *(_DWORD *)(v8 + 72) == -1 || v90 != nullptr )
            goto LABEL_39;
          v28 = *(_DWORD *)(v8 + 72);
          v90 = *(_DWORD **)(*((_DWORD *)v1 + 6) + 4 * v28);
          goto LABEL_37;
        }
        v11 = v10 - 1;
        if ( v11 != 0 )
        {
          if ( v11 != 1 || v94 != -1 )
            goto LABEL_39;
          v12 = *(_DWORD *)(v8 + 72);
          v13 = v95;
          v79[v13] = -1;
          v94 = v7;
          v78[v13] = v7;
          if ( v12 != -1 )
          {
            v14 = *(_DWORD **)(*((_DWORD *)v1 + 6) + 4 * v12);
            v15 = *v14;
            v16 = *v14 & 0xFFF00000;
            v86 = v14;
            if ( v16 == 0x10000000 )
            {
              v17 = 0;
              v18 = v15 & 0xFFFFF;
              if ( v18 != 0 )
              {
                v19 = (_DWORD *)v14[4];
                while ( *v19 != v94 )
                {
                  ++v17;
                  ++v19;
                  if ( v17 >= v18 )
                    goto LABEL_18;
                }
                v94 = *(_DWORD *)(v14[2] + 4 * v17);
LABEL_18:
                v6 = v93;
              }
            }
            else
            {
              v86 = nullptr;
            }
          }
          goto LABEL_38;
        }
        if ( v6 == -1 )
        {
          v20 = *(_DWORD *)(v8 + 72);
          v21 = v95;
          v79[v21] = -1;
          v6 = v7;
          v93 = v7;
          v78[v21] = v7;
          if ( v20 != -1 )
          {
            v22 = *(_DWORD **)(*((_DWORD *)v1 + 6) + 4 * v20);
            v23 = *v22;
            v24 = *v22 & 0xFFF00000;
            v87 = v22;
            if ( v24 == 0x10000000 )
            {
              v25 = 0;
              v26 = v23 & 0xFFFFF;
              if ( v26 != 0 )
              {
                v27 = (_DWORD *)v22[4];
                while ( *v27 != v6 )
                {
                  ++v25;
                  ++v27;
                  if ( v25 >= v26 )
                    goto LABEL_38;
                }
                v6 = *(_DWORD *)(v22[2] + 4 * v25);
                v93 = v6;
              }
            }
            else
            {
              v87 = nullptr;
            }
          }
          goto LABEL_38;
        }
LABEL_39:
        i += 4;
        if ( --v82 == 0 )
          goto LABEL_40;
      }
      if ( *(_DWORD *)(v8 + 72) == -1 || v89 != 0 )
        goto LABEL_39;
      v28 = *(_DWORD *)(v8 + 72);
      v89 = *(_DWORD *)(*((_DWORD *)v1 + 6) + 4 * v28);
LABEL_37:
      v29 = v95;
      v79[v29] = v28;
      v78[v29] = v7;
LABEL_38:
      ++v95;
      goto LABEL_39;
    }
LABEL_40:
    if ( v95 != v92 || v95 <= 1 )
      goto LABEL_96;
    v30 = false;
    if ( v90 != nullptr )
    {
      if ( *v90 != 542113793 )
        goto LABEL_56;
      if ( v6 != -1 )
      {
        v31 = (_DWORD *)v90[2];
        if ( v6 != *v31 )
          v30 = v6 != v31[1];
      }
      if ( v94 != -1 )
      {
        v32 = (_DWORD *)v90[2];
        if ( v94 != *v32 && v94 != v32[1] )
          v30 = true;
        if ( v6 != -1 )
        {
          v33 = (int *)v90[2];
          v34 = *v33;
          if ( v94 == v6 )
          {
            if ( v34 == v33[1] )
              goto LABEL_57;
          }
          else if ( v34 != v33[1] )
          {
            goto LABEL_57;
          }
LABEL_56:
          v30 = true;
        }
      }
    }
LABEL_57:
    v35 = 0;
    if ( v89 == 0 )
      goto LABEL_62;
    if ( *(_DWORD *)v89 == 268435457 )
      break;
LABEL_96:
    ++v81;
    v84 += 4 * v92;
    if ( v81 >= v80 )
      return 1;
  }
  v36 = *(_DWORD *)(*((_DWORD *)v1 + 5) + 4 * **(_DWORD **)(v89 + 8));
  if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v1 + 4) + 4 * *(_DWORD *)(v36 + 4)) + 5) & 1) == 0
    || *(double *)(v36 + 32) != 1.0 )
  {
    v30 = true;
  }
LABEL_62:
  if ( v30 )
    goto LABEL_96;
  v82 = 0;
  while ( 1 )
  {
    v83 = v79[v35];
    if ( v83 != -1 )
    {
      v91 = 1;
      v89 = v92;
      if ( v92 != 0 )
      {
        v37 = *((_DWORD *)v1 + 5);
        v38 = *((_DWORD *)v1 + 63);
        v39 = (_DWORD *)(v84 + *(_DWORD *)(*((_DWORD *)v1 + 64) + 8));
        for ( i = v92; i != 0; --i )
        {
          v40 = *(_DWORD **)(v37 + 4 * *v39);
          if ( v40[20] < v38 )
            v91 = 0;
          if ( v40[19] > v83 )
            v91 = 0;
          if ( (v87 != nullptr || v40[4] != 2) && (v86 != nullptr || v40[4] != 3) )
          {
            if ( v40[21] < v83 )
              v91 = 0;
          }
          else
          {
            --v89;
          }
          ++v39;
        }
        v35 = v82;
      }
      for ( i = 0; i < v95; ++i )
      {
        v41 = v79[i];
        if ( v41 != -1 )
        {
          v42 = *(_DWORD *)(*((_DWORD *)v1 + 6) + 4 * v41);
          v43 = *(_DWORD *)(v42 + 4);
          if ( v43 != 0 )
          {
            v44 = *((_DWORD *)v1 + 5);
            v45 = *(_DWORD **)(v42 + 8);
            for ( j = v43; j != 0; --j )
            {
              v47 = *(_DWORD *)(v44 + 4 * *v45);
              v48 = *(_DWORD *)(v47 + 72);
              if ( v48 > v83 && v48 != -1 || *(_DWORD *)(v47 + 80) < v83 )
                v91 = 0;
              ++v45;
            }
            v35 = v82;
            v1 = v88;
          }
        }
      }
      if ( v91 != 0 )
        break;
    }
    v82 = ++v35;
    if ( v35 >= v95 )
      goto LABEL_96;
  }
  v82 = v79[v35];
  if ( v82 == -1 )
    goto LABEL_96;
  v49 = v89;
  if ( v89 < 2 )
    goto LABEL_96;
  v50 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v50 != nullptr )
    v51 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v50);
  else
    v51 = nullptr;
  if ( v51 == nullptr )
    return -2147024882;
  v52 = D3DXShader::CInstruction::Initialize(this: v51, a2: v49 & 0xFFFFF | 0x70900000, a3: 2 * v49, a4: v49, a5: 0);
  if ( v52 < 0
    || (v52 = D3DXShader::CInstruction::Instance(this: v51, a2: *((struct D3DXShader::CInstruction **)v1 + 64))) < 0 )
  {
    v53 = v52;
    goto LABEL_142;
  }
  v54 = 0;
  if ( v49 != 0 )
  {
    v55 = 4 * v49;
    do
    {
      if ( v90 != nullptr )
      {
        *(_DWORD *)(*((_DWORD *)v51 + 2) + 4 * v54) = *(_DWORD *)v90[2];
        v56 = *(_DWORD *)(v90[2] + 4);
      }
      else
      {
        v56 = v94;
        if ( v94 == -1 )
        {
          v56 = v93;
          if ( v93 == -1 )
            goto LABEL_112;
        }
        else if ( v93 != -1 )
        {
LABEL_112:
          D3DXShader::CProgram::Error(
            this: v1,
            a2: *(struct D3DXShader::CNode **)(*((_DWORD *)v1 + 64) + 60),
            a3: 0x12D9u,
            format: "internal error: DST test failure");
          goto LABEL_113;
        }
        *(_DWORD *)(*((_DWORD *)v51 + 2) + 4 * v54) = v56;
      }
      *(_DWORD *)(v55 + *((_DWORD *)v51 + 2)) = v56;
      ++v54;
      v55 += 4;
    }
    while ( v54 < v89 );
  }
  v57 = 0;
  v58 = 0;
  if ( v95 != 0 )
  {
    while ( 1 )
    {
      v59 = v78[v57];
      v60 = *(_DWORD *)(*((_DWORD *)v1 + 5) + 4 * v59);
      if ( (v87 != nullptr || *(_DWORD *)(v60 + 16) != 2) && (v86 != nullptr || *(_DWORD *)(v60 + 16) != 3) )
        *(_DWORD *)(*((_DWORD *)v51 + 4) + 4 * v58++) = v59;
      if ( v58 > v89 )
        break;
      v1 = v88;
      if ( ++v57 >= v95 )
        goto LABEL_125;
    }
    D3DXShader::CProgram::Error(
      this: v88,
      a2: *(struct D3DXShader::CNode **)(*((_DWORD *)v88 + 64) + 60),
      a3: 0x12DAu,
      format: "internal error: DST test failure");
LABEL_113:
    v53 = 1;
LABEL_142:
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v51, a2: 1);
    return v53;
  }
  else
  {
LABEL_125:
    v61 = *((_DWORD *)v51 + 3);
    v92 = 0;
    if ( v61 != 0 )
    {
      v81 = 1;
      while ( 1 )
      {
        v84 = v81;
        if ( v81 < v61 )
          break;
LABEL_132:
        ++v92;
        v61 = *((_DWORD *)v51 + 3);
        ++v81;
        if ( v92 >= v61 )
          goto LABEL_133;
      }
      while ( 1 )
      {
        v62 = *((_DWORD *)v51 + 4);
        v63 = *((_DWORD *)v1 + 5);
        v64 = *(_DWORD *)(v63 + 4 * *(_DWORD *)(v62 + 4 * v92));
        v65 = *(_DWORD *)(v63 + 4 * *(_DWORD *)(4 * v84 + v62));
        if ( *(_DWORD *)(v64 + 16) > *(_DWORD *)(v65 + 16) )
        {
          v66 = *((_DWORD *)v51 + 4);
          v67 = (unsigned int *)(v66 + 4 * v84);
          v80 = *v67;
          v68 = v92;
          *v67 = *(_DWORD *)(v66 + 4 * v92);
          *(_DWORD *)(*((_DWORD *)v51 + 4) + 4 * v68) = v80;
          v1 = v88;
        }
        if ( *(_DWORD *)(v64 + 16) == *(_DWORD *)(v65 + 16) )
          break;
        if ( ++v84 >= *((_DWORD *)v51 + 3) )
          goto LABEL_132;
      }
      D3DXShader::CProgram::Error(
        this: v1,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)v1 + 64) + 60),
        a3: 0x12DBu,
        format: "internal error: multiple write to same output");
      v53 = -2147467259;
      goto LABEL_142;
    }
LABEL_133:
    for ( k = 0; k < v95; ++k )
    {
      v70 = v79[k];
      if ( v70 != -1 )
        **(_DWORD **)(*((_DWORD *)v1 + 6) + 4 * v70) = 0;
    }
    v71 = v87;
    if ( v87 != nullptr )
    {
      if ( *v87 == 268435457 )
      {
        *v87 = 0;
      }
      else if ( *v87 == 268435458 )
      {
        v72 = (_DWORD *)v87[2];
        if ( *v72 == v93 && v72[1] == v94 )
          *v87 = 0;
        if ( v72[1] == v93 && *v72 == v94 )
          *v71 = 0;
      }
    }
    v73 = v86;
    if ( v86 != nullptr )
    {
      if ( *v86 == 268435457 )
        goto LABEL_158;
      if ( *v86 == 268435458 )
      {
        v74 = (_DWORD *)v86[2];
        v75 = v93;
        if ( *v74 == v93 && v74[1] == v94 )
          *v86 = 0;
        if ( v74[1] == v75 && *v74 == v94 )
LABEL_158:
          *v73 = 0;
      }
    }
    v76 = 4 * v82;
    v77 = *(D3DXShader::CInstruction **)(4 * v82 + *((_DWORD *)v1 + 6));
    if ( v77 != nullptr )
      D3DXShader::CInstruction::`scalar deleting destructor'(this: v77, a2: 1);
    *(_DWORD *)(v76 + *((_DWORD *)v1 + 6)) = v51;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021262A
// Name: protected: virtual long D3DXShader::CVSProgram::PatternMatch(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::PatternMatch(D3DXShader::CVSProgram *this)
{
  int v2; // edi
  bool v3; // zf
  _DWORD *v4; // eax
  int result; // eax
  unsigned int i; // edi
  int v7; // eax
  int v8; // edi
  int v9; // eax
  _DWORD *v10; // eax
  int v11; // edi
  int v12; // eax
  _DWORD *v13; // eax
  void *v14; // eax
  unsigned int v15; // ebx
  int v16; // edi
  unsigned int v17; // ebx
  int v18; // edi
  unsigned int v19; // [esp+Ch] [ebp-8h]
  int v20; // [esp+10h] [ebp-4h]
  int v21; // [esp+10h] [ebp-4h]

  v2 = 0;
  if ( *((_DWORD *)this + 23) != 0 )
  {
    v3 = *((_DWORD *)this + 3) == 0;
    *((_DWORD *)this + 63) = 0;
    if ( !v3 )
    {
      do
      {
        v4 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)this + 63));
        *((_DWORD *)this + 64) = v4;
        if ( (*v4 & 0xFFF00000) == 0x20800000 )
        {
          result = D3DXShader::CShaderProgram::MatchENDWHILE(this);
          if ( result < 0 )
            return result;
          v2 |= result == 0;
        }
        ++*((_DWORD *)this + 63);
      }
      while ( *((_DWORD *)this + 63) < *((_DWORD *)this + 3) );
      if ( v2 != 0 )
        D3DXShader::CShaderProgram::Reset(this);
    }
  }
  if ( (*((_BYTE *)this + 204) & 4) != 0 )
    goto LABEL_26;
  for ( i = 0; i < *((_DWORD *)this + 3); ++i )
  {
    v7 = *((_DWORD *)this + 6);
    *((_DWORD *)this + 63) = i;
    *((_DWORD *)this + 64) = *(_DWORD *)(v7 + 4 * i);
    if ( D3DXShader::CVSProgram::VSMatchDST(this) == 0 )
      D3DXShader::CShaderProgram::Reset(this);
  }
  v8 = 0;
  if ( *((_DWORD *)this + 3) == 0 )
  {
LABEL_18:
    D3DXShader::CShaderProgram::Reset(this);
    v11 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      do
      {
        v12 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v11;
        v13 = *(_DWORD **)(v12 + 4 * v11);
        *((_DWORD *)this + 64) = v13;
        v14 = (void *)(*v13 & 0xFFF00000);
        if ( v14 == &unk_10300000
          || v14 == (void *)273678336
          || v14 == (void *)274726912
          || v14 == (void *)275775488
          || v14 == (void *)1342177280 )
        {
          result = D3DXShader::CShaderProgram::MatchRepMov(this);
          if ( result < 0 )
            return result;
        }
      }
      while ( (unsigned int)++v11 < *((_DWORD *)this + 3) );
    }
LABEL_26:
    if ( *((_DWORD *)this + 12) != 0 )
    {
      v19 = 0;
      while ( v19 < 0x10 )
      {
        v15 = *((_DWORD *)this + 3);
        v16 = 0;
        v20 = 1;
        if ( v15 != 0 )
        {
          do
          {
            *((_DWORD *)this + 64) = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v16);
            result = D3DXShader::CShaderProgram::ResolveAddress(this);
            if ( result < 0 )
              return result;
            if ( result == 0 )
              v20 = 0;
            result = D3DXShader::CBaseProgram::CopyInstruction(
                       this,
                       a2: *((struct D3DXShader::CInstruction **)this + 64));
            if ( result < 0 )
              return result;
            **((_DWORD **)this + 64) = 0;
          }
          while ( ++v16 < v15 );
        }
        result = D3DXShader::CProgram::CompactInstructions(this);
        if ( result < 0 )
          return result;
        ++v19;
        if ( v20 != 0 )
        {
          if ( v19 < 0x10 )
            goto LABEL_47;
          break;
        }
      }
      v17 = *((_DWORD *)this + 3);
      v18 = 0;
      v21 = 1;
      if ( v17 != 0 )
      {
        do
        {
          *((_DWORD *)this + 64) = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v18);
          result = D3DXShader::CShaderProgram::ResolveAddress(this);
          if ( result < 0 )
            return result;
          if ( result == 0 )
          {
            D3DXShader::CProgram::Error(
              this,
              a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
              a3: 0x11C9u,
              format: "relative address refrences too deep");
            v21 = 0;
          }
          result = D3DXShader::CBaseProgram::CopyInstruction(this, a2: *((struct D3DXShader::CInstruction **)this + 64));
          if ( result < 0 )
            return result;
          **((_DWORD **)this + 64) = 0;
        }
        while ( ++v18 < v17 );
      }
      result = D3DXShader::CProgram::CompactInstructions(this);
      if ( result < 0 )
        return result;
      if ( v21 == 0 )
        return -2147467259;
    }
LABEL_47:
    if ( *((_DWORD *)this + 24) == 0 )
      return 0;
    result = D3DXShader::CShaderProgram::ResolveFlowControl(this);
    if ( result >= 0 )
    {
      D3DXShader::CShaderProgram::Reset(this);
      result = D3DXShader::CProgram::CompactArguments(this);
      if ( result >= 0 )
        return 0;
    }
    return result;
  }
  while ( 1 )
  {
    v9 = *((_DWORD *)this + 6);
    *((_DWORD *)this + 63) = v8;
    v10 = *(_DWORD **)(v9 + 4 * v8);
    *((_DWORD *)this + 64) = v10;
    if ( (*v10 & 0xFFF00000) == 0x50000000 )
    {
      result = D3DXShader::CVSProgram::VSMatchDOT(this);
      if ( result < 0 )
        return result;
    }
    if ( (unsigned int)++v8 >= *((_DWORD *)this + 3) )
      goto LABEL_18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102128A5
// Name: protected: virtual int D3DXShader::CVSProgram::ViolatesPortConstraints(class D3DXShader::CInstruction __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::ViolatesPortConstraints(
        D3DXShader::CVSProgram *this,
        struct D3DXShader::CInstruction *a2,
        unsigned int *a3)
{
  struct D3DXShader::CInstruction *v3; // ebx
  int v6; // eax
  unsigned int v7; // ecx
  int v8; // edi
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // eax
  bool v13; // zf
  _DWORD *v14; // edi
  int v15; // eax
  int v16; // eax
  int v17; // edx
  _DWORD *v18; // ecx
  _DWORD *v19; // eax
  unsigned int v20; // ecx
  int v21; // edx
  _DWORD *v22; // eax
  _DWORD v23[36]; // [esp+8h] [ebp-ACh] BYREF
  int v24; // [esp+98h] [ebp-1Ch]
  int v25; // [esp+9Ch] [ebp-18h]
  int v26; // [esp+A0h] [ebp-14h]
  unsigned int v27; // [esp+A4h] [ebp-10h]
  unsigned int v28; // [esp+A8h] [ebp-Ch]
  unsigned int v29; // [esp+ACh] [ebp-8h]
  int v30; // [esp+B0h] [ebp-4h]

  v3 = a2;
  if ( a2 == nullptr )
    return 1;
  v6 = *(_DWORD *)a2;
  v7 = *(_DWORD *)a2 & 0xFFF00000;
  if ( v7 == 0 || v7 == 544210944 )
    return 0;
  v8 = v6 & 0xFFFFF;
  v27 = *((_DWORD *)a2 + 1) / (v6 & 0xFFFFFu);
  if ( v7 == 1884291072 || v7 == 1885339648 || v7 == 1886388224 )
    v27 = 2;
  if ( v27 <= 1 )
    return 0;
  v9 = *((_DWORD *)this + 34);
  v10 = *((_DWORD *)this + 31);
  v11 = *((_DWORD *)this + 32);
  v23[v11 + 18] = 0;
  v9 *= 4;
  *(_DWORD *)((char *)&v23[18] + v9) = 0;
  v10 *= 4;
  *(_DWORD *)((char *)&v23[18] + v10) = 0;
  v23[v11] = 1;
  v12 = 0;
  v13 = v27 == 0;
  *(_DWORD *)((char *)v23 + v9) = 3;
  *(_DWORD *)((char *)v23 + v10) = 1;
  v26 = 0;
  v28 = 0;
  if ( v13 )
    return 0;
  v25 = 0;
  v24 = 4 * v8;
  while ( 1 )
  {
    v14 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v12 + *((_DWORD *)v3 + 2)));
    v15 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v14[1]) + 4);
    if ( (v15 & 0x200) != 0 )
    {
      if ( (v15 & 0x80u) == 0 )
      {
        v16 = *((_DWORD *)this + 31);
        goto LABEL_22;
      }
LABEL_17:
      v16 = *((_DWORD *)this + 37);
      goto LABEL_22;
    }
    if ( (v15 & 0x80u) != 0 )
      goto LABEL_17;
    v16 = (v15 & 0x10) == 0
       || (*(int (__thiscall **)(D3DXShader::CVSProgram *, _DWORD))(*(_DWORD *)this + 84))(a1: this, a2: v14[27]) == 0xFFFF
        ? *((_DWORD *)this + 34)
        : *((_DWORD *)this + 32);
LABEL_22:
    v29 = 0;
    v30 = v16;
    if ( v28 != 0 )
    {
      v17 = *((_DWORD *)this + 5);
      v18 = *((_DWORD **)v3 + 2);
      do
      {
        v19 = *(_DWORD **)(v17 + 4 * *v18);
        if ( v14[1] == v19[1] && v14[2] == v19[2] && v14[3] == v19[3] )
          break;
        ++v29;
        v18 = (_DWORD *)((char *)v18 + v24);
      }
      while ( v29 < v28 );
      v3 = a2;
    }
    v20 = v28;
    if ( v29 == v28 )
    {
      v21 = v30;
      v22 = &v23[v30 + 18];
      if ( ++*v22 > v23[v21] )
        break;
    }
    if ( (unsigned __int16)*((_DWORD *)this + 50) >= 0x200u && *((_DWORD *)this + 31) == v30 && (unsigned int)++v26 > 2 )
      break;
    v12 = v24 + v25;
    v28 = v20 + 1;
    v25 += v24;
    if ( v20 + 1 >= v27 )
      return 0;
  }
  if ( a3 != nullptr )
    *a3 = v20;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10212A8B
// Name: protected: virtual int D3DXShader::CPSProgram::ViolatesWriteLim(class D3DXShader::CInstruction __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::ViolatesWriteLim(
        D3DXShader::CPSProgram *this,
        struct D3DXShader::CInstruction *a2,
        unsigned int a3)
{
  _DWORD *i; // edx
  int v5; // eax
  unsigned int v6; // eax
  int v8; // [esp+Ch] [ebp-4h]
  struct D3DXShader::CInstruction *v9; // [esp+18h] [ebp+8h]

  v8 = 0;
  v9 = *((struct D3DXShader::CInstruction **)a2 + 1);
  if ( v9 == nullptr )
    return 0;
  for ( i = *((_DWORD **)a2 + 2); ; ++i )
  {
    v5 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *i);
    if ( *((_DWORD *)this + 34) == *(_DWORD *)(v5 + 4) )
    {
      v6 = *(_DWORD *)(v5 + 80);
      if ( v6 < a3 && (*(_WORD *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * v6) + 2) & 0xFFF0) != 0 )
        break;
    }
    if ( ++v8 >= (unsigned int)v9 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10212AED
// Name: protected: long D3DXShader::CVSProgram::EmitAddresses(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::EmitAddresses(D3DXShader::CVSProgram *this)
{
  int v1; // eax
  int result; // eax
  unsigned int v3; // edi
  int v4; // ebx
  _DWORD *i; // eax
  int v6; // edx

  if ( (unsigned __int16)*((_DWORD *)this + 50) >= 0x200u )
    return 0;
  v1 = *((_DWORD *)this + 64);
  if ( (*(_WORD *)(v1 + 2) & 0xFFF0) == 0 )
    return 0;
  v3 = *(_DWORD *)(v1 + 4);
  v4 = 0;
  if ( v3 == 0 )
    return 0;
  for ( i = *(_DWORD **)(v1 + 8); ; ++i )
  {
    v6 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *i);
    if ( *(_DWORD *)(v6 + 8) != -1 )
      break;
    if ( ++v4 >= v3 )
      return 0;
  }
  result = D3DXShader::C30Program::EmitAddress(this, a2: *(_DWORD *)(v6 + 8));
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10212B49
// Name: protected: virtual long D3DXShader::CVSProgram::EmitInstructions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::EmitInstructions(D3DXShader::CVSProgram *this)
{
  unsigned int i; // edi
  int v3; // eax
  unsigned int j; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int result; // eax
  void *v9; // eax
  int v10; // eax
  _exception *v11; // [esp+0h] [ebp-Ch]

  for ( i = 0; i < *((_DWORD *)this + 3); ++i )
  {
    v3 = *((_DWORD *)this + 6);
    *((_DWORD *)this + 63) = i;
    *((_DWORD *)this + 64) = *(_DWORD *)(v3 + 4 * i);
    D3DXShader::CShaderProgram::SortInstruction(this);
  }
  for ( j = 0; j < *((_DWORD *)this + 3); ++j )
  {
    v5 = *((_DWORD *)this + 6);
    *((_DWORD *)this + 63) = j;
    v6 = *(_DWORD *)(v5 + 4 * j);
    *((_DWORD *)this + 64) = v6;
    v7 = *(_DWORD *)(v6 + 60);
    if ( v7 != 0 && *(_DWORD *)(v7 + 4) == 13 )
      *((_DWORD *)this + 65) = v7 + 48;
    result = D3DXShader::CVSProgram::EmitAddresses(this);
    if ( result < 0 )
      return result;
    v9 = (void *)(**((_DWORD **)this + 64) & 0xFFF00000);
    if ( (unsigned int)v9 > 0x70600000 )
    {
      if ( (unsigned int)v9 > 0x73A00000 )
      {
        if ( (unsigned int)v9 > 0x74200000 )
        {
          if ( v9 == (void *)1950351360
            || v9 == (void *)1951399936
            || v9 == (void *)1952448512
            || v9 == (void *)1953497088 )
          {
            if ( (*((_BYTE *)this + 112) & 4) != 0 )
              v10 = D3DXShader::CShaderProgram::EmitBREAK(this);
            else
              v10 = -2147467263;
          }
          else if ( v9 == (void *)1956642816 )
          {
            v10 = D3DXShader::CShaderProgram::EmitENDLOOP_INC(this);
          }
          else
          {
            if ( v9 != (void *)1957691392 )
              goto LABEL_118;
            v10 = D3DXShader::CShaderProgram::EmitENDLOOP(this);
          }
          goto LABEL_114;
        }
        if ( v9 == (void *)1948254208 )
        {
          v10 = D3DXShader::CShaderProgram::EmitLOOP(this);
        }
        else
        {
          if ( v9 == (void *)1940914176 || v9 == (void *)1941962752 )
            goto LABEL_88;
          if ( v9 == (void *)1943011328
            || v9 == (void *)1944059904
            || v9 == (void *)1945108480
            || v9 == (void *)1946157056 )
          {
LABEL_101:
            v10 = D3DXShader::CShaderProgram::EmitANDELSE(this);
            goto LABEL_114;
          }
          if ( v9 != (void *)1947205632 )
            goto LABEL_118;
          v10 = D3DXShader::CShaderProgram::EmitLOOP_INC(this);
        }
      }
      else
      {
        if ( v9 == (void *)1939865600 )
          goto LABEL_88;
        if ( (unsigned int)v9 > 0x73300000 )
        {
          if ( v9 != (void *)1933574144 )
          {
            if ( v9 != (void *)1934622720
              && v9 != (void *)1935671296
              && v9 != (void *)1936719872
              && v9 != (void *)1937768448 )
            {
              if ( v9 != (void *)1938817024 )
                goto LABEL_118;
LABEL_88:
              v10 = D3DXShader::CShaderProgram::EmitANDIF(this);
              goto LABEL_114;
            }
LABEL_89:
            v10 = D3DXShader::CShaderProgram::EmitIF(this);
            goto LABEL_114;
          }
          v10 = D3DXShader::CShaderProgram::EmitANDENDIF(this);
        }
        else
        {
          if ( v9 == (void *)1932525568 )
            goto LABEL_101;
          if ( v9 == (void *)1886388224 )
            goto LABEL_61;
          if ( v9 == (void *)1888485376 )
          {
            v10 = D3DXShader::CShaderProgram::EmitDST(this);
            goto LABEL_114;
          }
          if ( v9 == (void *)1892679680 )
          {
            v10 = D3DXShader::CShaderProgram::EmitPOW(this);
            goto LABEL_114;
          }
          if ( v9 == (void *)1895825408 )
          {
            v10 = D3DXShader::CVSProgram::VSEmitFRC(this);
            goto LABEL_114;
          }
          if ( v9 == (void *)1929379840 )
          {
            v10 = D3DXShader::CShaderProgram::EmitANDIFBOOL(this, a2: 0);
            goto LABEL_114;
          }
          if ( v9 == (void *)1930428416 )
            goto LABEL_101;
          if ( v9 != (void *)1931476992 )
            goto LABEL_118;
          v10 = D3DXShader::CShaderProgram::EmitANDIFBOOL(this, a2: 1);
        }
      }
    }
    else
    {
      if ( v9 == (void *)1885339648 )
        goto LABEL_61;
      if ( (unsigned int)v9 > 0x20300000 )
      {
        if ( (unsigned int)v9 > 0x50300000 )
        {
          if ( v9 == (void *)1879048192 )
          {
            v10 = D3DXShader::CShaderProgram::EmitABS(this);
          }
          else if ( v9 == (void *)1880096768 )
          {
            v10 = D3DXShader::CShaderProgram::EmitLRP(this);
          }
          else if ( v9 == (void *)1881145344 )
          {
            v10 = D3DXShader::CShaderProgram::EmitNRM(this);
          }
          else
          {
            if ( v9 != (void *)1882193920 && v9 != (void *)1883242496 )
            {
              if ( v9 != (void *)1884291072 )
                goto LABEL_118;
LABEL_61:
              v10 = D3DXShader::CShaderProgram::EmitMAT(this);
              goto LABEL_114;
            }
            v10 = D3DXShader::CShaderProgram::EmitMAD(this);
          }
        }
        else if ( v9 == (void *)1345323008 )
        {
          v10 = D3DXShader::CShaderProgram::EmitSINCOS(this);
        }
        else if ( v9 == (void *)541065216 )
        {
          v10 = D3DXShader::CShaderProgram::EmitADD(this);
        }
        else if ( v9 == (void *)542113792 )
        {
          v10 = D3DXShader::CShaderProgram::EmitMUL(this);
        }
        else if ( v9 == (void *)544210944 )
        {
          v10 = D3DXShader::CShaderProgram::EmitENDIF(this);
        }
        else
        {
          if ( v9 == (void *)545259520 )
            continue;
          if ( v9 == (void *)546308096 )
            goto LABEL_38;
          if ( v9 == (void *)1342177280 )
          {
            v10 = D3DXShader::CShaderProgram::EmitDOT(this);
          }
          else
          {
            if ( v9 != (void *)1343225856 )
              goto LABEL_118;
            v10 = D3DXShader::CShaderProgram::EmitLIT(this);
          }
        }
      }
      else
      {
        if ( v9 == (void *)540016640 )
        {
          v10 = D3DXShader::CShaderProgram::EmitGE(this);
          goto LABEL_114;
        }
        if ( (unsigned int)v9 > 0x10700000 )
        {
          if ( v9 == (void *)284164096 )
            goto LABEL_89;
          if ( v9 == (void *)287309824 )
            goto LABEL_38;
          if ( v9 == (void *)288358400 )
            continue;
          if ( v9 == (void *)290455552 )
            goto LABEL_38;
          if ( v9 == (void *)0x20000000 )
          {
            v10 = D3DXShader::CShaderProgram::EmitMIN(this);
          }
          else if ( v9 == (void *)537919488 )
          {
            v10 = D3DXShader::CShaderProgram::EmitMAX(this);
          }
          else
          {
            if ( v9 != (void *)538968064 )
              goto LABEL_118;
            v10 = D3DXShader::CShaderProgram::EmitLT(this);
          }
        }
        else
        {
          if ( v9 == (void *)275775488 )
          {
            v10 = D3DXShader::CShaderProgram::EmitRSQ(this);
            goto LABEL_114;
          }
          if ( v9 == nullptr )
          {
            v10 = D3DXShader::CShaderProgram::EmitVersion(pexcept: v11);
            goto LABEL_114;
          }
          if ( v9 == (void *)0x10000000 )
          {
LABEL_38:
            v10 = D3DXShader::CShaderProgram::EmitMOV(this);
            goto LABEL_114;
          }
          if ( v9 == &loc_10100000 )
          {
            v10 = D3DXShader::CShaderProgram::EmitNEG(this);
          }
          else if ( v9 == &unk_10300000 )
          {
            v10 = D3DXShader::CShaderProgram::EmitRCP(this);
          }
          else if ( v9 == (void *)272629760 )
          {
            v10 = D3DXShader::CShaderProgram::EmitFRC(this);
          }
          else if ( v9 == (void *)273678336 )
          {
            v10 = D3DXShader::CVSProgram::VSEmitEXP(this);
          }
          else
          {
            if ( v9 != (void *)274726912 )
              goto LABEL_118;
            v10 = D3DXShader::CVSProgram::VSEmitLOG(this);
          }
        }
      }
    }
LABEL_114:
    if ( v10 == -2147467263 )
    {
LABEL_118:
      D3DXShader::CProgram::Error(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x11B4u,
        format: "cannot map expression to vertex shader instruction set");
      return -2147467263;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10212FBF
// Name: public: D3DXShader::CFXLProgram::CFXLProgram(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CFXLProgram *__thiscall D3DXShader::CFXLProgram::CFXLProgram(D3DXShader::CFXLProgram *this)
{
  D3DXShader::CShaderProgram::CShaderProgram(this);
  *((_DWORD *)this + 126) = 0;
  *(_DWORD *)this = &D3DXShader::CFXLProgram::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10212FDA
// Name: protected: virtual long D3DXShader::CFXLProgram::InitCaps(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CFXLProgram::InitCaps(D3DXShader::CFXLProgram *this)
{
  int v2; // eax
  _DWORD v4[3]; // [esp+4h] [ebp-Ch] BYREF

  D3DXGetTargetDescByName(a1: (const char *)&stru_102A6BD8.m_Memory.m_nAllocationCount, a2: 0, a3: v4);
  v2 = v4[1];
  *((_DWORD *)this + 12) = 0;
  *((_BYTE *)this + 113) |= 2u;
  *((_DWORD *)this + 66) = v2;
  *((_DWORD *)this + 10) = 64;
  *((_DWORD *)this + 11) = 64;
  *((_DWORD *)this + 27) = *((_DWORD *)this + 27) & 0x7FFFFCFC | 0x80000202;
  *((_DWORD *)this + 14) = 0x2000;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021302B
// Name: public: long D3DXShader::CFXLProgram::EmitPool(class D3DXShader::CArgument __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CFXLProgram::EmitPool(D3DXShader::CFXLProgram *this, struct D3DXShader::CArgument *a2)
{
  int v2; // eax

  v2 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)a2 + 1)) + 4);
  if ( (v2 & 0x100) != 0 )
    return D3DXShader::CShaderProgram::Emit(this, a2: 1u);
  if ( (v2 & 0x200) != 0 && (v2 & 0x80u) != 0 )
    return D3DXShader::CShaderProgram::Emit(this, a2: 9u);
  if ( (v2 & 0x200) != 0 )
    return D3DXShader::CShaderProgram::Emit(this, a2: 2u);
  if ( (v2 & 0x10) != 0 )
    return D3DXShader::CShaderProgram::Emit(this, a2: 3u);
  if ( (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)a2 + 1)) + 4) & 0x2020) == 0x2020 )
    return D3DXShader::CShaderProgram::Emit(this, a2: 5u);
  if ( (v2 & 0x40020) == 0x40020 )
    return D3DXShader::CShaderProgram::Emit(this, a2: 6u);
  if ( (v2 & 0x20) != 0 )
    return D3DXShader::CShaderProgram::Emit(this, a2: 4u);
  if ( (v2 & 1) != 0 )
  {
    if ( (v2 & 2) != 0 )
      return D3DXShader::CShaderProgram::Emit(this, a2: 7u);
  }
  else if ( (v2 & 2) != 0 && (v2 & 4) != 0 )
  {
    return D3DXShader::CShaderProgram::Emit(this, a2: 8u);
  }
  if ( (v2 & 0x10000) != 0 )
    D3DXShader::CProgram::Error(
      this,
      a2: *(struct D3DXShader::CNode **)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)a2 + 18)) + 60),
      a3: 0x1194u,
      format: "clip not supported in texture shaders");
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x102130EC
// Name: public: long D3DXShader::CFXLProgram::EmitDouble(double)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CFXLProgram::EmitDouble(D3DXShader::CFXLProgram *this, double a2)
{
  int result; // eax

  result = D3DXShader::CShaderProgram::Assure(this, a2: 2u);
  if ( result >= 0 )
  {
    *(double *)(*((_DWORD *)this + 67) + 4 * *((_DWORD *)this + 68)) = a2;
    *((_DWORD *)this + 68) += 2;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10213124
// Name: public: virtual long D3DXShader::CFXLProgram::IndexSemantic(class D3DXShader::CArgument __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CFXLProgram::IndexSemantic(
        D3DXShader::CFXLProgram *this,
        struct D3DXShader::CArgument *a2,
        int a3)
{
  int v3; // ebx
  const char *v5; // esi
  char v6; // al
  unsigned int v7; // ebx
  int v8; // eax
  BOOL v9; // esi
  unsigned __int8 v10; // al
  int v12; // [esp+Ch] [ebp-28h]
  unsigned __int8 dest[32]; // [esp+10h] [ebp-24h] BYREF

  v3 = 0;
  LOBYTE(v12) = 0;
  if ( (*((_DWORD *)this + 50) & 0xFFFF0000) == 0x46580000 )
  {
    if ( *((_DWORD *)a2 + 27) == -1 )
      *((_DWORD *)a2 + 27) = (*((_DWORD *)this + 126))++;
  }
  else if ( *((_DWORD *)a2 + 27) == -1 )
  {
    strncpy(dest, source: *(unsigned __int8 **)(*((_DWORD *)a2 + 26) + 24), count: 0x20u);
    dest[31] = 0;
    v5 = (const char *)dest;
    if ( dest[0] != 0 )
    {
      do
      {
        if ( isalpha(c: *v5) == 0 )
          break;
        ++v5;
      }
      while ( *v5 != 0 );
      if ( *v5 == 0 )
        goto LABEL_13;
      v3 = atoi(nptr: v5);
    }
    if ( *v5 != 0 )
      *v5++ = 0;
LABEL_13:
    v6 = *v5;
    if ( *v5 == 0 )
      goto LABEL_18;
    do
    {
      if ( isdigit(c: v6) == 0 )
        break;
      v6 = *++v5;
    }
    while ( *v5 != 0 );
    if ( *v5 != 0 )
      v7 = -1;
    else
LABEL_18:
      v7 = (*((_DWORD *)a2 + 28) >> 2) + v3;
    v8 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)a2 + 1)) + 4);
    if ( (v8 & 0x10) != 0 && (v8 & 0x200) == 0 )
    {
      if ( _stricmp(dst: (const char *)dest, src: "position") == 0 )
      {
        v12 = 2;
      }
      else
      {
        if ( _stricmp(dst: (const char *)dest, src: "psize") != 0 )
        {
          v12 = 0;
          v9 = true;
          goto LABEL_27;
        }
        v12 = 3;
      }
      v9 = v7 != 0;
LABEL_27:
      if ( v9 && *((_DWORD *)a2 + 4) == 0 )
        D3DXShader::CProgram::Error(
          this,
          a2: *((struct D3DXShader::CNode **)a2 + 26),
          a3: 0x1196u,
          format: "invalid reference to input semantic '%s%d'",
          dest,
          v7);
      goto LABEL_37;
    }
    if ( (v8 & 0x20) == 0 )
    {
LABEL_38:
      v10 = v12;
      v9 = true;
      goto LABEL_39;
    }
    if ( _stricmp(dst: (const char *)dest, src: "color") == 0 )
    {
      v12 = 1;
      v9 = v7 != 0;
    }
    else
    {
      v12 = 0;
      v9 = true;
    }
    if ( v9 && *((_DWORD *)a2 + 4) == 0 )
      D3DXShader::CProgram::Error(
        this,
        a2: *((struct D3DXShader::CNode **)a2 + 26),
        a3: 0x1196u,
        format: "invalid reference to output semantic '%s%d'",
        dest,
        v7);
LABEL_37:
    v10 = v12;
    if ( v12 == 0 )
      goto LABEL_38;
LABEL_39:
    if ( v7 > 0xFFFF )
      v9 = true;
    *((_DWORD *)a2 + 27) = v10 | ((v7 | 0xFFFFFF00) << 8);
    return v9 ? 0x80004005 : 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10213324
// Name: public: long D3DXShader::CFXLProgram::EmitAddress(unsigned int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CFXLProgram::EmitAddress(D3DXShader::CFXLProgram *this, unsigned int a2, unsigned int a3)
{
  struct D3DXShader::CArgument *v4; // esi
  unsigned int v5; // eax

  v4 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * a2);
  v5 = *((_DWORD *)v4 + 2);
  if ( v5 != -1 && D3DXShader::CFXLProgram::EmitAddress(this, a2: v5, a3) < 0
    || D3DXShader::CFXLProgram::EmitPool(this, a2: v4) < 0
    || D3DXShader::CShaderProgram::Emit(this, a2: *((_DWORD *)v4 + 4) + 4 * *((_DWORD *)v4 + 3)) < 0 )
  {
    return -2147024882;
  }
  ++*(_DWORD *)(*((_DWORD *)this + 67) + 4 * a3);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021338B
// Name: public: virtual long D3DXShader::CFXLProgram::GenerateCode(struct ID3DXBuffer __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CFXLProgram::GenerateCode(D3DXShader::CFXLProgram *this, struct ID3DXBuffer **a2)
{
  bool v3; // zf
  int v5; // ebx
  int *v6; // edi
  int v7; // eax
  int v8; // edx
  unsigned int v9; // eax
  int v10; // eax
  unsigned int v11; // ebx
  unsigned int v12; // ecx
  int v13; // edx
  int v14; // eax
  unsigned int v15; // eax
  _DWORD *v16; // eax
  unsigned int v17; // edi
  unsigned int v18; // ecx
  _DWORD *v19; // eax
  unsigned int v20; // edi
  unsigned int i; // edi
  int v22; // eax
  int v23; // edx
  int v24; // ecx
  struct D3DXShader::CInstruction *v25; // edi
  int v26; // eax
  unsigned int v27; // ebx
  unsigned int v28; // eax
  int v29; // ecx
  _DWORD *v30; // eax
  int v31; // ecx
  unsigned int v32; // edx
  _DWORD *v33; // eax
  _DWORD *v34; // eax
  int *v35; // eax
  int v36; // eax
  int v37; // ecx
  int v38; // eax
  unsigned int v39; // ecx
  int *v40; // ecx
  struct D3DXCore::CBuffer *v41; // edx
  int *v42; // eax
  unsigned int v43; // eax
  void *v44; // edx
  unsigned __int8 *v45; // eax
  D3DXShader::CInstruction *v46; // ecx
  _DWORD *v47; // edx
  int v48; // ecx
  int v49; // eax
  struct D3DXCore::CBuffer *v50; // eax
  unsigned int v51; // ebx
  unsigned int j; // edi
  unsigned int k; // edi
  int v54; // eax
  unsigned int m; // edi
  unsigned int v56; // edi
  _DWORD *v57; // ebx
  unsigned int v58; // edi
  _DWORD *v59; // ebx
  unsigned int v60; // ebx
  int v61; // edi
  _DWORD *v62; // eax
  unsigned int v63; // edi
  int v64; // eax
  struct D3DXShader::CArgument *v65; // edi
  unsigned int v66; // ebx
  unsigned int v67; // eax
  struct D3DXShader::CArgument *v68; // edi
  unsigned int v69; // ebx
  unsigned int v70; // eax
  int v71; // eax
  _DWORD v72[4]; // [esp+14h] [ebp-94h]
  _DWORD *v73; // [esp+24h] [ebp-84h]
  unsigned int v74; // [esp+28h] [ebp-80h]
  unsigned int v75; // [esp+2Ch] [ebp-7Ch]
  unsigned int v76; // [esp+30h] [ebp-78h]
  int v77; // [esp+34h] [ebp-74h]
  int v78; // [esp+38h] [ebp-70h]
  int v79; // [esp+3Ch] [ebp-6Ch] BYREF
  int v80; // [esp+40h] [ebp-68h]
  int v81; // [esp+44h] [ebp-64h]
  void *v82; // [esp+48h] [ebp-60h]
  void *v83; // [esp+4Ch] [ebp-5Ch]
  void *v84; // [esp+50h] [ebp-58h]
  unsigned int v85; // [esp+54h] [ebp-54h]
  unsigned int v86; // [esp+58h] [ebp-50h]
  unsigned int v87; // [esp+5Ch] [ebp-4Ch]
  int v88; // [esp+60h] [ebp-48h]
  unsigned int v89; // [esp+64h] [ebp-44h]
  unsigned int v90; // [esp+68h] [ebp-40h]
  unsigned int v91; // [esp+6Ch] [ebp-3Ch]
  unsigned int v92; // [esp+70h] [ebp-38h]
  int v93; // [esp+74h] [ebp-34h]
  unsigned int v94; // [esp+78h] [ebp-30h]
  void *v95; // [esp+7Ch] [ebp-2Ch]
  int v96; // [esp+80h] [ebp-28h]
  unsigned int v97; // [esp+84h] [ebp-24h]
  int v98; // [esp+88h] [ebp-20h]
  unsigned int v99; // [esp+8Ch] [ebp-1Ch]
  unsigned int v100; // [esp+90h] [ebp-18h]
  struct D3DXCore::CBuffer *v101; // [esp+94h] [ebp-14h] BYREF
  _DWORD *v102; // [esp+98h] [ebp-10h]
  unsigned int v103; // [esp+9Ch] [ebp-Ch]
  int Code; // [esp+A0h] [ebp-8h]
  void *pMem; // [esp+A4h] [ebp-4h]

  v95 = nullptr;
  v89 = 0;
  v90 = 0;
  v91 = 0;
  v82 = nullptr;
  v83 = nullptr;
  v3 = *((_DWORD *)this + 3) == 0;
  v84 = nullptr;
  if ( v3 )
    return 1;
  Code = D3DXShader::CProgram::GenerateCode(this, a2);
  if ( Code < 0 )
    goto LABEL_212;
  Code = D3DXShader::CShaderProgram::CombineConstants(
           this,
           a2: *((_DWORD *)this + 31),
           a3: *((_DWORD *)this + 14),
           a4: 0x200u,
           a5: 0x42080u,
           a6: 99);
  if ( Code < 0 )
    goto LABEL_212;
  v97 = 0;
  v100 = 0;
  v85 = -1;
  v86 = -1;
  v87 = -1;
  v88 = -1;
  v74 = 0;
  v75 = 0;
  v76 = 0;
  v77 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    v5 = *((_DWORD *)this + 30);
    v6 = *((int **)this + 5);
    v102 = *((_DWORD **)this + 2);
    do
    {
      v7 = *v6;
      v8 = *(_DWORD *)(*v6 + 4);
      if ( v5 == v8 && *(_DWORD *)(v7 + 12) + 1 > v97 )
      {
        v97 = *(_DWORD *)(v7 + 12) + 1;
      }
      else if ( *((_DWORD *)this + 34) == v8 && *(_DWORD *)(v7 + 12) + 1 > v100 )
      {
        v100 = *(_DWORD *)(v7 + 12) + 1;
      }
      if ( *((_DWORD *)this + 33) == v8 )
      {
        if ( *(_DWORD *)(v7 + 12) > v74 )
          v74 = *(_DWORD *)(v7 + 12);
        if ( *((_DWORD *)this + 33) == v8 && *(_DWORD *)(v7 + 12) < v85 )
          v85 = *(_DWORD *)(v7 + 12);
      }
      if ( *((_DWORD *)this + 45) == v8 )
      {
        if ( *(_DWORD *)(v7 + 12) > v75 )
          v75 = *(_DWORD *)(v7 + 12);
        if ( *((_DWORD *)this + 45) == v8 && *(_DWORD *)(v7 + 12) < v86 )
          v86 = *(_DWORD *)(v7 + 12);
      }
      if ( *((_DWORD *)this + 46) == v8 )
      {
        if ( *(_DWORD *)(v7 + 12) > v76 )
          v76 = *(_DWORD *)(v7 + 12);
        if ( *((_DWORD *)this + 46) == v8 )
        {
          v9 = *(_DWORD *)(v7 + 12);
          if ( v9 < v87 )
            v87 = v9;
        }
      }
      ++v6;
      v102 = (_DWORD *)((char *)v102 - 1);
    }
    while ( v102 != nullptr );
  }
  v10 = *((_DWORD *)this + 33);
  v99 = 0;
  v79 = v10;
  v80 = *((_DWORD *)this + 45);
  v81 = *((_DWORD *)this + 46);
  do
  {
    if ( *(unsigned int *)((char *)&v85 + v99) != -1 )
    {
      v11 = *(unsigned int *)((char *)&v74 + v99) - *(unsigned int *)((char *)&v85 + v99) + 1;
      pMem = MemAlloc_Alloc(nSize: v11);
      if ( pMem == nullptr )
        goto LABEL_75;
      memset(pMem, 0, v11);
      v12 = 0;
      if ( *((_DWORD *)this + 2) != 0 )
      {
        v13 = *(int *)((char *)&v79 + v99);
        do
        {
          v14 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v12);
          if ( v13 == *(_DWORD *)(v14 + 4) )
            *((_BYTE *)pMem + *(_DWORD *)(v14 + 12) - *(unsigned int *)((char *)&v85 + v99)) = 1;
          ++v12;
        }
        while ( v12 < *((_DWORD *)this + 2) );
      }
      v15 = 0;
      v103 = 0;
      if ( v11 != 0 )
      {
        while ( 1 )
        {
          if ( v15 < v11 )
            goto LABEL_42;
          do
          {
            ++v103;
            while ( v15 < v11 && *((_BYTE *)pMem + v15) != 0 )
              ++v15;
            if ( ++v15 >= v11 )
              goto LABEL_50;
LABEL_42:
            ;
          }
          while ( *((_BYTE *)pMem + v15) != 0 );
          ++v15;
        }
      }
LABEL_50:
      v16 = MemAlloc_Alloc(nSize: 8 * v103);
      v17 = v99;
      *(void **)((char *)&v82 + v99) = v16;
      if ( v16 == nullptr )
      {
        free(pMem);
        goto LABEL_75;
      }
      v18 = 0;
      if ( v11 != 0 )
      {
        while ( 1 )
        {
          if ( v18 < v11 )
            goto LABEL_53;
          do
          {
            *v16 = v18 + *(unsigned int *)((char *)&v85 + v17);
            v19 = v16 + 1;
            while ( v18 < v11 && *((_BYTE *)pMem + v18) != 0 )
              ++v18;
            *v19 = v18 + *(unsigned int *)((char *)&v85 + v17) - *(v19 - 1);
            v16 = v19 + 1;
            if ( ++v18 >= v11 )
              goto LABEL_61;
LABEL_53:
            ;
          }
          while ( *((_BYTE *)pMem + v18) != 0 );
          ++v18;
        }
      }
LABEL_61:
      free(pMem);
      *(unsigned int *)((char *)&v89 + v17) = v103;
    }
    v99 += 4;
  }
  while ( v99 < 0xC );
  v20 = 32 * v97;
  v95 = MemAlloc_Alloc(nSize: 32 * v97);
  if ( v95 == nullptr )
    goto LABEL_75;
  if ( v100 > 0x40 )
    goto LABEL_212;
  memset(v95, 0, v20);
  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    v22 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * i);
    if ( *((_DWORD *)this + 30) == *(_DWORD *)(v22 + 4) && *(_DWORD *)(v22 + 8) == -1 )
      *((double *)v95 + 4 * *(_DWORD *)(v22 + 12) + *(_DWORD *)(v22 + 16)) = *(double *)(v22 + 32);
    if ( *((_DWORD *)this + 50) == 1415053568 )
    {
      v23 = *(_DWORD *)(v22 + 4);
      if ( *((_DWORD *)this + 32) == v23 )
      {
        if ( *(_DWORD *)(v22 + 12) > 1u )
        {
          D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x1194u, format: "too many arguments to target TX");
          goto LABEL_212;
        }
        v24 = (unsigned __int8)*(_DWORD *)(v22 + 108);
        if ( v24 == 2 )
        {
          *(_DWORD *)(v22 + 12) = 0;
        }
        else if ( v24 == 3 )
        {
          *(_DWORD *)(v22 + 12) = 1;
        }
      }
      if ( *((_DWORD *)this + 33) == v23 && *(_DWORD *)(v22 + 12) != 0 )
      {
        D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x1194u, format: "too many outputs to target TX");
        goto LABEL_212;
      }
    }
  }
  v92 = *((_DWORD *)this + 3);
  v100 = 0;
  if ( v92 != 0 )
  {
    while ( 2 )
    {
      v25 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v100);
      v26 = *(_DWORD *)v25;
      v98 = 0;
      *((_DWORD *)v25 + 10) = 0;
      v94 = v26 & 0xFFF00000;
      v27 = v26 & 0xFFFFF;
      if ( (v26 & 0xFFFFF) != 0 )
      {
        v28 = *((_DWORD *)v25 + 1) / v27;
        v29 = *((_DWORD *)this + 5);
        v103 = 0;
        v99 = v28;
        v3 = v28 == 0;
        v30 = *((_DWORD **)v25 + 4);
        v78 = *(_DWORD *)(*(_DWORD *)(v29 + 4 * *v30) + 16);
        if ( !v3 )
        {
          pMem = *((void **)v25 + 2);
          do
          {
            v31 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)pMem) + 16);
            v32 = v103++;
            *(&v79 + v32) = v31;
            pMem = (char *)pMem + 4 * v27;
          }
          while ( v103 < v99 );
        }
        if ( v27 == *((_DWORD *)v25 + 3) && v27 > 1 )
        {
          v103 = v78 + 1;
          v33 = v30 + 1;
          v102 = (_DWORD *)(v27 - 1);
          do
          {
            if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v33) + 16) == v103 )
            {
              ++v78;
              ++v103;
            }
            else
            {
              v98 = 1;
            }
            ++v33;
            v102 = (_DWORD *)((char *)v102 - 1);
          }
          while ( v102 != nullptr );
        }
        if ( v99 != 2 || v98 != 0 )
          goto LABEL_119;
        Code = 1;
        pMem = (void *)(v80 + 1);
        if ( v27 <= 1 )
          goto LABEL_118;
        v34 = *((_DWORD **)v25 + 2);
        v93 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v34) + 16);
        v73 = v34 + 1;
        v103 = (unsigned int)(v34 + 1);
        v35 = &v34[v27];
        v96 = (int)(v35 + 1);
        v102 = v35 + 1;
        v101 = (struct D3DXCore::CBuffer *)(v27 - 1);
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)v103) + 16) != v93 )
            Code = 0;
          if ( *(void **)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v102) + 16) == pMem )
            pMem = (char *)pMem + 1;
          else
            Code = 0;
          v103 += 4;
          ++v102;
          v101 = (struct D3DXCore::CBuffer *)((char *)v101 - 1);
        }
        while ( v101 != nullptr );
        if ( Code != 0 )
        {
LABEL_118:
          *((_DWORD *)v25 + 10) = 1;
        }
        else
        {
          v36 = *v35;
          pMem = (void *)(v79 + 1);
          v37 = *((_DWORD *)this + 5);
          v93 = *(_DWORD *)(*(_DWORD *)(v37 + 4 * v36) + 16);
          v103 = (unsigned int)v73;
          v102 = (_DWORD *)v96;
          Code = 1;
          v101 = (struct D3DXCore::CBuffer *)(v27 - 1);
          do
          {
            if ( *(_DWORD *)(*(_DWORD *)(v37 + 4 * *v102) + 16) != v93 )
              Code = 0;
            if ( *(void **)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)v103) + 16) == pMem )
              pMem = (char *)pMem + 1;
            else
              Code = 0;
            ++v102;
            v103 += 4;
            v101 = (struct D3DXCore::CBuffer *)((char *)v101 - 1);
          }
          while ( v101 != nullptr );
          if ( Code != 0 )
          {
            v103 = 0;
            v101 = (struct D3DXCore::CBuffer *)(4 * v27);
            do
            {
              v38 = *((_DWORD *)v25 + 2);
              v39 = v103++;
              v40 = (int *)(v38 + 4 * v39);
              v96 = *v40;
              v41 = v101;
              *v40 = *(_DWORD *)((char *)v101 + v38);
              *(_DWORD *)((char *)v41 + *((_DWORD *)v25 + 2)) = v96;
              v101 = (struct D3DXCore::CBuffer *)((char *)v41 + 4);
            }
            while ( v103 < v27 );
            goto LABEL_118;
          }
LABEL_119:
          pMem = (void *)1;
          if ( v27 > 1 )
          {
            do
            {
              v103 = 0;
              if ( v99 != 0 )
              {
                v102 = (_DWORD *)(*((_DWORD *)v25 + 2) + 4 * (_DWORD)pMem);
                do
                {
                  v42 = &v79 + v103;
                  v96 = *v42 + 1;
                  if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v102) + 16) == v96 )
                    *v42 = v96;
                  else
                    v98 = 1;
                  ++v103;
                  v102 += v27;
                }
                while ( v103 < v99 );
              }
              pMem = (char *)pMem + 1;
            }
            while ( (unsigned int)pMem < v27 );
          }
          if ( v98 != 0 )
          {
            if ( v94 != 1342177280 )
            {
              if ( v94 == 1345323008 )
              {
                pMem = nullptr;
                while ( 1 )
                {
                  if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                             + 4 * *(_DWORD *)(*((_DWORD *)v25 + 4) + 4 * (_DWORD)pMem))
                                 + 92) != 0 )
                  {
                    if ( pMem != nullptr )
                      v43 = D3DXShader::CBaseProgram::AddInstruction(this, a2: 0x10800001u, a3: 1u, a4: 1u);
                    else
                      v43 = D3DXShader::CBaseProgram::AddInstruction(this, a2: 0x10900001u, a3: 1u, a4: 1u);
                    if ( v43 == -1 )
                      goto LABEL_75;
                    v101 = *(struct D3DXCore::CBuffer **)(*((_DWORD *)this + 6) + 4 * v43);
                    Code = D3DXShader::CInstruction::Instance(this: v101, a2: v25);
                    if ( Code < 0 )
                      goto LABEL_212;
                    v44 = pMem;
                    **((_DWORD **)v101 + 4) = *(_DWORD *)(*((_DWORD *)v25 + 4) + 4 * (_DWORD)pMem);
                    **((_DWORD **)v101 + 2) = *(_DWORD *)(*((_DWORD *)v25 + 2) + 4 * (_DWORD)v44);
                  }
                  pMem = (char *)pMem + 1;
                  if ( (unsigned int)pMem >= v27 )
                    goto LABEL_153;
                }
              }
              v103 = 0;
              while ( 1 )
              {
                v45 = D3DXShader::CInstruction::operator new(a1: 0x74u);
                pMem = v45 != nullptr
                     ? (void *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v45)
                     : nullptr;
                v46 = (D3DXShader::CInstruction *)pMem;
                v3 = pMem == nullptr;
                v72[v103] = pMem;
                if ( v3 )
                  break;
                Code = D3DXShader::CInstruction::Initialize(this: v46, a2: v94 | 1, a3: v99, a4: 1u, a5: 0);
                if ( Code < 0 )
                  goto LABEL_212;
                Code = D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)pMem, a2: v25);
                if ( Code < 0 )
                  goto LABEL_212;
                v47 = *((_DWORD **)pMem + 4);
                v48 = *((_DWORD *)v25 + 4);
                v101 = nullptr;
                v49 = 4 * v103;
                v3 = v99 == 0;
                *v47 = *(_DWORD *)(4 * v103 + v48);
                if ( !v3 )
                {
                  v102 = (_DWORD *)v49;
                  do
                  {
                    v50 = v101;
                    *(_DWORD *)(*((_DWORD *)pMem + 2) + 4 * (_DWORD)v101) = *(_DWORD *)((char *)v102
                                                                                      + *((_DWORD *)v25 + 2));
                    v102 += v27;
                    v101 = (struct D3DXCore::CBuffer *)((char *)v50 + 1);
                  }
                  while ( (unsigned int)v50 + 1 < v99 );
                }
                D3DXShader::CBaseProgram::CopyInstruction(this, a2: (struct D3DXShader::CInstruction *)pMem);
                D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)pMem, a2: 1);
                if ( ++v103 >= v27 )
                  goto LABEL_153;
              }
LABEL_75:
              Code = -2147024882;
              goto LABEL_212;
            }
            *(_DWORD *)v25 = 1893728257;
          }
        }
      }
      D3DXShader::CBaseProgram::CopyInstruction(this, a2: v25);
LABEL_153:
      *(_DWORD *)v25 = 0;
      if ( ++v100 >= v92 )
        break;
      continue;
    }
  }
  D3DXShader::CProgram::CompactInstructions(this);
  Code = D3DXShader::CShaderProgram::Emit(this, a2: *((_DWORD *)this + 50));
  if ( Code < 0 )
    goto LABEL_212;
  if ( *((_DWORD *)this + 50) == 1180172801 )
  {
    v51 = v89;
    D3DXShader::CShaderProgram::Emit(this, a2: ((v90 + v91 + v89 + 5) << 17) & 0x7FFF0000 | 0xFFFE);
    Code = D3DXShader::CShaderProgram::Emit(this, a2: 0x49535250u);
    if ( Code < 0 )
      goto LABEL_212;
    for ( j = 0; j < 3; ++j )
    {
      if ( *(&v85 + j) == -1 )
        D3DXShader::CShaderProgram::Emit(this, a2: 0);
      else
        D3DXShader::CShaderProgram::Emit(this, a2: *(&v85 + j));
    }
    for ( k = 0; k < 0xC; k += 4 )
    {
      v54 = *(unsigned int *)((char *)&v85 + k);
      if ( v54 == -1 )
        D3DXShader::CShaderProgram::Emit(this, a2: 0);
      else
        D3DXShader::CShaderProgram::Emit(this, a2: *(unsigned int *)((char *)&v74 + k) - v54 + 1);
    }
    D3DXShader::CShaderProgram::Emit(this, a2: v51);
    for ( m = 0; m < v51; ++m )
    {
      D3DXShader::CShaderProgram::Emit(this, a2: *((_DWORD *)v82 + 2 * m));
      D3DXShader::CShaderProgram::Emit(this, a2: *((_DWORD *)v82 + 2 * m + 1));
    }
    D3DXShader::CShaderProgram::Emit(this, a2: v90);
    v56 = 0;
    if ( v90 != 0 )
    {
      v57 = v83;
      do
      {
        D3DXShader::CShaderProgram::Emit(this, a2: v57[2 * v56]);
        D3DXShader::CShaderProgram::Emit(this, a2: v57[2 * v56++ + 1]);
      }
      while ( v56 < v90 );
    }
    D3DXShader::CShaderProgram::Emit(this, a2: v91);
    v58 = 0;
    if ( v91 != 0 )
    {
      v59 = v84;
      do
      {
        D3DXShader::CShaderProgram::Emit(this, a2: v59[2 * v58]);
        D3DXShader::CShaderProgram::Emit(this, a2: v59[2 * v58++ + 1]);
      }
      while ( v58 < v91 );
    }
  }
  Code = D3DXShader::CShaderProgram::EmitSymbolTable(this);
  if ( Code >= 0 )
  {
    Code = D3DXShader::CShaderProgram::Emit(this, a2: ((v97 << 19) + 0x20000) & 0x7FFF0000 | 0xFFFE);
    if ( Code >= 0 )
    {
      Code = D3DXShader::CShaderProgram::Emit(this, a2: 0x54494C43u);
      if ( Code >= 0 )
      {
        v60 = 4 * v97;
        Code = D3DXShader::CShaderProgram::Emit(this, a2: 4 * v97);
        if ( Code >= 0 )
        {
          v61 = 0;
          if ( v60 != 0 )
          {
            while ( 1 )
            {
              Code = D3DXShader::CFXLProgram::EmitDouble(this, a2: *((double *)v95 + v61));
              if ( Code < 0 )
                break;
              if ( ++v61 >= v60 )
                goto LABEL_182;
            }
          }
          else
          {
LABEL_182:
            v98 = *((_DWORD *)this + 68);
            Code = D3DXShader::CShaderProgram::Emit(this, a2: 0);
            if ( Code >= 0 )
            {
              Code = D3DXShader::CShaderProgram::Emit(this, a2: 0x434C5846u);
              if ( Code >= 0 )
              {
                Code = D3DXShader::CShaderProgram::Emit(this, a2: *((_DWORD *)this + 3));
                if ( Code >= 0 )
                {
                  v3 = *((_DWORD *)this + 3) == 0;
                  v97 = 0;
                  if ( v3 )
                  {
LABEL_205:
                    Code = D3DXShader::CShaderProgram::Emit(this, a2: 0xF0F0F0F0);
                    if ( Code >= 0 )
                    {
                      Code = D3DXShader::CShaderProgram::Emit(this, a2: 0xF0F0F0Fu);
                      if ( Code >= 0 )
                      {
                        *(_DWORD *)(*((_DWORD *)this + 67) + 4 * v98) = ((*(_DWORD *)(*((_DWORD *)this + 67) + 4 * v98)
                                                                        + 4) << 16)
                                                                      & 0x7FFF0000
                                                                      | 0xFFFE;
                        Code = D3DXShader::CShaderProgram::Emit(this, a2: 0xFFFFu);
                        if ( Code >= 0 )
                        {
                          if ( a2 != nullptr )
                          {
                            Code = D3DXCore::CBuffer::Create(a1: 4 * *((_DWORD *)this + 68), a2: &v101);
                            if ( Code < 0 )
                              goto LABEL_212;
                            qmemcpy(
                              (void *)(*(int (__stdcall **)(struct D3DXCore::CBuffer *))(*(_DWORD *)v101 + 12))(a1: v101),
                              *((const void **)this + 67),
                              4 * *((_DWORD *)this + 68));
                            *a2 = (struct ID3DXBuffer *)v101;
                          }
                          Code = 0;
                        }
                      }
                    }
                  }
                  else
                  {
                    pMem = nullptr;
LABEL_187:
                    Code = D3DXShader::CShaderProgram::Emit(
                             this,
                             a2: **(_DWORD **)((char *)pMem + *((_DWORD *)this + 6))
                           | (*(_DWORD *)(*(_DWORD *)((char *)pMem + *((_DWORD *)this + 6)) + 40) != 0 ? 0x80000000 : 0));
                    if ( Code >= 0 )
                    {
                      v62 = *(_DWORD **)((char *)pMem + *((_DWORD *)this + 6));
                      v63 = *v62 & 0xFFFFF;
                      v101 = (struct D3DXCore::CBuffer *)(v62[1] / v63);
                      Code = D3DXShader::CShaderProgram::Emit(this, a2: (unsigned int)v101);
                      if ( Code >= 0 )
                      {
                        v64 = *((_DWORD *)this + 67);
                        v100 = 0;
                        *(_DWORD *)(v64 + 4 * v98) += 2;
                        if ( v101 != nullptr )
                        {
                          v102 = nullptr;
                          v92 = 4 * v63;
                          while ( 1 )
                          {
                            v65 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5)
                                                                   + 4
                                                                   * *(_DWORD *)((char *)v102
                                                                               + *(_DWORD *)(*(_DWORD *)((char *)pMem + *((_DWORD *)this + 6))
                                                                                           + 8)));
                            v66 = *((_DWORD *)this + 68);
                            Code = D3DXShader::CShaderProgram::Emit(this, a2: 0);
                            if ( Code < 0 )
                              break;
                            v67 = *((_DWORD *)v65 + 2);
                            if ( v67 != -1 )
                            {
                              Code = D3DXShader::CFXLProgram::EmitAddress(this, a2: v67, a3: v66);
                              if ( Code < 0 )
                                break;
                            }
                            Code = D3DXShader::CFXLProgram::EmitPool(this, a2: v65);
                            if ( Code < 0 )
                              break;
                            Code = D3DXShader::CShaderProgram::Emit(
                                     this,
                                     a2: *((_DWORD *)v65 + 4) + 4 * *((_DWORD *)v65 + 3));
                            if ( Code < 0 )
                              break;
                            *(_DWORD *)(*((_DWORD *)this + 67) + 4 * v98) += 2
                                                                           * *(_DWORD *)(*((_DWORD *)this + 67) + 4 * v66)
                                                                           + 3;
                            ++v100;
                            v102 = (_DWORD *)((char *)v102 + v92);
                            if ( v100 >= (unsigned int)v101 )
                              goto LABEL_197;
                          }
                        }
                        else
                        {
LABEL_197:
                          v100 = 0;
                          while ( 1 )
                          {
                            v68 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5)
                                                                   + 4
                                                                   * *(_DWORD *)(v100
                                                                               + *(_DWORD *)(*(_DWORD *)((char *)pMem + *((_DWORD *)this + 6))
                                                                                           + 16)));
                            v69 = *((_DWORD *)this + 68);
                            Code = D3DXShader::CShaderProgram::Emit(this, a2: 0);
                            if ( Code < 0 )
                              break;
                            v70 = *((_DWORD *)v68 + 2);
                            if ( v70 != -1 )
                            {
                              Code = D3DXShader::CFXLProgram::EmitAddress(this, a2: v70, a3: v69);
                              if ( Code < 0 )
                                break;
                            }
                            Code = D3DXShader::CFXLProgram::EmitPool(this, a2: v68);
                            if ( Code < 0 )
                              break;
                            Code = D3DXShader::CShaderProgram::Emit(
                                     this,
                                     a2: *((_DWORD *)v68 + 4) + 4 * *((_DWORD *)v68 + 3));
                            if ( Code < 0 )
                              break;
                            v71 = *((_DWORD *)this + 67);
                            v100 += 4;
                            *(_DWORD *)(v71 + 4 * v98) += 2 * *(_DWORD *)(v71 + 4 * v69) + 3;
                            if ( v100 >= 4 )
                            {
                              ++v97;
                              pMem = (char *)pMem + 4;
                              if ( v97 < *((_DWORD *)this + 3) )
                                goto LABEL_187;
                              goto LABEL_205;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_212:
  free(pMem: v95);
  free(pMem: v82);
  free(pMem: v83);
  free(pMem: v84);
  return Code;
}

//------------------------------------------------------------------------------
// Address: 0x10214027
// Name: sub_10214027
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_10214027(unsigned int a1, unsigned int a2, int a3)
{
  int v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // eax

  v3 = *(_DWORD *)(a3 + 16);
  v4 = *(_DWORD *)(*(_DWORD *)(v3 + 4 * a1) + 8);
  v5 = *(_DWORD *)(*(_DWORD *)(v3 + 4 * a2) + 8);
  if ( v4 < v5 )
    return 1;
  if ( v4 > v5 )
    return -1;
  if ( a1 > a2 )
    return 1;
  return -(a1 < a2);
}

//------------------------------------------------------------------------------
// Address: 0x10214060
// Name: sub_10214060
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_10214060(int a1, int a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  unsigned int v5; // edi
  const char *v6; // ecx
  int v7; // eax
  const char *v8; // esi
  int v9; // ecx
  int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned int v16; // edx
  _DWORD *v17; // [esp+1Ch] [ebp+10h]

  v3 = *(_DWORD *)(a3 + 20);
  v4 = *(_DWORD **)(v3 + 4 * a1);
  v5 = v4[24];
  v6 = *(const char **)(v5 + 32);
  v17 = *(_DWORD **)(v3 + 4 * a2);
  v8 = (const char *)&pMem;
  if ( v6 == nullptr )
    v6 = (const char *)&pMem;
  v7 = v17[24];
  if ( *(_DWORD *)(v7 + 32) != 0 )
    v8 = *(const char **)(v7 + 32);
  v9 = strcmp(v6, v8);
  if ( v9 > 0 )
    return 1;
  if ( v9 < 0 )
    return -1;
  v11 = strcmp(*(const char **)(*(_DWORD *)(v5 + 20) + 24), *(const char **)(*(_DWORD *)(v17[24] + 20) + 24));
  if ( v11 > 0 )
    return 1;
  if ( v11 < 0 )
    return -1;
  v12 = v17[24];
  if ( v5 > v12 )
    return 1;
  if ( v5 < v12 )
    return -1;
  v13 = v4[29];
  v14 = v17[29];
  if ( v13 < v14 )
    return -1;
  if ( v13 > v14 )
    return 1;
  v15 = v4[4];
  v16 = v17[4];
  if ( v16 > v15 )
    return -1;
  return v16 < v15;
}

//------------------------------------------------------------------------------
// Address: 0x1021413D
// Name: protected: virtual unsigned long D3DXShader::CShaderProgram::MakeSemantic(unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CShaderProgram::MakeSemantic(
        D3DXShader::CShaderProgram *this,
        unsigned int a2,
        unsigned int a3)
{
  return a2 & *((_DWORD *)this + 57) | (a3 << *((_DWORD *)this + 59));
}

//------------------------------------------------------------------------------
// Address: 0x1021415E
// Name: protected: virtual unsigned long D3DXShader::CShaderProgram::SemanticType(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CShaderProgram::SemanticType(D3DXShader::CShaderProgram *this, unsigned int a2)
{
  return a2 & *((_DWORD *)this + 57);
}

//------------------------------------------------------------------------------
// Address: 0x10214170
// Name: protected: virtual unsigned long D3DXShader::CShaderProgram::SemanticIndex(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CShaderProgram::SemanticIndex(D3DXShader::CShaderProgram *this, unsigned int a2)
{
  return (a2 & *((_DWORD *)this + 58)) >> *((_DWORD *)this + 59);
}

//------------------------------------------------------------------------------
// Address: 0x1021418A
// Name: protected: long D3DXShader::CShaderProgram::ComputeSwizzle(class D3DXShader::CInstruction __near *,unsigned int __near *,unsigned int,unsigned int __near *,unsigned int __near *,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::ComputeSwizzle(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CInstruction *a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned int *a5,
        unsigned int *a6,
        unsigned int a7,
        int a8)
{
  struct D3DXShader::CInstruction *v8; // ebx
  unsigned int v9; // esi
  unsigned int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // esi
  unsigned int v14; // edx
  int v15; // edi
  _DWORD *v16; // ecx
  int v17; // eax
  int v18; // eax
  unsigned int *v19; // eax
  int k; // esi
  unsigned int v21; // ecx
  unsigned int v23; // esi
  int v24; // edi
  unsigned int i; // eax
  int v26; // edx
  int v27; // esi
  unsigned int v28; // eax
  int v29; // ecx
  _DWORD v30[4]; // [esp+Ch] [ebp-40h]
  _DWORD v31[4]; // [esp+1Ch] [ebp-30h] BYREF
  _DWORD *v32; // [esp+2Ch] [ebp-20h]
  int v33; // [esp+30h] [ebp-1Ch]
  int j; // [esp+34h] [ebp-18h]
  int v35; // [esp+38h] [ebp-14h]
  unsigned int v36; // [esp+3Ch] [ebp-10h]
  int v37; // [esp+40h] [ebp-Ch]
  int v38; // [esp+44h] [ebp-8h]
  unsigned int *v39; // [esp+48h] [ebp-4h]

  v8 = a2;
  v9 = *(_DWORD *)a2;
  memset(v31, 0, sizeof(v31));
  v32 = (_DWORD *)v9;
  if ( (v9 & 0xFFF00000) == 0x50000000 || (v9 & 0xFFF00000) == 0x70800000 )
  {
    v23 = v9 & 0xFFFFF;
    v24 = 0;
    for ( i = 0; i < 4; ++i )
    {
      if ( i >= v23 )
        a6[i] = 255;
      else
        a6[i] = i;
    }
    if ( a4 != 0 )
    {
      v26 = *((_DWORD *)this + 5);
      v27 = **((_DWORD **)a2 + 4);
      while ( 1 )
      {
        v28 = a3[v24];
        v29 = *(_DWORD *)(v26 + 4 * v28);
        if ( (v28 != v27 || *(_DWORD *)(v29 + 60) != a7)
          && (*(_DWORD *)(v29 + 56) != v27 || *(_DWORD *)(v29 + 60) != a7) )
        {
          break;
        }
        if ( ++v24 >= a4 )
          return 0;
      }
      return 1;
    }
  }
  else
  {
    v10 = 0;
    v36 = 0;
    if ( a4 != 0 )
    {
      v35 = *((_DWORD *)this + 5);
      v11 = (char *)a3 - (char *)a5;
      v39 = a5;
      v33 = (char *)a3 - (char *)a5;
      do
      {
        v12 = *(unsigned int *)((char *)v39 + v11);
        v37 = 0;
        v38 = *(_DWORD *)(v35 + 4 * v12);
        if ( a8 == 0 || (v10 = *v39, *v39 < 4) )
        {
          v13 = 0;
          if ( *((_DWORD *)v8 + 3) == 0 )
            return 1;
          v14 = v10;
          v15 = *((_DWORD *)v8 + 4) - (_DWORD)v31;
          for ( j = v15; ; v15 = j )
          {
            v16 = &v31[v13];
            if ( a3[v14] == *(_DWORD *)((char *)v16 + v15) && *(_DWORD *)(v38 + 60) == a7
              || (v17 = *((_DWORD *)v8 + 4), v8 = a2, *(_DWORD *)(v38 + 56) == *(_DWORD *)(v17 + 4 * v13))
              && *(_DWORD *)(v38 + 60) == a7 )
            {
              v37 = 1;
              v30[v14] = v13;
              *v16 = 1;
            }
            if ( (unsigned int)++v13 >= *((_DWORD *)v8 + 3) )
              break;
          }
          if ( v37 == 0 )
            return 1;
          v11 = v33;
          v9 = (unsigned int)v32;
        }
        ++v39;
        v10 = ++v36;
      }
      while ( v36 < a4 );
    }
    if ( a8 == 0 )
    {
      v18 = 0;
      if ( (v9 & 0xFFFFF) != 0 )
      {
        while ( v31[v18] != 0 )
        {
          if ( ++v18 >= (v9 & 0xFFFFF) )
            goto LABEL_23;
        }
        return 1;
      }
    }
LABEL_23:
    v19 = a6;
    for ( k = 4; k != 0; --k )
    {
      v21 = *(unsigned int *)((char *)v19 + (char *)a5 - (char *)a6);
      if ( v21 >= 4 )
        *v19 = 255;
      else
        *v19 = v30[v21];
      ++v19;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021433B
// Name: protected: long D3DXShader::CShaderProgram::MatchComplexTree(class D3DXShader::CInstruction __near *,struct D3DXShader::D3DX_MATCHENTRY const __near *,class D3DXShader::CInstruction __near * __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchComplexTree(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CInstruction *a2,
        const struct D3DXShader::D3DX_MATCHENTRY *a3,
        struct D3DXShader::CInstruction **a4,
        unsigned int *a5,
        unsigned int *a6,
        unsigned int *a7,
        unsigned int a8,
        int a9)
{
  int v9; // ecx
  unsigned int v10; // edx
  const struct D3DXShader::D3DX_MATCHENTRY *v12; // ebx
  bool v13; // zf
  int v14; // ecx
  unsigned int v15; // edx
  int v16; // ecx
  int v17; // edx
  unsigned int v18; // eax
  int v19; // ebx
  unsigned int v20; // ecx
  int v21; // eax
  char *v22; // edi
  int v23; // esi
  unsigned int v24; // edi
  unsigned int *v25; // ecx
  unsigned int v26; // esi
  const struct D3DXShader::D3DX_MATCHENTRY *v27; // edx
  unsigned int v28; // ecx
  unsigned int v29; // eax
  int v30; // edi
  struct D3DXShader::CInstruction *v31; // edx
  unsigned int v32; // ebx
  int v33; // esi
  _DWORD *v34; // ecx
  unsigned int v35; // eax
  int v36; // eax
  struct D3DXShader::CInstruction *v37; // ecx
  int v38; // edi
  int v39; // esi
  _DWORD *v40; // edx
  unsigned int v41; // eax
  unsigned int n; // edx
  unsigned int v43; // edi
  unsigned int v44; // ebx
  int v45; // eax
  struct D3DXShader::CInstruction *v46; // ecx
  int v47; // edx
  _DWORD *v48; // ecx
  unsigned int v49; // eax
  unsigned int i; // eax
  unsigned int v51; // ecx
  unsigned int v52[80]; // [esp+0h] [ebp-1C4h] BYREF
  unsigned int v53[4]; // [esp+140h] [ebp-84h] BYREF
  struct D3DXShader::CInstruction *v54[16]; // [esp+150h] [ebp-74h] BYREF
  unsigned int k; // [esp+190h] [ebp-34h]
  int m; // [esp+194h] [ebp-30h]
  unsigned int v57; // [esp+198h] [ebp-2Ch]
  int v58; // [esp+19Ch] [ebp-28h]
  unsigned int v59; // [esp+1A0h] [ebp-24h]
  unsigned int v60; // [esp+1A4h] [ebp-20h]
  unsigned int v61; // [esp+1A8h] [ebp-1Ch]
  struct D3DXShader::CInstruction **v62; // [esp+1ACh] [ebp-18h]
  D3DXShader::CShaderProgram *v63; // [esp+1B0h] [ebp-14h]
  unsigned int v64; // [esp+1B4h] [ebp-10h] BYREF
  int matched; // [esp+1B8h] [ebp-Ch]
  unsigned int j; // [esp+1BCh] [ebp-8h]
  unsigned int ii; // [esp+1C0h] [ebp-4h]

  v63 = this;
  v9 = *(_DWORD *)a2;
  v10 = *(_DWORD *)a2 & 0xFFFFF;
  matched = 0;
  v64 = 0;
  v61 = v10;
  if ( v10 > a8 && a9 == 0 )
    return 1;
  v12 = a3;
  if ( (v9 & 0xFFF00000) != *((_DWORD *)a3 + 1) )
    return 1;
  v13 = *(_DWORD *)a3 == 0;
  v57 = 1;
  if ( v13 && a9 != 0 )
    v57 = 2;
  v58 = 0;
  while ( 1 )
  {
    v14 = *((_DWORD *)v12 + 7) + 1;
    v60 = 0;
    if ( v14 != 0 )
      break;
LABEL_91:
    if ( matched == 0 )
    {
LABEL_95:
      v49 = v64;
      qmemcpy(a4, v54, 4 * v64);
      a4[v49] = a2;
      *a5 = v64 + 1;
      for ( i = 0; i < 40; ++i )
      {
        v51 = v52[i + 40];
        if ( v51 == -1 )
        {
          v51 = v52[i];
          if ( v51 == -1 )
            continue;
        }
        a6[i] = v51;
      }
      return 0;
    }
    if ( ++v58 >= v57 )
      return matched;
  }
  while ( 1 )
  {
    v15 = *a5;
    qmemcpy(v54, a4, 4 * *a5);
    memset(v52, 255, sizeof(v52));
    v13 = *((_DWORD *)v12 + 2) == 0;
    v64 = v15;
    matched = 0;
    j = 0;
    if ( !v13 )
      break;
LABEL_30:
    v27 = a3;
    v13 = *((_DWORD *)a3 + 2) == 0;
    j = 0;
    if ( !v13 )
    {
      v62 = nullptr;
      do
      {
        if ( v60 != 0 )
          v28 = 1 - j;
        else
          v28 = j;
        if ( *((_DWORD *)v27 + v28 + 3) >= 0x10u )
        {
          v29 = 0;
          v59 = 0;
          if ( v64 != 0 )
          {
            do
            {
              v30 = 0;
              if ( v61 != 0 )
              {
                v31 = v54[v29];
                v32 = *((_DWORD *)v31 + 3);
                while ( 1 )
                {
                  ii = 0;
                  if ( v32 != 0 )
                    break;
LABEL_43:
                  if ( ++v30 >= v61 )
                    goto LABEL_46;
                }
                v33 = *(_DWORD *)(*((_DWORD *)a2 + 2) + 4 * ((_DWORD)v62 + v30));
                v34 = *((_DWORD **)v31 + 4);
                while ( v33 != *v34 )
                {
                  ++ii;
                  ++v34;
                  if ( ii >= v32 )
                    goto LABEL_43;
                }
                matched = 1;
              }
LABEL_46:
              v29 = ++v59;
            }
            while ( v59 < v64 );
            v27 = a3;
          }
        }
        ++j;
        v62 = (struct D3DXShader::CInstruction **)((char *)v62 + v61);
      }
      while ( j < *((_DWORD *)v27 + 2) );
    }
    if ( matched == 0 )
    {
      if ( v58 != 0 || *(_DWORD *)a3 != 0 )
        goto LABEL_95;
      for ( j = 0; j < v64; ++j )
      {
        v35 = *((_DWORD *)v54[j] + 3);
        ii = 0;
        for ( k = v35; ii < k; ++ii )
        {
          v36 = *((_DWORD *)v63 + 3);
          if ( v36 != 0 )
          {
            v62 = *((struct D3DXShader::CInstruction ***)v63 + 6);
            for ( m = v36; m != 0; --m )
            {
              v37 = *v62;
              if ( *v62 != nullptr && *(_DWORD *)v37 != 0 )
              {
                v38 = *((_DWORD *)v37 + 1);
                v59 = 0;
                if ( v38 != 0 )
                {
                  v39 = *(_DWORD *)(*((_DWORD *)v54[j] + 4) + 4 * ii);
                  v40 = *((_DWORD **)v37 + 2);
                  do
                  {
                    if ( *v40 == v39 || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v63 + 5) + 4 * *v40) + 56) == v39 )
                      v59 = 1;
                    ++v40;
                    --v38;
                  }
                  while ( v38 != 0 );
                }
                if ( v37 == a2 )
                  v41 = 0;
                else
                  v41 = v59;
                if ( v41 != 0 )
                {
                  for ( n = 0; n < v64; ++n )
                  {
                    if ( v37 == v54[n] )
                      v41 = 0;
                  }
                  if ( v41 != 0 )
                    matched = 1;
                }
              }
              ++v62;
            }
          }
        }
      }
      for ( ii = 0; ii < 0x28; ++ii )
      {
        v43 = v52[ii + 40];
        if ( v43 != -1 )
        {
          v44 = 0;
          if ( v64 != 0 )
          {
            v45 = *(_DWORD *)(*((_DWORD *)v63 + 5) + 4 * v43);
            do
            {
              v46 = v54[v44];
              v47 = *((_DWORD *)v46 + 3);
              if ( v47 != 0 )
              {
                v48 = *((_DWORD **)v46 + 4);
                do
                {
                  if ( v43 == *v48 || *(_DWORD *)(v45 + 56) == *v48 )
                    matched = 1;
                  ++v48;
                  --v47;
                }
                while ( v47 != 0 );
              }
              ++v44;
            }
            while ( v44 < v64 );
          }
        }
      }
      if ( matched == 0 )
        goto LABEL_95;
    }
    ++v60;
    v12 = a3;
    if ( v60 >= *((_DWORD *)a3 + 7) + 1 )
      goto LABEL_91;
  }
  ii = 0;
  while ( 1 )
  {
    v16 = v60 != 0 ? 1 - j : j;
    if ( *a7 >= 4 )
      return 1;
    v17 = *((_DWORD *)a2 + 2);
    v18 = ii;
    v19 = *(_DWORD *)(*((_DWORD *)v63 + 5) + 4 * *(_DWORD *)(v17 + 4 * (ii + *a7)));
    v20 = *((_DWORD *)a3 + v16 + 3);
    if ( v20 >= 0x10 )
    {
      v24 = 0;
      v25 = &v52[4 * v20 - 24];
      do
      {
        v26 = a7[v24];
        if ( v26 >= v61 )
          *v25 = -1;
        else
          *v25 = *(_DWORD *)(v17 + 4 * (v18 + v26));
        ++v24;
        ++v25;
      }
      while ( v24 < 4 );
    }
    else
    {
      v21 = *(_DWORD *)(v19 + 72);
      if ( v21 == -1
        || (v22 = (char *)a3 + 32 * (v20 - *(_DWORD *)a3),
            v23 = *((_DWORD *)v63 + 6),
            D3DXShader::CShaderProgram::ComputeSwizzle(
              this: v63,
              a2: *(struct D3DXShader::CInstruction **)(v23 + 4 * v21),
              a3: (unsigned int *)(v17 + 4 * ii),
              a4: v61,
              a5: a7,
              a6: v53,
              a7: *((_DWORD *)v22 + 6),
              a8: a9) != 0) )
      {
        matched = 1;
        goto LABEL_30;
      }
      matched = D3DXShader::CShaderProgram::MatchComplexTree(
                  this: v63,
                  a2: *(struct D3DXShader::CInstruction **)(v23 + 4 * *(_DWORD *)(v19 + 72)),
                  a3: (const struct D3DXShader::D3DX_MATCHENTRY *)v22,
                  a4: v54,
                  a5: &v64,
                  a6: v52,
                  a7: v53,
                  a8,
                  a9);
    }
    if ( matched != 1 )
    {
      ++j;
      ii += v61;
      if ( j < *((_DWORD *)a3 + 2) )
        continue;
    }
    goto LABEL_30;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021479D
// Name: protected: long D3DXShader::CShaderProgram::SuppressAdditionalErrors(unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::SuppressAdditionalErrors(D3DXShader::CShaderProgram *this, unsigned int *a2)
{
  unsigned int v2; // eax
  _DWORD *v3; // edx
  int v4; // ecx
  _DWORD *v5; // edi
  int v6; // ebx
  int v7; // esi
  int v8; // edx
  unsigned int v10; // [esp+4h] [ebp-8h]
  int v11; // [esp+8h] [ebp-4h]

  v2 = *a2 + 1;
  v3 = (_DWORD *)(*((_DWORD *)this + 5) + 4 * v2);
  v11 = *v3;
  v10 = *((_DWORD *)this + 2);
  if ( v2 < v10 )
  {
    v4 = *((_DWORD *)this + 4);
    v5 = v3;
    do
    {
      v6 = *(_DWORD *)(*(_DWORD *)(v4 + 4 * *(_DWORD *)(*v5 + 4)) + 4);
      if ( ((v6 & 0x10) == 0 || (v6 & 0x200) != 0) && (v6 & 0x20) == 0 )
        break;
      v7 = *(_DWORD *)(v11 + 104);
      v8 = *(_DWORD *)(*v5 + 104);
      if ( *(_DWORD *)(v7 + 36) != *(_DWORD *)(v8 + 36) )
        break;
      if ( *(_DWORD *)(v7 + 32) != *(_DWORD *)(v8 + 32) )
        break;
      ++v2;
      ++v5;
    }
    while ( v2 < v10 );
  }
  *a2 = v2 - 1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10214812
// Name: protected: virtual long D3DXShader::CShaderProgram::ValidateArguments(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CShaderProgram::ValidateArguments(D3DXShader::CShaderProgram *this)
{
  char v2; // bl
  bool v3; // zf
  int v4; // ecx
  int v5; // eax
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  struct D3DXShader::CArgument **v11; // eax
  struct D3DXShader::CArgument *v12; // ebx
  unsigned int v13; // [esp+Ch] [ebp-210h]
  unsigned int v14; // [esp+10h] [ebp-20Ch] BYREF
  char v15; // [esp+17h] [ebp-205h]
  char v16[256]; // [esp+18h] [ebp-204h] BYREF
  char string[256]; // [esp+118h] [ebp-104h] BYREF

  v2 = 0;
  v3 = *((_DWORD *)this + 2) == 0;
  v15 = 0;
  v14 = 0;
  if ( !v3 )
  {
    do
    {
      v4 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v14);
      v5 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v4 + 4)) + 4);
      if ( ((v5 & 0x10) != 0 && (v5 & 0x200) == 0 || (v5 & 0x20) != 0)
        && (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, _DWORD))(*(_DWORD *)this + 4))(
             a1: this,
             a2: v4,
             a3: 0) < 0 )
      {
        D3DXShader::CShaderProgram::SuppressAdditionalErrors(this, a2: &v14);
        v15 = 1;
        v2 = 1;
      }
      ++v14;
    }
    while ( v14 < *((_DWORD *)this + 2) );
    if ( v2 != 0 )
      return -2147467259;
  }
  v3 = *((_DWORD *)this + 2) == 0;
  v14 = 0;
  if ( !v3 )
  {
    do
    {
      v7 = *((_DWORD *)this + 5);
      v8 = *(_DWORD *)(v7 + 4 * v14);
      v9 = *(_DWORD *)(v8 + 4);
      v10 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v9) + 4);
      if ( (v10 & 0x10) != 0 && (v10 & 0x200) == 0 || (v10 & 0x20) != 0 )
      {
        v13 = v14 + 1;
        if ( v14 + 1 < *((_DWORD *)this + 2) )
        {
          v11 = (struct D3DXShader::CArgument **)(v7 + 4 * v13);
          while ( 1 )
          {
            v12 = *v11;
            if ( *((_DWORD *)*v11 + 1) == v9
              && *((_DWORD *)v12 + 28) == *(_DWORD *)(v8 + 112)
              && *((_DWORD *)v12 + 27) == *(_DWORD *)(v8 + 108)
              && ((*(_DWORD *)v8 ^ *(_DWORD *)v12) & 0x1000000) != 0 )
            {
              break;
            }
            ++v13;
            ++v11;
            if ( v13 >= *((_DWORD *)this + 2) )
              goto LABEL_23;
          }
          D3DXShader::CBaseProgram::CreateArgumentErrorString(
            this,
            a2: (struct D3DXShader::CArgument *)v8,
            string,
            count: 0x100u);
          D3DXShader::CBaseProgram::CreateArgumentErrorString(this, a2: v12, string: v16, count: 0x100u);
          D3DXShader::CProgram::Error(
            this,
            a2: *(struct D3DXShader::CNode **)(v8 + 104),
            a3: 0x1195u,
            format: "Inconsistent semantic definition: %s and %s",
            string,
            v16);
          D3DXShader::CShaderProgram::SuppressAdditionalErrors(this, a2: &v14);
          v15 = 1;
LABEL_23:
          v2 = v15;
        }
      }
      ++v14;
    }
    while ( v14 < *((_DWORD *)this + 2) );
  }
  return v2 != 0 ? 0x80004005 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x102149D8
// Name: protected: long D3DXShader::CShaderProgram::ColorParents(class D3DXShader::CInstruction __near * __near *,class D3DXShader::CInstruction __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::ColorParents(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CInstruction **a2,
        struct D3DXShader::CInstruction *a3,
        unsigned int a4)
{
  unsigned int v4; // edi
  bool v5; // zf

  if ( *((_DWORD *)a3 + 9) != a4 )
  {
    v4 = 0;
    v5 = *((_DWORD *)a3 + 5) == 0;
    *((_DWORD *)a3 + 9) = a4;
    if ( !v5 )
    {
      do
        D3DXShader::CShaderProgram::ColorParents(this, a2, a3: a2[*(_DWORD *)(*((_DWORD *)a3 + 6) + 4 * v4++)], a4);
      while ( v4 < *((_DWORD *)a3 + 5) );
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10214A1E
// Name: protected: long D3DXShader::CShaderProgram::ColorParents2(class D3DXShader::CInstruction __near * __near *,class D3DXShader::CInstruction __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::ColorParents2(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CInstruction **a2,
        struct D3DXShader::CInstruction *a3,
        unsigned int a4)
{
  unsigned int v4; // edi
  bool v5; // zf

  if ( *((_DWORD *)a3 + 10) != a4 )
  {
    v4 = 0;
    v5 = *((_DWORD *)a3 + 5) == 0;
    *((_DWORD *)a3 + 10) = a4;
    if ( !v5 )
    {
      do
        D3DXShader::CShaderProgram::ColorParents2(this, a2, a3: a2[*(_DWORD *)(*((_DWORD *)a3 + 6) + 4 * v4++)], a4);
      while ( v4 < *((_DWORD *)a3 + 5) );
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10214A64
// Name: protected: long D3DXShader::CShaderProgram::ColorChildren2(class D3DXShader::CInstruction __near * __near *,class D3DXShader::CInstruction __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::ColorChildren2(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CInstruction **a2,
        struct D3DXShader::CInstruction *a3,
        unsigned int a4)
{
  unsigned int v4; // edi
  bool v5; // zf

  if ( *((_DWORD *)a3 + 10) != a4 )
  {
    v4 = 0;
    v5 = *((_DWORD *)a3 + 7) == 0;
    *((_DWORD *)a3 + 10) = a4;
    if ( !v5 )
    {
      do
        D3DXShader::CShaderProgram::ColorChildren2(this, a2, a3: a2[*(_DWORD *)(*((_DWORD *)a3 + 8) + 4 * v4++)], a4);
      while ( v4 < *((_DWORD *)a3 + 7) );
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10214AAA
// Name: protected: long D3DXShader::CShaderProgram::FindPoolName(char const __near *,char const __near * __near *,char,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::FindPoolName(
        D3DXShader::CShaderProgram *this,
        const char *a2,
        const char **a3,
        char a4,
        unsigned int a5)
{
  int i; // eax
  int v8; // edx
  int *v9; // eax
  int v10; // esi
  struct D3DXShader::CNode *v11; // eax

  *a3 = nullptr;
  while ( 1 )
  {
    LOBYTE(i) = *a2;
    if ( *a2 == 0 )
      return -2147467259;
    for ( i = (char)i; isalnum(c: i) == 0; i = *a2 )
      ++a2;
    if ( tolower(c: *a2) == a4 )
      break;
    while ( isalnum(c: *a2) != 0 )
      ++a2;
  }
  v8 = 0;
  if ( *a3 != nullptr )
  {
    if ( *((_DWORD *)this + 2) == 0 )
      goto LABEL_18;
    v9 = *((int **)this + 5);
    v10 = *((_DWORD *)this + 2);
    do
    {
      if ( *(_DWORD *)(*v9 + 4) == a5 )
        v8 = *v9;
      ++v9;
      --v10;
    }
    while ( v10 != 0 );
    if ( v8 != 0 )
      v11 = *(struct D3DXShader::CNode **)(v8 + 96);
    else
LABEL_18:
      v11 = nullptr;
    D3DXShader::CProgram::Error(
      this,
      a2: v11,
      a3: 0x119Du,
      format: "cannot bind the same variable to multiple constants in the same constant bank");
    return -2147467259;
  }
  *a3 = a2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10214B51
// Name: protected: long D3DXShader::CShaderProgram::CombineConstants(unsigned int,unsigned int,unsigned long,unsigned long,char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::CombineConstants(
        D3DXShader::CShaderProgram *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        char a6)
{
  unsigned int v6; // ebx
  bool v8; // zf
  _DWORD *v9; // eax
  int v10; // edx
  unsigned int v11; // edi
  int v12; // ecx
  unsigned int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  const char **v16; // edi
  unsigned int v17; // eax
  int PoolName; // ebx
  char *v19; // ebx
  char *i; // ebx
  char v21; // bl
  unsigned int v22; // eax
  unsigned int **v23; // ebx
  char *v24; // eax
  bool v25; // cf
  int v26; // eax
  int v27; // edx
  int j; // edi
  int v29; // ecx
  int (__stdcall *v30)(unsigned int, unsigned int, const void *); // eax
  unsigned int v31; // ecx
  int v32; // eax
  int v33; // edx
  unsigned int *v34; // edx
  char *v35; // edi
  int v36; // ecx
  unsigned int v37; // eax
  int v38; // edx
  int *v39; // eax
  struct D3DXShader::CNode *v40; // eax
  unsigned int k; // edx
  int v42; // edx
  unsigned int v43; // edi
  _DWORD *v44; // edx
  int v45; // ebx
  unsigned int m; // ecx
  int v47; // eax
  unsigned int n; // ecx
  int v49; // eax
  int v50; // edi
  int v51; // eax
  int v52; // eax
  void *v53; // edx
  int v54; // eax
  unsigned int v55; // ecx
  unsigned int **v56; // edi
  unsigned int ii; // edx
  int v58; // eax
  int v59; // ecx
  int v60; // ecx
  unsigned int *v62; // [esp-4h] [ebp-28h]
  const void *v63; // [esp+0h] [ebp-24h]
  void *v64; // [esp+Ch] [ebp-18h]
  char *v65; // [esp+10h] [ebp-14h] BYREF
  int (__stdcall *v66)(unsigned int, unsigned int, const void *); // [esp+14h] [ebp-10h]
  char *nptr; // [esp+18h] [ebp-Ch]
  void *pMem; // [esp+1Ch] [ebp-8h]
  unsigned int *v69; // [esp+20h] [ebp-4h]
  unsigned int v70; // [esp+30h] [ebp+Ch]

  v6 = 0;
  v8 = *((_DWORD *)this + 1) == 0;
  v66 = nullptr;
  v64 = nullptr;
  if ( !v8 )
  {
    do
    {
      v9 = *(_DWORD **)(*((_DWORD *)this + 4) + 4 * v6);
      v10 = v9[1];
      v9[4] = 0;
      if ( (v10 & 0x400) == 0 )
      {
        v11 = 0;
        for ( v9[2] = 0; v11 < *((_DWORD *)this + 2); ++v11 )
        {
          v12 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v11);
          if ( *(_DWORD *)(v12 + 4) == v6 )
          {
            v13 = *(_DWORD *)(v12 + 12) + 1;
            if ( v13 > v9[2] )
              v9[2] = v13;
          }
        }
        if ( (v10 & 0x100) != 0 && (v10 & 0x800) == 0 )
          v9[1] = v10 & 0xFFFFFFBF;
        v14 = v9[1];
        if ( (v14 & 0x10) != 0 && (v14 & 0xA00) == 0 )
          v9[1] = v14 & 0xFFFFFFBF;
        v15 = v9[1];
        if ( (v15 & 0x80u) != 0 && (v15 & 0x800) == 0 && v9[2] == 1 )
          v9[1] = v15 & 0xFFFFFFBF;
      }
      ++v6;
    }
    while ( v6 < *((_DWORD *)this + 1) );
  }
  pMem = MemAlloc_Alloc(nSize: 8 * a3);
  if ( pMem == nullptr )
    goto LABEL_131;
  v69 = nullptr;
  memset(pMem, 0, 8 * a3);
  if ( *((_DWORD *)this + 1) != 0 )
  {
    while ( 1 )
    {
      v16 = *(const char ***)(*((_DWORD *)this + 4) + 4 * (_DWORD)v69);
      v17 = (unsigned int)v16[1];
      if ( (a4 & v17) == a4 && (v17 & a5) == 0 && (v17 & 0x40) != 0 && (v17 & 0x800) != 0 && v16[2] != nullptr )
      {
        v62 = v69;
        v16[4] = (const char *)-1;
        PoolName = D3DXShader::CShaderProgram::FindPoolName(
                     this,
                     a2: *v16,
                     a3: (const char **)&v65,
                     a4: a6,
                     a5: (unsigned int)v62);
        if ( PoolName < 0 )
          goto LABEL_150;
        v19 = v65;
        if ( v65 != nullptr && a6 == tolower(c: *v65) )
        {
          nptr = v19 + 1;
          if ( isdigit(c: v19[1]) != 0 )
          {
            for ( i = v19 + 2; isdigit(c: *i) != 0; ++i )
              ;
            v21 = *i;
            if ( v21 == 0 || v21 == 59 )
              v16[4] = (const char *)atoi(nptr);
          }
        }
        if ( (unsigned int)v16[4] >= a3 )
        {
          v38 = 0;
          if ( *((_DWORD *)this + 2) == 0 )
            goto LABEL_72;
          v39 = *((int **)this + 5);
          v70 = *((_DWORD *)this + 2);
          do
          {
            if ( *(unsigned int **)(*v39 + 4) == v69 )
              v38 = *v39;
            ++v39;
            --v70;
          }
          while ( v70 != 0 );
          if ( v38 != 0 )
            v40 = *(struct D3DXShader::CNode **)(v38 + 96);
          else
LABEL_72:
            v40 = nullptr;
          D3DXShader::CProgram::Error(
            this,
            a2: v40,
            a3: 0x119Du,
            format: "invalid register semantic '%s', or variable must be bound to multiple register banks (%c register binding required)",
            *v16,
            a6);
          goto LABEL_142;
        }
        nptr = nullptr;
        if ( v16[2] != nullptr )
          break;
      }
LABEL_42:
      v69 = (unsigned int *)((char *)v69 + 1);
      if ( (unsigned int)v69 >= *((_DWORD *)this + 1) )
        goto LABEL_43;
    }
    while ( 1 )
    {
      v22 = (unsigned int)&v16[4][(_DWORD)nptr];
      if ( v22 >= a3 )
        break;
      v23 = (unsigned int **)((char *)pMem + 8 * v22);
      if ( *v23 != nullptr )
        D3DXShader::CProgram::Error(
          this,
          a2: nullptr,
          a3: 0x1194u,
          format: "overlapping register semantics not yet implemented '%c%u'",
          a6,
          &v16[4][(_DWORD)nptr]);
      *v23 = v69;
      v24 = nptr;
      v23[1] = (unsigned int *)nptr;
      v25 = ++v24 < v16[2];
      nptr = v24;
      if ( !v25 )
        goto LABEL_42;
    }
    if ( a6 == 98 )
      goto LABEL_139;
    if ( a6 == 99 )
      goto LABEL_135;
    if ( a6 != 105 )
    {
      if ( a6 == 115 )
      {
        D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x119Eu, format: "maximum sampler register index exceeded");
      }
      else if ( a6 == 118 )
      {
LABEL_133:
        D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x119Au, format: "maximum input register index exceeded");
      }
      goto LABEL_142;
    }
LABEL_130:
    D3DXShader::CProgram::Error(
      this,
      a2: nullptr,
      a3: 0x11C7u,
      format: "maximum iterator register index exceeded - Try reducing number of loops");
    goto LABEL_142;
  }
LABEL_43:
  v26 = *((_DWORD *)this + 1);
  v69 = nullptr;
  if ( v26 != 0 )
  {
    v27 = *((_DWORD *)this + 4);
    for ( j = v26; j != 0; --j )
    {
      v29 = *(_DWORD *)(*(_DWORD *)v27 + 4);
      if ( (a4 & v29) == a4
        && (v29 & a5) == 0
        && (v29 & 0x40) != 0
        && (v29 & 0x800) == 0
        && *(_DWORD *)(*(_DWORD *)v27 + 8) != 0 )
      {
        v69 = (unsigned int *)((char *)v69 + 1);
      }
      v27 += 4;
    }
  }
  v30 = (int (__stdcall *)(unsigned int, unsigned int, const void *))MemAlloc_Alloc(nSize: 4 * (_DWORD)v69);
  v31 = 0;
  v66 = v30;
  if ( v30 == nullptr )
  {
LABEL_131:
    PoolName = -2147024882;
    goto LABEL_150;
  }
  v8 = *((_DWORD *)this + 1) == 0;
  v69 = nullptr;
  if ( !v8 )
  {
    do
    {
      v32 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v31);
      v33 = *(_DWORD *)(v32 + 4);
      if ( (a4 & v33) == a4 && (v33 & a5) == 0 && (v33 & 0x40) != 0 && (v33 & 0x800) == 0 && *(_DWORD *)(v32 + 8) != 0 )
      {
        v34 = v69;
        v69 = (unsigned int *)((char *)v69 + 1);
        *((_DWORD *)v66 + (_DWORD)v34) = v31;
      }
      ++v31;
    }
    while ( v31 < *((_DWORD *)this + 1) );
  }
  v35 = (char *)v66;
  D3DXShader::HeapSort(this: (D3DXShader *)sub_10214027, a2: v66, a3: v69, a4: (unsigned int)this, a5: v63);
  v65 = nullptr;
  if ( v69 != nullptr )
  {
    nptr = v35;
    while ( 1 )
    {
      v36 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)nptr);
      v37 = 0;
      if ( a3 != 0 )
      {
        do
        {
          while ( v37 < a3 && *((_DWORD *)pMem + 2 * v37) != 0 )
            ++v37;
          for ( k = v37; k < a3; ++k )
          {
            if ( *((_DWORD *)pMem + 2 * k) != 0 )
              break;
          }
          if ( k - v37 >= *(_DWORD *)(v36 + 8) )
            break;
          v37 = k;
        }
        while ( k < a3 );
      }
      v42 = *(_DWORD *)(v36 + 8);
      if ( v42 + v37 > a3 )
        break;
      v43 = 0;
      if ( v42 != 0 )
      {
        v44 = (char *)pMem + 8 * v37;
        do
        {
          v45 = *(_DWORD *)nptr;
          v44[1] = v43;
          *v44 = v45;
          ++v43;
          v44 += 2;
        }
        while ( v43 < *(_DWORD *)(v36 + 8) );
      }
      ++v65;
      nptr += 4;
      *(_DWORD *)(v36 + 16) = v37;
      if ( v65 >= (char *)v69 )
        goto LABEL_94;
    }
    switch ( a6 )
    {
      case 'v':
        goto LABEL_133;
      case 'c':
        goto LABEL_135;
      case 's':
        goto LABEL_137;
      case 'b':
        goto LABEL_139;
      default:
        break;
    }
    if ( a6 != 105 )
      goto LABEL_142;
    goto LABEL_130;
  }
LABEL_94:
  for ( m = 0; m < *((_DWORD *)this + 2); ++m )
  {
    v47 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * m);
    *(_DWORD *)(v47 + 12) += *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v47 + 4)) + 16);
  }
  for ( n = 0; n < *((_DWORD *)this + 1); *(_DWORD *)(v49 + 16) = 0 )
  {
    v49 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * n);
    *(_DWORD *)(v49 + 8) += *(_DWORD *)(v49 + 16);
    ++n;
  }
  v8 = *((_DWORD *)this + 1) == 0;
  v69 = nullptr;
  if ( v8 )
  {
LABEL_117:
    if ( a2 != -1 )
    {
      for ( ii = 0; ii < *((_DWORD *)this + 2); ++ii )
      {
        v58 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * ii);
        v59 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v58 + 4)) + 4);
        if ( (a4 & v59) == a4 && (v59 & a5) == 0 )
        {
          if ( (v59 & 0x100) == 0 )
          {
            *(_DWORD *)(v58 + 4) = a2;
            continue;
          }
          if ( (v59 & 0x40000) != 0 )
          {
            v60 = *((_DWORD *)this + 97);
          }
          else
          {
            if ( (v59 & 0x800) != 0 )
              continue;
            v60 = *((_DWORD *)this + 30);
          }
          *(_DWORD *)(v58 + 4) = v60;
        }
      }
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * a2) + 16) = 0;
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * a2) + 8) = a3;
      if ( a2 == *((_DWORD *)this + 31) )
      {
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 30)) + 16) = 0;
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 30)) + 8) = a3;
      }
    }
    PoolName = 0;
    goto LABEL_150;
  }
  while ( 1 )
  {
    v50 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * (_DWORD)v69);
    v51 = *(_DWORD *)(v50 + 4);
    if ( (a4 & v51) == a4 )
    {
      if ( (v51 & a5) != 0 )
        goto LABEL_116;
      if ( (v51 & 0x40) != 0 )
        goto LABEL_116;
      if ( (v51 & 0x800) != 0 )
        goto LABEL_116;
      v52 = *(_DWORD *)(v50 + 8);
      if ( v52 == 0 )
        goto LABEL_116;
      v53 = MemAlloc_Alloc(nSize: 4 * v52);
      v64 = v53;
      if ( v53 == nullptr )
        goto LABEL_131;
      memset(v53, 0xFFu, 4 * *(_DWORD *)(v50 + 8));
      v8 = *((_DWORD *)this + 2) == 0;
      nptr = nullptr;
      if ( !v8 )
        break;
LABEL_115:
      free(pMem: v53);
      v64 = nullptr;
    }
LABEL_116:
    v69 = (unsigned int *)((char *)v69 + 1);
    if ( (unsigned int)v69 >= *((_DWORD *)this + 1) )
      goto LABEL_117;
  }
  while ( 1 )
  {
    v54 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * (_DWORD)nptr);
    if ( *(unsigned int **)(v54 + 4) == v69 )
    {
      if ( *((_DWORD *)v53 + *(_DWORD *)(v54 + 12)) == -1 )
      {
        v55 = 0;
        if ( a3 == 0 )
          break;
        do
        {
          if ( *((_DWORD *)pMem + 2 * v55) == 0 )
            break;
          ++v55;
        }
        while ( v55 < a3 );
        if ( v55 >= a3 )
          break;
        v56 = (unsigned int **)((char *)pMem + 8 * v55);
        *v56 = v69;
        v56[1] = *(unsigned int **)(v54 + 12);
        *((_DWORD *)v53 + *(_DWORD *)(v54 + 12)) = v55;
      }
      *(_DWORD *)(v54 + 12) = *((_DWORD *)v53 + *(_DWORD *)(v54 + 12));
    }
    if ( (unsigned int)++nptr >= *((_DWORD *)this + 2) )
      goto LABEL_115;
  }
  switch ( a6 )
  {
    case 'v':
      goto LABEL_133;
    case 'c':
LABEL_135:
      D3DXShader::CProgram::Error(
        this,
        a2: nullptr,
        a3: 0x119Bu,
        format: "maximum constant register index exceeded - Try reducing number of constants referenced");
      break;
    case 's':
LABEL_137:
      D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x11C2u, format: "maximum sampler register index exceeded");
      break;
    case 'b':
LABEL_139:
      D3DXShader::CProgram::Error(
        this,
        a2: nullptr,
        a3: 0x11C6u,
        format: "maximum boolean register index exceeded - Try reducing number of constant branches");
      break;
    case 'i':
      D3DXShader::CProgram::Error(
        this,
        a2: nullptr,
        a3: 0x11C7u,
        format: "maximum iterator register index exceeded - Try reducing number of loops and depth of loops");
      break;
    default:
      break;
  }
LABEL_142:
  PoolName = -2147467259;
LABEL_150:
  free(pMem);
  free(pMem: v66);
  free(pMem: v64);
  return PoolName;
}

//------------------------------------------------------------------------------
// Address: 0x102151D3
// Name: protected: long D3DXShader::CShaderProgram::Reset(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::Reset(D3DXShader::CShaderProgram *this)
{
  int result; // eax

  *((_DWORD *)this + 78) = -1;
  *((_DWORD *)this + 79) = -1;
  *((_DWORD *)this + 80) = -1;
  *((_DWORD *)this + 81) = -1;
  *((_DWORD *)this + 82) = -1;
  *((_DWORD *)this + 83) = 0;
  *((_DWORD *)this + 84) = 0;
  result = D3DXShader::CProgram::ReadWriteInfo(this);
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10215204
// Name: protected: virtual long D3DXShader::CShaderProgram::EmitInstructions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitInstructions(D3DXShader::CShaderProgram *this)
{
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x1021520A
// Name: protected: virtual int D3DXShader::CShaderProgram::ViolatesWriteLim(class D3DXShader::CInstruction __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::ViolatesWriteLim(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CInstruction *a2,
        unsigned int a3)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021520F
// Name: protected: long D3DXShader::CShaderProgram::IndexSemanticFromTable(class D3DXShader::CArgument __near *,struct D3DXShader::D3DX_SEMANTIC __near *,unsigned short,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CShaderProgram::IndexSemanticFromTable(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CArgument *a2,
        struct D3DXShader::D3DX_SEMANTIC *a3,
        unsigned __int16 a4,
        int *a5)
{
  struct D3DXShader::D3DX_SEMANTIC *v5; // ebx
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // eax
  const char *v8; // edi
  char v9; // al
  struct D3DXShader::D3DX_SEMANTIC *v10; // edi
  const char *v11; // ecx
  const char *ArgumentType; // [esp+Ch] [ebp-58h]
  int v14; // [esp+14h] [ebp-50h]
  int v16; // [esp+1Ch] [ebp-48h]
  unsigned int v17; // [esp+1Ch] [ebp-48h]
  unsigned __int8 dest[64]; // [esp+20h] [ebp-44h] BYREF

  v14 = 0;
  v5 = a3;
  *a5 = 0;
  *((_BYTE *)a2 + 3) &= ~0x40u;
  v6 = *(unsigned __int8 **)(*((_DWORD *)a2 + 26) + 24);
  strncpy(dest, source: v6, count: 0x3Fu);
  dest[63] = 0;
  v7 = dest;
  if ( dest[0] != 0 )
  {
    while ( *v7 != 95 )
    {
      if ( *++v7 == 0 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    if ( *v7 != 95 )
      goto LABEL_7;
  }
  *v7 = 0;
  if ( _stricmp(dst: (const char *)v7 + 1, src: "centroid") != 0 )
  {
    *a5 = 1;
    *((_DWORD *)a2 + 27) = 0;
    D3DXShader::CProgram::Error(
      this,
      a2: *((struct D3DXShader::CNode **)a2 + 26),
      a3: 0x1196u,
      format: "invalid input semantic '%s', only _centroid allowed",
      (const char *)v6);
    return *a5 != 0;
  }
  v14 = 1;
LABEL_7:
  v8 = (const char *)dest;
  if ( dest[0] == 0 )
    goto LABEL_13;
  do
  {
    if ( isalpha(c: *v8) == 0 )
      break;
    ++v8;
  }
  while ( *v8 != 0 );
  if ( *v8 != 0 )
    v16 = atoi(nptr: v8);
  else
LABEL_13:
    v16 = 0;
  if ( *v8 != 0 )
    *v8++ = 0;
  v9 = *v8;
  if ( *v8 == 0 )
    goto LABEL_21;
  do
  {
    if ( isdigit(c: v9) == 0 )
      break;
    v9 = *++v8;
  }
  while ( *v8 != 0 );
  if ( *v8 != 0 )
    v17 = -1;
  else
LABEL_21:
    v17 = (*((_DWORD *)a2 + 28) >> 2) + v16;
  v10 = nullptr;
  ArgumentType = D3DXShader::CBaseProgram::GetArgumentType(this, a2);
  if ( *((_DWORD *)a3 + 4) == -1 )
    goto LABEL_42;
  do
  {
    if ( _stricmp(dst: *(const char **)v5, src: (const char *)dest) == 0 )
    {
      v10 = v5;
      if ( (a4 & *((_WORD *)v5 + 2)) != 0 )
        break;
    }
    v5 = (struct D3DXShader::D3DX_SEMANTIC *)((char *)v5 + 36);
  }
  while ( *((_DWORD *)v5 + 4) != -1 );
  if ( v10 == nullptr || *((_DWORD *)v5 + 4) == -1 )
  {
LABEL_42:
    *((_BYTE *)a2 + 3) |= 0x40u;
    *((_DWORD *)a2 + 27) = 0;
  }
  else
  {
    if ( v14 != 0 && (*((_BYTE *)v10 + 8) & 1) == 0 )
      *(_DWORD *)a2 |= 0x40000000u;
    v11 = *((const char **)v10 + 3);
    if ( v11 != nullptr )
      D3DXShader::CProgram::Warning(
        this,
        a2: *((struct D3DXShader::CNode **)a2 + 26),
        a3: 0x1261u,
        format: "%s semantics '%s' has been deprecated; use '%s%d' instead",
        ArgumentType,
        (const char *)dest,
        v11,
        v17);
    if ( v17 < *((_DWORD *)v5 + 5) || v17 >= *((_DWORD *)v5 + 6) )
      *(_DWORD *)a2 |= 0x40000000u;
    if ( *((_DWORD *)a2 + 4) < *((_DWORD *)v5 + 8) )
    {
      if ( (a4 & *((_WORD *)v10 + 2)) == 0 )
        *(_DWORD *)a2 |= 0x40000000u;
      *((_DWORD *)a2 + 27) = (unsigned __int16)*((_DWORD *)v10 + 4) | ((v17 + *((_DWORD *)v10 + 7)) << 16);
      if ( v14 != 0 )
        *((_BYTE *)a2 + 3) |= 1u;
    }
    else
    {
      *(_DWORD *)a2 |= 0x40000000u;
      *a5 = 1;
      D3DXShader::CProgram::Error(
        this,
        a2: *((struct D3DXShader::CNode **)a2 + 26),
        a3: 0x11CBu,
        format: "invalid type used for '%s' %s semantics",
        (const char *)dest,
        ArgumentType);
    }
  }
  return *a5 != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10215450
// Name: protected: virtual long D3DXShader::CShaderProgram::PropCentroid(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::PropCentroid(D3DXShader::CShaderProgram *this)
{
  unsigned int v1; // ebx
  _DWORD *v2; // edx
  int v3; // esi
  _DWORD *v4; // eax
  int v5; // ebx
  unsigned int v6; // ebx
  _DWORD *v7; // esi
  int v8; // eax
  _DWORD *v9; // edx
  int v10; // esi
  int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  _DWORD *v15; // [esp+18h] [ebp-8h]
  unsigned int v16; // [esp+1Ch] [ebp-4h]

  do
  {
    v1 = 0;
    v12 = 0;
    v16 = 0;
    if ( *((_DWORD *)this + 3) == 0 )
      break;
    do
    {
      v2 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v16);
      v14 = 0;
      if ( v2[1] != 0 )
      {
        v3 = *((_DWORD *)this + 5);
        v15 = (_DWORD *)v2[2];
        v13 = v2[1];
        do
        {
          v4 = *(_DWORD **)(v3 + 4 * *v15);
          if ( (*v4 & 0x1000000) != 0 )
            v14 = 1;
          v5 = v4[14];
          if ( v5 != -1 )
            v4 = *(_DWORD **)(v3 + 4 * v5);
          if ( (*v4 & 0x1000000) != 0 )
            v14 = 1;
          ++v15;
          --v13;
        }
        while ( v13 != 0 );
        v6 = 0;
        if ( v14 != 0 && v2[3] != 0 )
        {
          do
          {
            v7 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v2[4] + 4 * v6));
            if ( (*v7 & 0x1000000) == 0 )
            {
              *v7 |= 0x1000000u;
              v12 = 1;
            }
            ++v6;
          }
          while ( v6 < v2[3] );
        }
      }
      ++v16;
    }
    while ( v16 < *((_DWORD *)this + 3) );
    v1 = 0;
  }
  while ( v12 != 0 );
  if ( *((_DWORD *)this + 2) != 0 )
  {
    do
    {
      v8 = *((_DWORD *)this + 5);
      v9 = *(_DWORD **)(v8 + 4 * v1);
      v10 = v9[14];
      if ( v10 != -1 && (**(_DWORD **)(v8 + 4 * v10) & 0x1000000) != 0 )
        *v9 |= 0x1000000u;
      ++v1;
    }
    while ( v1 < *((_DWORD *)this + 2) );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10215535
// Name: protected: long D3DXShader::CShaderProgram::MatchBREAK2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchBREAK2(D3DXShader::CShaderProgram *this)
{
  int v2; // eax
  unsigned __int8 *v4; // eax
  D3DXShader::CInstruction *v5; // edi
  D3DXShader::CInstruction *v6; // ecx
  unsigned int v7; // eax
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // esi
  unsigned int v12; // [esp+14h] [ebp-8h]
  int v13; // [esp+18h] [ebp-4h]

  v2 = **((_DWORD **)this + 64);
  if ( (v2 & 0xFFF00000) != 0x11400000 || (v2 & 0xFFFFF) != 1 )
    return 1;
  if ( (*((_BYTE *)this + 112) & 4) == 0 )
  {
    D3DXShader::CProgram::Error(
      this,
      a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
      a3: 0x11C8u,
      format: "cannot map general loop to this instruction set");
    return -2147467259;
  }
  v4 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v4 != nullptr )
    v5 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v4);
  else
    v5 = nullptr;
  if ( v5 == nullptr )
    return -2147024882;
  v13 = D3DXShader::CInstruction::Initialize(this: v5, a2: 0x74500001u, a3: 2u, a4: 1u, a5: 0);
  v6 = v5;
  if ( v13 < 0 )
    goto LABEL_14;
  v13 = D3DXShader::CInstruction::Instance(this: v5, a2: *((struct D3DXShader::CInstruction **)this + 64));
  if ( v13 < 0 || (v7 = D3DXShader::CBaseProgram::AddArgument(this, a2: 0, a3: 0, a4: 0, a5: 0.0), v12 = v7, v7 == -1) )
  {
    v6 = v5;
LABEL_14:
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v6, a2: 1);
    return v13;
  }
  v8 = *((_DWORD *)this + 5);
  v9 = *(_DWORD *)(v8 + 4 * v7);
  D3DXShader::CArgument::Initialize(
    this: (D3DXShader::CArgument *)v9,
    a2: *(struct D3DXShader::CArgument **)(v8 + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 8)));
  **((_DWORD **)v5 + 4) = **(_DWORD **)(*((_DWORD *)this + 64) + 16);
  **((_DWORD **)v5 + 2) = **(_DWORD **)(*((_DWORD *)this + 64) + 8);
  *(_DWORD *)(*((_DWORD *)v5 + 2) + 4) = v12;
  if ( *(_DWORD *)(v9 + 56) == -1 )
  {
    v10 = **(_DWORD **)(*((_DWORD *)this + 64) + 8);
    *(_BYTE *)(v9 + 62) |= 8u;
    *(_DWORD *)(v9 + 56) = v10;
  }
  else
  {
    *(_DWORD *)(v9 + 60) ^= 0x80000u;
  }
  v11 = D3DXShader::CInstruction::Initialize(this: *((D3DXShader::CInstruction **)this + 64), a2: v5);
  D3DXShader::CInstruction::`scalar deleting destructor'(this: v5, a2: 1);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x1021569D
// Name: protected: long D3DXShader::CShaderProgram::MatchENDWHILE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchENDWHILE(D3DXShader::CShaderProgram *this)
{
  unsigned int v2; // edi
  int v4; // eax
  _DWORD *v5; // ecx
  _DWORD *v6; // eax
  int v7; // edx
  _DWORD *v8; // ecx
  _DWORD *v9; // edx
  unsigned int v10; // eax
  int v11; // ebx
  int v12; // edi
  int v13; // [esp+8h] [ebp-18h]
  unsigned int v14; // [esp+8h] [ebp-18h]
  unsigned int v15; // [esp+Ch] [ebp-14h]
  unsigned int v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  _DWORD *v18; // [esp+18h] [ebp-8h]
  unsigned int v19; // [esp+18h] [ebp-8h]
  unsigned int v20; // [esp+1Ch] [ebp-4h]
  int v21; // [esp+1Ch] [ebp-4h]

  v2 = **((_DWORD **)this + 64) & 0xFFFFF;
  v15 = v2;
  if ( (**((_DWORD **)this + 64) & 0xFFF00000) != 0x20800000 )
    return 1;
  v13 = 0;
  v16 = 0;
  v17 = 0;
  while ( 1 )
  {
    v20 = 0;
    if ( v2 != 0 )
    {
      v4 = *((_DWORD *)this + 64);
      v5 = *(_DWORD **)(v4 + 16);
      v6 = (_DWORD *)(v17 + *(_DWORD *)(v4 + 8));
      v18 = v5;
      do
      {
        v7 = *((_DWORD *)this + 5);
        v8 = *(_DWORD **)(v7 + 4 * *v18);
        v9 = *(_DWORD **)(v7 + 4 * *v6);
        if ( v9[1] != v8[1] )
          break;
        if ( v9[2] != v8[2] )
          break;
        if ( v9[3] != v8[3] )
          break;
        if ( v9[4] != v8[4] )
          break;
        ++v20;
        ++v18;
        ++v6;
      }
      while ( v20 < v2 );
    }
    if ( v20 == v2 )
      goto LABEL_23;
    v10 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v2 & 0xFFFFF | 0x10000000, a3: v2, a4: v2);
    v14 = v10;
    if ( v10 == -1 )
      return -2147024882;
    v19 = 0;
    v11 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v10);
    if ( v2 != 0 )
      break;
LABEL_18:
    while ( v10 > *((_DWORD *)this + 63)
         || v10 != 0 && (**(_DWORD **)(*((_DWORD *)this + 6) + 4 * v10 - 4) & 0xFFF00000) == 0x20800000 )
    {
      *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v10) = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v10 - 4);
      --v10;
    }
    *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v10) = v11;
    ++*((_DWORD *)this + 63);
    v13 = 1;
LABEL_23:
    ++v16;
    v17 += 4 * v2;
    if ( v16 >= 2 )
      return v13 == 0;
  }
  v21 = v17;
  while ( 1 )
  {
    v12 = 4 * v19;
    *(_DWORD *)(4 * v19 + *(_DWORD *)(v11 + 8)) = *(_DWORD *)(v21 + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
    *(_DWORD *)(v21 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)) = D3DXShader::CBaseProgram::CopyArgument(
                                                                   this,
                                                                   a2: *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(4 * v19 + *(_DWORD *)(*((_DWORD *)this + 64) + 16))));
    *(_DWORD *)(4 * v19 + *(_DWORD *)(v11 + 16)) = *(_DWORD *)(v21 + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
    if ( *(_DWORD *)(4 * v19 + *(_DWORD *)(v11 + 16)) == -1 )
      return -2147024882;
    ++v19;
    v21 += 4;
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v12 + *(_DWORD *)(v11 + 16))) + 20) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v12 + *(_DWORD *)(v11 + 8))) + 20);
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v12 + *(_DWORD *)(v11 + 16))) + 24) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v12 + *(_DWORD *)(v11 + 8))) + 24);
    if ( v19 >= v15 )
    {
      v10 = v14;
      v2 = v15;
      goto LABEL_18;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10215896
// Name: protected: long D3DXShader::CShaderProgram::MatchSINCOS(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchSINCOS(D3DXShader::CShaderProgram *this)
{
  _DWORD *v2; // ecx
  int v3; // eax
  int v4; // edx
  int v5; // edi
  unsigned int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  unsigned int v9; // ebx
  int v10; // edi
  unsigned int v11; // eax
  unsigned int *v12; // ecx
  D3DXShader::CInstruction *v13; // [esp+14h] [ebp-Ch]
  unsigned int v14; // [esp+18h] [ebp-8h]
  unsigned int v15; // [esp+1Ch] [ebp-4h]

  v2 = *(_DWORD **)(*((_DWORD *)this + 64) + 16);
  v3 = *((_DWORD *)this + 5);
  v4 = *(_DWORD *)(v3 + 4 * *v2);
  if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v4 + 4)) + 4) & 1) == 0
    || *(_DWORD *)(v4 + 60) != 0
    || *(_DWORD *)(*(_DWORD *)(v3 + 4 * v2[1]) + 60) != 0 )
  {
    v14 = 0;
    if ( *((_DWORD *)this + 2) != 0 )
    {
      v5 = *((_DWORD *)this + 2);
      do
      {
        if ( *((_DWORD *)this + 34) == *(_DWORD *)(*(_DWORD *)v3 + 4) )
        {
          v6 = *(_DWORD *)(*(_DWORD *)v3 + 12);
          if ( v6 >= v14 )
            v14 = v6 + 1;
        }
        v3 += 4;
        --v5;
      }
      while ( v5 != 0 );
    }
    v7 = D3DXShader::CBaseProgram::AddInstruction(this, a2: 0x10000004u, a3: 4u, a4: 4u);
    if ( v7 != -1 )
    {
      v13 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v7);
      result = D3DXShader::CInstruction::Instance(this: v13, a2: *((struct D3DXShader::CInstruction **)this + 64));
      if ( result < 0 )
        return result;
      v15 = 0;
      while ( 1 )
      {
        v9 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: v14, a4: v15, a5: 0.0);
        if ( v9 == -1 )
          break;
        v10 = 4 * v15;
        result = D3DXShader::CArgument::Instance(
                   this: *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v9),
                   a2: *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5)
                                                    + 4
                                                    * *(_DWORD *)(4 * v15 + *(_DWORD *)(*((_DWORD *)this + 64) + 16))));
        if ( result < 0 )
          return result;
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v9) + 24) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                                                              + 4
                                                                                              * *(_DWORD *)(v10 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)))
                                                                                  + 24);
        ++v15;
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v9) + 20) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                                                              + 4
                                                                                              * *(_DWORD *)(v10 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)))
                                                                                  + 20);
        *(_DWORD *)(v10 + *((_DWORD *)v13 + 4)) = *(_DWORD *)(v10 + *(_DWORD *)(*((_DWORD *)this + 64) + 16));
        *(_DWORD *)(v10 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)) = v9;
        *(_DWORD *)(v10 + *((_DWORD *)v13 + 2)) = v9;
        if ( v15 >= 4 )
        {
          v11 = *((_DWORD *)this + 3) - 2;
          v12 = (unsigned int *)((char *)this + 252);
          while ( v11 > *v12 )
          {
            *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v11 + 4) = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v11);
            --v11;
          }
          *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *v12 + 4) = v13;
          goto LABEL_21;
        }
      }
    }
    return -2147024882;
  }
  else
  {
LABEL_21:
    *((_DWORD *)this + 99) = 1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10215A36
// Name: void D3DXShader::ExchangeRow(class D3DXShader::CInstruction __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall D3DXShader::ExchangeRow(D3DXShader *this, struct D3DXShader::CInstruction *a2, unsigned int a3)
{
  unsigned int v4; // esi
  int v6; // edx
  int *v7; // eax
  int v8; // esi
  int *v9; // eax
  int v10; // esi
  int thisa; // [esp+10h] [ebp+8h]
  struct D3DXShader::CInstruction *v12; // [esp+14h] [ebp+Ch]

  v4 = *(_DWORD *)this & 0xFFFFF;
  if ( *((_DWORD *)this + 1) / v4 != 0 )
  {
    v12 = (struct D3DXShader::CInstruction *)(4 * v4);
    v6 = 4 * (_DWORD)a2;
    thisa = *((_DWORD *)this + 1) / v4;
    do
    {
      v7 = (int *)(v6 + *((_DWORD *)this + 2));
      v8 = *v7;
      *v7 = v7[1];
      *(_DWORD *)(*((_DWORD *)this + 2) + v6 + 4) = v8;
      v6 += (int)v12;
      --thisa;
    }
    while ( thisa != 0 );
  }
  v9 = (int *)(4 * (_DWORD)a2 + *((_DWORD *)this + 4));
  v10 = *v9;
  *v9 = v9[1];
  *(_DWORD *)(*((_DWORD *)this + 4) + 4 * (_DWORD)a2 + 4) = v10;
}

//------------------------------------------------------------------------------
// Address: 0x10215AA1
// Name: protected: long D3DXShader::CShaderProgram::SortInstruction(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall D3DXShader::CShaderProgram::SortInstruction@<eax>(
        D3DXShader::CShaderProgram *this@<ecx>,
        unsigned int a2@<ebx>)
{
  _DWORD *v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // ebx
  _DWORD *v6; // eax
  unsigned int v8; // [esp-4h] [ebp-14h]
  unsigned int v9; // [esp+Ch] [ebp-4h]

  v3 = *((_DWORD **)this + 64);
  v4 = *v3 & 0xFFFFF;
  if ( v4 != v3[3]
    || D3DXShader::CInstruction::IsSpecial(this: *((D3DXShader::CInstruction **)this + 64)) != 0
    || D3DXShader::CInstruction::IsFlowControl(this: *((D3DXShader::CInstruction **)this + 64)) != 0
    && D3DXShader::CInstruction::IsCopy(this: *((D3DXShader::CInstruction **)this + 64)) == 0
    || v4 > 4
    || v4 == 0 )
  {
    return 1;
  }
  v9 = 0;
  v8 = a2;
  do
  {
    v5 = 0;
    if ( v4 - v9 != 1 )
    {
      do
      {
        v6 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 16) + 4 * v5);
        if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v6) + 16) > *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v6[1])
                                                                                        + 16) )
          D3DXShader::ExchangeRow(this: *((D3DXShader **)this + 64), a2: (struct D3DXShader::CInstruction *)v5, a3: v8);
        ++v5;
      }
      while ( v5 < v4 - v9 - 1 );
    }
    ++v9;
  }
  while ( v9 < v4 );
  return 0;
}
