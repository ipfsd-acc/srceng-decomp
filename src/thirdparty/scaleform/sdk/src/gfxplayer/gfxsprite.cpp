// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxsprite.cpp
// Functions: 226
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxsprite.h"

//------------------------------------------------------------------------------
// Address: 0x10068740
// Name: public: GFxCharPosInfo::GFxCharPosInfo(class GFxResourceId,int,bool,class GRenderer::Cxform const __near &,bool,class GMatrix2D const __near &,float,unsigned short,bool,enum GRenderer::BlendType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharPosInfo::GFxCharPosInfo(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CFuncMemPolicyNone> *this,
        CMatRenderContextBase *chId,
        __int128 depth,
        int a4,
        float ratio,
        unsigned __int16 clipDepth,
        bool hasBlendMode,
        char blend)
{
  *(_QWORD *)&this->m_pfnProxied = 0;
  DWORD2(this->m_pfnProxied) = 0;
  qmemcpy((char *)&this->m_pfnProxied + 12, (const void *)DWORD2(depth), 0x20u);
  *((float *)this + 11) = *(float *)a4;
  *(this + 2) = *(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CFuncMemPolicyNone> *)(a4 + 4);
  *((_DWORD *)this + 19) = chId;
  *((_BYTE *)this + 83) = 0;
  *((float *)this + 17) = ratio;
  if ( BYTE12(depth) != 0 )
    *((_BYTE *)this + 83) |= 4u;
  if ( BYTE4(depth) != 0 )
    *((_BYTE *)this + 83) |= 8u;
  if ( hasBlendMode )
    *((_BYTE *)this + 83) |= 0x80u;
  *((_DWORD *)this + 18) = depth;
  *((_DWORD *)this + 19) = chId;
  *((_WORD *)this + 40) = clipDepth;
  *((_BYTE *)this + 82) = blend;
}

//------------------------------------------------------------------------------
// Address: 0x100AD470
// Name: public: bool GASString::operator==(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASString::operator==(const char ***this, const char *a2)
{
  return strcmp(**this, a2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AD4C0
// Name: protected: void GFxASCharacter::SetHitTestDisableFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetHitTestDisableFlag(
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v)
{
  if ( (_BYTE)v != 0 )
    *((_DWORD *)this + 40) |= 0x800u;
  else
    *((_DWORD *)this + 40) &= ~0x800u;
}

//------------------------------------------------------------------------------
// Address: 0x100AD4F0
// Name: private: void GFxSprite::SetLockRoot(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetLockRoot(GFxSprite *this, bool v)
{
  char v2; // al

  v2 = *((_BYTE *)this + 480);
  if ( v )
    *((_BYTE *)this + 480) = v2 | 0x20;
  else
    *((_BYTE *)this + 480) = v2 & 0xDF;
}

//------------------------------------------------------------------------------
// Address: 0x100AD520
// Name: private: static int GFxTimelineSnapshot::DepthLess(int,struct GFxTimelineSnapshot::SnapshotElement const __near *)
// Source: json
//------------------------------------------------------------------------------
static BOOL __cdecl GFxTimelineSnapshot::DepthLess(int a1, const struct GFxTimelineSnapshot::SnapshotElement *a2)
{
  return a1 < *((_DWORD *)a2 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x100AD540
// Name: public: void GFxSprite::SetRootNodeLoadingStat(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const GFxTestStream *__thiscall GFxSprite::SetRootNodeLoadingStat(
        _DWORD *this,
        const GFxTestStream *result,
        unsigned int loadingFrame)
{
  const GFxTestStream *v3; // eax

  if ( *(this + 112) != 0 )
  {
    *(_DWORD *)(*(this + 112) + 20) = result;
    v3 = (const GFxTestStream *)*(this + 112);
    v3[1].__vftable = LOBYTE(v3[1].SType) != 0 ? nullptr : (GFxTestStream_vtbl *)loadingFrame;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100AD590
// Name: public: virtual class GFxASCharacter __near * GFxSprite::GetLevelMovie(int)const
// Source: json
//------------------------------------------------------------------------------
struct GFxSprite *__userpurge GFxSprite::GetLevelMovie@<eax>(
        GFxTestStream *this@<ecx>,
        const char *level,
        const char *a3)
{
  return GFxMovieRoot::GetLevelMovie(this: *((GFxMovieRoot **)this + 47), (int)level);
}

//------------------------------------------------------------------------------
// Address: 0x100AD5A0
// Name: public: virtual class GFxASCharacter __near * GFxSprite::GetASRootMovie(bool)const
// Source: json
//------------------------------------------------------------------------------
struct GFxASCharacter *__thiscall GFxSprite::GetASRootMovie(GFxSprite *this, int a2)
{
  struct GFxASCharacter *result; // eax
  int v3; // ecx
  char v4; // dl

  result = (struct GFxASCharacter *)this;
  v3 = (int)*(this + 8);
  if ( v3 != 0 && ((_BYTE)a2 != 0 || ((v4 = *((_BYTE *)result + 480)) & 0x10) == 0 || (v4 & 0x20) == 0) )
  {
    if ( (*((_BYTE *)result + 118) & 0x10) != 0 )
      return GFxMovieRoot::GetLevelMovie(this: *((GFxMovieRoot **)result + 47), level: 0);
    else
      return (*(struct GFxASCharacter *(__thiscall **)(int, int))(*(_DWORD *)v3 + 104))(a1: v3, a2);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AD5F0
// Name: public: unsigned long GFxSprite::GetBytesLoaded(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSprite::GetBytesLoaded(GPtr<GFxZlibSupportBase> *this)
{
  GPtr<GFxZlibSupportBase> *pObject; // esi
  _TAPE_WMI_OPERATIONS *v2; // eax
  _TAPE_WMI_OPERATIONS *v4; // [esp+0h] [ebp-4h]

  pObject = this;
  if ( this == nullptr )
    return 0;
  while ( 1 )
  {
    v2 = GASObjectInterface::ToSprite(result: v4);
    if ( v2 != nullptr && v2[37].DataBufferSize != 0 )
      break;
    pObject = (GPtr<GFxZlibSupportBase> *)pObject[8].pObject;
    if ( pObject == nullptr )
      return 0;
  }
  return *(_DWORD *)(v2[37].DataBufferSize + 20);
}

//------------------------------------------------------------------------------
// Address: 0x100AD630
// Name: public: int GFxSprite::GetSoundVolume(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSprite::GetSoundVolume(GPtr<GFxZlibSupportBase> *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 114);
  if ( v1 != 0 )
    return *(_DWORD *)v1;
  else
    return 100;
}

//------------------------------------------------------------------------------
// Address: 0x100AD650
// Name: public: float GFxSprite::GetRealSoundVolume(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall GFxSprite::GetRealSoundVolume@<st0>(GFxValue *this@<ecx>, _TAPE_WMI_OPERATIONS *a2@<esi>)
{
  int *v2; // eax
  int v3; // edi
  int *Method; // eax
  _TAPE_WMI_OPERATIONS *v6; // [esp-8h] [ebp-10h]
  int v7; // [esp+0h] [ebp-8h]
  int va; // [esp+4h] [ebp-4h]
  float vb; // [esp+4h] [ebp-4h]

  v2 = *((int **)this + 114);
  if ( v2 != nullptr )
    va = *v2;
  else
    va = 100;
  v3 = *((_DWORD *)this + 8);
  vb = (double)va / 100.0;
  if ( v3 != 0 )
  {
    v6 = a2;
    do
    {
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)(v3 + 120) + 8))(a1: v3 + 120) == 2 )
      {
        Method = (int *)GASObjectInterface::ToSprite(result: v6)[38].Method;
        if ( Method != nullptr )
          v7 = *Method;
        else
          v7 = 100;
        vb = (double)v7 / 100.0 * vb;
      }
      v3 = *(_DWORD *)(v3 + 32);
    }
    while ( v3 != 0 );
  }
  return vb;
}

//------------------------------------------------------------------------------
// Address: 0x100AD6E0
// Name: public: int GFxSprite::GetSoundPan(void)
// Source: json
//------------------------------------------------------------------------------
GPtr<GFxZlibSupportBase> *__thiscall GFxSprite::GetSoundPan(GPtr<GFxZlibSupportBase> *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 114);
  if ( v1 != 0 )
    return *(GPtr<GFxZlibSupportBase> **)(v1 + 8);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100AD700
// Name: public: float GFxSprite::GetRealSoundPan(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall GFxSprite::GetRealSoundPan@<st0>(GFxValue *this@<ecx>, _TAPE_WMI_OPERATIONS *a2@<esi>)
{
  int v2; // eax
  int v3; // edi
  unsigned int Method; // eax
  _TAPE_WMI_OPERATIONS *v6; // [esp-8h] [ebp-10h]
  int v7; // [esp+0h] [ebp-8h]
  int va; // [esp+4h] [ebp-4h]
  float vb; // [esp+4h] [ebp-4h]

  v2 = *((_DWORD *)this + 114);
  if ( v2 != 0 )
    va = *(_DWORD *)(v2 + 8);
  else
    va = 0;
  v3 = *((_DWORD *)this + 8);
  vb = (double)va / 100.0;
  if ( v3 != 0 )
  {
    v6 = a2;
    do
    {
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)(v3 + 120) + 8))(a1: v3 + 120) == 2 )
      {
        Method = GASObjectInterface::ToSprite(result: v6)[38].Method;
        if ( Method != 0 )
          v7 = *(_DWORD *)(Method + 8);
        else
          v7 = 0;
        vb = (double)v7 / 100.0 * vb;
      }
      v3 = *(_DWORD *)(v3 + 32);
    }
    while ( v3 != 0 );
  }
  return vb;
}

//------------------------------------------------------------------------------
// Address: 0x100AD790
// Name: _GFx_InitObjectMembers_::_2_::InitVisitor::Visit
// Source: rtti_class
//------------------------------------------------------------------------------
int __thiscall GFx_InitObjectMembers_::_2_::InitVisitor::Visit(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // ecx
  char v7; // [esp+7h] [ebp-1h] BYREF

  v4 = *(this + 1);
  v5 = *(this + 2) + 120;
  v7 = 0;
  return (*(int (__thiscall **)(int, int, int, int, char *))(*(_DWORD *)v5 + 12))(
           a1: v5,
           a2: v4,
           a3: a2,
           a4: a3,
           a5: &v7);
}

//------------------------------------------------------------------------------
// Address: 0x100AD7D0
// Name: public: virtual class GFxASCharacter __near * GFxSprite::GetRelativeTarget(class GASString const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::GetRelativeTarget(GMemoryFile *this, _IMAGE_SYMBOL_EX *name, _BYTE *first_call)
{
  const void *Version; // eax
  unsigned int Short; // ecx
  bool v6; // al
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  int v9; // edx
  int v10; // eax
  char *v11; // [esp-Ch] [ebp-1Ch]
  bool caseSensitive; // [esp+Ch] [ebp-4h]

  Version = GFxCharacter::GetVersion((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)this);
  Short = name->N.Name.Short;
  v6 = (unsigned int)Version > 6;
  caseSensitive = v6;
  if ( *(int *)(name->N.Name.Short + 12) >= 0 )
  {
LABEL_18:
    if ( **(_BYTE **)Short != 95
      || (_BYTE)first_call == 0
      || (v11 = *(char **)Short,
          first_call = nullptr,
          (v10 = GFxMovieRoot::ParseLevelName(
                   nptr: v11,
                   ptail: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&first_call,
                   caseSensitive)) == -1)
      || *first_call != 0 )
    {
      GFxDisplayList::GetCharacterByName(
        this: (CMemberFuncProxy0<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *)(this + 7),
        psc: (unsigned int)this + 352);
    }
    else
    {
      GFxMovieRoot::GetLevelMovie(this: *((GFxMovieRoot **)this + 47), level: v10);
    }
    return;
  }
  if ( v6 )
  {
    v7 = *((_DWORD **)this + 88);
    if ( v7[51] == Short || v7[63] == Short || v7[52] == Short || v7[67] == Short )
      return;
    if ( v7[66] == Short )
    {
LABEL_8:
      ((void (__thiscall *)(GMemoryFile *, _DWORD))this->__vftable[1].LGetLength)(a1: this, a2: 0);
      return;
    }
    goto LABEL_18;
  }
  if ( *(_DWORD *)(Short + 4) == 0 )
    GASStringNode::ResolveLowercase_Impl();
  v8 = *((_DWORD **)this + 88);
  Short = name->N.Name.Short;
  if ( v8[51] != name->N.Name.Short )
  {
    v9 = *(_DWORD *)(Short + 4);
    if ( *(_DWORD *)(v8[63] + 4) != v9 && v8[52] != Short && *(_DWORD *)(v8[67] + 4) != v9 )
    {
      if ( *(_DWORD *)(v8[66] + 4) == v9 )
        goto LABEL_8;
      goto LABEL_18;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD920
// Name: public: virtual bool GFxSprite::OnButtonEvent(class GFxEventId const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::OnButtonEvent(GMemoryFile *this, unsigned int id)
{
  int v4; // ecx

  if ( (*((_DWORD *)this + 40) & 0x10) == 0 || *((int *)this + 111) >= 0 )
    return 0;
  if ( ((unsigned __int8 (__thiscall *)(GMemoryFile *, unsigned int))this->__vftable[1].Flush)(a1: this, a2: id) != 0 )
    return 0;
  v4 = *((_DWORD *)this + 8);
  if ( v4 == 0 )
    return 0;
  return (*(int (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 264))(a1: v4, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x100AD980
// Name: public: virtual void GFxSprite::DetachChild(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::DetachChild(GFxSprite *this, struct GFxASCharacter *a2)
{
  GFxDisplayList::RemoveCharacter(this: (IMaterial *)this + 49, (__vc_attributes::pointer_defaultAttribute)a2);
}

//------------------------------------------------------------------------------
// Address: 0x100AD990
// Name: public: virtual bool GFxSprite::ExecuteBuffer(class GASActionBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::ExecuteBuffer(_BYTE *this, GASActionBuffer *result)
{
  tagPOLYTEXTW *v2; // eax

  if ( (*(this + 118) & 0x10) != 0 )
    return 0;
  v2 = (tagPOLYTEXTW *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 112))(a1: this);
  GASActionBuffer::Execute(this: result, a2: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AD9C0
// Name: public: virtual void GFxSprite::OnEventXmlsocketOnxml(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxSprite::OnEventXmlsocketOnxml(GFxFontLib *this)
{
  void (__thiscall *dtr_GRefCountImplCore)(struct GFxFontLib *); // eax
  _DWORD v3[2]; // [esp+0h] [ebp-10h] BYREF
  __int16 v4; // [esp+8h] [ebp-8h]
  int v5; // [esp+Ah] [ebp-6h]

  v3[1] = 0;
  dtr_GRefCountImplCore = this->__vftable[16].dtr_GRefCountImplCore;
  v4 = 0;
  v3[0] = 16777223;
  v5 = 65280;
  return ((void *(__thiscall *)(GFxFontLib *, _DWORD *))dtr_GRefCountImplCore)(a1: this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100ADA00
// Name: public: virtual void GFxSprite::OnEventLoadProgress(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxSprite::OnEventLoadProgress(GFxFontLib *this)
{
  void (__thiscall *dtr_GRefCountImplCore)(struct GFxFontLib *); // eax
  _DWORD v3[2]; // [esp+0h] [ebp-10h] BYREF
  __int16 v4; // [esp+8h] [ebp-8h]
  int v5; // [esp+Ah] [ebp-6h]

  v3[1] = 0;
  dtr_GRefCountImplCore = this->__vftable[16].dtr_GRefCountImplCore;
  v4 = 0;
  v3[0] = 16777218;
  v5 = 65280;
  return ((void *(__thiscall *)(GFxFontLib *, _DWORD *))dtr_GRefCountImplCore)(a1: this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100ADA40
// Name: public: virtual void GFxSprite::VisitMembers(class GASStringContext __near *,struct GASObjectInterface::MemberVisitor __near *,unsigned int,class GASObjectInterface const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::VisitMembers(
        GMemoryFile *this,
        struct GASStringContext *psc,
        struct GASObjectInterface::MemberVisitor *pvisitor,
        unsigned int visitFlags,
        int a5)
{
  if ( (visitFlags & 2) != 0 )
    GFxDisplayList::VisitMembers(this: (GFxDisplayList *)((char *)this + 76), visitFlags: pvisitor, a3: visitFlags);
  GFxASCharacter::VisitMembers(
    (GFxASCharacter *)this,
    pvisitor: psc,
    pvisitor_4: pvisitor,
    visitFlags,
    a5: this != (GMemoryFile *)120 ? (const struct GASObjectInterface *)this : nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100ADA80
// Name: public: virtual bool GFxSprite::DeleteMember(class GASStringContext __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxSprite::DeleteMember(
        GFxSprite *this,
        _IMAGE_SYMBOL_EX *result,
        CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *a3)
{
  return GFxASCharacter::DeleteMember(this, result, a3) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100ADAA0
// Name: public: class GFxSprite __near * GFxSprite::GetMask(void)const
// Source: json
//------------------------------------------------------------------------------
struct GFxSprite *__thiscall GFxSprite::GetMask(GFxSprite *this)
{
  if ( *(this + 116) == nullptr || ((unsigned __int8 (__thiscall *)(GFxSprite *))(*this)[11].RefCount)(a1: this) != 0 )
    return nullptr;
  else
    return (struct GFxSprite *)*(this + 116);
}

//------------------------------------------------------------------------------
// Address: 0x100ADAD0
// Name: public: void GFxSprite::SetMaskOwner(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
GPtr<GFxZlibSupportBase> *__thiscall GFxSprite::SetMaskOwner(_DWORD *this, GPtr<GFxZlibSupportBase> *result)
{
  GPtr<GFxZlibSupportBase> *v3; // eax

  if ( *(this + 116) != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD *))(*this + 180))(a1: this) == 0
    && *(this + 116) != 0 )
  {
    GFxSprite::SetMask(result: nullptr);
  }
  v3 = result;
  *(this + 116) = result;
  if ( result != nullptr )
    *(this + 40) |= 0x8000u;
  else
    *(this + 40) &= ~0x8000u;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100ADB30
// Name: GFx_SpritePlay
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFx_SpritePlay(_CONNECTDLGSTRUCTW fn)
{
  int v1; // ecx
  int result; // eax
  int v3; // ecx

  v1 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v1 == 0 )
  {
    result = *(_DWORD *)(fn.cbStructure + 24);
    v3 = *(_DWORD *)(result + 116);
    goto LABEL_6;
  }
  result = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1);
  if ( result == 2 )
  {
    result = *(_DWORD *)(fn.cbStructure + 8);
    if ( result != 0 )
    {
      v3 = result - 120;
LABEL_6:
      if ( v3 != 0 )
        return (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 328))(a1: v3, a2: 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ADB70
// Name: GFx_SpriteStop
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFx_SpriteStop(_CONNECTDLGSTRUCTW fn)
{
  int v1; // ecx
  int result; // eax
  int v3; // ecx

  v1 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v1 == 0 )
  {
    result = *(_DWORD *)(fn.cbStructure + 24);
    v3 = *(_DWORD *)(result + 116);
    goto LABEL_6;
  }
  result = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1);
  if ( result == 2 )
  {
    result = *(_DWORD *)(fn.cbStructure + 8);
    if ( result != 0 )
    {
      v3 = result - 120;
LABEL_6:
      if ( v3 != 0 )
        return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 328))(a1: v3, a2: 1);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ADBB0
// Name: GFx_SpritePrevFrame
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFx_SpritePrevFrame(_CONNECTDLGSTRUCTW fn)
{
  int v1; // ecx
  int result; // eax
  int v3; // esi
  int v4; // eax

  v1 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v1 != 0 )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1);
    if ( result != 2 )
      return result;
    result = *(_DWORD *)(fn.cbStructure + 8);
    if ( result == 0 )
      return result;
    v3 = result - 120;
  }
  else
  {
    result = *(_DWORD *)(fn.cbStructure + 24);
    v3 = *(_DWORD *)(result + 116);
  }
  if ( v3 != 0 )
  {
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 316))(a1: v3);
    if ( v4 > 0 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 324))(a1: v3, a2: v4 - 1);
    return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 328))(a1: v3, a2: 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ADC10
// Name: GFx_SpriteGetBytesLoaded
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteGetBytesLoaded(_DWORD *fn)
{
  int v1; // ecx
  GPtr<GFxZlibSupportBase> *v2; // ecx
  int v3; // eax
  int BytesLoaded; // eax
  int v5; // esi
  int v6; // edi

  v1 = fn[2];
  if ( v1 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1) != 2 )
      return;
    v3 = fn[2];
    if ( v3 == 0 )
      return;
    v2 = (GPtr<GFxZlibSupportBase> *)(v3 - 120);
  }
  else
  {
    v2 = *(GPtr<GFxZlibSupportBase> **)(fn[6] + 116);
  }
  if ( v2 != nullptr )
  {
    BytesLoaded = GFxSprite::GetBytesLoaded(this: v2);
    v5 = fn[1];
    v6 = BytesLoaded;
    if ( *(_BYTE *)v5 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v5);
    *(_DWORD *)(v5 + 4) = v6;
    *(_BYTE *)v5 = 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ADC70
// Name: GFx_SpriteGetSWFVersion
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteGetSWFVersion(_CONNECTDLGSTRUCTW fn)
{
  int v1; // ecx
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *v2; // ecx
  int v3; // eax
  const void *Version; // eax
  int v5; // esi
  const void *v6; // edi

  v1 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v1 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1) != 2 )
      return;
    v3 = *(_DWORD *)(fn.cbStructure + 8);
    if ( v3 == 0 )
      return;
    v2 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)(v3 - 120);
  }
  else
  {
    v2 = *(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> **)(*(_DWORD *)(fn.cbStructure + 24) + 116);
  }
  if ( v2 != nullptr )
  {
    Version = GFxCharacter::GetVersion(this: v2);
    v5 = *(_DWORD *)(fn.cbStructure + 4);
    v6 = Version;
    if ( *(_BYTE *)v5 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v5);
    *(_DWORD *)(v5 + 4) = v6;
    *(_BYTE *)v5 = 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ADCD0
// Name: GFx_SpriteLoadMovie
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFx_SpriteLoadMovie(_CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // esi
  int v2; // ecx
  int result; // eax
  GString v4; // edi
  int v5; // edi
  int v6; // ebx
  struct GASValue *v7; // eax
  bool v8; // zf
  int v9; // ebx
  struct GASValue *v10; // eax
  int v11; // eax
  char *v12; // [esp-10h] [ebp-24h]
  GRendererNode *v13; // [esp-Ch] [ebp-20h]
  int v14; // [esp+8h] [ebp-Ch] BYREF
  int v15; // [esp+Ch] [ebp-8h] BYREF
  int v16; // [esp+10h] [ebp-4h]

  cbStructure = fn.cbStructure;
  v2 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v2 != 0 )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( result != 2 )
      return result;
    v5 = *(_DWORD *)(cbStructure + 8);
    if ( v5 == 0 )
      return result;
    v4.pData = (GString::DataDesc *)(v5 - 120);
  }
  else
  {
    result = *(_DWORD *)(fn.cbStructure + 24);
    v4.pData = *(GString::DataDesc **)(result + 116);
  }
  if ( v4.pData != nullptr )
  {
    result = *(_DWORD *)(cbStructure + 28);
    if ( result > 0 )
    {
      v16 = 0;
      if ( result > 1 )
      {
        v6 = *(_DWORD *)(cbStructure + 24);
        v7 = GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 1);
        GASValue::ToStringImpl(a1: v7, a2: &v15, a3: v6, a4: -1, a5: 0);
        GASString::ToLower(a1: &v15, a2: &fn);
        v8 = (*(_DWORD *)(v15 + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode();
        if ( GASString::operator==(this: (const char ***)&fn, a2: "get") )
        {
          v16 = 1;
        }
        else if ( GASString::operator==(this: (const char ***)&fn, a2: "post") )
        {
          v16 = 2;
        }
        v8 = (*(_DWORD *)(fn.cbStructure + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode();
      }
      v9 = *(_DWORD *)(cbStructure + 24);
      v10 = GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
      GASValue::ToStringImpl(a1: v10, a2: &v14, a3: v9, a4: -1, a5: 0);
      v13 = (GRendererNode *)v16;
      v12 = *(char **)v14;
      v11 = (*(int (__thiscall **)(GString))(*(_DWORD *)v4.HeapTypeBits + 84))(a1: v4);
      GFxMovieRoot::AddLoadQueueEntry(this: v11, a2: v4, a3: v12, a4: v13, pmovieClipLoader: 0);
      result = v14;
      v8 = (*(_DWORD *)(v14 + 8))-- == 1;
      if ( v8 )
        return (unsigned int)GASStringNode::ReleaseNode().Sid;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ADE00
// Name: GFx_SpriteUnloadMovie
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteUnloadMovie(_CONNECTDLGSTRUCTW fn)
{
  int v1; // ecx
  GString::DataDesc *v2; // ecx
  int v3; // eax
  int v4; // eax
  GString v5; // [esp-10h] [ebp-14h]

  v1 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v1 == 0 )
  {
    v2 = *(GString::DataDesc **)(*(_DWORD *)(fn.cbStructure + 24) + 116);
    goto LABEL_6;
  }
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1) == 2 )
  {
    v3 = *(_DWORD *)(fn.cbStructure + 8);
    if ( v3 != 0 )
    {
      v2 = (GString::DataDesc *)(v3 - 120);
LABEL_6:
      if ( v2 != nullptr )
      {
        v5.pData = v2;
        v4 = (*(int (**)(void))(v2->Size + 84))();
        GFxMovieRoot::AddLoadQueueEntry(this: v4, a2: v5, a3: (char *)&pMem, a4: nullptr, pmovieClipLoader: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ADE50
// Name: GFx_SpriteLoadVariables
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFx_SpriteLoadVariables(_CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // esi
  int v2; // ecx
  int result; // eax
  unsigned int v4; // edi
  int v5; // edi
  int v6; // ebx
  struct GASValue *v7; // eax
  bool v8; // zf
  int v9; // ebx
  struct GASValue *v10; // eax
  GString::DataDesc *v11; // eax
  char *v12; // [esp-Ch] [ebp-20h]
  GRendererNode *v13; // [esp-8h] [ebp-1Ch]
  int v14; // [esp+8h] [ebp-Ch] BYREF
  int v15; // [esp+Ch] [ebp-8h] BYREF
  int v16; // [esp+10h] [ebp-4h]

  cbStructure = fn.cbStructure;
  v2 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v2 != 0 )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( result != 2 )
      return result;
    v5 = *(_DWORD *)(cbStructure + 8);
    if ( v5 == 0 )
      return result;
    v4 = v5 - 120;
  }
  else
  {
    result = *(_DWORD *)(fn.cbStructure + 24);
    v4 = *(_DWORD *)(result + 116);
  }
  if ( v4 != 0 )
  {
    result = *(_DWORD *)(cbStructure + 28);
    if ( result > 0 )
    {
      v16 = 0;
      if ( result > 1 )
      {
        v6 = *(_DWORD *)(cbStructure + 24);
        v7 = GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 1);
        GASValue::ToStringImpl(a1: v7, a2: &v15, a3: v6, a4: -1, a5: 0);
        GASString::ToLower(a1: &v15, a2: &fn);
        v8 = (*(_DWORD *)(v15 + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode();
        if ( GASString::operator==(this: (const char ***)&fn, a2: "get") )
        {
          v16 = 1;
        }
        else if ( GASString::operator==(this: (const char ***)&fn, a2: "post") )
        {
          v16 = 2;
        }
        v8 = (*(_DWORD *)(fn.cbStructure + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode();
      }
      v9 = *(_DWORD *)(cbStructure + 24);
      v10 = GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
      GASValue::ToStringImpl(a1: v10, a2: &v14, a3: v9, a4: -1, a5: 0);
      v13 = (GRendererNode *)v16;
      v12 = *(char **)v14;
      v11 = (GString::DataDesc *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v4 + 84))(a1: v4);
      GFxMovieRoot::AddVarLoadQueueEntry(a1: v11, a2: (_TAPE_WMI_OPERATIONS *)cbStructure, result: v4, a4: v12, a5: v13);
      result = v14;
      v8 = (*(_DWORD *)(v14 + 8))-- == 1;
      if ( v8 )
        return (unsigned int)GASStringNode::ReleaseNode().Sid;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ADF70
// Name: public: virtual void GFxSprite::SetName(class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetName(GFxSprite *this, const struct GASString *name)
{
  GFxASCharacter::SetName((GFxASCharacter *)this, (int)name);
  *(this + 52) = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100ADF90
// Name: public: static unsigned short GASMovieClipObject::GetButtonEventNameMask(class GASStringContext __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
static int __cdecl GASMovieClipObject::GetButtonEventNameMask(struct GASStringContext *a1, const struct GASString *a2)
{
  _DWORD *v2; // eax
  int v3; // ecx

  v2 = *(_DWORD **)a1;
  v3 = *(_DWORD *)a2;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 372) == *(_DWORD *)a2 )
    return 1;
  if ( v2[94] == v3 )
    return 2;
  if ( v2[95] == v3 )
    return 4;
  if ( v2[96] == v3 )
    return 8;
  if ( v2[97] == v3 )
    return 16;
  if ( v2[98] == v3 )
    return 32;
  if ( v2[99] == v3 )
    return 64;
  if ( v2[123] == v3 )
    return 128;
  if ( v2[124] == v3 )
    return 256;
  if ( v2[125] == v3 )
    return 512;
  if ( v2[126] == v3 )
    return 1024;
  if ( v2[127] == v3 )
    return 2048;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AE060
// Name: public: virtual bool GASMovieClipObject::DeleteMember(class GASStringContext __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge GASMovieClipObject::DeleteMember@<al>(
        GFxValue::ObjectInterface *this@<ecx>,
        _IMAGE_SYMBOL_EX *psc,
        struct GASString *name,
        bool a4)
{
  _BYTE *v5; // eax
  unsigned __int8 (__thiscall *v6)(GFxValue::ObjectInterface *, _IMAGE_SYMBOL_EX *, struct GASString *, GASValue *); // eax
  __int16 ButtonEventNameMask; // ax
  GASValue v9[4]; // [esp+Ch] [ebp-10h] BYREF

  if ( *(_DWORD *)(*(_DWORD *)name + 16) > 2u )
  {
    v5 = **(_BYTE ***)name;
    if ( *v5 == 111 && v5[1] == 110 )
    {
      v6 = *((unsigned __int8 (__thiscall **)(GFxValue::ObjectInterface *, _IMAGE_SYMBOL_EX *, struct GASString *, GASValue *))this->pMovieRoot
           + 11);
      LOBYTE(v9[0]) = 0;
      if ( v6(a1: this, a2: psc, a3: name, a4: v9) != 0 )
      {
        ButtonEventNameMask = GASMovieClipObject::GetButtonEventNameMask(a1: (struct GASStringContext *)psc, a2: name);
        if ( ButtonEventNameMask != 0 )
          *((_WORD *)this + 20) &= ~ButtonEventNameMask;
      }
      GASValue::~GASValue(this: v9);
    }
  }
  return GASObject::DeleteMember((GASObject *)this, name: psc, a3: name);
}

//------------------------------------------------------------------------------
// Address: 0x100AE0D0
// Name: public: static void GASMovieClipCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GASMovieClipCtorFunction::GlobalCtor(const GFxValue::ObjectInterface::ArrVisitor *result)
{
  GFxValue::ObjectInterface::ArrVisitor_vtbl *v1; // eax
  GFxValue::ObjectInterface::ArrVisitor_vtbl *v2; // esi

  if ( result[2].__vftable != nullptr
    && (*((int (__thiscall **)(GFxValue::ObjectInterface::ArrVisitor_vtbl *))result[2].dtr_ArrVisitor + 2))(a1: result[2].__vftable) == 11 )
  {
    v1 = result[2].__vftable;
    if ( v1 != nullptr )
      GASValue::SetAsObject(this: (GASValue *)result[1].__vftable, a2: (struct GASObject *)&v1[-2]);
    else
      GASValue::SetAsObject(this: (GASValue *)result[1].__vftable, a2: nullptr);
  }
  else
  {
    v2 = result[1].__vftable;
    GASValue::DropRefs(this: (GASValue *)v2);
    LOBYTE(v2->dtr_ArrVisitor) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE1A0
// Name: public: GFxFontHandle::~GFxFontHandle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontHandle::~GFxFontHandle(
        CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *this)
{
  GFxFontManager *v2; // ecx
  IShaderDevice *v3; // ecx
  IShaderDevice *v4; // ecx
  IShaderDevice *v5; // ecx
  volatile LONG *v6; // esi

  v2 = (GFxFontManager *)DWORD1(this->m_pfnProxied);
  if ( v2 != nullptr )
    GFxFontManager::RemoveFontHandle(this: v2, a2: (struct GFxFontHandle *)this);
  v3 = *((IShaderDevice **)this + 7);
  if ( v3 != nullptr )
    GFxResource::Release(this: v3);
  *((_DWORD *)this + 7) = 0;
  v4 = *((IShaderDevice **)this + 8);
  if ( v4 != nullptr )
    GFxResource::Release(this: v4);
  v5 = *((IShaderDevice **)this + 7);
  if ( v5 != nullptr )
    GFxResource::Release(this: v5);
  v6 = (volatile LONG *)(HIDWORD(this->m_pfnProxied) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v6 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x100AE200
// Name: public: virtual void GFxSpriteDef::SetSoundStream(class GFxSoundStreamDef __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSpriteDef::SetSoundStream(GFxSpriteDef *this, struct GFxSoundStreamDef *a2)
{
  GRefCountNTSImpl *v3; // ecx

  if ( a2 != nullptr )
    ++a2->m_nAllocationCount;
  v3 = *((GRefCountNTSImpl **)this + 12);
  if ( v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
  *((_DWORD *)this + 12) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x100AE230
// Name: public: void GFxSprite::SetRendererString(class GASString)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxSprite::SetRendererString(GFxFontLib::FontResult *this, _DWORD *str)
{
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  int v5; // esi
  int v6; // eax
  int v7; // esi
  bool v8; // zf
  void *result; // eax
  int v10; // [esp+Ch] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 119) == 0 )
  {
    v3 = *(_DWORD *)(*((_DWORD *)this + 47) + 32);
    v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
    v10 = 323;
    v5 = v4(a1: v3, a2: 92, a3: &v10);
    if ( v5 != 0 )
    {
      GASStringManager::CreateStringNode(this: *(const char **)(*((_DWORD *)this + 88) + 636));
      *(_DWORD *)v5 = v6;
      ++*(_DWORD *)(v6 + 8);
      *(float *)(v5 + 4) = 0.0;
      *(_DWORD *)(v5 + 72) = 0;
      *(_DWORD *)(v5 + 76) = 0;
      *(_DWORD *)(v5 + 80) = 0;
      *(_DWORD *)(v5 + 84) = 0;
      *(_BYTE *)(v5 + 88) = 0;
    }
    else
    {
      v5 = 0;
    }
    *((_DWORD *)this + 119) = v5;
  }
  v7 = *((_DWORD *)this + 119);
  ++str[2];
  v8 = (*(_DWORD *)(*(_DWORD *)v7 + 8))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode();
  *(_DWORD *)v7 = str;
  *(_BYTE *)(*((_DWORD *)this + 119) + 88) |= 1u;
  *(_DWORD *)(*((_DWORD *)this + 119) + 72) = ***((_DWORD ***)this + 119);
  result = str;
  v8 = str[2]-- == 1;
  if ( v8 )
    return GASStringNode::ReleaseNode().Sid;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AE2F0
// Name: public: void GFxSprite::SetRendererFloat(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetRendererFloat(GFxSprite *this, volatile int a2)
{
  GFxASUserData_vtbl *v3; // ecx
  int (__thiscall *v4)(GFxASUserData_vtbl *, int, int *); // edx
  int v5; // esi
  int v6; // eax
  int v7; // [esp+8h] [ebp-4h] BYREF

  if ( *(this + 119) == nullptr )
  {
    v3 = (*(this + 47))[2].__vftable;
    v4 = *((int (__thiscall **)(GFxASUserData_vtbl *, int, int *))v3->dtr_GRefCountImplCore + 10);
    v7 = 323;
    v5 = v4(a1: v3, a2: 92, a3: &v7);
    if ( v5 != 0 )
    {
      GASStringManager::CreateStringNode(this: (const char *)(*(this + 88))[39].pData);
      *(_DWORD *)v5 = v6;
      ++*(_DWORD *)(v6 + 8);
      *(float *)(v5 + 4) = 0.0;
      *(_DWORD *)(v5 + 72) = 0;
      *(_DWORD *)(v5 + 76) = 0;
      *(_DWORD *)(v5 + 80) = 0;
      *(_DWORD *)(v5 + 84) = 0;
      *(_BYTE *)(v5 + 88) = 0;
    }
    else
    {
      v5 = 0;
    }
    *(this + 119) = (GFxSprite)v5;
  }
  (*(this + 119))->RefCount = a2;
  LOBYTE((*(this + 119))[5].pObjectInterface) |= 2u;
  (*(this + 119))[4].pData = (void *)&(*(this + 119))->RefCount;
}

//------------------------------------------------------------------------------
// Address: 0x100AE390
// Name: public: void GFxSprite::SetRendererMatrix(float __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxTestStream *__thiscall GFxSprite::SetRendererMatrix(_DWORD *this, GFxTestStream *result, unsigned int count)
{
  int v4; // ecx
  int (__thiscall *v5)(int, int, int *); // edx
  int v6; // esi
  int v7; // eax
  GFxTestStream *v8; // eax
  int v9; // [esp+Ch] [ebp-4h] BYREF

  if ( *(this + 119) == 0 )
  {
    v4 = *(_DWORD *)(*(this + 47) + 32);
    v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
    v9 = 323;
    v6 = v5(a1: v4, a2: 92, a3: &v9);
    if ( v6 != 0 )
    {
      GASStringManager::CreateStringNode(this: *(const char **)(*(this + 88) + 636));
      *(_DWORD *)v6 = v7;
      ++*(_DWORD *)(v7 + 8);
      *(float *)(v6 + 4) = 0.0;
      *(_DWORD *)(v6 + 72) = 0;
      *(_DWORD *)(v6 + 76) = 0;
      *(_DWORD *)(v6 + 80) = 0;
      *(_DWORD *)(v6 + 84) = 0;
      *(_BYTE *)(v6 + 88) = 0;
    }
    else
    {
      v6 = 0;
    }
    *(this + 119) = v6;
  }
  *(_BYTE *)(*(this + 119) + 88) |= 3u;
  memcpy(dst: (unsigned __int8 *)(*(this + 119) + 8), src: (unsigned __int8 *)result, count: 4 * count);
  v8 = (GFxTestStream *)*(this + 119);
  v8[5].__vftable = (GFxTestStream_vtbl *)&v8->SType;
  *(_DWORD *)(*(this + 119) + 84) = count;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100AE450
// Name: public: void GFxSprite::ForceShutdown(void)
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *__thiscall GFxSprite::ForceShutdown(
        GFxFontLib *this)
{
  return GFxASCharacter::RemoveFromPlaylist(
           (int)this,
           result: *((const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **)this
           + 47));
}

//------------------------------------------------------------------------------
// Address: 0x100AE460
// Name: public: void GFxSprite::ClearDisplayList(void)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxSprite::ClearDisplayList(GFxFontLib *this)
{
  _DWORD *result; // eax

  GFxDisplayList::Clear(pheapAddr: (IMorph *)this + 49);
  result = *((_DWORD **)this + 47);
  result[2333] |= 0x400u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AE480
// Name: public: virtual class GFxMovieDefImpl __near * GFxSprite::GetResourceMovieDef(void)const
// Source: json
//------------------------------------------------------------------------------
struct GFxMovieDefImpl *__thiscall GFxSprite::GetResourceMovieDef(GFxSprite *this)
{
  return (struct GFxMovieDefImpl *)*(this + 36);
}

//------------------------------------------------------------------------------
// Address: 0x100AE490
// Name: public: virtual class GFxFontManager __near * GFxSprite::GetFontManager(void)const
// Source: json
//------------------------------------------------------------------------------
struct GFxFontManager *__thiscall GFxSprite::GetFontManager(GFxSprite *this)
{
  int v1; // eax

  v1 = (int)*(this + 112);
  if ( v1 != 0 )
    return *(struct GFxFontManager **)(v1 + 28);
  else
    return ((struct GFxFontManager *(__thiscall *)(_DWORD))(*(this + 8))->__vftable[12].dtr_GRefCountImplCore)(a1: *(this + 8));
}

//------------------------------------------------------------------------------
// Address: 0x100AE4B0
// Name: public: unsigned int GFxSprite::GetLoadingFrame(void)const
// Source: json
//------------------------------------------------------------------------------
const GPtr<GFxZlibSupportBase> *__thiscall GFxSprite::GetLoadingFrame(int this)
{
  int v1; // eax

  v1 = *(_DWORD *)(this + 448);
  if ( v1 == 0 || *(_BYTE *)(v1 + 24) != 0 )
    return (*(const GPtr<GFxZlibSupportBase> *(__thiscall **)(_DWORD))(**(_DWORD **)(this + 184) + 40))(a1: *(_DWORD *)(this + 184));
  else
    return *(const GPtr<GFxZlibSupportBase> **)(v1 + 16);
}

//------------------------------------------------------------------------------
// Address: 0x100AE4E0
// Name: public: void GFxSprite::GetTextSnapshot(class GFxStaticTextSnapshotData __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::GetTextSnapshot(GPtr<GFxZlibSupportBase> *this, GPtr<GFxAmpViewStats> *a2)
{
  unsigned int v3; // edi
  const GFxAmpViewStats *v4; // esi
  int v5; // eax
  unsigned int n; // [esp+8h] [ebp-4h]

  v3 = 0;
  n = *((_DWORD *)this + 50);
  if ( n != 0 )
  {
    do
    {
      v4 = *(const GFxAmpViewStats **)(*((_DWORD *)this + 49) + 4 * v3);
      if ( v4 != nullptr )
      {
        v5 = (*(int (__thiscall **)(const GFxAmpViewStats *))(*(_DWORD *)v4 + 88))(a1: v4);
        if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5) & 0xFF00) == 0x8200 )
          GFxStaticTextSnapshotData::Add(this: a2, pstChar: v4);
      }
      ++v3;
    }
    while ( v3 < n );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE550
// Name: public: bool GFxSprite::IsSoundPlaying(class GASSoundObject __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxSprite::IsSoundPlaying(_DWORD *this, const GFxValue *result)
{
  int v2; // ecx
  unsigned int v3; // edx
  int v4; // eax
  int v5; // esi
  int i; // ecx
  int v8; // ecx

  v2 = *(this + 114);
  if ( v2 == 0 )
    return false;
  v3 = *(_DWORD *)(v2 + 16);
  v4 = 0;
  if ( v3 == 0 )
    return false;
  v5 = *(_DWORD *)(v2 + 12);
  for ( i = v5; *(const GFxValue **)(*(_DWORD *)i + 12) != result; i += 4 )
  {
    if ( ++v4 >= v3 )
      return false;
  }
  v8 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v4) + 8);
  return v8 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 20))(a1: v8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AE5C0
// Name: public: void GFxSprite::UpdateActiveSoundVolume(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxSprite::UpdateActiveSoundVolume(
        GFxFontLib *this@<ecx>,
        _TAPE_WMI_OPERATIONS *a2@<edi>,
        _TAPE_WMI_OPERATIONS *a3@<esi>)
{
  int v4; // eax
  unsigned int i; // edi
  int v6; // eax
  int v7; // ecx
  GRefCountNTSImpl **v8; // eax
  GRefCountNTSImpl *v9; // esi
  unsigned int j; // edi
  int v11; // eax
  GFxFontLib *v12; // eax
  _TAPE_WMI_OPERATIONS *v13; // [esp+4h] [ebp-10h]
  unsigned int v14; // [esp+4h] [ebp-10h]
  float va; // [esp+10h] [ebp-4h]

  if ( *((_DWORD *)this + 114) != 0 )
  {
    v13 = a2;
    va = GFxSprite::GetRealSoundVolume((GFxValue *)this, a2: a3);
    v4 = *((_DWORD *)this + 114);
    for ( i = 0; i < *(_DWORD *)(v4 + 16); ++i )
    {
      v6 = *(_DWORD *)(v4 + 12);
      v7 = *(_DWORD *)(v6 + 4 * i);
      v8 = (GRefCountNTSImpl **)(v6 + 4 * i);
      if ( v7 != 0 )
        ++*(_DWORD *)(v7 + 4);
      v9 = *v8;
      (*((void (__stdcall **)(float))(*v8)[1].dtr_GRefCountImplCore + 10))(a1: COERCE_FLOAT(LODWORD(va)));
      GRefCountNTSImpl::Release(this: v9);
      v4 = *((_DWORD *)this + 114);
    }
    for ( j = 0; j < *((_DWORD *)this + 50); ++j )
    {
      v11 = *(_DWORD *)(*((_DWORD *)this + 49) + 4 * j);
      if ( *(char *)(v11 + 118) < 0 && (*(int (__thiscall **)(int))(*(_DWORD *)(v11 + 120) + 8))(a1: v11 + 120) == 2 )
      {
        v12 = (GFxFontLib *)GASObjectInterface::ToSprite(result: v13);
        GFxSprite::UpdateActiveSoundVolume(this: v12, v: v14);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE680
// Name: public: void GFxSprite::UpdateActiveSoundPan(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxSprite::UpdateActiveSoundPan(
        GFxFontLib *this@<ecx>,
        _TAPE_WMI_OPERATIONS *a2@<edi>,
        _TAPE_WMI_OPERATIONS *a3@<esi>)
{
  int v4; // eax
  unsigned int i; // edi
  int v6; // eax
  int v7; // ecx
  GRefCountNTSImpl **v8; // eax
  GRefCountNTSImpl *v9; // esi
  unsigned int j; // edi
  int v11; // eax
  GFxFontLib *v12; // eax
  _TAPE_WMI_OPERATIONS *v13; // [esp+4h] [ebp-10h]
  unsigned int v14; // [esp+4h] [ebp-10h]
  float va; // [esp+10h] [ebp-4h]

  if ( *((_DWORD *)this + 114) != 0 )
  {
    v13 = a2;
    va = GFxSprite::GetRealSoundPan((GFxValue *)this, a2: a3);
    v4 = *((_DWORD *)this + 114);
    for ( i = 0; i < *(_DWORD *)(v4 + 16); ++i )
    {
      v6 = *(_DWORD *)(v4 + 12);
      v7 = *(_DWORD *)(v6 + 4 * i);
      v8 = (GRefCountNTSImpl **)(v6 + 4 * i);
      if ( v7 != 0 )
        ++*(_DWORD *)(v7 + 4);
      v9 = *v8;
      (*((void (__stdcall **)(float))(*v8)[1].dtr_GRefCountImplCore + 12))(a1: COERCE_FLOAT(LODWORD(va)));
      GRefCountNTSImpl::Release(this: v9);
      v4 = *((_DWORD *)this + 114);
    }
    for ( j = 0; j < *((_DWORD *)this + 50); ++j )
    {
      v11 = *(_DWORD *)(*((_DWORD *)this + 49) + 4 * j);
      if ( *(char *)(v11 + 118) < 0 && (*(int (__thiscall **)(int))(*(_DWORD *)(v11 + 120) + 8))(a1: v11 + 120) == 2 )
      {
        v12 = (GFxFontLib *)GASObjectInterface::ToSprite(result: v13);
        GFxSprite::UpdateActiveSoundPan(this: v12, v: v14);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE740
// Name: public: virtual void GFxSprite::SetPause(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetPause(GFxSprite *this, int pause)
{
  int v3; // eax
  unsigned int i; // esi
  int v5; // ecx
  unsigned int v6; // esi
  char *v7; // ecx

  v3 = (int)*(this + 114);
  if ( v3 != 0 )
  {
    for ( i = 0; i < *(_DWORD *)(v3 + 16); ++i )
    {
      v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 12) + 4 * i) + 8);
      if ( v5 != 0 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 16))(a1: v5, a2: pause);
      v3 = (int)*(this + 114);
    }
  }
  v6 = 0;
  if ( *(this + 50) != nullptr )
  {
    do
    {
      v7 = *((char **)&(*(this + 49))->__vftable + v6);
      if ( v7[118] < 0 )
        (*(void (__thiscall **)(char *, int))(*(_DWORD *)v7 + 252))(a1: v7, a2: pause);
      ++v6;
    }
    while ( v6 < (unsigned int)*(this + 50) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE7C0
// Name: public: void GFxSprite::IncrementFrameAndCheckForLoop(void)
// Source: json
//------------------------------------------------------------------------------
GImageInfo *__thiscall GFxSprite::IncrementFrameAndCheckForLoop(GFxFontLib *this)
{
  int v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // eax
  char v5; // cl
  GImageInfo *result; // eax

  v2 = *((_DWORD *)this + 112);
  ++*((_DWORD *)this + 54);
  if ( v2 == 0 || *(_BYTE *)(v2 + 24) != 0 )
    v3 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 46) + 40))(a1: *((_DWORD *)this + 46));
  else
    v3 = *(_DWORD *)(v2 + 16);
  v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 46) + 40))(a1: *((_DWORD *)this + 46));
  if ( v3 >= v4 || *((_DWORD *)this + 54) < v3 )
  {
    if ( *((_DWORD *)this + 54) >= v4 )
    {
      v5 = *((_BYTE *)this + 480) | 2;
      *((_DWORD *)this + 54) = 0;
      *((_BYTE *)this + 480) = v5;
      if ( v4 <= 1 )
      {
        ((void (__thiscall *)(GFxFontLib *, int))this->__vftable[41].dtr_GRefCountImplCore)(a1: this, a2: 1);
      }
      else
      {
        GFxDisplayList::MarkAllEntriesForRemoval(result: nullptr);
        *(_DWORD *)(*((_DWORD *)this + 47) + 9332) |= 0x400u;
      }
    }
  }
  else if ( v3 != 0 )
  {
    *((_DWORD *)this + 54) = v3 - 1;
  }
  else
  {
    *((_DWORD *)this + 54) = 0;
  }
  result = *((GImageInfo **)this + 47);
  if ( result != nullptr )
  {
    result = (GImageInfo *)result[257].TargetHeight;
    if ( result != nullptr )
      return (GImageInfo *)GFxAmpViewStats::SetCurrentFrame(this: result);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AE8A0
// Name: public: void GFxSprite::MakeSnapshot(class GFxTimelineSnapshot __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::MakeSnapshot(GFxSprite *this, struct GFxTimelineSnapshot *a2, char *a3, char *a4)
{
  char *i; // edi
  unsigned int j; // esi
  int v6; // [esp+0h] [ebp-Ch] BYREF
  unsigned int v7; // [esp+4h] [ebp-8h]
  GRefCountNTSImpl *v8; // [esp+8h] [ebp-4h]

  v8 = (GRefCountNTSImpl *)this;
  if ( this != nullptr )
    *(this + 1) = (GFxSprite)((char *)*(this + 1) + 1);
  for ( i = a3; i <= a4; ++i )
  {
    (*(this + 46))->__vftable[5].OnDestroy(this: *(this + 46), a2: (GFxMovieView *)&v6, a3: i);
    for ( j = 0; j < v7; ++j )
      (*(void (__thiscall **)(_DWORD, struct GFxTimelineSnapshot *, char *))(**(_DWORD **)(v6 + 4 * j) + 24))(
        a1: *(_DWORD *)(v6 + 4 * j),
        a2,
        a3: i);
    this = (GFxSprite *)v8;
  }
  if ( this != nullptr )
    GRefCountNTSImpl::Release((GRefCountNTSImpl *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100AE910
// Name: public: void GFxSprite::ExecuteInitActionFrameTags(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::ExecuteInitActionFrameTags(GPtr<GFxZlibSupportBase> *this, GFxZlibSupportBase *frame)
{
  int v3; // ecx
  unsigned int i; // edi
  int v5; // [esp+4h] [ebp-8h] BYREF
  unsigned int v6; // [esp+8h] [ebp-4h]

  if ( *((_BYTE *)&frame->__vftable + *((_DWORD *)this + 55)) == 0 )
  {
    ++*((_DWORD *)this + 1);
    v3 = *((_DWORD *)this + 46);
    v5 = 0;
    v6 = 0;
    if ( (*(unsigned __int8 (__thiscall **)(int, int *, GFxZlibSupportBase *))(*(_DWORD *)v3 + 48))(
           a1: v3,
           a2: &v5,
           a3: frame) != 0
      && v6 != 0 )
    {
      for ( i = 0; i < v6; ++i )
        (*(void (__thiscall **)(_DWORD, GPtr<GFxZlibSupportBase> *))(**(_DWORD **)(v5 + 4 * i) + 4))(
          a1: *(_DWORD *)(v5 + 4 * i),
          a2: this);
      *((_BYTE *)&frame->__vftable + *((_DWORD *)this + 55)) = 1;
    }
    GRefCountNTSImpl::Release((GRefCountNTSImpl *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE990
// Name: public: void GFxSprite::ExecuteImportedInitActions(class GFxMovieDef __near *)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *__userpurge GFxSprite::ExecuteImportedInitActions@<eax>(
        GMemoryFile *this@<ecx>,
        __int64 psourceMovie,
        int pdataDef)
{
  _DWORD *v4; // esi
  int v5; // ecx
  unsigned int v6; // ebx
  const CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *result; // eax
  unsigned __int8 (__thiscall *v8)(_DWORD *, int *, unsigned int); // edx
  GFxInitImportActions *v9; // esi
  int v10; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v11; // [esp+10h] [ebp-10h]
  unsigned int fc; // [esp+14h] [ebp-Ch]
  _DWORD *v13; // [esp+18h] [ebp-8h]
  unsigned int f; // [esp+1Ch] [ebp-4h]

  v4 = *(_DWORD **)(*(_DWORD *)(psourceMovie + 28) + 12);
  v5 = v4[8];
  v6 = 0;
  v13 = v4;
  f = 0;
  result = GFxMovieDataDef::LoadTaskData::GetInitActionListSize(this: v5);
  fc = (unsigned int)result;
  if ( result != nullptr )
  {
    do
    {
      v8 = *(unsigned __int8 (__thiscall **)(_DWORD *, int *, unsigned int))(*v4 + 48);
      v10 = 0;
      v11 = 0;
      if ( v8(a1: v4, a2: &v10, a3: f) != 0 && v11 != 0 )
      {
        do
        {
          v9 = *(GFxInitImportActions **)(v10 + 4 * v6);
          if ( (*((unsigned __int8 (__thiscall **)(GFxInitImportActions *))&(*v9)->m_pObject + 1))(a1: v9) != 0 )
            GFxInitImportActions::ExecuteInContext(
              this: v9,
              a2: this,
              pbindDef: (struct GFxMovieDefImpl *)psourceMovie,
              recursiveCheck: true);
          else
            ((void (__thiscall *)(GFxInitImportActions *, GMemoryFile *, _DWORD))DWORD2((*v9)->m_pfnProxied))(
              a1: v9,
              a2: this,
              a3: 0);
          ++v6;
        }
        while ( v6 < v11 );
        v4 = v13;
        v6 = 0;
      }
      result = (const CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *)(f + 1);
      f = (unsigned int)result;
    }
    while ( (unsigned int)result < fc );
  }
  *(_DWORD *)(*((_DWORD *)this + 47) + 9332) |= 0x400u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AEA40
// Name: public: void GFxSprite::AddActionBuffer(class GASActionBuffer __near *,enum GFxActionPriority::Priority)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::AddActionBuffer(_DWORD *this, int a, const GPoint3<float> *a_4)
{
  const GPoint3<float> *inserted; // eax
  _DWORD *p_x; // esi
  GRefCountNTSImpl *z_low; // ecx
  GRefCountNTSImpl *v7; // ecx

  inserted = GFxMovieRoot::ActionQueueType::InsertEntry(this: *(this + 47) + 9224, result: a_4);
  p_x = (_DWORD *)&inserted->x;
  if ( inserted != nullptr )
  {
    LODWORD(inserted->y) = 1;
    ++*(this + 1);
    z_low = (GRefCountNTSImpl *)LODWORD(inserted->z);
    if ( z_low != nullptr )
      GRefCountNTSImpl::Release(this: z_low);
    p_x[2] = this;
    if ( a != 0 )
      ++*(_DWORD *)(a + 4);
    v7 = (GRefCountNTSImpl *)p_x[3];
    if ( v7 != nullptr )
      GRefCountNTSImpl::Release(this: v7);
    p_x[3] = a;
    p_x[4] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEAB0
// Name: public: virtual void GFxSprite::PropagateMouseEvent(class GFxEventId const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::PropagateMouseEvent(int this, GMemoryFile *result)
{
  if ( this != 0 )
    ++*(_DWORD *)(this + 4);
  if ( result->__vftable == (GMemoryFile_vtbl *)8 && *(_DWORD *)(*(_DWORD *)(this + 188) + 2500) != 0 )
    GFxASCharacter::DoMouseDrag((GFxASCharacter *)this, a2: (const CMaterialDict::MissingMaterial_t *)result);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)this + 16))(a1: this) != 0 )
  {
    GFxDisplayList::PropagateMouseEvent(this: (CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *)(this + 196));
    (*(void (__thiscall **)(int, GMemoryFile *))(*(_DWORD *)this + 128))(a1: this, a2: result);
  }
  GRefCountNTSImpl::Release((GRefCountNTSImpl *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100AEB10
// Name: public: virtual void GFxSprite::PropagateKeyEvent(class GFxEventId const __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::PropagateKeyEvent(
        GMemoryFile *this,
        CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *id,
        int *pkeyMask)
{
  if ( this != nullptr )
    ++this->RefCount;
  if ( (unsigned __int8)this->Tell(this) != 0 )
  {
    GFxDisplayList::PropagateKeyEvent(result: id);
    ((void (__thiscall *)(GMemoryFile *, CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *, int *))this->__vftable[1].Close)(
      a1: this,
      a2: id,
      a3: pkeyMask);
  }
  GRefCountNTSImpl::Release((GRefCountNTSImpl *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100AEB70
// Name: public: void GFxSprite::MoveDisplayObject(class GFxCharPosInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100AEBA0
// Name: public: void GFxSprite::ReplaceDisplayObject(class GFxCharPosInfo const __near &,class GFxCharacter __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
const char *__userpurge GFxSprite::ReplaceDisplayObject@<eax>(
        GMemoryFile *this@<ecx>,
        int a2@<esi>,
        _IMAGE_SYMBOL_EX *name,
        int a4,
        int a5)
{
  _DWORD *v6; // esi
  void (__thiscall *v7)(int); // eax
  _DWORD *v8; // eax
  const char *result; // eax
  __int128 v10; // [esp-8h] [ebp-10h]

  if ( *(_DWORD *)(*(_DWORD *)a5 + 16) != 0 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)a4 + 40))(a1: a4, a2: a5);
  DWORD1(v10) = a2;
  v6 = *(_DWORD **)(a4 + 32);
  if ( v6 != nullptr )
  {
    while ( (*(int (__thiscall **)(_DWORD *, _DWORD))(*v6 + 76))(a1: v6, a2: DWORD1(v10)) == 0 )
    {
      v6 = (_DWORD *)v6[8];
      if ( v6 == nullptr )
        goto LABEL_8;
    }
    v7 = *(void (__thiscall **)(int))(*(_DWORD *)a4 + 80);
    *(_WORD *)(a4 + 118) |= 1u;
    v7(a1: a4);
  }
LABEL_8:
  LODWORD(v10) = a4;
  GFxDisplayList::ReplaceDisplayObject(this: (CMatCallQueue *)(this + 7), pos: (CLateBoundPtr<IMesh>)name, ch: v10);
  if ( *(_DWORD *)(*(_DWORD *)a5 + 16) != 0 && *(char *)(a4 + 118) < 0 )
  {
    v8 = (_DWORD *)((int (__thiscall *)(GMemoryFile *))this->__vftable[1].IsValid)(a1: this);
    GFxMovieRoot::ResolveStickyVariables(
      this: v8,
      a2: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)a4);
  }
  result = *((const char **)this + 47);
  *((_DWORD *)result + 2333) |= 0x400u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AEC40
// Name: public: void GFxSprite::RemoveDisplayObject(int,class GFxResourceId)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSprite::RemoveDisplayObject(GMemoryFile *this, GFile *depth, int id)
{
  int result; // eax

  GFxDisplayList::RemoveDisplayObject(this: (GFxDisplayList *)(this + 7), (int)depth, a3: (struct GFxResourceId)id);
  result = *((_DWORD *)this + 47);
  *(_DWORD *)(result + 9332) |= 0x400u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AEC80
// Name: public: virtual bool GFxSprite::ReplaceChildCharacterOnLoad(class GFxASCharacter __near *,class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::ReplaceChildCharacterOnLoad(GMemoryFile *this, unsigned __int8 *poldChar, int pnewChar)
{
  char result; // al
  ScaleformRenderer *v5; // eax

  result = ((int (__thiscall *)(GMemoryFile *, unsigned __int8 *, int))this->__vftable[4].IsValid)(
             a1: this,
             a2: poldChar,
             a3: pnewChar);
  if ( result != 0 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)pnewChar + 132))(a1: pnewChar);
    v5 = (ScaleformRenderer *)((int (__thiscall *)(GMemoryFile *))this->__vftable[1].IsValid)(a1: this);
    GFxMovieRoot::DoActions(this: v5);
    *(_DWORD *)(*((_DWORD *)this + 47) + 9332) |= 0x400u;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AECE0
// Name: public: virtual bool GFxSprite::ExecuteEvent(class GFxEventId const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxSprite::ExecuteEvent(GMemoryFile *this, const struct GFxEventId *id)
{
  int v5; // eax
  int v6; // eax
  bool rv; // [esp+2Fh] [ebp+Bh]

  if ( (*((_BYTE *)this + 118) & 0x10) != 0 )
    return false;
  ++this->RefCount;
  if ( *(_DWORD *)id != 1
    || (v5 = *((_DWORD *)this + 40), *((_WORD *)this + 59) &= ~0x20u, (v5 & 0x1000) != 0)
    || *((char *)this + 480) < 0 )
  {
    rv = GFxASCharacter::ExecuteEvent(
           (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this,
           a2: id);
    if ( *(_DWORD *)id == 4 )
    {
      v6 = *((_DWORD *)this + 47);
      *((_WORD *)this + 59) |= 0x10u;
      *((_DWORD *)this + 35) = *(_DWORD *)(v6 + 10252);
      *(_DWORD *)(v6 + 10252) = this;
      ++this->RefCount;
    }
    GRefCountNTSImpl::Release((GRefCountNTSImpl *)this);
    return rv;
  }
  else
  {
    GRefCountNTSImpl::Release((GRefCountNTSImpl *)this);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEDB0
// Name: public: bool GFxSprite::HasEventHandler(class GFxEventId const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::HasEventHandler(GFxSprite *this, const struct GFxEventId *a2)
{
  unsigned int *v2; // edi
  int v4; // eax
  const struct GFxEventId *v5; // eax
  int v6; // eax
  bool v7; // zf
  GASValue method[4]; // [esp+8h] [ebp-10h] BYREF

  v2 = (unsigned int *)a2;
  if ( GFxASCharacter::HasClipEventHandler((GFxASCharacter *)this, a2) )
    return 1;
  v4 = ((int (__thiscall *)(GFxSprite *))(*this)[6].pData)(a1: this);
  GFxEventId::GetFunctionName(this: v2, &a2, psc: (_DWORD *)(v4 + 120));
  v5 = a2;
  if ( *((_DWORD *)a2 + 4) != 0 )
  {
    v6 = (int)*(this + 113);
    LOBYTE(method[0]) = 0;
    if ( (v6 != 0 || (v6 = (int)*(this + 32)) != 0)
      && (*(unsigned __int8 (__thiscall **)(int, GFxSprite *, const struct GFxEventId **, GASValue *))(*(_DWORD *)(v6 + 16) + 44))(
           a1: v6 + 16,
           a2: this + 88,
           a3: &a2,
           a4: method) != 0 )
    {
      GASValue::~GASValue(this: method);
      v7 = (*((_DWORD *)a2 + 2))-- == 1;
      if ( v7 )
        GASStringNode::ReleaseNode();
      return 1;
    }
    GASValue::~GASValue(this: method);
    v5 = a2;
  }
  v7 = (*((_DWORD *)v5 + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AEE60
// Name: public: bool GFxSprite::InvokeArgs(char const __near *,class GASValue __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::InvokeArgs(
        GRefCountBase<GFxResourceLibBase,2> *this,
        char *varname,
        struct GASValue *a3,
        char *a4,
        char *args)
{
  struct GASObjectInterface *v6; // eax

  if ( this != nullptr )
  {
    ++this->RefCount;
    v6 = (struct GASObjectInterface *)(this + 15);
  }
  else
  {
    v6 = nullptr;
  }
  GAS_InvokeParsed(varname, a2: a3, args: v6, a4: (__vc_attributes::max_isAttribute *)this + 58, a5: a4, a6: args);
  if ( this != nullptr )
    GRefCountNTSImpl::Release((GRefCountNTSImpl *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100AEEB0
// Name: public: void GFxSprite::SetMask(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetMask(GPtr<GFxZlibSupportBase> *this, GPtr<GFxZlibSupportBase> *result)
{
  _DWORD *v3; // edi

  if ( *((_DWORD *)this + 116) != 0 )
  {
    if ( ((unsigned __int8 (__thiscall *)(GPtr<GFxZlibSupportBase> *))this->pObject[15].__vftable)(a1: this) == 0 )
    {
      v3 = *((_DWORD **)this + 116);
      if ( v3 != nullptr )
      {
        if ( v3[116] != 0
          && (*(unsigned __int8 (__thiscall **)(_DWORD))(*v3 + 180))(a1: *((_DWORD *)this + 116)) == 0
          && v3[116] != 0 )
        {
          GFxSprite::SetMask(result: nullptr);
        }
        v3[40] &= ~0x8000u;
        v3[116] = 0;
      }
    }
    if ( *((_DWORD *)this + 116) != 0 )
    {
      if ( ((unsigned __int8 (__thiscall *)(GPtr<GFxZlibSupportBase> *))this->pObject[15].__vftable)(a1: this) != 0
        && *((_DWORD *)this + 116) != 0 )
      {
        GFxSprite::SetMask(result: nullptr);
      }
      if ( *((_DWORD *)this + 116) != 0
        && ((unsigned __int8 (__thiscall *)(GPtr<GFxZlibSupportBase> *))this->pObject[15].__vftable)(a1: this) == 0 )
      {
        GRefCountNTSImpl::Release(this: *((GRefCountNTSImpl **)this + 116));
      }
    }
  }
  *((_DWORD *)this + 40) &= ~0x8000u;
  *((_DWORD *)this + 116) = result;
  if ( result != nullptr )
  {
    ++result[1].pObject;
    *((_WORD *)this + 58) = 0;
    if ( result[116].pObject != nullptr
      && ((unsigned __int8 (__thiscall *)(GPtr<GFxZlibSupportBase> *))result->pObject[15].__vftable)(a1: result) != 0
      && result[116].pObject != nullptr )
    {
      GFxSprite::SetMask(result: nullptr);
    }
    GFxSprite::SetMaskOwner(this: result, result: this);
  }
  *(_DWORD *)(*((_DWORD *)this + 47) + 9332) |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x100AEFD0
// Name: public: void GFxSprite::SetScale9Grid(struct GFxScale9Grid const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetScale9Grid(GFxSprite *this, int a2)
{
  void *v3; // eax
  const struct GFxScale9Grid *v4; // edi
  bool v5; // bl
  GFxASUserData_vtbl *v6; // ecx
  int (__thiscall *v7)(GFxASUserData_vtbl *, int, int *); // eax
  _DWORD *v8; // eax

  v3 = *(this + 48);
  v4 = (const struct GFxScale9Grid *)a2;
  v5 = (a2 != 0) != (v3 != nullptr);
  if ( a2 != 0 )
  {
    if ( v3 == nullptr )
    {
      v6 = (*(this + 47))[2].__vftable;
      v7 = *((int (__thiscall **)(GFxASUserData_vtbl *, int, int *))v6->dtr_GRefCountImplCore + 10);
      a2 = 265;
      *(this + 48) = (GFxSprite)v7(a1: v6, a2: 16, a3: &a2);
    }
    v8 = *(this + 48);
    *v8 = *(_DWORD *)v4;
    v8[1] = *((_DWORD *)v4 + 1);
    v8[2] = *((_DWORD *)v4 + 2);
    v8[3] = *((_DWORD *)v4 + 3);
    *((_WORD *)this + 59) |= 1u;
  }
  else
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
    *((_WORD *)this + 59) &= ~1u;
    *(this + 48) = nullptr;
  }
  if ( v5 )
    ((void (__thiscall *)(GFxSprite *))(*this)[5].__vftable)(a1: this);
  (*(this + 47))[583].RefCount |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x100AF090
// Name: public: virtual void GFxSprite::PropagateScale9GridExists(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::PropagateScale9GridExists(GFxFontLib *this)
{
  char result; // al
  unsigned int v3; // ebx
  int v4; // edi
  _WORD *v5; // ecx
  bool actualGrida; // [esp+7h] [ebp-1h]

  result = ((int (__thiscall *)(GFxFontLib *))this->__vftable[9].FindFont)(a1: this) != 0;
  actualGrida = result;
  if ( (*((_BYTE *)this + 118) & 1) != 0 || result == 0 )
  {
    v3 = *((_DWORD *)this + 50);
    v4 = 0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v5 = *(_WORD **)(*((_DWORD *)this + 49) + 4 * v4);
        if ( (*((_BYTE *)this + 118) & 1) != 0 || result != 0 )
          v5[59] |= 1u;
        else
          v5[59] &= ~1u;
        result = (*(int (__thiscall **)(_WORD *))(*(_DWORD *)v5 + 80))(a1: v5);
        if ( ++v4 >= v3 )
          break;
        result = actualGrida;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AF100
// Name: public: virtual void GFxSprite::PropagateNoAdvanceGlobalFlag(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxSprite::PropagateNoAdvanceGlobalFlag(GFxFontLib *this)
{
  unsigned int result; // eax
  int v3; // eax
  CMatQueuedMesh **v4; // esi
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v5; // ebx
  int v6; // eax
  unsigned int n; // [esp+4h] [ebp-10h]
  unsigned int i; // [esp+Ch] [ebp-8h]
  bool actualValuea; // [esp+13h] [ebp-1h]

  actualValuea = (*(_DWORD *)(this + 10) & 8) != 0;
  result = 0;
  i = 0;
  n = *((_DWORD *)this + 50);
  if ( n != 0 )
  {
    do
    {
      v3 = *(_DWORD *)(*((_DWORD *)this + 49) + 4 * result);
      v4 = *(_BYTE *)(v3 + 118) >> 7 != 0 ? (CMatQueuedMesh **)v3 : nullptr;
      if ( v4 != nullptr )
      {
        if ( (*(_DWORD *)(this + 10) & 8) != 0 || actualValuea )
          v4[40] = (CMatQueuedMesh *)((unsigned int)v4[40] | 8);
        else
          v4[40] = (CMatQueuedMesh *)((unsigned int)v4[40] & 0xFFFFFFF7);
        (*(void (__thiscall **)(CMatQueuedMesh **))&(*v4)[3].m_VertexSize)(a1: v4);
        v5 = *((const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **)this
             + 47);
        v6 = ((int (__thiscall *)(CMatQueuedMesh **, bool))(*v4)[3].m_nIndices)(
               a1: v4,
               a2: ((unsigned int)v4[40] & 0x80000) != 0);
        if ( v6 == -1 )
        {
          GFxASCharacter::RemoveFromOptimizedPlaylist(this: v4, result: v5);
        }
        else if ( v6 == 1 )
        {
          GFxASCharacter::AddToOptimizedPlayList(this: (int)v4, result: v5);
        }
      }
      result = i + 1;
      i = result;
    }
    while ( result < n );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AF1E0
// Name: public: virtual void GFxSprite::PropagateNoAdvanceLocalFlag(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxSprite::PropagateNoAdvanceLocalFlag(GFxFontLib *this)
{
  unsigned int result; // eax
  int v3; // eax
  CMatQueuedMesh **v4; // esi
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v5; // ebx
  int v6; // eax
  unsigned int n; // [esp+4h] [ebp-10h]
  unsigned int i; // [esp+Ch] [ebp-8h]
  bool actualValuea; // [esp+13h] [ebp-1h]

  actualValuea = (*(_DWORD *)(this + 10) & 4) != 0;
  result = 0;
  i = 0;
  n = *((_DWORD *)this + 50);
  if ( n != 0 )
  {
    do
    {
      v3 = *(_DWORD *)(*((_DWORD *)this + 49) + 4 * result);
      v4 = *(_BYTE *)(v3 + 118) >> 7 != 0 ? (CMatQueuedMesh **)v3 : nullptr;
      if ( v4 != nullptr )
      {
        if ( (*(_DWORD *)(this + 10) & 4) != 0 || actualValuea )
          v4[40] = (CMatQueuedMesh *)((unsigned int)v4[40] | 4);
        else
          v4[40] = (CMatQueuedMesh *)((unsigned int)v4[40] & 0xFFFFFFFB);
        (*(void (__thiscall **)(CMatQueuedMesh **))&(*v4)[3].m_bExternalIB)(a1: v4);
        v5 = *((const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **)this
             + 47);
        v6 = ((int (__thiscall *)(CMatQueuedMesh **, bool))(*v4)[3].m_nIndices)(
               a1: v4,
               a2: ((unsigned int)v4[40] & 0x80000) != 0);
        if ( v6 == -1 )
        {
          GFxASCharacter::RemoveFromOptimizedPlaylist(this: v4, result: v5);
        }
        else if ( v6 == 1 )
        {
          GFxASCharacter::AddToOptimizedPlayList(this: (int)v4, result: v5);
        }
      }
      result = i + 1;
      i = result;
    }
    while ( result < n );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AF2C0
// Name: public: virtual void GFxSprite::PropagateFocusGroupMask(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const GPtr<GFxZlibSupportBase> *__userpurge GFxSprite::PropagateFocusGroupMask@<eax>(
        GPtr<GFxZlibSupportBase> *this@<ecx>,
        const GPtr<GFxZlibSupportBase> *result@<eax>,
        GFxZlibSupportBase *mask)
{
  unsigned int v4; // ebx
  unsigned int i; // esi
  GFxZlibSupportBase *pObject; // edx

  v4 = *((_DWORD *)this + 50);
  for ( i = 0; i < v4; ++i )
  {
    result = *(const GPtr<GFxZlibSupportBase> **)(*((_DWORD *)this + 49) + 4 * i);
    if ( (BYTE2(result[29].pObject) >> 7 != 0 ? (unsigned int)result : 0) != 0 )
    {
      pObject = (BYTE2(result[29].pObject) >> 7 != 0 ? result : nullptr)->pObject;
      *(BYTE2(result[29].pObject) >> 7 != 0 ? (_WORD *)((char *)&result[41].pObject + 2) : (_WORD *)166) = (_WORD)mask;
      result = (const GPtr<GFxZlibSupportBase> *)((int (__stdcall *)(GFxZlibSupportBase *))pObject[25].RefCount)(a1: mask);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AF320
// Name: public: virtual void GFxSprite::UpdateViewAndPerspective(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlMemory<unsigned char,int> *__thiscall GFxSprite::UpdateViewAndPerspective(GFxFontLib *this)
{
  const CUtlMemory<unsigned char,int> *result; // eax
  unsigned int v3; // ebx
  unsigned int i; // esi
  int v5; // ecx

  result = GFxCharacter::UpdateViewAndPerspective(this);
  v3 = *((_DWORD *)this + 50);
  for ( i = 0; i < v3; ++i )
  {
    result = *((const CUtlMemory<unsigned char,int> **)this + 49);
    v5 = *((_DWORD *)&result->m_pMemory + i);
    if ( v5 != 0 )
      result = (const CUtlMemory<unsigned char,int> *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AF360
// Name: public: virtual bool GFxSprite::Has3D(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::Has3D(GFxSprite *this)
{
  unsigned int v3; // ebx
  int v4; // esi
  int v5; // ecx

  if ( GFxCharacter::Is3D(this, result: nullptr) != 0 )
    return 1;
  v3 = (unsigned int)*(this + 50);
  v4 = 0;
  if ( v3 == 0 )
    return 0;
  while ( 1 )
  {
    v5 = *((_DWORD *)&(*(this + 49))->__vftable + v4);
    if ( v5 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5) != 0 )
      break;
    if ( ++v4 >= v3 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AF3B0
// Name: GFx_SpriteNextFrame
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFx_SpriteNextFrame(_CONNECTDLGSTRUCTW fn)
{
  int v1; // ecx
  int result; // eax
  int v3; // esi
  int v4; // eax
  int v5; // edi
  int v6; // eax

  v1 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v1 != 0 )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1);
    if ( result != 2 )
      return result;
    result = *(_DWORD *)(fn.cbStructure + 8);
    if ( result == 0 )
      return result;
    v3 = result - 120;
  }
  else
  {
    result = *(_DWORD *)(fn.cbStructure + 24);
    v3 = *(_DWORD *)(result + 116);
  }
  if ( v3 != 0 )
  {
    v4 = *(_DWORD *)(v3 + 448);
    if ( v4 == 0 || *(_BYTE *)(v4 + 24) != 0 )
      v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v3 + 184) + 40))(a1: *(_DWORD *)(v3 + 184));
    else
      v5 = *(_DWORD *)(v4 + 16);
    v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 316))(a1: v3);
    if ( v6 < v5 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 324))(a1: v3, a2: v6 + 1);
    return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 328))(a1: v3, a2: 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AF440
// Name: GFx_SpriteGetBytesTotal
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteGetBytesTotal(_CONNECTDLGSTRUCTW fn)
{
  int v1; // ecx
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // esi
  int v6; // edi

  v1 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v1 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1) != 2 )
      return;
    v3 = *(_DWORD *)(fn.cbStructure + 8);
    if ( v3 == 0 )
      return;
    v2 = v3 - 120;
  }
  else
  {
    v2 = *(_DWORD *)(*(_DWORD *)(fn.cbStructure + 24) + 116);
  }
  if ( v2 != 0 )
  {
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 92))(a1: v2);
    v5 = *(_DWORD *)(fn.cbStructure + 4);
    v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 28) + 12) + 32) + 40);
    if ( *(_BYTE *)v5 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v5);
    *(_DWORD *)(v5 + 4) = v6;
    *(_BYTE *)v5 = 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF4A0
// Name: GFx_SpriteDuplicateMovieClip
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteDuplicateMovieClip(_CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // esi
  GASValue *v2; // edi
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  _SERVICE_STATUS *v6; // ebx
  int v7; // edi
  struct GASValue *v8; // eax
  GASValue *v9; // eax
  int v10; // eax
  int v11; // eax
  tagBITMAPCOREHEADER *v12; // edi
  struct GASEnvironment *v14; // [esp-Ch] [ebp-18h]
  _SERVICE_STATUS *v15; // [esp-8h] [ebp-14h]
  int v16; // [esp+8h] [ebp-4h] BYREF
  CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *fna; // [esp+14h] [ebp+8h]

  cbStructure = fn.cbStructure;
  v2 = *(GASValue **)(fn.cbStructure + 4);
  GASValue::DropRefs(this: v2);
  *(_BYTE *)v2 = 0;
  v3 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v3 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3) != 2 )
      return;
    v4 = *(_DWORD *)(fn.cbStructure + 8);
    if ( v4 == 0 )
      return;
    fna = (CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)(v4 - 120);
  }
  else
  {
    fna = *(CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **)(*(_DWORD *)(fn.cbStructure + 24) + 116);
  }
  if ( fna != nullptr )
  {
    v5 = *(_DWORD *)(cbStructure + 28);
    if ( v5 >= 2 )
    {
      if ( v5 == 3 )
      {
        v15 = *(_SERVICE_STATUS **)(cbStructure + 24);
        GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 2);
        v6 = GASValue::ToObjectInterface(result: v15);
      }
      else
      {
        v6 = nullptr;
      }
      v7 = *(_DWORD *)(cbStructure + 24);
      v8 = GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
      GASValue::ToStringImpl(a1: v8, a2: &v16, a3: v7, a4: -1, a5: 0);
      v14 = *(struct GASEnvironment **)(cbStructure + 24);
      v9 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 1);
      v10 = (int)GASValue::ToNumber(this: v9, a2: v14);
      v11 = GFxASCharacter::CloneDisplayObject(
              this: fna,
              newname: (_IMAGE_SYMBOL_EX *)&v16,
              depth: v10 + 0x4000,
              a4: (int)v6);
      v12 = (tagBITMAPCOREHEADER *)v11;
      if ( v11 != 0 )
        ++*(_DWORD *)(v11 + 4);
      if ( (*(_DWORD *)(v16 + 8))-- == 1 )
        GASStringNode::ReleaseNode();
      if ( (unsigned int)GFxCharacter::GetVersion(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)fna) >= 6 )
        GASValue::SetAsCharacter(result: v12);
      if ( v12 != nullptr )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF5B0
// Name: GFx_SpriteAttachAudio
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteAttachAudio(int fn)
{
  GASValue *v1; // edi
  int v2; // ecx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v3; // ebx
  int v4; // ebx
  int v5; // eax
  GASValue *v6; // eax
  struct GASObject *v7; // eax
  struct GASObject *v8; // edi
  struct GFxMovieRoot *MovieRoot; // eax
  IShaderAPI *v10; // eax
  IShaderAPI *v11; // esi
  const struct GASEnvironment *v12; // [esp-4h] [ebp-10h]

  v1 = *(GASValue **)(fn + 4);
  GASValue::DropRefs(this: v1);
  *(_BYTE *)v1 = 0;
  v2 = *(_DWORD *)(fn + 8);
  if ( v2 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2) != 2 )
      return;
    v4 = *(_DWORD *)(fn + 8);
    if ( v4 == 0 )
      return;
    v3 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)(v4 - 120);
  }
  else
  {
    v3 = *(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)(*(_DWORD *)(fn + 24) + 116);
  }
  if ( v3 != nullptr )
  {
    if ( *(int *)(fn + 28) >= 1 )
    {
      v12 = *(const struct GASEnvironment **)(fn + 24);
      v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
      v7 = GASValue::ToObject(this: v6, a2: v12);
      v8 = v7;
      if ( v7 != nullptr && ((int (__thiscall *)(struct GASObject *))v7[2].pNode[1].pNext)(a1: &v7[2]) == 34 )
      {
        MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fn + 24));
        v10 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(
                              a1: (int)MovieRoot + 8,
                              a2: 35);
        v11 = v10;
        if ( v10 != nullptr )
        {
          GRefCountImpl::Release(this: v10);
          ((void (__thiscall *)(IShaderAPI *, struct GASObject *, CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))v11->SetPixelShaderConstant)(
            a1: v11,
            a2: v8,
            a3: v3);
        }
      }
    }
    else
    {
      v5 = DWORD1(v3[6].m_pfnProxied);
      if ( v5 == 0 )
        GFxASCharacter::CreateCharacterHandle(this: v3);
      GASEnvironment::LogScriptError(
        this: *(GASEnvironment **)(fn + 24),
        a2: "Error: %s.attachAudio() needs one Argument\n",
        **(const char ***)(v5 + 12));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF690
// Name: GFx_SpriteSetMask
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteSetMask(int fn)
{
  GASValue *v1; // edi
  int v2; // ecx
  GPtr<GFxZlibSupportBase> *v3; // edi
  int v4; // eax
  GASValue *v5; // eax
  GPtr<GFxZlibSupportBase> *v6; // eax
  const struct GASEnvironment *v7; // [esp-4h] [ebp-Ch]
  _TAPE_WMI_OPERATIONS *v8; // [esp+0h] [ebp-8h]

  v1 = *(GASValue **)(fn + 4);
  GASValue::DropRefs(this: v1);
  *(_BYTE *)v1 = 0;
  v2 = *(_DWORD *)(fn + 8);
  if ( v2 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2) != 2 )
      return;
    v4 = *(_DWORD *)(fn + 8);
    if ( v4 == 0 )
      return;
    v3 = (GPtr<GFxZlibSupportBase> *)(v4 - 120);
  }
  else
  {
    v3 = *(GPtr<GFxZlibSupportBase> **)(*(_DWORD *)(fn + 24) + 116);
  }
  if ( v3 != nullptr && *(int *)(fn + 28) >= 1 )
  {
    if ( *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0) == 1
      || (v7 = *(const struct GASEnvironment **)(fn + 24),
          v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0),
          GASValue::ToASCharacter(this: v5, a2: v7) == nullptr) )
    {
      GFxSprite::SetMask(this: v3, result: nullptr);
    }
    else
    {
      v6 = (GPtr<GFxZlibSupportBase> *)GASObjectInterface::ToSprite(result: v8);
      GFxSprite::SetMask(this: v3, result: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF720
// Name: public: static void GFxSprite::SpriteSwapDepths(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxSprite::SpriteSwapDepths(int a1@<ebx>, GASFnCall *result)
{
  GString::DataDesc *v3; // ecx
  GString::DataDesc *y; // esi
  GString::DataDesc *v5; // esi
  GASValue *v6; // ebx
  __vc_attributes::idl_moduleAttribute *v7; // eax
  int v8; // edi
  struct GFxASCharacter *TargetByValue; // ebx
  int v10; // ecx
  CMatPaintmaps *v11; // esi
  char v12; // al
  __int128 v13; // [esp-Ch] [ebp-1Ch]
  unsigned int depth2; // [esp+8h] [ebp-8h]
  int v15; // [esp+Ch] [ebp-4h]
  __vc_attributes::idl_moduleAttribute *fn; // [esp+18h] [ebp+8h]

  v3 = (GString::DataDesc *)result[2];
  if ( v3 != nullptr )
  {
    if ( (unsigned int)((*(int (__thiscall **)(GString::DataDesc *))(v3->Size + 8))(a1: v3) - 2) > 3 )
      return;
    v5 = (GString::DataDesc *)result[2];
    if ( v5 == nullptr )
      return;
    y = v5 - 10;
  }
  else
  {
    y = (GString::DataDesc *)result[6][2].ptStart.y;
  }
  if ( y == nullptr || (int)result[7] < 1 )
    return;
  DWORD2(v13) = a1;
  v15 = *(_DWORD *)y[2].Data;
  v6 = (GASValue *)GASFnCall::Arg(this: result, a2: 0);
  v7 = (*(int (__thiscall **)(unsigned int *))(y[10].Size + 8))(a1: &y[10].Size) == 2
     ? (__vc_attributes::idl_moduleAttribute *)y
     : nullptr;
  if ( *(_BYTE *)v6 == 3 || *(_BYTE *)v6 == 4 )
  {
    depth2 = (int)GASValue::ToNumber(this: v6, a2: (struct GASEnvironment *)result[6]) + 0x4000;
    if ( depth2 > 0x7EFFFFFD )
      return;
    v8 = v15;
    TargetByValue = nullptr;
    goto LABEL_19;
  }
  v10 = (int)result[6];
  if ( v7 != nullptr )
  {
    fn = *(__vc_attributes::idl_moduleAttribute **)(v10 + 116);
    GASEnvironment::SetTarget(this: v10, result: v7);
    TargetByValue = GASEnvironment::FindTargetByValue(
                      this: (GASEnvironment *)result[6],
                      path: (__vc_attributes::event_receiverAttribute::type_e)v6);
    GASEnvironment::SetTarget(this: (int)result[6], result: fn);
  }
  else
  {
    TargetByValue = GASEnvironment::FindTargetByValue(
                      this: (GASEnvironment *)v10,
                      path: (__vc_attributes::event_receiverAttribute::type_e)v6);
  }
  if ( TargetByValue != nullptr && TargetByValue != (struct GFxASCharacter *)y )
  {
    v8 = v15;
    if ( v15 == *((_DWORD *)TargetByValue + 8) )
    {
      depth2 = *((_DWORD *)TargetByValue + 5);
LABEL_19:
      if ( *(int *)y[1].Data >= 0 )
      {
        (*(void (__thiscall **)(GString::DataDesc *, _DWORD))(y->Size + 32))(a1: y, a2: 0);
        if ( v8 != 0 )
        {
          v11 = *(CMatPaintmaps **)y[1].Data;
          *(_QWORD *)&v13 = __PAIR64__((*(int (__thiscall **)(int))(*(_DWORD *)v8 + 316))(a1: v8), depth2);
          GFxDisplayList::SwapDepths(
            this: (CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *)(v8 + 196),
            depth1: v11,
            depth2: v13);
          if ( v12 != 0 )
          {
            *(_DWORD *)(*(_DWORD *)(v8 + 188) + 9332) |= 0x400u;
            if ( TargetByValue != nullptr )
              (*(void (__thiscall **)(struct GFxASCharacter *, _DWORD))(*(_DWORD *)TargetByValue + 32))(
                a1: TargetByValue,
                a2: 0);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF880
// Name: GFx_SpriteGetNextHighestDepth
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100AF8F0
// Name: GFx_SpriteGetInstanceAtDepth
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFx_SpriteGetInstanceAtDepth(_CONNECTDLGSTRUCTW fn)
{
  GASValue *v1; // edi
  int v2; // ecx
  int result; // eax
  int v4; // edi
  GASValue *v5; // eax
  int v6; // eax
  struct GASEnvironment *v7; // [esp-4h] [ebp-Ch]

  v1 = *(GASValue **)(fn.cbStructure + 4);
  GASValue::DropRefs(this: v1);
  *(_BYTE *)v1 = 0;
  v2 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v2 != 0 )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( result != 2 )
      return result;
    result = *(_DWORD *)(fn.cbStructure + 8);
    if ( result == 0 )
      return result;
    v4 = result - 120;
  }
  else
  {
    result = *(_DWORD *)(fn.cbStructure + 24);
    v4 = *(_DWORD *)(result + 116);
  }
  if ( v4 != 0 && *(int *)(fn.cbStructure + 28) >= 1 )
  {
    v7 = *(struct GASEnvironment **)(fn.cbStructure + 24);
    v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 0);
    v6 = (int)GASValue::ToNumber(this: v5, a2: v7);
    result = GFxDisplayList::GetDisplayIndex(this: (GFxDisplayList *)(v4 + 196), a2: v6 + 0x4000);
    if ( result != -1 )
    {
      result = *(_DWORD *)(*(_DWORD *)(v4 + 196) + 4 * result);
      if ( result != 0 )
        return (int)GASValue::SetAsCharacter(result: *(_BYTE *)(result + 118) >> 7 != 0 ? (tagBITMAPCOREHEADER *)result : nullptr);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AF990
// Name: public: void GFxSprite::LineTo(float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSprite::LineTo(GFxSprite *this@<ecx>, Vector *a2@<edi>, float a3, float a4)
{
  int v5; // eax
  int (__thiscall *v6)(int, int, int *); // edx
  IClientTools *v7; // eax
  GFxASUserData *v8; // eax
  GFxASUserData *v9; // edi
  GRefCountNTSImpl *v10; // ecx
  QAngle *v11; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h] BYREF
  float x; // [esp+24h] [ebp+Ch]

  if ( *(this + 115) == nullptr )
  {
    v5 = ((int (__thiscall *)(_DWORD))(*(this + 47))->__vftable[30].OnDestroy)(a1: *(this + 47));
    v6 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v5 + 40);
    v12 = 322;
    v7 = (IClientTools *)v6(a1: v5, a2: 136, a3: &v12);
    if ( v7 != nullptr )
    {
      LOBYTE(v8) = GFxDrawingContext::GFxDrawingContext(this: v7, a2, a3: v11, a4: (float *)v12);
      v9 = v8;
    }
    else
    {
      v9 = nullptr;
    }
    v10 = (GRefCountNTSImpl *)*(this + 115);
    if ( v10 != nullptr )
      GRefCountNTSImpl::Release(this: v10);
    *(this + 115) = v9;
  }
  x = 20.0 * a3;
  GFxDrawingContext::LineTo(this: (IClientTools *)*(this + 115), x: (void *)LODWORD(x));
  GFxCharacter::InvalidateHitResult((GFxCharacter *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100AFA30
// Name: public: void GFxSprite::CurveTo(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSprite::CurveTo(GFxValue *this@<ecx>, Vector *a2@<edi>, float cx, int cy, int a5, int aya)
{
  int v7; // ecx
  int (__thiscall *v8)(int, int, int *); // edx
  IClientTools *v9; // eax
  int v10; // eax
  int v11; // edi
  GRefCountNTSImpl *v12; // ecx
  QAngle *v13; // [esp+18h] [ebp-8h]
  int v14; // [esp+1Ch] [ebp-4h] BYREF
  float ay; // [esp+34h] [ebp+14h]

  if ( *((_DWORD *)this + 115) == 0 )
  {
    v7 = *(_DWORD *)(*((_DWORD *)this + 47) + 32);
    v8 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v7 + 40);
    v14 = 322;
    v9 = (IClientTools *)v8(a1: v7, a2: 136, a3: &v14);
    if ( v9 != nullptr )
    {
      LOBYTE(v10) = GFxDrawingContext::GFxDrawingContext(this: v9, a2, a3: v13, a4: (float *)v14);
      v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    v12 = *((GRefCountNTSImpl **)this + 115);
    if ( v12 != nullptr )
      GRefCountNTSImpl::Release(this: v12);
    *((_DWORD *)this + 115) = v11;
  }
  ay = 20.0 * cx;
  GFxDrawingContext::CurveTo(this: *((IClientTools **)this + 115), cx: (const char *)LODWORD(ay));
  GFxCharacter::InvalidateHitResult((GFxCharacter *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100AFAF0
// Name: public: bool GFxSprite::AcquirePath(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSprite::AcquirePath(GFxValue *this@<ecx>, Vector *a2@<edi>, unsigned __int16 newShapeFlag)
{
  int v4; // ecx
  int (__thiscall *v5)(int, int, int *); // edx
  IClientTools *v6; // eax
  int v7; // eax
  int v8; // edi
  GRefCountNTSImpl *v9; // ecx
  QAngle *v10; // [esp+0h] [ebp-8h]
  int v11; // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 115) == 0 )
  {
    v4 = *(_DWORD *)(*((_DWORD *)this + 47) + 32);
    v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
    v11 = 322;
    v6 = (IClientTools *)v5(a1: v4, a2: 136, a3: &v11);
    if ( v6 != nullptr )
    {
      LOBYTE(v7) = GFxDrawingContext::GFxDrawingContext(this: v6, a2, a3: v10, a4: (float *)v11);
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    v9 = *((GRefCountNTSImpl **)this + 115);
    if ( v9 != nullptr )
      GRefCountNTSImpl::Release(this: v9);
    *((_DWORD *)this + 115) = v8;
  }
  *(_DWORD *)(*((_DWORD *)this + 47) + 9332) |= 0x400u;
  GFxCharacter::InvalidateHitResult((GFxCharacter *)this);
  GFxDrawingContext::AcquirePath(this: *((IClientTools **)this + 115), newShapeFlag);
}

//------------------------------------------------------------------------------
// Address: 0x100AFB80
// Name: public: virtual void GFxSprite::SetStateChangeFlags(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetStateChangeFlags(GFxSprite *this, int flags)
{
  unsigned int v3; // ebx
  unsigned int i; // esi
  int v5; // ecx

  v3 = (unsigned int)*(this + 50);
  *(this + 40) = (GFxSprite)(((unsigned int)*(this + 40)
                            ^ ((unsigned __int8)flags << 16))
                           & 0x30000
                           ^ (unsigned int)*(this + 40));
  for ( i = 0; i < v3; ++i )
  {
    v5 = *((_DWORD *)&(*(this + 49))->__vftable + i);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 184))(a1: v5, a2: flags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AFBE0
// Name: public: class GFxSprite __near * GFxSprite::GetHitArea(void)const
// Source: json
//------------------------------------------------------------------------------
_TAPE_WMI_OPERATIONS *__thiscall GFxSprite::GetHitArea(GFxSprite *this, _TAPE_WMI_OPERATIONS *a2)
{
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v3; // ecx
  int v4; // eax

  v3 = (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)*(this + 117);
  if ( v3 != nullptr && (GFxCharacterHandle::ResolveCharacter(this: v3, a2: (GFxMovieRoot *)*(this + 47)), v4 != 0) )
    return GASObjectInterface::ToSprite(result: a2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100AFC10
// Name: GFx_SpriteClear
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteClear(int fn)
{
  int v1; // ecx
  GFxCharacter *v2; // esi
  int v3; // eax
  IClientTools *v4; // ecx
  CBaseHandle v5; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h]

  v1 = *(_DWORD *)(fn + 8);
  if ( v1 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1) != 2 )
      return;
    v3 = *(_DWORD *)(fn + 8);
    if ( v3 == 0 )
      return;
    v2 = (GFxCharacter *)(v3 - 120);
  }
  else
  {
    v2 = *(GFxCharacter **)(*(_DWORD *)(fn + 24) + 116);
  }
  if ( v2 != nullptr )
  {
    v4 = *((IClientTools **)v2 + 115);
    if ( v4 != nullptr )
      GFxDrawingContext::Clear(this: v4, a2: v5, a3: savedregs);
    GFxCharacter::InvalidateHitResult(this: v2);
    *(_DWORD *)(*((_DWORD *)v2 + 47) + 9332) |= 0x400u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AFC70
// Name: GFx_SpriteLineTo
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteLineTo(GASFnCall *y)
{
  GASFnCall v1; // ecx
  GFxSprite *v2; // edi
  GASFnCall v3; // eax
  GASValue *v4; // eax
  GASValue *v5; // eax
  struct GASEnvironment *v6; // [esp+4h] [ebp-10h]
  struct GASEnvironment *v7; // [esp+4h] [ebp-10h]
  float x; // [esp+10h] [ebp-4h]
  float ya; // [esp+1Ch] [ebp+8h]

  v1 = y[2];
  if ( v1 != nullptr )
  {
    if ( (*(int (__thiscall **)(GASFnCall))(v1->cbSize + 8))(a1: v1) != 2 )
      return;
    v3 = y[2];
    if ( v3 == nullptr )
      return;
    v2 = (GFxSprite *)&v3[-3];
  }
  else
  {
    v2 = (GFxSprite *)y[6][2].ptStart.y;
  }
  if ( v2 != nullptr && (int)y[7] >= 2 )
  {
    v6 = (struct GASEnvironment *)y[6];
    v4 = (GASValue *)GASFnCall::Arg(this: y, a2: 0);
    x = GASValue::ToNumber(this: v4, a2: v6);
    v7 = (struct GASEnvironment *)y[6];
    v5 = (GASValue *)GASFnCall::Arg(this: y, a2: 1);
    ya = GASValue::ToNumber(this: v5, a2: v7);
    GFxSprite::LineTo(this: v2, a2: (Vector *)v2, a3: x, a4: ya);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AFD00
// Name: GFx_SpriteCurveTo
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteCurveTo(GASFnCall *ay)
{
  GASFnCall v1; // ecx
  GFxValue *y; // edi
  GASFnCall v3; // eax
  GASValue *v4; // eax
  GASValue *v5; // eax
  GASValue *v6; // eax
  GASValue *v7; // eax
  struct GASEnvironment *v8; // [esp+Ch] [ebp-18h]
  struct GASEnvironment *v9; // [esp+Ch] [ebp-18h]
  struct GASEnvironment *v10; // [esp+Ch] [ebp-18h]
  struct GASEnvironment *v11; // [esp+Ch] [ebp-18h]
  float v12; // [esp+18h] [ebp-Ch]
  int cy; // [esp+1Ch] [ebp-8h]
  int v14; // [esp+20h] [ebp-4h]
  int aya; // [esp+2Ch] [ebp+8h]

  v1 = ay[2];
  if ( v1 != nullptr )
  {
    if ( (*(int (__thiscall **)(GASFnCall))(v1->cbSize + 8))(a1: v1) != 2 )
      return;
    v3 = ay[2];
    if ( v3 == nullptr )
      return;
    y = (GFxValue *)&v3[-3];
  }
  else
  {
    y = (GFxValue *)ay[6][2].ptStart.y;
  }
  if ( y != nullptr && (int)ay[7] >= 4 )
  {
    v8 = (struct GASEnvironment *)ay[6];
    v4 = (GASValue *)GASFnCall::Arg(this: ay, a2: 0);
    v12 = GASValue::ToNumber(this: v4, a2: v8);
    v9 = (struct GASEnvironment *)ay[6];
    v5 = (GASValue *)GASFnCall::Arg(this: ay, a2: 1);
    *(float *)&cy = GASValue::ToNumber(this: v5, a2: v9);
    v10 = (struct GASEnvironment *)ay[6];
    v6 = (GASValue *)GASFnCall::Arg(this: ay, a2: 2);
    *(float *)&v14 = GASValue::ToNumber(this: v6, a2: v10);
    v11 = (struct GASEnvironment *)ay[6];
    v7 = (GASValue *)GASFnCall::Arg(this: ay, a2: 3);
    *(float *)&aya = GASValue::ToNumber(this: v7, a2: v11);
    GFxSprite::CurveTo(this: y, a2: (Vector *)y, cx: v12, cy, a5: v14, aya);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AFDE0
// Name: _GASMovieClipObject::Set__proto___::_5_::MemberVisitor::Visit
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASMovieClipObject::Set__proto___::_5_::MemberVisitor::Visit(
        struct GASStringContext **this,
        struct GASString *a2,
        int a3,
        int a4)
{
  int result; // eax
  int v5; // edx

  result = GASMovieClipObject::GetButtonEventNameMask(a1: *(this + 2), a2);
  if ( (_WORD)result != 0 )
    *(_BYTE *)(*(_DWORD *)(v5 + 4) + 58) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AFE10
// Name: public: bool GASMovieClipObject::ActsAsButton(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASMovieClipObject::ActsAsButton(GFxValue::ObjectInterface *this)
{
  GFxValue::ObjectInterface *v1; // esi
  struct GFxMovieRoot *i; // edi

  v1 = this;
  if ( *((_WORD *)this + 28) == 0 )
  {
    while ( 2 )
    {
      if ( BYTE2(v1[14].pMovieRoot) == 0 )
      {
        for ( i = v1[6].pMovieRoot; ; i = *((struct GFxMovieRoot **)i + 6) )
        {
          if ( i == nullptr )
            return 0;
          if ( (*(int (__thiscall **)(int))(*((_DWORD *)v1[6].pMovieRoot + 4) + 8))(a1: (int)v1[6].pMovieRoot + 16) == 11 )
            break;
        }
        v1 = (GFxValue::ObjectInterface *)i;
        if ( *((_WORD *)i + 28) == 0 )
          continue;
      }
      break;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B0120
// Name: unsigned int G_UpperBoundSliced<class GArrayDH_POD<struct GFxTimelineSnapshot::SnapshotElement __near *,2,struct GArrayDefaultPolicy>,int,int (*)(int,struct GFxTimelineSnapshot::SnapshotElement const __near *)>(class GArrayDH_POD<struct GFxTimelineSnapshot::SnapshotElement __near *,2,struct GArrayDefaultPolicy> const __near &,unsigned int,unsigned int,int const __near &,int (*)(int,struct GFxTimelineSnapshot::SnapshotElement const __near *))
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_UpperBoundSliced<GArrayDH_POD<GFxTimelineSnapshot::SnapshotElement *,2,GArrayDefaultPolicy>,int,int (__cdecl *)(int,GFxTimelineSnapshot::SnapshotElement const *)>(
        _DWORD *a1,
        int a2,
        int a3,
        _DWORD *a4,
        int (__cdecl *a5)(_DWORD, _DWORD))
{
  int result; // eax
  int i; // edi
  int v7; // ebx

  result = a2;
  for ( i = a3 - a2; i > 0; result = a2 )
  {
    v7 = (i >> 1) + result;
    if ( a5(a1: *a4, a2: *(_DWORD *)(*a1 + 4 * v7)) != 0 )
    {
      i >>= 1;
    }
    else
    {
      a2 = v7 + 1;
      i += -1 - (i >> 1);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B01A0
// Name: public: virtual class GRect<float> GFxSprite::GetFocusRect(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
float *__thiscall GFxSprite::GetFocusRect(void *this, float *a2)
{
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v3; // ecx
  int v4; // eax
  float *v5; // esi
  _TAPE_WMI_OPERATIONS *v7; // [esp+0h] [ebp-40h]
  float v8[2]; // [esp+Ch] [ebp-34h] BYREF
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> haRect; // [esp+14h] [ebp-2Ch] BYREF
  float v10[6]; // [esp+24h] [ebp-1Ch] BYREF

  v3 = *((CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this
       + 117);
  if ( v3 != nullptr && (GFxCharacterHandle::ResolveCharacter(this: v3, a2: *((GFxMovieRoot **)this + 47)), v4 != 0) )
    v5 = (float *)GASObjectInterface::ToSprite(result: v7);
  else
    v5 = nullptr;
  GMatrix2D::SetIdentity(this: v10);
  if ( v5 != nullptr )
  {
    v10[0] = v5[17];
    v10[1] = v5[18];
    v10[2] = v5[19];
    v10[3] = v5[20];
    v10[4] = v5[21];
    v10[5] = v5[22];
    (*(void (__thiscall **)(float *, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *))(*(_DWORD *)v5 + 244))(
      a1: v5,
      a2: &haRect);
    *a2 = 0.0;
    a2[1] = 0.0;
    a2[2] = 0.0;
    a2[3] = 0.0;
    GMatrix2D::EncloseTransform(this: v10, a2, a3: (float *)&haRect);
  }
  else
  {
    GMatrix2D::SetIdentity(this: v8);
    (*(void (__thiscall **)(void *, float *, float *))(*(_DWORD *)this + 52))(a1: this, a2, a3: v8);
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100B02E0
// Name: public: void GFxSprite::ExecuteFrameTags(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::ExecuteFrameTags(GPtr<GFxZlibSupportBase> *this, GFxZlibSupportBase *frame)
{
  int v3; // eax
  unsigned int v4; // eax
  GRefCountNTSImpl *v5; // ecx
  unsigned int i; // esi
  int v7; // [esp+8h] [ebp-8h] BYREF
  unsigned int v8; // [esp+Ch] [ebp-4h]

  if ( this != nullptr )
    ++*((_DWORD *)this + 1);
  v3 = *((_DWORD *)this + 112);
  if ( v3 == 0 || *(_BYTE *)(v3 + 24) != 0 )
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 46) + 40))(a1: *((_DWORD *)this + 46));
  else
    v4 = *(_DWORD *)(v3 + 16);
  v5 = (GRefCountNTSImpl *)this;
  if ( (unsigned int)frame < v4 )
  {
    GFxSprite::ExecuteInitActionFrameTags(this, frame);
    (*(void (__thiscall **)(_DWORD, int *, GFxZlibSupportBase *))(**((_DWORD **)this + 46) + 44))(
      a1: *((_DWORD *)this + 46),
      a2: &v7,
      a3: frame);
    for ( i = 0; i < v8; ++i )
      (*(void (__thiscall **)(_DWORD, GPtr<GFxZlibSupportBase> *, int))(**(_DWORD **)(v7 + 4 * i) + 8))(
        a1: *(_DWORD *)(v7 + 4 * i),
        a2: this,
        a3: 4);
    v5 = (GRefCountNTSImpl *)this;
  }
  GRefCountNTSImpl::Release(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100B0370
// Name: public: bool GFxSprite::GotoLabeledFrame(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::GotoLabeledFrame(
        GPtr<GFxZlibSupportBase> *this,
        const GPtr<GFxZlibSupportBase> *label,
        int offset)
{
  int v4; // ecx
  int v6; // eax
  unsigned int targetFrame; // [esp+8h] [ebp-4h] BYREF

  v4 = *((_DWORD *)this + 46);
  targetFrame = -1;
  if ( (*(unsigned __int8 (__thiscall **)(int, const GPtr<GFxZlibSupportBase> *, unsigned int *, _DWORD))(*(_DWORD *)v4 + 52))(
         a1: v4,
         a2: label,
         a3: &targetFrame,
         a4: 0) != 0 )
  {
    ((void (__thiscall *)(GPtr<GFxZlibSupportBase> *, unsigned int))this->pObject[27].__vftable)(
      a1: this,
      a2: offset + targetFrame);
    return 1;
  }
  else
  {
    v6 = *((_DWORD *)this + 37);
    if ( v6 == 0 )
      GFxASCharacter::CreateCharacterHandle((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this);
    GFxLogBase<GFxCharacter>::LogWarning(
      a1: (int)(this + 3),
      a2: (int)"Error: %s, MovieImpl::GotoLabeledFrame('%s') unknown label\n",
      **(const char ***)(v6 + 12),
      (const char *)label);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B03F0
// Name: GFx_InitObjectMembers
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_InitObjectMembers(int fn)
{
  _TAPE_WMI_OPERATIONS *v1; // eax
  GRefCountNTSImpl *v2; // esi
  _SERVICE_STATUS *v3; // eax
  _SERVICE_STATUS *v4; // [esp-4h] [ebp-18h]
  _TAPE_WMI_OPERATIONS *v5; // [esp+0h] [ebp-14h]
  void **v6; // [esp+8h] [ebp-Ch] BYREF
  int v7; // [esp+Ch] [ebp-8h]
  GRefCountNTSImpl *v8; // [esp+10h] [ebp-4h]

  v1 = GASObjectInterface::ToSprite(result: v5);
  v2 = (GRefCountNTSImpl *)v1;
  if ( v1 != nullptr )
    ++v1->DataBufferSize;
  v4 = *(_SERVICE_STATUS **)(fn + 24);
  GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
  v3 = GASValue::ToObjectInterface(result: v4);
  v7 = *(_DWORD *)(fn + 24);
  v6 = (void **)&`GFx_InitObjectMembers'::`2'::InitVisitor::`vftable';
  v8 = v2;
  (*(void (__thiscall **)(_SERVICE_STATUS *, int, void ***, _DWORD, _DWORD))(v3->dwServiceType + 32))(
    a1: v3,
    a2: v7 + 120,
    a3: &v6,
    a4: 0,
    a5: 0);
  v6 = &GString::InitStruct::`vftable';
  if ( v2 != nullptr )
    GRefCountNTSImpl::Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100B0460
// Name: public: virtual int GFxSprite::CheckAdvanceStatus(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSprite::CheckAdvanceStatus(GFxSprite *this, bool a2)
{
  char v2; // bl
  int v3; // eax
  int result; // eax
  bool v5; // zf
  int v6; // [esp+8h] [ebp-10h] BYREF
  int v7; // [esp+Ch] [ebp-Ch]
  __int16 v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+12h] [ebp-6h]

  if ( (*(_BYTE *)(this + 40) & 0xC) != 0 || (*((_BYTE *)this + 118) & 0x40) != 0 )
  {
    v2 = 1;
  }
  else
  {
    v2 = 0;
    if ( *(this + 53) == nullptr )
      return !a2;
    if ( (GFxSprite *)(*(this + 47))[574].RefCount == this )
      return !a2;
    v3 = (int)*(this + 114);
    if ( v3 != 0 && *(_DWORD *)(v3 + 16) != 0 )
      return !a2;
  }
  if ( a2 )
  {
    if ( v2 != 0 )
      return -1;
    v7 = 0;
    v6 = 2;
    v8 = 0;
    v9 = 65280;
    if ( GFxSprite::HasEventHandler(this, a2: (const struct GFxEventId *)&v6) == 0 )
      return -1;
  }
  else if ( v2 == 0 )
  {
    v7 = 0;
    v6 = 2;
    v8 = 0;
    v9 = 65280;
    v5 = GFxSprite::HasEventHandler(this, a2: (const struct GFxEventId *)&v6) == 0;
    result = 1;
    if ( !v5 )
      return result;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B0530
// Name: public: void GFxSprite::ReplaceDisplayObject(class GFxCharPosInfo const __near &,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::ReplaceDisplayObject(GMemoryFile *this, _IMAGE_SYMBOL_EX *name, int a3)
{
  int v4; // eax
  int Type; // edi
  GRefCountNTSImpl *v6; // edi
  int rid[2]; // [esp+Ch] [ebp-8h] BYREF

  GFxMovieDefImpl::GetCharacterCreateInfo(
    this: *((CMatQueuedIndexBuffer **)this + 36),
    (_RATE_QUOTA_LIMIT *)rid,
    rh: *(const IndexDesc_t **)&name[3].Type);
  if ( rid[0] != 0 )
  {
    v6 = (GRefCountNTSImpl *)(*(int (__thiscall **)(int, GMemoryFile *, _DWORD, int))(*(_DWORD *)rid[0] + 36))(
                               a1: rid[0],
                               a2: this,
                               a3: *(_DWORD *)&name[3].Type,
                               a4: rid[1]);
    GFxSprite::ReplaceDisplayObject(this, a2: (int)this, name, a4: (int)v6, a5: a3);
    v6[3].__vftable = *((GRefCountNTSImpl_vtbl **)this + 54);
    GRefCountNTSImpl::Release(this: v6);
  }
  else
  {
    v4 = *((_DWORD *)this + 37);
    Type = name[3].Type;
    if ( v4 == 0 )
      GFxASCharacter::CreateCharacterHandle((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this);
    GFxLogBase<GFxCharacter>::LogError(
      a1: (int)&this->FileData,
      a2: (int)"%s, Sprite::ReplaceDisplayObject(): unknown cid = %d\n",
      **(const char ***)(v4 + 12),
      Type);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B05D0
// Name: public: virtual void GFxSprite::CallFrameActions(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::CallFrameActions(GPtr<GFxZlibSupportBase> *this, GFxZlibSupportBase *frameNumber)
{
  GFxZlibSupportBase *v2; // edi
  int v4; // eax
  unsigned int v5; // eax
  unsigned int started; // eax
  int v7; // ecx
  void (__thiscall *v8)(int, int *, GFxZlibSupportBase *); // edx
  unsigned int i; // ebx
  int v10; // edi
  unsigned int v11; // eax
  int v12; // eax
  int v13; // [esp+8h] [ebp-Ch] BYREF
  unsigned int v14; // [esp+Ch] [ebp-8h]
  unsigned int aqCurSession; // [esp+10h] [ebp-4h]

  v2 = frameNumber;
  if ( frameNumber == (GFxZlibSupportBase *)-1
    || ((v4 = *((_DWORD *)this + 112)) == 0 || *(_BYTE *)(v4 + 24) != 0
      ? (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 46) + 40))(a1: *((_DWORD *)this + 46)))
      : (v5 = *(_DWORD *)(v4 + 16)),
        (unsigned int)v2 >= v5) )
  {
    v12 = *((_DWORD *)this + 37);
    if ( v12 == 0 )
      GFxASCharacter::CreateCharacterHandle((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this);
    GFxLogBase<GFxCharacter>::LogError(
      a1: (int)(this + 3),
      a2: (int)"Error: %s, CallFrame('%d') - unknown frame\n",
      **(const char ***)(v12 + 12),
      v2);
  }
  else
  {
    started = GFxMovieRoot::ActionQueueType::StartNewSession(
                this: (GFxMovieRoot::ActionQueueType *)(*((_DWORD *)this + 47) + 9224),
                a2: (unsigned int *)&frameNumber);
    v7 = *((_DWORD *)this + 46);
    v8 = *(void (__thiscall **)(int, int *, GFxZlibSupportBase *))(*(_DWORD *)v7 + 44);
    aqCurSession = started;
    v8(a1: v7, a2: &v13, a3: v2);
    for ( i = 0; i < v14; ++i )
    {
      v10 = *(_DWORD *)(v13 + 4 * i);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 16))(a1: v10) != 0 )
        (*(void (__thiscall **)(int, GPtr<GFxZlibSupportBase> *))(*(_DWORD *)v10 + 4))(a1: v10, a2: this);
    }
    v11 = aqCurSession;
    *(_DWORD *)(*((_DWORD *)this + 47) + 9304) = frameNumber;
    GFxMovieRoot::DoActionsForSession(this: *((GFxMovieRoot **)this + 47), a2: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B06C0
// Name: public: bool GFxSprite::Invoke(char const __near *,class GASValue __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::Invoke(GFxSprite *this, _IMAGE_SYMBOL_EX::<unnamed_type_N> varname, unsigned int a3)
{
  GFxSprite *v4; // ecx
  char v5; // bl
  _IMAGE_SYMBOL_EX v7; // [esp-18h] [ebp-20h]

  if ( this != nullptr )
  {
    *(this + 1) = (GFxSprite)((char *)*(this + 1) + 1);
    v4 = this + 30;
  }
  else
  {
    v4 = nullptr;
  }
  *(_DWORD *)&v7.Type = a3;
  v7.SectionNumber = (int)(this + 58);
  v7.Value = (unsigned int)v4;
  v7.N = varname;
  v5 = GAS_Invoke(varname: v7, a2: *(this + 60) - *(this + 61) + 32 * (_DWORD)*(this + 65) - 32);
  if ( this != nullptr )
    GRefCountNTSImpl::Release((GRefCountNTSImpl *)this);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100B0730
// Name: public: bool GFxSprite::ActsAsButton(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::ActsAsButton(GFxSprite *this)
{
  GFxValue::ObjectInterface *v1; // ecx

  if ( (int)*(this + 111) < 0
    && ((unsigned int)*(this + 40) & 0x10) != 0
    && (*(this + 113) == nullptr
      ? (v1 = (GFxValue::ObjectInterface *)*(this + 32))
      : (v1 = (GFxValue::ObjectInterface *)*(this + 113)),
        v1 != nullptr) )
  {
    return GASMovieClipObject::ActsAsButton(this: v1);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0770
// Name: public: virtual bool GFxSprite::IsTabable(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GFxSprite::IsTabable(GFxSprite *this)
{
  unsigned __int8 result; // al
  int v3; // ebx
  char v4; // bl
  unsigned __int8 v6; // bl
  GFxValue::ObjectInterface *v7; // ecx
  GASValue v8[4]; // [esp+4h] [ebp-14h] BYREF
  struct GASStringNode *ConstStringNode; // [esp+14h] [ebp-4h] BYREF

  result = ((int (__thiscall *)(GFxSprite *))(*this)[1].__vftable)(a1: this);
  if ( result != 0 )
  {
    if ( ((unsigned int)*(this + 40) & 0x60) != 0 )
    {
      return ((unsigned int)*(this + 40) & 0x60) == 96;
    }
    else
    {
      v3 = (int)*(this + 32);
      if ( v3 != 0 )
      {
        LOBYTE(v8[0]) = 0;
        ConstStringNode = GASStringManager::CreateConstStringNode(
                            this: (GASStringManager *)(*(this + 88))[39].pData,
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E410.m_Size,
                            a3: 0xAu,
                            a4: 0);
        ++*((_DWORD *)ConstStringNode + 2);
        v4 = (*(int (__thiscall **)(int, GFxSprite *, struct GASStringNode **, GASValue *))(*(_DWORD *)(v3 + 16) + 44))(
               a1: v3 + 16,
               a2: this + 88,
               a3: &ConstStringNode,
               a4: v8);
        if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
          GASStringNode::ReleaseNode();
        if ( v4 != 0 && LOBYTE(v8[0]) != 0 && LOBYTE(v8[0]) != 10 )
        {
          v6 = (unsigned __int8)GASValue::ToBool(result: (tagPOLYTEXTW *)(this + 58));
          GASValue::~GASValue(this: v8);
          return v6;
        }
        GASValue::~GASValue(this: v8);
      }
      return (int)*(this + 111) < 0
          && ((unsigned int)*(this + 40) & 0x10) != 0
          && ((v7 = (GFxValue::ObjectInterface *)*(this + 113)) != nullptr
           || (v7 = (GFxValue::ObjectInterface *)*(this + 32)) != nullptr)
          && GASMovieClipObject::ActsAsButton(this: v7) != 0
          || *((__int16 *)this + 82) > 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B0890
// Name: public: virtual bool GFxSprite::IsFocusEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::IsFocusEnabled(GFxSprite *this)
{
  char v2; // al
  int v3; // ebx
  char v4; // bl
  unsigned __int8 v6; // bl
  GFxValue::ObjectInterface *v8; // esi
  GFxValue::ObjectInterface *v9; // esi
  GASValue v10[4]; // [esp+4h] [ebp-14h] BYREF
  struct GASStringNode *ConstStringNode; // [esp+14h] [ebp-4h] BYREF

  v2 = *((_BYTE *)this + 481);
  if ( v2 != 0 )
  {
    if ( v2 == 2 )
    {
      if ( (int)*(this + 111) < 0
        && ((unsigned int)*(this + 40) & 0x10) != 0
        && (*(this + 113) == nullptr
          ? (v9 = (GFxValue::ObjectInterface *)*(this + 32))
          : (v9 = (GFxValue::ObjectInterface *)*(this + 113)),
            v9 != nullptr) )
      {
        return GASMovieClipObject::ActsAsButton(this: v9);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return v2 == 1;
    }
  }
  else
  {
    v3 = (int)*(this + 32);
    if ( v3 != 0 )
    {
      LOBYTE(v10[0]) = 0;
      ConstStringNode = GASStringManager::CreateConstStringNode(
                          this: (GASStringManager *)(*(this + 88))[39].pData,
                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E3DC.m_Size,
                          a3: 0xCu,
                          a4: 0);
      ++*((_DWORD *)ConstStringNode + 2);
      v4 = (*(int (__thiscall **)(int, GFxSprite *, struct GASStringNode **, GASValue *))(*(_DWORD *)(v3 + 16) + 44))(
             a1: v3 + 16,
             a2: this + 88,
             a3: &ConstStringNode,
             a4: v10);
      if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
        GASStringNode::ReleaseNode();
      if ( v4 != 0 && LOBYTE(v10[0]) != 0 && LOBYTE(v10[0]) != 10 )
      {
        v6 = (unsigned __int8)GASValue::ToBool(result: (tagPOLYTEXTW *)(this + 58));
        GASValue::~GASValue(this: v10);
        return v6;
      }
      GASValue::~GASValue(this: v10);
    }
    if ( (int)*(this + 111) < 0
      && ((unsigned int)*(this + 40) & 0x10) != 0
      && (*(this + 113) == nullptr
        ? (v8 = (GFxValue::ObjectInterface *)*(this + 32))
        : (v8 = (GFxValue::ObjectInterface *)*(this + 113)),
          v8 != nullptr) )
    {
      return GASMovieClipObject::ActsAsButton(this: v8);
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B09E0
// Name: public: virtual void GFxSprite::OnGettingKeyboardFocus(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::OnGettingKeyboardFocus(GPtr<GFxZlibSupportBase> *this, GFxZlibSupportBase *__formal)
{
  GFxValue::ObjectInterface *v3; // ecx
  GFxZlibSupportBase_vtbl *v4; // edx
  _DWORD v5[2]; // [esp+8h] [ebp-10h] BYREF
  __int16 v6; // [esp+10h] [ebp-8h]
  int v7; // [esp+12h] [ebp-6h]

  if ( *((int *)this + 111) < 0 && (*(_DWORD *)(this + 40) & 0x10) != 0 )
  {
    v3 = *((GFxValue::ObjectInterface **)this + 113);
    if ( (v3 != nullptr || (v3 = *((GFxValue::ObjectInterface **)this + 32)) != nullptr)
      && GASMovieClipObject::ActsAsButton(this: v3) != 0
      && ((*(_DWORD *)(((int (__thiscall *)(GPtr<GFxZlibSupportBase> *))this->pObject[7].__vftable)(a1: this) + 9332) >> 28)
        & 3) != 1 )
    {
      v4 = this->pObject[22].__vftable;
      v6 = 0;
      v5[0] = 0x2000;
      v5[1] = 0;
      v7 = 65280;
      ((void (__thiscall *)(GPtr<GFxZlibSupportBase> *, _DWORD *))v4)(a1: this, a2: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0A70
// Name: public: virtual bool GFxSprite::OnLosingKeyboardFocus(class GFxASCharacter __near *,unsigned int,enum GFxFocusMovedType)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::OnLosingKeyboardFocus(GFxValue::ObjectInterface **this, int a2, int a3, int a4)
{
  GFxValue::ObjectInterface *v5; // ecx
  int v6; // eax
  struct GFxMovieRoot *pMovieRoot; // edx
  _DWORD v9[2]; // [esp+8h] [ebp-10h] BYREF
  __int16 v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+12h] [ebp-6h]

  if ( (int)*(this + 111) < 0 && ((unsigned int)*(this + 40) & 0x10) != 0 )
  {
    v5 = *(this + 113);
    if ( (v5 != nullptr || (v5 = *(this + 32)) != nullptr) && GASMovieClipObject::ActsAsButton(this: v5) != 0 )
    {
      v6 = ((int (__thiscall *)(GFxValue::ObjectInterface **))(*this)[21].pMovieRoot)(a1: this);
      if ( *(_BYTE *)(52 * *(unsigned __int8 *)(v6 + a3 + 10228) + v6 + 9440) != 0
        && ((*(_DWORD *)(((int (__thiscall *)(GFxValue::ObjectInterface **))(*this)[21].pMovieRoot)(a1: this) + 9332) >> 28)
          & 3) != 1 )
      {
        pMovieRoot = (*this)[66].pMovieRoot;
        v10 = 0;
        v9[0] = 0x4000;
        v9[1] = 0;
        v11 = 65280;
        ((void (__thiscall *)(GFxValue::ObjectInterface **, _DWORD *))pMovieRoot)(a1: this, a2: v9);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B0B30
// Name: public: virtual unsigned int GFxSprite::GetCursorType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSprite::GetCursorType(GFxValue::ObjectInterface **this)
{
  GFxValue::ObjectInterface *v2; // ecx
  tagPOLYTEXTW *v3; // edi
  GASValue val[4]; // [esp+4h] [ebp-10h] BYREF

  if ( (int)*(this + 111) >= 0 )
    return 0;
  if ( ((unsigned int)*(this + 40) & 0x10) == 0 )
    return 0;
  v2 = *(this + 113);
  if ( v2 == nullptr )
  {
    v2 = *(this + 32);
    if ( v2 == nullptr )
      return 0;
  }
  if ( GASMovieClipObject::ActsAsButton(this: v2) == 0 )
    return 0;
  v3 = (tagPOLYTEXTW *)((int (__thiscall *)(GFxValue::ObjectInterface **))(*this)[27].pMovieRoot)(a1: this);
  LOBYTE(val[0]) = 0;
  if ( ((unsigned __int8 (__thiscall *)(GFxValue::ObjectInterface **, tagPOLYTEXTW *, int, GASValue *))(*(this + 30))[11].pMovieRoot)(
         a1: this + 30,
         a2: v3 + 3,
         a3: v3[3].x + 520,
         a4: val) == 0
    || LOBYTE(val[0]) != 0 && LOBYTE(val[0]) != 10 && (unsigned __int8)GASValue::ToBool(result: v3) != 0 )
  {
    GASValue::~GASValue(this: val);
    return 1;
  }
  else
  {
    GASValue::~GASValue(this: val);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0BF0
// Name: GFx_SpriteGotoAndPlay
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GFx_SpriteGotoAndPlay(unsigned int targetFrame)
{
  unsigned int v1; // edi
  int v2; // ecx
  char *result; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v4; // esi
  int v5; // eax
  GASValue *v6; // ecx
  struct GASEnvironment *v7; // eax
  bool v8; // zf
  unsigned int v9; // eax
  char *v10; // [esp+8h] [ebp-4h] BYREF

  v1 = targetFrame;
  v2 = *(_DWORD *)(targetFrame + 8);
  if ( v2 != 0 )
  {
    result = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( result != (char *)2 )
      return result;
    result = *(char **)(v1 + 8);
    if ( result == nullptr )
      return result;
    v4 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)(result - 120);
  }
  else
  {
    result = *(char **)(targetFrame + 24);
    v4 = *((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)result
         + 29);
  }
  if ( v4 == nullptr )
    return result;
  if ( *(int *)(v1 + 28) < 1 )
  {
    v5 = DWORD1(v4[6].m_pfnProxied);
    if ( v5 == 0 )
      GFxASCharacter::CreateCharacterHandle(this: v4);
    return (char *)GFxLogBase<GFxCharacter>::LogScriptError(
                     a1: (int)&v4->m_pfnProxied + 12,
                     a2: (int)"Error: %s, GFx_SpriteGotoAndPlay needs one arg\n",
                     **(const char ***)(v5 + 12));
  }
  v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 0);
  v7 = *(struct GASEnvironment **)(v1 + 24);
  targetFrame = -1;
  if ( *(_BYTE *)v6 != 5 )
  {
    v9 = GASValue::ToUInt32(this: v6, a2: v7) - 1;
    targetFrame = v9;
LABEL_18:
    (*(void (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *, unsigned int))(LODWORD(v4->m_pfnProxied) + 324))(
      a1: v4,
      a2: v9);
    return (char *)(*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *, _DWORD))(LODWORD(v4->m_pfnProxied) + 328))(
                     a1: v4,
                     a2: 0);
  }
  GASValue::ToStringImpl(a1: v6, a2: &v10, a3: v7, a4: -1, a5: 0);
  v8 = (*(unsigned __int8 (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *, _DWORD, unsigned int *, int))(LODWORD(v4->m_pfnProxied) + 320))(
         a1: v4,
         a2: *(_DWORD *)v10,
         a3: &targetFrame,
         a4: 1) == 0;
  result = v10;
  if ( !v8 )
  {
    v8 = (*((_DWORD *)v10 + 2))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode();
    v9 = targetFrame;
    goto LABEL_18;
  }
  v8 = (*((_DWORD *)v10 + 2))-- == 1;
  if ( v8 )
    return (char *)GASStringNode::ReleaseNode().Sid;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B0D00
// Name: GFx_SpriteGotoAndStop
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GFx_SpriteGotoAndStop(unsigned int targetFrame)
{
  unsigned int v1; // edi
  int v2; // ecx
  char *result; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v4; // esi
  int v5; // eax
  GASValue *v6; // ecx
  struct GASEnvironment *v7; // eax
  bool v8; // zf
  unsigned int v9; // eax
  char *v10; // [esp+8h] [ebp-4h] BYREF

  v1 = targetFrame;
  v2 = *(_DWORD *)(targetFrame + 8);
  if ( v2 != 0 )
  {
    result = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( result != (char *)2 )
      return result;
    result = *(char **)(v1 + 8);
    if ( result == nullptr )
      return result;
    v4 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)(result - 120);
  }
  else
  {
    result = *(char **)(targetFrame + 24);
    v4 = *((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)result
         + 29);
  }
  if ( v4 == nullptr )
    return result;
  if ( *(int *)(v1 + 28) < 1 )
  {
    v5 = DWORD1(v4[6].m_pfnProxied);
    if ( v5 == 0 )
      GFxASCharacter::CreateCharacterHandle(this: v4);
    return (char *)GFxLogBase<GFxCharacter>::LogScriptError(
                     a1: (int)&v4->m_pfnProxied + 12,
                     a2: (int)"Error: %s, GFx_SpriteGotoAndPlay needs one arg\n",
                     **(const char ***)(v5 + 12));
  }
  v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 0);
  v7 = *(struct GASEnvironment **)(v1 + 24);
  targetFrame = -1;
  if ( *(_BYTE *)v6 != 5 )
  {
    v9 = GASValue::ToUInt32(this: v6, a2: v7) - 1;
    targetFrame = v9;
LABEL_18:
    (*(void (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *, unsigned int))(LODWORD(v4->m_pfnProxied) + 324))(
      a1: v4,
      a2: v9);
    return (char *)(*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *, int))(LODWORD(v4->m_pfnProxied) + 328))(
                     a1: v4,
                     a2: 1);
  }
  GASValue::ToStringImpl(a1: v6, a2: &v10, a3: v7, a4: -1, a5: 0);
  v8 = (*(unsigned __int8 (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *, _DWORD, unsigned int *, int))(LODWORD(v4->m_pfnProxied) + 320))(
         a1: v4,
         a2: *(_DWORD *)v10,
         a3: &targetFrame,
         a4: 1) == 0;
  result = v10;
  if ( !v8 )
  {
    v8 = (*((_DWORD *)v10 + 2))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode();
    v9 = targetFrame;
    goto LABEL_18;
  }
  v8 = (*((_DWORD *)v10 + 2))-- == 1;
  if ( v8 )
    return (char *)GASStringNode::ReleaseNode().Sid;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B0E10
// Name: GFx_SpriteRemoveMovieClip
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteRemoveMovieClip(int fn)
{
  int v1; // ecx
  int v2; // esi
  int v3; // eax
  int v4; // eax

  v1 = *(_DWORD *)(fn + 8);
  if ( v1 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1) != 2 )
      return;
    v3 = *(_DWORD *)(fn + 8);
    if ( v3 == 0 )
      return;
    v2 = v3 - 120;
  }
  else
  {
    v2 = *(_DWORD *)(*(_DWORD *)(fn + 24) + 116);
  }
  if ( v2 != 0 )
  {
    if ( *(int *)(v2 + 20) >= 0x4000 )
    {
      GFxASCharacter::RemoveDisplayObject(this: (GFxASCharacter *)v2);
    }
    else
    {
      v4 = *(_DWORD *)(v2 + 148);
      if ( v4 == 0 )
      {
        GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v2);
        if ( v4 == 0 )
          v4 = *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)v2 + 108))(a1: v2) + 120);
      }
      GFxLogBase<GFxCharacter>::LogScriptWarning(
        a1: v2 + 12,
        a2: (int)"%s.removeMovieClip() failed - depth must be >= 0\n",
        **(const char ***)(v4 + 8));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0E90
// Name: GFx_SpriteLocalToGlobal
// Source: json
//------------------------------------------------------------------------------
void __usercall GFx_SpriteLocalToGlobal(int a1@<edi>, int fn)
{
  GASValue *v2; // esi
  int v3; // ecx
  int v4; // eax
  unsigned int *p_dwControlsAccepted; // edi
  _SERVICE_STATUS *v6; // eax
  _SERVICE_STATUS *v7; // esi
  void (__thiscall *v8)(_SERVICE_STATUS *, unsigned int *, int, char *, char *); // edx
  void (__thiscall *v9)(_SERVICE_STATUS *, unsigned int *, int, char *, char *); // edx
  int v10; // [esp-10h] [ebp-78h]
  int v11; // [esp-10h] [ebp-78h]
  _SERVICE_STATUS *v12; // [esp-8h] [ebp-70h]
  GASValue xval[4]; // [esp+8h] [ebp-60h] BYREF
  GASValue yval[4]; // [esp+18h] [ebp-50h] BYREF
  float v16; // [esp+28h] [ebp-40h]
  int p; // [esp+2Ch] [ebp-3Ch] BYREF
  float v18; // [esp+30h] [ebp-38h]
  char v19; // [esp+34h] [ebp-34h] BYREF
  double v20; // [esp+38h] [ebp-30h] BYREF
  float result_4; // [esp+40h] [ebp-28h]
  GFxCharacter *result_8; // [esp+44h] [ebp-24h]
  char v23; // [esp+4Bh] [ebp-1Dh] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v24; // [esp+4Ch] [ebp-1Ch] BYREF

  v2 = *(GASValue **)(fn + 4);
  GASValue::DropRefs(this: v2);
  *(_BYTE *)v2 = 0;
  v3 = *(_DWORD *)(fn + 8);
  if ( v3 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3) != 2 )
      return;
    v4 = *(_DWORD *)(fn + 8);
    if ( v4 == 0 )
      return;
    result_8 = (GFxCharacter *)(v4 - 120);
  }
  else
  {
    result_8 = *(GFxCharacter **)(*(_DWORD *)(fn + 24) + 116);
  }
  if ( result_8 != nullptr && *(int *)(fn + 28) >= 1 )
  {
    v12 = *(_SERVICE_STATUS **)(fn + 24);
    p_dwControlsAccepted = &v12[4].dwControlsAccepted;
    GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
    v6 = GASValue::ToObjectInterface(result: v12);
    v7 = v6;
    if ( v6 != nullptr )
    {
      LOBYTE(xval[0]) = 0;
      LOBYTE(yval[0]) = 0;
      (*(void (__thiscall **)(_SERVICE_STATUS *, unsigned int *, unsigned int, GASValue *))(v6->dwServiceType + 44))(
        a1: v6,
        a2: p_dwControlsAccepted,
        a3: *p_dwControlsAccepted + 524,
        a4: xval);
      (*(void (__thiscall **)(_SERVICE_STATUS *, unsigned int *, unsigned int, GASValue *))(v7->dwServiceType + 44))(
        a1: v7,
        a2: p_dwControlsAccepted,
        a3: *p_dwControlsAccepted + 528,
        a4: yval);
      if ( (LOBYTE(xval[0]) == 3 || LOBYTE(xval[0]) == 4) && (LOBYTE(yval[0]) == 3 || LOBYTE(yval[0]) == 4) )
      {
        result_4 = GASValue::ToNumber(this: yval, a2: (struct GASEnvironment *)*(_DWORD *)(fn + 24));
        v16 = GASValue::ToNumber(this: xval, a2: (struct GASEnvironment *)*(_DWORD *)(fn + 24));
        *(float *)&p = v16 * 20.0;
        v18 = 20.0 * result_4;
        GMatrix2D::SetIdentity(this: (float *)&v24);
        GFxCharacter::GetWorldMatrix(this: result_8, pmat: (CMaterialDict *)&v24);
        GMatrix2D::Transform(
          this: &v24,
          result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)((char *)&v20 + 4),
          (float *)&p,
          p_4: a1);
        p = SHIDWORD(v20);
        v18 = result_4;
        v8 = *(void (__thiscall **)(_SERVICE_STATUS *, unsigned int *, int, char *, char *))(v7->dwServiceType + 40);
        v10 = *p_dwControlsAccepted + 524;
        v19 = 3;
        v23 = 0;
        v20 = *((float *)&v20 + 1) / 20.0;
        v8(a1: v7, a2: p_dwControlsAccepted, a3: v10, a4: &v19, a5: &v23);
        GASValue::~GASValue(this: (GASValue *)&v19);
        v9 = *(void (__thiscall **)(_SERVICE_STATUS *, unsigned int *, int, char *, char *))(v7->dwServiceType + 40);
        v11 = *p_dwControlsAccepted + 528;
        v19 = 3;
        v23 = 0;
        v20 = v18 / 20.0;
        v9(a1: v7, a2: p_dwControlsAccepted, a3: v11, a4: &v19, a5: &v23);
        GASValue::~GASValue(this: (GASValue *)&v19);
      }
      GASValue::~GASValue(this: yval);
      GASValue::~GASValue(this: xval);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1060
// Name: GFx_SpriteGlobalToLocal
// Source: json
//------------------------------------------------------------------------------
void __usercall GFx_SpriteGlobalToLocal(int a1@<edi>, int fn)
{
  GASValue *v2; // esi
  int v3; // ecx
  int v4; // eax
  unsigned int *p_dwControlsAccepted; // edi
  _SERVICE_STATUS *v6; // eax
  _SERVICE_STATUS *v7; // esi
  void (__thiscall *v8)(_SERVICE_STATUS *, unsigned int *, int, char *, char *); // edx
  void (__thiscall *v9)(_SERVICE_STATUS *, unsigned int *, int, char *, char *); // edx
  int v10; // [esp-10h] [ebp-78h]
  int v11; // [esp-10h] [ebp-78h]
  _SERVICE_STATUS *v12; // [esp-8h] [ebp-70h]
  GASValue xval[4]; // [esp+8h] [ebp-60h] BYREF
  GASValue yval[4]; // [esp+18h] [ebp-50h] BYREF
  float v16; // [esp+28h] [ebp-40h]
  int p; // [esp+2Ch] [ebp-3Ch] BYREF
  float v18; // [esp+30h] [ebp-38h]
  char v19; // [esp+34h] [ebp-34h] BYREF
  double v20; // [esp+38h] [ebp-30h] BYREF
  float result_4; // [esp+40h] [ebp-28h]
  GFxCharacter *result_8; // [esp+44h] [ebp-24h]
  char v23; // [esp+4Bh] [ebp-1Dh] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v24; // [esp+4Ch] [ebp-1Ch] BYREF

  v2 = *(GASValue **)(fn + 4);
  GASValue::DropRefs(this: v2);
  *(_BYTE *)v2 = 0;
  v3 = *(_DWORD *)(fn + 8);
  if ( v3 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3) != 2 )
      return;
    v4 = *(_DWORD *)(fn + 8);
    if ( v4 == 0 )
      return;
    result_8 = (GFxCharacter *)(v4 - 120);
  }
  else
  {
    result_8 = *(GFxCharacter **)(*(_DWORD *)(fn + 24) + 116);
  }
  if ( result_8 != nullptr && *(int *)(fn + 28) >= 1 )
  {
    v12 = *(_SERVICE_STATUS **)(fn + 24);
    p_dwControlsAccepted = &v12[4].dwControlsAccepted;
    GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
    v6 = GASValue::ToObjectInterface(result: v12);
    v7 = v6;
    if ( v6 != nullptr )
    {
      LOBYTE(xval[0]) = 0;
      LOBYTE(yval[0]) = 0;
      (*(void (__thiscall **)(_SERVICE_STATUS *, unsigned int *, unsigned int, GASValue *))(v6->dwServiceType + 44))(
        a1: v6,
        a2: p_dwControlsAccepted,
        a3: *p_dwControlsAccepted + 524,
        a4: xval);
      (*(void (__thiscall **)(_SERVICE_STATUS *, unsigned int *, unsigned int, GASValue *))(v7->dwServiceType + 44))(
        a1: v7,
        a2: p_dwControlsAccepted,
        a3: *p_dwControlsAccepted + 528,
        a4: yval);
      if ( (LOBYTE(xval[0]) == 3 || LOBYTE(xval[0]) == 4) && (LOBYTE(yval[0]) == 3 || LOBYTE(yval[0]) == 4) )
      {
        result_4 = GASValue::ToNumber(this: yval, a2: (struct GASEnvironment *)*(_DWORD *)(fn + 24));
        v16 = GASValue::ToNumber(this: xval, a2: (struct GASEnvironment *)*(_DWORD *)(fn + 24));
        *(float *)&p = v16 * 20.0;
        v18 = 20.0 * result_4;
        GMatrix2D::SetIdentity(this: (float *)&v24);
        GFxCharacter::GetWorldMatrix(this: result_8, pmat: (CMaterialDict *)&v24);
        GMatrix2D::TransformByInverse(
          this: &v24,
          result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)((char *)&v20 + 4),
          (float *)&p,
          p_4: a1);
        p = SHIDWORD(v20);
        v18 = result_4;
        v8 = *(void (__thiscall **)(_SERVICE_STATUS *, unsigned int *, int, char *, char *))(v7->dwServiceType + 40);
        v10 = *p_dwControlsAccepted + 524;
        v19 = 3;
        v23 = 0;
        v20 = *((float *)&v20 + 1) / 20.0;
        v8(a1: v7, a2: p_dwControlsAccepted, a3: v10, a4: &v19, a5: &v23);
        GASValue::~GASValue(this: (GASValue *)&v19);
        v9 = *(void (__thiscall **)(_SERVICE_STATUS *, unsigned int *, int, char *, char *))(v7->dwServiceType + 40);
        v11 = *p_dwControlsAccepted + 528;
        v19 = 3;
        v23 = 0;
        v20 = v18 / 20.0;
        v9(a1: v7, a2: p_dwControlsAccepted, a3: v11, a4: &v19, a5: &v23);
        GASValue::~GASValue(this: (GASValue *)&v19);
      }
      GASValue::~GASValue(this: yval);
      GASValue::~GASValue(this: xval);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1230
// Name: GFx_SpriteHitTest
// Source: json
//------------------------------------------------------------------------------
void __usercall GFx_SpriteHitTest(_TAPE_WMI_OPERATIONS *a1@<edi>, int fn)
{
  int v2; // ecx
  GFxCharacter *v3; // ebx
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  GASValue *v7; // eax
  GASValue *v8; // eax
  bool v9; // cc
  unsigned __int8 v10; // al
  float *v11; // edi
  GASValue *v12; // eax
  GASValue *v13; // eax
  int (__thiscall *v14)(float *, _DWORD, _DWORD, int, _DWORD); // edx
  char v15; // bl
  int v16; // esi
  int v17; // esi
  GASValue *v18; // eax
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v19; // edi
  __vc_attributes::max_isAttribute *v20; // ecx
  char v21; // al
  int v23; // esi
  struct GASEnvironment *v24; // [esp+14h] [ebp-D8h]
  struct GASEnvironment *v25; // [esp+14h] [ebp-D8h]
  tagPOLYTEXTW *v26; // [esp+14h] [ebp-D8h]
  tagPOLYTEXTW *v27; // [esp+14h] [ebp-D8h]
  struct GASEnvironment *v28; // [esp+14h] [ebp-D8h]
  struct GASEnvironment *v29; // [esp+14h] [ebp-D8h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> targetLocalRect; // [esp+24h] [ebp-C8h] BYREF
  float v32; // [esp+30h] [ebp-BCh]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> spriteLocalBounds; // [esp+34h] [ebp-B8h] BYREF
  float v34; // [esp+40h] [ebp-ACh]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> spriteWorldRect; // [esp+44h] [ebp-A8h] BYREF
  float v36; // [esp+50h] [ebp-9Ch]
  float wy; // [esp+54h] [ebp-98h]
  int hitTestMask; // [esp+58h] [ebp-94h]
  float wx; // [esp+5Ch] [ebp-90h] BYREF
  GMatrix3D pmat; // [esp+60h] [ebp-8Ch] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v41; // [esp+A0h] [ebp-4Ch] BYREF
  struct GMatrix2D v42; // [esp+B8h] [ebp-34h] BYREF
  struct GMatrix2D v43; // [esp+D0h] [ebp-1Ch] BYREF

  v2 = *(_DWORD *)(fn + 8);
  if ( v2 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2) != 2 )
      return;
    v4 = *(_DWORD *)(fn + 8);
    if ( v4 == 0 )
      return;
    v3 = (GFxCharacter *)(v4 - 120);
  }
  else
  {
    v3 = *(GFxCharacter **)(*(_DWORD *)(fn + 24) + 116);
  }
  if ( v3 != nullptr )
  {
    v5 = *(_DWORD *)(fn + 4);
    GASValue::DropRefs(this: (GASValue *)v5);
    *(_BYTE *)v5 = 2;
    *(_BYTE *)(v5 + 4) = 0;
    GMatrix2D::SetIdentity(this: (float *)&v41);
    (*(void (__thiscall **)(GFxCharacter *, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *, CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *))(*(_DWORD *)v3 + 52))(
      a1: v3,
      a2: &spriteLocalBounds,
      a3: &v41);
    if ( *(float *)&spriteLocalBounds.m_pMemory != *(float *)&spriteLocalBounds.m_nGrowSize
      || *(float *)&spriteLocalBounds.m_nAllocationCount != v34 )
    {
      v6 = *(_DWORD *)(fn + 28);
      if ( v6 >= 2 )
      {
        v24 = *(struct GASEnvironment **)(fn + 24);
        LOBYTE(hitTestMask) = 0;
        v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
        wy = GASValue::ToNumber(this: v7, a2: v24);
        v25 = *(struct GASEnvironment **)(fn + 24);
        v8 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
        wx = GASValue::ToNumber(this: v8, a2: v25);
        v9 = *(_DWORD *)(fn + 28) < 3;
        *(float *)&spriteWorldRect.m_nGrowSize = wx * 20.0;
        v36 = 20.0 * wy;
        if ( !v9 )
        {
          v26 = *(tagPOLYTEXTW **)(fn + 24);
          GASFnCall::Arg(this: (GASFnCall *)fn, a2: 2);
          LOBYTE(hitTestMask) = (unsigned __int8)GASValue::ToBool(result: v26) != 0;
        }
        if ( *(int *)(fn + 28) >= 4 )
        {
          v27 = *(tagPOLYTEXTW **)(fn + 24);
          GASFnCall::Arg(this: (GASFnCall *)fn, a2: 3);
          v10 = (unsigned __int8)GASValue::ToBool(result: v27);
          LOBYTE(hitTestMask) = (v10 != 0 ? 2 : 0) | hitTestMask;
        }
        v11 = (float *)(*(int (__thiscall **)(GFxCharacter *))(*(_DWORD *)v3 + 84))(a1: v3);
        if ( GFxCharacter::Is3D(
               this: v3,
               result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) != 0
          && v11 != nullptr )
        {
          v28 = *(struct GASEnvironment **)(fn + 24);
          v12 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
          wx = GASValue::ToNumber(this: v12, a2: v28);
          v29 = *(struct GASEnvironment **)(fn + 24);
          v13 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
          wy = GASValue::ToNumber(this: v13, a2: v29);
          v14 = *(int (__thiscall **)(float *, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v11 + 192);
          wx = (wx - v11[32]) / v11[30];
          wy = (wy - v11[33]) / v11[31];
          v15 = v14(a1: v11, a2: LODWORD(wx), a3: LODWORD(wy), a4: hitTestMask & 2 | 1, a5: 0);
        }
        else
        {
          GMatrix2D::SetIdentity(this: (float *)&v41);
          GFxCharacter::GetLevelMatrix(this: v3, pmat: (CMaterialDict *)&v41);
          GMatrix2D::TransformByInverse(
            this: &v41,
            result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&v43.M_[1][1],
            p: (float *)&spriteWorldRect.m_nGrowSize,
            p_4: (int)a1);
          if ( (*((_BYTE *)v3 + 118) & 1) == 0 )
          {
            if ( *(float *)&spriteLocalBounds.m_nGrowSize < (double)v43.M_[1][1]
              || *(float *)&spriteLocalBounds.m_pMemory > (double)v43.M_[1][1]
              || v34 < (double)v43.M_[1][2]
              || *(float *)&spriteLocalBounds.m_nAllocationCount > (double)v43.M_[1][2] )
            {
              v17 = *(_DWORD *)(fn + 4);
              GASValue::DropRefs(this: (GASValue *)v17);
              *(_BYTE *)(v17 + 4) = 0;
              *(_BYTE *)v17 = 2;
              return;
            }
            if ( (hitTestMask & 1) == 0 )
            {
              v16 = *(_DWORD *)(fn + 4);
              GASValue::DropRefs(this: (GASValue *)v16);
              *(_BYTE *)(v16 + 4) = 1;
              *(_BYTE *)v16 = 2;
              return;
            }
          }
          v15 = (*(int (__thiscall **)(GFxCharacter *, float *, int))(*(_DWORD *)v3 + 68))(
                  a1: v3,
                  a2: &v43.M_[1][1],
                  a3: hitTestMask);
        }
        goto LABEL_52;
      }
      if ( v6 != 1 )
        return;
      v18 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
      v19 = nullptr;
      if ( *(_BYTE *)v18 == 7 )
      {
        if ( GASValue::ToASCharacter(this: v18, a2: *(const struct GASEnvironment **)(fn + 24)) == nullptr )
          return;
        v19 = (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)GASObjectInterface::ToSprite(result: a1);
      }
      else
      {
        GASValue::ToStringImpl(a1: v18, a2: &wx, a3: *(_DWORD *)(fn + 24), a4: -1, a5: 0);
        v20 = *(__vc_attributes::max_isAttribute **)(fn + 24);
        LOBYTE(v41.m_Memory.m_nGrowSize) = 0;
        GASEnvironment::GetVariable(
          this: v20,
          varname: (_IMAGE_SYMBOL_EX *)&wx,
          a3: (GASValue *)&v41.m_Memory.m_nGrowSize,
          retVal: 0,
          paschar: nullptr,
          a6: nullptr,
          a7: 0);
        if ( v21 != 0 )
        {
          if ( GASValue::ToASCharacter(
                 this: (GASValue *)&v41.m_Memory.m_nGrowSize,
                 a2: *(const struct GASEnvironment **)(fn + 24)) != nullptr )
            v19 = (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)GASObjectInterface::ToSprite(result: a1);
          else
            v19 = nullptr;
        }
        GASValue::~GASValue(this: (GASValue *)&v41.m_Memory.m_nGrowSize);
        if ( (*(_DWORD *)(LODWORD(wx) + 8))-- == 1 )
          GASStringNode::ReleaseNode();
      }
      if ( v19 != nullptr )
      {
        GMatrix2D::SetIdentity(this: (float *)&v42);
        (*(void (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *, struct GMatrix2D *))(LODWORD(v19->m_pfnProxied) + 52))(
          a1: v19,
          a2: &targetLocalRect,
          a3: &v42);
        if ( *(float *)&targetLocalRect.m_pMemory != *(float *)&targetLocalRect.m_nGrowSize
          || *(float *)&targetLocalRect.m_nAllocationCount != v32 )
        {
          if ( GFxCharacter::Is3D(
                 this: v3,
                 result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) != 0 )
          {
            GMatrix3D::SetIdentity(this: &pmat);
            GFxCharacter::GetWorldMatrix3D(
              this: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)v3,
              (CMatQueuedMesh::MST_MeshInfo_t *)&pmat);
            v43.M_[0][2] = 0.0;
            v43.M_[1][0] = 0.0;
            v43.M_[1][1] = 0.0;
            v43.M_[1][2] = 0.0;
            GMatrix3D::EncloseTransform(
              this: (float *)&pmat,
              result: (const CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)&v43.M_[0][2],
              r: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&spriteLocalBounds,
              bDivideByW: 0.0);
          }
          else
          {
            GMatrix2D::SetIdentity(this: (float *)&v42);
            GFxCharacter::GetWorldMatrix(this: v3, pmat: (CMaterialDict *)&v42);
            v43.M_[0][2] = 0.0;
            v43.M_[1][0] = 0.0;
            v43.M_[1][1] = 0.0;
            v43.M_[1][2] = 0.0;
            GMatrix2D::EncloseTransform(this: (float *)&v42, a2: &v43.M_[0][2], a3: (float *)&spriteLocalBounds);
          }
          *(float *)&spriteWorldRect.m_pMemory = v43.M_[0][2];
          *(float *)&spriteWorldRect.m_nAllocationCount = v43.M_[1][0];
          *(float *)&spriteWorldRect.m_nGrowSize = v43.M_[1][1];
          v36 = v43.M_[1][2];
          if ( GFxCharacter::Is3D(
                 this: v19,
                 result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) != 0 )
          {
            GMatrix3D::SetIdentity(this: &pmat);
            GFxCharacter::GetWorldMatrix3D(this: v19, (CMatQueuedMesh::MST_MeshInfo_t *)&pmat);
            v42.M_[0][2] = 0.0;
            v42.M_[1][0] = 0.0;
            v42.M_[1][1] = 0.0;
            v42.M_[1][2] = 0.0;
            GMatrix3D::EncloseTransform(
              this: (float *)&pmat,
              result: (const CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)&v42.M_[0][2],
              r: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&targetLocalRect,
              bDivideByW: 0.0);
          }
          else
          {
            GMatrix2D::SetIdentity(this: (float *)&v43);
            GFxCharacter::GetWorldMatrix(this: (GFxCharacter *)v19, pmat: (CMaterialDict *)&v43);
            v42.M_[0][2] = 0.0;
            v42.M_[1][0] = 0.0;
            v42.M_[1][1] = 0.0;
            v42.M_[1][2] = 0.0;
            GMatrix2D::EncloseTransform(this: (float *)&v43, a2: &v42.M_[0][2], a3: (float *)&targetLocalRect);
          }
          v43.M_[0][2] = v42.M_[0][2];
          v43.M_[1][0] = v42.M_[1][0];
          v43.M_[1][1] = v42.M_[1][1];
          v43.M_[1][2] = v42.M_[1][2];
          v15 = v42.M_[1][0] <= (double)v36
             && *(float *)&spriteWorldRect.m_nAllocationCount <= (double)v43.M_[1][2]
             && *(float *)&spriteWorldRect.m_pMemory <= (double)v43.M_[1][1]
             && v43.M_[0][2] <= (double)*(float *)&spriteWorldRect.m_nGrowSize;
LABEL_52:
          v23 = *(_DWORD *)(fn + 4);
          GASValue::DropRefs(this: (GASValue *)v23);
          *(_BYTE *)(v23 + 4) = v15;
          *(_BYTE *)v23 = 2;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B17F0
// Name: public: void GFxSprite::SetNoLine(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall GFxSprite::SetNoLine@<al>(GFxFontLib *this@<ecx>, Vector *a2@<edi>)
{
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  IClientTools *v5; // eax
  int v6; // eax
  int v7; // edi
  GRefCountNTSImpl *v8; // ecx
  char result; // al
  Vector *v10; // [esp-4h] [ebp-Ch]
  QAngle *v11; // [esp+0h] [ebp-8h]
  int v12; // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 115) == 0 )
  {
    v3 = *(_DWORD *)(*((_DWORD *)this + 47) + 32);
    v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
    v10 = a2;
    v12 = 322;
    v5 = (IClientTools *)v4(a1: v3, a2: 136, a3: &v12);
    if ( v5 != nullptr )
    {
      LOBYTE(v6) = GFxDrawingContext::GFxDrawingContext(this: v5, a2, a3: v11, a4: (float *)v12);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    v8 = *((GRefCountNTSImpl **)this + 115);
    if ( v8 != nullptr )
      GRefCountNTSImpl::Release(this: v8);
    *((_DWORD *)this + 115) = v7;
    a2 = v10;
  }
  result = GFxDrawingContext::NoLine(this: *((GFxDrawingContext **)this + 115));
  if ( result == 0 )
  {
    GFxSprite::AcquirePath((GFxValue *)this, a2, newShapeFlag: 0);
    return GFxDrawingContext::SetNoLine(this: *((IClientTools **)this + 115), a2: (CBaseHandle)v11, a3: v12);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B1870
// Name: public: void GFxSprite::SetLineStyle(float,unsigned int,bool,enum GFxLineStyle::LineStyle,enum GFxLineStyle::LineStyle,enum GFxLineStyle::LineStyle,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetLineStyle(
        GFxValue *this,
        float lineWidth,
        unsigned int rgba,
        int hinting,
        CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *scaling,
        CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *caps,
        CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *joins,
        int miterLimit)
{
  int v9; // ecx
  int (__thiscall *v10)(int, int, int *); // edx
  IClientTools *v11; // eax
  int v12; // eax
  int v13; // edi
  GRefCountNTSImpl *v14; // ecx
  Vector *v15; // [esp+28h] [ebp-Ch]
  QAngle *v16; // [esp+2Ch] [ebp-8h]
  int v17; // [esp+30h] [ebp-4h] BYREF
  float lineWidtha; // [esp+3Ch] [ebp+8h]

  if ( *((_DWORD *)this + 115) == 0 )
  {
    v9 = *(_DWORD *)(*((_DWORD *)this + 47) + 32);
    v10 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v9 + 40);
    v17 = 322;
    v11 = (IClientTools *)v10(a1: v9, a2: 136, a3: &v17);
    if ( v11 != nullptr )
    {
      LOBYTE(v12) = GFxDrawingContext::GFxDrawingContext(this: v11, a2: v15, a3: v16, a4: (float *)v17);
      v13 = v12;
    }
    else
    {
      v13 = 0;
    }
    v14 = *((GRefCountNTSImpl **)this + 115);
    if ( v14 != nullptr )
      GRefCountNTSImpl::Release(this: v14);
    *((_DWORD *)this + 115) = v13;
  }
  if ( (rgba & 0xFF000000) != 0 )
  {
    if ( lineWidth <= 0.0 )
      lineWidth = 0.050000001;
    lineWidtha = lineWidth * 20.0;
    if ( (unsigned __int8)GFxDrawingContext::SameLineStyle(
                            this: *((IClientTools **)this + 115),
                            result: (QAngle *)LODWORD(lineWidtha),
                            lineWidth: rgba) == 0 )
    {
      GFxSprite::AcquirePath(this, a2: (Vector *)rgba, newShapeFlag: 0);
      GFxDrawingContext::SetLineStyle(
        this: *((IClientTools **)this + 115),
        result: (Vector *)LODWORD(lineWidtha),
        lineWidth: rgba);
    }
  }
  else if ( !GFxDrawingContext::NoLine(this: *((GFxDrawingContext **)this + 115)) )
  {
    GFxSprite::AcquirePath(this, a2: (Vector *)rgba, newShapeFlag: 0);
    GFxDrawingContext::SetNoLine(this: *((IClientTools **)this + 115), a2: (CBaseHandle)v15, a3: (int)v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1990
// Name: public: void GFxSprite::BeginBitmapFill(enum GFxFillType,class GFxImageResource __near *,class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSprite::BeginBitmapFill(
        GFxValue *this@<ecx>,
        Vector *a2@<edi>,
        long double fillType,
        float pimageRes_4)
{
  GFxSprite::AcquirePath(this, a2, newShapeFlag: 1u);
  GFxDrawingContext::SetBitmapFill(result: (const IClientTools *)LODWORD(fillType));
}

//------------------------------------------------------------------------------
// Address: 0x100B19C0
// Name: GFx_SpriteBeginFill
// Source: json
//------------------------------------------------------------------------------
void __usercall GFx_SpriteBeginFill(const FlashlightState_t *a1@<edi>, int alpha)
{
  int v2; // ecx
  int v3; // ebx
  int v4; // eax
  GASValue *v5; // eax
  Vector *v6; // edi
  GASValue *v7; // eax
  int v8; // edi
  double v9; // st7
  bool v10; // c0
  bool v11; // c3
  double v12; // st7
  struct GASEnvironment *v13; // [esp-8h] [ebp-18h]
  struct GASEnvironment *v14; // [esp-8h] [ebp-18h]
  CBaseHandle v16; // [esp+0h] [ebp-10h]
  int v17; // [esp+4h] [ebp-Ch]
  float alphab; // [esp+18h] [ebp+8h]
  float alphaa; // [esp+18h] [ebp+8h]
  float alphac; // [esp+18h] [ebp+8h]

  v2 = *(_DWORD *)(alpha + 8);
  if ( v2 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2) != 2 )
      return;
    v4 = *(_DWORD *)(alpha + 8);
    if ( v4 == 0 )
      return;
    v3 = v4 - 120;
  }
  else
  {
    v3 = *(_DWORD *)(*(_DWORD *)(alpha + 24) + 116);
  }
  if ( v3 == 0 )
    return;
  if ( *(int *)(alpha + 28) > 0 )
  {
    v13 = *(struct GASEnvironment **)(alpha + 24);
    v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)alpha, a2: 0);
    v6 = (Vector *)(GASValue::ToUInt32(this: v5, a2: v13) | 0xFF000000);
    if ( *(int *)(alpha + 28) <= 1 )
    {
LABEL_13:
      GFxSprite::AcquirePath(this: (GFxValue *)v3, a2: v6, newShapeFlag: 1u);
      GFxDrawingContext::SetFill(this: *(IClientTools **)(v3 + 460), rgba: (unsigned __int16)v6, a3: a1);
      return;
    }
    v14 = *(struct GASEnvironment **)(alpha + 24);
    v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)alpha, a2: 1);
    alphab = GASValue::ToNumber(this: v7, a2: v14);
    v8 = (unsigned int)v6 & 0xFFFFFF;
    alphaa = alphab * 255.0 / 100.0;
    v9 = alphaa;
    if ( alphaa >= 255.0 )
    {
      alphaa = 255.0;
    }
    else
    {
      v10 = v9 > 0.0;
      v11 = 0.0 == v9;
      v12 = 0.0;
      if ( !v10 && !v11 )
      {
LABEL_12:
        alphac = v12;
        v6 = (Vector *)(((__int64)alphac << 24) | v8);
        goto LABEL_13;
      }
    }
    v12 = alphaa;
    goto LABEL_12;
  }
  GFxSprite::AcquirePath(this: (GFxValue *)v3, a2: &a1->m_vecLightOrigin, newShapeFlag: 1u);
  GFxDrawingContext::SetNoFill(this: *(IClientTools **)(v3 + 460), a2: v16, a3: v17);
}

//------------------------------------------------------------------------------
// Address: 0x100B1AF0
// Name: GFx_SpriteCreateGradient
// Source: json
//------------------------------------------------------------------------------
const char **__usercall GFx_SpriteCreateGradient@<eax>(int a1@<ebx>, int a2@<edi>, int a3@<esi>, int a4)
{
  const char **result; // eax
  int v5; // edi
  struct GASValue *v6; // eax
  GASValue *v7; // eax
  struct GASObject *v8; // eax
  struct GASObject *v9; // edi
  bool v10; // cc
  GASValue *v11; // eax
  struct GASObject *v12; // eax
  struct GASObject *v13; // edi
  struct GASObject *v14; // ebx
  GASValue *v15; // eax
  struct GASObject *v16; // eax
  struct GASObject *v17; // edi
  int sequence; // eax
  struct GASStringContext *v19; // ebx
  GASValue *v20; // eax
  struct GASObject *v21; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // edx
  GASObjectInterface *v23; // edi
  float *v24; // eax
  bool v25; // al
  bool v26; // zf
  int v27; // edi
  struct GASValue *v28; // eax
  int v29; // edi
  struct GASValue *v30; // eax
  GASValue *v31; // eax
  GViewport *v32; // ecx
  char v33; // al
  void *v34; // eax
  float v35; // edi
  struct GASObject *v36; // eax
  int v37; // ebx
  unsigned int v38; // edi
  int v39; // edi
  double v40; // st7
  bool v41; // c0
  bool v42; // c3
  double v43; // st7
  CTSQueue<CFunctor *,0,1>::Node_t *v44; // eax
  int v45; // edi
  double v46; // st7
  bool v47; // c0
  bool v48; // c3
  double v49; // st7
  int v50; // ecx
  struct GASObject *v51; // eax
  int v52; // ecx
  const struct GASEnvironment *v53; // [esp+4h] [ebp-84h]
  const struct GASEnvironment *v54; // [esp+4h] [ebp-84h]
  int v55; // [esp+4h] [ebp-84h]
  struct GASEnvironment *v56; // [esp+4h] [ebp-84h]
  const struct GASEnvironment *v57; // [esp+8h] [ebp-80h]
  const struct GASEnvironment *v58; // [esp+8h] [ebp-80h]
  struct GASEnvironment *v61; // [esp+Ch] [ebp-7Ch]
  struct GASObject *v62; // [esp+10h] [ebp-78h]
  int v63; // [esp+14h] [ebp-74h]
  struct GASObject *v64; // [esp+18h] [ebp-70h]
  const char **v65; // [esp+1Ch] [ebp-6Ch] BYREF
  struct GASObject *v66; // [esp+20h] [ebp-68h]
  float v67; // [esp+24h] [ebp-64h]
  GASValue v68[4]; // [esp+28h] [ebp-60h] BYREF
  float v69; // [esp+38h] [ebp-50h]
  int v70; // [esp+3Ch] [ebp-4Ch]
  __int64 v71; // [esp+40h] [ebp-48h] BYREF
  float v72; // [esp+48h] [ebp-40h] BYREF
  float v73; // [esp+4Ch] [ebp-3Ch] BYREF
  float v74; // [esp+50h] [ebp-38h]
  struct GMatrix2D penv; // [esp+54h] [ebp-34h] BYREF
  GMatrix2D v76; // [esp+6Ch] [ebp-1Ch] BYREF

  result = (const char **)a4;
  v73 = 0.0;
  v63 = a4;
  if ( *(int *)(a3 + 28) <= 0 )
    return result;
  v5 = *(_DWORD *)(a3 + 24);
  v6 = GASFnCall::Arg(this: (GASFnCall *)a3, a2: 0);
  GASValue::ToStringImpl(a1: v6, a2: &v65, a3: v5, a4: -1, a5: 0);
  if ( *(int *)(a3 + 28) <= 1 )
    goto LABEL_76;
  v57 = *(const struct GASEnvironment **)(a3 + 24);
  v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)a3, a2: 1);
  v8 = GASValue::ToObject(this: v7, a2: v57);
  v9 = v8;
  if ( v8 == nullptr )
    goto LABEL_76;
  if ( ((int (__thiscall *)(struct GASObject *))v8[2].pNode[1].pNext)(a1: &v8[2]) != 7 )
    goto LABEL_76;
  v10 = *(_DWORD *)(a3 + 28) <= 2;
  v66 = v9;
  if ( v10 )
    goto LABEL_76;
  v58 = *(const struct GASEnvironment **)(a3 + 24);
  v11 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)a3, a2: 2);
  v12 = GASValue::ToObject(this: v11, a2: v58);
  v13 = v12;
  if ( v12 == nullptr )
    goto LABEL_76;
  if ( ((int (__thiscall *)(struct GASObject *))v12[2].pNode[1].pNext)(a1: &v12[2]) != 7 )
    goto LABEL_76;
  v14 = v13;
  v62 = v13;
  if ( *(int *)(a3 + 28) <= 3 )
    goto LABEL_76;
  v53 = *(const struct GASEnvironment **)(a3 + 24);
  v15 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)a3, a2: 3);
  v16 = GASValue::ToObject(this: v15, a2: v53);
  v17 = v16;
  if ( v16 == nullptr )
    goto LABEL_76;
  if ( ((int (__thiscall *)(struct GASObject *))v16[2].pNode[1].pNext)(a1: &v16[2]) != 7 )
    goto LABEL_76;
  v64 = v17;
  if ( *(int *)(a3 + 28) <= 4 )
    goto LABEL_76;
  sequence = v66[7].sequence;
  if ( sequence <= 0 || sequence != v14[7].sequence || sequence != v17[7].sequence )
    goto LABEL_76;
  GMatrix2D::SetIdentity(this: (float *)&v76);
  v54 = *(const struct GASEnvironment **)(a3 + 24);
  LOBYTE(v68[0]) = 0;
  v19 = (const struct GASEnvironment *)((char *)v54 + 120);
  v20 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)a3, a2: 4);
  *(float *)&v21 = COERCE_FLOAT(GASValue::ToObject(this: v20, a2: v54));
  pNode = v21[2].pNode;
  v23 = (GASObjectInterface *)&v21[2];
  v72 = *(float *)&v21;
  if ( ((int (__thiscall *)(struct GASObject *, int, int))pNode[1].pNext)(a1: v21 + 2, a2: a1, a3: a2) == 15 )
  {
    GASMatrixObject::GetMatrix((void *)&penv, v: *(GMemAddressStub **)(a3 + 24), a3: (const char *)v62, a4);
    v76.M_[0][0] = *v24;
    v76.M_[0][1] = v24[1];
    v76.M_[0][2] = v24[2];
    v76.M_[1][0] = v24[3];
    v76.M_[1][1] = v24[4];
    v76.M_[1][2] = v24[5];
  }
  else
  {
    if ( GASObjectInterface::GetConstMemberRaw(
           this: v23,
           psc: v19,
           psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"matrixType",
           psc_8: (struct GASValue *)v68) == 0
      || (v55 = *(_DWORD *)(a3 + 24),
          LODWORD(v73) = 1,
          GASValue::ToStringImpl(a1: v68, a2: &v72, a3: v55, a4: -1, a5: 0),
          v25 = GASString::operator==(this: (const char ***)&v72, a2: "box"),
          HIBYTE(v74) = 1,
          !v25) )
    {
      HIBYTE(v74) = 0;
    }
    if ( (LOBYTE(v73) & 1) != 0 )
    {
      v26 = (*(_DWORD *)(LODWORD(v72) + 8))-- == 1;
      if ( v26 )
        GASStringNode::ReleaseNode();
    }
    if ( HIBYTE(v74) != 0 )
    {
      *(float *)&v70 = 0.0;
      v72 = 0.0;
      v74 = 100.0;
      v69 = 100.0;
      v73 = 0.0;
      if ( GASObjectInterface::GetConstMemberRaw(
             this: v23,
             psc: v19,
             psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nGrowSize,
             psc_8: (struct GASValue *)v68) != 0 )
        *(float *)&v70 = GASValue::ToNumber(this: v68, a2: (struct GASEnvironment *)*(_DWORD *)(a3 + 24));
      if ( GASObjectInterface::GetConstMemberRaw(
             this: v23,
             psc: v19,
             psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nAllocationCount,
             psc_8: (struct GASValue *)v68) != 0 )
        v72 = GASValue::ToNumber(this: v68, a2: (struct GASEnvironment *)*(_DWORD *)(a3 + 24));
      if ( GASObjectInterface::GetConstMemberRaw(
             this: v23,
             psc: v19,
             psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"w",
             psc_8: (struct GASValue *)v68) != 0 )
        v74 = GASValue::ToNumber(this: v68, a2: (struct GASEnvironment *)*(_DWORD *)(a3 + 24));
      if ( GASObjectInterface::GetConstMemberRaw(
             this: v23,
             psc: v19,
             psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"h",
             psc_8: (struct GASValue *)v68) != 0 )
        v69 = GASValue::ToNumber(this: v68, a2: (struct GASEnvironment *)*(_DWORD *)(a3 + 24));
      if ( GASObjectInterface::GetConstMemberRaw(
             this: v23,
             psc: v19,
             psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"r",
             psc_8: (struct GASValue *)v68) != 0 )
        v73 = GASValue::ToNumber(this: v68, a2: (struct GASEnvironment *)*(_DWORD *)(a3 + 24));
      *(float *)&v70 = v74 * 0.5 + *(float *)&v70;
      v72 = 0.5 * v69 + v72;
      v74 = v74 * 0.0006103515625;
      v69 = 0.0006103515625 * v69;
      v67 = cos(v73);
      *((float *)&v71 + 1) = v67;
      v67 = sin(v73);
      penv.M_[0][0] = *((float *)&v71 + 1);
      penv.M_[0][1] = -v67;
      penv.M_[0][2] = 0.0;
      penv.M_[1][2] = 0.0;
      penv.M_[1][0] = v67;
      penv.M_[1][1] = *((float *)&v71 + 1);
      GMatrix2D::Append(this: &v76, a2: &penv);
      v76.M_[0][0] = v76.M_[0][0] * v74;
      v76.M_[0][1] = v76.M_[0][1] * v74;
      v76.M_[0][2] = v74 * v76.M_[0][2];
      v76.M_[1][0] = v76.M_[1][0] * v69;
      v76.M_[1][1] = v76.M_[1][1] * v69;
      v76.M_[1][2] = v69 * v76.M_[1][2];
      v76.M_[0][2] = v76.M_[0][2] + *(float *)&v70;
      v76.M_[1][2] = v76.M_[1][2] + v72;
    }
    else
    {
      if ( GASObjectInterface::GetConstMemberRaw(
             this: v23,
             psc: v19,
             psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Size,
             psc_8: (struct GASValue *)v68) != 0 )
      {
        *((float *)&v71 + 1) = GASValue::ToNumber(this: v68, a2: (struct GASEnvironment *)*(_DWORD *)(a3 + 24));
        v76.M_[0][0] = *((float *)&v71 + 1) * 0.0006103515625;
      }
      if ( GASObjectInterface::GetConstMemberRaw(
             this: v23,
             psc: v19,
             psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Memory.m_nGrowSize,
             psc_8: (struct GASValue *)v68) != 0 )
      {
        *((float *)&v71 + 1) = GASValue::ToNumber(this: v68, a2: (struct GASEnvironment *)*(_DWORD *)(a3 + 24));
        v76.M_[0][1] = *((float *)&v71 + 1) * 0.0006103515625;
      }
      if ( GASObjectInterface::GetConstMemberRaw(
             this: v23,
             psc: v19,
             psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Memory.m_nAllocationCount,
             psc_8: (struct GASValue *)v68) != 0 )
        v76.M_[0][2] = GASValue::ToNumber(this: v68, a2: (struct GASEnvironment *)*(_DWORD *)(a3 + 24));
      if ( GASObjectInterface::GetConstMemberRaw(
             this: v23,
             psc: v19,
             psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968,
             psc_8: (struct GASValue *)v68) != 0 )
      {
        *((float *)&v71 + 1) = GASValue::ToNumber(this: v68, a2: (struct GASEnvironment *)*(_DWORD *)(a3 + 24));
        v76.M_[1][0] = *((float *)&v71 + 1) * 0.0006103515625;
      }
      if ( GASObjectInterface::GetConstMemberRaw(
             this: v23,
             psc: v19,
             psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"e",
             psc_8: (struct GASValue *)v68) != 0 )
      {
        *((float *)&v71 + 1) = GASValue::ToNumber(this: v68, a2: (struct GASEnvironment *)*(_DWORD *)(a3 + 24));
        v76.M_[1][1] = *((float *)&v71 + 1) * 0.0006103515625;
      }
      if ( GASObjectInterface::GetConstMemberRaw(
             this: v23,
             psc: v19,
             psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"h",
             psc_8: (struct GASValue *)v68) != 0 )
        v76.M_[1][2] = GASValue::ToNumber(this: v68, a2: (struct GASEnvironment *)*(_DWORD *)(a3 + 24));
    }
  }
  v10 = *(_DWORD *)(a3 + 28) <= 5;
  v74 = 0.0;
  LOBYTE(v72) = 0;
  if ( !v10 )
  {
    v27 = *(_DWORD *)(a3 + 24);
    v28 = GASFnCall::Arg(this: (GASFnCall *)a3, a2: 5);
    GASValue::ToStringImpl(a1: v28, a2: (char *)&v71 + 4, a3: v27, a4: -1, a5: 0);
    if ( *(int *)(a3 + 28) > 6 )
    {
      v29 = *(_DWORD *)(a3 + 24);
      v30 = GASFnCall::Arg(this: (GASFnCall *)a3, a2: 6);
      GASValue::ToStringImpl(a1: v30, a2: &v73, a3: v29, a4: -1, a5: 0);
      LOBYTE(v72) = GASString::operator==(this: (const char ***)&v73, a2: "linearRGB");
      v26 = (*(_DWORD *)(LODWORD(v73) + 8))-- == 1;
      if ( v26 )
        GASStringNode::ReleaseNode();
      if ( *(int *)(a3 + 28) > 7 )
      {
        v61 = *(struct GASEnvironment **)(a3 + 24);
        v31 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)a3, a2: 7);
        v74 = GASValue::ToNumber(this: v31, a2: v61);
        GASNumberUtil::IsNaN(v: v32, u: COERCE_UNSIGNED_INT64(v74), u_4: HIDWORD(COERCE_UNSIGNED_INT64(v74)));
        if ( v33 != 0 )
        {
          v74 = 0.0;
        }
        else if ( v74 >= -1.0 )
        {
          if ( v74 > 1.0 )
            v74 = 1.0;
        }
        else
        {
          v74 = -1.0;
        }
      }
    }
    v26 = (*(_DWORD *)(HIDWORD(v71) + 8))-- == 1;
    if ( v26 )
      GASStringNode::ReleaseNode();
  }
  v70 = 16;
  if ( GASString::operator==(this: &v65, a2: "radial") )
  {
    v70 = 18;
    if ( 0.0 != v74 )
      v70 = 19;
  }
  HIDWORD(v71) = 258;
  v34 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 20, a3: (char *)&v71 + 4);
  if ( v34 == nullptr )
    goto LABEL_75;
  v35 = COERCE_FLOAT(GFxGradientData::GFxGradientData(a1: v34, a2: v70, a3: v66[7].sequence, a4: LODWORD(v72)));
  v69 = v35;
  if ( v35 == 0.0 )
    goto LABEL_75;
  v36 = v66;
  v37 = 0;
  *(float *)(LODWORD(v35) + 16) = v74;
  if ( v36[7].sequence <= 0 )
    goto LABEL_74;
  do
  {
    v38 = GASValue::ToUInt32(this: *((GASValue **)&v66[7].pNode->pNext + v37), a2: *(struct GASEnvironment **)(a3 + 24))
        | 0xFF000000;
    *((float *)&v71 + 1) = GASValue::ToNumber(
                             this: (GASValue *)*((_DWORD *)&v62[7].pNode->pNext + v37),
                             a2: (struct GASEnvironment *)*(_DWORD *)(a3 + 24));
    v39 = v38 & 0xFFFFFF;
    *((float *)&v71 + 1) = *((float *)&v71 + 1) * 255.0 / 100.0;
    v40 = *((float *)&v71 + 1);
    if ( *((float *)&v71 + 1) >= 255.0 )
    {
      v73 = 255.0;
    }
    else
    {
      v73 = *((float *)&v71 + 1);
      v41 = v40 > 0.0;
      v42 = 0.0 == v40;
      v43 = 0.0;
      if ( !v41 && !v42 )
        goto LABEL_69;
    }
    v43 = v73;
LABEL_69:
    v73 = v43;
    HIDWORD(v71) = HIWORD(v74) | 0xC00;
    v44 = v64[7].pNode;
    v56 = *(struct GASEnvironment **)(a3 + 24);
    v71 = (__int64)v73;
    v45 = ((_DWORD)v71 << 24) | v39;
    v72 = GASValue::ToNumber(this: (GASValue *)*((_DWORD *)&v44->pNext + v37), a2: v56);
    v46 = v72;
    if ( v72 >= 255.0 )
    {
      v73 = 255.0;
    }
    else
    {
      v73 = v72;
      v47 = v46 > 0.0;
      v48 = 0.0 == v46;
      v49 = 0.0;
      if ( !v47 && !v48 )
        goto LABEL_72;
    }
    v49 = v73;
LABEL_72:
    v50 = *(_DWORD *)(LODWORD(v69) + 12);
    v72 = v49;
    v51 = v66;
    v52 = v50 + 8 * v37++;
    HIDWORD(v71) = (int)v72;
    *(_BYTE *)v52 = BYTE4(v71);
    *(_DWORD *)(v52 + 4) = v45;
  }
  while ( v37 < v51[7].sequence );
  v35 = v69;
LABEL_74:
  GFxFillStyle::SetGradientFill(a1: v63, a2: v70, a3: LODWORD(v35), a4: &v76);
  GRefCountImpl::Release(this: (IShaderAPI *)LODWORD(v35));
LABEL_75:
  GASValue::~GASValue(this: v68);
LABEL_76:
  result = v65;
  v26 = v65[2]-- == (const char *)1;
  if ( v26 )
    return (const char **)GASStringNode::ReleaseNode().Sid;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B2290
// Name: GFx_SpriteBeginGradientFill
// Source: json
//------------------------------------------------------------------------------
const char **__usercall GFx_SpriteBeginGradientFill@<eax>(int a1@<ebx>, _CONNECTDLGSTRUCTW fn)
{
  int v2; // ecx
  const char **result; // eax
  int v4; // edi

  v2 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v2 != 0 )
  {
    result = (const char **)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( result != (const char **)2 )
      return result;
    result = *(const char ***)(fn.cbStructure + 8);
    if ( result == nullptr )
      return result;
    v4 = (int)(result - 30);
  }
  else
  {
    result = *(const char ***)(fn.cbStructure + 24);
    v4 = (int)result[29];
  }
  if ( v4 != 0 )
  {
    GFxSprite::AcquirePath(this: (GFxValue *)v4, a2: (Vector *)v4, newShapeFlag: 1u);
    result = (const char **)GFxDrawingContext::SetNewFill(this: *(GFxDrawingContext **)(v4 + 460));
    if ( result != nullptr )
      return GFx_SpriteCreateGradient(a1, a2: v4, a3: fn.cbStructure, a4: (int)result);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B22F0
// Name: GFx_SpriteLineGradientStyle
// Source: json
//------------------------------------------------------------------------------
const char **__usercall GFx_SpriteLineGradientStyle@<eax>(int a1@<ebx>, _CONNECTDLGSTRUCTW fn)
{
  int v2; // ecx
  const char **result; // eax
  int v4; // edi

  v2 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v2 != 0 )
  {
    result = (const char **)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( result != (const char **)2 )
      return result;
    result = *(const char ***)(fn.cbStructure + 8);
    if ( result == nullptr )
      return result;
    v4 = (int)(result - 30);
  }
  else
  {
    result = *(const char ***)(fn.cbStructure + 24);
    v4 = (int)result[29];
  }
  if ( v4 != 0 )
  {
    GFxSprite::AcquirePath(this: (GFxValue *)v4, a2: (Vector *)v4, newShapeFlag: 1u);
    result = (const char **)GFxDrawingContext::CreateLineComplexFill(this: *(GFxDrawingContext **)(v4 + 460));
    if ( result != nullptr )
      return GFx_SpriteCreateGradient(a1, a2: v4, a3: fn.cbStructure, a4: (int)result);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B2350
// Name: GFx_SpriteEndFill
// Source: json
//------------------------------------------------------------------------------
__int16 __usercall GFx_SpriteEndFill@<ax>(Vector *a1@<edi>, _CONNECTDLGSTRUCTW fn)
{
  int v2; // ecx
  int v3; // eax
  int v4; // esi

  v2 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v2 != 0 )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( v3 != 2 )
      return v3;
    v3 = *(_DWORD *)(fn.cbStructure + 8);
    if ( v3 == 0 )
      return v3;
    v4 = v3 - 120;
  }
  else
  {
    v3 = *(_DWORD *)(fn.cbStructure + 24);
    v4 = *(_DWORD *)(v3 + 116);
  }
  if ( v4 != 0 )
  {
    GFxSprite::AcquirePath(this: (GFxValue *)v4, a2: a1, newShapeFlag: 1u);
    LOWORD(v3) = GFxDrawingContext::SetNoFill(
                   this: *(IClientTools **)(v4 + 460),
                   a2: (CBaseHandle)fn.cbStructure,
                   a3: (int)fn.hwndOwner);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100B23A0
// Name: GFx_SpriteLineStyle
// Source: json
//------------------------------------------------------------------------------
void __usercall GFx_SpriteLineStyle(Vector *a1@<edi>, float alpha)
{
  const char **v2; // esi
  const char *v3; // ecx
  const char *v4; // eax
  GASValue *v5; // eax
  bool v6; // cc
  GASValue *v7; // eax
  unsigned int v8; // eax
  GASValue *v9; // eax
  double v10; // st7
  bool v11; // c0
  bool v12; // c3
  double v13; // st7
  const char *v14; // edi
  struct GASValue *v15; // eax
  const char *v16; // edi
  struct GASValue *v17; // eax
  const char **v18; // eax
  const char **v19; // edi
  bool v20; // zf
  const char *v21; // edi
  struct GASValue *v22; // eax
  const char **v23; // eax
  const char **v24; // edi
  GASValue *v25; // eax
  struct GASEnvironment *v26; // [esp+14h] [ebp-38h]
  struct GASEnvironment *v27; // [esp+18h] [ebp-34h]
  struct GASEnvironment *v28; // [esp+18h] [ebp-34h]
  struct GASEnvironment *v29; // [esp+18h] [ebp-34h]
  tagPOLYTEXTW *v30; // [esp+18h] [ebp-34h]
  float lineWidth; // [esp+24h] [ebp-28h]
  int hinting; // [esp+28h] [ebp-24h]
  __int64 v33; // [esp+2Ch] [ebp-20h] BYREF
  GFxValue *v34; // [esp+34h] [ebp-18h]
  CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *caps; // [esp+38h] [ebp-14h]
  CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *joins; // [esp+3Ch] [ebp-10h]
  CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *scaling; // [esp+40h] [ebp-Ch]
  unsigned int rgba; // [esp+44h] [ebp-8h]
  int miterLimit; // [esp+48h] [ebp-4h]

  v2 = (const char **)LODWORD(alpha);
  v3 = *(const char **)(LODWORD(alpha) + 8);
  if ( v3 != nullptr )
  {
    if ( (*(int (__thiscall **)(const char *))(*(_DWORD *)v3 + 8))(a1: v3) != 2 )
      return;
    v4 = v2[2];
    if ( v4 == nullptr )
      return;
    v34 = (GFxValue *)(v4 - 120);
  }
  else
  {
    v34 = *(GFxValue **)(*(_DWORD *)(LODWORD(alpha) + 24) + 116);
  }
  if ( v34 == nullptr )
    return;
  if ( (int)v2[7] > 0 )
  {
    v27 = (struct GASEnvironment *)v2[6];
    v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 0);
    lineWidth = GASValue::ToNumber(this: v5, a2: v27);
    v6 = (int)v2[7] <= 1;
    *(float *)&miterLimit = 3.0;
    rgba = -16777216;
    LOBYTE(hinting) = 0;
    scaling = nullptr;
    caps = nullptr;
    joins = nullptr;
    if ( v6
      || (v28 = (struct GASEnvironment *)v2[6],
          v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 1),
          v8 = GASValue::ToUInt32(this: v7, a2: v28),
          v6 = (int)v2[7] <= 2,
          rgba = v8 | 0xFF000000,
          v6) )
    {
LABEL_47:
      GFxSprite::SetLineStyle(this: v34, lineWidth, rgba, hinting, scaling, caps, joins, miterLimit);
      return;
    }
    v29 = (struct GASEnvironment *)v2[6];
    v9 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 2);
    alpha = GASValue::ToNumber(this: v9, a2: v29);
    rgba &= 0xFFFFFFu;
    alpha = alpha * 255.0 / 100.0;
    v10 = alpha;
    if ( alpha >= 255.0 )
    {
      alpha = 255.0;
    }
    else
    {
      v11 = v10 > 0.0;
      v12 = 0.0 == v10;
      v13 = 0.0;
      if ( !v11 && !v12 )
      {
LABEL_13:
        alpha = v13;
        v33 = (__int64)alpha;
        rgba |= (_DWORD)v33 << 24;
        if ( (int)v2[7] > 3 )
        {
          v30 = (tagPOLYTEXTW *)v2[6];
          GASFnCall::Arg(this: (GASFnCall *)v2, a2: 3);
          LOBYTE(hinting) = (unsigned __int8)GASValue::ToBool(result: v30);
          if ( (int)v2[7] > 4 )
          {
            v14 = v2[6];
            v15 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 4);
            GASValue::ToStringImpl(a1: v15, a2: &alpha, a3: v14, a4: -1, a5: 0);
            if ( GASString::operator==(this: (const char ***)&alpha, a2: (const char *)&stru_102A09D0) )
            {
              scaling = (CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)6;
            }
            else if ( GASString::operator==(this: (const char ***)&alpha, a2: "vertical") )
            {
              scaling = (CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)4;
            }
            else if ( GASString::operator==(this: (const char ***)&alpha, a2: "horizontal") )
            {
              scaling = (CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)2;
            }
            if ( (int)v2[7] > 5 )
            {
              v16 = v2[6];
              v17 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 5);
              GASValue::ToStringImpl(a1: v17, a2: (char *)&v33 + 4, a3: v16, a4: -1, a5: 0);
              v18 = (const char **)HIDWORD(v33);
              ++*(_DWORD *)(HIDWORD(v33) + 8);
              v19 = v18;
              v20 = (*(_DWORD *)(LODWORD(alpha) + 8))-- == 1;
              if ( v20 )
                GASStringNode::ReleaseNode();
              alpha = *(float *)&v19;
              v20 = (*(_DWORD *)(HIDWORD(v33) + 8))-- == 1;
              if ( v20 )
                GASStringNode::ReleaseNode();
              if ( GASString::operator==(this: (const char ***)&alpha, a2: (const char *)&stru_102A09D0) )
              {
                caps = (CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)64;
              }
              else if ( GASString::operator==(this: (const char ***)&alpha, a2: "square") )
              {
                caps = (CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)128;
              }
              if ( (int)v2[7] > 6 )
              {
                v21 = v2[6];
                v22 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 6);
                GASValue::ToStringImpl(a1: v22, a2: (char *)&v33 + 4, a3: v21, a4: -1, a5: 0);
                v23 = (const char **)HIDWORD(v33);
                ++*(_DWORD *)(HIDWORD(v33) + 8);
                v24 = v23;
                v20 = (*(_DWORD *)(LODWORD(alpha) + 8))-- == 1;
                if ( v20 )
                  GASStringNode::ReleaseNode();
                alpha = *(float *)&v24;
                v20 = (*(_DWORD *)(HIDWORD(v33) + 8))-- == 1;
                if ( v20 )
                  GASStringNode::ReleaseNode();
                if ( GASString::operator==(this: (const char ***)&alpha, a2: "miter") )
                {
                  joins = (CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)32;
                }
                else if ( GASString::operator==(this: (const char ***)&alpha, a2: "bevel") )
                {
                  joins = (CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)16;
                }
                if ( (int)v2[7] > 7 )
                {
                  v26 = (struct GASEnvironment *)v2[6];
                  v25 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 7);
                  *(float *)&miterLimit = GASValue::ToNumber(this: v25, a2: v26);
                  if ( *(float *)&miterLimit < 1.0 )
                    *(float *)&miterLimit = 1.0;
                  if ( *(float *)&miterLimit > 255.0 )
                    *(float *)&miterLimit = 255.0;
                }
              }
            }
            v20 = (*(_DWORD *)(LODWORD(alpha) + 8))-- == 1;
            if ( v20 )
              GASStringNode::ReleaseNode();
          }
        }
        goto LABEL_47;
      }
    }
    v13 = alpha;
    goto LABEL_13;
  }
  GFxSprite::SetNoLine(this: (GFxFontLib *)v34, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x100B2720
// Name: GFx_SpriteMoveTo
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteMoveTo(GASFnCall *y)
{
  GASFnCall v1; // ecx
  int v2; // edi
  GASFnCall v3; // eax
  GASValue *v4; // eax
  GASValue *v5; // eax
  struct GASEnvironment *v6; // [esp+4h] [ebp-10h]
  struct GASEnvironment *v7; // [esp+4h] [ebp-10h]
  float x; // [esp+10h] [ebp-4h]
  float ya; // [esp+1Ch] [ebp+8h]

  v1 = y[2];
  if ( v1 != nullptr )
  {
    if ( (*(int (__thiscall **)(GASFnCall))(v1->cbSize + 8))(a1: v1) != 2 )
      return;
    v3 = y[2];
    if ( v3 == nullptr )
      return;
    v2 = (int)&v3[-3];
  }
  else
  {
    v2 = y[6][2].ptStart.y;
  }
  if ( v2 != 0 && (int)y[7] >= 2 )
  {
    v6 = (struct GASEnvironment *)y[6];
    v4 = (GASValue *)GASFnCall::Arg(this: y, a2: 0);
    x = GASValue::ToNumber(this: v4, a2: v6);
    v7 = (struct GASEnvironment *)y[6];
    v5 = (GASValue *)GASFnCall::Arg(this: y, a2: 1);
    GASValue::ToNumber(this: v5, a2: v7);
    GFxSprite::AcquirePath(this: (GFxValue *)v2, a2: (Vector *)v2, newShapeFlag: 0);
    ya = 20.0 * x;
    GFxDrawingContext::MoveTo(this: *(IClientTools **)(v2 + 460), x: (void *)LODWORD(ya));
    GFxCharacter::InvalidateHitResult(this: (GFxCharacter *)v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B27E0
// Name: public: virtual enum GASObjectInterface::ObjectType GASMovieClipObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASMovieClipObject::GetObjectType()
{
  return 11;
}

//------------------------------------------------------------------------------
// Address: 0x100B2800
// Name: public: GWeakPtr<class GFxASCharacter>::operator class GPtr<class GFxASCharacter>(void)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__userpurge GWeakPtr<GFxASCharacter>::operator GPtr<GFxASCharacter>@<eax>(
        _DWORD **a1@<ecx>,
        _DWORD *a2,
        GMemoryHeap *a3,
        int a4,
        const char *a5,
        int a6)
{
  _DWORD *v7; // eax
  int v8; // ecx
  _DWORD *result; // eax

  v7 = *a1;
  if ( *a1 == nullptr )
  {
LABEL_8:
    *a2 = 0;
    return a2;
  }
  if ( v7[1] == 0 )
  {
    if ( (*v7)-- == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
    *a1 = nullptr;
    goto LABEL_8;
  }
  v8 = v7[1];
  result = a2;
  *a2 = v8;
  if ( v8 != 0 )
    ++*(_DWORD *)(v8 + 4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B2BF0
// Name: public: bool GFxMovieRoot::IsKeyboardFocused(class GFxASCharacter const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
BOOL __userpurge GFxMovieRoot::IsKeyboardFocused@<eax>(
        ISteamRemoteStorage *this@<ecx>,
        unsigned __int64 ch,
        void *controllerIdx,
        int a4)
{
  int v5; // esi
  _DWORD *v6; // eax
  GRefCountNTSImpl *v7; // edi
  bool controllerIdx_3; // [esp+17h] [ebp+Bh]

  v5 = 52 * (*((unsigned __int8 *)this + HIDWORD(ch) + 10228) + 181);
  v6 = *(ISteamRemoteStorage_vtbl **)((char *)&this->__vftable + v5);
  v7 = nullptr;
  if ( v6 != nullptr )
  {
    if ( v6[1] != 0 )
    {
      v7 = (GRefCountNTSImpl *)v6[1];
      if ( v7 != nullptr )
      {
        ++v7->RefCount;
        ++v7->RefCount;
        GRefCountNTSImpl::Release(this: v7);
      }
    }
    else
    {
      if ( (*v6)-- == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
      *(ISteamRemoteStorage_vtbl **)((char *)&this->__vftable + v5) = nullptr;
    }
  }
  controllerIdx_3 = v7 == (GRefCountNTSImpl *)ch;
  if ( v7 != nullptr )
    GRefCountNTSImpl::Release(this: v7);
  return controllerIdx_3 && *((_BYTE *)this + 52 * *((unsigned __int8 *)this + HIDWORD(ch) + 10228) + 9440) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B2C90
// Name: public: void GFxSprite::ExecuteFrame0Events(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::ExecuteFrame0Events(GFxFontLib *this)
{
  char result; // al
  const GPoint3<float> *inserted; // edi
  GRefCountNTSImpl *z_low; // ecx
  GRefCountNTSImpl *x_low; // ecx
  __int64 v6; // [esp+Ch] [ebp-8h]

  result = *((_BYTE *)this + 480);
  if ( (result & 8) == 0 )
  {
    *((_BYTE *)this + 480) = result | 8;
    GFxSprite::ExecuteFrameTags((GPtr<GFxZlibSupportBase> *)this, frame: nullptr);
    LOWORD(v6) = 0;
    *(_DWORD *)((char *)&v6 + 2) = 65280;
    inserted = GFxMovieRoot::ActionQueueType::InsertEntry(
                 this: *((_DWORD *)this + 47) + 9224,
                 result: (const GPoint3<float> *)5);
    LODWORD(inserted->y) = 2;
    ++this->RefCount;
    z_low = (GRefCountNTSImpl *)LODWORD(inserted->z);
    if ( z_low != nullptr )
      GRefCountNTSImpl::Release(this: z_low);
    LODWORD(inserted->z) = this;
    x_low = (GRefCountNTSImpl *)LODWORD(inserted[1].x);
    if ( x_low != nullptr )
      GRefCountNTSImpl::Release(this: x_low);
    inserted[1].x = 0.0;
    LODWORD(inserted[1].y) = 1;
    inserted[1].z = 0.0;
    *(_QWORD *)&inserted[2].x = v6;
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B2D30
// Name: public: virtual class GRect<float> GFxSprite::GetBounds(class GMatrix2D const __near &)const
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall GFxSprite::GetBounds(
        GPtr<GFxZlibSupportBase> *this,
        const GPtr<GFxZlibSupportBase> *transform,
        float *a3)
{
  GPtr<GFxZlibSupportBase> *v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // eax
  int v6; // edi
  int v7; // eax
  double v8; // st6
  double v9; // st5
  double v10; // st4
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // rtt
  double v15; // st6
  double v16; // st7
  double v17; // rt0
  IClientTools *pObject; // ecx
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double v23; // st7
  _BYTE v24[16]; // [esp+Ch] [ebp-64h] BYREF
  float v25; // [esp+1Ch] [ebp-54h]
  int v26; // [esp+20h] [ebp-50h]
  int v27; // [esp+24h] [ebp-4Ch]
  unsigned int i; // [esp+28h] [ebp-48h]
  unsigned int n; // [esp+2Ch] [ebp-44h]
  GPtr<GFxZlibSupportBase> *v30; // [esp+30h] [ebp-40h]
  float v31; // [esp+34h] [ebp-3Ch] BYREF
  float v32; // [esp+38h] [ebp-38h]
  float v33; // [esp+3Ch] [ebp-34h]
  float v34; // [esp+40h] [ebp-30h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> tempRect; // [esp+44h] [ebp-2Ch] BYREF
  float v36; // [esp+50h] [ebp-20h]
  GMatrix2D v37; // [esp+54h] [ebp-1Ch] BYREF

  v3 = this;
  v4 = *((_DWORD *)this + 50);
  *(float *)&transform->pObject = 0.0;
  *(float *)&transform[1].pObject = 0.0;
  *(float *)&transform[2].pObject = 0.0;
  v30 = this;
  *(float *)&transform[3].pObject = 0.0;
  n = v4;
  *(float *)&tempRect.m_pMemory = 0.0;
  *(float *)&tempRect.m_nAllocationCount = 0.0;
  *(float *)&tempRect.m_nGrowSize = 0.0;
  v36 = 0.0;
  GMatrix2D::SetIdentity(this: (float *)&v37);
  v5 = 0;
  for ( i = 0; v5 < n; i = v5 )
  {
    v6 = *((_DWORD *)&v3[49].pObject->__vftable + v5);
    if ( v6 != 0 )
    {
      v37.M_[0][0] = *a3;
      v37.M_[0][1] = a3[1];
      v37.M_[0][2] = a3[2];
      v37.M_[1][0] = a3[3];
      v37.M_[1][1] = a3[4];
      v37.M_[1][2] = a3[5];
      GMatrix2D::Prepend(this: &v37, a2: (const struct GMatrix2D *)(v6 + 68));
      v7 = (*(int (__thiscall **)(int, _BYTE *, GMatrix2D *))(*(_DWORD *)v6 + 52))(a1: v6, a2: v24, a3: &v37);
      v26 = *(int *)(v7 + 4);
      v27 = *(int *)(v7 + 8);
      v25 = *(float *)(v7 + 12);
      tempRect.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)v7;
      tempRect.m_nAllocationCount = v26;
      v8 = *(float *)&v27;
      tempRect.m_nGrowSize = v27;
      v9 = v25;
      v36 = v25;
      if ( *(float *)&tempRect.m_pMemory < (double)*(float *)&v27 && *(float *)&v26 < v9 )
      {
        if ( *(float *)&transform[2].pObject <= (double)*(float *)&transform->pObject
          || *(float *)&transform[3].pObject <= (double)*(float *)&transform[1].pObject )
        {
          v17 = *(float *)&v26;
          transform->pObject = (GFxZlibSupportBase *)tempRect.m_pMemory;
          *(float *)&transform[1].pObject = v17;
          *(float *)&transform[2].pObject = v8;
          *(float *)&transform[3].pObject = v9;
        }
        else
        {
          if ( *(float *)&transform->pObject <= (double)*(float *)&tempRect.m_pMemory )
          {
            v11 = *(float *)&v26;
            v10 = *(float *)&transform->pObject;
          }
          else
          {
            v10 = *(float *)&tempRect.m_pMemory;
            v11 = *(float *)&v26;
          }
          v31 = v10;
          if ( *(float *)&transform[2].pObject <= v8 )
          {
            v13 = *(float *)&v27;
            v12 = v25;
          }
          else
          {
            v12 = v25;
            v13 = *(float *)&transform[2].pObject;
          }
          v33 = v13;
          if ( *(float *)&transform[1].pObject <= v11 )
          {
            v16 = v12;
            v15 = *(float *)&transform[1].pObject;
          }
          else
          {
            v14 = v12;
            v15 = v11;
            v16 = v14;
          }
          v32 = v15;
          if ( *(float *)&transform[3].pObject > v16 )
            v16 = *(float *)&transform[3].pObject;
          v34 = v16;
          *(float *)&transform->pObject = v31;
          *(float *)&transform[1].pObject = v32;
          *(float *)&transform[2].pObject = v33;
          *(float *)&transform[3].pObject = v34;
        }
      }
    }
    v3 = v30;
    v5 = i + 1;
  }
  pObject = (IClientTools *)v3[115].pObject;
  if ( pObject != nullptr )
  {
    GFxDrawingContext::ComputeBound(this: pObject);
    if ( *(float *)&tempRect.m_nGrowSize > (double)*(float *)&tempRect.m_pMemory
      && v36 > (double)*(float *)&tempRect.m_nAllocationCount )
    {
      v31 = 0.0;
      v32 = 0.0;
      v33 = 0.0;
      v34 = 0.0;
      GMatrix2D::EncloseTransform(this: a3, a2: &v31, a3: (float *)&tempRect);
      if ( *(float *)&transform[2].pObject <= (double)*(float *)&transform->pObject
        || *(float *)&transform[3].pObject <= (double)*(float *)&transform[1].pObject )
      {
        *(float *)&transform->pObject = v31;
        *(float *)&transform[1].pObject = v32;
        *(float *)&transform[2].pObject = v33;
        v23 = v34;
      }
      else
      {
        v19 = v31;
        if ( v31 >= (double)*(float *)&transform->pObject )
          v19 = *(float *)&transform->pObject;
        *(float *)&tempRect.m_pMemory = v19;
        v20 = v33;
        if ( v33 < (double)*(float *)&transform[2].pObject )
          v20 = *(float *)&transform[2].pObject;
        *(float *)&tempRect.m_nGrowSize = v20;
        v21 = v32;
        if ( v32 >= (double)*(float *)&transform[1].pObject )
          v21 = *(float *)&transform[1].pObject;
        *(float *)&tempRect.m_nAllocationCount = v21;
        v22 = v34;
        if ( v34 < (double)*(float *)&transform[3].pObject )
          v22 = *(float *)&transform[3].pObject;
        v36 = v22;
        transform->pObject = (GFxZlibSupportBase *)tempRect.m_pMemory;
        transform[1].pObject = (GFxZlibSupportBase *)tempRect.m_nAllocationCount;
        transform[2].pObject = (GFxZlibSupportBase *)tempRect.m_nGrowSize;
        v23 = v36;
      }
      *(float *)&transform[3].pObject = v23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3010
// Name: public: virtual class GRect<float> GFxSprite::GetBounds(class GMatrix3D const __near &,bool)const
// Source: rtti_class
//------------------------------------------------------------------------------
GFxZlibSupportBase *__thiscall GFxSprite::GetBounds(
        unsigned int *this,
        GFxZlibSupportBase *result,
        float *a3,
        bool bDivideByW)
{
  unsigned int *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // eax
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v7; // eax
  float *v8; // eax
  int v9; // eax
  double v10; // st6
  double v11; // st5
  double v12; // st4
  double v13; // st7
  double v14; // st6
  double v15; // st5
  double v16; // rtt
  double v17; // st6
  double v18; // st7
  double v19; // rt0
  IClientTools *v20; // ecx
  double v21; // st7
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  _BYTE v27[16]; // [esp+Ch] [ebp-114h] BYREF
  int v28; // [esp+1Ch] [ebp-104h]
  unsigned int n; // [esp+20h] [ebp-100h]
  int v30; // [esp+24h] [ebp-FCh]
  unsigned int i; // [esp+28h] [ebp-F8h]
  float v32; // [esp+2Ch] [ebp-F4h]
  unsigned int *v33; // [esp+30h] [ebp-F0h]
  float *v34; // [esp+34h] [ebp-ECh]
  __vc_attributes::pointer_defaultAttribute v35; // [esp+38h] [ebp-E8h]
  CUtlMemory<unsigned short,int> v36; // [esp+3Ch] [ebp-E4h] BYREF
  float v37; // [esp+48h] [ebp-D8h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v38[4]; // [esp+4Ch] [ebp-D4h] BYREF
  GMatrix3D v39; // [esp+9Ch] [ebp-84h] BYREF
  GMatrix3D v40; // [esp+DCh] [ebp-44h] BYREF

  v4 = this;
  v5 = *(this + 50);
  *(float *)&result->__vftable = 0.0;
  *(float *)&result->RefCount = 0.0;
  LOBYTE(v32) = bDivideByW;
  *(float *)&result->SType = 0.0;
  *(float *)&result[1].__vftable = 0.0;
  v33 = this;
  *(float *)&v38[0].m_Memory.m_pMemory = 0.0;
  v34 = a3;
  *(float *)&v38[0].m_Memory.m_nAllocationCount = 0.0;
  n = v5;
  *(float *)&v38[0].m_Memory.m_nGrowSize = 0.0;
  *(float *)&v38[0].m_Size = 0.0;
  GMatrix3D::SetIdentity(this: &v40);
  v6 = 0;
  i = 0;
  if ( v5 != 0 )
  {
    do
    {
      v7 = *(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> **)(v4[49] + 4 * v6);
      v35.type = (__vc_attributes::pointer_defaultAttribute::type_e)v7;
      if ( *(float *)&v7 != 0.0 )
      {
        v40 = *(GMatrix3D *)v34;
        GFxCharacter::GetLocalMatrix3D(this: v7, a2: (CBasePerMaterialContextData *)&v38[0].m_pElements);
        v39 = v40;
        GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v40, a2: v8, a3: (float *)&v39);
        v9 = (*(int (__thiscall **)(__vc_attributes::pointer_defaultAttribute::type_e, _BYTE *, GMatrix3D *, float))(*(_DWORD *)v35.type + 60))(
               a1: v35.type,
               a2: v27,
               a3: &v40,
               a4: COERCE_FLOAT(LODWORD(v32)));
        v35.type = *(__vc_attributes::pointer_defaultAttribute::type_e *)(v9 + 4);
        v28 = *(int *)(v9 + 8);
        v30 = *(int *)(v9 + 12);
        v38[0].m_Memory.m_pMemory = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)v9;
        v38[0].m_Memory.m_nAllocationCount = v35.type;
        v10 = *(float *)&v28;
        v38[0].m_Memory.m_nGrowSize = v28;
        v11 = *(float *)&v30;
        v38[0].m_Size = v30;
        if ( *(float *)&v38[0].m_Memory.m_pMemory < (double)*(float *)&v28 && *(float *)&v35.type < v11 )
        {
          if ( *(float *)&result->SType <= (double)*(float *)&result->__vftable
            || *(float *)&result[1].__vftable <= (double)*(float *)&result->RefCount )
          {
            v19 = *(float *)&v35.type;
            result->__vftable = (GFxZlibSupportBase_vtbl *)v38[0].m_Memory.m_pMemory;
            *(float *)&result->RefCount = v19;
            *(float *)&result->SType = v10;
            *(float *)&result[1].__vftable = v11;
          }
          else
          {
            if ( *(float *)&result->__vftable <= (double)*(float *)&v38[0].m_Memory.m_pMemory )
            {
              v13 = *(float *)&v35.type;
              v12 = *(float *)&result->__vftable;
            }
            else
            {
              v12 = *(float *)&v38[0].m_Memory.m_pMemory;
              v13 = *(float *)&v35.type;
            }
            *(float *)&v36.m_pMemory = v12;
            if ( *(float *)&result->SType <= v10 )
            {
              v15 = *(float *)&v28;
              v14 = *(float *)&v30;
            }
            else
            {
              v14 = *(float *)&v30;
              v15 = *(float *)&result->SType;
            }
            *(float *)&v36.m_nGrowSize = v15;
            if ( *(float *)&result->RefCount <= v13 )
            {
              v18 = v14;
              v17 = *(float *)&result->RefCount;
            }
            else
            {
              v16 = v14;
              v17 = v13;
              v18 = v16;
            }
            *(float *)&v36.m_nAllocationCount = v17;
            if ( *(float *)&result[1].__vftable > v18 )
              v18 = *(float *)&result[1].__vftable;
            v37 = v18;
            *(CUtlMemory<unsigned short,int> *)result = v36;
            *(float *)&result[1].__vftable = v37;
          }
        }
      }
      v4 = v33;
      v6 = i + 1;
      i = v6;
    }
    while ( v6 < n );
  }
  v20 = (IClientTools *)v4[115];
  if ( v20 != nullptr )
  {
    GFxDrawingContext::ComputeBound(this: v20);
    if ( *(float *)&v38[0].m_Memory.m_nGrowSize > (double)*(float *)&v38[0].m_Memory.m_pMemory
      && *(float *)&v38[0].m_Size > (double)*(float *)&v38[0].m_Memory.m_nAllocationCount )
    {
      *(float *)&v36.m_pMemory = 0.0;
      *(float *)&v36.m_nAllocationCount = 0.0;
      *(float *)&v36.m_nGrowSize = 0.0;
      v37 = 0.0;
      GMatrix3D::EncloseTransform(
        this: v34,
        result: (const CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)&v36,
        r: v38,
        bDivideByW: v32);
      if ( *(float *)&result->SType <= (double)*(float *)&result->__vftable
        || *(float *)&result[1].__vftable <= (double)*(float *)&result->RefCount )
      {
        *(CUtlMemory<unsigned short,int> *)result = v36;
        v25 = v37;
      }
      else
      {
        v21 = *(float *)&v36.m_pMemory;
        if ( *(float *)&v36.m_pMemory >= (double)*(float *)&result->__vftable )
          v21 = *(float *)&result->__vftable;
        *(float *)&v38[0].m_Memory.m_pMemory = v21;
        v22 = *(float *)&v36.m_nGrowSize;
        if ( *(float *)&v36.m_nGrowSize < (double)*(float *)&result->SType )
          v22 = *(float *)&result->SType;
        *(float *)&v38[0].m_Memory.m_nGrowSize = v22;
        v23 = *(float *)&v36.m_nAllocationCount;
        if ( *(float *)&v36.m_nAllocationCount >= (double)*(float *)&result->RefCount )
          v23 = *(float *)&result->RefCount;
        *(float *)&v38[0].m_Memory.m_nAllocationCount = v23;
        v24 = v37;
        if ( v37 < (double)*(float *)&result[1].__vftable )
          v24 = *(float *)&result[1].__vftable;
        *(float *)&v38[0].m_Size = v24;
        *result = (GFxZlibSupportBase)v38[0].m_Memory;
        v25 = *(float *)&v38[0].m_Size;
      }
      *(float *)&result[1].__vftable = v25;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B33E0
// Name: public: virtual class GRect<float> GFxSprite::GetRectBounds(class GMatrix2D const __near &)const
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall GFxSprite::GetRectBounds(
        GPtr<GFxZlibSupportBase> *this,
        const GPtr<GFxZlibSupportBase> *transform,
        float *a3)
{
  GPtr<GFxZlibSupportBase> *v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // eax
  int v6; // edi
  int v7; // eax
  double v8; // st6
  double v9; // st5
  double v10; // st4
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // st7
  _BYTE v15[16]; // [esp+Ch] [ebp-58h] BYREF
  GPtr<GFxZlibSupportBase> *v16; // [esp+1Ch] [ebp-48h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> tempRect; // [esp+20h] [ebp-44h]
  float v18; // [esp+2Ch] [ebp-38h]
  unsigned int i; // [esp+30h] [ebp-34h]
  unsigned int n; // [esp+34h] [ebp-30h]
  float v21; // [esp+38h] [ebp-2Ch]
  float v22; // [esp+3Ch] [ebp-28h]
  float v23; // [esp+40h] [ebp-24h]
  float v24; // [esp+44h] [ebp-20h]
  GMatrix2D v25; // [esp+48h] [ebp-1Ch] BYREF

  v3 = this;
  v4 = *((_DWORD *)this + 50);
  *(float *)&transform->pObject = 0.0;
  *(float *)&transform[1].pObject = 0.0;
  *(float *)&transform[2].pObject = 0.0;
  v16 = this;
  *(float *)&transform[3].pObject = 0.0;
  n = v4;
  GMatrix2D::SetIdentity(this: (float *)&v25);
  v5 = 0;
  i = 0;
  if ( n != 0 )
  {
    while ( 1 )
    {
      v6 = *((_DWORD *)&v3[49].pObject->__vftable + v5);
      if ( v6 != 0 )
      {
        v25.M_[0][0] = *a3;
        v25.M_[0][1] = a3[1];
        v25.M_[0][2] = a3[2];
        v25.M_[1][0] = a3[3];
        v25.M_[1][1] = a3[4];
        v25.M_[1][2] = a3[5];
        GMatrix2D::Prepend(this: &v25, a2: (const struct GMatrix2D *)(v6 + 68));
        v7 = (*(int (__thiscall **)(int, _BYTE *, GMatrix2D *))(*(_DWORD *)v6 + 64))(a1: v6, a2: v15, a3: &v25);
        tempRect.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)v7;
        tempRect.m_nAllocationCount = *(int *)(v7 + 4);
        tempRect.m_nGrowSize = *(int *)(v7 + 8);
        v18 = *(float *)(v7 + 12);
        v8 = *(float *)&tempRect.m_nGrowSize;
        if ( *(float *)&tempRect.m_nGrowSize > (double)*(float *)&tempRect.m_pMemory )
        {
          v9 = *(float *)&tempRect.m_nAllocationCount;
          if ( v18 > (double)*(float *)&tempRect.m_nAllocationCount )
          {
            if ( *(float *)&transform[2].pObject <= (double)*(float *)&transform->pObject
              || *(float *)&transform[3].pObject <= (double)*(float *)&transform[1].pObject )
            {
              v14 = v18;
              transform->pObject = (GFxZlibSupportBase *)tempRect.m_pMemory;
              *(float *)&transform[1].pObject = v9;
              *(float *)&transform[2].pObject = v8;
              *(float *)&transform[3].pObject = v14;
            }
            else
            {
              if ( *(float *)&transform->pObject <= (double)*(float *)&tempRect.m_pMemory )
              {
                v11 = v18;
                v10 = *(float *)&transform->pObject;
              }
              else
              {
                v10 = *(float *)&tempRect.m_pMemory;
                v11 = v18;
              }
              v21 = v10;
              if ( *(float *)&transform[2].pObject <= v8 )
              {
                v13 = *(float *)&tempRect.m_nGrowSize;
                v12 = *(float *)&tempRect.m_nAllocationCount;
              }
              else
              {
                v12 = *(float *)&tempRect.m_nAllocationCount;
                v13 = *(float *)&transform[2].pObject;
              }
              v23 = v13;
              if ( *(float *)&transform[1].pObject <= v12 )
                v12 = *(float *)&transform[1].pObject;
              v22 = v12;
              if ( *(float *)&transform[3].pObject > v11 )
                v11 = *(float *)&transform[3].pObject;
              v24 = v11;
              *(float *)&transform->pObject = v21;
              *(float *)&transform[1].pObject = v22;
              *(float *)&transform[2].pObject = v23;
              *(float *)&transform[3].pObject = v24;
            }
          }
        }
      }
      v5 = i + 1;
      i = v5;
      if ( v5 >= n )
        break;
      v3 = v16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B35A0
// Name: public: virtual void GFxSprite::Restart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::Restart(GFxFontLib *this)
{
  int v2; // eax
  GImageInfo *v3; // eax
  GFxZlibSupportBase *v4; // [esp-4h] [ebp-Ch]

  GFxDisplayList::MarkAllEntriesForRemoval(result: nullptr);
  v2 = *((_DWORD *)this + 47);
  *((_DWORD *)this + 54) = 0;
  if ( v2 != 0 )
  {
    v3 = *(GImageInfo **)(v2 + 10308);
    if ( v3 != nullptr )
      GFxAmpViewStats::SetCurrentFrame(this: v3);
  }
  *((_BYTE *)this + 480) = *(_BYTE *)(this + 30) & 0xFC | 1;
  v4 = *((GFxZlibSupportBase **)this + 54);
  *((_BYTE *)this + 169) = 0;
  *((_DWORD *)this + 53) = 0;
  GFxSprite::ExecuteFrameTags((GPtr<GFxZlibSupportBase> *)this, frame: v4);
  GFxDisplayList::UnloadMarkedObjects(this: (GFxDisplayList *)((char *)this + 196));
  *(_DWORD *)(*((_DWORD *)this + 47) + 9332) |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x100B3630
// Name: public: virtual bool GFxSprite::OnKeyEvent(class GFxEventId const __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxSprite::OnKeyEvent@<al>(int a1@<ecx>, void *a2@<ebx>, int a3, int *pkeyMask)
{
  int (__stdcall *v6)(int); // edx
  int v7; // eax
  int (__thiscall *v8)(int, int *); // edx
  ISteamRemoteStorage *v9; // eax
  __int16 v10; // ax
  char v11; // al
  void (__thiscall *v12)(int, int *); // edx
  char v13; // cl
  void (__thiscall *v14)(int, int *); // edx
  unsigned __int64 v16; // [esp-Ch] [ebp-24h]
  int v17; // [esp+0h] [ebp-18h]
  int v18; // [esp+8h] [ebp-10h] BYREF
  int v19; // [esp+Ch] [ebp-Ch]
  __int16 v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+12h] [ebp-6h]
  char rv; // [esp+23h] [ebp+Bh]
  int *pkeyMaska; // [esp+24h] [ebp+Ch]

  v6 = *(int (__stdcall **)(int))(*(_DWORD *)a1 + 128);
  if ( *(_DWORD *)a3 != 64 )
    return v6(a1: a3);
  rv = v6(a1: a3);
  if ( (*pkeyMask & 0x10000) == 0 )
  {
    v7 = GFxEventId::ConvertToButtonKeyCode(this: (GFxEventId *)a3);
    if ( v7 != 0 )
    {
      v8 = *(int (__thiscall **)(int, int *))(*(_DWORD *)a1 + 128);
      v20 = v7;
      v18 = 0x20000;
      v19 = 0;
      v21 = 0;
      rv = v8(a1, a2: &v18);
      if ( rv != 0 )
        *pkeyMask |= 0x10000u;
    }
  }
  v9 = (ISteamRemoteStorage *)(*(int (__thiscall **)(int))(*(_DWORD *)a1 + 84))(a1);
  HIDWORD(v16) = *(char *)(a3 + 11);
  LODWORD(v16) = a1;
  pkeyMaska = (int *)v9;
  if ( GFxMovieRoot::IsKeyboardFocused(this: v9, ch: v16, controllerIdx: a2, a4: v17) )
  {
    v10 = *(_WORD *)(a3 + 8);
    if ( (v10 == 13 || v10 == 32)
      && ((*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)a1 + 216))(a1) != 0
       || (((unsigned int)pkeyMaska[2333] >> 26) & 3) == 1) )
    {
      v11 = *(_BYTE *)(a3 + 11);
      v20 = 13;
      v12 = *(void (__thiscall **)(int, int *))(*(_DWORD *)a1 + 128);
      BYTE1(v21) = v11;
      v18 = 1024;
      v19 = 0;
      LOBYTE(v21) = 0;
      HIWORD(v21) = 0;
      v12(a1, a2: &v18);
      v13 = *(_BYTE *)(a3 + 11);
      v14 = *(void (__thiscall **)(int, int *))(*(_DWORD *)a1 + 128);
      v20 = 13;
      BYTE1(v21) = v13;
      v18 = 2048;
      v19 = 0;
      LOBYTE(v21) = 0;
      HIWORD(v21) = 0;
      v14(a1, a2: &v18);
    }
  }
  return rv;
}

//------------------------------------------------------------------------------
// Address: 0x100B3780
// Name: public: virtual bool GFxSprite::OnEvent(class GFxEventId const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::OnEvent(GMemoryFile *this, float *id)
{
  int v3; // eax
  char v5; // cl
  float v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  ISteamRemoteStorage *v10; // eax
  bool v11; // zf
  int v12; // eax
  const GPoint3<float> *inserted; // esi
  float v14; // ecx
  float v15; // edx
  float v16; // eax
  float v17; // ebx
  GRefCountNTSImpl *z_low; // ecx
  GRefCountNTSImpl *x_low; // ecx
  float v20; // ecx
  float v21; // edx
  float v22; // eax
  unsigned __int64 v24; // [esp-8h] [ebp-34h]
  void *v25; // [esp+0h] [ebp-2Ch]
  int v26; // [esp+4h] [ebp-28h]
  GASValue method[4]; // [esp+8h] [ebp-24h] BYREF
  float v28; // [esp+18h] [ebp-14h]
  float v29; // [esp+1Ch] [ebp-10h]
  float v30; // [esp+20h] [ebp-Ch]
  int v31; // [esp+28h] [ebp-4h] BYREF
  bool hasMethod; // [esp+37h] [ebp+Bh]

  if ( (*((_BYTE *)this + 480) & 0x40) != 0 )
    v3 = *((_DWORD *)this + 46);
  else
    v3 = 0;
  if ( v3 == 0 )
    goto LABEL_13;
  v5 = *(_BYTE *)(v3 + 52);
  if ( (v5 & 7) == 0 )
    goto LABEL_13;
  v6 = *id;
  if ( *(_DWORD *)id > 0x2000u )
  {
    if ( LODWORD(v6) == 0x4000 )
    {
LABEL_11:
      if ( (v5 & 1) != 0 )
        GFxSprite::GotoLabeledFrame((GPtr<GFxZlibSupportBase> *)this, label: &label, offset: 0);
      goto LABEL_13;
    }
    if ( LODWORD(v6) != 0x10000 )
      goto LABEL_13;
    goto LABEL_37;
  }
  if ( *(_DWORD *)id == 0x2000 )
  {
LABEL_37:
    if ( (v5 & 4) != 0 )
      GFxSprite::GotoLabeledFrame(
        (GPtr<GFxZlibSupportBase> *)this,
        label: (const GPtr<GFxZlibSupportBase> *)&stru_102A09D0.m_Size,
        offset: 0);
    goto LABEL_13;
  }
  if ( LODWORD(v6) != 1024 )
  {
    if ( LODWORD(v6) != 2048 )
    {
      if ( LODWORD(v6) != 4096 )
        goto LABEL_13;
      goto LABEL_11;
    }
    goto LABEL_37;
  }
  if ( (v5 & 2) != 0 )
    GFxSprite::GotoLabeledFrame(
      (GPtr<GFxZlibSupportBase> *)this,
      label: (const GPtr<GFxZlibSupportBase> *)"_down",
      offset: 0);
LABEL_13:
  if ( GFxASCharacter::HasClipEventHandler((GFxASCharacter *)this, a2: (const struct GFxEventId *)id) )
  {
LABEL_26:
    v12 = ((int (__thiscall *)(GMemoryFile *))this->__vftable[1].IsValid)(a1: this);
    inserted = GFxMovieRoot::ActionQueueType::InsertEntry(this: v12 + 9224, result: (const GPoint3<float> *)4);
    if ( inserted != nullptr )
    {
      v14 = *id;
      v15 = id[1];
      v16 = id[2];
      v17 = id[3];
      LODWORD(inserted->y) = 2;
      ++this->RefCount;
      v28 = v14;
      z_low = (GRefCountNTSImpl *)LODWORD(inserted->z);
      v29 = v15;
      v30 = v16;
      if ( z_low != nullptr )
        GRefCountNTSImpl::Release(this: z_low);
      LODWORD(inserted->z) = this;
      x_low = (GRefCountNTSImpl *)LODWORD(inserted[1].x);
      if ( x_low != nullptr )
        GRefCountNTSImpl::Release(this: x_low);
      v20 = v28;
      v21 = v29;
      v22 = v30;
      inserted[1].x = 0.0;
      inserted[1].y = v20;
      inserted[1].z = v21;
      inserted[2].x = v22;
      inserted[2].y = v17;
    }
    return 1;
  }
  v7 = ((int (__thiscall *)(GMemoryFile *))this->__vftable[1].Write)(a1: this);
  GFxEventId::GetFunctionName(this: (unsigned int *)id, a2: &v31, psc: (_DWORD *)(v7 + 120));
  v8 = v31;
  if ( *(_DWORD *)(v31 + 16) != 0 )
  {
    v9 = *((_DWORD *)this + 113);
    hasMethod = false;
    LOBYTE(method[0]) = 0;
    if ( (v9 != 0 || (v9 = *((_DWORD *)this + 32)) != 0)
      && (*(unsigned __int8 (__thiscall **)(int, char *, int *, GASValue *))(*(_DWORD *)(v9 + 16) + 44))(
           a1: v9 + 16,
           a2: (char *)this + 352,
           a3: &v31,
           a4: method) != 0 )
    {
      hasMethod = true;
    }
    if ( *(_DWORD *)id != 64 && *(_DWORD *)id != 128
      || *((_BYTE *)this + 356) >= 6u
      && (HIDWORD(v24) = *((char *)id + 11),
          LODWORD(v24) = this,
          v10 = (ISteamRemoteStorage *)((int (__thiscall *)(GMemoryFile *))this->__vftable[1].IsValid)(a1: this),
          GFxMovieRoot::IsKeyboardFocused(this: v10, ch: v24, controllerIdx: v25, a4: v26)) )
    {
      if ( hasMethod )
      {
        GASValue::~GASValue(this: method);
        v11 = (*(_DWORD *)(v31 + 8))-- == 1;
        if ( v11 )
          GASStringNode::ReleaseNode();
        goto LABEL_26;
      }
    }
    GASValue::~GASValue(this: method);
    v8 = v31;
  }
  v11 = (*(_DWORD *)(v8 + 8))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B39A0
// Name: public: virtual void GFxSprite::OnInsertionAsLevel(int)
// Source: json
//------------------------------------------------------------------------------
const GFxZlibSupportBase *__thiscall GFxSprite::OnInsertionAsLevel(
        const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **this,
        const GFxZlibSupportBase *result)
{
  int v3; // eax
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v4; // edi
  const GFxZlibSupportBase *v5; // eax

  if ( result != nullptr )
  {
    if ( (int)result > 0 )
    {
      v3 = ((int (__thiscall *)(const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **, _DWORD))DWORD1((*this)[4].m_pfnProxied))(
             a1: this,
             a2: 0);
      if ( v3 != 0 )
      {
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 216))(a1: v3) != 0 )
          *(this + 40) = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)((unsigned int)*(this + 40) | 0x180);
        else
          *(this + 40) = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)((unsigned int)*(this + 40) & 0xFFFFFE7F | 0x100);
      }
    }
  }
  else
  {
    *(this + 40) = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)((unsigned int)*(this + 40) | 0x180);
  }
  GFxASCharacter::AddToPlayList(this, result: *(this + 47));
  v4 = *(this + 47);
  v5 = (const GFxZlibSupportBase *)GFxSprite::CheckAdvanceStatus(
                                     (GFxSprite *)this,
                                     a2: ((unsigned int)*(this + 40) & 0x80000) != 0);
  if ( v5 == (const GFxZlibSupportBase *)-1 )
  {
    GFxASCharacter::RemoveFromOptimizedPlaylist((CMatQueuedMesh **)this, result: v4);
    *((_WORD *)this + 83) = -1;
    return (const GFxZlibSupportBase *)0xFFFF;
  }
  else
  {
    if ( v5 == (const GFxZlibSupportBase *)1 )
      v5 = (const GFxZlibSupportBase *)GFxASCharacter::AddToOptimizedPlayList((int)this, result: v4);
    *((_WORD *)this + 83) = -1;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100B3A80
// Name: public: virtual void GFxSprite::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetVisible(GFxSprite *this, bool visible)
{
  bool v3; // cl
  int v4; // eax
  unsigned int v5; // eax
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v6; // edi
  int v7; // eax
  int v8; // eax

  if ( visible )
  {
    *(this + 40) = (GFxSprite)((unsigned int)*(this + 40) | 1);
    v3 = false;
  }
  else
  {
    *(this + 40) = (GFxSprite)((unsigned int)*(this + 40) & 0xFFFFFFFE);
    v3 = ((*(this + 47))[583].RefCount & 0x800) != 0;
  }
  v4 = (int)*(this + 40);
  if ( v3 != ((v4 & 8) != 0) )
  {
    if ( v3 )
      v5 = v4 | 8;
    else
      v5 = v4 & 0xFFFFFFF7;
    *(this + 40) = (GFxSprite)v5;
    v6 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)*(this + 47);
    v7 = GFxSprite::CheckAdvanceStatus(this, a2: (v5 & 0x80000) != 0);
    if ( v7 == -1 )
    {
      GFxASCharacter::RemoveFromOptimizedPlaylist((CMatQueuedMesh **)this, result: v6);
    }
    else if ( v7 == 1 )
    {
      GFxASCharacter::AddToOptimizedPlayList((int)this, result: v6);
    }
    v8 = (int)*(this + 8);
    if ( v8 != 0 && (*(_DWORD *)(v8 + 160) & 8) == 0 )
      ((void (__thiscall *)(GFxSprite *))(*this)[18].pObjectInterface)(a1: this);
  }
  (*(this + 47))[583].RefCount |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x100B3B50
// Name: GFx_SpriteStartDrag
// Source: json
//------------------------------------------------------------------------------
CMatQueuedMesh *__cdecl GFx_SpriteStartDrag(int lockCenter)
{
  int v2; // ecx
  CMatQueuedMesh *result; // eax
  int p_m_pVertexData; // edi
  GASValue *v5; // eax
  GASValue *v6; // eax
  GASValue *v7; // eax
  GASValue *v8; // eax
  double v9; // st7
  double v10; // st6
  double v11; // st5
  double v12; // st4
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v13; // esi
  tagPOLYTEXTW *v14; // [esp-4h] [ebp-44h]
  struct GASEnvironment *v15; // [esp-4h] [ebp-44h]
  struct GASEnvironment *v16; // [esp-4h] [ebp-44h]
  struct GASEnvironment *v17; // [esp-4h] [ebp-44h]
  struct GASEnvironment *v18; // [esp-4h] [ebp-44h]
  int v19; // [esp+Ch] [ebp-34h] BYREF
  __int16 v20; // [esp+10h] [ebp-30h]
  float v21; // [esp+14h] [ebp-2Ch]
  float v22; // [esp+18h] [ebp-28h]
  float v23; // [esp+1Ch] [ebp-24h]
  float v24; // [esp+20h] [ebp-20h]
  float v25; // [esp+24h] [ebp-1Ch]
  float v26; // [esp+28h] [ebp-18h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> bounds; // [esp+2Ch] [ebp-14h]
  int v28; // [esp+38h] [ebp-8h]
  CMatRenderContextBase::MatrixStackItem_t *m_pMemory; // [esp+3Ch] [ebp-4h]
  unsigned __int8 lockCentera; // [esp+48h] [ebp+8h]

  v2 = *(_DWORD *)(lockCenter + 8);
  if ( v2 != 0 )
  {
    result = (CMatQueuedMesh *)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( result != (CMatQueuedMesh *)2 )
      return result;
    result = *(CMatQueuedMesh **)(lockCenter + 8);
    if ( result == nullptr )
      return result;
    p_m_pVertexData = (int)&result[-2].m_pVertexData;
  }
  else
  {
    result = *(CMatQueuedMesh **)(lockCenter + 24);
    p_m_pVertexData = HIDWORD(result[1].m_VertexFormat);
  }
  if ( p_m_pVertexData != 0 )
  {
    v19 = 0;
    v22 = 0.0;
    v20 = 0;
    v21 = 0.0;
    lockCentera = 0;
    v24 = 0.0;
    v23 = 0.0;
    v26 = 0.0;
    v25 = 0.0;
    if ( *(int *)(lockCenter + 28) > 0 )
    {
      v14 = *(tagPOLYTEXTW **)(lockCenter + 24);
      GASFnCall::Arg(this: (GASFnCall *)lockCenter, a2: 0);
      lockCentera = (unsigned __int8)GASValue::ToBool(result: v14);
      if ( *(int *)(lockCenter + 28) > 4 )
      {
        v15 = *(struct GASEnvironment **)(lockCenter + 24);
        HIBYTE(v20) = 1;
        v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)lockCenter, a2: 1);
        *(float *)&m_pMemory = GASValue::ToNumber(this: v5, a2: v15);
        v16 = *(struct GASEnvironment **)(lockCenter + 24);
        *(float *)&bounds.m_pMemory = *(float *)&m_pMemory * 20.0;
        v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)lockCenter, a2: 2);
        *(float *)&m_pMemory = GASValue::ToNumber(this: v6, a2: v16);
        v17 = *(struct GASEnvironment **)(lockCenter + 24);
        *(float *)&bounds.m_nAllocationCount = *(float *)&m_pMemory * 20.0;
        v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)lockCenter, a2: 3);
        *(float *)&m_pMemory = GASValue::ToNumber(this: v7, a2: v17);
        v18 = *(struct GASEnvironment **)(lockCenter + 24);
        *(float *)&bounds.m_nGrowSize = *(float *)&m_pMemory * 20.0;
        v8 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)lockCenter, a2: 4);
        *(float *)&m_pMemory = GASValue::ToNumber(this: v8, a2: v18);
        *(float *)&v28 = *(float *)&m_pMemory * 20.0;
        v9 = *(float *)&bounds.m_pMemory;
        v10 = *(float *)&bounds.m_nGrowSize;
        if ( *(float *)&bounds.m_nGrowSize < (double)*(float *)&bounds.m_pMemory )
        {
          m_pMemory = bounds.m_pMemory;
          bounds.m_pMemory = (CMatRenderContextBase::MatrixStackItem_t *)bounds.m_nGrowSize;
          bounds.m_nGrowSize = (int)m_pMemory;
          v9 = *(float *)&bounds.m_pMemory;
          v10 = *(float *)&m_pMemory;
        }
        v11 = *(float *)&bounds.m_nAllocationCount;
        v12 = *(float *)&v28;
        if ( *(float *)&v28 < (double)*(float *)&bounds.m_nAllocationCount )
        {
          m_pMemory = (CMatRenderContextBase::MatrixStackItem_t *)bounds.m_nAllocationCount;
          bounds.m_nAllocationCount = v28;
          v28 = (int)m_pMemory;
          v11 = *(float *)&bounds.m_nAllocationCount;
          v12 = *(float *)&m_pMemory;
        }
        v21 = v9;
        v22 = v11;
        v23 = v10;
        v24 = v12;
      }
    }
    v19 = p_m_pVertexData;
    GFxMovieRoot::DragState::InitCenterDelta(
      this: (GFxMovieRoot::DragState *)&v19,
      a2: (const CMaterialDict::MissingMaterial_t *)p_m_pVertexData,
      a3: lockCentera);
    v13 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)(*(int (__thiscall **)(int))(*(_DWORD *)p_m_pVertexData + 84))(a1: p_m_pVertexData);
    GFxMovieRoot::SetDragState(this: (int)v13, st: (ScaleformRenderer::VertexShaderType)&v19);
    result = (CMatQueuedMesh *)GFxSprite::CheckAdvanceStatus(
                                 this: (GFxSprite *)p_m_pVertexData,
                                 a2: (*(_DWORD *)(p_m_pVertexData + 160) & 0x80000) != 0);
    if ( result == (CMatQueuedMesh *)-1 )
    {
      return GFxASCharacter::RemoveFromOptimizedPlaylist(this: (CMatQueuedMesh **)p_m_pVertexData, result: v13);
    }
    else if ( result == (CMatQueuedMesh *)1 )
    {
      return GFxASCharacter::AddToOptimizedPlayList(this: p_m_pVertexData, result: v13);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B3D30
// Name: GFx_SpriteStopDrag
// Source: json
//------------------------------------------------------------------------------
CMatQueuedMesh *__cdecl GFx_SpriteStopDrag(_CONNECTDLGSTRUCTW fn)
{
  int v1; // ecx
  CMatQueuedMesh *result; // eax
  int p_m_pVertexData; // esi
  int v4; // edi

  v1 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v1 != 0 )
  {
    result = (CMatQueuedMesh *)(*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1);
    if ( result != (CMatQueuedMesh *)2 )
      return result;
    result = *(CMatQueuedMesh **)(fn.cbStructure + 8);
    if ( result == nullptr )
      return result;
    p_m_pVertexData = (int)&result[-2].m_pVertexData;
  }
  else
  {
    result = *(CMatQueuedMesh **)(fn.cbStructure + 24);
    p_m_pVertexData = HIDWORD(result[1].m_VertexFormat);
  }
  if ( p_m_pVertexData != 0 )
  {
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)p_m_pVertexData + 84))(a1: p_m_pVertexData);
    *(_DWORD *)(v4 + 9188) = 0;
    result = (CMatQueuedMesh *)GFxSprite::CheckAdvanceStatus(
                                 this: (GFxSprite *)p_m_pVertexData,
                                 a2: (*(_DWORD *)(p_m_pVertexData + 160) & 0x80000) != 0);
    if ( result == (CMatQueuedMesh *)-1 )
    {
      return GFxASCharacter::RemoveFromOptimizedPlaylist(
               this: (CMatQueuedMesh **)p_m_pVertexData,
               result: (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)v4);
    }
    else if ( result == (CMatQueuedMesh *)1 )
    {
      return GFxASCharacter::AddToOptimizedPlayList(
               this: p_m_pVertexData,
               result: (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)v4);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B3E90
// Name: public: void GFxSprite::SetIMECandidateListFont(class GFxFontResource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetIMECandidateListFont(GFxSprite *this, int a2)
{
  int v3; // eax
  struct GFxFontResource *v4; // esi
  __int16 *v5; // ecx
  __int16 *v6; // eax
  struct GFxMovieDef *v7; // edi
  GFxASUserData_vtbl *v8; // ecx
  int (__thiscall *v9)(GFxASUserData_vtbl *, int, int *); // edx
  GFxFontHandle *v10; // eax
  struct GFxFontHandle *v11; // edi
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *FontHandle; // esi
  GFxASUserData_vtbl *v13; // ecx
  int (__thiscall *v14)(GFxASUserData_vtbl *, int, int *); // eax
  GFxFontHandle *v15; // eax
  GFxFontHandle *v16; // eax
  bool v17; // zf

  if ( *(this + 111) == (GFxSprite)9999 )
  {
    v3 = (int)*(this + 112);
    if ( v3 != 0 && *(_DWORD *)(v3 + 28) != 0 )
    {
      v4 = (struct GFxFontResource *)a2;
      v5 = *(__int16 **)(a2 + 12);
      v6 = *(__int16 **)(a2 + 20);
      if ( (*((_DWORD *)v5 + 5) & 0x40) != 0 )
      {
        (*(void (**)(void))(*(_DWORD *)v5 + 60))();
        FontHandle = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)GFxFontManager::CreateFontHandle(this: (CDefaultClientRenderable *)(*(this + 112))[1].pData);
        if ( FontHandle == nullptr )
          return;
        v13 = (*(this + 47))[2].__vftable;
        v14 = *((int (__thiscall **)(GFxASUserData_vtbl *, int, int *))v13->dtr_GRefCountImplCore + 10);
        a2 = 326;
        v15 = (GFxFontHandle *)v14(a1: v13, a2: 36, a3: &a2);
        if ( v15 != nullptr )
          v16 = GFxFontHandle::GFxFontHandle(
                  this: v15,
                  a2: nullptr,
                  a3: (struct GFxFontResource *)DWORD1(FontHandle[1].m_pfnProxied),
                  a4: "$IMECandidateListFont",
                  a5: 0,
                  a6: (struct GFxMovieDef *)DWORD2(FontHandle[1].m_pfnProxied));
        else
          v16 = nullptr;
        v17 = LODWORD(FontHandle->m_pfnProxied)-- == 1;
        v11 = v16;
        if ( v17 )
        {
          GFxFontHandle::~GFxFontHandle(this: FontHandle);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: FontHandle);
        }
      }
      else
      {
        if ( v6 != nullptr )
          v7 = *((struct GFxMovieDef **)v6 + 10);
        else
          v7 = nullptr;
        v8 = (*(this + 47))[2].__vftable;
        v9 = *((int (__thiscall **)(GFxASUserData_vtbl *, int, int *))v8->dtr_GRefCountImplCore + 10);
        a2 = 326;
        v10 = (GFxFontHandle *)v9(a1: v8, a2: 36, a3: &a2);
        if ( v10 != nullptr )
          v11 = GFxFontHandle::GFxFontHandle(this: v10, a2: nullptr, a3: v4, a4: "$IMECandidateListFont", a5: 0, a6: v7);
        else
          v11 = nullptr;
      }
      if ( v11 != nullptr )
      {
        GFxFontManager::SetIMECandidateFont(this: (GFxFontManager *)(*(this + 112))[1].pData, a2: v11);
        v17 = (*(_DWORD *)v11)-- == 1;
        if ( v17 )
        {
          GFxFontHandle::~GFxFontHandle(this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)v11);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B4280
// Name: public: GFxTimelineSnapshot::GFxTimelineSnapshot(enum GFxTimelineSnapshot::DirectionType,class GMemoryHeap __near *,class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxTimelineSnapshot::GFxTimelineSnapshot(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *result; // eax
  _DWORD *v5; // ecx

  result = this;
  *this = 0;
  *(this + 1) = 0;
  *(this + 3) = 0;
  *(this + 4) = a3;
  *(this + 2) = 50;
  *(this + 5) = 0;
  *(this + 6) = 0;
  *(this + 7) = 0;
  *(this + 8) = a3;
  v5 = this + 9;
  *v5 = v5;
  v5[1] = v5;
  result[11] = a4;
  result[12] = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B42C0
// Name: public: GFxTimelineSnapshot::~GFxTimelineSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTimelineSnapshot::~GFxTimelineSnapshot(GFxTimelineSnapshot *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  _DWORD *v4; // edx
  _DWORD *v5; // eax
  _DWORD *v6; // esi

  v2 = *((_DWORD **)this + 10);
  v3 = (_DWORD *)((char *)this + 36);
  if ( v2 != v3 )
  {
    do
    {
      v4 = (_DWORD *)v2[1];
      *v2 = *((_DWORD *)this + 3);
      *((_DWORD *)this + 3) = v2;
      v2 = v4;
    }
    while ( v4 != v3 );
  }
  *v3 = v3;
  v3[1] = v3;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 5));
  v5 = *(_DWORD **)this;
  if ( *(_DWORD *)this != 0 )
  {
    do
    {
      v6 = (_DWORD *)v5[700];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
      v5 = v6;
    }
    while ( v6 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B4320
// Name: public: struct GFxTimelineSnapshot::SnapshotElement __near * GFxTimelineSnapshot::Add(int)
// Source: json
//------------------------------------------------------------------------------
struct GFxTimelineSnapshot::SnapshotElement *__thiscall GFxTimelineSnapshot::Add(GFxTimelineSnapshot *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int *v5; // edi
  unsigned int v6; // eax
  _DWORD *v8; // [esp+8h] [ebp-4h] BYREF

  v3 = (_DWORD *)GListAllocBase<GFxTimelineSnapshot::SnapshotElement,50,GAllocatorDH<GFxTimelineSnapshot::SnapshotElement,2>>::Alloc();
  v4 = v3;
  v8 = v3;
  if ( v3 == nullptr )
    return nullptr;
  *v3 = *((_DWORD *)this + 9);
  v3[1] = (char *)this + 36;
  *(_DWORD *)(*((_DWORD *)this + 9) + 4) = v3;
  *((_DWORD *)this + 9) = v3;
  v5 = (int *)((char *)this + 20);
  v3[3] = a2;
  v6 = G_UpperBoundSliced<GArrayDH_POD<GFxTimelineSnapshot::SnapshotElement *,2,GArrayDefaultPolicy>,int,int (__cdecl *)(int,GFxTimelineSnapshot::SnapshotElement const *)>(
         a1: v5,
         a2: 0,
         a3: v5[1],
         a4: &a2,
         a5: (int (__cdecl *)(_DWORD, _DWORD))GFxTimelineSnapshot::DepthLess);
  GArrayBase<GArrayDataDH<GFxTimelineSnapshot::SnapshotElement *,GAllocatorDH_POD<GFxTimelineSnapshot::SnapshotElement *,2>,GArrayDefaultPolicy>>::InsertAt(
    this: v5,
    a2: v6,
    a3: &v8);
  return (struct GFxTimelineSnapshot::SnapshotElement *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x100B4390
// Name: public: void GFxSpriteDef::Read(class GFxLoadProcess __near *,class GFxResourceId)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSpriteDef::Read(GFxSpriteDef *this, struct GFxLoadProcess *p, struct GFxResourceId a3)
{
  GFxLoadProcess *v3; // esi
  IShaderDeviceMgr *v4; // edi
  GFxSpriteDef *v5; // ebx
  unsigned int v6; // eax
  int v7; // eax
  IShaderDeviceMgr_vtbl *v8; // eax
  unsigned __int16 v9; // dx
  unsigned int v10; // eax
  GFxLoadProcess v11; // eax
  unsigned int Version; // esi
  int v13; // ebx
  void *v14; // esi
  void *v15; // esi
  int v16; // esi
  GRefCountBaseStatImpl<GRefCountImpl,326> *v17; // ecx
  INetChannel *v18; // ebx
  unsigned int v19; // esi
  unsigned int v20; // esi
  const char *(__thiscall **i)(struct INetChannel *); // eax
  void (__thiscall *v22)(CUtlDict<ITextureInternal *,unsigned short> *, unsigned __int16, HBITMAP__); // ecx
  GFxLoadProcess v23; // eax
  int v24; // eax
  ShaderDisplayMode_t *v25; // [esp+0h] [ebp-54h]
  int v26; // [esp+4h] [ebp-50h]
  _DWORD v27[5]; // [esp+Ch] [ebp-48h] BYREF
  int v28; // [esp+20h] [ebp-34h]
  int v29; // [esp+24h] [ebp-30h]
  unsigned int v30; // [esp+28h] [ebp-2Ch]
  GString v31; // [esp+2Ch] [ebp-28h] BYREF
  unsigned int tagEnd; // [esp+30h] [ebp-24h]
  GFxSpriteDef *v33; // [esp+34h] [ebp-20h]
  GRefCountBaseStatImpl<GRefCountImpl,326> *v34; // [esp+38h] [ebp-1Ch]
  unsigned __int16 prenderer[2]; // [esp+3Ch] [ebp-18h]
  GRefCountBaseStatImpl<GRefCountImpl,326> *tagInfo; // [esp+40h] [ebp-14h] BYREF
  int v37; // [esp+44h] [ebp-10h]
  int v38; // [esp+48h] [ebp-Ch]
  int v39; // [esp+4Ch] [ebp-8h]

  v3 = (GFxLoadProcess *)p;
  v4 = *((IShaderDeviceMgr **)p + 201);
  v5 = this;
  v33 = this;
  *(_DWORD *)prenderer = p;
  if ( v4 == nullptr )
    v4 = (IShaderDeviceMgr *)((char *)p + 40);
  GFxStream::GetTagEndPosition(this: v4, a2: v25, a3: v26);
  *((_DWORD *)p + 190) = 1;
  *((_DWORD *)p + 191) = v5;
  tagEnd = v6;
  v7 = (char *)v4[12].__vftable - (char *)v4[11].__vftable;
  BYTE1(v4[5].__vftable) = 0;
  if ( v7 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v8 = v4[11].__vftable;
  v9 = *(_WORD *)((char *)&v4[15].Connect + (unsigned int)v8);
  v4[11].__vftable = (IShaderDeviceMgr_vtbl *)((char *)&v8->Connect + 2);
  *((_DWORD *)v5 + 6) = v9;
  if ( v9 == 0 )
    *((_DWORD *)v5 + 6) = 1;
  GArrayData<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,265>,GArrayDefaultPolicy>::Resize(
    this: (INetChannel *)v5 + 8,
    a2: *((_DWORD *)v5 + 6));
  GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v4, a2: (int)"  frames = %d\n", *((_DWORD *)v5 + 6));
  *((_DWORD *)v5 + 7) = 0;
  if ( (IShaderDeviceMgr_vtbl *)((char *)v4[11].__vftable + (char *)v4[13].__vftable - (char *)v4[12].__vftable) < (IShaderDeviceMgr_vtbl *)tagEnd )
  {
    while ( 1 )
    {
      GFxStream::OpenTag(this: v4, pTagInfo: (IShaderDeviceDependentObject *)&tagInfo);
      v30 = v10;
      GString::GString(this: &v31, a2: (const char *)(((int)v3[8][1].pNext & 0xFFFFFFFC) + 8));
      v11 = v3[4];
      if ( v11->Version != 0 )
      {
        Version = v11->Version;
        v13 = v39;
        v29 = v38;
        v34 = tagInfo;
        v28 = v37;
        GString::GString(result: (CImagePacker *)&v31);
        v27[2] = v28;
        v27[3] = v29;
        v27[1] = v34;
        v27[4] = v13;
        (*(void (__thiscall **)(unsigned int, _DWORD *, int))(*(_DWORD *)Version + 8))(a1: Version, a2: v27, a3: 1);
        v14 = (void *)(v27[0] & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v27[0] & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
        v5 = v33;
      }
      v15 = (void *)(v31.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v31.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v15);
      if ( v30 == 1 )
        break;
      if ( v30 >= 0x55 )
      {
        if ( v30 - 1000 > 9 )
          goto LABEL_35;
        v22 = *((void (__thiscall **)(CUtlDict<ITextureInternal *,unsigned short> *, unsigned __int16, HBITMAP__))GFx_GFX_TagLoaderTable
              + v30
              - 1000);
      }
      else
      {
        v22 = *((void (__thiscall **)(CUtlDict<ITextureInternal *,unsigned short> *, unsigned __int16, HBITMAP__))GFx_SWF_TagLoaderTable
              + v30);
      }
      if ( v22 == nullptr )
      {
LABEL_35:
        GFxLogBase<GFxStream>::LogParse(
          this: (tagBITMAPINFOHEADER *)v4,
          a2: (int)"*** no tag loader for type %d\n",
          v30);
        goto LABEL_36;
      }
      v22(this: (CUtlDict<ITextureInternal *,unsigned short> *)v22, prenderer: prenderer[0], ptext: (HBITMAP__)&tagInfo);
LABEL_36:
      GFxStream::CloseTag(this: (GFxStream *)v4);
      v3 = *(GFxLoadProcess **)prenderer;
      if ( (IShaderDeviceMgr_vtbl *)((char *)v4[11].__vftable + (char *)v4[13].__vftable - (char *)v4[12].__vftable) >= (IShaderDeviceMgr_vtbl *)tagEnd )
        goto LABEL_37;
    }
    v16 = *((_DWORD *)v5 + 9);
    if ( *((_DWORD *)v5 + 7) != v16 )
    {
LABEL_28:
      GFxLoadProcess::CommitFrameTags(this: *(GFxLoadProcess **)prenderer);
      GFxLogBase<GFxStream>::LogParse(
        this: (tagBITMAPINFOHEADER *)v4,
        a2: (int)"  ShowFrame (sprite, char id = %d)\n",
        LOWORD(a3.Id));
      ++*((_DWORD *)v5 + 7);
      goto LABEL_36;
    }
    v17 = *((GRefCountBaseStatImpl<GRefCountImpl,326> **)v5 + 9);
    v18 = (INetChannel *)((char *)v5 + 32);
    v19 = v16 + 1;
    v34 = v17;
    if ( v19 >= (unsigned int)v17 )
    {
      if ( (INetChannel_vtbl *)v19 < v18[2].__vftable )
        goto LABEL_22;
      GArrayDataBase<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,265>,GArrayDefaultPolicy>::Reserve(
        this: v18,
        pheapAddr: v18,
        newCapacity: v19 + (v19 >> 2));
    }
    else
    {
      if ( v19 >= (unsigned int)v18[2].__vftable >> 1 )
        goto LABEL_22;
      GArrayDataBase<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,265>,GArrayDefaultPolicy>::Reserve(
        this: v18,
        pheapAddr: v18,
        newCapacity: v19);
    }
    v17 = v34;
LABEL_22:
    v18[1].__vftable = (INetChannel_vtbl *)v19;
    if ( v19 > (unsigned int)v17 )
    {
      v20 = v19 - (_DWORD)v17;
      for ( i = &v18->GetName + 2 * (_DWORD)v17; v20 != 0; --v20 )
      {
        if ( i != nullptr )
        {
          *i = nullptr;
          i[1] = nullptr;
        }
        i += 2;
      }
    }
    GFxLogBase<GFxStream>::LogError(
      this: (tagBITMAPINFOHEADER *)v4,
      a2: (int)"An extra frame is found for sprite id = %d, framecnt = %d, actual frames = %d\n",
      LOWORD(a3.Id),
      *((_DWORD *)v33 + 6),
      *((_DWORD *)v33 + 7) + 1);
    v5 = v33;
    goto LABEL_28;
  }
LABEL_37:
  v23 = v3[190];
  if ( v3[3 * (_DWORD)v23 + 193] != nullptr || v23 == nullptr && v3[199] != nullptr )
  {
    v24 = *((_DWORD *)v5 + 9);
    if ( *((_DWORD *)v5 + 7) == v24 )
    {
      GArrayData<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,265>,GArrayDefaultPolicy>::Resize(
        this: (INetChannel *)v5 + 8,
        a2: v24 + 1);
      GFxLogBase<GFxStream>::LogError(
        this: (tagBITMAPINFOHEADER *)v4,
        a2: (int)"An extra frame is found for sprite id = %d, framecnt = %d, actual frames = %d\n",
        LOWORD(a3.Id),
        *((_DWORD *)v5 + 6),
        *((_DWORD *)v5 + 7) + 1);
    }
    GFxLoadProcess::CommitFrameTags(this: v3);
  }
  v3[190] = nullptr;
  v3[191] = nullptr;
  GFxLogBase<GFxStream>::LogParse(
    this: (tagBITMAPINFOHEADER *)v4,
    a2: (int)"  -- sprite END, char id = %d --\n",
    LOWORD(a3.Id));
}

//------------------------------------------------------------------------------
// Address: 0x100B46C0
// Name: public: void GFxSpriteDef::InitEmptyClipDef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSpriteDef::InitEmptyClipDef(INetChannel *this)
{
  *((_DWORD *)this + 6) = 1;
  GArrayData<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,265>,GArrayDefaultPolicy>::Resize(
    this: this + 8,
    a2: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x100B46E0
// Name: public: void GFxSprite::SetLevel(int)
// Source: json
//------------------------------------------------------------------------------
const GFxZlibSupportBase *__thiscall GFxSprite::SetLevel(_DWORD *this, const GFxZlibSupportBase *result)
{
  int v3; // eax
  const GFxZlibSupportBase *v4; // eax
  unsigned __int16 v6; // [esp+0h] [ebp-358h]
  unsigned __int16 v7; // [esp+0h] [ebp-358h]
  _DWORD v8[3]; // [esp+4h] [ebp-354h] BYREF
  int v9; // [esp+10h] [ebp-348h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v10; // [esp+14h] [ebp-344h] BYREF
  unsigned __int8 v11[64]; // [esp+314h] [ebp-44h] BYREF

  *(this + 111) = result;
  memset(v11, 0, sizeof(v11));
  v8[0] = 2;
  v8[1] = v11;
  v8[2] = 64;
  GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v10, a2: (const struct GMsgFormat::Sink *)v8);
  GMsgFormat::Parse(result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_1029E6EC);
  GMsgFormat::FormatD1<int>(this: (int)&v10, (CUtlSymbolTable::StringPool_t *)&result);
  GMsgFormat::FinishFormatD(this: &v10, a2: v6);
  GMsgFormat::~GMsgFormat(this: &v10, data_size: v7);
  GASStringManager::CreateStringNode(this: *(const char **)(*(this + 88) + 636));
  v9 = v3;
  ++*(_DWORD *)(v3 + 8);
  (*(void (__thiscall **)(_DWORD *, int *))(*this + 40))(a1: this, a2: &v9);
  v4 = (const GFxZlibSupportBase *)v9;
  if ( (*(_DWORD *)(v9 + 8))-- == 1 )
    return (const GFxZlibSupportBase *)GASStringNode::ReleaseNode().Sid;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100B47D0
// Name: public: void GFxSprite::CalcDisplayListHitTestMaskArray(class GArray<unsigned char,2,struct GArrayDefaultPolicy> __near *,class GPoint<float> const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge GFxSprite::CalcDisplayListHitTestMaskArray@<eax>(
        int a1@<ecx>,
        int a2@<esi>,
        _RGNDATAHEADER *result,
        int testShape,
        int a5)
{
  GRefCountBase<GFxResourceLibBase,2> *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // esi
  GRefCountBase<GFxResourceLibBase,2>_vtbl *v9; // ebx
  char v10; // al
  GRefCountBase<GFxResourceLibBase,2> *v11; // edx
  unsigned int i; // eax
  int v13; // ecx
  unsigned __int8 *v14; // [esp-10h] [ebp-4Ch]
  int v15; // [esp-4h] [ebp-40h]
  CCountedStringPoolBase<unsigned int>::hash_item_t v16; // [esp+8h] [ebp-34h] BYREF
  int v17; // [esp+14h] [ebp-28h]
  GRefCountBase<GFxResourceLibBase,2> *v18; // [esp+18h] [ebp-24h]
  unsigned int n; // [esp+1Ch] [ebp-20h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v20; // [esp+20h] [ebp-1Ch] BYREF
  float v21; // [esp+34h] [ebp-8h]

  v5 = (GRefCountBase<GFxResourceLibBase,2> *)result;
  *(_DWORD *)&v16.nReferenceCount = testShape;
  v6 = *(_DWORD *)(a1 + 200);
  v7 = 0;
  v17 = a1;
  v18 = (GRefCountBase<GFxResourceLibBase,2> *)result;
  n = v6;
  if ( v6 != 0 )
  {
    v15 = a2;
    do
    {
      v8 = *(_DWORD *)(*(_DWORD *)(a1 + 196) + 4 * v7);
      if ( *(_WORD *)(v8 + 116) != 0 )
      {
        if ( v5->RefCount == 0 )
        {
          if ( (GRefCountBase<GFxResourceLibBase,2>_vtbl *)v6 >= v5[1].__vftable )
          {
            GArrayDataBase<unsigned char,GAllocatorGH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
              this: (void **)&v5->__vftable,
              pheapAddr: (ButtonCode_t)v5,
              newCapacity: v6 + (v6 >> 2));
            v6 = n;
          }
          v14 = (unsigned __int8 *)v5->__vftable;
          v5->RefCount = v6;
          memset(dst: v14, value: 1u, count: v6);
        }
        v20.m_Memory.m_pMemory = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(v8 + 68);
        v20.m_Memory.m_nAllocationCount = *(int *)(v8 + 72);
        v20.m_Memory.m_nGrowSize = *(int *)(v8 + 76);
        v20.m_Size = *(int *)(v8 + 80);
        v20.m_pElements = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(v8 + 84);
        v21 = *(float *)(v8 + 88);
        GMatrix2D::TransformByInverse(this: &v20, result: &v16, p: *(float **)&v16.nReferenceCount, p_4: v15);
        v9 = v5->__vftable;
        v10 = (*(int (__thiscall **)(int, CCountedStringPoolBase<unsigned int>::hash_item_t *, int))(*(_DWORD *)v8 + 68))(
                a1: v8,
                a2: &v16,
                a3: 1);
        v11 = (GRefCountBase<GFxResourceLibBase,2> *)n;
        *((_BYTE *)&v9->dtr_GRefCountImplCore + v7) = v10;
        for ( i = v7 + 1;
              i < (unsigned int)v11;
              *((_BYTE *)&v18->dtr_GRefCountImplCore + i++) = *((_BYTE *)&v18->dtr_GRefCountImplCore + v7) )
        {
          v13 = *(_DWORD *)(*(_DWORD *)(v17 + 196) + 4 * i);
          if ( v13 != 0 && *(_DWORD *)(v13 + 20) > (int)*(unsigned __int16 *)(v8 + 116) )
            break;
        }
        a1 = v17;
        v5 = v18;
        v7 = i - 1;
        v6 = (unsigned int)v11;
      }
      ++v7;
    }
    while ( v7 < v6 );
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100B4900
// Name: public: virtual class GFxASCharacter __near * GFxSprite::GetTopMostMouseEntity(class GPoint<float> const __near &,struct GFxCharacter::TopMostParams const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *__thiscall GFxSprite::GetTopMostMouseEntity(
        GPtr<GFxZlibSupportBase> *this,
        CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,Rect_t *,Rect_t *),ITexture *,int,Rect_t *,Rect_t *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pt,
        int a3)
{
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v3; // esi
  int v4; // eax
  int Perspective3D; // edi
  int View3D; // ebx
  int v7; // eax
  struct GFxSprite *Mask; // eax
  struct GFxSprite *v9; // edi
  int v10; // ebx
  int v11; // eax
  int v12; // ebx
  int v13; // ecx
  int v14; // edi
  GFxSprite *v15; // ecx
  int v16; // ecx
  GFxSprite *v18; // ecx
  _TAPE_WMI_OPERATIONS *HitArea; // eax
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v20; // edx
  int v21; // [esp-20h] [ebp-DCh]
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v22; // [esp-1Ch] [ebp-D8h]
  const CMaterialDict::MaterialLookup_t *v23; // [esp-8h] [ebp-C4h]
  int v24; // [esp-8h] [ebp-C4h]
  int n; // [esp+Ch] [ebp-B0h]
  CCountedStringPoolBase<unsigned int>::hash_item_t v26; // [esp+10h] [ebp-ACh] BYREF
  int p[2]; // [esp+1Ch] [ebp-A0h] BYREF
  GRefCountBase<GFxResourceLibBase,2> v28; // [esp+24h] [ebp-98h] BYREF
  unsigned int nNextElement; // [esp+2Ch] [ebp-90h]
  GMatrix3D v30; // [esp+30h] [ebp-8Ch] BYREF
  GMatrix2D v31; // [esp+70h] [ebp-4Ch] BYREF
  struct GMatrix2D m; // [esp+88h] [ebp-34h] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v33; // [esp+A0h] [ebp-1Ch] BYREF
  CMatQueuedMesh *m_pObject; // [esp+B4h] [ebp-8h]

  v3 = (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)this;
  v4 = *((_DWORD *)this + 40) >> 11;
  *(_DWORD *)&v26.nReferenceCount = a3;
  if ( (v4 & 1) != 0
    || ((unsigned __int8 (__thiscall *)(GPtr<GFxZlibSupportBase> *))this->pObject[1].RefCount)(a1: this) == 0
    && v3[19].m_pObject == nullptr )
  {
    return nullptr;
  }
  if ( (*(unsigned __int8 (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(v3->m_pfnProxied) + 180))(a1: v3) != 0 )
    return nullptr;
  if ( *(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> **)(a3 + 4) == v3 )
    return nullptr;
  v23 = *(const CMaterialDict::MaterialLookup_t **)a3;
  if ( (*(unsigned __int8 (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(v3->m_pfnProxied) + 196))(a1: v3) == 0 )
    return nullptr;
  v33.m_Memory.m_pMemory = *((CCountedStringPoolBase<unsigned int>::hash_item_t **)&v3[2].m_pObject + 1);
  v33.m_Memory.m_nAllocationCount = v3[3].m_pfnProxied;
  v33.m_Memory.m_nGrowSize = SDWORD1(v3[3].m_pfnProxied);
  v33.m_Size = SDWORD2(v3[3].m_pfnProxied);
  v33.m_pElements = (CCountedStringPoolBase<unsigned int>::hash_item_t *)HIDWORD(v3[3].m_pfnProxied);
  m_pObject = v3[3].m_pObject;
  if ( GFxCharacter::Is3D(
         this: v3,
         result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) != 0 )
  {
    Perspective3D = GFxCharacter::GetPerspective3D(this: v3, checkAncestors: true);
    View3D = GFxCharacter::GetView3D(this: v3, checkAncestors: true);
    if ( Perspective3D != 0 )
      *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(v3->m_pfnProxied) + 84))(a1: v3)
                + 224) = Perspective3D;
    if ( View3D != 0 )
      *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(v3->m_pfnProxied) + 84))(a1: v3)
                + 228) = View3D;
    GMatrix3D::SetIdentity(this: &v30);
    GFxCharacter::GetWorldMatrix3D(this: v3, pmat: (CMatQueuedMesh::MST_MeshInfo_t *)&v30);
    *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(v3->m_pfnProxied) + 84))(a1: v3)
              + 232) = &v30;
    v7 = (*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *, int *))(LODWORD(v3->m_pfnProxied) + 84))(
           a1: v3,
           a2: p);
    GScreenToWorld::GetWorldPoint(this: (CUtlBuffer *)(v7 + 208));
  }
  else
  {
    GMatrix2D::TransformByInverse(
      this: &v33,
      result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&v28.RefCount,
      p: (float *)pt,
      p_4: (int)v23);
    p[0] = v28.RefCount;
    p[1] = nNextElement;
  }
  n = DWORD2(v3[8].m_pfnProxied);
  Mask = GFxSprite::GetMask(this: (GFxSprite *)v3);
  v9 = Mask;
  if ( Mask != nullptr
    && (*(unsigned __int8 (__thiscall **)(struct GFxSprite *))(*(_DWORD *)Mask + 180))(a1: Mask) != 0
    && (*((_BYTE *)v9 + 118) & 0x10) == 0 )
  {
    if ( GFxCharacter::Is3D(
           this: v9,
           result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) != 0 )
    {
      v10 = GFxCharacter::GetPerspective3D(this: v9, checkAncestors: true);
      v26.nNextElement = GFxCharacter::GetView3D(this: v9, checkAncestors: true);
      if ( v10 != 0 )
        *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(v3->m_pfnProxied) + 84))(a1: v3)
                  + 224) = v10;
      if ( v26.nNextElement != 0 )
        *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(v3->m_pfnProxied) + 84))(a1: v3)
                  + 228) = v26.nNextElement;
      GMatrix3D::SetIdentity(this: &v30);
      GFxCharacter::GetWorldMatrix3D(
        this: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)v9,
        pmat: (CMatQueuedMesh::MST_MeshInfo_t *)&v30);
      *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(v3->m_pfnProxied) + 84))(a1: v3)
                + 232) = &v30;
      v11 = (*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *, volatile int *))(LODWORD(v3->m_pfnProxied) + 84))(
              a1: v3,
              a2: &v28.RefCount);
      GScreenToWorld::GetWorldPoint(this: (CUtlBuffer *)(v11 + 208));
    }
    else
    {
      GMatrix2D::SetIdentity(this: (float *)&v31);
      GMatrix2D::SetIdentity(this: (float *)&m);
      GFxCharacter::GetWorldMatrix(this: v9, pmat: (CMaterialDict *)&m);
      GMatrix2D::SetInverse(a1: (float *)&v31, (const CMaterialDict::MaterialLookup_t *)&m, a3: v23);
      GMatrix2D::SetIdentity(this: (float *)&m);
      GFxCharacter::GetWorldMatrix(this: (GFxCharacter *)v3, pmat: (CMaterialDict *)&m);
      GMatrix2D::Prepend(this: &v31, a2: &m);
      GMatrix2D::Transform(
        this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v31,
        result: &v26,
        (float *)p,
        p_4: v24);
      v28.RefCount = (volatile int)v26.pString;
      nNextElement = v26.nNextElement;
    }
    if ( (*(unsigned __int8 (__thiscall **)(struct GFxSprite *, volatile int *, int))(*(_DWORD *)v9 + 68))(
           a1: v9,
           a2: &v28.RefCount,
           a3: 1) == 0 )
      return nullptr;
  }
  v28.__vftable = nullptr;
  v28.RefCount = 0;
  *(float *)&nNextElement = 0.0;
  GFxSprite::CalcDisplayListHitTestMaskArray(
    a1: (int)v3,
    a2: (int)v3,
    result: (_RGNDATAHEADER *)&v28,
    testShape: (int)p,
    a5: 1);
  v12 = n - 1;
  if ( n - 1 < 0 )
  {
LABEL_42:
    if ( DWORD1(v3[19].m_pfnProxied) != 0 && GFxSprite::ActsAsButton(this: (GFxSprite *)v3) != 0 )
    {
      v22 = v3;
      v21 = 1;
      if ( (unsigned __int8)GFxDrawingContext::DefPointTestLocal(
                              this: (IClientTools *)DWORD1(v3[19].m_pfnProxied),
                              pt: (int)p) != 0 )
      {
LABEL_59:
        ((void (__thiscall *)(GMemoryHeap *, GRefCountBase<GFxResourceLibBase,2>_vtbl *, int, CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))GMemory::pGlobalHeap->Free)(
          a1: GMemory::pGlobalHeap,
          a2: v28.__vftable,
          a3: v21,
          a4: v22);
        return v3;
      }
    }
    ((void (__thiscall *)(GMemoryHeap *, GRefCountBase<GFxResourceLibBase,2>_vtbl *, int))GMemory::pGlobalHeap->Free)(
      a1: GMemory::pGlobalHeap,
      a2: v28.__vftable,
      a3: v21);
    return nullptr;
  }
  while ( 1 )
  {
    v13 = *(_DWORD *)(DWORD1(v3[8].m_pfnProxied) + 4 * v12);
    if ( (v28.RefCount == 0 || *((_BYTE *)&v28.dtr_GRefCountImplCore + v12) != 0 && *(_WORD *)(v13 + 116) == 0)
      && (*(_BYTE *)(v13 + 118) & 2) == 0 )
    {
      v14 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 72))(a1: v13);
      if ( v14 != 0 && *(_BYTE *)(*(_DWORD *)&v26.nReferenceCount + 12) != 0 )
        goto LABEL_39;
      if ( GFxSprite::ActsAsButton(this: (GFxSprite *)v3) != 0 )
        break;
      v15 = (GFxSprite *)v3[19].m_pObject;
      if ( v15 != nullptr && GFxSprite::ActsAsButton(this: v15) != 0 )
        break;
      if ( v14 != 0
        && (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)v14 != v3 )
      {
        v16 = *(_DWORD *)(v14 + 32);
        if ( v16 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v16 + 16))(a1: v16) != 0 )
        {
LABEL_39:
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v28.__vftable);
          return (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)v14;
        }
        goto LABEL_48;
      }
    }
LABEL_41:
    if ( --v12 < 0 )
      goto LABEL_42;
  }
  if ( v14 == 0 )
    goto LABEL_41;
  v18 = (GFxSprite *)v3[19].m_pObject;
  if ( v18 == nullptr || GFxSprite::ActsAsButton(this: v18) == 0 )
  {
    HitArea = GFxSprite::GetHitArea(this: (GFxSprite *)v3, a2: (_TAPE_WMI_OPERATIONS *)p);
    if ( HitArea != nullptr )
    {
      v20 = (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)HitArea;
      while ( 1 )
      {
        v20 = (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)DWORD2(v20[1].m_pfnProxied);
        if ( v20 == nullptr )
          break;
        if ( v20 == v3 )
        {
          v3 = (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)(*(int (__thiscall **)(_TAPE_WMI_OPERATIONS *, int *, _DWORD))(HitArea->Method + 72))(a1: HitArea, a2: p, a3: *(_DWORD *)&v26.nReferenceCount);
          goto LABEL_52;
        }
      }
LABEL_48:
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v28.__vftable);
      return nullptr;
    }
    goto LABEL_59;
  }
  v3 = (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)v3[19].m_pObject;
LABEL_52:
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v28.__vftable);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100B4E30
// Name: public: GFxSprite::ActiveSounds::~ActiveSounds(void)
// Source: json
//------------------------------------------------------------------------------
const D3D11_BLEND_DESC *__thiscall GFxSprite::ActiveSounds::~ActiveSounds(CD3D11_BLEND_DESC *this)
{
  int v2; // ecx
  IShaderAPI *v3; // ecx
  D3D11_BLEND i; // edi
  IShaderAPI *v5; // ecx
  D3D11_BLEND DestBlend; // eax
  GRefCountNTSImpl **v7; // edi
  D3D11_BLEND v8; // ebx

  v2 = *(_DWORD *)&this->RenderTarget[0].RenderTargetWriteMask;
  if ( v2 != 0 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2);
    v3 = *(IShaderAPI **)&this->RenderTarget[0].RenderTargetWriteMask;
    if ( v3 != nullptr )
      GRefCountImpl::Release(this: v3);
    *(_DWORD *)&this->RenderTarget[0].RenderTargetWriteMask = 0;
  }
  for ( i = 0; (unsigned int)i < this->RenderTarget[0].DestBlendAlpha; ++i )
    GASSoundObject::ReleaseTarget(this: *(GASSoundObject **)(this->RenderTarget[0].SrcBlendAlpha + 4 * i));
  v5 = *(IShaderAPI **)&this->RenderTarget[0].RenderTargetWriteMask;
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)this->RenderTarget[0].SrcBlendAlpha);
  DestBlend = this->RenderTarget[0].DestBlend;
  v7 = (GRefCountNTSImpl **)(this->RenderTarget[0].SrcBlend + 4 * DestBlend - 4);
  if ( DestBlend != 0 )
  {
    v8 = this->RenderTarget[0].DestBlend;
    do
    {
      if ( *v7 != nullptr )
        GRefCountNTSImpl::Release(this: *v7);
      --v7;
      --v8;
    }
    while ( v8 != 0 );
  }
  return ((const D3D11_BLEND_DESC *(__thiscall *)(GMemoryHeap *, D3D11_BLEND))GMemory::pGlobalHeap->Free)(
           a1: GMemory::pGlobalHeap,
           a2: this->RenderTarget[0].SrcBlend);
}

//------------------------------------------------------------------------------
// Address: 0x100B4ED0
// Name: public: void GFxSprite::StopActiveSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::StopActiveSounds(GFxFontLib *this)
{
  int v2; // eax
  unsigned int i; // edi
  int v4; // eax
  int v5; // ecx
  GRefCountNTSImpl **v6; // eax
  GRefCountNTSImpl *v7; // esi
  unsigned int j; // edi
  int v9; // eax
  GFxFontLib *v10; // eax
  const MorphWeight_t *v11; // [esp+0h] [ebp-Ch]
  unsigned int v12; // [esp+0h] [ebp-Ch]

  v2 = *((_DWORD *)this + 114);
  if ( v2 != 0 )
  {
    for ( i = 0; i < *(_DWORD *)(v2 + 16); ++i )
    {
      v4 = *(_DWORD *)(v2 + 12);
      v5 = *(_DWORD *)(v4 + 4 * i);
      v6 = (GRefCountNTSImpl **)(v4 + 4 * i);
      if ( v5 != 0 )
        ++*(_DWORD *)(v5 + 4);
      v7 = *v6;
      (*((void (__thiscall **)(GRefCountNTSImpl_vtbl *))(*v6)[1].dtr_GRefCountImplCore + 3))(a1: (*v6)[1].__vftable);
      GRefCountNTSImpl::Release(this: v7);
      v2 = *((_DWORD *)this + 114);
    }
    GArrayDataBase<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (CMatNullRenderContext *)(*((_DWORD *)this + 114) + 12),
      pheapAddr: (IMorph *)(*((_DWORD *)this + 114) + 12),
      newSize: 0,
      a4: v11);
  }
  for ( j = 0; j < *((_DWORD *)this + 50); ++j )
  {
    v9 = *(_DWORD *)(*((_DWORD *)this + 49) + 4 * j);
    if ( *(char *)(v9 + 118) < 0 && (*(int (__thiscall **)(int))(*(_DWORD *)(v9 + 120) + 8))(a1: v9 + 120) == 2 )
    {
      v10 = (GFxFontLib *)GASObjectInterface::ToSprite(result: (_TAPE_WMI_OPERATIONS *)v11);
      GFxSprite::StopActiveSounds(this: v10, a2: v12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B4F70
// Name: public: void GFxSprite::StopActiveSounds(class GFxSoundResource __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSprite::StopActiveSounds(GFxValue *this@<ecx>, const MorphWeight_t *a2@<ebx>, wchar_t *pres)
{
  GFxValue *v3; // esi
  const char *pString; // eax
  unsigned int i; // ebx
  int v6; // eax
  int v7; // ecx
  GRefCountNTSImpl *v8; // eax
  CMatNullRenderContext *v9; // esi
  const char *j; // edi
  int v11; // eax
  GFxValue *v12; // eax
  const MorphWeight_t *v13; // [esp-4h] [ebp-14h]
  const wchar_t *v14; // [esp-4h] [ebp-14h]
  GRefCountNTSImpl *v15; // [esp+8h] [ebp-8h]

  v3 = this;
  pString = *((const char **)this + 114);
  if ( pString != nullptr )
  {
    v13 = a2;
    for ( i = 0; i < *((_DWORD *)pString + 4); pString = v3[28].Value.pString )
    {
      v6 = *((_DWORD *)pString + 3);
      v7 = *(_DWORD *)(v6 + 4 * i);
      if ( v7 != 0 )
        ++*(_DWORD *)(v7 + 4);
      v8 = *(GRefCountNTSImpl **)(v6 + 4 * i);
      v15 = v8;
      if ( (wchar_t *)v8[2].__vftable == pres )
      {
        (*((void (__thiscall **)(GRefCountNTSImpl_vtbl *))v8[1].dtr_GRefCountImplCore + 3))(a1: v8[1].__vftable);
        v9 = (CMatNullRenderContext *)(v3[28].Value.pString + 12);
        if ( v9->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable == (CRefCountServiceBase<1,CRefMT>_vtbl *)1 )
        {
          GArrayDataBase<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
            this: v9,
            pheapAddr: (IMorph *)v9,
            newSize: 0,
            a4: v13);
          v8 = v15;
          v3 = this;
        }
        else
        {
          if ( *((_DWORD *)&v9->AddRef + i) != 0 )
            GRefCountNTSImpl::Release(this: *((GRefCountNTSImpl **)&v9->AddRef + i));
          memmove(
            dst: (unsigned __int8 *)&v9->AddRef + 4 * i,
            src: (unsigned __int8 *)&v9->Release + 4 * i,
            count: 4
          * ((int)v9->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable
           - i)
          - 4);
          v8 = v15;
          --v9->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
          v3 = this;
        }
      }
      else
      {
        ++i;
      }
      GRefCountNTSImpl::Release(this: v8);
    }
  }
  for ( j = nullptr; j < v3[12].Value.pString; ++j )
  {
    v11 = *(_DWORD *)(v3[12].Type + 4 * (_DWORD)j);
    if ( *(char *)(v11 + 118) < 0 )
    {
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)(v11 + 120) + 8))(a1: v11 + 120) == 2 )
      {
        v12 = (GFxValue *)GASObjectInterface::ToSprite(result: (_TAPE_WMI_OPERATIONS *)pres);
        GFxSprite::StopActiveSounds(this: v12, pres: v14);
      }
      v3 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B50A0
// Name: public: virtual void GFxPlaceObjectUnpacked::AddToTimelineSnapshot(class GFxTimelineSnapshot __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),CFuncMemPolicyNone> *__thiscall GFxPlaceObjectUnpacked::AddToTimelineSnapshot(
        _DWORD *this,
        CMemberFuncProxyBase<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),CFuncMemPolicyNone> *result,
        unsigned int frame)
{
  int v4; // ebx
  int v5; // eax
  const CMemberFuncProxyBase<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),CFuncMemPolicyNone> *v6; // eax
  int m_pfnProxied; // [esp-Ch] [ebp-1Ch]
  int v8; // [esp+Ch] [ebp-4h] BYREF

  (*(void (__thiscall **)(_DWORD *, const char *))(*this + 28))(a1: this, a2: "\n");
  v4 = *(this + 19);
  m_pfnProxied = result[1].m_pfnProxied;
  v8 = v4;
  v5 = G_UpperBoundSliced<GArrayDH_POD<GFxTimelineSnapshot::SnapshotElement *,2,GArrayDefaultPolicy>,int,int (__cdecl *)(int,GFxTimelineSnapshot::SnapshotElement const *)>(
         a1: (_DWORD *)&result->m_pObject + 1,
         a2: 0,
         a3: m_pfnProxied,
         a4: &v8,
         a5: (int (__cdecl *)(_DWORD, _DWORD))GFxTimelineSnapshot::DepthLess);
  if ( v5 != 0
    && HIDWORD((v6 = *(const CMemberFuncProxyBase<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),CFuncMemPolicyNone> **)(*((_DWORD *)&result->m_pObject + 1) + 4 * v5 - 4))->m_pfnProxied) == v4
    && v6 != nullptr
    && (BYTE5(v6[2].m_pfnProxied) & 2) == 0 )
  {
    LODWORD(v6[2].m_pfnProxied) = this;
    *((_DWORD *)&v6[1].m_pObject + 1) = this;
    v6[1].m_pObject = (CMatQueuedIndexBuffer *)this;
    HIDWORD(v6[1].m_pfnProxied) = this;
    DWORD2(v6[1].m_pfnProxied) = this;
    DWORD1(v6[1].m_pfnProxied) = this;
    LODWORD(v6[1].m_pfnProxied) = this;
    *((_DWORD *)&v6->m_pObject + 1) = this;
    v6->m_pObject = (CMatQueuedIndexBuffer *)this;
    DWORD2(v6->m_pfnProxied) = frame;
    BYTE5(v6[2].m_pfnProxied) |= 1u;
  }
  else
  {
    v6 = (const CMemberFuncProxyBase<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),CFuncMemPolicyNone> *)GFxTimelineSnapshot::Add(this: (GFxTimelineSnapshot *)result, a2: *(this + 19));
    LODWORD(v6[2].m_pfnProxied) = this;
    *((_DWORD *)&v6[1].m_pObject + 1) = this;
    v6[1].m_pObject = (CMatQueuedIndexBuffer *)this;
    HIDWORD(v6[1].m_pfnProxied) = this;
    DWORD2(v6[1].m_pfnProxied) = this;
    DWORD1(v6[1].m_pfnProxied) = this;
    LODWORD(v6[1].m_pfnProxied) = this;
    *((_DWORD *)&v6->m_pObject + 1) = this;
    v6->m_pObject = (CMatQueuedIndexBuffer *)this;
    BYTE4(v6[2].m_pfnProxied) = 0;
    DWORD2(v6->m_pfnProxied) = frame;
    BYTE5(v6[2].m_pfnProxied) |= 1u;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100B5160
// Name: public: virtual void GFxPlaceObject::AddToTimelineSnapshot(class GFxTimelineSnapshot __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject::AddToTimelineSnapshot(
        GFxPlaceObject *this,
        struct GFxTimelineSnapshot *a2,
        unsigned int a3)
{
  int Depth; // ebx
  int v5; // eax
  int v6; // eax
  struct GFxTimelineSnapshot::SnapshotElement *v7; // eax
  int v8; // [esp-Ch] [ebp-1Ch]
  int v9; // [esp+Ch] [ebp-4h] BYREF

  (*(void (__thiscall **)(GFxPlaceObject *, const char *))(*(_DWORD *)this + 28))(a1: this, a2: "\n");
  Depth = GFxPlaceObject::GetDepth(this);
  v8 = *((_DWORD *)a2 + 6);
  v9 = Depth;
  v5 = G_UpperBoundSliced<GArrayDH_POD<GFxTimelineSnapshot::SnapshotElement *,2,GArrayDefaultPolicy>,int,int (__cdecl *)(int,GFxTimelineSnapshot::SnapshotElement const *)>(
         a1: (_DWORD *)a2 + 5,
         a2: 0,
         a3: v8,
         a4: &v9,
         a5: (int (__cdecl *)(_DWORD, _DWORD))GFxTimelineSnapshot::DepthLess);
  if ( v5 != 0
    && *(_DWORD *)((v6 = *(_DWORD *)(*((_DWORD *)a2 + 5) + 4 * v5 - 4)) + 12) == Depth
    && v6 != 0
    && (*(_BYTE *)(v6 + 53) & 2) == 0 )
  {
    *(_DWORD *)(v6 + 48) = this;
    *(_DWORD *)(v6 + 44) = this;
    *(_DWORD *)(v6 + 40) = this;
    *(_DWORD *)(v6 + 36) = this;
    *(_DWORD *)(v6 + 32) = this;
    *(_DWORD *)(v6 + 28) = this;
    *(_DWORD *)(v6 + 24) = this;
    *(_DWORD *)(v6 + 20) = this;
    *(_DWORD *)(v6 + 16) = this;
    *(_DWORD *)(v6 + 8) = a3;
    *(_BYTE *)(v6 + 53) |= 1u;
  }
  else
  {
    v7 = GFxTimelineSnapshot::Add(this: a2, a2: Depth);
    *((_BYTE *)v7 + 52) = 0;
    *((_DWORD *)v7 + 12) = this;
    *((_DWORD *)v7 + 11) = this;
    *((_DWORD *)v7 + 10) = this;
    *((_DWORD *)v7 + 9) = this;
    *((_DWORD *)v7 + 8) = this;
    *((_DWORD *)v7 + 7) = this;
    *((_DWORD *)v7 + 6) = this;
    *((_DWORD *)v7 + 5) = this;
    *((_DWORD *)v7 + 4) = this;
    *((_DWORD *)v7 + 2) = a3;
    *((_BYTE *)v7 + 53) |= 1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5230
// Name: public: virtual void GFxPlaceObject2::AddToTimelineSnapshot(class GFxTimelineSnapshot __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject2::AddToTimelineSnapshot(
        GFxPlaceObject2 *this,
        CMatQueuedMesh *psnapshot,
        unsigned int frame)
{
  int Depth; // ebx
  unsigned __int8 v5; // al
  CMatQueuedRenderContext **p_m_pOwner; // edi
  int v7; // eax
  int v8; // edi
  struct GFxTimelineSnapshot::SnapshotElement *v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // eax
  char v12; // al
  char v13; // al
  CMatCallQueue *m_pCallQueue; // [esp-Ch] [ebp-20h]
  int v15; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int8 placeType; // [esp+13h] [ebp-1h]

  (*(void (__thiscall **)(GFxPlaceObject2 *, const char *))(*(_DWORD *)this + 28))(a1: this, a2: "\n");
  Depth = GFxPlaceObject2::GetDepth(this);
  v5 = GFxPlaceObject3::GetPlaceType(this);
  p_m_pOwner = &psnapshot->m_pOwner;
  placeType = v5;
  m_pCallQueue = psnapshot->m_pCallQueue;
  v15 = Depth;
  v7 = G_UpperBoundSliced<GArrayDH_POD<GFxTimelineSnapshot::SnapshotElement *,2,GArrayDefaultPolicy>,int,int (__cdecl *)(int,GFxTimelineSnapshot::SnapshotElement const *)>(
         a1: &psnapshot->m_pOwner,
         a2: 0,
         a3: (int)m_pCallQueue,
         a4: &v15,
         a5: (int (__cdecl *)(_DWORD, _DWORD))GFxTimelineSnapshot::DepthLess);
  if ( v7 != 0
    && *(_DWORD *)((v8 = *((_DWORD *)*p_m_pOwner + v7 - 1)) + 12) == Depth
    && v8 != 0
    && (*(_BYTE *)(v8 + 53) & 2) == 0 )
  {
    if ( placeType == 1 )
    {
      (*(void (__thiscall **)(GFxPlaceObject2 *, char *))(*(_DWORD *)this + 40))(a1: this, a2: (char *)&frame + 3);
      v13 = HIBYTE(frame);
      if ( (frame & 0x4000000) != 0 )
        *(_DWORD *)(v8 + 20) = this;
      if ( (v13 & 8) != 0 )
        *(_DWORD *)(v8 + 24) = this;
      if ( (v13 & 0x20) != 0 )
        *(_DWORD *)(v8 + 28) = this;
      if ( v13 < 0 )
        *(_DWORD *)(v8 + 32) = this;
      if ( (v13 & 1) != 0 )
        *(_DWORD *)(v8 + 36) = this;
      if ( (v13 & 0x40) != 0 )
        *(_DWORD *)(v8 + 40) = this;
      if ( (v13 & 0x10) != 0 )
        *(_DWORD *)(v8 + 44) = this;
      if ( (v13 & 2) != 0 )
        *(_DWORD *)(v8 + 48) = this;
    }
    else if ( placeType == 2 )
    {
      if ( *(_BYTE *)(v8 + 52) != 0 )
        *(_BYTE *)(v8 + 52) = 2;
      (*(void (__thiscall **)(GFxPlaceObject2 *, char *))(*(_DWORD *)this + 40))(a1: this, a2: (char *)&psnapshot + 3);
      v12 = HIBYTE(psnapshot);
      if ( (HIBYTE(psnapshot) & 4) != 0 )
        *(_DWORD *)(v8 + 20) = this;
      if ( (v12 & 8) != 0 )
        *(_DWORD *)(v8 + 24) = this;
      if ( (v12 & 0x20) != 0 )
        *(_DWORD *)(v8 + 28) = this;
      if ( v12 < 0 )
        *(_DWORD *)(v8 + 32) = this;
      if ( (v12 & 1) != 0 )
        *(_DWORD *)(v8 + 36) = this;
      if ( (v12 & 0x40) != 0 )
        *(_DWORD *)(v8 + 40) = this;
      if ( (v12 & 0x10) != 0 )
        *(_DWORD *)(v8 + 44) = this;
      if ( (v12 & 2) != 0 )
        *(_DWORD *)(v8 + 48) = this;
      *(_DWORD *)(v8 + 8) = frame;
    }
    else
    {
      v11 = frame;
      *(_DWORD *)(v8 + 48) = this;
      *(_DWORD *)(v8 + 44) = this;
      *(_DWORD *)(v8 + 40) = this;
      *(_DWORD *)(v8 + 36) = this;
      *(_DWORD *)(v8 + 32) = this;
      *(_DWORD *)(v8 + 28) = this;
      *(_DWORD *)(v8 + 24) = this;
      *(_DWORD *)(v8 + 20) = this;
      *(_DWORD *)(v8 + 16) = this;
      *(_DWORD *)(v8 + 8) = v11;
    }
  }
  else
  {
    v9 = GFxTimelineSnapshot::Add(this: (GFxTimelineSnapshot *)psnapshot, a2: Depth);
    v10 = frame;
    *((_BYTE *)v9 + 52) = placeType;
    *((_DWORD *)v9 + 12) = this;
    *((_DWORD *)v9 + 11) = this;
    *((_DWORD *)v9 + 10) = this;
    *((_DWORD *)v9 + 9) = this;
    *((_DWORD *)v9 + 8) = this;
    *((_DWORD *)v9 + 7) = this;
    *((_DWORD *)v9 + 6) = this;
    *((_DWORD *)v9 + 5) = this;
    *((_DWORD *)v9 + 4) = this;
    *((_DWORD *)v9 + 2) = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B53C0
// Name: public: virtual void GFxPlaceObject3::AddToTimelineSnapshot(class GFxTimelineSnapshot __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxPlaceObject3::AddToTimelineSnapshot(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CFuncMemPolicyNone> *this,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CFuncMemPolicyNone> *result,
        unsigned int frame)
{
  unsigned __int16 v4; // ax
  int v5; // ebx
  unsigned __int8 v6; // al
  CMatRenderContextBase **v7; // edi
  int v8; // eax
  int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // edx
  char v12; // al
  int m_pfnProxied; // [esp-Ch] [ebp-20h]
  int v15; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int8 placeType; // [esp+13h] [ebp-1h]

  (*(void (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CFuncMemPolicyNone> *, const char *))(LODWORD(this->m_pfnProxied) + 28))(
    a1: this,
    a2: "\n");
  GFxPlaceObject3::GetDepth(this);
  v5 = v4;
  v6 = GFxPlaceObject3::GetPlaceType(this);
  v7 = &result->m_pObject + 1;
  placeType = v6;
  m_pfnProxied = result[1].m_pfnProxied;
  v15 = v5;
  v8 = G_UpperBoundSliced<GArrayDH_POD<GFxTimelineSnapshot::SnapshotElement *,2,GArrayDefaultPolicy>,int,int (__cdecl *)(int,GFxTimelineSnapshot::SnapshotElement const *)>(
         a1: (_DWORD *)&result->m_pObject + 1,
         a2: 0,
         a3: m_pfnProxied,
         a4: &v15,
         a5: (int (__cdecl *)(_DWORD, _DWORD))GFxTimelineSnapshot::DepthLess);
  if ( v8 != 0 && *(_DWORD *)((v9 = *((_DWORD *)*v7 + v8 - 1)) + 12) == v5 && v9 != 0 && (*(_BYTE *)(v9 + 53) & 2) == 0 )
  {
    if ( placeType == 1 )
    {
      (*(void (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CFuncMemPolicyNone> *, char *))(LODWORD(this->m_pfnProxied) + 40))(
        a1: this,
        a2: (char *)&frame + 3);
      LOBYTE(v10) = HIBYTE(frame);
      if ( (frame & 0x4000000) != 0 )
        *(_DWORD *)(v9 + 20) = this;
      if ( (v10 & 8) != 0 )
        *(_DWORD *)(v9 + 24) = this;
      if ( (v10 & 0x20) != 0 )
        *(_DWORD *)(v9 + 28) = this;
      if ( (v10 & 0x80u) != 0 )
        *(_DWORD *)(v9 + 32) = this;
      if ( (v10 & 1) != 0 )
        *(_DWORD *)(v9 + 36) = this;
      if ( (v10 & 0x40) != 0 )
        *(_DWORD *)(v9 + 40) = this;
      if ( (v10 & 0x10) != 0 )
        *(_DWORD *)(v9 + 44) = this;
      if ( (v10 & 2) != 0 )
        *(_DWORD *)(v9 + 48) = this;
    }
    else if ( placeType == 2 )
    {
      if ( *(_BYTE *)(v9 + 52) != 0 )
        *(_BYTE *)(v9 + 52) = 2;
      (*(void (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CFuncMemPolicyNone> *, char *))(LODWORD(this->m_pfnProxied) + 40))(
        a1: this,
        a2: (char *)&result + 3);
      v12 = HIBYTE(result);
      if ( (HIBYTE(result) & 4) != 0 )
        *(_DWORD *)(v9 + 20) = this;
      if ( (v12 & 8) != 0 )
        *(_DWORD *)(v9 + 24) = this;
      if ( (v12 & 0x20) != 0 )
        *(_DWORD *)(v9 + 28) = this;
      if ( v12 < 0 )
        *(_DWORD *)(v9 + 32) = this;
      if ( (v12 & 1) != 0 )
        *(_DWORD *)(v9 + 36) = this;
      if ( (v12 & 0x40) != 0 )
        *(_DWORD *)(v9 + 40) = this;
      if ( (v12 & 0x10) != 0 )
        *(_DWORD *)(v9 + 44) = this;
      if ( (v12 & 2) != 0 )
        *(_DWORD *)(v9 + 48) = this;
      LOBYTE(v10) = frame;
      *(_DWORD *)(v9 + 8) = frame;
    }
    else
    {
      v10 = frame;
      *(_DWORD *)(v9 + 48) = this;
      *(_DWORD *)(v9 + 44) = this;
      *(_DWORD *)(v9 + 40) = this;
      *(_DWORD *)(v9 + 36) = this;
      *(_DWORD *)(v9 + 32) = this;
      *(_DWORD *)(v9 + 28) = this;
      *(_DWORD *)(v9 + 24) = this;
      *(_DWORD *)(v9 + 20) = this;
      *(_DWORD *)(v9 + 16) = this;
      *(_DWORD *)(v9 + 8) = v10;
    }
  }
  else
  {
    v10 = (unsigned int)GFxTimelineSnapshot::Add(this: (GFxTimelineSnapshot *)result, a2: v5);
    v11 = frame;
    *(_BYTE *)(v10 + 52) = placeType;
    *(_DWORD *)(v10 + 48) = this;
    *(_DWORD *)(v10 + 44) = this;
    *(_DWORD *)(v10 + 40) = this;
    *(_DWORD *)(v10 + 36) = this;
    *(_DWORD *)(v10 + 32) = this;
    *(_DWORD *)(v10 + 28) = this;
    *(_DWORD *)(v10 + 24) = this;
    *(_DWORD *)(v10 + 20) = this;
    *(_DWORD *)(v10 + 16) = this;
    *(_DWORD *)(v10 + 8) = v11;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x100B5550
// Name: public: virtual void GFxSprite::Display(class GFxDisplayContext __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::Display(GFxSprite *this, CUtlVector<void *,CUtlMemory<void *,int> > *a2)
{
  GFxAmpViewStats *m_nAllocationCount; // ebx
  int v3; // eax
  float v5; // ecx
  int v6; // edx
  float v7; // eax
  float v8; // ecx
  int m_nGrowSize; // ecx
  void **m_pMemory; // edx
  void **m_pElements; // eax
  int m_Size; // edx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  struct GFxCharacter *v16; // ebx
  int v17; // ebx
  char v18; // al
  int v19; // eax
  float v20; // ecx
  void (__thiscall ***v21)(_DWORD, int); // esi
  void *const *v22; // [esp+0h] [ebp-FCh]
  float *v23; // [esp+4h] [ebp-F8h]
  CUtlVector<void *,CUtlMemory<void *,int> > oldFilters; // [esp+Ch] [ebp-F0h] BYREF
  float v25; // [esp+20h] [ebp-DCh]
  float v26; // [esp+24h] [ebp-D8h]
  int v27; // [esp+38h] [ebp-C4h]
  int oldXform[5]; // [esp+3Ch] [ebp-C0h] BYREF
  char v29; // [esp+50h] [ebp-ACh]
  int v30; // [esp+54h] [ebp-A8h]
  int v31; // [esp+58h] [ebp-A4h]
  GFxAmpViewStats *v32; // [esp+5Ch] [ebp-A0h]
  float v33; // [esp+6Ch] [ebp-90h]
  float v34; // [esp+70h] [ebp-8Ch]
  float v35; // [esp+74h] [ebp-88h]
  int v36; // [esp+78h] [ebp-84h]
  char v37; // [esp+7Dh] [ebp-7Fh]
  char v38; // [esp+7Eh] [ebp-7Eh]
  char v39; // [esp+7Fh] [ebp-7Dh]
  GMatrix3D v40; // [esp+80h] [ebp-7Ch] BYREF
  struct GRenderer::Cxform v41; // [esp+C0h] [ebp-3Ch] BYREF
  struct GMatrix2D v42; // [esp+E0h] [ebp-1Ch] BYREF

  m_nAllocationCount = (GFxAmpViewStats *)a2[7].m_Memory.m_nAllocationCount;
  v3 = 0;
  v32 = m_nAllocationCount;
  if ( m_nAllocationCount != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: m_nAllocationCount, swdHandle: 1u, a3: 1u);
    GTimer::GetRawTicks(li: v5, a2: *(float *)&v22, a3: v23);
    v31 = v6;
  }
  else
  {
    v31 = 0;
  }
  v30 = v3;
  v7 = *((float *)this + 40);
  v8 = v7;
  if ( (LOBYTE(v7) & 3) != 1 && (LOWORD(v7) & 0x8000) == 0 )
  {
    if ( m_nAllocationCount == nullptr )
      return;
    LOBYTE(v8) = LOBYTE(v7) & 3;
    GTimer::GetRawTicks(li: v8, a2: *(float *)&v22, a3: v23);
    goto LABEL_38;
  }
  m_nGrowSize = a2->m_Memory.m_nGrowSize;
  m_pMemory = a2->m_Memory.m_pMemory;
  oldXform[1] = a2->m_Memory.m_nAllocationCount;
  m_pElements = a2->m_pElements;
  oldXform[0] = (int)m_pMemory;
  m_Size = a2->m_Size;
  oldXform[2] = m_nGrowSize;
  LOBYTE(m_nGrowSize) = a2[1].m_Memory.m_pMemory;
  oldXform[4] = (int)m_pElements;
  v13 = (int)*(this + 36);
  oldXform[3] = m_Size;
  v14 = a2[5].m_Size;
  v29 = m_nGrowSize;
  v15 = *(_DWORD *)(v13 + 28) + 24;
  v36 = v14;
  a2[5].m_Size = v15;
  GRenderer::Cxform::Cxform(this: (float *)&v41);
  GMatrix2D::SetIdentity(this: (float *)&v42);
  GMatrix3D::SetIdentity(this: &v40);
  if ( *(this + 116) == nullptr || ((unsigned __int8 (__thiscall *)(GFxSprite *))(*this)[11].RefCount)(a1: this) != 0 )
    v16 = nullptr;
  else
    v16 = (struct GFxCharacter *)*(this + 116);
  v39 = 0;
  if ( v16 != nullptr )
  {
    if ( (*(unsigned __int8 (__thiscall **)(struct GFxCharacter *))(*(_DWORD *)v16 + 180))(a1: v16) == 0
      || (*((_BYTE *)v16 + 118) & 0x10) != 0 )
    {
      GFxSprite::SetMask((GPtr<GFxZlibSupportBase> *)this, result: nullptr);
    }
    else
    {
      GFxDisplayContext::PreDrawMask(this: (GFxDisplayContext *)a2, a2: v16, a3: &v42, a4: &v40);
      GFxDisplayContext::PushAndDrawMask(this: a2, pmask: (int)v16, a3: v22);
      v39 = 1;
    }
  }
  GFxDisplayContext::PreDisplay(
    this: (GFxDisplayContext *)a2,
    a2: (struct GFxDisplayContextTransforms *)oldXform,
    a3: (const struct GFxCharacter *)this,
    a4: &v42,
    a5: &v40,
    a6: &v41);
  v17 = (int)*(this + 43);
  *(float *)&oldFilters.m_Size = 0.0;
  *(float *)&oldFilters.m_pElements = 0.0;
  v25 = 0.0;
  LOBYTE(oldFilters.m_Memory.m_pMemory) = 0;
  v26 = 0.0;
  v27 = 0;
  oldFilters.m_Memory.m_nGrowSize = 0;
  oldFilters.m_Memory.m_nAllocationCount = 0;
  v38 = 0;
  if ( v17 != 0 && *(_BYTE *)(v17 + 12) != 0 )
  {
    if ( *(_DWORD *)(v17 + 16) != 0 )
    {
      v33 = *(float *)(v17 + 24);
      v35 = *(float *)(v17 + 28);
      v34 = *(float *)(v17 + 32);
      GFxDisplayContext::DisplayFilterPrePass(this: a2, ch: (void *const *)this);
      goto LABEL_30;
    }
    GFxDisplayContext::BeginFilters(this: a2, oldFilters: (void *const *)&oldFilters.m_Memory.m_pMemory, ch: (int)this);
    v38 = v18;
  }
  if ( *(this + 115) != nullptr )
  {
    GFxCharacter::GetActiveBlendMode((CMemberFuncProxy2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CFuncMemPolicyNone> *)this);
    GFxDrawingContext::Display(this: (IClientTools *)*(this + 115), context: (int)a2);
  }
  v19 = (int)*(this + 119);
  v37 = 0;
  if ( v19 != 0 )
    v37 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2[3].m_Size + 12) + 76))(
            a1: *(_DWORD *)(a2[3].m_Size + 12),
            a2: v19 + 72);
  GFxDisplayList::Display(
    this: (CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *)(this + 49),
    context: (const CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *)a2);
  if ( v37 != 0 )
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2[3].m_Size + 12) + 80))(a1: *(_DWORD *)(a2[3].m_Size + 12));
  if ( v38 != 0 )
    GFxDisplayContext::EndFilters(this: a2, &oldFilters);
LABEL_30:
  a2[5].m_Size = v36;
  GFxDisplayContext::PostDisplay(this: a2, (int)oldXform);
  ((void (__thiscall *)(GFxSprite *))(*this)[17].RefCount)(a1: this);
  if ( v39 != 0 )
    GFxDisplayContext::PopMask(this: a2, a2: v22);
  v21 = (void (__thiscall ***)(_DWORD, int))v27;
  if ( v27 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v27 + 4), Value: -1) == 1 && v21 != nullptr )
    (**v21)(a1: v21, a2: 1);
  if ( v32 != nullptr )
  {
    GTimer::GetRawTicks(li: v20, a2: *(float *)&v22, a3: v23);
LABEL_38:
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5890
// Name: GFx_InitializeClassInstance
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_InitializeClassInstance(int fn)
{
  _TAPE_WMI_OPERATIONS *v1; // eax
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v2; // esi
  unsigned int v3; // eax
  int v4; // [esp-4h] [ebp-18h]
  _TAPE_WMI_OPERATIONS *v5; // [esp+0h] [ebp-14h]
  int v6; // [esp+8h] [ebp-Ch] BYREF
  int v7; // [esp+Ch] [ebp-8h]
  char v8; // [esp+10h] [ebp-4h]

  v1 = GASObjectInterface::ToSprite(result: v5);
  v2 = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v1;
  if ( v1 != nullptr )
    ++v1->DataBufferSize;
  v4 = *(_DWORD *)(fn + 24);
  GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
  GASValue::ToFunction(a1: &v6, a2: v4);
  if ( v6 != 0 )
    v3 = v6 + 16;
  else
    v3 = 0;
  GFxASCharacter::SetProtoToPrototypeOf(this: v2, psrcObj: v3);
  if ( (v8 & 2) == 0 && v6 != 0 )
    GRefCountBaseGC<323>::Release(a1: v6, a2: fn);
  v6 = 0;
  if ( (v8 & 1) == 0 && v7 != 0 )
    GRefCountBaseGC<323>::Release(a1: v7, a2: fn);
  v7 = 0;
  if ( v2 != nullptr )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v2);
}

//------------------------------------------------------------------------------
// Address: 0x100B5920
// Name: public: GFxMovieRoot::ActionEntry::~ActionEntry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ActionEntry::~ActionEntry(GMatrix3D *this)
{
  GASValue *v2; // edi
  float v3; // ebx
  int v4; // ecx
  bool v5; // zf
  int v6; // ecx
  GRefCountNTSImpl *v7; // ecx
  GRefCountNTSImpl *v8; // esi

  v2 = (GASValue *)(LODWORD(this->M_[3][0]) + 16 * LODWORD(this->M_[3][1]) - 16);
  if ( LODWORD(this->M_[3][1]) != 0 )
  {
    v3 = this->M_[3][1];
    do
    {
      GASValue::~GASValue(this: v2);
      v2 -= 4;
      --LODWORD(v3);
    }
    while ( v3 != 0.0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)LODWORD(this->M_[3][0]));
  if ( (LOBYTE(this->M_[2][2]) & 2) == 0 )
  {
    v4 = LODWORD(this->M_[2][0]);
    if ( v4 != 0 )
      GRefCountBaseGC<323>::Release(a1: v4, a2: (int)v2);
  }
  v5 = (LOBYTE(this->M_[2][2]) & 1) == 0;
  this->M_[2][0] = 0.0;
  if ( v5 )
  {
    v6 = LODWORD(this->M_[2][1]);
    if ( v6 != 0 )
      GRefCountBaseGC<323>::Release(a1: v6, a2: 0);
  }
  this->M_[2][1] = 0.0;
  v7 = (GRefCountNTSImpl *)LODWORD(this->M_[0][3]);
  if ( v7 != nullptr )
    GRefCountNTSImpl::Release(this: v7);
  v8 = (GRefCountNTSImpl *)LODWORD(this->M_[0][2]);
  if ( v8 != nullptr )
    GRefCountNTSImpl::Release(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x100B59B0
// Name: public: virtual bool GFxSprite::GetStandardMember(enum GFxASCharacter::StandardMember,class GASValue __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSprite::GetStandardMember(
        GMemoryFile *this@<ecx>,
        double a2@<st0>,
        const GMemoryFile *member,
        unsigned int penv,
        int opcodeFlag)
{
  tagCOMPAREITEMSTRUCT *v7; // eax
  tagCOMPAREITEMSTRUCT *LoadingFrame; // eax
  int v9; // ebx
  char v10; // al
  GASValue *v11; // ecx
  bool v12; // bl
  struct GFxCharacterHandle *v13; // edi
  int v14; // ebx
  int v15; // ecx
  int (__thiscall *v16)(int, int, int *); // edx
  GASRectangleObject *v17; // eax
  struct GASObject *v18; // ebx
  float *v19; // edi
  double v20; // st6
  double v21; // st5
  double v22; // st7
  int v23; // [esp+0h] [ebp-2Ch]
  double v24[4]; // [esp+Ch] [ebp-20h] BYREF
  unsigned int penva; // [esp+38h] [ebp+Ch]

  if ( GFxASCharacter::GetStandardMember(a1: (int)this, a2, a3: (int)member, a4: (GASValue *)penv, opcodeFlag) == 0 )
  {
    switch ( (unsigned int)member )
    {
      case 4u:
        GASValue::SetInt(this: penv, result: (tagCOMPAREITEMSTRUCT *)(*((_DWORD *)this + 54) + 1));
        return;
      case 5u:
        v7 = (tagCOMPAREITEMSTRUCT *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 46) + 40))(a1: *((_DWORD *)this + 46));
        GASValue::SetInt(this: penv, result: v7);
        return;
      case 0xCu:
        LoadingFrame = (tagCOMPAREITEMSTRUCT *)GFxSprite::GetLoadingFrame((int)this);
        GASValue::SetInt(this: penv, result: LoadingFrame);
        return;
      case 0x1Cu:
        LOBYTE(v9) = *((_BYTE *)this + 480) >> 5;
        goto LABEL_8;
      case 0x21u:
        v10 = *((_BYTE *)this + 481);
        v11 = (GASValue *)penv;
        if ( v10 != 0 )
          goto LABEL_10;
        goto LABEL_25;
      case 0x22u:
        v10 = *((_BYTE *)this + 482);
        v11 = (GASValue *)penv;
        if ( v10 == 0 )
          goto LABEL_25;
LABEL_10:
        v12 = v10 == 1;
        GASValue::DropRefs(this: v11);
        *(_BYTE *)(penv + 4) = v12;
        *(_BYTE *)penv = 2;
        break;
      case 0x24u:
        if ( *(_BYTE *)(this->__vftable[1].GetErrorCode(this) + 124) < 8u )
          return;
        if ( *((_DWORD *)this + 48) != 0 )
        {
          v14 = this->__vftable[1].GetErrorCode(this);
          v15 = *(_DWORD *)(*(_DWORD *)(v14 + 120) + 656);
          v16 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v15 + 40);
          penva = v14;
          opcodeFlag = 323;
          v17 = (GASRectangleObject *)v16(a1: v15, a2: 52, a3: &opcodeFlag);
          if ( v17 != nullptr )
            v18 = (struct GASObject *)GASRectangleObject::GASRectangleObject(
                                        this: v17,
                                        a2: (struct GASEnvironment *)v14);
          else
            v18 = nullptr;
          v19 = *((float **)this + 48);
          *(float *)&opcodeFlag = v19[1] / 20.0;
          v20 = *(float *)&opcodeFlag;
          *(float *)&opcodeFlag = v19[2] + *v19;
          *(float *)&opcodeFlag = *(float *)&opcodeFlag / 20.0;
          v21 = *(float *)&opcodeFlag;
          *(float *)&opcodeFlag = v19[3] + v19[1];
          *(float *)&opcodeFlag = *(float *)&opcodeFlag / 20.0;
          v22 = *(float *)&opcodeFlag;
          *(float *)&opcodeFlag = *v19 / 20.0;
          v24[0] = *(float *)&opcodeFlag;
          v24[1] = v20;
          v24[2] = v21;
          v24[3] = v22;
          GASRectangleObject::SetProperties(penv: penva, r: (GMemoryHeap *)v24, a3: v23);
          GASValue::SetAsObject(this: (GASValue *)penv, a2: v18);
          if ( v18 != nullptr )
            GRefCountBaseGC<323>::Release(a1: (int)v18, a2: (int)v19);
        }
        else
        {
          v11 = (GASValue *)penv;
LABEL_25:
          GASValue::DropRefs(this: v11);
          *(_BYTE *)penv = 0;
        }
        break;
      case 0x25u:
        v13 = *((struct GFxCharacterHandle **)this + 117);
        if ( v13 != nullptr )
        {
          GASValue::SetAsCharacterHandle(this: (GASValue *)penv, a2: v13);
        }
        else
        {
          GASValue::DropRefs(this: (GASValue *)penv);
          *(_BYTE *)penv = 0;
        }
        return;
      case 0x45u:
        if ( *(_BYTE *)(*(_DWORD *)(this->__vftable[1].GetErrorCode(this) + 120) + 684) == 1 )
        {
          v9 = *((_DWORD *)this + 40) >> 11;
LABEL_8:
          GASValue::DropRefs(this: (GASValue *)penv);
          *(_BYTE *)(penv + 4) = v9 & 1;
          *(_BYTE *)penv = 2;
        }
        return;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5C70
// Name: private: bool GFxSprite::GetMember(class GASEnvironment __near *,class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge GFxSprite::GetMember(
        GFxFontLib *this@<ecx>,
        double a2@<st0>,
        struct GStringHash<GString,GAllocatorGH<GString,2> > *penv,
        _IMAGE_SYMBOL_EX *name,
        _IMAGE_SYMBOL_EX *pcaseInsensitiveName,
        MaterialPrimitiveType_t *memberName)
{
  struct GStringHash<GString,GAllocatorGH<GString,2> > *v6; // ebx
  char v8; // al
  CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *StandardMemberConstant; // ebx
  int v10; // ecx
  int (__thiscall *v11)(int, int, _BYTE *); // edx
  GASTransformObject *v12; // edi
  struct GASEnvironment *v13; // eax
  struct GASObject *v14; // esi
  int v15; // eax
  struct GASStringNode *ConstStringNode; // esi
  int (__cdecl *v18)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *); // ebx
  int v19; // ecx
  int (__thiscall *v20)(int, int, _BYTE *); // edx
  unsigned int v21; // eax
  GASArrayObject *v22; // edi
  int i; // esi
  double PerspectiveFOV; // st7
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // ebx
  int v30; // eax
  struct GStringHash<GString,GAllocatorGH<GString,2> > *v31; // eax
  char v32; // bl
  tagBITMAPCOREHEADER *CharacterByName; // eax
  int v34; // ebx
  GMemoryHeap *v35; // [esp+14h] [ebp-98h]
  const char *v36; // [esp+18h] [ebp-94h]
  int v37; // [esp+1Ch] [ebp-90h]
  GASValue *params; // [esp+20h] [ebp-8Ch] OVERLAPPED BYREF
  GASValue *v39; // [esp+24h] [ebp-88h]
  GASValue v40; // [esp+28h] [ebp-84h] BYREF
  double v41; // [esp+2Ch] [ebp-80h]
  int v42; // [esp+34h] [ebp-78h]
  GFxValue::ObjectInterface newproto; // [esp+38h] [ebp-74h] BYREF
  unsigned int v44; // [esp+3Ch] [ebp-70h]
  struct GStringHash<GString,GAllocatorGH<GString,2> > *v45; // [esp+40h] [ebp-6Ch]
  _BYTE rv[5]; // [esp+47h] [ebp-65h] OVERLAPPED BYREF
  GASValue *v47; // [esp+4Ch] [ebp-60h]
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> v48; // [esp+50h] [ebp-5Ch] BYREF

  v6 = penv;
  v45 = penv;
  *(_DWORD *)&rv[1] = name;
  v47 = (GASValue *)memberName;
  GFxASCharacter::IsStandardMember(memberName, pcaseInsensitiveName, lowerCase: nullptr);
  if ( v8 != 0 )
  {
    StandardMemberConstant = GFxASCharacter::GetStandardMemberConstant(this, result: pcaseInsensitiveName);
    if ( ((unsigned __int8 (__thiscall *)(GFxFontLib *, CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, GASValue *, _DWORD))this->__vftable[36].dtr_GRefCountImplCore)(
           a1: this,
           a2: StandardMemberConstant,
           a3: v47,
           a4: 0) == 0 )
    {
      switch ( (unsigned int)StandardMemberConstant )
      {
        case '#':
          v10 = *(_DWORD *)(*(_DWORD *)(((int (__thiscall *)(GFxFontLib *))this->__vftable[14].dtr_GRefCountImplCore)(a1: this)
                                      + 120)
                          + 656);
          v11 = *(int (__thiscall **)(int, int, _BYTE *))(*(_DWORD *)v10 + 40);
          *(_DWORD *)&rv[1] = 323;
          v12 = (GASTransformObject *)v11(a1: v10, a2: 72, a3: &rv[1]);
          if ( v12 != nullptr )
          {
            v13 = (struct GASEnvironment *)((int (__thiscall *)(GFxFontLib *))this->__vftable[14].dtr_GRefCountImplCore)(a1: this);
            v14 = (struct GASObject *)GASTransformObject::GASTransformObject(
                                        this: v12,
                                        a2: v13,
                                        a3: (struct GFxASCharacter *)this);
          }
          else
          {
            v14 = nullptr;
          }
          GASValue::SetAsObject(this: v47, a2: v14);
          if ( v14 != nullptr )
            GRefCountBaseGC<323>::Release(a1: (int)v14, a2: (int)v12);
          break;
        case 'l':
          GFxASCharacter::GeomDataType::GeomDataType(this: &v48);
          GFxASCharacter::GetGeomData(
            (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this,
            a2,
            fX: &v48);
          GASValue::SetNumber(this: v47, a2: *(double *)(v25 + 56));
          break;
        case 'm':
          GFxASCharacter::GeomDataType::GeomDataType(this: &v48);
          GFxASCharacter::GetGeomData(
            (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this,
            a2,
            fX: &v48);
          GASValue::SetNumber(this: v47, a2: *(double *)(v26 + 64));
          break;
        case 'n':
          GFxASCharacter::GeomDataType::GeomDataType(this: &v48);
          GFxASCharacter::GetGeomData(
            (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this,
            a2,
            fX: &v48);
          GASValue::SetNumber(this: v47, a2: *(double *)(v27 + 72));
          break;
        case 'o':
          GFxASCharacter::GeomDataType::GeomDataType(this: &v48);
          GFxASCharacter::GetGeomData(
            (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this,
            a2,
            fX: &v48);
          GASValue::SetNumber(this: v47, a2: *(double *)(v28 + 80));
          break;
        case 'p':
          v18 = *((int (__cdecl **)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *))this + 23);
          if ( v18 == nullptr )
            v18 = GMatrix3D::Identity;
          v19 = *(_DWORD *)(*((_DWORD *)v45 + 30) + 656);
          v20 = *(int (__thiscall **)(int, int, _BYTE *))(*(_DWORD *)v19 + 40);
          *(_DWORD *)&rv[1] = 323;
          if ( v20(a1: v19, a2: 76, a3: &rv[1]) != 0 )
          {
            v21 = ((int (__thiscall *)(GFxFontLib *))this->__vftable[14].dtr_GRefCountImplCore)(a1: this);
            v22 = (GASArrayObject *)GASArrayObject::GASArrayObject(penv: v21, a2: v35, a3: v36, a4: v37);
          }
          else
          {
            v22 = nullptr;
          }
          GASArrayObject::Resize(size: (void *)0x10, a2: v35);
          for ( i = 0; i < 16; ++i )
          {
            *(float *)&rv[1] = *((float *)v18 + i);
            v41 = *(float *)&rv[1];
            LOBYTE(v40) = 3;
            GASArrayObject::SetElement(this: v22, a2: i, a3: (const struct GASValue *)&v40);
            GASValue::~GASValue(this: &v40);
          }
          GASValue::SetAsObject(this: v47, a2: (struct GASObject *)v22);
          if ( v22 != nullptr )
            GRefCountBaseGC<323>::Release(a1: (int)v22, a2: (int)v22);
          break;
        case 'q':
          GFxASCharacter::GeomDataType::GeomDataType(this: &v48);
          PerspectiveFOV = GFxCharacter::GetPerspectiveFOV((GFxCharacter *)this, a2: false);
          GASValue::SetNumber(this: v47, a2: PerspectiveFOV);
          break;
        case 'r':
          if ( *((int *)this + 111) < 0 )
            goto LABEL_29;
          v15 = ((int (__thiscall *)(GFxFontLib *))this->__vftable[14].dtr_GRefCountImplCore)(a1: this);
          ConstStringNode = GASStringManager::CreateConstStringNode(
                              this: *(GASStringManager **)(*(_DWORD *)(v15 + 120) + 636),
                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0AD0,
                              a3: 0xBu,
                              a4: 0);
          ++*((_DWORD *)ConstStringNode + 2);
          *(_DWORD *)&rv[1] = ConstStringNode;
          GASValue::SetString(this: v47, str: (_IMAGE_SYMBOL_EX *)&rv[1]);
          if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
            GASStringNode::ReleaseNode();
          break;
        default:
LABEL_29:
          v6 = v45;
          goto LABEL_30;
      }
    }
  }
  else
  {
LABEL_30:
    if ( v6 != nullptr && pcaseInsensitiveName->N.Name.Short == *(_DWORD *)(*((_DWORD *)v6 + 30) + 320)
      || *(_DWORD *)&rv[1] != 0 && pcaseInsensitiveName->N.Name.Short == *(_DWORD *)(**(_DWORD **)&rv[1] + 320) )
    {
      GASValue::SetAsObject(this: v47, a2: *((struct GASObject **)this + 32));
      return;
    }
    v29 = *((_DWORD *)this + 113);
    if ( v29 != 0 )
    {
      v30 = *(_DWORD *)(v29 + 24);
      if ( v30 != 0 )
        *(_DWORD *)(v30 + 8) = (*(_DWORD *)(v30 + 8) + 1) & 0x8FFFFFFF;
      v44 = *(_DWORD *)(v29 + 24);
      if ( v44 != 0 )
        GRefCountBaseGC<323>::Release(a1: v44, a2: (int)pcaseInsensitiveName);
      v31 = v45;
      *(_DWORD *)(v29 + 24) = 0;
      v32 = 0;
      if ( v31 != nullptr
        && (*(unsigned __int8 (__thiscall **)(int, struct GStringHash<GString,GAllocatorGH<GString,2> > *, _IMAGE_SYMBOL_EX *, GASValue *))(*(_DWORD *)(*((_DWORD *)this + 113) + 16) + 16))(
             a1: *((_DWORD *)this + 113) + 16,
             a2: v31,
             a3: pcaseInsensitiveName,
             a4: v47) != 0
        || *(_DWORD *)&rv[1] != 0
        && (*(unsigned __int8 (__thiscall **)(int, _DWORD, _IMAGE_SYMBOL_EX *, GASValue *))(*(_DWORD *)(*((_DWORD *)this + 113) + 16)
                                                                                          + 44))(
             a1: *((_DWORD *)this + 113) + 16,
             a2: *(_DWORD *)&rv[1],
             a3: pcaseInsensitiveName,
             a4: v47) != 0 )
      {
        v32 = 1;
      }
      GASMovieClipObject::Exchange__proto__(
        this: *((GFxValue::ObjectInterface **)this + 113),
        &newproto,
        a3: v44,
        a4: (const GFxValue *)v35);
      if ( newproto.pMovieRoot != nullptr )
        GRefCountBaseGC<323>::Release(a1: (int)newproto.pMovieRoot, a2: (int)pcaseInsensitiveName);
      if ( v32 != 0 )
      {
        if ( v44 != 0 )
          GRefCountBaseGC<323>::Release(a1: v44, a2: (int)pcaseInsensitiveName);
        return;
      }
      if ( v44 != 0 )
        GRefCountBaseGC<323>::Release(a1: v44, a2: (int)pcaseInsensitiveName);
    }
    CharacterByName = (tagBITMAPCOREHEADER *)GFxDisplayList::GetCharacterByName(
                                               this: (CMemberFuncProxy0<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *)((char *)this + 196),
                                               psc: (unsigned int)(this + 22));
    if ( CharacterByName != nullptr )
    {
      GASValue::SetAsCharacter(result: CharacterByName);
    }
    else
    {
      v34 = *((_DWORD *)this + 32);
      if ( (v34 == 0
         || (v45 == nullptr
          || (*(unsigned __int8 (__thiscall **)(int, struct GStringHash<GString,GAllocatorGH<GString,2> > *, _IMAGE_SYMBOL_EX *, GASValue *))(*(_DWORD *)(v34 + 16) + 16))(
               a1: v34 + 16,
               a2: v45,
               a3: pcaseInsensitiveName,
               a4: v47) == 0)
         && (*(_DWORD *)&rv[1] == 0
          || (*(unsigned __int8 (__thiscall **)(int, _DWORD, _IMAGE_SYMBOL_EX *, GASValue *))(*(_DWORD *)(v34 + 16) + 44))(
               a1: v34 + 16,
               a2: *(_DWORD *)&rv[1],
               a3: pcaseInsensitiveName,
               a4: v47) == 0))
        && GASString::GetLength(this: (GASString *)pcaseInsensitiveName) != 0
        && **(_BYTE **)pcaseInsensitiveName->N.Name.Short == 95 )
      {
        v39 = v47;
        params = (GASValue *)pcaseInsensitiveName;
        v40 = nullptr;
        v41 = 0.0;
        v42 = 0;
        GASEnvironment::CheckGlobalAndLevels(this: (__vc_attributes::satypeAttribute *)this + 58, a2: rv, a3: &params);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6220
// Name: public: virtual bool GFxSprite::PointTestLocal(class GPoint<float> const __near &,unsigned char)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxSprite::PointTestLocal@<al>(
        GFxCharacter *this@<ecx>,
        const CMaterialDict::MaterialLookup_t *a2@<edi>,
        float *p,
        int a4)
{
  float *v4; // ebx
  float *v7; // ecx
  bool v8; // zf
  GFxCharacter *v9; // edi
  int v10; // eax
  double v11; // st7
  int v12; // edi
  int Perspective3D; // ebx
  int v14; // eax
  int v15; // eax
  IClientTools *v16; // ecx
  int v17; // [esp-24h] [ebp-DCh]
  GFxCharacter *v18; // [esp-20h] [ebp-D8h]
  CCountedStringPoolBase<unsigned int>::hash_item_t *v19; // [esp-14h] [ebp-CCh]
  int v21; // [esp-Ch] [ebp-C4h]
  int v22; // [esp+8h] [ebp-B0h]
  CCountedStringPoolBase<unsigned int>::hash_item_t v23; // [esp+10h] [ebp-A8h] BYREF
  unsigned int nNextElement; // [esp+1Ch] [ebp-9Ch]
  int v25; // [esp+20h] [ebp-98h]
  int View3D; // [esp+24h] [ebp-94h]
  char v27; // [esp+2Bh] [ebp-8Dh]
  GMatrix3D pmat; // [esp+2Ch] [ebp-8Ch] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v29; // [esp+6Ch] [ebp-4Ch] BYREF
  float v30; // [esp+80h] [ebp-38h]
  struct GMatrix2D m; // [esp+84h] [ebp-34h] BYREF
  GMatrix2D v32; // [esp+9Ch] [ebp-1Ch] BYREF

  v4 = p;
  if ( (*((_DWORD *)this + 40) & 0x800) != 0 )
    return 0;
  if ( (*((_BYTE *)this + 118) & 1) == 0
    && (*(unsigned __int8 (__thiscall **)(GFxCharacter *))(*(_DWORD *)this + 8))(a1: this) == 0 )
  {
    GMatrix2D::SetIdentity(this: (float *)&m);
    v7 = (float *)(*(int (__thiscall **)(GFxCharacter *, float *, struct GMatrix2D *))(*(_DWORD *)this + 52))(
                    a1: this,
                    a2: &v32.M_[0][2],
                    a3: &m);
    if ( v7[2] < (double)*p || *v7 > (double)*p || v7[3] < (double)p[1] || v7[1] > (double)p[1] )
      return 0;
  }
  v27 = a4 & 2;
  if ( (a4 & 2) != 0 && (*(unsigned __int8 (__thiscall **)(GFxCharacter *))(*(_DWORD *)this + 16))(a1: this) == 0 )
    return 0;
  v8 = *((_DWORD *)this + 116) == 0;
  View3D = *((_DWORD *)this + 50);
  if ( v8 )
    goto LABEL_17;
  if ( (*(unsigned __int8 (__thiscall **)(GFxCharacter *))(*(_DWORD *)this + 180))(a1: this) != 0 )
    goto LABEL_17;
  v9 = *((GFxCharacter **)this + 116);
  if ( v9 == nullptr )
    goto LABEL_17;
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)v9 + 180))(a1: *((_DWORD *)this + 116)) == 0 )
    goto LABEL_17;
  if ( (*((_BYTE *)v9 + 118) & 0x10) != 0 )
    goto LABEL_17;
  GMatrix2D::SetIdentity(this: (float *)&v32);
  GMatrix2D::SetIdentity(this: (float *)&m);
  GFxCharacter::GetWorldMatrix(this: v9, pmat: (CMaterialDict *)&m);
  GMatrix2D::SetInverse(a1: (float *)&v32, (const CMaterialDict::MaterialLookup_t *)&m, a3: a2);
  GMatrix2D::SetIdentity(this: (float *)&m);
  GFxCharacter::GetWorldMatrix(this, pmat: (CMaterialDict *)&m);
  GMatrix2D::Prepend(this: &v32, a2: &m);
  GMatrix2D::Transform(
    this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v32,
    result: &v23,
    p,
    p_4: v21);
  v19 = &v23;
  if ( (*(unsigned __int8 (__thiscall **)(GFxCharacter *))(*(_DWORD *)v9 + 68))(a1: v9) != 0 )
  {
LABEL_17:
    memset(v32.M_[1], 0, sizeof(v32.M_[1]));
    GFxSprite::CalcDisplayListHitTestMaskArray(
      a1: (int)this,
      a2: (int)this,
      result: (_RGNDATAHEADER *)v32.M_[1],
      testShape: (int)p,
      a5: a4 & 1);
    GMatrix2D::SetIdentity(this: (float *)&v29);
    *(float *)&v23.nReferenceCount = *p;
    v10 = View3D - 1;
    v11 = p[1];
    v25 = View3D - 1;
    for ( *(float *)&nNextElement = v11; v25 >= 0; v10 = --v25 )
    {
      v12 = *(_DWORD *)(*((_DWORD *)this + 49) + 4 * v10);
      if ( (v27 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v12 + 16))(a1: v12) != 0)
        && (LODWORD(v32.M_[1][1]) == 0 || *(_BYTE *)(LODWORD(v32.M_[1][0]) + v25) != 0 && *(_WORD *)(v12 + 116) == 0) )
      {
        if ( GFxCharacter::Is3D(
               this: (_DWORD *)v12,
               result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) != 0 )
        {
          Perspective3D = GFxCharacter::GetPerspective3D(this: (_DWORD *)v12, checkAncestors: true);
          View3D = GFxCharacter::GetView3D(this: (_DWORD *)v12, checkAncestors: true);
          if ( Perspective3D != 0 )
            *(_DWORD *)((*(int (__thiscall **)(GFxCharacter *))(*(_DWORD *)this + 84))(a1: this) + 224) = Perspective3D;
          if ( View3D != 0 )
          {
            v14 = (*(int (__thiscall **)(GFxCharacter *))(*(_DWORD *)this + 84))(a1: this);
            *(_DWORD *)(v14 + 228) = View3D;
          }
          GMatrix3D::SetIdentity(this: &pmat);
          GFxCharacter::GetWorldMatrix3D(
            this: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)v12,
            (CMatQueuedMesh::MST_MeshInfo_t *)&pmat);
          *(_DWORD *)((*(int (__thiscall **)(GFxCharacter *))(*(_DWORD *)this + 84))(a1: this) + 232) = &pmat;
          v15 = (*(int (__thiscall **)(GFxCharacter *, unsigned __int8 *))(*(_DWORD *)this + 84))(
                  a1: this,
                  a2: &v23.nReferenceCount);
          GScreenToWorld::GetWorldPoint(this: (CUtlBuffer *)(v15 + 208));
          v4 = p;
        }
        else
        {
          v29.m_Memory.m_pMemory = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(v12 + 68);
          v29.m_Memory.m_nAllocationCount = *(int *)(v12 + 72);
          v29.m_Memory.m_nGrowSize = *(int *)(v12 + 76);
          v29.m_Size = *(int *)(v12 + 80);
          v29.m_pElements = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(v12 + 84);
          v30 = *(float *)(v12 + 88);
          GMatrix2D::TransformByInverse(this: &v29, result: &v23, p: v4, p_4: (int)v19);
          *(float *)&v23.nReferenceCount = *(float *)&v23.pString;
          nNextElement = v23.nNextElement;
        }
        if ( (*(unsigned __int8 (__thiscall **)(int, unsigned __int8 *, int))(*(_DWORD *)v12 + 68))(
               a1: v12,
               a2: &v23.nReferenceCount,
               a3: a4) != 0 )
          goto LABEL_34;
      }
    }
    v16 = *((IClientTools **)this + 115);
    if ( v16 != nullptr )
    {
      v18 = this;
      LOBYTE(v22) = a4 & 1;
      v17 = v22;
      if ( (unsigned __int8)GFxDrawingContext::DefPointTestLocal(this: v16, pt: (int)v4) != 0 )
      {
LABEL_34:
        ((void (__thiscall *)(GMemoryHeap *, _DWORD, int, GFxCharacter *))GMemory::pGlobalHeap->Free)(
          a1: GMemory::pGlobalHeap,
          a2: LODWORD(v32.M_[1][0]),
          a3: v17,
          a4: v18);
        return 1;
      }
    }
    ((void (__thiscall *)(GMemoryHeap *, _DWORD, int, GFxCharacter *))GMemory::pGlobalHeap->Free)(
      a1: GMemory::pGlobalHeap,
      a2: LODWORD(v32.M_[1][0]),
      a3: v17,
      a4: v18);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B65E0
// Name: public: virtual void GFxSprite::FillTabableArray(struct GFxASCharacter::FillTabableParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSprite::FillTabableArray(
        GRefCountBase<GFxResourceLibBase,2> *this@<ecx>,
        float a2@<ebx>,
        unsigned int a3@<edi>,
        const GMatrix2D *a4@<esi>,
        GStat::StatValue *params)
{
  unsigned int v5; // eax
  unsigned int v6; // ebx
  int v7; // edi
  int v8; // eax
  GRefCountBase<GFxResourceLibBase,2> *v9; // esi
  char v10; // bl
  unsigned __int8 v12; // al
  unsigned int i; // edi
  unsigned int v14; // esi
  bool v15; // cc
  const GMatrix2D *v17; // [esp-8h] [ebp-24h]
  float v18; // [esp-4h] [ebp-20h]
  GASValue val[4]; // [esp+0h] [ebp-1Ch] BYREF
  unsigned int n; // [esp+10h] [ebp-Ch]
  struct GASStringNode *ConstStringNode; // [esp+14h] [ebp-8h] BYREF
  GRefCountBase<GFxResourceLibBase,2> *v22; // [esp+18h] [ebp-4h]

  v5 = *((_DWORD *)this + 50);
  v22 = this;
  n = v5;
  if ( v5 != 0 )
  {
    v18 = a2;
    v6 = (unsigned int)params;
    v17 = a4;
    if ( *((_BYTE *)this + 482) == 0 && BYTE2(params->pName) == 0 )
    {
      v7 = *((_DWORD *)this + 32);
      if ( v7 != 0 )
      {
        v8 = *((_DWORD *)this + 88);
        v9 = this + 44;
        LOBYTE(val[0]) = 0;
        ConstStringNode = GASStringManager::CreateConstStringNode(
                            this: *(GASStringManager **)(v8 + 636),
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E3DC,
                            a3: 0xBu,
                            a4: 0);
        ++*((_DWORD *)ConstStringNode + 2);
        v10 = (*(int (__thiscall **)(int, GRefCountBase<GFxResourceLibBase,2> *, struct GASStringNode **, GASValue *))(*(_DWORD *)(v7 + 16) + 44))(
                a1: v7 + 16,
                a2: v9,
                a3: &ConstStringNode,
                a4: val);
        if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
          GASStringNode::ReleaseNode();
        if ( v10 != 0 && LOBYTE(val[0]) != 0 && LOBYTE(val[0]) != 10 )
        {
          v12 = (unsigned __int8)GASValue::ToBool(result: (tagPOLYTEXTW *)&v22[29]);
          BYTE2(params->pName) = 2 - (v12 != 0);
        }
        GASValue::~GASValue(this: val);
        v6 = (unsigned int)params;
        this = v22;
      }
    }
    if ( *((_BYTE *)this + 482) != 2 && *(_BYTE *)(v6 + 6) != 2 )
    {
      for ( i = 0; i < n; ++i )
      {
        v14 = *(_DWORD *)(*((_DWORD *)this + 49) + 4 * i);
        if ( v14 != 0 && *(char *)(v14 + 118) < 0 )
        {
          if ( (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)v14 + 16))(a1: v14) != 0 )
          {
            ++*(_DWORD *)(v14 + 4);
            v15 = *(_WORD *)(v14 + 164) <= 0;
            params = (GStat::StatValue *)v14;
            if ( !v15 && *(_BYTE *)(v6 + 4) == 0 )
            {
              GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorDH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
                this: *(GStatBag::Iterator **)v6,
                pheapAddr: *(ButtonCode_t *)(*(_DWORD *)v6 + 12),
                newSize: 0);
              *(_BYTE *)(v6 + 4) = 1;
            }
            if ( ((*(unsigned __int8 (__thiscall **)(unsigned int, unsigned int))(*(_DWORD *)v14 + 212))(
                    a1: v14,
                    a2: a3) != 0
               || *(_BYTE *)(v6 + 5) != 0
               && (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)v14 + 220))(a1: v14) != 0)
              && (*(_BYTE *)(v6 + 4) == 0 || *(__int16 *)(v14 + 164) > 0) )
            {
              GArrayBase<GArrayDataDH<GPtr<GFxASCharacter>,GAllocatorDH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>>::PushBack(
                this: *(GMatrix2D **)v6,
                val: (const GMatrix2D *)&params,
                a3: v17,
                a4: v18);
            }
            a3 = v6;
            (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v14 + 228))(a1: v14);
            GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v14);
          }
          this = v22;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6790
// Name: GFx_SpriteGetBounds
// Source: json
//------------------------------------------------------------------------------
char __usercall GFx_SpriteGetBounds@<al>(_TAPE_WMI_OPERATIONS *a1@<esi>, int fn)
{
  int v2; // ecx
  int v3; // eax
  GFxCharacter *v4; // edi
  GASValue *v5; // eax
  struct GFxASCharacter *v6; // eax
  GFxCharacter *v7; // esi
  float *v8; // eax
  int v9; // ecx
  int (__thiscall *v10)(int, int, struct GASObject **, const CMaterialDict::MaterialLookup_t *); // edx
  GASObject *v11; // eax
  _DWORD *v12; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // edx
  int v14; // eax
  struct GASObject *v15; // edi
  CTSQueue<CFunctor *,0,1>::Node_t *v16; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *v17; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *v18; // edx
  struct GASObject *v19; // esi
  int v21; // [esp-10h] [ebp-7Ch]
  int v22; // [esp-10h] [ebp-7Ch]
  int v23; // [esp-10h] [ebp-7Ch]
  const struct GASEnvironment *v24; // [esp-4h] [ebp-70h]
  const CMaterialDict::MaterialLookup_t *v25; // [esp-4h] [ebp-70h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> b; // [esp+8h] [ebp-64h] BYREF
  float v27; // [esp+14h] [ebp-58h]
  struct GASObject *v28; // [esp+18h] [ebp-54h] BYREF
  char v29; // [esp+1Fh] [ebp-4Dh] BYREF
  float v30[6]; // [esp+20h] [ebp-4Ch] BYREF
  GMatrix2D v31; // [esp+38h] [ebp-34h] BYREF
  struct GMatrix2D m; // [esp+50h] [ebp-1Ch] BYREF

  v2 = *(_DWORD *)(fn + 8);
  if ( v2 != 0 )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( v3 != 2 )
      return v3;
    v3 = *(_DWORD *)(fn + 8);
    if ( v3 == 0 )
      return v3;
    v4 = (GFxCharacter *)(v3 - 120);
  }
  else
  {
    v3 = *(_DWORD *)(fn + 24);
    v4 = *(GFxCharacter **)(v3 + 116);
  }
  if ( v4 != nullptr )
  {
    if ( *(int *)(fn + 28) <= 0 )
    {
      v6 = v4;
    }
    else
    {
      v24 = *(const struct GASEnvironment **)(fn + 24);
      v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
      v6 = GASValue::ToASCharacter(this: v5, a2: v24);
    }
    v25 = (const CMaterialDict::MaterialLookup_t *)a1;
    if ( v6 != nullptr )
      v7 = (GFxCharacter *)GASObjectInterface::ToSprite(result: a1);
    else
      v7 = nullptr;
    *(float *)&b.m_pMemory = 0.0;
    *(float *)&b.m_nAllocationCount = 0.0;
    *(float *)&b.m_nGrowSize = 0.0;
    v27 = 0.0;
    GMatrix2D::SetIdentity(this: (float *)&v31);
    if ( v7 != nullptr )
    {
      if ( v7 != v4 )
      {
        GMatrix2D::SetIdentity(this: (float *)&m);
        GFxCharacter::GetWorldMatrix(this: v7, pmat: (CMaterialDict *)&m);
        GMatrix2D::SetInverse(a1: (float *)&v31, (const CMaterialDict::MaterialLookup_t *)&m, a3: v25);
        GMatrix2D::SetIdentity(this: (float *)&m);
        GFxCharacter::GetWorldMatrix(this: v4, pmat: (CMaterialDict *)&m);
        GMatrix2D::Prepend(this: &v31, a2: &m);
      }
      GMatrix2D::SetIdentity(this: v30);
      v8 = (float *)(*(int (__thiscall **)(GFxCharacter *, float *, float *))(*(_DWORD *)v4 + 52))(
                      a1: v4,
                      a2: &m.M_[0][2],
                      a3: v30);
      GMatrix2D::EncloseTransform(this: (float *)&v31, a2: (float *)&b, a3: v8);
    }
    v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(fn + 24) + 120) + 656);
    v10 = *(int (__thiscall **)(int, int, struct GASObject **, const CMaterialDict::MaterialLookup_t *))(*(_DWORD *)v9 + 40);
    v28 = (struct GASObject *)323;
    v11 = (GASObject *)v10(a1: v9, a2: 52, a3: &v28, a4: v25);
    if ( v11 != nullptr )
      v28 = GASObject::GASObject(this: v11, a2: *(struct GASEnvironment **)(fn + 24));
    else
      v28 = nullptr;
    v12 = *(_DWORD **)(fn + 24);
    pNext = v28[2].pNode[5].pNext;
    v14 = v12[30];
    v12 += 30;
    v15 = v28 + 2;
    LOBYTE(m.M_[0][2]) = 3;
    v29 = 0;
    *(double *)&m.M_[1][0] = *(float *)&b.m_pMemory / 20.0;
    ((void (__thiscall *)(struct GASObject *, _DWORD *, int, float *))pNext)(
      a1: &v28[2],
      a2: v12,
      a3: v14 + 532,
      a4: &m.M_[0][2]);
    GASValue::~GASValue(this: (GASValue *)&m.M_[0][2]);
    v16 = v15->pNode[5].pNext;
    v21 = *v12 + 536;
    LOBYTE(m.M_[0][2]) = 3;
    v29 = 0;
    *(double *)&m.M_[1][0] = *(float *)&b.m_nGrowSize / 20.0;
    ((void (__thiscall *)(struct GASObject *, _DWORD *, int, float *, char *))v16)(
      a1: v15,
      a2: v12,
      a3: v21,
      a4: &m.M_[0][2],
      a5: &v29);
    GASValue::~GASValue(this: (GASValue *)&m.M_[0][2]);
    v17 = v15->pNode[5].pNext;
    v22 = *v12 + 540;
    LOBYTE(m.M_[0][2]) = 3;
    v29 = 0;
    *(double *)&m.M_[1][0] = *(float *)&b.m_nAllocationCount / 20.0;
    ((void (__thiscall *)(struct GASObject *, _DWORD *, int, float *, char *))v17)(
      a1: v15,
      a2: v12,
      a3: v22,
      a4: &m.M_[0][2],
      a5: &v29);
    GASValue::~GASValue(this: (GASValue *)&m.M_[0][2]);
    v18 = v15->pNode[5].pNext;
    v23 = *v12 + 544;
    LOBYTE(m.M_[0][2]) = 3;
    v29 = 0;
    *(double *)&m.M_[1][0] = v27 / 20.0;
    ((void (__thiscall *)(struct GASObject *, _DWORD *, int, float *, char *))v18)(
      a1: v15,
      a2: v12,
      a3: v23,
      a4: &m.M_[0][2],
      a5: &v29);
    GASValue::~GASValue(this: (GASValue *)&m.M_[0][2]);
    v19 = v28;
    GASValue::SetAsObject(this: *(GASValue **)(fn + 4), a2: v28);
    LOBYTE(v3) = GRefCountBaseGC<323>::Release(a1: (int)v19, a2: (int)v15);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100B69E0
// Name: GFx_SpriteGetRect
// Source: json
//------------------------------------------------------------------------------
char __usercall GFx_SpriteGetRect@<al>(_TAPE_WMI_OPERATIONS *a1@<esi>, int fn)
{
  int v2; // ecx
  int v3; // eax
  GFxCharacter *v4; // edi
  GASValue *v5; // eax
  struct GFxASCharacter *v6; // eax
  GFxCharacter *v7; // esi
  float *v8; // eax
  int v9; // ecx
  int (__thiscall *v10)(int, int, struct GASObject **, const CMaterialDict::MaterialLookup_t *); // edx
  GASObject *v11; // eax
  _DWORD *v12; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // edx
  int v14; // eax
  struct GASObject *v15; // edi
  CTSQueue<CFunctor *,0,1>::Node_t *v16; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *v17; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *v18; // edx
  struct GASObject *v19; // esi
  int v21; // [esp-10h] [ebp-7Ch]
  int v22; // [esp-10h] [ebp-7Ch]
  int v23; // [esp-10h] [ebp-7Ch]
  const struct GASEnvironment *v24; // [esp-4h] [ebp-70h]
  const CMaterialDict::MaterialLookup_t *v25; // [esp-4h] [ebp-70h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> b; // [esp+8h] [ebp-64h] BYREF
  float v27; // [esp+14h] [ebp-58h]
  struct GASObject *v28; // [esp+18h] [ebp-54h] BYREF
  char v29; // [esp+1Fh] [ebp-4Dh] BYREF
  float v30[6]; // [esp+20h] [ebp-4Ch] BYREF
  GMatrix2D v31; // [esp+38h] [ebp-34h] BYREF
  struct GMatrix2D m; // [esp+50h] [ebp-1Ch] BYREF

  v2 = *(_DWORD *)(fn + 8);
  if ( v2 != 0 )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( v3 != 2 )
      return v3;
    v3 = *(_DWORD *)(fn + 8);
    if ( v3 == 0 )
      return v3;
    v4 = (GFxCharacter *)(v3 - 120);
  }
  else
  {
    v3 = *(_DWORD *)(fn + 24);
    v4 = *(GFxCharacter **)(v3 + 116);
  }
  if ( v4 != nullptr )
  {
    if ( *(int *)(fn + 28) <= 0 )
    {
      v6 = v4;
    }
    else
    {
      v24 = *(const struct GASEnvironment **)(fn + 24);
      v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
      v6 = GASValue::ToASCharacter(this: v5, a2: v24);
    }
    v25 = (const CMaterialDict::MaterialLookup_t *)a1;
    if ( v6 != nullptr )
      v7 = (GFxCharacter *)GASObjectInterface::ToSprite(result: a1);
    else
      v7 = nullptr;
    *(float *)&b.m_pMemory = 0.0;
    *(float *)&b.m_nAllocationCount = 0.0;
    *(float *)&b.m_nGrowSize = 0.0;
    v27 = 0.0;
    GMatrix2D::SetIdentity(this: (float *)&v31);
    if ( v7 != nullptr )
    {
      if ( v7 != v4 )
      {
        GMatrix2D::SetIdentity(this: (float *)&m);
        GFxCharacter::GetWorldMatrix(this: v7, pmat: (CMaterialDict *)&m);
        GMatrix2D::SetInverse(a1: (float *)&v31, (const CMaterialDict::MaterialLookup_t *)&m, a3: v25);
        GMatrix2D::SetIdentity(this: (float *)&m);
        GFxCharacter::GetWorldMatrix(this: v4, pmat: (CMaterialDict *)&m);
        GMatrix2D::Prepend(this: &v31, a2: &m);
      }
      GMatrix2D::SetIdentity(this: v30);
      v8 = (float *)(*(int (__thiscall **)(GFxCharacter *, float *, float *))(*(_DWORD *)v4 + 64))(
                      a1: v4,
                      a2: &m.M_[0][2],
                      a3: v30);
      GMatrix2D::EncloseTransform(this: (float *)&v31, a2: (float *)&b, a3: v8);
    }
    v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(fn + 24) + 120) + 656);
    v10 = *(int (__thiscall **)(int, int, struct GASObject **, const CMaterialDict::MaterialLookup_t *))(*(_DWORD *)v9 + 40);
    v28 = (struct GASObject *)323;
    v11 = (GASObject *)v10(a1: v9, a2: 52, a3: &v28, a4: v25);
    if ( v11 != nullptr )
      v28 = GASObject::GASObject(this: v11, a2: *(struct GASEnvironment **)(fn + 24));
    else
      v28 = nullptr;
    v12 = *(_DWORD **)(fn + 24);
    pNext = v28[2].pNode[5].pNext;
    v14 = v12[30];
    v12 += 30;
    v15 = v28 + 2;
    LOBYTE(m.M_[0][2]) = 3;
    v29 = 0;
    *(double *)&m.M_[1][0] = *(float *)&b.m_pMemory / 20.0;
    ((void (__thiscall *)(struct GASObject *, _DWORD *, int, float *))pNext)(
      a1: &v28[2],
      a2: v12,
      a3: v14 + 532,
      a4: &m.M_[0][2]);
    GASValue::~GASValue(this: (GASValue *)&m.M_[0][2]);
    v16 = v15->pNode[5].pNext;
    v21 = *v12 + 536;
    LOBYTE(m.M_[0][2]) = 3;
    v29 = 0;
    *(double *)&m.M_[1][0] = *(float *)&b.m_nGrowSize / 20.0;
    ((void (__thiscall *)(struct GASObject *, _DWORD *, int, float *, char *))v16)(
      a1: v15,
      a2: v12,
      a3: v21,
      a4: &m.M_[0][2],
      a5: &v29);
    GASValue::~GASValue(this: (GASValue *)&m.M_[0][2]);
    v17 = v15->pNode[5].pNext;
    v22 = *v12 + 540;
    LOBYTE(m.M_[0][2]) = 3;
    v29 = 0;
    *(double *)&m.M_[1][0] = *(float *)&b.m_nAllocationCount / 20.0;
    ((void (__thiscall *)(struct GASObject *, _DWORD *, int, float *, char *))v17)(
      a1: v15,
      a2: v12,
      a3: v22,
      a4: &m.M_[0][2],
      a5: &v29);
    GASValue::~GASValue(this: (GASValue *)&m.M_[0][2]);
    v18 = v15->pNode[5].pNext;
    v23 = *v12 + 544;
    LOBYTE(m.M_[0][2]) = 3;
    v29 = 0;
    *(double *)&m.M_[1][0] = v27 / 20.0;
    ((void (__thiscall *)(struct GASObject *, _DWORD *, int, float *, char *))v18)(
      a1: v15,
      a2: v12,
      a3: v23,
      a4: &m.M_[0][2],
      a5: &v29);
    GASValue::~GASValue(this: (GASValue *)&m.M_[0][2]);
    v19 = v28;
    GASValue::SetAsObject(this: *(GASValue **)(fn + 4), a2: v28);
    LOBYTE(v3) = GRefCountBaseGC<323>::Release(a1: (int)v19, a2: (int)v15);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100B6C30
// Name: GFx_SpriteGetTextSnapshot
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_SpriteGetTextSnapshot(_CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // edi
  int v2; // ecx
  GPtr<GFxAmpViewStats> *v3; // ebx
  int v4; // eax
  int v5; // ecx
  int (__thiscall *v6)(int, int, _CONNECTDLGSTRUCTW *); // eax
  GASTextSnapshotObject *v7; // eax
  struct GASObject *v8; // esi

  cbStructure = fn.cbStructure;
  v2 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v2 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2) != 2 )
      return;
    v4 = *(_DWORD *)(cbStructure + 8);
    if ( v4 == 0 )
      return;
    v3 = (GPtr<GFxAmpViewStats> *)(v4 - 120);
  }
  else
  {
    v3 = *(GPtr<GFxAmpViewStats> **)(*(_DWORD *)(fn.cbStructure + 24) + 116);
  }
  if ( v3 != nullptr )
  {
    v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 656);
    v6 = *(int (__thiscall **)(int, int, _CONNECTDLGSTRUCTW *))(*(_DWORD *)v5 + 40);
    fn.cbStructure = 323;
    v7 = (GASTextSnapshotObject *)v6(a1: v5, a2: 72, a3: &fn);
    if ( v7 != nullptr )
      v8 = (struct GASObject *)GASTextSnapshotObject::GASTextSnapshotObject(
                                 this: v7,
                                 a2: *(struct GASEnvironment **)(cbStructure + 24));
    else
      v8 = nullptr;
    GASTextSnapshotObject::Process(result: v3);
    GASValue::SetAsObject(this: *(GASValue **)(cbStructure + 4), a2: v8);
    if ( v8 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v8, a2: cbStructure);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6CC0
// Name: GFx_SpriteBeginBitmapFill
// Source: json
//------------------------------------------------------------------------------
char __usercall GFx_SpriteBeginBitmapFill@<al>(int a1@<ebx>, char *a2@<edi>, int fn)
{
  int v3; // ecx
  struct GASObject *v4; // eax
  GASValue *v5; // eax
  int v6; // ebx
  GASValue *v7; // eax
  struct GASObject *v8; // eax
  float *v9; // eax
  int v10; // eax
  const struct GASEnvironment *v12; // [esp-Ch] [ebp-50h]
  const struct GASEnvironment *v13; // [esp-8h] [ebp-4Ch]
  char *v14; // [esp-8h] [ebp-4Ch]
  tagPOLYTEXTW *v15; // [esp-8h] [ebp-4Ch]
  tagPOLYTEXTW *v16; // [esp-8h] [ebp-4Ch]
  unsigned int v18; // [esp+4h] [ebp-40h]
  GFxValue *sequence; // [esp+8h] [ebp-3Ch]
  unsigned __int8 repeat; // [esp+Fh] [ebp-35h]
  _BYTE penv[24]; // [esp+10h] [ebp-34h] BYREF
  float v22[6]; // [esp+28h] [ebp-1Ch] BYREF

  v3 = *(_DWORD *)(fn + 8);
  if ( v3 != 0 )
  {
    v4 = (struct GASObject *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    if ( v4 != (struct GASObject *)2 )
      return (char)v4;
    v4 = *(struct GASObject **)(fn + 8);
    if ( v4 == nullptr )
      return (char)v4;
    v4 -= 15;
    sequence = (GFxValue *)v4;
  }
  else
  {
    v4 = *(struct GASObject **)(fn + 24);
    sequence = (GFxValue *)v4[14].sequence;
  }
  if ( sequence != nullptr && *(int *)(fn + 28) > 0 )
  {
    v13 = *(const struct GASEnvironment **)(fn + 24);
    v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
    v4 = GASValue::ToObject(this: v5, a2: v13);
    v6 = (int)v4;
    if ( v4 != nullptr )
    {
      v4[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v4[1].pNode->pNext + 1) & 0x8FFFFFFF);
      if ( ((int (__thiscall *)(struct GASObject *))v4[2].pNode[1].pNext)(a1: &v4[2]) != 26 )
        goto LABEL_23;
      v18 = *(_DWORD *)(v6 + 52);
      if ( v18 == 0 )
        goto LABEL_23;
      GMatrix2D::SetIdentity(this: v22);
      if ( *(int *)(fn + 28) > 1 )
      {
        v14 = a2;
        v12 = *(const struct GASEnvironment **)(fn + 24);
        v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
        v8 = GASValue::ToObject(this: v7, a2: v12);
        if ( v8 != nullptr && ((int (__thiscall *)(struct GASObject *))v8[2].pNode[1].pNext)(a1: &v8[2]) == 15 )
        {
          GASMatrixObject::GetMatrix(penv, v: *(GMemAddressStub **)(fn + 24), a3: a2, a4: a1);
          v22[0] = *v9;
          v22[1] = v9[1];
          v22[2] = v9[2];
          v22[3] = v9[3];
          v22[4] = v9[4];
          v22[5] = v9[5];
        }
        a2 = v14;
        if ( *(int *)(fn + 28) > 2 )
        {
          v15 = *(tagPOLYTEXTW **)(fn + 24);
          GASFnCall::Arg(this: (GASFnCall *)fn, a2: 2);
          repeat = (unsigned __int8)GASValue::ToBool(result: v15);
          if ( *(int *)(fn + 28) > 3 )
          {
            v16 = *(tagPOLYTEXTW **)(fn + 24);
            GASFnCall::Arg(this: (GASFnCall *)fn, a2: 3);
            if ( (unsigned __int8)GASValue::ToBool(result: v16) != 0 )
            {
              v10 = (repeat == 0) + 64;
LABEL_22:
              GFxSprite::BeginBitmapFill(
                this: sequence,
                (Vector *)a2,
                fillType: COERCE_LONG_DOUBLE(__PAIR64__(v18, v10)),
                pimageRes_4: COERCE_FLOAT(v22));
LABEL_23:
              LOBYTE(v4) = GRefCountBaseGC<323>::Release(a1: v6, (int)a2);
              return (char)v4;
            }
          }
          if ( repeat == 0 )
          {
            v10 = 67;
            goto LABEL_22;
          }
        }
      }
      v10 = 66;
      goto LABEL_22;
    }
  }
  return (char)v4;
}

//------------------------------------------------------------------------------
// Address: 0x100B6E60
// Name: protected: void GASMovieClipObject::SetMemberCommon(class GASStringContext __near *,class GASString const __near &,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASMovieClipObject::SetMemberCommon(
        GFxValue::ObjectInterface *this@<ecx>,
        _IMAGE_SYMBOL_EX *psc,
        struct GASString *name,
        tagWNDCLASSW *val,
        bool size)
{
  unsigned int i; // edi
  _DWORD *v6; // eax
  GRefCountNTSImpl *v7; // esi
  _BYTE *v8; // eax
  unsigned __int8 (__thiscall *v9)(unsigned int, unsigned int, struct GASString *, GASValue *); // edx
  __int16 ButtonEventNameMask; // ax
  _BYTE **v11; // eax
  int v12; // ecx
  int v13; // eax
  _DWORD *v14; // ecx
  struct GASEnvironment *v16; // eax
  const struct GASEnvironment *v17; // eax
  struct GASObject *v18; // eax
  int v19; // ebx
  signed int v20; // eax
  GRefCountNTSImpl_vtbl *v21; // eax
  struct GASEnvironment *v22; // eax
  _DWORD *v23; // [esp+10h] [ebp-6Ch] BYREF
  GASValue v24[4]; // [esp+20h] [ebp-5Ch] BYREF
  GASValue *v25; // [esp+30h] [ebp-4Ch]
  unsigned int sizea; // [esp+34h] [ebp-48h]
  GFxTestStream result; // [esp+38h] [ebp-44h] BYREF

  i = (unsigned int)this;
  sizea = (unsigned int)psc;
  v6 = *((_DWORD **)this + 13);
  v7 = nullptr;
  v25 = (GASValue *)val;
  if ( v6 != nullptr )
  {
    if ( v6[1] != 0 )
    {
      v7 = (GRefCountNTSImpl *)v6[1];
      if ( v7 != nullptr )
      {
        ++v7->RefCount;
        ++v7->RefCount;
        GRefCountNTSImpl::Release(this: v7);
        if ( (GRefCountNTSImpl *)((int (__thiscall *)(GRefCountNTSImpl *, _DWORD))v7->__vftable[26].dtr_GRefCountImplCore)(
                                   a1: v7,
                                   a2: 0) == v7 )
          goto LABEL_12;
      }
    }
    else
    {
      if ( (*v6)-- == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
      *(_DWORD *)(i + 52) = 0;
    }
  }
  if ( *(_DWORD *)(*(_DWORD *)name + 16) > 2u )
  {
    v8 = **(_BYTE ***)name;
    if ( *v8 == 111 && v8[1] == 110 )
    {
      v9 = *(unsigned __int8 (__thiscall **)(unsigned int, unsigned int, struct GASString *, GASValue *))(*(_DWORD *)(i + 16) + 44);
      LOBYTE(v24[0]) = 0;
      if ( v9(a1: i + 16, a2: sizea, a3: name, a4: v24) == 0 )
      {
        ButtonEventNameMask = GASMovieClipObject::GetButtonEventNameMask(a1: (struct GASStringContext *)sizea, a2: name);
        if ( ButtonEventNameMask != 0 )
          *(_WORD *)(i + 56) |= ButtonEventNameMask;
      }
      GASValue::~GASValue(this: v24);
    }
  }
LABEL_12:
  if ( v7 != nullptr )
  {
    v11 = *(_BYTE ***)name;
    if ( *(int *)(*(_DWORD *)name + 12) < 0 )
    {
      v12 = *(_DWORD *)sizea;
      if ( v11 == *(_BYTE ***)(*(_DWORD *)sizea + 612) )
      {
        v13 = ((int (__thiscall *)(GRefCountNTSImpl *))v7->__vftable[28].dtr_GRefCountImplCore)(a1: v7);
        v23 = v14;
        GASValue::ToStringImpl(a1: v25, a2: &v23, a3: v13, a4: -1, a5: 0);
        GFxSprite::SetRendererString(this: (GFxFontLib::FontResult *)v7, str: v23);
      }
      else if ( v11 == *(_BYTE ***)(v12 + 616) )
      {
        v16 = (struct GASEnvironment *)((int (__thiscall *)(GRefCountNTSImpl *))v7->__vftable[28].dtr_GRefCountImplCore)(a1: v7);
        *(float *)&v25 = GASValue::ToNumber(this: v25, a2: v16);
        GFxSprite::SetRendererFloat(this: (GFxSprite *)v7, a2: (volatile int)v25);
      }
      else if ( v11 == *(_BYTE ***)(v12 + 620) )
      {
        v17 = (const struct GASEnvironment *)((int (__thiscall *)(GRefCountNTSImpl *))v7->__vftable[28].dtr_GRefCountImplCore)(a1: v7);
        v18 = GASValue::ToObject(this: v25, a2: v17);
        v19 = (int)v18;
        if ( v18 != nullptr )
        {
          v18[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v18[1].pNode->pNext + 1) & 0x8FFFFFFF);
          if ( ((int (__thiscall *)(struct GASObject *))v18[2].pNode[1].pNext)(a1: &v18[2]) == 7 )
          {
            v20 = *(_DWORD *)(v19 + 60);
            sizea = 16;
            if ( v20 <= 16 )
              sizea = v20;
            for ( i = 0; i < sizea; ++i )
            {
              v21 = v7->__vftable;
              v25 = *(GASValue **)(*(_DWORD *)(v19 + 56) + 4 * i);
              v22 = (struct GASEnvironment *)((int (__thiscall *)(GRefCountNTSImpl *))v21[28].dtr_GRefCountImplCore)(a1: v7);
              *((float *)&result.__vftable + i) = GASValue::ToNumber(this: v25, a2: v22);
            }
            GFxSprite::SetRendererMatrix(this: v7, &result, count: sizea);
          }
          GRefCountBaseGC<323>::Release(a1: v19, a2: i);
        }
      }
    }
    GRefCountNTSImpl::Release(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7060
// Name: public: virtual bool GASMovieClipObject::SetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASMovieClipObject::SetMemberRaw(
        GASObject *this,
        _IMAGE_SYMBOL_EX *psc,
        const struct GASString *name,
        tagWNDCLASSW *val,
        const struct GASPropFlags *a5)
{
  bool v7; // [esp+0h] [ebp-Ch]

  GASMovieClipObject::SetMemberCommon(this: (GFxValue::ObjectInterface *)this - 4, psc, name, val, size: v7);
  return GASObject::SetMemberRaw(this, a2: (struct GASStringContext *)psc, a3: name, a4: (GASValue *)val, a5);
}

//------------------------------------------------------------------------------
// Address: 0x100B70A0
// Name: public: virtual bool GASMovieClipObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASMovieClipObject::SetMember(
        GFxValue::ObjectInterface *this@<ecx>,
        _IMAGE_SYMBOL_EX *penv,
        _IMAGE_SYMBOL_EX *name,
        tagWNDCLASSW *val,
        const GFxValue *flags,
        unsigned int flags_4,
        bool flags_8)
{
  bool v8; // [esp+0h] [ebp-Ch]

  GASMovieClipObject::SetMemberCommon(this: this - 4, psc: penv + 6, (struct GASString *)name, val, size: v8);
  GASObject::SetMember((CTSQueue<CFunctor *,0,1> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100B74A0
// Name: public: void GFxSprite::AddActiveSound(class GSoundChannel __near *,class GASSoundObject __near *,class GFxSoundResource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::AddActiveSound(GFxValue *this, IShaderDevice *a2, int a3, int a4)
{
  _DWORD *v5; // eax
  int v6; // ecx
  unsigned int v7; // eax
  int (__thiscall *v8)(struct CMatNullRenderContext *); // ecx
  int (__thiscall *v9)(struct CMatNullRenderContext *); // edx
  int v10; // ecx
  int (__thiscall *v11)(struct CMatNullRenderContext *); // edi
  int (__thiscall *v12)(struct CMatNullRenderContext *); // eax
  int (__thiscall *v13)(struct CMatNullRenderContext *); // edi
  IShaderAPI *v14; // ecx
  CMatNullRenderContext *v15; // esi
  void *m_pCurrentProxyData; // edx
  CMatNullRenderContext_vtbl *v17; // eax
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v18; // esi
  int v19; // eax
  const MorphWeight_t *v20; // [esp+0h] [ebp-18h]
  int v21; // [esp+Ch] [ebp-Ch] BYREF
  int v22; // [esp+10h] [ebp-8h] BYREF
  int (__thiscall *v23)(struct CMatNullRenderContext *); // [esp+14h] [ebp-4h]

  if ( *((_DWORD *)this + 114) == 0 )
  {
    v22 = 326;
    v5 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40, a3: &v22);
    if ( v5 != nullptr )
    {
      v5[3] = 0;
      v5[4] = 0;
      v5[5] = 0;
      v5[6] = 0;
      v5[7] = 0;
      v5[8] = 0;
      v5[9] = 0;
      *v5 = 100;
      v5[2] = 0;
    }
    else
    {
      v5 = nullptr;
    }
    *((_DWORD *)this + 114) = v5;
  }
  v6 = *((_DWORD *)this + 114);
  v7 = 0;
  if ( *(_DWORD *)(v6 + 16) == 0 )
    goto LABEL_14;
  v8 = *(int (__thiscall **)(struct CMatNullRenderContext *))(v6 + 12);
  v23 = v8;
  while ( *(IShaderDevice **)(*(_DWORD *)v8 + 8) != a2 )
  {
    ++v7;
    v8 = (int (__thiscall *)(struct CMatNullRenderContext *))((char *)v8 + 4);
    if ( v7 >= *(_DWORD *)(*((_DWORD *)this + 114) + 16) )
      goto LABEL_14;
  }
  v9 = v23;
  v10 = *((_DWORD *)v23 + v7);
  if ( v10 != 0 )
    ++*(_DWORD *)(v10 + 4);
  v11 = *((int (__thiscall **)(struct CMatNullRenderContext *))v9 + v7);
  if ( v11 == nullptr )
  {
LABEL_14:
    v21 = 326;
    v12 = (int (__thiscall *)(struct CMatNullRenderContext *))GMemory::pGlobalHeap->Alloc_2(
                                                                this: GMemory::pGlobalHeap,
                                                                a2: 20,
                                                                a3: &v21);
    if ( v12 != nullptr )
    {
      *(_DWORD *)v12 = &GRefCountImplCore::`vftable';
      *((_DWORD *)v12 + 1) = 1;
      *(_DWORD *)v12 = &GFxSprite::ActiveSoundItem::`vftable';
      *((_DWORD *)v12 + 2) = 0;
      *((_DWORD *)v12 + 3) = 0;
      *((_DWORD *)v12 + 4) = 0;
      v13 = v12;
    }
    else
    {
      v13 = nullptr;
    }
    v23 = v13;
    if ( a2 != nullptr )
      GRefCountImpl::AddRef(this: a2);
    v14 = *((IShaderAPI **)v13 + 2);
    if ( v14 != nullptr )
      GRefCountImpl::Release(this: v14);
    *((_DWORD *)v13 + 2) = a2;
    v15 = *((CMatNullRenderContext **)this + 114);
    m_pCurrentProxyData = v15->m_pCurrentProxyData;
    v15 = (CMatNullRenderContext *)((char *)v15 + 12);
    GArrayDataBase<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: v15,
      pheapAddr: (IMorph *)v15,
      newSize: (unsigned int)m_pCurrentProxyData + 1,
      a4: v20);
    v17 = (CMatNullRenderContext_vtbl *)((char *)v15->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
                                       + 4
                                       * (int)v15->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable
                                       - 4);
    if ( (CMatNullRenderContext_vtbl *)((char *)v15->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
                                      + 4
                                      * (int)v15->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable) != (CMatNullRenderContext_vtbl *)4 )
    {
      if ( v13 != nullptr )
        ++*((_DWORD *)v13 + 1);
      v17->AddRef = v13;
    }
    v18 = *((const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **)this
          + 47);
    v19 = GFxSprite::CheckAdvanceStatus((GFxSprite *)this, a2: (*(_DWORD *)(this + 10) & 0x80000) != 0);
    if ( v19 == -1 )
    {
      GFxASCharacter::RemoveFromOptimizedPlaylist((CMatQueuedMesh **)this, result: v18);
    }
    else if ( v19 == 1 )
    {
      GFxASCharacter::AddToOptimizedPlayList((int)this, result: v18);
    }
    v11 = v23;
  }
  *((_DWORD *)v11 + 3) = a3;
  *((_DWORD *)v11 + 4) = a4;
  if ( a4 != 0 )
  {
    ++*(_DWORD *)(a4 + 28);
    GRefCountImpl::AddRef(this: *((IShaderDevice **)v11 + 4));
  }
  GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v11);
}

//------------------------------------------------------------------------------
// Address: 0x100B7640
// Name: public: void GFxSprite::SetStreamingSound(class GSoundChannel __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxSprite::SetStreamingSound(GFxValue *this, IShaderDevice *a2)
{
  _DWORD *v3; // eax
  int v4; // ecx
  int v5; // ebx
  IShaderAPI *v6; // ecx
  int *v7; // ebx
  int v8; // edi
  double result; // st7
  float v10; // [esp+8h] [ebp-14h]
  int v11; // [esp+18h] [ebp-4h] BYREF

  if ( a2 != nullptr || *((_DWORD *)this + 114) != 0 )
  {
    if ( *((_DWORD *)this + 114) == 0 )
    {
      v11 = 326;
      v3 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40, a3: &v11);
      if ( v3 != nullptr )
      {
        v3[3] = 0;
        v3[4] = 0;
        v3[5] = 0;
        v3[6] = 0;
        v3[7] = 0;
        v3[8] = 0;
        v3[9] = 0;
        *v3 = 100;
        v3[2] = 0;
      }
      else
      {
        v3 = nullptr;
      }
      *((_DWORD *)this + 114) = v3;
    }
    v4 = *(_DWORD *)(*((_DWORD *)this + 114) + 36);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    v5 = *((_DWORD *)this + 114);
    if ( a2 != nullptr )
      GRefCountImpl::AddRef(this: a2);
    v6 = *(IShaderAPI **)(v5 + 36);
    if ( v6 != nullptr )
      GRefCountImpl::Release(this: v6);
    *(_DWORD *)(v5 + 36) = a2;
    v7 = *(int **)(*((_DWORD *)this + 114) + 36);
    if ( v7 != nullptr )
    {
      v8 = *v7;
      result = GFxSprite::GetRealSoundVolume(this, a2: (_TAPE_WMI_OPERATIONS *)this);
      v10 = result;
      (*(void (__thiscall **)(int *, _DWORD))(v8 + 40))(a1: v7, a2: LODWORD(v10));
      GFxSprite::AddActiveSound(this, a2, a3: 0, a4: 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B7720
// Name: public: void GFxSprite::SetSoundVolume(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetSoundVolume(GFxValue *this, long double volume)
{
  _DWORD *v3; // eax
  int v4; // [esp+8h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 114) == 0 )
  {
    v4 = 326;
    v3 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40, a3: &v4);
    if ( v3 != nullptr )
    {
      v3[3] = 0;
      v3[4] = 0;
      v3[5] = 0;
      v3[6] = 0;
      v3[7] = 0;
      v3[8] = 0;
      v3[9] = 0;
      *v3 = 100;
      v3[2] = 0;
    }
    else
    {
      v3 = nullptr;
    }
    *((_DWORD *)this + 114) = v3;
  }
  *(long double *)*((_DWORD *)this + 114) = volume;
  GFxSprite::UpdateActiveSoundVolume((GFxFontLib *)this, a2: (_TAPE_WMI_OPERATIONS *)this, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100B77A0
// Name: public: void GFxSprite::SetSoundPan(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetSoundPan(int this, const GFxZlibSupportBase *result)
{
  _DWORD *v3; // eax
  int v4; // [esp+8h] [ebp-4h] BYREF

  if ( *(_DWORD *)(this + 456) == 0 )
  {
    v4 = 326;
    v3 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40, a3: &v4);
    if ( v3 != nullptr )
    {
      v3[3] = 0;
      v3[4] = 0;
      v3[5] = 0;
      v3[6] = 0;
      v3[7] = 0;
      v3[8] = 0;
      v3[9] = 0;
      *v3 = 100;
      v3[2] = 0;
    }
    else
    {
      v3 = nullptr;
    }
    *(_DWORD *)(this + 456) = v3;
  }
  *(_DWORD *)(*(_DWORD *)(this + 456) + 8) = result;
  GFxSprite::UpdateActiveSoundPan((GFxFontLib *)this, a2: (_TAPE_WMI_OPERATIONS *)this, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100B7820
// Name: public: void GFxSprite::CheckActiveSounds(void)
// Source: json
//------------------------------------------------------------------------------
GFxSprite __usercall GFxSprite::CheckActiveSounds@<eax>(GFxFontLib *this@<ecx>, const MorphWeight_t *a2@<edi>)
{
  GFxSprite result; // eax
  GFxASUserData_vtbl *v3; // esi
  int v4; // edi
  _DWORD *v5; // ecx
  unsigned int v6; // ebx
  int v7; // eax
  unsigned __int8 *v8; // edi
  int v9; // esi
  int v10; // ecx
  unsigned __int8 (__thiscall *v11)(int, const MorphWeight_t *); // edx
  GASSoundObject *v12; // ecx
  unsigned int v13; // esi
  int v14; // ebx
  GRefCountNTSImpl **v15; // edi
  _DWORD *v16; // esi
  unsigned int v17; // esi
  void *v18; // esi
  CMatQueuedMesh **v19; // edi
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v20; // esi
  int v21; // eax
  unsigned int v22; // eax
  int v23; // edx
  GFxSprite v24; // eax
  GFxASUserData_vtbl *v25; // ecx
  unsigned int v26; // esi
  CMatNullRenderContext *p_pData; // edi
  _DWORD *pData; // eax
  GRefCountNTSImpl **j; // esi
  int v30; // ebx
  GRefCountNTSImpl **v31; // esi
  unsigned int k; // edi
  const MorphWeight_t *v33; // [esp-8h] [ebp-38h]
  int v34; // [esp+4h] [ebp-2Ch] BYREF
  unsigned int v35; // [esp+8h] [ebp-28h]
  int v36; // [esp+Ch] [ebp-24h]
  int v37; // [esp+10h] [ebp-20h] BYREF
  unsigned int v38; // [esp+14h] [ebp-1Ch]
  unsigned int v39; // [esp+18h] [ebp-18h]
  GRefCountNTSImpl *v40; // [esp+1Ch] [ebp-14h]
  bool v41[4]; // [esp+20h] [ebp-10h]
  unsigned __int8 *dst; // [esp+24h] [ebp-Ch]
  GFxSprite *v43; // [esp+28h] [ebp-8h]
  unsigned int i; // [esp+2Ch] [ebp-4h]

  result = *((GFxSprite *)this + 114);
  v3 = nullptr;
  v43 = (GFxSprite *)this;
  if ( result != nullptr )
  {
    v33 = a2;
    v34 = 0;
    v35 = 0;
    v36 = 0;
    if ( result[1].__vftable != nullptr )
    {
      do
      {
        v4 = (int)result->pData + 4 * (_DWORD)v3;
        GArrayDataBase<GPtr<GFxSprite::ActiveSoundItem>,GAllocatorGH<GPtr<GFxSprite::ActiveSoundItem>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
          this: (CVertexBuilder *)&v34,
          a2: (ButtonCode_t)&v34,
          a3: v35 + 1);
        v5 = (_DWORD *)(v34 + 4 * v35 - 4);
        if ( v34 + 4 * v35 != 4 )
        {
          if ( *(_DWORD *)v4 != 0 )
            ++*(_DWORD *)(*(_DWORD *)v4 + 4);
          *v5 = *(_DWORD *)v4;
        }
        result = v43[114];
        v3 = (GFxASUserData_vtbl *)((char *)v3 + 1);
      }
      while ( v3 < result[1].__vftable );
    }
    v6 = 0;
    v37 = 0;
    v38 = 0;
    v39 = 0;
    i = 0;
    while ( i < v35 )
    {
      v7 = *(_DWORD *)(v34 + 4 * i);
      v8 = (unsigned __int8 *)(v34 + 4 * i);
      dst = v8;
      if ( v7 != 0 )
      {
        ++*(_DWORD *)(v7 + 4);
        v6 = v38;
      }
      v9 = *(_DWORD *)v8;
      v10 = *(_DWORD *)(*(_DWORD *)v8 + 8);
      v11 = *(unsigned __int8 (__thiscall **)(int, const MorphWeight_t *))(*(_DWORD *)v10 + 20);
      v40 = *(GRefCountNTSImpl **)v8;
      if ( v11(a1: v10, a2: v33) != 0 )
      {
        ++i;
      }
      else
      {
        v12 = *(GASSoundObject **)(v9 + 12);
        if ( v12 != nullptr )
          GASSoundObject::ExecuteOnSoundComplete(this: v12);
        v13 = v6 + 1;
        if ( v6 + 1 >= v6 )
        {
          if ( v13 >= v39 )
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: (CVertexBuilder *)&v37,
              pheapAddr: (ButtonCode_t)&v37,
              newCapacity: v13 + (v13 >> 2));
        }
        else
        {
          v14 = -1;
          v15 = (GRefCountNTSImpl **)(v37 + 4 * (v13 - 1) - 4);
          do
          {
            if ( *v15 != nullptr )
              GRefCountNTSImpl::Release(this: *v15);
            --v15;
            --v14;
          }
          while ( v14 != 0 );
          if ( v13 < v39 >> 1 )
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: (CVertexBuilder *)&v37,
              pheapAddr: (ButtonCode_t)&v37,
              newCapacity: v13);
          v8 = dst;
        }
        v38 = v13;
        v16 = (_DWORD *)(v37 + 4 * v13 - 4);
        if ( v16 != nullptr )
        {
          if ( *(_DWORD *)v8 != 0 )
            ++*(_DWORD *)(*(_DWORD *)v8 + 4);
          *v16 = *(_DWORD *)v8;
        }
        v17 = v35;
        if ( v35 == 1 )
        {
          v18 = (void *)v34;
          if ( *(_DWORD *)v34 != 0 )
            GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)v34);
          if ( (v36 & 0xFFFFFFFE) != 0 )
          {
            if ( v18 != nullptr )
            {
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v18);
              v34 = 0;
            }
            v36 = 0;
          }
          v35 = 0;
        }
        else
        {
          if ( *(_DWORD *)v8 != 0 )
            GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)v8);
          memmove(dst: v8, src: v8 + 4, count: 4 * (v17 - i) - 4);
          v35 = v17 - 1;
        }
        v19 = (CMatQueuedMesh **)v43;
        v20 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)v43[47];
        v41[0] = ((unsigned int)v43[40] & 0x80000) != 0;
        v21 = GFxSprite::CheckAdvanceStatus(this: v43, a2: v41[0]);
        if ( v21 == -1 )
        {
          GFxASCharacter::RemoveFromOptimizedPlaylist(this: v19, result: v20);
        }
        else if ( v21 == 1 )
        {
          GFxASCharacter::AddToOptimizedPlayList(this: (int)v19, result: v20);
        }
        v6 = v38;
      }
      GRefCountNTSImpl::Release(this: v40);
    }
    v22 = 0;
    for ( i = 0; v22 < v6; i = v22 )
    {
      v23 = *(_DWORD *)(v37 + 4 * v22);
      v24 = v43[114];
      if ( v24 != nullptr )
      {
        v25 = v24[1].__vftable;
        v26 = 0;
        if ( v25 != nullptr )
        {
          p_pData = (CMatNullRenderContext *)&v24->pData;
          pData = v24->pData;
          while ( *pData != v23 )
          {
            ++v26;
            ++pData;
            if ( v26 >= (unsigned int)v25 )
              goto LABEL_59;
          }
          if ( v26 != -1 )
          {
            if ( p_pData->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable == (CRefCountServiceBase<1,CRefMT>_vtbl *)1 )
            {
              GArrayDataBase<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
                this: p_pData,
                pheapAddr: (IMorph *)p_pData,
                newSize: 0,
                a4: v33);
            }
            else
            {
              if ( *((_DWORD *)&p_pData->AddRef + v26) != 0 )
                GRefCountNTSImpl::Release(this: *((GRefCountNTSImpl **)&p_pData->AddRef + v26));
              memmove(
                dst: (unsigned __int8 *)&p_pData->AddRef + 4 * v26,
                src: (unsigned __int8 *)&p_pData->Release + 4 * v26,
                count: 4
              * ((int)p_pData->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable
               - v26)
              - 4);
              v6 = v38;
              --p_pData->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
            }
          }
        }
      }
LABEL_59:
      v22 = i + 1;
    }
    for ( j = (GRefCountNTSImpl **)(v37 + 4 * v6 - 4); v6 != 0; --v6 )
    {
      if ( *j != nullptr )
        GRefCountNTSImpl::Release(this: *j);
      --j;
    }
    ((void (__thiscall *)(GMemoryHeap *, int, const MorphWeight_t *))GMemory::pGlobalHeap->Free)(
      a1: GMemory::pGlobalHeap,
      a2: v37,
      a3: v33);
    v30 = v34;
    v31 = (GRefCountNTSImpl **)(v34 + 4 * v35 - 4);
    if ( v35 != 0 )
    {
      for ( k = v35; k != 0; --k )
      {
        if ( *v31 != nullptr )
          GRefCountNTSImpl::Release(this: *v31);
        --v31;
      }
    }
    return (GFxSprite)((int (__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(
                        a1: GMemory::pGlobalHeap,
                        a2: v30);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B7B30
// Name: public: virtual void GFxSprite::AdvanceFrame(bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::AdvanceFrame(GPtr<GFxZlibSupportBase> *this, GFxZlibSupportBase *nextFrame, int framePos)
{
  int v4; // eax
  int v5; // edi
  void (__thiscall *SType)(GPtr<GFxZlibSupportBase> *, _DWORD *); // edx
  _DWORD *v7; // eax
  _DWORD v8[2]; // [esp+4h] [ebp-30h] BYREF
  __int16 v9; // [esp+Ch] [ebp-28h]
  int v10; // [esp+Eh] [ebp-26h]
  _DWORD v11[2]; // [esp+14h] [ebp-20h] BYREF
  __int16 v12; // [esp+1Ch] [ebp-18h]
  int v13; // [esp+1Eh] [ebp-16h]
  _DWORD v14[2]; // [esp+24h] [ebp-10h] BYREF
  __int16 v15; // [esp+2Ch] [ebp-8h]
  int v16; // [esp+2Eh] [ebp-6h]

  if ( (*(_BYTE *)(this + 40) & 0xC) == 0 && (*((_WORD *)this + 59) & 0x100) == 0 && *((int *)this + 5) >= -1 )
  {
    ++*((_DWORD *)this + 1);
    if ( (_BYTE)nextFrame != 0 )
    {
      GFxSprite::CheckActiveSounds((GFxFontLib *)this, a2: (const MorphWeight_t *)1);
      if ( *((_DWORD *)this + 53) != 1 )
      {
        v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 46) + 56))(a1: *((_DWORD *)this + 46));
        if ( v4 != 0
          && (*(unsigned __int8 (__thiscall **)(int, _DWORD, _DWORD, GPtr<GFxZlibSupportBase> *))(*(_DWORD *)v4 + 4))(
               a1: v4,
               a2: *((_DWORD *)this + 47),
               a3: *((_DWORD *)this + 54),
               a4: this) == 0 )
        {
          (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this + 46) + 60))(a1: *((_DWORD *)this + 46), a2: 0);
        }
      }
    }
    if ( *(_DWORD *)(*((_DWORD *)this + 47) + 2500) != 0 )
      GFxASCharacter::DoMouseDrag((GFxASCharacter *)this, a2: (const CMaterialDict::MissingMaterial_t *)1);
    if ( (_BYTE)nextFrame == 0 )
      goto LABEL_20;
    if ( *((_DWORD *)this + 53) != 0 )
    {
      v9 = 0;
      v8[0] = 2;
      v8[1] = 0;
      v10 = 65280;
      v7 = v8;
    }
    else
    {
      v5 = *((_DWORD *)this + 54);
      GFxSprite::IncrementFrameAndCheckForLoop((GFxFontLib *)this);
      if ( *((_DWORD *)this + 54) != v5 )
      {
        GFxSprite::ExecuteInitActionFrameTags(this, frame: *((GFxZlibSupportBase **)this + 54));
        SType = (void (__thiscall *)(GPtr<GFxZlibSupportBase> *, _DWORD *))this->pObject[10].SType;
        v15 = 0;
        v14[0] = 2;
        v14[1] = 0;
        v16 = 65280;
        SType(a1: this, a2: v14);
        GFxSprite::ExecuteFrameTags(this, frame: *((GFxZlibSupportBase **)this + 54));
        goto LABEL_18;
      }
      v12 = 0;
      v11[0] = 2;
      v11[1] = 0;
      v13 = 65280;
      v7 = v11;
    }
    ((void (__stdcall *)(_DWORD *))this->pObject[10].SType)(a1: v7);
LABEL_18:
    if ( *((_DWORD *)this + 54) == 0 )
      GFxDisplayList::UnloadMarkedObjects(this: (GFxDisplayList *)(this + 49));
LABEL_20:
    GRefCountNTSImpl::Release((GRefCountNTSImpl *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7CA0
// Name: GFxRemoveObjectBase_AddToTimelineSnapshot
// Source: json
//------------------------------------------------------------------------------
struct GFxTimelineSnapshot::SnapshotElement *__cdecl GFxRemoveObjectBase_AddToTimelineSnapshot(
        unsigned __int16 a1,
        GFxTimelineSnapshot *a2)
{
  int v2; // ecx
  CThread *v3; // edi
  int v4; // ebx
  int v5; // esi
  const char *v6; // ebx
  struct GFxTimelineSnapshot::SnapshotElement *result; // eax
  int v8; // ecx
  int v9; // eax
  unsigned int v10; // ecx
  _BYTE **v11; // eax
  _DWORD *v12; // esi
  unsigned int v13; // [esp+Ch] [ebp-4h] BYREF

  (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 28))(a1: v2, a2: "\n");
  v3 = (CThread *)((char *)a2 + 20);
  v13 = a1;
  v4 = G_UpperBoundSliced<GArrayDH_POD<GFxTimelineSnapshot::SnapshotElement *,2,GArrayDefaultPolicy>,int,int (__cdecl *)(int,GFxTimelineSnapshot::SnapshotElement const *)>(
         a1: (_DWORD *)a2 + 5,
         a2: 0,
         a3: *((_DWORD *)a2 + 6),
         a4: &v13,
         a5: (int (__cdecl *)(_DWORD, _DWORD))GFxTimelineSnapshot::DepthLess);
  if ( v4 != 0 )
  {
    v5 = *((_DWORD *)v3->__vftable + v4 - 1);
    v6 = (const char *)(v4 - 1);
    if ( *(_DWORD *)(v5 + 12) == a1 && v5 != 0 )
    {
      if ( *(_BYTE *)(v5 + 52) != 0 )
      {
        *(_DWORD *)(*(_DWORD *)v5 + 4) = *(_DWORD *)(v5 + 4);
        **(_DWORD **)(v5 + 4) = *(_DWORD *)v5;
        GArrayBase<GArrayDataDH<GFxTimelineSnapshot::SnapshotElement *,GAllocatorDH_POD<GFxTimelineSnapshot::SnapshotElement *,2>,GArrayDefaultPolicy>>::RemoveAt(
          this: v3,
          index: v6);
        *(_DWORD *)v5 = *((_DWORD *)a2 + 3);
        *((_DWORD *)a2 + 3) = v5;
      }
      else
      {
        v8 = *(_DWORD *)(v5 + 16);
        if ( v8 == 0
          || *((_DWORD *)a2 + 12) != 0
          || (v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 36))(a1: v8)) == 0
          || (v10 = 0, (v13 = *(_DWORD *)(v9 + 4)) == 0) )
        {
LABEL_16:
          v12 = *((_DWORD **)&v3->dtr_CThread + (_DWORD)v6);
          *(_DWORD *)(*v12 + 4) = v12[1];
          *(_DWORD *)v12[1] = *v12;
          GArrayBase<GArrayDataDH<GFxTimelineSnapshot::SnapshotElement *,GAllocatorDH_POD<GFxTimelineSnapshot::SnapshotElement *,2>,GArrayDefaultPolicy>>::RemoveAt(
            this: v3,
            index: v6);
          *v12 = *((_DWORD *)a2 + 3);
          *((_DWORD *)a2 + 3) = v12;
          return a2;
        }
        v11 = *(_BYTE ***)v9;
        while ( (**v11 & 4) == 0 )
        {
          ++v10;
          ++v11;
          if ( v10 >= v13 )
            goto LABEL_16;
        }
        *(_BYTE *)(v5 + 53) |= 2u;
      }
    }
  }
  result = a2;
  if ( *((_DWORD *)a2 + 12) == 0 )
  {
    result = GFxTimelineSnapshot::Add(this: a2, a2: a1);
    *((_BYTE *)result + 53) |= 2u;
    *((_BYTE *)result + 52) = 3;
    *((_DWORD *)result + 3) = a1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B7DC0
// Name: public: virtual void GFxRemoveObject::AddToTimelineSnapshot(class GFxTimelineSnapshot __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxRemoveObject::AddToTimelineSnapshot(
        CMatRenderData<CPrimList> *this,
        IMatRenderContext *psnapshot,
        unsigned int __formal)
{
  GFxRemoveObjectBase_AddToTimelineSnapshot(a1: HIWORD(this->m_pRenderData), a2: (GFxTimelineSnapshot *)psnapshot);
}

//------------------------------------------------------------------------------
// Address: 0x100B7DE0
// Name: public: virtual void GFxRemoveObject2::AddToTimelineSnapshot(class GFxTimelineSnapshot __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector4D *),CFuncMemPolicyNone> *__thiscall GFxRemoveObject2::AddToTimelineSnapshot(
        unsigned __int16 *this,
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector4D *),CFuncMemPolicyNone> *result,
        unsigned int __formal)
{
  return (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector4D *),CFuncMemPolicyNone> *)GFxRemoveObjectBase_AddToTimelineSnapshot(a1: *(this + 2), a2: (GFxTimelineSnapshot *)result);
}

//------------------------------------------------------------------------------
// Address: 0x100B7E00
// Name: public: virtual void GFxSprite::SetPlayState(enum GFxMovie::PlayState)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetPlayState(GPtr<GFxZlibSupportBase> *this, CDefaultDataCacheClient *s)
{
  __int16 v3; // ax

  *((_DWORD *)this + 53) = s;
  v3 = *((_WORD *)this + 59);
  if ( (v3 & 0x100) == 0 && *((int *)this + 5) >= -1 && (v3 & 0x10) == 0 )
    GFxASCharacter::ModifyOptimizedPlayListLocal<GFxSprite>(
      (int)this,
      result: *((const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **)this
      + 47));
  if ( *((_DWORD *)this + 53) == 1 )
    GFxSprite::SetStreamingSound((GFxValue *)this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100B7E50
// Name: void GFx_FindClassAndInitializeClassInstance(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_FindClassAndInitializeClassInstance(const struct GASFnCall *fn)
{
  const struct GASFnCall *v1; // esi
  int v2; // edi
  struct GASValue *v3; // eax
  const struct GASFnCall *v4; // eax
  _TAPE_WMI_OPERATIONS *v5; // eax
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v6; // esi
  unsigned int v7; // eax
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *v8; // edx
  int (__thiscall *Release)(struct CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *); // eax
  int v10; // eax
  int v11; // eax
  GMatrix3D *v12; // ecx
  _TAPE_WMI_OPERATIONS *v13; // eax
  int v14; // eax
  _TAPE_WMI_OPERATIONS *v16; // [esp+0h] [ebp-FCh]
  GMatrix3D v17; // [esp+Ch] [ebp-F0h] BYREF
  GMatrix3D v18; // [esp+4Ch] [ebp-B0h] BYREF
  GMatrix3D v19; // [esp+8Ch] [ebp-70h] BYREF
  _KCRM_MARSHAL_HEADER *gctxt; // [esp+CCh] [ebp-30h]
  __int64 v21; // [esp+D0h] [ebp-2Ch]
  __int64 v22; // [esp+D8h] [ebp-24h]
  int v23; // [esp+E0h] [ebp-1Ch]
  _BYTE v24[12]; // [esp+E4h] [ebp-18h]
  int v25; // [esp+F0h] [ebp-Ch] BYREF
  int v26; // [esp+F4h] [ebp-8h]
  char v27; // [esp+F8h] [ebp-4h]

  v1 = fn;
  v2 = *((_DWORD *)fn + 6);
  gctxt = *(_KCRM_MARSHAL_HEADER **)(v2 + 120);
  v27 = 0;
  v25 = 0;
  v26 = 0;
  v3 = GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
  GASValue::ToStringImpl(a1: v3, a2: &fn, a3: v2, a4: -1, a5: 0);
  v4 = fn;
  if ( *((_DWORD *)fn + 4) != 0 )
  {
    if ( GASGlobalContext::FindRegisteredClass(
           this: (GFxMeshCacheManager *)gctxt,
           className: (_IMAGE_SYMBOL_EX *)(*((_DWORD *)v1 + 6) + 120),
           key: (_IMAGE_SYMBOL_EX *)&fn,
           a4: (struct GASFunctionRef *)&v25) != 0 )
    {
      v5 = GASObjectInterface::ToSprite(result: v16);
      v6 = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v5;
      v2 = 1;
      if ( v5 != nullptr )
        ++v5->DataBufferSize;
      if ( v25 != 0 )
        v7 = v25 + 16;
      else
        v7 = 0;
      GFxASCharacter::SetProtoToPrototypeOf(this: v6, psrcObj: v7);
      v21 = 0x40000;
      LOWORD(v22) = 0;
      *(_DWORD *)((char *)&v22 + 2) = 65280;
      memset(&v18.M_[0][3], 0, 14);
      *(_DWORD *)((char *)&v18.M_[1][2] + 2) = 65280;
      memset(v18.M_[2], 0, 9);
      memset(v18.M_[3], 0, 12);
      v18.M_[0][0] = 0.0;
      *(_QWORD *)&v18.M_[0][1] = 2;
      if ( v6 != nullptr )
        ++v6->m_nUserID;
      *(_QWORD *)&v18.M_[1][0] = v21;
      v8 = v6->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable;
      *(_QWORD *)&v18.M_[1][2] = v22;
      Release = v8[5].Release;
      *(_QWORD *)&v18.M_[0][2] = (unsigned int)v6;
      v18.M_[3][3] = 0.0;
      v10 = Release(this: v6);
      GFxMovieRoot::ActionEntry::Execute(this: &v18, a2: v10);
      GFxMovieRoot::ActionEntry::~ActionEntry(this: &v18);
      memset(&v17.M_[0][3], 0, 14);
      *(_DWORD *)((char *)&v17.M_[1][2] + 2) = 65280;
      memset(v17.M_[2], 0, 9);
      memset(v17.M_[3], 0, 12);
      v17.M_[0][0] = 0.0;
      *(_QWORD *)&v17.M_[0][1] = 3;
      ++v6->m_nUserID;
      if ( LODWORD(v17.M_[0][2]) != 0 )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)LODWORD(v17.M_[0][2]));
      LODWORD(v17.M_[0][2]) = v6;
      if ( LODWORD(v17.M_[0][3]) != 0 )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)LODWORD(v17.M_[0][3]));
      v17.M_[0][3] = 0.0;
      GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)v17.M_[2], orig: (const struct GASFunctionRefBase *)&v25);
      v17.M_[3][3] = 0.0;
      v11 = v6->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[5].Release(this: v6);
      GFxMovieRoot::ActionEntry::Execute(this: &v17, a2: v11);
      v12 = &v17;
    }
    else
    {
      v13 = GASObjectInterface::ToSprite(result: v16);
      v6 = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v13;
      if ( v13 != nullptr )
        ++v13->DataBufferSize;
      v23 = 0x40000;
      *(_DWORD *)v24 = 0;
      *(_WORD *)&v24[4] = 0;
      *(_DWORD *)&v24[6] = 65280;
      memset(&v19.M_[0][3], 0, 14);
      *(_DWORD *)((char *)&v19.M_[1][2] + 2) = 65280;
      memset(v19.M_[2], 0, 9);
      memset(v19.M_[3], 0, 12);
      v19.M_[0][0] = 0.0;
      *(_QWORD *)&v19.M_[0][1] = 2;
      if ( v13 != nullptr )
      {
        ++v13->DataBufferSize;
        if ( LODWORD(v19.M_[0][2]) != 0 )
          GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)LODWORD(v19.M_[0][2]));
      }
      LODWORD(v19.M_[0][2]) = v6;
      if ( LODWORD(v19.M_[0][3]) != 0 )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)LODWORD(v19.M_[0][3]));
      LODWORD(v19.M_[1][0]) = v23;
      v19.M_[1][3] = *(float *)&v24[8];
      v19.M_[0][3] = 0.0;
      *(_QWORD *)&v19.M_[1][1] = *(_QWORD *)v24;
      v19.M_[3][3] = 0.0;
      v14 = v6->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[5].Release(this: v6);
      GFxMovieRoot::ActionEntry::Execute(this: &v19, a2: v14);
      v12 = &v19;
    }
    GFxMovieRoot::ActionEntry::~ActionEntry(this: v12);
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v6);
    v4 = fn;
  }
  if ( (*((_DWORD *)v4 + 2))-- == 1 )
    GASStringNode::ReleaseNode();
  if ( (v27 & 2) == 0 && v25 != 0 )
    GRefCountBaseGC<323>::Release(a1: v25, a2: v2);
  v25 = 0;
  if ( (v27 & 1) == 0 && v26 != 0 )
    GRefCountBaseGC<323>::Release(a1: v26, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100B8160
// Name: public: virtual bool GFxSprite::OnUnloading(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GFxSprite::OnUnloading(GFxSprite *this)
{
  int v2; // ecx
  unsigned int v3; // edi
  signed int v4; // eax
  GFxSprite **v5; // edx
  ScaleformUIImpl *v6; // ecx
  int v7; // eax
  const GPoint3<float> *inserted; // edi
  GRefCountNTSImpl *z_low; // ecx
  GRefCountNTSImpl *x_low; // ecx
  int v11; // edx
  float v12; // eax
  float v13; // ecx
  float v14; // edx
  int v15; // eax
  const GPoint3<float> *v16; // edi
  GRefCountNTSImpl *v17; // ecx
  GRefCountNTSImpl *v18; // ecx
  int v19; // ecx
  float v20; // edx
  float v21; // eax
  float v22; // ecx
  const CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *v24; // [esp+0h] [ebp-40h]
  _DWORD v25[2]; // [esp+Ch] [ebp-34h] BYREF
  __int16 v26; // [esp+14h] [ebp-2Ch]
  int v27; // [esp+16h] [ebp-2Ah]
  int v28; // [esp+1Ch] [ebp-24h]
  float v29; // [esp+20h] [ebp-20h]
  __int64 v30; // [esp+24h] [ebp-1Ch]
  int v31; // [esp+2Ch] [ebp-14h]
  float v32; // [esp+30h] [ebp-10h]
  __int64 v33; // [esp+34h] [ebp-Ch]
  unsigned __int8 v34; // [esp+3Fh] [ebp-1h]

  GFxASCharacter::RemoveFromPlaylist(
    (int)this,
    result: (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)*(this + 47));
  v2 = (int)*(this + 47);
  v3 = *(_DWORD *)(v2 + 9352);
  if ( *(this + 117) != nullptr )
  {
    v4 = 0;
    if ( v3 != 0 )
    {
      v5 = *(GFxSprite ***)(v2 + 9348);
      v6 = (ScaleformUIImpl *)(v2 + 9348);
      while ( *v5 != this )
      {
        ++v4;
        ++v5;
        if ( v4 >= v3 )
          goto LABEL_9;
      }
      if ( v4 > -1 )
        GArrayBase<GArrayData<GPtr<GFxSprite>,GAllocatorLH<GPtr<GFxSprite>,326>,GArrayDefaultPolicy>>::RemoveAt(
          pheapAddr: v6,
          index: v4);
    }
  }
LABEL_9:
  (*(this + 47))[583].RefCount |= 0x400u;
  v34 = (unsigned __int8)GFxDisplayList::UnloadAll(result: v24);
  if ( v34 != 0 )
  {
    v26 = 0;
    v25[0] = 4;
    v25[1] = 0;
    v27 = 65280;
    if ( GFxSprite::HasEventHandler(this, a2: (const struct GFxEventId *)v25) == 0 )
      return v34;
    v34 = 0;
  }
  if ( (*((_BYTE *)this + 118) & 0x20) != 0 && ((unsigned int)*(this + 40) & 0x1000) == 0 )
  {
    v7 = ((int (__thiscall *)(GFxSprite *))(*this)[5].RefCount)(a1: this);
    inserted = GFxMovieRoot::ActionQueueType::InsertEntry(this: v7 + 9224, result: (const GPoint3<float> *)4);
    if ( inserted != nullptr )
    {
      LOWORD(v33) = 0;
      LODWORD(inserted->y) = 2;
      v31 = 1;
      v32 = 0.0;
      *(_DWORD *)((char *)&v33 + 2) = 65280;
      *(this + 1) = (GFxSprite)((char *)*(this + 1) + 1);
      z_low = (GRefCountNTSImpl *)LODWORD(inserted->z);
      if ( z_low != nullptr )
        GRefCountNTSImpl::Release(this: z_low);
      LODWORD(inserted->z) = this;
      x_low = (GRefCountNTSImpl *)LODWORD(inserted[1].x);
      if ( x_low != nullptr )
        GRefCountNTSImpl::Release(this: x_low);
      v11 = v31;
      v12 = v32;
      v13 = *(float *)&v33;
      inserted[1].x = 0.0;
      LODWORD(inserted[1].y) = v11;
      v14 = *((float *)&v33 + 1);
      inserted[1].z = v12;
      inserted[2].x = v13;
      inserted[2].y = v14;
    }
  }
  v15 = ((int (__thiscall *)(GFxSprite *))(*this)[5].RefCount)(a1: this);
  v16 = GFxMovieRoot::ActionQueueType::InsertEntry(this: v15 + 9224, result: (const GPoint3<float> *)4);
  if ( v16 != nullptr )
  {
    LODWORD(v16->y) = 2;
    v28 = 4;
    v29 = 0.0;
    LOWORD(v30) = 0;
    *(_DWORD *)((char *)&v30 + 2) = 65280;
    *(this + 1) = (GFxSprite)((char *)*(this + 1) + 1);
    v17 = (GRefCountNTSImpl *)LODWORD(v16->z);
    if ( v17 != nullptr )
      GRefCountNTSImpl::Release(this: v17);
    LODWORD(v16->z) = this;
    v18 = (GRefCountNTSImpl *)LODWORD(v16[1].x);
    if ( v18 != nullptr )
      GRefCountNTSImpl::Release(this: v18);
    v19 = v28;
    v20 = v29;
    v21 = *(float *)&v30;
    v16[1].x = 0.0;
    LODWORD(v16[1].y) = v19;
    v22 = *((float *)&v30 + 1);
    v16[1].z = v20;
    v16[2].x = v21;
    v16[2].y = v22;
  }
  return v34;
}

//------------------------------------------------------------------------------
// Address: 0x100B8320
// Name: public: void GFxSprite::SetHitArea(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetHitArea(
        int this,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *result)
{
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v3; // ecx
  int v4; // eax
  _TAPE_WMI_OPERATIONS *v5; // eax
  int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // eax
  _DWORD *v9; // ecx
  GFxZlibSupportBase *v10; // eax
  GFxZlibSupportBase *v11; // ebx
  GFxCharacterHandle *v12; // edi
  int v13; // edi
  int v14; // ecx
  int v15; // edx
  _DWORD *v16; // eax
  GFxCharacterHandle *v17; // edi
  _TAPE_WMI_OPERATIONS *v18; // [esp+0h] [ebp-10h]
  int v19; // [esp+4h] [ebp-Ch]
  signed int haIndex; // [esp+Ch] [ebp-4h]

  v3 = *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(this + 468);
  if ( v3 != nullptr )
  {
    GFxCharacterHandle::ResolveCharacter(this: v3, a2: *(GFxMovieRoot **)(this + 188));
    if ( v4 != 0 )
    {
      v5 = GASObjectInterface::ToSprite(result: v18);
      if ( v5 != nullptr )
        v5[39].DataBufferSize = 0;
    }
  }
  v6 = *(_DWORD *)(this + 188);
  v7 = *(_DWORD *)(v6 + 9352);
  if ( *(_DWORD *)(this + 468) != 0 && (v8 = 0, v7 != 0) )
  {
    v9 = *(_DWORD **)(v6 + 9348);
    while ( *v9 != this )
    {
      ++v8;
      ++v9;
      if ( v8 >= v7 )
        goto LABEL_10;
    }
    haIndex = v8;
  }
  else
  {
LABEL_10:
    haIndex = -1;
  }
  if ( result != nullptr )
  {
    v10 = (GFxZlibSupportBase *)DWORD1(result[6].m_pfnProxied);
    if ( v10 == nullptr )
      GFxASCharacter::CreateCharacterHandle(this: result);
    v11 = v10;
    if ( v10 != nullptr )
      ++v10->__vftable;
    v12 = *(GFxCharacterHandle **)(this + 468);
    if ( v12 != nullptr )
    {
      *v12 = (GFxCharacterHandle)((char *)*v12 - 1);
      if ( (int)*v12 <= 0 )
      {
        GFxCharacterHandle::~GFxCharacterHandle(this: v12);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v12);
      }
    }
    *(_DWORD *)(this + 468) = v11;
    if ( haIndex == -1 )
    {
      ++*(_DWORD *)(this + 4);
      v13 = *(_DWORD *)(this + 188);
      v14 = *(_DWORD *)(v13 + 9352);
      v13 += 9348;
      GArrayDataBase<GPtr<GFxSprite>,GAllocatorLH<GPtr<GFxSprite>,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
        this: (ScaleformUIImpl *)v13,
        pheapAddr: (const void *)v13,
        newSize: v14 + 1,
        a4: (int)v18,
        a5: v19);
      v15 = *(_DWORD *)(v13 + 4);
      v16 = (_DWORD *)(*(_DWORD *)v13 + 4 * v15 - 4);
      if ( *(_DWORD *)v13 + 4 * v15 != 4 )
      {
        ++*(_DWORD *)(this + 4);
        *v16 = this;
      }
      GRefCountNTSImpl::Release((GRefCountNTSImpl *)this);
    }
    result[19].m_pObject = (CMatRenderContextBase *)this;
  }
  else
  {
    v17 = *(GFxCharacterHandle **)(this + 468);
    if ( v17 != nullptr )
    {
      *v17 = (GFxCharacterHandle)((char *)*v17 - 1);
      if ( (int)*v17 <= 0 )
      {
        GFxCharacterHandle::~GFxCharacterHandle(this: v17);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v17);
      }
    }
    *(_DWORD *)(this + 468) = 0;
    if ( haIndex > -1 )
      GArrayBase<GArrayData<GPtr<GFxSprite>,GAllocatorLH<GPtr<GFxSprite>,326>,GArrayDefaultPolicy>>::RemoveAt(
        pheapAddr: (ScaleformUIImpl *)(*(_DWORD *)(this + 188) + 9348),
        index: haIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8490
// Name: public: virtual void GASMovieClipObject::Set__proto__(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMovieClipObject::Set__proto__(
        CTSQueue<CFunctor *,0,1> *this,
        CTSQueue<CFunctor *,0,1>::Node_t *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *a3)
{
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // ecx
  int *p_m_Size; // [esp+Ch] [ebp-Ch] BYREF
  int v6; // [esp+10h] [ebp-8h]
  CTSQueue<CFunctor *,0,1>::Node_t *v7; // [esp+14h] [ebp-4h]

  GASObject::Set__proto__(this, psc, psc_4: a3);
  if ( a3 != nullptr && ((int (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t *))a3[2].pNext[1].pNext)(a1: &a3[2]) != 11 )
  {
    p_m_Size = &stru_102A0AD0.m_Size;
    if ( this != (CTSQueue<CFunctor *,0,1> *)16 )
      *((_DWORD *)&this->m_Tail - 4) = (*((_DWORD *)&this->m_Tail - 4) + 1) & 0x8FFFFFFF;
    pNode = this->m_Tail.value.pNode;
    v6 = (int)this - 16;
    v7 = psc;
    ((void (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t *, CTSQueue<CFunctor *,0,1>::Node_t *, int **, int, _DWORD))pNode[2].pNext[4].pNext)(
      a1: &pNode[2],
      a2: psc,
      a3: &p_m_Size,
      a4: 13,
      a5: 0);
    if ( v6 != 0 )
      GRefCountBaseGC<323>::Release(a1: v6, a2: (int)psc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8800
// Name: public: GASMovieClipObject::GASMovieClipObject(class GASGlobalContext __near *,class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
const GFxValue::ObjectInterface *__thiscall GASMovieClipObject::GASMovieClipObject(
        char *this,
        _KCRM_MARSHAL_HEADER *result,
        GRefCountWeakSupportImpl *a3)
{
  _EVENTLOGRECORD *GC; // eax
  struct GWeakPtrProxy *WeakProxy; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v6; // eax

  GC = (_EVENTLOGRECORD *)GASGlobalContext::GetGC(this: (GASGlobalContext *)result);
  GASObject::GASObject(result: GC);
  *(_DWORD *)this = &GASButtonObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASMovieClipObject::`vftable'{for `GASObjectInterface'};
  if ( a3 != nullptr )
    WeakProxy = GRefCountWeakSupportImpl::CreateWeakProxy(this: a3);
  else
    WeakProxy = nullptr;
  *((_DWORD *)this + 13) = WeakProxy;
  *((_WORD *)this + 28) = 0;
  *(this + 58) = 0;
  v6 = (CTSQueue<CFunctor *,0,1>::Node_t *)((int (__thiscall *)(GRefCountWeakSupportImpl *))a3->__vftable[28].dtr_GRefCountImplCore)(a1: a3);
  GASMovieClipObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 16),
    psc: v6 + 15,
    a3: (CTSQueue<CFunctor *,0,1>::Node_t *)a3[10].pWeakProxy);
  return (const GFxValue::ObjectInterface *)this;
}

//------------------------------------------------------------------------------
// Address: 0x100B8870
// Name: public: virtual bool GFxSprite::SetStandardMember(enum GFxASCharacter::StandardMember,class GASValue const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSprite::SetStandardMember(
        CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *this,
        signed int member,
        struct GASValue *a3,
        bool a4)
{
  int v5; // eax
  signed int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // eax
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v10; // edx
  unsigned __int8 v11; // bl
  char result; // al
  tagPOLYTEXTW *v14; // eax
  unsigned __int8 v15; // al
  tagPOLYTEXTW *v16; // eax
  tagPOLYTEXTW *v17; // eax
  tagPOLYTEXTW *v18; // eax
  unsigned __int8 v19; // al
  const struct GASEnvironment *v20; // eax
  struct GFxASCharacter *v21; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v22; // edi
  const struct GASEnvironment *v23; // ebx
  struct GASObject *v24; // eax
  int v25; // [esp+0h] [ebp-4Ch]
  const char *v26; // [esp+4h] [ebp-48h]
  int v27; // [esp+8h] [ebp-44h]
  double v28; // [esp+Ch] [ebp-40h] BYREF
  double v29; // [esp+14h] [ebp-38h]
  double v30; // [esp+1Ch] [ebp-30h]
  double v31; // [esp+24h] [ebp-28h]
  GASValue v32[4]; // [esp+2Ch] [ebp-20h] BYREF
  GASValue v33[4]; // [esp+3Ch] [ebp-10h] BYREF
  float membera; // [esp+54h] [ebp+8h]
  float memberb; // [esp+54h] [ebp+8h]
  float memberc; // [esp+54h] [ebp+8h]
  float memberd; // [esp+54h] [ebp+8h]
  struct GASValue *ConstStringNode; // [esp+58h] [ebp+Ch]

  GASValue::GASValue(this: v33, a2: a3);
  v5 = (*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
  v6 = member;
  v7 = v5;
  if ( member > 21 && v5 != 0 )
  {
    v8 = *((_DWORD *)this + 113);
    if ( v8 != 0 && *(_DWORD *)(v8 + 44) != 0 )
    {
      v9 = *(_DWORD *)(v7 + 120);
      v10 = *(&GFxASCharacter::MemberTable + 3 * member);
      LOBYTE(v32[0]) = 0;
      ConstStringNode = GASStringManager::CreateConstStringNode(
                          this: *(GASStringManager **)(v9 + 636),
                          result: v10,
                          a3: strlen((const char *)v10),
                          a4: 0);
      ++*((_DWORD *)ConstStringNode + 2);
      v11 = (unsigned __int8)GASObject::InvokeWatchpoint();
      if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
        GASStringNode::ReleaseNode();
      if ( v11 != 0 )
        GASValue::operator=(v: (tagWNDCLASSW *)v32);
      GASValue::~GASValue(this: v32);
      v6 = member;
    }
  }
  if ( GFxASCharacter::SetStandardMember(this, member: v6, val: (tagWNDCLASSW *)v33, opcodeFlag: a4) != 0 )
  {
LABEL_12:
    GASValue::~GASValue(this: v33);
    return 1;
  }
  else
  {
    switch ( v6 )
    {
      case 4:
      case 5:
      case 12:
        goto LABEL_12;
      case 28:
        v14 = (tagPOLYTEXTW *)(*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
        v15 = (unsigned __int8)GASValue::ToBool(result: v14);
        GFxSprite::SetLockRoot((GFxSprite *)this, v: v15);
        GASValue::~GASValue(this: v33);
        return 1;
      case 33:
        if ( LOBYTE(v33[0]) == 0 || LOBYTE(v33[0]) == 10 )
        {
          *((_BYTE *)this + 481) = 0;
          GASValue::~GASValue(this: v33);
          return 1;
        }
        else
        {
          v16 = (tagPOLYTEXTW *)(*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
          *((_BYTE *)this + 481) = 2 - ((unsigned __int8)GASValue::ToBool(result: v16) != 0);
          GASValue::~GASValue(this: v33);
          return 1;
        }
      case 34:
        if ( LOBYTE(v33[0]) == 0 || LOBYTE(v33[0]) == 10 )
        {
          *((_BYTE *)this + 482) = 0;
          GASValue::~GASValue(this: v33);
          return 1;
        }
        else
        {
          v17 = (tagPOLYTEXTW *)(*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
          *((_BYTE *)this + 482) = 2 - ((unsigned __int8)GASValue::ToBool(result: v17) != 0);
          GASValue::~GASValue(this: v33);
          return 1;
        }
      case 36:
        if ( *(_BYTE *)((*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this)
                      + 124) < 8u )
          goto LABEL_28;
        v23 = (const struct GASEnvironment *)(*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
        v24 = GASValue::ToObject(this: v33, a2: v23);
        if ( v24 != nullptr && ((int (__thiscall *)(struct GASObject *))v24[2].pNode[1].pNext)(a1: &v24[2]) == 17 )
        {
          v28 = 0.0;
          v29 = 0.0;
          v30 = 0.0;
          v31 = 0.0;
          GASRectangleObject::GetProperties(
            penv: (unsigned int)v23,
            r: (GMemoryHeap *)&v28,
            params: v25,
            a4: v26,
            a5: v27);
          membera = v28;
          *(float *)v32 = membera * 20.0;
          memberb = v29;
          *(float *)&v32[1] = memberb * 20.0;
          memberc = v30 - v28;
          *(float *)&v32[2] = memberc * 20.0;
          memberd = v31 - v29;
          *(float *)&v32[3] = 20.0 * memberd;
          GFxSprite::SetScale9Grid((GFxSprite *)this, a2: (int)v32);
        }
        else
        {
          GFxSprite::SetScale9Grid((GFxSprite *)this, a2: 0);
        }
        GASValue::~GASValue(this: v33);
        result = 1;
        break;
      case 37:
        v20 = (const struct GASEnvironment *)(*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
        v21 = GASValue::ToASCharacter(this: v33, a2: v20);
        v22 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v21;
        if ( v21 != nullptr && (*(int (__thiscall **)(int))(*((_DWORD *)v21 + 30) + 8))(a1: (int)v21 + 120) == 2 )
        {
          GFxSprite::SetHitArea((int)this, result: v22);
          GASValue::~GASValue(this: v33);
          result = 1;
        }
        else
        {
          GFxSprite::SetHitArea((int)this, result: nullptr);
LABEL_28:
          GASValue::~GASValue(this: v33);
          result = 0;
        }
        break;
      case 69:
        if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this)
                                  + 120)
                      + 684) != 1 )
          goto LABEL_28;
        v18 = (tagPOLYTEXTW *)(*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
        v19 = (unsigned __int8)GASValue::ToBool(result: v18);
        GFxASCharacter::SetHitTestDisableFlag(
          (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this,
          v: (const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v19);
        GASValue::~GASValue(this: v33);
        result = 1;
        break;
      default:
        goto LABEL_28;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B8C30
// Name: public: virtual void GFxSprite::OnEventUnload(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxSprite::OnEventUnload(GFxFontLib *this)
{
  CD3D11_BLEND_DESC *v2; // edi
  bool v3; // zf

  v2 = *((CD3D11_BLEND_DESC **)this + 114);
  *((_WORD *)this + 59) |= 0x100u;
  if ( v2 != nullptr )
  {
    GFxSprite::ActiveSounds::~ActiveSounds(this: v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
  }
  v3 = *((_DWORD *)this + 117) == 0;
  *((_DWORD *)this + 114) = 0;
  if ( !v3 )
    GFxSprite::SetHitArea((int)this, result: nullptr);
  *(_DWORD *)(*((_DWORD *)this + 47) + 9332) |= 0x400u;
  GFxDisplayList::Clear(pheapAddr: (IMorph *)this + 49);
  GFxASCharacter::OnEventUnload((GFxASCharacter *)this);
  return (*(void *(__thiscall **)(char *, GFxFontLib *, _DWORD))(*((_DWORD *)this + 30) + 52))(
           a1: (char *)this + 120,
           a2: this + 22,
           a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B8CC0
// Name: public: virtual void GFxSprite::OnEventLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::OnEventLoad(GFxFontLib *this)
{
  int v2; // ecx
  const GPoint3<float> *inserted; // edi
  GRefCountNTSImpl *z_low; // ecx
  GRefCountNTSImpl *x_low; // ecx
  int v6; // eax
  float v7; // ecx
  float v8; // edx
  float v9; // eax
  int v10; // ecx
  const GPoint3<float> *v11; // edi
  GRefCountNTSImpl *v12; // ecx
  GRefCountNTSImpl *v13; // ecx
  int v14; // edx
  float v15; // eax
  float v16; // ecx
  float v17; // edx
  unsigned int v18; // edi
  int v19; // eax
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v20; // ecx
  int v21; // eax
  GFxFontLib *v22; // eax
  _TAPE_WMI_OPERATIONS *v23; // [esp+0h] [ebp-40h]
  _DWORD v24[2]; // [esp+Ch] [ebp-34h] BYREF
  __int16 v25; // [esp+14h] [ebp-2Ch]
  int v26; // [esp+16h] [ebp-2Ah]
  int v27; // [esp+1Ch] [ebp-24h]
  float v28; // [esp+20h] [ebp-20h]
  __int64 v29; // [esp+24h] [ebp-1Ch]
  int v30; // [esp+2Ch] [ebp-14h]
  float v31; // [esp+30h] [ebp-10h]
  __int64 v32; // [esp+34h] [ebp-Ch]
  unsigned int spriteArraySizea; // [esp+3Ch] [ebp-4h]

  v24[0] = 1;
  v24[1] = 0;
  v25 = 0;
  v26 = 65280;
  if ( GFxASCharacter::HasClipEventHandler((GFxASCharacter *)this, a2: (const struct GFxEventId *)v24) )
  {
    v2 = *((_DWORD *)this + 47) + 9224;
    v30 = 1;
    v31 = 0.0;
    LOWORD(v32) = 0;
    *(_DWORD *)((char *)&v32 + 2) = 65280;
    inserted = GFxMovieRoot::ActionQueueType::InsertEntry(this: v2, result: (const GPoint3<float> *)4);
    LODWORD(inserted->y) = 2;
    ++this->RefCount;
    z_low = (GRefCountNTSImpl *)LODWORD(inserted->z);
    if ( z_low != nullptr )
      GRefCountNTSImpl::Release(this: z_low);
    LODWORD(inserted->z) = this;
    x_low = (GRefCountNTSImpl *)LODWORD(inserted[1].x);
    if ( x_low != nullptr )
      GRefCountNTSImpl::Release(this: x_low);
    v6 = v30;
    v7 = v31;
    v8 = *(float *)&v32;
    inserted[1].x = 0.0;
    LODWORD(inserted[1].y) = v6;
    v9 = *((float *)&v32 + 1);
    inserted[1].z = v7;
    inserted[2].x = v8;
    inserted[2].y = v9;
  }
  else
  {
    LOWORD(v29) = 0;
    v10 = *((_DWORD *)this + 47) + 9224;
    v27 = 1;
    v28 = 0.0;
    *(_DWORD *)((char *)&v29 + 2) = 65280;
    v11 = GFxMovieRoot::ActionQueueType::InsertEntry(this: v10, result: (const GPoint3<float> *)5);
    LODWORD(v11->y) = 2;
    ++this->RefCount;
    v12 = (GRefCountNTSImpl *)LODWORD(v11->z);
    if ( v12 != nullptr )
      GRefCountNTSImpl::Release(this: v12);
    LODWORD(v11->z) = this;
    v13 = (GRefCountNTSImpl *)LODWORD(v11[1].x);
    if ( v13 != nullptr )
      GRefCountNTSImpl::Release(this: v13);
    v14 = v27;
    v15 = v28;
    v16 = *(float *)&v29;
    v11[1].x = 0.0;
    LODWORD(v11[1].y) = v14;
    v17 = *((float *)&v29 + 1);
    v11[1].z = v15;
    v11[2].x = v16;
    v11[2].y = v17;
  }
  *((_WORD *)this + 59) |= 0x20u;
  GFxSprite::ExecuteFrameTags((GPtr<GFxZlibSupportBase> *)this, frame: nullptr);
  v18 = 0;
  spriteArraySizea = *(_DWORD *)(*((_DWORD *)this + 47) + 9352);
  if ( spriteArraySizea != 0 )
  {
    do
    {
      v19 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 47) + 9348) + 4 * v18);
      v20 = *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v19 + 468);
      if ( v20 != nullptr
        && (GFxCharacterHandle::ResolveCharacter(this: v20, a2: *(GFxMovieRoot **)(v19 + 188)), v21 != 0) )
      {
        v22 = (GFxFontLib *)GASObjectInterface::ToSprite(result: v23);
      }
      else
      {
        v22 = nullptr;
      }
      if ( this == v22 )
        GFxSprite::SetHitArea(
          this: *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 47) + 9348) + 4 * v18),
          result: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this);
      ++v18;
    }
    while ( v18 < spriteArraySizea );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8E50
// Name: private: class GASMovieClipObject __near * GFxSprite::GetMovieClipObject(void)
// Source: json
//------------------------------------------------------------------------------
const GFxValue::ObjectInterface *__thiscall GFxSprite::GetMovieClipObject(GRefCountWeakSupportImpl *this)
{
  int v2; // ecx
  int (__thiscall *v3)(int, int, int *); // edx
  char *v4; // edi
  _KCRM_MARSHAL_HEADER *v5; // eax
  const GFxValue::ObjectInterface *v6; // edi
  int v7; // ecx
  int v9; // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 113) != 0 )
    return *((const GFxValue::ObjectInterface **)this + 113);
  v2 = *(_DWORD *)(*((_DWORD *)this + 47) + 32);
  v3 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v2 + 40);
  v9 = 323;
  v4 = (char *)v3(a1: v2, a2: 60, a3: &v9);
  if ( v4 != nullptr )
  {
    v5 = (_KCRM_MARSHAL_HEADER *)((int (__thiscall *)(GRefCountWeakSupportImpl *))this->__vftable[52].dtr_GRefCountImplCore)(a1: this);
    v6 = GASMovieClipObject::GASMovieClipObject(this: v4, result: v5, a3: this);
  }
  else
  {
    v6 = nullptr;
  }
  v7 = *((_DWORD *)this + 113);
  if ( v7 != 0 )
    GRefCountBaseGC<323>::Release(a1: v7, a2: (int)v6);
  *((_DWORD *)this + 113) = v6;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100B8ED0
// Name: public: virtual class GASObject __near * GFxSprite::GetASObject(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const GFxValue::ObjectInterface *__thiscall GFxSprite::GetASObject(GRefCountWeakSupportImpl *this)
{
  return GFxSprite::GetMovieClipObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B8EE0
// Name: public: virtual class GASObject __near * GASMovieClipCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
struct GASObject *__thiscall GASMovieClipCtorFunction::CreateNewObject(
        GASMovieClipCtorFunction *this,
        struct GASEnvironment *a2)
{
  int v2; // ecx
  int (__thiscall *v3)(int, int, int *); // edx
  vc_attributes::PreRangeAttribute **v4; // edi
  GASObject *v5; // eax
  GASObject *v6; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *ActualPrototype; // eax
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v2 = *(_DWORD *)(*((_DWORD *)a2 + 30) + 656);
  v3 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v2 + 40);
  v4 = (vc_attributes::PreRangeAttribute **)((char *)a2 + 120);
  v9 = 323;
  v5 = (GASObject *)v3(a1: v2, a2: 60, a3: &v9);
  v6 = v5;
  if ( v5 == nullptr )
    return nullptr;
  GASObject::GASObject(this: v5, a2);
  v6->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASButtonObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v6[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASMovieClipObject::`vftable'{for `GASObjectInterface'};
  v6[6].sequence = 0;
  LOWORD(v6[7].pNode) = 0;
  BYTE2(v6[7].pNode) = 0;
  ActualPrototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetActualPrototype(this: *v4, a2, a3: 6);
  GASMovieClipObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)&v6[2],
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v4,
    a3: ActualPrototype);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100B9000
// Name: public: virtual bool GFxSprite::SetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::SetMemberRaw(
        GMemoryFile *this,
        _IMAGE_SYMBOL_EX *psc,
        _IMAGE_SYMBOL_EX *name,
        tagWNDCLASSW *val,
        int flags)
{
  char v6; // al
  CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *StandardMemberConstant; // eax

  GFxASCharacter::IsStandardMember(
    memberName: (const MaterialPrimitiveType_t *)this,
    pcaseInsensitiveName: name,
    lowerCase: nullptr);
  if ( v6 == 0
    || (StandardMemberConstant = GFxASCharacter::GetStandardMemberConstant(this: (char *)this - 120, result: name),
        (*(unsigned __int8 (__thiscall **)(char *, CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, tagWNDCLASSW *, _DWORD))(*((_DWORD *)this - 30) + 284))(
          a1: (char *)this - 120,
          a2: StandardMemberConstant,
          a3: val,
          a4: 0) == 0) )
  {
    if ( *((_DWORD *)this + 83) != 0
      || GFxSprite::GetMovieClipObject(this: (GRefCountWeakSupportImpl *)this - 10) != nullptr )
    {
      (*(void (__thiscall **)(int, _IMAGE_SYMBOL_EX *, _IMAGE_SYMBOL_EX *, tagWNDCLASSW *, int))(*(_DWORD *)(*((_DWORD *)this + 83) + 16)
                                                                                               + 40))(
        a1: *((_DWORD *)this + 83) + 16,
        a2: psc,
        a3: name,
        a4: val,
        a5: flags);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9090
// Name: public: GASMovieClipProto::GASMovieClipProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASMovieClipProto *__thiscall GASMovieClipProto::GASMovieClipProto(
        GASMovieClipProto *this,
        ScaleformFileOpener *result,
        struct GASObject *ConstStringNode,
        const struct GASFunctionRef *a4)
{
  GASObject *v5; // edi
  struct GASString *p_GetFileModifyTime; // ebx
  ScaleformFileOpener_vtbl *v7; // eax
  bool v8; // zf
  ScaleformFileOpener_vtbl *v9; // eax
  ScaleformFileOpener_vtbl *v10; // eax
  ScaleformFileOpener_vtbl *v11; // eax
  ScaleformFileOpener_vtbl *v12; // eax
  bool v14; // [esp+0h] [ebp-20h]
  GFxValue val; // [esp+Ch] [ebp-14h] BYREF
  GASMovieClipProto *v16; // [esp+1Ch] [ebp-4h]

  v16 = this;
  GASPrototype<GASMovieClipObject,GASEnvironment>::GASPrototype<GASMovieClipObject,GASEnvironment>(result);
  v5 = (GASObject *)((char *)this + 16);
  *(_DWORD *)this = &GASMovieClipProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASMovieClipProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 15) = &stru_102A09D0.m_Memory.m_nGrowSize;
  HIBYTE(a4) = 1;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 15,
    a2: (struct GASObject *)this,
    a3: (struct GASStringContext *)result,
    a4: (const struct GASNameFunction *)&MovieClipFunctionTable,
    a5: (const struct GASPropFlags *)((char *)&a4 + 3));
  p_GetFileModifyTime = (struct GASString *)&result->__vftable[32].GetFileModifyTime;
  HIBYTE(a4) = 3;
  LOBYTE(val.pObjectInterface) = 2;
  LOBYTE(val.Type) = 1;
  GASMovieClipObject::SetMemberCommon(
    this: (GFxValue::ObjectInterface *)&v5[-2],
    psc: (_IMAGE_SYMBOL_EX *)result,
    name: p_GetFileModifyTime,
    (tagWNDCLASSW *)&val,
    size: v14);
  GASObject::SetMemberRaw(
    this: v5,
    a2: (struct GASStringContext *)result,
    a3: p_GetFileModifyTime,
    a4: (GASValue *)&val,
    a5: (const struct GASPropFlags *)((char *)&a4 + 3));
  GASValue::~GASValue(this: (GASValue *)&val);
  v7 = result->__vftable;
  HIBYTE(a4) = 3;
  LOBYTE(val.pObjectInterface) = 10;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: (GASStringManager *)v7[39].OpenFileEx,
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E434.m_Size,
                                          a3: 7u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  ((void (__thiscall *)(GASObject *, ScaleformFileOpener *, struct GASObject **, GFxValue *, char *))v5->pNode[5].pNext)(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &val,
    a5: (char *)&a4 + 3);
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode();
  GASValue::~GASValue(this: (GASValue *)&val);
  v9 = result->__vftable;
  HIBYTE(a4) = 3;
  LOBYTE(val.pObjectInterface) = 10;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: (GASStringManager *)v9[39].OpenFileEx,
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E3C4,
                                          a3: 0xAu,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  ((void (__thiscall *)(GASObject *, ScaleformFileOpener *, struct GASObject **, GFxValue *, char *))v5->pNode[5].pNext)(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &val,
    a5: (char *)&a4 + 3);
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode();
  GASValue::~GASValue(this: (GASValue *)&val);
  v10 = result->__vftable;
  HIBYTE(a4) = 3;
  LOBYTE(val.pObjectInterface) = 10;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: (GASStringManager *)v10[39].OpenFileEx,
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E410,
                                          a3: 8u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  ((void (__thiscall *)(GASObject *, ScaleformFileOpener *, struct GASObject **, GFxValue *, char *))v5->pNode[5].pNext)(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &val,
    a5: (char *)&a4 + 3);
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode();
  GASValue::~GASValue(this: (GASValue *)&val);
  v11 = result->__vftable;
  HIBYTE(a4) = 3;
  LOBYTE(val.pObjectInterface) = 10;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: (GASStringManager *)v11[39].OpenFileEx,
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E434,
                                          a3: 0xBu,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  ((void (__thiscall *)(GASObject *, ScaleformFileOpener *, struct GASObject **, GFxValue *, char *))v5->pNode[5].pNext)(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &val,
    a5: (char *)&a4 + 3);
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode();
  GASValue::~GASValue(this: (GASValue *)&val);
  v12 = result->__vftable;
  HIBYTE(a4) = 3;
  LOBYTE(val.pObjectInterface) = 10;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: (GASStringManager *)v12[39].OpenFileEx,
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E3C4.m_Size,
                                          a3: 9u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  ((void (__thiscall *)(GASObject *, ScaleformFileOpener *))v5->pNode[5].pNext)(a1: v5, a2: result);
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode();
  GASValue::~GASValue(this: (GASValue *)&val);
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x100B93C0
// Name: public: GFxSpriteDef::GFxSpriteDef(class GFxMovieDataDef __near *)
// Source: json
//------------------------------------------------------------------------------
GFxSpriteDef *__thiscall GFxSpriteDef::GFxSpriteDef(GFxSpriteDef *this, struct GFxMovieDataDef *pmd)
{
  *(_DWORD *)this = &GFxResource::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0x40000;
  *(_DWORD *)this = &GFxSpriteDef::`vftable';
  *((_DWORD *)this + 4) = pmd;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_BYTE *)this + 52) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B9410
// Name: public: virtual unsigned int GFxSpriteDef::GetVersion(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSpriteDef::GetVersion(GRefCountBaseNTS<GFxKeyboardState,326> *this)
{
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 4) + 32))(a1: *((_DWORD *)this + 4));
}

//------------------------------------------------------------------------------
// Address: 0x100B9420
// Name: public: virtual unsigned int GFxSpriteDef::GetSWFFlags(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSpriteDef::GetSWFFlags(GRefCountBaseNTS<GFxKeyboardState,326> *this)
{
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 4) + 68))(a1: *((_DWORD *)this + 4));
}

//------------------------------------------------------------------------------
// Address: 0x100B9430
// Name: public: virtual bool GFxSpriteDef::GetLabeledFrame(char const __near *,unsigned int __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSpriteDef::GetLabeledFrame(
        GRefCountBaseNTS<GFxKeyboardState,326> *this,
        GRefCountBaseNTS<GFxKeyboardState,326> *label,
        unsigned int *frameNumber,
        bool translateNumbers)
{
  return GFxMovieDataDef::TranslateFrameString(
           result: (const CP4AutoEditAddFile *)this + 5,
           a2: (char *)label,
           frameNumber,
           translateNumbers);
}

//------------------------------------------------------------------------------
// Address: 0x100B9450
// Name: public: virtual unsigned int GFxSpriteDef::GetResourceTypeCode(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSpriteDef::GetResourceTypeCode(GRefCountBaseNTS<GFxKeyboardState,326> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100B9460
// Name: public: virtual float GFxSpriteDef::GetFrameRate(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxSpriteDef::GetFrameRate(GFxSpriteDef *this)
{
  return *(float *)(*(_DWORD *)(*((_DWORD *)this + 4) + 32) + 64);
}

//------------------------------------------------------------------------------
// Address: 0x100B9470
// Name: public: virtual unsigned long GFxSpriteDef::GetFileBytes(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSpriteDef::GetFileBytes(GRefCountBaseNTS<GFxKeyboardState,326> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100B9480
// Name: public: virtual char const __near * GFxSpriteDef::GetFileURL(void)const
// Source: json
//------------------------------------------------------------------------------
GRefCountBaseNTS<GFxKeyboardState,326> *__thiscall GFxSpriteDef::GetFileURL(_DWORD *this)
{
  return (GRefCountBaseNTS<GFxKeyboardState,326> *)((*(_DWORD *)(*(_DWORD *)(*(this + 4) + 32) + 36) & 0xFFFFFFFC) + 8);
}

//------------------------------------------------------------------------------
// Address: 0x100B9490
// Name: public: virtual void GFxSpriteDef::SetLoadingPlaylistFrame(struct GFxTimelineDef::Frame const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSpriteDef::SetLoadingPlaylistFrame(GFxSpriteDef *this, const struct Frame *a2)
{
  struct Frame *v2; // eax

  v2 = (struct Frame *)(*((_DWORD *)this + 8) + 8 * *((_DWORD *)this + 7));
  v2->lpVtbl = a2->lpVtbl;
  v2[1].lpVtbl = a2[1].lpVtbl;
}

//------------------------------------------------------------------------------
// Address: 0x100B94B0
// Name: public: virtual struct GFxTimelineDef::Frame const GFxSpriteDef::GetPlaylist(int)const
// Source: json
//------------------------------------------------------------------------------
struct Frame __thiscall GFxSpriteDef::GetPlaylist(GFxSpriteDef *this, _DWORD *a2, int frameNumber)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v7; // ecx

  v3 = *((_DWORD *)this + 8);
  v4 = *(_DWORD *)(v3 + 8 * frameNumber);
  v5 = v3 + 8 * frameNumber;
  v7 = *(_DWORD *)(v5 + 4);
  *a2 = v4;
  a2[1] = v7;
  return (struct Frame)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100B94D0
// Name: public: virtual class GRect<float> GFxSpriteDef::GetFrameRect(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
float *__stdcall GFxSpriteDef::GetFrameRect(float *a1)
{
  *a1 = 0.0;
  a1[1] = 0.0;
  a1[2] = 1.0;
  a1[3] = 1.0;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x100B94F0
// Name: public: virtual GFxSpriteDef::~GFxSpriteDef(void)
// Source: json
//------------------------------------------------------------------------------
IScaleformUI::KeyCode __thiscall GFxSpriteDef::~GFxSpriteDef(char *this)
{
  unsigned int v2; // edi
  GRefCountNTSImpl *v3; // ecx
  IScaleformUI::KeyCode result; // eax
  ButtonCode_t v5; // [esp+0h] [ebp-8h]

  v2 = 0;
  for ( *(_DWORD *)this = &GFxSpriteDef::`vftable'; v2 < *((_DWORD *)this + 9); ++v2 )
    GFxTimelineDef::Frame::DestroyTags(this: (GFxTimelineDef::Frame *)(*((_DWORD *)this + 8) + 8 * v2));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 11));
  v3 = *((GRefCountNTSImpl **)this + 12);
  if ( v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 8));
  result = GHashSetBase<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<bool,2>,GHashsetCachedNodeEntry<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<bool,2>,GHashsetCachedNodeEntry<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF>>(
             this: (ScaleformUIImpl *)(this + 20),
             a2: v5);
  *(_DWORD *)this = &GFxResource::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B9560
// Name: private: virtual void GFxSprite::CloneInternalData(class GFxASCharacter const __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxSprite::CloneInternalData@<eax>(
        GFxFontLib *this@<ecx>,
        GFxFontLib::FontResult *src,
        const char *src_4,
        unsigned int a4,
        GFxMovieDef *a5,
        GFxStateBag *a6,
        GFxResourceWeakLib *a7)
{
  _TAPE_WMI_OPERATIONS *v8; // eax
  GFxValue::ObjectInterface *DataBuffer; // eax
  const GFxValue::ObjectInterface *MovieClipObject; // eax
  int result; // eax
  _TAPE_WMI_OPERATIONS *v12; // [esp+0h] [ebp-8h]

  GFxASCharacter::CloneInternalData(
    (CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this,
    (unsigned int)src);
  if ( ((int (__thiscall *)(GFxFontLib::FontResult *))src[15].pMovieDef->pLib)(a1: &src[15]) == 2 )
  {
    v8 = GASObjectInterface::ToSprite(result: v12);
    if ( (v8[37].Method & 0x80000000) != 0 && (v8[13].DataBufferSize & 0x10) != 0 )
    {
      if ( v8[37].DataBuffer != nullptr )
        DataBuffer = (GFxValue::ObjectInterface *)v8[37].DataBuffer;
      else
        DataBuffer = (GFxValue::ObjectInterface *)v8[10].DataBuffer;
      if ( DataBuffer != nullptr && GASMovieClipObject::ActsAsButton(this: DataBuffer) != 0 )
      {
        MovieClipObject = GFxSprite::GetMovieClipObject((GRefCountWeakSupportImpl *)this);
        if ( MovieClipObject != nullptr )
          BYTE2(MovieClipObject[14].pMovieRoot) = 1;
      }
    }
  }
  result = *((_DWORD *)this + 47);
  *(_DWORD *)(result + 9332) |= 0x400u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B95F0
// Name: public: GFxCharPosInfo::GFxCharPosInfo(class GFxCharPosInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxCharPosInfo *__thiscall GFxCharPosInfo::GFxCharPosInfo(GFxCharPosInfo *this, const struct GFxCharPosInfo *__that)
{
  VertexDesc_t *v4; // [esp+0h] [ebp-Ch]

  GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>(
    (CMatQueuedMesh *)this,
    a: (int *)__that,
    a3: v4);
  qmemcpy((char *)this + 12, (char *)__that + 12, 0x48u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B9670
// Name: public: virtual bool GFxSprite::ReplaceChildCharacter(class GFxASCharacter __near *,class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall GFxSprite::ReplaceChildCharacter(
        GMemoryFile *this,
        CMatQueuedMesh *poldChar,
        CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pnewChar)
{
  GMemoryFile *v3; // ebx
  char v5; // bl
  _TAPE_WMI_OPERATIONS *v6; // eax
  char Method; // cl
  char v8; // cl
  unsigned int DataBufferSize; // eax
  ScaleformRenderer *v10; // eax
  unsigned int DisplayIndex; // eax
  VertexDesc_t *v12; // [esp-Ch] [ebp-28h] BYREF
  unsigned int v13; // [esp-8h] [ebp-24h]
  CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *m_pOwner; // [esp-4h] [ebp-20h]
  __int128 v15; // [esp+0h] [ebp-1Ch] OVERLAPPED BYREF
  GMemoryFile *v16; // [esp+18h] [ebp-4h]

  v3 = this;
  m_pOwner = (CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)poldChar->m_pOwner;
  v16 = this;
  if ( GFxDisplayList::GetDisplayIndex(this: (GFxDisplayList *)(this + 7), a2: m_pOwner) == -1 )
    return 0;
  GFxASCharacter::CopyPhysicalProperties(this: pnewChar, (unsigned int)poldChar);
  if ( ((int (__thiscall *)(CRefCountServiceDestruct<CRefST> *))pnewChar[2].CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable[2].dtr_CRefCountServiceDestruct<CRefST>)(a1: &pnewChar[2].CRefCountServiceDestruct<CRefST>) == 2
    && (*((int (__thiscall **)(unsigned __int8 **))poldChar[1].m_pVertexData + 2))(a1: &poldChar[1].m_pVertexData) == 2 )
  {
    v5 = LOBYTE(GASObjectInterface::ToSprite(result: (_TAPE_WMI_OPERATIONS *)v15)[40].Method) >> 5;
    v6 = GASObjectInterface::ToSprite(result: (_TAPE_WMI_OPERATIONS *)v15);
    Method = v6[40].Method;
    if ( (v5 & 1) != 0 )
      v8 = Method | 0x20;
    else
      v8 = Method & 0xDF;
    LOBYTE(v6[40].Method) = v8;
    DataBufferSize = GASObjectInterface::ToSprite(result: (_TAPE_WMI_OPERATIONS *)v15)[14].DataBufferSize;
    if ( DataBufferSize != 0 )
    {
      if ( *(_BYTE *)(DataBufferSize + 13) != 0 )
      {
        GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>(
          this: (CMatQueuedMesh *)((char *)&v15 + 12),
          a: (int *)DataBufferSize,
          a3: (VertexDesc_t *)v15);
        GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::PopBack(this: (ITypeInfo *)v15);
        GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>(
          this: (CMatQueuedMesh *)&v12,
          a: (int *)&v15 + 3,
          a3: v12);
        ((void (__thiscall *)(CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, VertexDesc_t *, unsigned int, CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *))pnewChar->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[3].AddRef)(
          a1: pnewChar,
          a2: v12,
          a3: v13,
          a4: m_pOwner);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)HIDWORD(v15));
      }
      else
      {
        GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>(
          this: (CMatQueuedMesh *)&v12,
          a: (int *)DataBufferSize,
          a3: v12);
        ((void (__thiscall *)(CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, VertexDesc_t *, unsigned int, CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *))pnewChar->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[3].AddRef)(
          a1: pnewChar,
          a2: v12,
          a3: v13,
          a4: m_pOwner);
      }
    }
    v3 = v16;
  }
  poldChar->IMesh::IVertexBuffer::__vftable[1].GetRoomRemaining(this: poldChar);
  HIWORD(poldChar[1].m_VertexFormat) |= 0x100u;
  v10 = (ScaleformRenderer *)((int (__thiscall *)(GMemoryFile *))v3->__vftable[1].IsValid)(a1: v3);
  GFxMovieRoot::DoActions(this: v10);
  GFxASCharacter::MoveNameHandle(
    this: (CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)pnewChar,
    poldChar,
    a3: v15);
  DisplayIndex = GFxDisplayList::GetDisplayIndex(this: (GFxDisplayList *)&v3[7], a2: poldChar->m_pOwner);
  if ( DisplayIndex == -1 )
    return 0;
  m_pOwner = pnewChar;
  v13 = DisplayIndex;
  GFxDisplayList::ReplaceDisplayObjectAtIndex();
  *(_DWORD *)(v3[6].FileIndex + 9332) |= 0x400u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B97E0
// Name: public: GASEnvironment::GASEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
GASEnvironment *__thiscall GASEnvironment::GASEnvironment(GASEnvironment *this)
{
  *this = (GASEnvironment)&GASEnvironment::`vftable';
  GASPagedStack<GASValue,32>::GASPagedStack<GASValue,32>(this: (__vc_attributes::progidAttribute *)this + 2);
  *((_BYTE *)this + 40) = 0;
  *((_BYTE *)this + 56) = 0;
  *((_BYTE *)this + 72) = 0;
  *((_BYTE *)this + 88) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_BYTE *)this + 124) = 0;
  GASPagedStack<GPtr<GASFunctionObject>,32>::GASPagedStack<GPtr<GASFunctionObject>,32>(this: (GRenderer::CachedData *)this + 16);
  *((_DWORD *)this + 40) = 0;
  *((_DWORD *)this + 41) = 0;
  *((_DWORD *)this + 42) = 0;
  *((_DWORD *)this + 43) = 0;
  *((_BYTE *)this + 176) = 10;
  *((_BYTE *)this + 198) &= 0xFCu;
  *((_DWORD *)this + 48) = 0;
  *((_WORD *)this + 98) = 0;
  *((_DWORD *)this + 50) = 0;
  *((_DWORD *)this + 51) = 0;
  *((_DWORD *)this + 52) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B9870
// Name: public: virtual GASEnvironment::~GASEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::~GASEnvironment(GASEnvironment *this)
{
  int v2; // eax
  int *v3; // edi
  int v4; // ebx
  GASValue *v5; // edi
  int v6; // ebx
  GASValue *v7; // edi
  int i; // ebx

  *this = (GASEnvironment)&GASEnvironment::`vftable';
  v2 = *((_DWORD *)this + 51);
  v3 = (int *)(*((_DWORD *)this + 50) + 4 * v2 - 4);
  if ( v2 != 0 )
  {
    v4 = *((_DWORD *)this + 51);
    do
    {
      if ( *v3 != 0 )
        GRefCountBaseGC<323>::Release(a1: *v3, a2: (int)v3);
      --v3;
      --v4;
    }
    while ( v4 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 50));
  GASValue::~GASValue(this: (GASValue *)this + 44);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 41));
  GASPagedStack<GPtr<GASFunctionObject>,32>::~GASPagedStack<GPtr<GASFunctionObject>,32>(this: (__vc_attributes::atl::aggregatesAttribute *)this + 32);
  v5 = (GASValue *)(*((_DWORD *)this + 26) + 16 * *((_DWORD *)this + 27) - 16);
  if ( *((_DWORD *)this + 27) != 0 )
  {
    v6 = *((_DWORD *)this + 27);
    do
    {
      GASValue::~GASValue(this: v5);
      v5 -= 4;
      --v6;
    }
    while ( v6 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 26));
  v7 = (GASValue *)(this + 26);
  for ( i = 3; i >= 0; --i )
  {
    v7 -= 4;
    GASValue::~GASValue(this: v7);
  }
  GASPagedStack<GASValue,32>::~GASPagedStack<GASValue,32>(this: (__vc_attributes::iid_isAttribute *)this + 2);
  *this = (GASEnvironment)&GFxLogBase<GFxLoadProcess>::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100B99A0
// Name: public: GFxSprite::GFxSprite(class GFxTimelineDef __near *,class GFxMovieDefImpl __near *,class GFxMovieRoot __near *,class GFxASCharacter __near *,class GFxResourceId,bool)
// Source: json
//------------------------------------------------------------------------------
GFxFontLib::FontResult *__thiscall GFxSprite::GFxSprite(
        GFxFontLib::FontResult *this,
        _IMAGE_SECTION_HEADER::<unnamed_type_Misc> pdefImpl,
        _IMAGE_SECTION_HEADER::<unnamed_type_Misc> pbindingDefImpl,
        int a4,
        struct GFxASCharacter *a5,
        struct GFxResourceId a6,
        int loadedSeparately)
{
  int v8; // ecx
  char v9; // cl
  char v10; // al
  char v11; // al
  struct GFxASCharacter *v12; // edi
  int v13; // eax
  char v14; // dl
  int v15; // ecx
  int v16; // eax
  int v17; // edi
  int (__thiscall *v18)(int, int, struct GFxASCharacter **); // edx
  int v19; // eax
  char v20; // cl
  int v21; // edx
  int v22; // eax
  int (__thiscall *v23)(int, int, _IMAGE_SECTION_HEADER::<unnamed_type_Misc> *); // edx
  CDefaultClientRenderable *v24; // eax
  int v25; // eax
  int v26; // edi
  GRefCountNTSImpl *v27; // ecx
  int v28; // eax
  int v29; // edx
  _DWORD *v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // edi
  ICvar *v33; // ecx
  vc_attributes::PreRangeAttribute *v34; // eax
  int ActualPrototype; // eax
  int v36; // edi
  int v37; // ecx
  float v39; // [esp+0h] [ebp-Ch]

  GFxASCharacter::GFxASCharacter((GFxASCharacter *)this, pbindingDefImpl, a3: a5, a4: a6);
  this->pMovieDef = (GFxMovieDef *)&GFxSprite::`vftable'{for `GRefCountBaseWeakSupport<GFxCharacter,322>'};
  *((_DWORD *)this + 3) = &GFxSprite::`vftable'{for `GFxLogBase<GFxCharacter>'};
  *((_DWORD *)this + 30) = &GFxSprite::`vftable';
  if ( pdefImpl.PhysicalAddress != 0 )
    GRefCountImpl::AddRef(this: (IShaderDevice *)pdefImpl.PhysicalAddress);
  v8 = a4;
  *((_IMAGE_SECTION_HEADER::<unnamed_type_Misc> *)this + 46) = pdefImpl;
  *((_DWORD *)this + 47) = v8;
  *((_DWORD *)this + 48) = 0;
  *((_DWORD *)this + 49) = 0;
  *((_DWORD *)this + 50) = 0;
  *((_DWORD *)this + 51) = 0;
  *((_DWORD *)this + 52) = 0;
  *((_DWORD *)this + 53) = 0;
  *((_DWORD *)this + 54) = 0;
  *((_DWORD *)this + 55) = 0;
  *((_DWORD *)this + 56) = 0;
  *((_DWORD *)this + 57) = 0;
  GASEnvironment::GASEnvironment(this: (GASEnvironment *)this + 58);
  *((_DWORD *)this + 111) = -1;
  *((_DWORD *)this + 112) = 0;
  *((_DWORD *)this + 113) = 0;
  *((_DWORD *)this + 115) = 0;
  *((_DWORD *)this + 117) = 0;
  *((_DWORD *)this + 118) = 0;
  *((_DWORD *)this + 119) = 0;
  *((_WORD *)this + 240) = 0;
  *((_BYTE *)this + 482) = 0;
  *((_DWORD *)this + 121) = 0;
  *((_DWORD *)this + 116) = 0;
  *((_DWORD *)this + 114) = 0;
  if ( ((*(int (__thiscall **)(_IMAGE_SECTION_HEADER::<unnamed_type_Misc>))(*(_DWORD *)pdefImpl.PhysicalAddress + 8))(a1: pdefImpl)
      & 0xFF00) == 0x8400 )
  {
    GFxSprite::SetScale9Grid((GFxSprite *)this, a2: *(_DWORD *)(pdefImpl.PhysicalAddress + 44));
    *((_BYTE *)this + 480) |= 0x40u;
  }
  GASEnvironment::SetTargetOnConstruct(this: (int)(this + 29), result: (__vc_attributes::idl_moduleAttribute *)this);
  v9 = loadedSeparately;
  v10 = *(_BYTE *)(this + 60) & 0xDC | 1;
  *((_BYTE *)this + 480) = v10;
  if ( v9 != 0 )
    v11 = v10 | 0x10;
  else
    v11 = v10 & 0xEF;
  v12 = a5;
  *((_BYTE *)this + 480) = v11;
  if ( v12 != nullptr && v9 == 0 )
  {
    v13 = (*(int (__thiscall **)(struct GFxASCharacter *))(*(_DWORD *)v12 + 92))(a1: v12);
    if ( v13 != pbindingDefImpl.PhysicalAddress )
    {
      v14 = 1;
      HIBYTE(loadedSeparately) = 1;
LABEL_14:
      if ( v12 != nullptr && v14 == 0 )
        goto LABEL_35;
      goto LABEL_16;
    }
    v9 = loadedSeparately;
  }
  HIBYTE(loadedSeparately) = 0;
  v14 = 0;
  if ( v9 == 0 )
    goto LABEL_14;
LABEL_16:
  v15 = *((_DWORD *)this + 47);
  v16 = *(_DWORD *)(v15 + 60);
  if ( v16 != v15 + 56 )
  {
    while ( *(_DWORD *)(v16 + 12) != *((_DWORD *)this + 36) || *(_BYTE *)(v16 + 24) != v14 )
    {
      v16 = *(_DWORD *)(v16 + 4);
      if ( v16 == *((_DWORD *)this + 47) + 56 )
        goto LABEL_22;
    }
    ++*(_DWORD *)(v16 + 8);
    *((_DWORD *)this + 112) = v16;
  }
LABEL_22:
  if ( *((_DWORD *)this + 112) == 0 )
  {
    v17 = *(_DWORD *)(a4 + 32);
    v18 = *(int (__thiscall **)(int, int, struct GFxASCharacter **))(*(_DWORD *)v17 + 40);
    a5 = (struct GFxASCharacter *)326;
    v19 = v18(a1: v17, a2: 32, a3: &a5);
    if ( v19 != 0 )
    {
      *(_DWORD *)(v19 + 12) = *((_DWORD *)this + 36);
      v20 = HIBYTE(loadedSeparately);
      *(_DWORD *)(v19 + 8) = 1;
      *(_BYTE *)(v19 + 24) = v20;
      *(_DWORD *)(v19 + 28) = 0;
    }
    else
    {
      v19 = 0;
    }
    v21 = *((_DWORD *)this + 36);
    *((_DWORD *)this + 112) = v19;
    *(_DWORD *)(*((_DWORD *)this + 112) + 20) = *(_DWORD *)(*(_DWORD *)(v21 + 28) + 128);
    if ( HIBYTE(loadedSeparately) != 0 )
      v22 = 0;
    else
      v22 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 36) + 20))(a1: *((_DWORD *)this + 36));
    *(_DWORD *)(*((_DWORD *)this + 112) + 16) = v22;
    v23 = *(int (__thiscall **)(int, int, _IMAGE_SECTION_HEADER::<unnamed_type_Misc> *))(*(_DWORD *)v17 + 40);
    pbindingDefImpl.PhysicalAddress = 326;
    v24 = (CDefaultClientRenderable *)v23(a1: v17, a2: 52, a3: &pbindingDefImpl);
    if ( v24 != nullptr )
    {
      LOBYTE(v25) = GFxFontManager::GFxFontManager(this: v24);
      loadedSeparately = v25;
    }
    else
    {
      loadedSeparately = 0;
    }
    v26 = *((_DWORD *)this + 112);
    v27 = *(GRefCountNTSImpl **)(v26 + 28);
    if ( v27 != nullptr )
      GRefCountNTSImpl::Release(this: v27);
    *(_DWORD *)(v26 + 28) = loadedSeparately;
    v28 = *((_DWORD *)this + 47);
    v29 = *(_DWORD *)(v28 + 60);
    v30 = *((_DWORD **)this + 112);
    v28 += 56;
    v30[1] = v29;
    *v30 = v28;
    **(_DWORD **)(v28 + 4) = v30;
    *(_DWORD *)(v28 + 4) = v30;
  }
LABEL_35:
  v31 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 46) + 40))(a1: *((_DWORD *)this + 46));
  v32 = v31;
  v33 = (ICvar *)this + 55;
  if ( v31 >= *((_DWORD *)this + 56) )
  {
    if ( v31 >= *((_DWORD *)this + 57) )
      GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
        this: v33,
        pheapAddr: (ConVar *)((char *)this + 220),
        newCapacity: v31 + (v31 >> 2),
        a4: v39);
  }
  else if ( v31 < *((_DWORD *)this + 57) >> 1 )
  {
    GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
      this: v33,
      pheapAddr: (ConVar *)((char *)this + 220),
      newCapacity: v31,
      a4: v39);
  }
  *((_DWORD *)this + 56) = v32;
  memset(dst: *((unsigned __int8 **)this + 55), value: 0, count: v32);
  GFxASCharacter::GetGC((CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this);
  ActualPrototype = GASGlobalContext::GetActualPrototype(this: v34, a2: (struct GASEnvironment *)(this + 29), a3: 6);
  v36 = ActualPrototype;
  if ( ActualPrototype != 0 )
    *(_DWORD *)(ActualPrototype + 8) = (*(_DWORD *)(ActualPrototype + 8) + 1) & 0x8FFFFFFF;
  v37 = *((_DWORD *)this + 32);
  if ( v37 != 0 )
    GRefCountBaseGC<323>::Release(a1: v37, a2: ActualPrototype);
  *((_DWORD *)this + 32) = v36;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B9CF0
// Name: public: virtual struct GFxScale9Grid const __near * GFxSprite::GetScale9Grid(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSprite::GetScale9Grid(_DWORD *this)
{
  return *(this + 48);
}

//------------------------------------------------------------------------------
// Address: 0x100B9D00
// Name: public: virtual class GASEnvironment __near * GFxSprite::GetASEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::GetASEnvironment(GFxTestStream *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100B9D10
// Name: public: virtual unsigned int GFxSprite::GetCurrentFrame(void)const
// Source: json
//------------------------------------------------------------------------------
const GPtr<GFxZlibSupportBase> *__thiscall GFxSprite::GetCurrentFrame(_DWORD *this)
{
  return (const GPtr<GFxZlibSupportBase> *)*(this + 54);
}

//------------------------------------------------------------------------------
// Address: 0x100B9D20
// Name: public: virtual bool GFxSprite::HasLooped(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxSprite::HasLooped(GFxSprite *this)
{
  return (*(_BYTE *)(this + 120) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B9D60
// Name: public: virtual class GFxCharacterDef __near * GFxSprite::GetCharacterDef(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::GetCharacterDef(GFxTestStream *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100B9D70
// Name: public: virtual bool GFxSprite::GetLabeledFrame(char const __near *,unsigned int __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxSprite::GetLabeledFrame(GFxSprite *this, const char *a2, unsigned int *a3, int a4)
{
  return ((bool (__thiscall *)(_DWORD, const char *, unsigned int *, int))(*(this + 46))->__vftable[6].OnDestroy)(
           a1: *(this + 46),
           a2,
           a3,
           a4);
}

//------------------------------------------------------------------------------
// Address: 0x100B9D90
// Name: public: virtual void GFxSprite::GetBounds(class GPoint<float> __near *,class GMatrix3D const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::GetBounds(GPtr<GFxZlibSupportBase> *this, GFxZlibSupportBase *pts, int a3, int bDivideByW)
{
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st6
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> r; // [esp+0h] [ebp-10h] BYREF
  GFxState::StateType v9; // [esp+Ch] [ebp-4h]

  ((void (__thiscall *)(GPtr<GFxZlibSupportBase> *, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *, int, int))this->pObject[5].__vftable)(
    a1: this,
    a2: &r,
    a3,
    a4: bDivideByW);
  v4 = *(float *)&r.m_pMemory;
  pts->__vftable = (GFxZlibSupportBase_vtbl *)r.m_pMemory;
  v5 = *(float *)&r.m_nAllocationCount;
  pts->RefCount = r.m_nAllocationCount;
  v6 = *(float *)&r.m_nGrowSize;
  pts->SType = (GFxState::StateType)r.m_nGrowSize;
  *(float *)&pts[1].__vftable = v5;
  *(float *)&pts[1].RefCount = v6;
  v7 = *(float *)&v9;
  pts[1].SType = v9;
  *(float *)&pts[2].RefCount = v7;
  *(float *)&pts[2].__vftable = v4;
}

//------------------------------------------------------------------------------
// Address: 0x100B9DE0
// Name: public: virtual bool GFxSprite::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSprite::GetMember(
        int a1@<ecx>,
        double a2@<st0>,
        GFxFontLib *result,
        _IMAGE_SYMBOL_EX *name,
        MaterialPrimitiveType_t *a5)
{
  GFxSprite::GetMember(
    this: (GFxFontLib *)(a1 - 120),
    a2,
    penv: (struct GStringHash<GString,GAllocatorGH<GString,2> > *)result,
    name: nullptr,
    pcaseInsensitiveName: name,
    memberName: a5);
}

//------------------------------------------------------------------------------
// Address: 0x100B9E00
// Name: public: virtual bool GFxSprite::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSprite::GetMemberRaw(
        GFxSprite *this@<ecx>,
        double a2@<st0>,
        _IMAGE_SYMBOL_EX *a3,
        _IMAGE_SYMBOL_EX *a4,
        MaterialPrimitiveType_t *a5)
{
  GFxSprite::GetMember(
    this: (GFxFontLib *)(this - 30),
    a2,
    penv: nullptr,
    name: a3,
    pcaseInsensitiveName: a4,
    memberName: a5);
}

//------------------------------------------------------------------------------
// Address: 0x100B9E20
// Name: public: virtual GFxSprite::~GFxSprite(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxSprite::~GFxSprite(
        GFxFontLib *this@<ecx>,
        CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *a2@<ebx>,
        int a3@<edi>)
{
  bool v4; // zf
  GPtr<GFxZlibSupportBase> *v5; // ecx
  int v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // edi
  GRefCountNTSImpl *v9; // ecx
  void *v10; // edi
  void *v11; // edi
  GFxCharacterHandle *v12; // edi
  GRefCountNTSImpl *v13; // ecx
  int v14; // ecx
  int v15; // eax
  GRefCountNTSImpl **v16; // edi
  IShaderDevice *v17; // ecx
  int v19; // [esp+4h] [ebp-4h]

  v4 = *((_DWORD *)this + 116) == 0;
  this->__vftable = (GFxFontLib_vtbl *)&GFxSprite::`vftable'{for `GRefCountBaseWeakSupport<GFxCharacter,322>'};
  this->pImpl = (struct GFxFontLibImpl *)&GFxSprite::`vftable'{for `GFxLogBase<GFxCharacter>'};
  *((_DWORD *)this + 30) = &GFxSprite::`vftable';
  if ( !v4 )
  {
    if ( !GFxASCharacter::IsUsedAsMask((GFxASCharacter *)this) )
    {
      if ( *((_DWORD *)this + 116) == 0 )
        goto LABEL_9;
      GFxSprite::SetMask((GPtr<GFxZlibSupportBase> *)this, result: nullptr);
    }
    if ( *((_DWORD *)this + 116) != 0
      && ((unsigned __int8 (__thiscall *)(GFxFontLib *))this->__vftable[22].FindFont)(a1: this) != 0 )
    {
      v5 = *((GPtr<GFxZlibSupportBase> **)this + 116);
      if ( v5 != nullptr )
        GFxSprite::SetMask(this: v5, result: nullptr);
    }
  }
LABEL_9:
  v6 = *((_DWORD *)this + 112);
  if ( v6 != 0 )
  {
    --*(_DWORD *)(v6 + 8);
    v7 = *((_DWORD **)this + 112);
    if ( v7[2] == 0 )
    {
      *(_DWORD *)(*v7 + 4) = v7[1];
      *(_DWORD *)v7[1] = *v7;
      v8 = *((_DWORD **)this + 112);
      if ( v8 != nullptr )
      {
        v9 = (GRefCountNTSImpl *)v8[7];
        if ( v9 != nullptr )
          GRefCountNTSImpl::Release(this: v9);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
      }
    }
  }
  v10 = *((void **)this + 114);
  if ( v10 != nullptr )
  {
    GFxSprite::ActiveSounds::~ActiveSounds(this: *((CD3D11_BLEND_DESC **)this + 114));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
  }
  GFxDisplayList::Clear(pheapAddr: (IMorph *)this + 49);
  *(_DWORD *)(*((_DWORD *)this + 47) + 9332) |= 0x400u;
  ((void (__thiscall *)(GMemoryHeap *, _DWORD, int))GMemory::pGlobalHeap->Free)(
    a1: GMemory::pGlobalHeap,
    a2: *((_DWORD *)this + 48),
    a3);
  v11 = *((void **)this + 119);
  if ( v11 != nullptr )
  {
    v4 = (*(_DWORD *)(*(_DWORD *)v11 + 8))-- == 1;
    if ( v4 )
      GASStringNode::ReleaseNode();
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
  }
  v12 = *((GFxCharacterHandle **)this + 117);
  if ( v12 != nullptr )
  {
    *v12 = (GFxCharacterHandle)((char *)*v12 - 1);
    if ( (int)*v12 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v12);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v12);
    }
  }
  v13 = *((GRefCountNTSImpl **)this + 115);
  if ( v13 != nullptr )
    GRefCountNTSImpl::Release(this: v13);
  v14 = *((_DWORD *)this + 113);
  if ( v14 != 0 )
    GRefCountBaseGC<323>::Release(a1: v14, a2: (int)v12);
  GASEnvironment::~GASEnvironment(this: (GASEnvironment *)this + 58);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 55));
  v15 = *((_DWORD *)this + 50);
  v16 = (GRefCountNTSImpl **)(*((_DWORD *)this + 49) + 4 * v15 - 4);
  if ( v15 != 0 )
  {
    v19 = *((_DWORD *)this + 50);
    do
    {
      if ( *v16 != nullptr )
        GRefCountNTSImpl::Release(this: *v16);
      --v16;
      --v19;
    }
    while ( v19 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 49));
  v17 = *((IShaderDevice **)this + 46);
  if ( v17 != nullptr )
    GFxResource::Release(this: v17);
  GFxASCharacter::~GFxASCharacter((GFxASCharacter *)this, a2: (GFxMovie *)this, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x100BA010
// Name: public: class GFxCharacter __near * GFxSprite::AddDisplayObject(class GFxCharPosInfo const __near &,class GASString const __near &,class GArrayLH<class GFxSwfEvent __near *,260,struct GArrayDefaultPolicy> const __near *,class GASObjectInterface const __near *,unsigned int,unsigned long,struct GFxCharacterCreateInfo __near *,class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
GFxMeshCacheManager_vtbl *__thiscall GFxSprite::AddDisplayObject(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *this,
        _IMAGE_SYMBOL_EX *name,
        int a3,
        GFxRenderGen *a4,
        struct GASObjectInterface *a5,
        GRendererEventHandler *createFrame,
        unsigned int addFlags,
        IndexDesc_t *rh,
        volatile int a9)
{
  IndexDesc_t *v10; // eax
  unsigned __int16 *m_pIndices; // ecx
  unsigned int m_nOffset; // eax
  int v13; // eax
  int Type; // esi
  CMatPaintmaps *SectionNumber; // edx
  _DWORD *v17; // eax
  _DWORD *v18; // esi
  int v19; // eax
  int v20; // edi
  GRendererEventHandler *v21; // eax
  bool v22; // zf
  char *v23; // eax
  GRendererEventHandler *pRenEventHandler; // edx
  int v25; // edi
  CMatQueuedIndexBuffer *v26; // esi
  CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v27; // eax
  void (__thiscall *v28)(int); // eax
  GRendererEventHandler *pNext; // eax
  GRendererEventHandler *v30; // ecx
  void (__thiscall *OnEvent)(GRendererEventHandler *, GRenderer *, GRendererEventHandler::EventType); // edx
  _KCRM_MARSHAL_HEADER *v32; // eax
  unsigned int pHeap; // edi
  const GFxValue::ObjectInterface *MovieClipObject; // eax
  _DWORD *v35; // eax
  int v36; // eax
  const GPoint3<float> *inserted; // edi
  GRefCountNTSImpl *z_low; // ecx
  GRefCountNTSImpl *x_low; // ecx
  int v40; // ecx
  float v41; // edx
  float v42; // eax
  float v43; // ecx
  _KCRM_MARSHAL_HEADER *v44; // eax
  int v45; // ecx
  int v46; // edx
  CMatQueuedIndexBuffer *v47; // eax
  CMatQueuedIndexBuffer *NameOfExportedResource; // edi
  int v49; // eax
  struct GASStringNode *StringNode; // eax
  GRendererEventHandler *v51; // ecx
  _IMAGE_SYMBOL_EX *v52; // eax
  GPtr<IDirect3DPixelShader9> *v53; // edi
  GRefCountNTSImpl *v54; // ecx
  GRefCountNTSImpl *v55; // ecx
  const GPoint3<float> *v56; // eax
  _DWORD *v57; // edi
  GRefCountNTSImpl *v58; // ecx
  GRefCountNTSImpl *v59; // ecx
  int v60; // edx
  int v61; // eax
  int v62; // ecx
  int v63; // edx
  struct GASObjectInterface *v64; // edi
  const GPoint3<float> *v65; // eax
  GPtr<IDirect3DPixelShader9> *v66; // edi
  GRefCountNTSImpl *v67; // ecx
  GRefCountNTSImpl *v68; // ecx
  const GPoint3<float> *v69; // eax
  _DWORD *v70; // edi
  GRefCountNTSImpl *v71; // ecx
  GRefCountNTSImpl *v72; // ecx
  GPtr<IDirect3DPixelShader9> *p_params; // ecx
  const GPoint3<float> *v74; // eax
  GPtr<IDirect3DPixelShader9> *v75; // edi
  GRefCountNTSImpl *v76; // ecx
  GRefCountNTSImpl *v77; // ecx
  const GPoint3<float> *v78; // eax
  _DWORD *p_x; // edi
  GRefCountNTSImpl *v80; // ecx
  GRefCountNTSImpl *v81; // ecx
  int v82; // eax
  int v83; // ecx
  int v84; // edx
  int v85; // eax
  const GPoint3<float> *v86; // eax
  GPtr<IDirect3DPixelShader9> *v87; // edi
  GRefCountNTSImpl *v88; // ecx
  GRefCountNTSImpl *pObject; // ecx
  CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v90; // edi
  void (__thiscall *BeginCastBuffer)(struct CMatQueuedIndexBuffer *, MaterialIndexFormat_t); // edx
  int v92; // eax
  GFxSprite *v93; // edi
  GFxMeshCacheManager_vtbl *v94; // esi
  _BYTE v95[24]; // [esp-8h] [ebp-164h] BYREF
  GASValue v96[4]; // [esp+14h] [ebp-148h] BYREF
  GASValue v[4]; // [esp+24h] [ebp-138h] BYREF
  GASValue v98[4]; // [esp+34h] [ebp-128h] BYREF
  GASValue v99[4]; // [esp+44h] [ebp-118h] BYREF
  GPtr<IDirect3DPixelShader9> v100; // [esp+54h] [ebp-108h] BYREF
  int v101; // [esp+58h] [ebp-104h]
  int v102; // [esp+5Ch] [ebp-100h]
  _DWORD v103[2]; // [esp+60h] [ebp-FCh] BYREF
  __int16 v104; // [esp+68h] [ebp-F4h]
  int v105; // [esp+6Ah] [ebp-F2h]
  unsigned __int16 *v106; // [esp+70h] [ebp-ECh]
  unsigned int v107; // [esp+74h] [ebp-E8h]
  int v108; // [esp+78h] [ebp-E4h]
  int v109; // [esp+7Ch] [ebp-E0h]
  __int64 v110; // [esp+80h] [ebp-DCh]
  int v111; // [esp+88h] [ebp-D4h]
  int v112; // [esp+8Ch] [ebp-D0h]
  __int64 v113; // [esp+90h] [ebp-CCh]
  int v114; // [esp+98h] [ebp-C4h]
  float v115; // [esp+9Ch] [ebp-C0h]
  __int64 v116; // [esp+A0h] [ebp-BCh]
  struct GASObjectInterface *v117; // [esp+A8h] [ebp-B4h]
  GPtr<IDirect3DPixelShader9> v118; // [esp+ACh] [ebp-B0h] BYREF
  int v119; // [esp+B0h] [ebp-ACh]
  int v120; // [esp+B4h] [ebp-A8h]
  int v121; // [esp+B8h] [ebp-A4h] BYREF
  int v122; // [esp+BCh] [ebp-A0h]
  char v123; // [esp+C0h] [ebp-9Ch]
  const IDirect3DPixelShader9 *params; // [esp+C4h] [ebp-98h] BYREF
  int v125; // [esp+C8h] [ebp-94h]
  int v126; // [esp+CCh] [ebp-90h]
  unsigned int oldSessionId; // [esp+D0h] [ebp-8Ch] BYREF
  _KCRM_MARSHAL_HEADER *gctxt; // [esp+D4h] [ebp-88h]
  int v129; // [esp+D8h] [ebp-84h]
  GFxSprite *v130; // [esp+DCh] [ebp-80h]
  GFxMeshCacheManager key; // [esp+E0h] [ebp-7Ch] BYREF
  CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v132; // [esp+FCh] [ebp-60h]
  bool nameSet; // [esp+100h] [ebp-5Ch]
  bool replaceIfDepthIsOccupied; // [esp+101h] [ebp-5Bh]
  bool placeObject; // [esp+102h] [ebp-5Ah]
  bool animatedByTimeline; // [esp+103h] [ebp-59h]
  CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> newPos; // [esp+104h] [ebp-58h] BYREF
  char v138; // [esp+156h] [ebp-6h]
  char v139; // [esp+157h] [ebp-5h]
  unsigned int addFlagsa; // [esp+178h] [ebp+1Ch]

  v129 = a3;
  key.RefCount = a9;
  v117 = a5;
  key.pRenderGen = a4;
  key.pRenEventHandler = (GRendererEventHandler *)this;
  key.SType = (GFxState::StateType)name;
  placeObject = (addFlags & 4) != 0;
  replaceIfDepthIsOccupied = addFlags & 1;
  if ( rh != nullptr )
  {
    v10 = rh;
  }
  else
  {
    *(_DWORD *)&v95[4] = 0;
    GFxMovieDefImpl::GetCharacterCreateInfo(
      this: *((CMatQueuedIndexBuffer **)this + 36),
      rid: (_RATE_QUOTA_LIMIT *)&v95[20],
      rh: *(const IndexDesc_t **)&name[3].Type);
  }
  m_pIndices = v10->m_pIndices;
  m_nOffset = v10->m_nOffset;
  v106 = m_pIndices;
  v107 = m_nOffset;
  if ( m_pIndices == nullptr )
  {
    v13 = *((_DWORD *)this + 37);
    Type = name[3].Type;
    if ( v13 == 0 )
      GFxASCharacter::CreateCharacterHandle(this);
    GFxLogBase<GFxCharacter>::LogError(
      a1: (int)&this->m_pfnProxied + 12,
      a2: (int)"%s, GFxSprite::AddDisplayObject(): unknown cid = %d\n",
      **(const char ***)(v13 + 12),
      Type);
    return nullptr;
  }
  SectionNumber = (CMatPaintmaps *)name[3].SectionNumber;
  *(_DWORD *)&v95[4] = (char *)&key.pMeshCache + 3;
  HIBYTE(key.pMeshCache) = 0;
  GFxDisplayList::GetCharacterAtDepth(
    this: (CMemberFuncProxy0<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *)((char *)this + 196),
    depth: SectionNumber,
    pisMarkedForRemove: *(__int128 *)&v95[4]);
  v18 = v17;
  if ( !placeObject )
  {
    replaceIfDepthIsOccupied = true;
    goto LABEL_49;
  }
  animatedByTimeline = true;
  if ( v17 != nullptr )
  {
    animatedByTimeline = (*(int (__thiscall **)(_DWORD *))(*v17 + 28))(a1: v17);
    if ( !animatedByTimeline && (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v18 + 24))(a1: v18) != 0 )
    {
      (*(void (__thiscall **)(_DWORD *, int))(*v18 + 32))(a1: v18, a2: 1);
      animatedByTimeline = true;
    }
  }
  if ( HIBYTE(key.pMeshCache) == 0 )
  {
    if ( v18 == nullptr )
      goto LABEL_49;
    if ( !animatedByTimeline )
      return nullptr;
  }
  if ( v18 == nullptr || (int)v18[5] < -1 || v18[4] != *(_DWORD *)(key.SType + 76) )
    goto LABEL_49;
  if ( *((char *)v18 + 118) >= 0 )
    v19 = *((_DWORD *)this + 88) + 8;
  else
    GFxASCharacter::GetOriginalName(this: (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v18);
  v20 = *(_DWORD *)v19;
  key.__vftable = (GFxMeshCacheManager_vtbl *)(*(_DWORD *)(*(_DWORD *)v19 + 8) + 1);
  *(_DWORD *)(v20 + 8) = key.__vftable;
  if ( *((char *)v18 + 118) < 0 )
  {
    if ( *(_DWORD *)(*(_DWORD *)v129 + 16) != 0 )
    {
      if ( v20 != *(_DWORD *)v129 )
        goto LABEL_46;
    }
    else if ( *(_DWORD *)(v20 + 16) != 0 && (v18[40] & 0x4000) == 0 )
    {
LABEL_46:
      v23 = (char *)&key.__vftable[-1].dtr_GRefCountImplCore + 3;
      *(_DWORD *)(v20 + 8) = (char *)key.__vftable - 1;
      if ( v23 == nullptr )
        GASStringNode::ReleaseNode();
LABEL_49:
      pRenEventHandler = key.pRenEventHandler;
      key.pRenEventHandler[11].pRenderer[233].Handlers.Root.pNext = (GRendererEventHandler *)((int)key.pRenEventHandler[11].pRenderer[233].Handlers.Root.pNext
                                                                                            | 0x400);
      v25 = (*(int (__thiscall **)(unsigned __int16 *, GRendererEventHandler *, _DWORD, unsigned int))(*(_DWORD *)v106 + 36))(
              a1: v106,
              a2: pRenEventHandler,
              a3: *(_DWORD *)(key.SType + 76),
              a4: v107);
      v26 = *(_BYTE *)(v25 + 118) >> 7 != 0 ? (CMatQueuedIndexBuffer *)v25 : nullptr;
      key.__vftable = (GFxMeshCacheManager_vtbl *)v25;
      if ( v26 != nullptr )
        v130 = (GFxSprite *)GASObjectInterface::ToSprite(result: *(_TAPE_WMI_OPERATIONS **)&v95[8]);
      else
        v130 = nullptr;
      v27 = *(CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **)(v25 + 32);
      *(_WORD *)(v25 + 118) &= ~1u;
      nameSet = false;
      v132 = v27;
      if ( v27 != nullptr )
      {
        while ( (*(int (__thiscall **)(CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *))(LODWORD(v132->m_pfnProxied) + 76))(a1: v132) == 0 )
        {
          v132 = (CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)DWORD2(v132[1].m_pfnProxied);
          if ( v132 == nullptr )
            goto LABEL_57;
        }
        v28 = *(void (__thiscall **)(int))(*(_DWORD *)v25 + 80);
        *(_WORD *)(v25 + 118) |= 1u;
        v28(a1: v25);
      }
LABEL_57:
      if ( v26 != nullptr )
      {
        if ( *(_DWORD *)(*(_DWORD *)v129 + 16) != 0 )
        {
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v25 + 44))(a1: v25, a2: v129);
          nameSet = true;
        }
        if ( key.RefCount != 0 )
          ((void (__thiscall *)(CMatQueuedIndexBuffer *, volatile int))v26->__vftable[4].Lock)(
            a1: v26,
            a2: key.RefCount);
        if ( (addFlags & 4) != 0 )
          HIWORD(v26[2].m_pRTDynamicIndexBuffer) |= 0x200u;
        else
          ((void (__thiscall *)(CMatQueuedIndexBuffer *, _DWORD))v26->ModifyBegin)(a1: v26, a2: 0);
      }
      if ( (addFlags & 4) != 0 )
        *(_WORD *)(v25 + 118) |= 0x200u;
      pNext = createFrame;
      if ( createFrame == (GRendererEventHandler *)-1 )
        pNext = key.pRenEventHandler[13].pNext;
      v30 = key.pRenEventHandler;
      *(_DWORD *)(v25 + 24) = pNext;
      OnEvent = v30->__vftable[10].OnEvent;
      animatedByTimeline = true;
      v132 = (CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)((int (__thiscall *)(GRendererEventHandler *))OnEvent)(a1: v30);
      if ( v26 != nullptr && key.pRenderGen != nullptr )
      {
        v32 = *((_KCRM_MARSHAL_HEADER **)key.pRenderGen + 1);
        pHeap = 0;
        key.pHeap = nullptr;
        gctxt = v32;
        if ( v32 != nullptr )
        {
          do
          {
            GFxSwfEvent::AttachTo(
              this: *(CMemberFuncProxy3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CFuncMemPolicyNone> **)(*(_DWORD *)key.pRenderGen + 4 * pHeap),
              a2: pHeap,
              a3: (int)v26,
              ch: v26,
              method: *(__int128 *)&v95[8]);
            if ( v130 != nullptr && (**(_DWORD **)(*(_DWORD *)key.pRenderGen + 4 * pHeap) & 0xFBFC00) != 0 )
            {
              MovieClipObject = GFxSprite::GetMovieClipObject(this: (GRefCountWeakSupportImpl *)v130);
              if ( MovieClipObject != nullptr )
                BYTE2(MovieClipObject[14].pMovieRoot) = 1;
            }
            if ( placeObject )
            {
              v35 = *(_DWORD **)(*(_DWORD *)key.pRenderGen + 4 * pHeap);
              if ( *v35 == 512 )
              {
                v36 = v35[4];
                if ( v36 != 0 && *(_DWORD *)(v36 + 12) != 0 && **(_BYTE **)(v36 + 8) != 0 )
                {
                  inserted = GFxMovieRoot::ActionQueueType::InsertEntry(
                               this: (int)&v132[384].m_pfnProxied + 8,
                               result: (const GPoint3<float> *)1);
                  if ( inserted != nullptr )
                  {
                    LODWORD(inserted->y) = 2;
                    v114 = 512;
                    v115 = 0.0;
                    LOWORD(v116) = 0;
                    *(_DWORD *)((char *)&v116 + 2) = 65280;
                    ++v26->m_pOwner;
                    z_low = (GRefCountNTSImpl *)LODWORD(inserted->z);
                    if ( z_low != nullptr )
                      GRefCountNTSImpl::Release(this: z_low);
                    LODWORD(inserted->z) = v26;
                    x_low = (GRefCountNTSImpl *)LODWORD(inserted[1].x);
                    if ( x_low != nullptr )
                      GRefCountNTSImpl::Release(this: x_low);
                    v40 = v114;
                    v41 = v115;
                    v42 = *(float *)&v116;
                    inserted[1].x = 0.0;
                    LODWORD(inserted[1].y) = v40;
                    v43 = *((float *)&v116 + 1);
                    inserted[1].z = v41;
                    inserted[2].x = v42;
                    inserted[2].y = v43;
                  }
                  pHeap = (unsigned int)key.pHeap;
                }
              }
            }
            key.pHeap = (GMemoryHeap *)++pHeap;
          }
          while ( pHeap < (unsigned int)gctxt );
        }
      }
      key.pRenderGen = nullptr;
      if ( v26 == nullptr )
      {
        v90 = v132;
LABEL_160:
        addFlagsa = addFlags & 0xFFFFFFFE;
        if ( replaceIfDepthIsOccupied )
          addFlagsa |= 1u;
        if ( v26 != nullptr )
        {
          GFxASCharacter::AddToPlayList(this: v26, result: v90);
          BeginCastBuffer = v26->__vftable[5].BeginCastBuffer;
          LOBYTE(oldSessionId) = ((int)v26[4].__vftable & 0x80000) != 0;
          v92 = ((int (__thiscall *)(CMatQueuedIndexBuffer *, unsigned int))BeginCastBuffer)(a1: v26, a2: oldSessionId);
          if ( v92 == -1 )
          {
            GFxASCharacter::RemoveFromOptimizedPlaylist(this: (CMatQueuedMesh **)v26, result: v90);
          }
          else if ( v92 == 1 )
          {
            GFxASCharacter::AddToOptimizedPlayList(this: (int)v26, result: v90);
          }
        }
        *(_DWORD *)&v95[4] = addFlagsa;
        *(_DWORD *)v95 = key.__vftable;
        GFxDisplayList::AddDisplayObject(
          this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)&key.pRenEventHandler[12].GListNode<GRendererEventHandler>,
          pos: (CLateBoundPtr<IMesh>)key.SType,
          ch: *(__int128 *)v95,
          addFlags: *(IMesh *const **)&v95[16],
          di: *(const int **)&v95[20]);
        if ( nameSet )
          GFxMovieRoot::ResolveStickyVariables(
            this: v90,
            a2: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v26);
        if ( v26 == nullptr || placeObject )
        {
          if ( v130 != nullptr )
            *((_BYTE *)v130 + 480) |= 0x80u;
        }
        else
        {
          GFxMovieRoot::DoActionsForSession(this: (GFxMovieRoot *)v90, a2: (unsigned int)key.pRenderGen);
          v93 = v130;
          if ( v130 != nullptr )
          {
            v104 = 0;
            v103[0] = 1;
            v103[1] = 0;
            v105 = 65280;
            if ( GFxSprite::HasEventHandler(this: v130, a2: (const struct GFxEventId *)v103) != 0 )
              *((_BYTE *)v93 + 480) |= 0x80u;
          }
        }
        if ( v26 != nullptr
          && nameSet
          && *(void (__thiscall **)(GRendererEventHandler *, GRenderer *, GRendererEventHandler::EventType))v129 == key.pRenEventHandler[22].__vftable[68].OnEvent )
        {
          GFxSprite::SetHitArea(
            this: (int)key.pRenEventHandler,
            result: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v26);
        }
        v94 = key.__vftable;
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)key.__vftable);
        return v94;
      }
      v44 = (_KCRM_MARSHAL_HEADER *)((int (__thiscall *)(GRendererEventHandler *))key.pRenEventHandler->__vftable[26].dtr_GRendererEventHandler)(a1: key.pRenEventHandler);
      *(_DWORD *)&v95[4] = v45;
      v46 = *((_DWORD *)v106 + 3);
      gctxt = v44;
      v123 = 0;
      v121 = 0;
      v122 = 0;
      *(_DWORD *)&v95[4] = v46;
      v47 = (CMatQueuedIndexBuffer *)(*((int (__thiscall **)(GFxMeshCacheManager_vtbl *))key.dtr_GRefCountImplCore + 23))(a1: key.__vftable);
      NameOfExportedResource = GFxMovieDefImpl::GetNameOfExportedResource(
                                 this: v47,
                                 rid: *(const CMatQueuedIndexBuffer **)&v95[4]);
      key.pRenderGen = (GFxRenderGen *)GFxMovieRoot::ActionQueueType::StartNewSession(
                                         this: (GFxMovieRoot::ActionQueueType *)((char *)&v132[384].m_pfnProxied + 8),
                                         a2: &oldSessionId);
      BYTE2(key.pMeshCache) = 0;
      if ( NameOfExportedResource == nullptr )
      {
LABEL_135:
        if ( placeObject )
        {
          if ( animatedByTimeline )
          {
            v78 = GFxMovieRoot::ActionQueueType::InsertEntry(
                    this: (int)&v132[384].m_pfnProxied + 8,
                    result: (const GPoint3<float> *)3);
            p_x = (_DWORD *)&v78->x;
            if ( v78 != nullptr )
            {
              LODWORD(v78->y) = 2;
              v108 = 0x40000;
              v109 = 0;
              LOWORD(v110) = 0;
              *(_DWORD *)((char *)&v110 + 2) = 65280;
              ++v26->m_pOwner;
              v80 = (GRefCountNTSImpl *)LODWORD(v78->z);
              if ( v80 != nullptr )
                GRefCountNTSImpl::Release(this: v80);
              p_x[2] = v26;
              v81 = (GRefCountNTSImpl *)p_x[3];
              if ( v81 != nullptr )
                GRefCountNTSImpl::Release(this: v81);
              v82 = v108;
              v83 = v109;
              v84 = v110;
              p_x[3] = 0;
              p_x[4] = v82;
              v85 = HIDWORD(v110);
              p_x[5] = v83;
              p_x[6] = v84;
              p_x[7] = v85;
            }
          }
        }
        else if ( BYTE2(key.pMeshCache) == 0
               && (unsigned int)GFxCharacter::GetVersion(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)key.pRenEventHandler) >= 6
               && v117 != nullptr )
        {
          v100.pObject = nullptr;
          v101 = 0;
          v102 = 0;
          LOBYTE(v98[0]) = 0;
          GASValue::SetAsObjectInterface(this: v98, a2: v117);
          GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::PushBack(
            this: &v100,
            a2: (const struct GASValue *)v98);
          v86 = GFxMovieRoot::ActionQueueType::InsertEntry(
                  this: (int)&v132[384].m_pfnProxied + 8,
                  result: (const GPoint3<float> *)3);
          v87 = (GPtr<IDirect3DPixelShader9> *)v86;
          if ( v86 != nullptr )
          {
            LODWORD(v86->y) = 4;
            ++v26->m_pOwner;
            v88 = (GRefCountNTSImpl *)LODWORD(v86->z);
            if ( v88 != nullptr )
              GRefCountNTSImpl::Release(this: v88);
            v87[2].pObject = (IDirect3DPixelShader9 *)v26;
            pObject = (GRefCountNTSImpl *)v87[3].pObject;
            if ( pObject != nullptr )
              GRefCountNTSImpl::Release(this: pObject);
            v87[3].pObject = nullptr;
            *(_DWORD *)&v95[4] = &v100;
            v87[11].pObject = (IDirect3DPixelShader9 *)GFx_InitObjectMembers;
            GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::operator=(
              this: v87 + 12,
              a2: *(_DWORD **)&v95[4]);
          }
          GASValue::~GASValue(this: v98);
          GArray<GASValue,2,GArrayDefaultPolicy>::~GArray<GASValue,2,GArrayDefaultPolicy>(this: &v100);
        }
        v22 = (v123 & 2) == 0;
        v90 = v132;
        v132[387].m_pObject = (CMatQueuedMesh *)oldSessionId;
        if ( v22 && v121 != 0 )
          GRefCountBaseGC<323>::Release(a1: v121, a2: (int)v90);
        v121 = 0;
        if ( (v123 & 1) == 0 && v122 != 0 )
          GRefCountBaseGC<323>::Release(a1: v122, a2: (int)v90);
        goto LABEL_160;
      }
      v49 = ((int (__thiscall *)(GRendererEventHandler *))key.pRenEventHandler->__vftable[14].dtr_GRendererEventHandler)(a1: key.pRenEventHandler);
      StringNode = GASStringManager::CreateStringNode(
                     this: *(GASStringManager **)(*(_DWORD *)(v49 + 120) + 636),
                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)NameOfExportedResource->__vftable
                                                                                               & 0xFFFFFFFC)
                                                                                              + 8),
                     length: *(_DWORD *)((int)NameOfExportedResource->__vftable & 0xFFFFFFFC) & 0x7FFFFFFF);
      v51 = key.pRenEventHandler;
      key.RefCount = (volatile int)StringNode;
      ++*((_DWORD *)StringNode + 2);
      v52 = (_IMAGE_SYMBOL_EX *)((int (__thiscall *)(GRendererEventHandler *))v51->__vftable[14].dtr_GRendererEventHandler)(a1: v51);
      if ( GASGlobalContext::FindRegisteredClass(
             this: (GFxMeshCacheManager *)gctxt,
             className: v52 + 6,
             key: (_IMAGE_SYMBOL_EX *)&key.RefCount,
             a4: (struct GASFunctionRef *)&v121) != 0 )
      {
        params = nullptr;
        v125 = 0;
        v126 = 0;
        key.pHeap = (GMemoryHeap *)((char *)&v132[384].m_pfnProxied + 8);
        v53 = (GPtr<IDirect3DPixelShader9> *)GFxMovieRoot::ActionQueueType::InsertEntry(
                                               this: (int)&v132[384].m_pfnProxied + 8,
                                               result: (const GPoint3<float> *)1);
        GASValue::GASValue(this: v96, a2: (const struct GASFunctionRef *)&v121);
        GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
          this: (GPtr<IDirect3DPixelShader9> *)&params,
          pheapAddr: (ButtonCode_t)&params,
          newSize: 1u);
        if ( &params[4 * v125] != (const IDirect3DPixelShader9 *)16 )
          GASValue::GASValue(this: (GASValue *)&params[4 * v125 - 4], a2: (const struct GASValue *)v96);
        GASValue::~GASValue(this: v96);
        if ( v53 != nullptr )
        {
          v53[1].pObject = (IDirect3DPixelShader9 *)4;
          ++v26->m_pOwner;
          v54 = (GRefCountNTSImpl *)v53[2].pObject;
          if ( v54 != nullptr )
            GRefCountNTSImpl::Release(this: v54);
          v53[2].pObject = (IDirect3DPixelShader9 *)v26;
          v55 = (GRefCountNTSImpl *)v53[3].pObject;
          if ( v55 != nullptr )
            GRefCountNTSImpl::Release(this: v55);
          v53[3].pObject = nullptr;
          *(_DWORD *)&v95[4] = &params;
          v53[11].pObject = (IDirect3DPixelShader9 *)GFx_InitializeClassInstance;
          GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::operator=(
            this: v53 + 12,
            a2: *(_DWORD **)&v95[4]);
        }
        v56 = GFxMovieRoot::ActionQueueType::InsertEntry(this: (int)key.pHeap, result: (const GPoint3<float> *)3);
        v57 = (_DWORD *)&v56->x;
        if ( v56 != nullptr )
        {
          LOWORD(v113) = 0;
          LODWORD(v56->y) = 2;
          v111 = 0x40000;
          v112 = 0;
          *(_DWORD *)((char *)&v113 + 2) = 65280;
          ++v26->m_pOwner;
          v58 = (GRefCountNTSImpl *)LODWORD(v56->z);
          if ( v58 != nullptr )
            GRefCountNTSImpl::Release(this: v58);
          v57[2] = v26;
          v59 = (GRefCountNTSImpl *)v57[3];
          if ( v59 != nullptr )
            GRefCountNTSImpl::Release(this: v59);
          v60 = v111;
          v61 = v112;
          v62 = v113;
          v57[3] = 0;
          v57[4] = v60;
          v63 = HIDWORD(v113);
          v57[5] = v61;
          v57[6] = v62;
          v57[7] = v63;
        }
        animatedByTimeline = false;
        if ( (unsigned int)GFxCharacter::GetVersion(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)key.pRenEventHandler) >= 6 )
        {
          v64 = v117;
          if ( v117 != nullptr )
          {
            GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::Resize(
              this: (GPtr<IDirect3DPixelShader9> *)&params,
              newSize: 0);
            LOBYTE(v[0]) = 0;
            GASValue::SetAsObjectInterface(this: v, a2: v64);
            GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::PushBack(
              this: (GPtr<IDirect3DPixelShader9> *)&params,
              a2: (const struct GASValue *)v);
            v65 = GFxMovieRoot::ActionQueueType::InsertEntry(this: (int)key.pHeap, result: (const GPoint3<float> *)3);
            v66 = (GPtr<IDirect3DPixelShader9> *)v65;
            if ( v65 != nullptr )
            {
              LODWORD(v65->y) = 4;
              ++v26->m_pOwner;
              v67 = (GRefCountNTSImpl *)LODWORD(v65->z);
              if ( v67 != nullptr )
                GRefCountNTSImpl::Release(this: v67);
              v66[2].pObject = (IDirect3DPixelShader9 *)v26;
              v68 = (GRefCountNTSImpl *)v66[3].pObject;
              if ( v68 != nullptr )
                GRefCountNTSImpl::Release(this: v68);
              *(_DWORD *)&v95[4] = &params;
              v66[3].pObject = nullptr;
              v66[11].pObject = (IDirect3DPixelShader9 *)GFx_InitObjectMembers;
              GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::operator=(
                this: v66 + 12,
                a2: *(_DWORD **)&v95[4]);
            }
            GASValue::~GASValue(this: v);
          }
        }
        BYTE2(key.pMeshCache) = 1;
        v69 = GFxMovieRoot::ActionQueueType::InsertEntry(this: (int)key.pHeap, result: (const GPoint3<float> *)3);
        v70 = (_DWORD *)&v69->x;
        if ( v69 != nullptr )
        {
          LODWORD(v69->y) = 3;
          ++v26->m_pOwner;
          v71 = (GRefCountNTSImpl *)LODWORD(v69->z);
          if ( v71 != nullptr )
            GRefCountNTSImpl::Release(this: v71);
          v70[2] = v26;
          v72 = (GRefCountNTSImpl *)v70[3];
          if ( v72 != nullptr )
            GRefCountNTSImpl::Release(this: v72);
          *(_DWORD *)&v95[4] = &v121;
          v70[3] = 0;
          GASFunctionRefBase::Assign(
            this: (GASFunctionRefBase *)(v70 + 8),
            orig: *(const struct GASFunctionRefBase **)&v95[4]);
        }
        p_params = (GPtr<IDirect3DPixelShader9> *)&params;
      }
      else
      {
        if ( !placeObject )
          goto LABEL_133;
        v99[1] = (GASValue)key.RefCount;
        LOBYTE(v99[0]) = 5;
        ++*(_DWORD *)(key.RefCount + 8);
        v118.pObject = nullptr;
        v119 = 0;
        v120 = 0;
        GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
          this: &v118,
          pheapAddr: (ButtonCode_t)&v118,
          newSize: 1u);
        if ( &v118.pObject[4 * v119] != (IDirect3DPixelShader9 *)16 )
          GASValue::GASValue(this: (GASValue *)&v118.pObject[4 * v119 - 4], a2: (const struct GASValue *)v99);
        GASValue::~GASValue(this: v99);
        v74 = GFxMovieRoot::ActionQueueType::InsertEntry(
                this: (int)&v132[384].m_pfnProxied + 8,
                result: (const GPoint3<float> *)3);
        v75 = (GPtr<IDirect3DPixelShader9> *)v74;
        if ( v74 != nullptr )
        {
          LODWORD(v74->y) = 4;
          ++v26->m_pOwner;
          v76 = (GRefCountNTSImpl *)LODWORD(v74->z);
          if ( v76 != nullptr )
            GRefCountNTSImpl::Release(this: v76);
          v75[2].pObject = (IDirect3DPixelShader9 *)v26;
          v77 = (GRefCountNTSImpl *)v75[3].pObject;
          if ( v77 != nullptr )
            GRefCountNTSImpl::Release(this: v77);
          *(_DWORD *)&v95[4] = &v118;
          v75[3].pObject = nullptr;
          v75[11].pObject = (IDirect3DPixelShader9 *)GFx_FindClassAndInitializeClassInstance;
          GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::operator=(
            this: v75 + 12,
            a2: *(_DWORD **)&v95[4]);
        }
        animatedByTimeline = false;
        p_params = &v118;
      }
      GArray<GASValue,2,GArrayDefaultPolicy>::~GArray<GASValue,2,GArrayDefaultPolicy>(this: p_params);
LABEL_133:
      v22 = (*(_DWORD *)(key.RefCount + 8))-- == 1;
      if ( v22 )
        GASStringNode::ReleaseNode();
      goto LABEL_135;
    }
  }
  v21 = createFrame;
  if ( createFrame == (GRendererEventHandler *)-1 )
    v21 = key.pRenEventHandler[13].pNext;
  if ( (GRendererEventHandler *)v18[6] != v21 )
  {
    replaceIfDepthIsOccupied = true;
    goto LABEL_46;
  }
  GFxCharPosInfo::GFxCharPosInfo(this: (GFxCharPosInfo *)&newPos, __that: (const struct GFxCharPosInfo *)key.SType);
  if ( *((char *)v18 + 118) < 0 && (*(_BYTE *)(key.SType + 83) & 0x20) == 0 && v18[43] != 0 )
    v139 |= 0x20u;
  if ( *(char *)(key.SType + 83) >= 0 && (*(int (__thiscall **)(_DWORD *))(*v18 + 20))(a1: v18) != 0 )
  {
    v139 |= 0x80u;
    v138 = 0;
  }
  if ( (*(_BYTE *)(key.SType + 83) & 8) == 0 && !GRenderer::Cxform::IsIdentity(this: (GRenderer::Cxform *)(v18 + 9)) )
  {
    v139 |= 8u;
    GRenderer::Cxform::SetIdentity(this: (float *)&newPos.m_iRefs);
  }
  GFxSprite::MoveDisplayObject(this: (GFxSprite *)key.pRenEventHandler, a2: (const struct GFxCharPosInfo *)&newPos);
  GMemory::pGlobalHeap->Free(
    this: GMemory::pGlobalHeap,
    a2: newPos.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
  v22 = (*(_DWORD *)(v20 + 8))-- == 1;
  if ( v22 )
    GASStringNode::ReleaseNode();
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100BABE0
// Name: GFx_SpriteAttachMovie
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GFx_SpriteAttachMovie(int fn)
{
  GASValue *v1; // esi
  int v2; // ecx
  void *result; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v4; // esi
  int v5; // esi
  int v6; // ebx
  struct GASValue *v7; // eax
  GFxMovieRoot *v8; // eax
  void *v9; // ebx
  int v10; // eax
  const char *v11; // edi
  int v12; // eax
  const char *v13; // edi
  unsigned int v14; // edx
  _ENUM_SERVICE_STATUSA *v15; // ebx
  GASValue *v16; // eax
  int v17; // ebx
  struct GASValue *v18; // eax
  GFxMeshCacheManager_vtbl *v19; // eax
  tagBITMAPCOREHEADER *v20; // ebx
  bool v21; // zf
  const char *v22; // edi
  int v23; // eax
  __int128 v24; // [esp-10h] [ebp-ACh]
  struct GASEnvironment *v25; // [esp-10h] [ebp-ACh]
  struct GFxMovieDefImpl *v26; // [esp+8h] [ebp-94h]
  _SERVICE_STATUS *v27; // [esp+10h] [ebp-8Ch]
  IndexDesc_t rh; // [esp+20h] [ebp-7Ch] BYREF
  int v29; // [esp+30h] [ebp-6Ch]
  _ENUM_SERVICE_STATUSA *resBindData; // [esp+34h] [ebp-68h] BYREF
  int v31; // [esp+38h] [ebp-64h]
  bool v32; // [esp+3Fh] [ebp-5Dh]
  int v33; // [esp+40h] [ebp-5Ch] BYREF
  CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> pos; // [esp+44h] [ebp-58h] BYREF
  unsigned int v35; // [esp+8Ch] [ebp-10h]

  v1 = *(GASValue **)(fn + 4);
  GASValue::DropRefs(this: v1);
  *(_BYTE *)v1 = 0;
  v2 = *(_DWORD *)(fn + 8);
  if ( v2 != 0 )
  {
    result = (void *)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( result != (void *)2 )
      return result;
    v5 = *(_DWORD *)(fn + 8);
    if ( v5 == 0 )
      return result;
    v4 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)(v5 - 120);
  }
  else
  {
    result = *(void **)(fn + 24);
    v4 = *((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)result
         + 29);
  }
  if ( v4 != nullptr && *(int *)(fn + 28) >= 3 )
  {
    v6 = *(_DWORD *)(fn + 24);
    v7 = GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
    GASValue::ToStringImpl(a1: v7, a2: &v33, a3: v6, a4: -1, a5: 0);
    resBindData = nullptr;
    v31 = 0;
    GString::GString(this: (GString *)&rh.m_nFirstIndex, a2: *(const char **)v33);
    v26 = (struct GFxMovieDefImpl *)(*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v4->m_pfnProxied) + 92))(a1: v4);
    v8 = (GFxMovieRoot *)(*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v4->m_pfnProxied) + 84))(a1: v4);
    v32 = GFxMovieRoot::FindExportedResource(
            this: v8,
            a2: v26,
            result: (CMatQueuedIndexBuffer *)&resBindData,
            a4: (const struct GString *)&rh.m_nFirstIndex) == 0;
    v9 = (void *)(rh.m_nFirstIndex & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((rh.m_nFirstIndex & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
    if ( v32 )
    {
      v10 = DWORD1(v4[6].m_pfnProxied);
      v11 = *(const char **)v33;
      if ( v10 == 0 )
        GFxASCharacter::CreateCharacterHandle(this: v4);
      GFxLogBase<GFxCharacter>::LogScriptWarning(
        a1: (int)&v4->m_pfnProxied + 12,
        a2: (int)"Error: %s.attachMovie() failed - export name \"%s\" is not found.\n",
        **(const char ***)(v10 + 12),
        v11);
    }
    else if ( ((*((int (__thiscall **)(_ENUM_SERVICE_STATUSA *))resBindData->lpServiceName + 2))(a1: resBindData)
             & 0x8000) != 0 )
    {
      v14 = *(_DWORD *)(v31 + 40);
      v15 = resBindData;
      HIDWORD(v24) = 1;
      DWORD2(v24) = GRenderer::Cxform::Identity;
      DWORD1(v24) = 1;
      v25 = *(struct GASEnvironment **)(fn + 24);
      rh.m_pIndices = (unsigned __int16 *)resBindData;
      rh.m_nOffset = v14;
      v16 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 2);
      LODWORD(v24) = (int)GASValue::ToNumber(this: v16, a2: v25) + 0x4000;
      GFxCharPosInfo::GFxCharPosInfo(
        this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CFuncMemPolicyNone> *)&pos,
        chId: (CMatRenderContextBase *)v15->ServiceStatus.dwCurrentState,
        depth: v24,
        a4: (int)&GMatrix2D::Identity,
        ratio: 0.0,
        clipDepth: 0,
        hasBlendMode: false,
        blend: 0);
      if ( v35 > 0x7EFFFFFD )
      {
        v22 = *(const char **)v33;
        v23 = DWORD1(v4[6].m_pfnProxied);
        if ( v23 == 0 )
          GFxASCharacter::CreateCharacterHandle(this: v4);
        GFxLogBase<GFxCharacter>::LogScriptWarning(
          a1: (int)&v4->m_pfnProxied + 12,
          a2: (int)"Error: %s.attachMovie(\"%s\") failed - depth (%d) must be >= 0\n",
          **(const char ***)(v23 + 12),
          v22,
          v35);
      }
      else
      {
        if ( *(_DWORD *)(fn + 28) == 4 )
        {
          v27 = *(_SERVICE_STATUS **)(fn + 24);
          GASFnCall::Arg(this: (GASFnCall *)fn, a2: 3);
          v29 = (int)GASValue::ToObjectInterface(result: v27);
        }
        else
        {
          v29 = 0;
        }
        v17 = *(_DWORD *)(fn + 24);
        v18 = GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
        GASValue::ToStringImpl(a1: v18, a2: &rh.m_nIndexSize, a3: v17, a4: -1, a5: 0);
        v19 = GFxSprite::AddDisplayObject(
                this: v4,
                name: (_IMAGE_SYMBOL_EX *)&pos,
                a3: (int)&rh.m_nIndexSize,
                a4: nullptr,
                a5: (struct GASObjectInterface *)v29,
                createFrame: (GRendererEventHandler *)0xFFFFFFFF,
                addFlags: 1u,
                &rh,
                a9: 0);
        v20 = (tagBITMAPCOREHEADER *)v19;
        if ( v19 != nullptr )
          ++v19[1].dtr_GRefCountImplCore;
        v21 = (*(_DWORD *)(rh.m_nIndexSize + 8))-- == 1;
        if ( v21 )
          GASStringNode::ReleaseNode();
        if ( v20 != nullptr )
        {
          (*(void (__thiscall **)(tagBITMAPCOREHEADER *, _DWORD))(v20->bcSize + 32))(a1: v20, a2: 0);
          if ( (unsigned int)GFxCharacter::GetVersion(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v4) >= 6 )
            GASValue::SetAsCharacter(result: LOBYTE(v20[9].bcBitCount) >> 7 != 0 ? v20 : nullptr);
          GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v20);
        }
      }
      GMemory::pGlobalHeap->Free(
        this: GMemory::pGlobalHeap,
        a2: pos.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
    }
    else
    {
      v12 = DWORD1(v4[6].m_pfnProxied);
      v13 = *(const char **)v33;
      if ( v12 == 0 )
        GFxASCharacter::CreateCharacterHandle(this: v4);
      GFxLogBase<GFxCharacter>::LogScriptWarning(
        a1: (int)&v4->m_pfnProxied + 12,
        a2: (int)"Error: %s.attachMovie() failed - \"%s\" is not a movieclip.\n",
        **(const char ***)(v12 + 12),
        v13);
    }
    if ( resBindData != nullptr )
      GFxResource::Release(this: (IShaderDevice *)resBindData);
    result = (void *)v33;
    v21 = (*(_DWORD *)(v33 + 8))-- == 1;
    if ( v21 )
      return GASStringNode::ReleaseNode().Sid;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BAED0
// Name: GFx_SpriteAttachBitmap
// Source: json
//------------------------------------------------------------------------------
char __cdecl GFx_SpriteAttachBitmap(int fn)
{
  GASValue *v1; // esi
  int v2; // ecx
  const void *Version; // eax
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *v4; // esi
  int v5; // esi
  GASValue *v6; // eax
  struct GASObject *v7; // eax
  IShaderDevice *v8; // edi
  int v9; // eax
  GASValue *v10; // eax
  struct GFxMovieRoot *MovieRoot; // ebx
  IShaderDevice *v12; // eax
  int v13; // ecx
  int (__thiscall *v14)(int, int, int *); // eax
  GFxFontLib::FontResult *v15; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v16; // edi
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  __int128 v22; // [esp-Ch] [ebp-124h]
  struct GASEnvironment *v23; // [esp-Ch] [ebp-124h]
  __int128 v24; // [esp-Ch] [ebp-124h]
  _PSINJECTDATA v25; // [esp+14h] [ebp-104h]
  const struct GASEnvironment *v26; // [esp+14h] [ebp-104h]
  tagPOLYTEXTW *v27; // [esp+14h] [ebp-104h]
  struct GASObject *v28; // [esp+28h] [ebp-F0h]
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *smoothing; // [esp+2Ch] [ebp-ECh]
  IShaderDevice *smoothinga; // [esp+2Ch] [ebp-ECh]
  int v31; // [esp+30h] [ebp-E8h] BYREF
  float v32[8]; // [esp+34h] [ebp-E4h] BYREF
  CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> locpos; // [esp+54h] [ebp-C4h] BYREF
  CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> pos; // [esp+A8h] [ebp-70h] BYREF
  unsigned int v35; // [esp+F0h] [ebp-28h]
  float v36[6]; // [esp+FCh] [ebp-1Ch] BYREF

  v1 = *(GASValue **)(fn + 4);
  GASValue::DropRefs(this: v1);
  *(_BYTE *)v1 = 0;
  v2 = *(_DWORD *)(fn + 8);
  if ( v2 != 0 )
  {
    Version = (const void *)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( Version != (const void *)2 )
      return (char)Version;
    v5 = *(_DWORD *)(fn + 8);
    if ( v5 == 0 )
      return (char)Version;
    v4 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)(v5 - 120);
  }
  else
  {
    Version = *(const void **)(fn + 24);
    v4 = *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> **)Version
         + 29);
  }
  if ( v4 != nullptr && *(int *)(fn + 28) >= 2 )
  {
    Version = GFxCharacter::GetVersion(this: v4);
    if ( (unsigned int)Version >= 8 )
    {
      v26 = *(const struct GASEnvironment **)(fn + 24);
      v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
      v7 = GASValue::ToObject(this: v6, a2: v26);
      v8 = (IShaderDevice *)v7;
      v28 = v7;
      if ( v7 != nullptr )
      {
        v7[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v7[1].pNode->pNext + 1) & 0x8FFFFFFF);
        if ( ((int (__thiscall *)(struct GASObject *))v7[2].pNode[1].pNext)(a1: &v7[2]) == 26 )
        {
          smoothing = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v8[13].__vftable;
          if ( smoothing != nullptr )
          {
            HIDWORD(v22) = 1;
            DWORD2(v22) = GRenderer::Cxform::Identity;
            DWORD1(v22) = 1;
            v23 = *(struct GASEnvironment **)(fn + 24);
            v10 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
            LODWORD(v22) = (int)GASValue::ToNumber(this: v10, a2: v23) + 0x4000;
            GFxCharPosInfo::GFxCharPosInfo(
              this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CFuncMemPolicyNone> *)&pos,
              chId: (CMatRenderContextBase *)1,
              depth: v22,
              a4: (int)&GMatrix2D::Identity,
              ratio: 0.0,
              clipDepth: 0,
              hasBlendMode: false,
              blend: 0);
            if ( v35 <= 0x7EFFFFFD )
            {
              if ( *(int *)(fn + 28) < 4 )
              {
                LOBYTE(v31) = 0;
              }
              else
              {
                v27 = *(tagPOLYTEXTW **)(fn + 24);
                GASFnCall::Arg(this: (GASFnCall *)fn, a2: 3);
                LOBYTE(v31) = (unsigned __int8)GASValue::ToBool(result: v27);
              }
              v25.DataBytes = 0;
              MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fn + 24));
              GFxMovieRoot::CreateImageMovieDef(
                this: (ScaleformRenderer::FillStyle *)MovieRoot,
                pimageResource: smoothing,
                a3: v31,
                a4: (int)&pMem,
                pls: v25);
              v8 = v12;
              smoothinga = v12;
              if ( v12 != nullptr )
              {
                v13 = *((_DWORD *)MovieRoot + 8);
                v14 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v13 + 40);
                v31 = 322;
                v15 = (GFxFontLib::FontResult *)v14(a1: v13, a2: 488, a3: &v31);
                if ( v15 != nullptr )
                {
                  v16 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GFxSprite::GFxSprite(this: v15, pdefImpl: (_IMAGE_SECTION_HEADER::<unnamed_type_Misc>)v8[7].GetBackBufferDimensions, pbindingDefImpl: (_IMAGE_SECTION_HEADER::<unnamed_type_Misc>)v8, a4: (int)MovieRoot, a5: (struct GFxASCharacter *)v4, a6: (struct GFxResourceId)65537, loadedSeparately: 1);
                  if ( v16 != nullptr )
                  {
                    GMatrix2D::SetIdentity(this: v36);
                    *((_QWORD *)&v24 + 1) = (unsigned int)GRenderer::Cxform::Cxform(this: v32) | 0x100000000LL;
                    *(_QWORD *)&v24 = 1;
                    GFxCharPosInfo::GFxCharPosInfo(
                      this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CFuncMemPolicyNone> *)&locpos,
                      chId: (CMatRenderContextBase *)1,
                      depth: v24,
                      a4: (int)v36,
                      ratio: 0.0,
                      clipDepth: 0,
                      hasBlendMode: false,
                      blend: 0);
                    v31 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(fn + 24) + 120) + 8);
                    ++*(_DWORD *)(v31 + 8);
                    GFxASCharacter::AddToPlayList(
                      this: v16,
                      result: (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)MovieRoot);
                    GFxASCharacter::ModifyOptimizedPlayList(
                      this: (CMatQueuedMesh **)v16,
                      result: (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)MovieRoot);
                    GFxSprite::AddDisplayObject(
                      this: v16,
                      name: (_IMAGE_SYMBOL_EX *)&locpos,
                      a3: (int)&v31,
                      a4: nullptr,
                      a5: nullptr,
                      createFrame: (GRendererEventHandler *)1,
                      addFlags: 0,
                      rh: nullptr,
                      a9: 0);
                    GFxSprite::ReplaceDisplayObject(
                      this: (GMemoryFile *)v4,
                      a2: (int)v4,
                      name: (_IMAGE_SYMBOL_EX *)&pos,
                      a4: (int)v16,
                      a5: (int)&v31);
                    (*(void (__thiscall **)(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *, _DWORD))(LODWORD(v4->m_pfnProxied) + 32))(
                      a1: v4,
                      a2: 0);
                    if ( (*(_DWORD *)(v31 + 8))-- == 1 )
                      GASStringNode::ReleaseNode();
                    GMemory::pGlobalHeap->Free(
                      this: GMemory::pGlobalHeap,
                      a2: locpos.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
                    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v16);
                  }
                  v8 = smoothinga;
                }
                GFxResource::Release(this: v8);
              }
              GMemory::pGlobalHeap->Free(
                this: GMemory::pGlobalHeap,
                a2: pos.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
              v18 = (int)v28;
              goto LABEL_36;
            }
            v19 = DWORD1(v4[6].m_pfnProxied);
            if ( v19 == 0 )
              GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v4);
            GFxLogBase<GFxCharacter>::LogScriptWarning(
              a1: (int)&v4->m_pfnProxied + 12,
              a2: (int)"Error: %s.attachBitmap() failed - depth (%d) must be >= 0\n",
              **(const char ***)(v19 + 12),
              v35);
            GMemory::pGlobalHeap->Free(
              this: GMemory::pGlobalHeap,
              a2: pos.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
          }
          else
          {
            v9 = DWORD1(v4[6].m_pfnProxied);
            if ( v9 == 0 )
            {
              GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v4);
              if ( v9 == 0 )
                v9 = *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *))(LODWORD(v4->m_pfnProxied) + 108))(a1: v4)
                               + 120);
            }
            GFxLogBase<GFxCharacter>::LogScriptWarning(
              a1: (int)&v4->m_pfnProxied + 12,
              a2: (int)"Error: %s.attachBitmap() failed - no image set in BitmapData.\n",
              **(const char ***)(v9 + 8));
          }
LABEL_35:
          v18 = (int)v8;
LABEL_36:
          LOBYTE(Version) = GRefCountBaseGC<323>::Release(a1: v18, a2: (int)v8);
          return (char)Version;
        }
      }
      v20 = DWORD1(v4[6].m_pfnProxied);
      if ( v20 == 0 )
        GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v4);
      LOBYTE(Version) = GFxLogBase<GFxCharacter>::LogScriptWarning(
                          a1: (int)&v4->m_pfnProxied + 12,
                          a2: (int)"Error: %s.attachBitmap() failed - the argument is not a BitmapData.\n",
                          **(const char ***)(v20 + 12));
      if ( v8 != nullptr )
        goto LABEL_35;
    }
  }
  return (char)Version;
}

//------------------------------------------------------------------------------
// Address: 0x100BB260
// Name: GFx_SpriteCreateEmptyMovieClip
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFx_SpriteCreateEmptyMovieClip(_CONNECTDLGSTRUCTW fn)
{
  GASValue *v1; // edi
  int v2; // ecx
  int result; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v4; // ebx
  int v5; // ebx
  GASValue *v6; // eax
  int v7; // edi
  struct GASValue *v8; // eax
  GFxMeshCacheManager_vtbl *v9; // eax
  tagBITMAPCOREHEADER *v10; // edi
  __int128 v12; // [esp-14h] [ebp-8Ch]
  struct GASEnvironment *v13; // [esp-14h] [ebp-8Ch]
  int v14; // [esp+1Ch] [ebp-5Ch] BYREF
  CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> pos; // [esp+20h] [ebp-58h] BYREF
  unsigned int v16; // [esp+68h] [ebp-10h]

  v1 = *(GASValue **)(fn.cbStructure + 4);
  GASValue::DropRefs(this: v1);
  *(_BYTE *)v1 = 0;
  v2 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v2 != 0 )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( result != 2 )
      return result;
    v5 = *(_DWORD *)(fn.cbStructure + 8);
    if ( v5 == 0 )
      return result;
    v4 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)(v5 - 120);
  }
  else
  {
    result = *(_DWORD *)(fn.cbStructure + 24);
    v4 = *(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)(result + 116);
  }
  if ( v4 != nullptr && *(int *)(fn.cbStructure + 28) >= 2 )
  {
    HIDWORD(v12) = 1;
    DWORD2(v12) = GRenderer::Cxform::Identity;
    DWORD1(v12) = 1;
    v13 = *(struct GASEnvironment **)(fn.cbStructure + 24);
    v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 1);
    LODWORD(v12) = (int)GASValue::ToNumber(this: v6, a2: v13) + 0x4000;
    GFxCharPosInfo::GFxCharPosInfo(
      this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CFuncMemPolicyNone> *)&pos,
      chId: (CMatRenderContextBase *)0x10001,
      depth: v12,
      a4: (int)&GMatrix2D::Identity,
      ratio: 0.0,
      clipDepth: 0,
      hasBlendMode: false,
      blend: 0);
    if ( v16 > 0x7EFFFFFD )
    {
      return ((int (__thiscall *)(GMemoryHeap *, CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *))GMemory::pGlobalHeap->Free)(
               a1: GMemory::pGlobalHeap,
               a2: pos.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
    }
    else
    {
      v7 = *(_DWORD *)(fn.cbStructure + 24);
      v8 = GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 0);
      GASValue::ToStringImpl(a1: v8, a2: &v14, a3: v7, a4: -1, a5: 0);
      v9 = GFxSprite::AddDisplayObject(
             this: v4,
             name: (_IMAGE_SYMBOL_EX *)&pos,
             a3: (int)&v14,
             a4: nullptr,
             a5: nullptr,
             createFrame: (GRendererEventHandler *)0xFFFFFFFF,
             addFlags: 1u,
             rh: nullptr,
             a9: 0);
      v10 = (tagBITMAPCOREHEADER *)v9;
      if ( v9 != nullptr )
        ++v9[1].dtr_GRefCountImplCore;
      if ( (*(_DWORD *)(v14 + 8))-- == 1 )
        GASStringNode::ReleaseNode();
      if ( v10 != nullptr )
      {
        (*(void (__thiscall **)(tagBITMAPCOREHEADER *, _DWORD))(v10->bcSize + 32))(a1: v10, a2: 0);
        GASValue::SetAsCharacter(result: LOBYTE(v10[9].bcBitCount) >> 7 != 0 ? v10 : nullptr);
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v10);
      }
      return ((int (__thiscall *)(GMemoryHeap *, CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *))GMemory::pGlobalHeap->Free)(
               a1: GMemory::pGlobalHeap,
               a2: pos.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BB3E0
// Name: GFx_SpriteCreateTextField
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFx_SpriteCreateTextField(_CONNECTDLGSTRUCTW fn)
{
  GASValue *v1; // esi
  int v2; // ecx
  int result; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v4; // ebx
  int v5; // ebx
  GASValue *v6; // eax
  int v7; // esi
  struct GASValue *v8; // eax
  GFxMeshCacheManager_vtbl *v9; // eax
  GRefCountNTSImpl *v10; // ebx
  tagBITMAPCOREHEADER *v12; // esi
  struct GASValue *v13; // eax
  struct GASValue *v14; // eax
  struct GASValue *v15; // eax
  struct GASValue *v16; // eax
  __int128 v17; // [esp-14h] [ebp-90h]
  struct GASEnvironment *v18; // [esp-14h] [ebp-90h]
  int v19; // [esp+1Ch] [ebp-60h] BYREF
  void (__thiscall **v20)(tagBITMAPCOREHEADER *, int, struct GASValue *, _DWORD); // [esp+20h] [ebp-5Ch]
  CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> pos; // [esp+24h] [ebp-58h] BYREF
  unsigned int v22; // [esp+6Ch] [ebp-10h]

  v1 = *(GASValue **)(fn.cbStructure + 4);
  GASValue::DropRefs(this: v1);
  *(_BYTE *)v1 = 0;
  v2 = *(_DWORD *)(fn.cbStructure + 8);
  if ( v2 != 0 )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    if ( result != 2 )
      return result;
    v5 = *(_DWORD *)(fn.cbStructure + 8);
    if ( v5 == 0 )
      return result;
    v4 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)(v5 - 120);
  }
  else
  {
    result = *(_DWORD *)(fn.cbStructure + 24);
    v4 = *(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)(result + 116);
  }
  if ( v4 != nullptr && *(int *)(fn.cbStructure + 28) >= 6 )
  {
    HIDWORD(v17) = 1;
    DWORD2(v17) = GRenderer::Cxform::Identity;
    DWORD1(v17) = 1;
    v18 = *(struct GASEnvironment **)(fn.cbStructure + 24);
    v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 1);
    LODWORD(v17) = (int)GASValue::ToNumber(this: v6, a2: v18) + 0x4000;
    GFxCharPosInfo::GFxCharPosInfo(
      this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CFuncMemPolicyNone> *)&pos,
      chId: (CMatRenderContextBase *)0x10002,
      depth: v17,
      a4: (int)&GMatrix2D::Identity,
      ratio: 0.0,
      clipDepth: 0,
      hasBlendMode: false,
      blend: 0);
    if ( v22 > 0x7EFFFFFD )
    {
      return ((int (__thiscall *)(GMemoryHeap *, CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *))GMemory::pGlobalHeap->Free)(
               a1: GMemory::pGlobalHeap,
               a2: pos.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
    }
    else
    {
      v7 = *(_DWORD *)(fn.cbStructure + 24);
      v8 = GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 0);
      GASValue::ToStringImpl(a1: v8, a2: &v19, a3: v7, a4: -1, a5: 0);
      v9 = GFxSprite::AddDisplayObject(
             this: v4,
             name: (_IMAGE_SYMBOL_EX *)&pos,
             a3: (int)&v19,
             a4: nullptr,
             a5: nullptr,
             createFrame: (GRendererEventHandler *)0xFFFFFFFF,
             addFlags: 1u,
             rh: nullptr,
             a9: 0);
      v10 = (GRefCountNTSImpl *)v9;
      if ( v9 != nullptr )
        ++v9[1].dtr_GRefCountImplCore;
      if ( (*(_DWORD *)(v19 + 8))-- == 1 )
        GASStringNode::ReleaseNode();
      if ( v10 != nullptr )
      {
        ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD))v10->__vftable[8].dtr_GRefCountImplCore)(a1: v10, a2: 0);
        v12 = BYTE2(v10[14].RefCount) >> 7 != 0 ? (tagBITMAPCOREHEADER *)v10 : nullptr;
        v20 = (void (__thiscall **)(tagBITMAPCOREHEADER *, int, struct GASValue *, _DWORD))(v12->bcSize + 284);
        v13 = GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 2);
        (*v20)(a1: v12, a2: 0, a3: v13, a4: 0);
        v20 = (void (__thiscall **)(tagBITMAPCOREHEADER *, int, struct GASValue *, _DWORD))(v12->bcSize + 284);
        v14 = GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 3);
        (*v20)(a1: v12, a2: 1, a3: v14, a4: 0);
        v20 = (void (__thiscall **)(tagBITMAPCOREHEADER *, int, struct GASValue *, _DWORD))(v12->bcSize + 284);
        v15 = GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 4);
        (*v20)(a1: v12, a2: 8, a3: v15, a4: 0);
        v20 = (void (__thiscall **)(tagBITMAPCOREHEADER *, int, struct GASValue *, _DWORD))(v12->bcSize + 284);
        v16 = GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 5);
        (*v20)(a1: v12, a2: 9, a3: v16, a4: 0);
        GASValue::SetAsCharacter(result: v12);
        GRefCountNTSImpl::Release(this: v10);
      }
      return ((int (__thiscall *)(GMemoryHeap *, CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *))GMemory::pGlobalHeap->Free)(
               a1: GMemory::pGlobalHeap,
               a2: pos.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BB5F0
// Name: public: virtual class GFxCharacter __near * GFxSpriteDef::CreateCharacterInstance(class GFxASCharacter __near *,class GFxResourceId,class GFxMovieDefImpl __near *)
// Source: json
//------------------------------------------------------------------------------
GFxFontLib::FontResult *__thiscall GFxSpriteDef::CreateCharacterInstance(
        void *this,
        int result,
        struct GFxResourceId a3,
        _IMAGE_SECTION_HEADER::<unnamed_type_Misc> pbindingImpl)
{
  struct GFxASCharacter *v4; // esi
  int v6; // edi
  int v7; // ecx
  int (__thiscall *v8)(int, int, int *); // eax
  GFxFontLib::FontResult *v9; // eax

  v4 = (struct GFxASCharacter *)result;
  v6 = (*(int (__thiscall **)(int))(*(_DWORD *)result + 84))(a1: result);
  v7 = *(_DWORD *)(v6 + 32);
  v8 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v7 + 40);
  result = 322;
  v9 = (GFxFontLib::FontResult *)v8(a1: v7, a2: 488, a3: &result);
  if ( v9 != nullptr )
    return GFxSprite::GFxSprite(
             this: v9,
             pdefImpl: (_IMAGE_SECTION_HEADER::<unnamed_type_Misc>)this,
             pbindingDefImpl: pbindingImpl,
             a4: v6,
             a5: v4,
             a6: a3,
             loadedSeparately: 0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100BB650
// Name: public: virtual void GFxSpriteDef::AddFrameName(class GString const __near &,class GFxLog __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSpriteDef::AddFrameName(
        GRefCountBaseNTS<GFxKeyboardState,326> *this,
        const struct AudioState_t *name,
        GFxLogBase<GFxLog> *a3)
{
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v3; // edi
  CUtlHash<int,CKeyValuesGrowableStringTable::CLookupFunctor &,CKeyValuesGrowableStringTable::CLookupFunctor &> *v5; // ebx
  char v6; // al
  const char *v7; // eax
  int v9; // [esp+Ch] [ebp-8h] BYREF
  unsigned int currentlyAssigned; // [esp+10h] [ebp-4h]

  v3 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)name;
  v5 = (CUtlHash<int,CKeyValuesGrowableStringTable::CLookupFunctor &,CKeyValuesGrowableStringTable::CLookupFunctor &> *)((char *)this + 20);
  currentlyAssigned = 0;
  GStringHashLH<unsigned int,2,GString::NoCaseHashFunctor,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<GString>(
    this: (IVEngineClient *)this + 5,
    key: name);
  if ( v6 == 1 && a3 != nullptr )
    GFxLogBase<GFxLog>::LogError(
      this: a3 + 3,
      pfmt: "AddFrameName(%d, '%s') -- frame name already assigned to frame %d; overriding\n",
      *((_DWORD *)this + 7),
      (const char *)(((int)v3->m_Memory.m_pMemory & 0xFFFFFFFC) + 8),
      currentlyAssigned);
  if ( GString::GetLength(this: (GString *)v3) != 0 )
  {
    v7 = (const char *)(((int)v3->m_Memory.m_pMemory & 0xFFFFFFFC) + 8);
    if ( *v7 == 95 )
    {
      if ( strcmp(v7, (const char *)&label) == 0 )
      {
        *((_BYTE *)this + 52) |= 1u;
      }
      else if ( (unsigned __int8)GString::operator==(this: v3) != 0 )
      {
        *((_BYTE *)this + 52) |= 2u;
      }
      else if ( (unsigned __int8)GString::operator==(this: v3) != 0 )
      {
        *((_BYTE *)this + 52) |= 4u;
      }
    }
  }
  name = *((const struct AudioState_t **)this + 7);
  v9 = (int)v3;
  currentlyAssigned = (unsigned int)&name;
  return GHashSetBase<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<unsigned int,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF>>::Set<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeRef>(
           this: v5,
           a2: (int)v5,
           a3: (int)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x100BB770
// Name: public: void GFxSprite::ExecuteSnapshot(class GFxTimelineSnapshot __near *,enum GFxActionPriority::Priority)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GFxSprite::ExecuteSnapshot(GFxValue *this, const CMatQueuedMesh *psnapshot, GFxValue *prio)
{
  const char *result; // eax
  unsigned __int8 *i; // ebx
  int v5; // ecx
  int v6; // edi
  _BYTE *v7; // esi
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  double v15; // st7
  _BYTE *v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  char v21; // cl
  int v22; // eax
  int v23; // eax
  __int16 v24; // cx
  int v25; // eax
  int v26; // eax
  double v27; // st7
  int v28; // eax
  int v29; // eax
  int *v30; // esi
  int j; // edi
  void *v32; // eax
  int v33; // eax
  int v34; // esi
  int v35; // eax
  int *v36; // ecx
  const char *v37; // ecx
  bool v38; // zf
  unsigned int v39; // eax
  int v40; // ecx
  int v41; // edi
  _BYTE *v42; // esi
  int v43; // ecx
  int v44; // eax
  int v45; // eax
  int v46; // ecx
  int v47; // eax
  int v48; // eax
  int v49; // eax
  double v50; // st7
  _BYTE *v51; // eax
  int v52; // eax
  int v53; // eax
  int v54; // eax
  int v55; // eax
  char v56; // cl
  int v57; // eax
  int v58; // eax
  __int16 v59; // cx
  int v60; // eax
  int v61; // eax
  double v62; // st7
  int v63; // eax
  int v64; // eax
  int *v65; // esi
  int k; // edi
  void *v67; // eax
  GMemoryFile *v68; // esi
  int v69; // ecx
  int v70; // edi
  _BYTE *v71; // esi
  int v72; // ecx
  int v73; // eax
  int v74; // eax
  int v75; // ecx
  int v76; // eax
  int v77; // eax
  int v78; // eax
  double v79; // st7
  _BYTE *v80; // eax
  int v81; // eax
  int v82; // eax
  int v83; // eax
  int v84; // eax
  char v85; // cl
  int v86; // eax
  int v87; // eax
  __int16 v88; // cx
  int v89; // eax
  int v90; // eax
  double v91; // st7
  int v92; // eax
  int v93; // eax
  int *v94; // esi
  int m; // edi
  void *v96; // eax
  int v97; // eax
  int v98; // esi
  int v99; // ecx
  int *v100; // eax
  const char *v101; // ecx
  int v102; // eax
  GMemoryFile *v103; // esi
  __int128 v104; // [esp+0h] [ebp-394h]
  int v105; // [esp+10h] [ebp-384h] BYREF
  int v106; // [esp+14h] [ebp-380h] BYREF
  int v107; // [esp+18h] [ebp-37Ch] BYREF
  int v108; // [esp+1Ch] [ebp-378h] BYREF
  int v109; // [esp+20h] [ebp-374h] BYREF
  int v110; // [esp+24h] [ebp-370h] BYREF
  GMemoryFile *v111; // [esp+28h] [ebp-36Ch]
  int v112; // [esp+2Ch] [ebp-368h]
  CMatQueuedMesh pos; // [esp+30h] [ebp-364h] BYREF
  int v114; // [esp+80h] [ebp-314h]
  int v115; // [esp+84h] [ebp-310h]
  int v116; // [esp+88h] [ebp-30Ch]
  IStream v117[2]; // [esp+90h] [ebp-304h] BYREF
  _BYTE v118[64]; // [esp+98h] [ebp-2FCh] BYREF
  IMesh *v119; // [esp+D8h] [ebp-2BCh]
  _DWORD v120[5]; // [esp+DCh] [ebp-2B8h]
  _BYTE v121[96]; // [esp+F0h] [ebp-2A4h] BYREF
  _BYTE v122[96]; // [esp+150h] [ebp-244h] BYREF
  _BYTE v123[96]; // [esp+1B0h] [ebp-1E4h] BYREF
  _BYTE v124[96]; // [esp+210h] [ebp-184h] BYREF
  _BYTE v125[96]; // [esp+270h] [ebp-124h] BYREF
  _BYTE v126[96]; // [esp+2D0h] [ebp-C4h] BYREF
  _BYTE v127[96]; // [esp+330h] [ebp-64h] BYREF
  int v128; // [esp+390h] [ebp-4h] BYREF

  v111 = (GMemoryFile *)this;
  result = (char *)&psnapshot->m_VertexFormat + 4;
  v112 = 0;
  HIDWORD(v104) = (char *)&psnapshot->m_VertexFormat + 4;
  if ( psnapshot->m_pVertexData != (unsigned __int8 *)&psnapshot->m_VertexFormat + 4 )
  {
    for ( i = psnapshot->m_pVertexData; ; i = *((unsigned __int8 **)i + 1) )
    {
      switch ( i[52] )
      {
        case 0u:
          memset(&pos, 0, 12);
          GRenderer::Cxform::Cxform(this: (float *)&pos.m_pMSTActualMesh);
          GMatrix2D::SetIdentity(this: (float *)&pos.m_pIndexData);
          v5 = *((_DWORD *)i + 4);
          *(float *)&pos.m_pVertexOverride = 0.0;
          v114 = 0;
          *((_DWORD *)&pos.m_pIndexOverride + 1) = 0x40000;
          pos.m_pIndexOverride = nullptr;
          (*(void (__thiscall **)(int, CMatQueuedMesh *))(*(_DWORD *)v5 + 32))(a1: v5, a2: &pos);
          v6 = 7;
          v7 = v118;
          do
          {
            *((_DWORD *)v7 - 2) = 0;
            *((_DWORD *)v7 - 1) = 0;
            *(_DWORD *)v7 = 0;
            GRenderer::Cxform::Cxform(this: (float *)v7 + 1);
            GMatrix2D::SetIdentity(this: (float *)v7 + 9);
            *((_DWORD *)v7 + 17) = 0x40000;
            v7[75] = 0;
            *((float *)v7 + 15) = 0.0;
            *((_DWORD *)v7 + 16) = 0;
            *((_WORD *)v7 + 36) = 0;
            v7[74] = 0;
            v7 += 96;
            --v6;
          }
          while ( v6 >= 0 );
          v8 = *((_DWORD *)i + 9);
          if ( v8 != *((_DWORD *)i + 4) )
          {
            (*(void (__thiscall **)(int, IStream *))(*(_DWORD *)v8 + 32))(a1: v8, a2: v117);
            HIBYTE(v114) |= 1u;
            pos.m_pIndexOverride = v119;
          }
          v9 = *((_DWORD *)i + 12);
          if ( v9 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v9 )
            {
              v10 = 0;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 12) + 32))(a1: *((_DWORD *)i + 12), a2: v121);
              v10 = 1;
            }
            v11 = v120[24 * v10];
            HIBYTE(v114) |= 2u;
            *((_DWORD *)&pos.m_pIndexOverride + 1) = v11;
          }
          v12 = *((_DWORD *)i + 5);
          if ( v12 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v12 )
            {
              v13 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v12 )
            {
              v13 = 1;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 5) + 32))(a1: *((_DWORD *)i + 5), a2: v122);
              v13 = 2;
            }
            v14 = 96 * v13;
            v15 = *(float *)&v118[v14 + 36];
            HIBYTE(v114) |= 4u;
            *(float *)&pos.m_pIndexData = v15;
            v16 = &v118[v14 + 36];
            pos.m_nVerts = *((int *)v16 + 1);
            pos.m_nIndices = *((int *)v16 + 2);
            *(float *)&pos.m_VertexSize = *((float *)v16 + 3);
            *(float *)&pos.m_bExternalIB = *((float *)v16 + 4);
            pos.m_Type = *((MaterialPrimitiveType_t *)v16 + 5);
          }
          v17 = *((_DWORD *)i + 6);
          if ( v17 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v17 )
            {
              v18 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v17 )
            {
              v18 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v17 )
            {
              v18 = 2;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 6) + 32))(a1: *((_DWORD *)i + 6), a2: v123);
              v18 = 3;
            }
            qmemcpy(&pos.m_pMSTActualMesh, &v118[96 * v18 + 4], 0x20u);
            HIBYTE(v114) |= 8u;
          }
          v19 = *((_DWORD *)i + 8);
          if ( v19 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v19 )
            {
              v20 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v19 )
            {
              v20 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v19 )
            {
              v20 = 2;
            }
            else if ( *((_DWORD *)i + 6) == v19 )
            {
              v20 = 3;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 8) + 32))(a1: *((_DWORD *)i + 8), a2: v124);
              v20 = 4;
            }
            v21 = BYTE2(v120[24 * v20 + 1]);
            HIBYTE(v114) |= 0x80u;
            BYTE2(v114) = v21;
          }
          v22 = *((_DWORD *)i + 10);
          if ( v22 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v22 )
            {
              v23 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v22 )
            {
              v23 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v22 )
            {
              v23 = 2;
            }
            else if ( *((_DWORD *)i + 6) == v22 )
            {
              v23 = 3;
            }
            else if ( *((_DWORD *)i + 8) == v22 )
            {
              v23 = 4;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 10) + 32))(a1: *((_DWORD *)i + 10), a2: v125);
              v23 = 5;
            }
            v24 = v120[24 * v23 + 1];
            HIBYTE(v114) |= 0x40u;
            LOWORD(v114) = v24;
          }
          v25 = *((_DWORD *)i + 11);
          if ( v25 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v25 )
            {
              v26 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v25 )
            {
              v26 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v25 )
            {
              v26 = 2;
            }
            else if ( *((_DWORD *)i + 6) == v25 )
            {
              v26 = 3;
            }
            else if ( *((_DWORD *)i + 8) == v25 )
            {
              v26 = 4;
            }
            else if ( *((_DWORD *)i + 10) == v25 )
            {
              v26 = 5;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 11) + 32))(a1: *((_DWORD *)i + 11), a2: v126);
              v26 = 6;
            }
            v27 = *(float *)&v118[96 * v26 + 60];
            HIBYTE(v114) |= 0x10u;
            *(float *)&pos.m_pVertexOverride = v27;
          }
          v28 = *((_DWORD *)i + 7);
          if ( v28 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v28 )
            {
              v29 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v28 )
            {
              v29 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v28 )
            {
              v29 = 2;
            }
            else if ( *((_DWORD *)i + 6) == v28 )
            {
              v29 = 3;
            }
            else if ( *((_DWORD *)i + 8) == v28 )
            {
              v29 = 4;
            }
            else if ( *((_DWORD *)i + 10) == v28 )
            {
              v29 = 5;
            }
            else if ( *((_DWORD *)i + 11) == v28 )
            {
              v29 = 6;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 7) + 32))(a1: *((_DWORD *)i + 7), a2: v127);
              v29 = 7;
            }
            GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::operator=(
              a1: &pos,
              this: &v117[24 * v29],
              a: *(_ULARGE_INTEGER *)&v104);
            HIBYTE(v114) |= 0x20u;
          }
          v30 = &v128;
          for ( j = 7; j >= 0; --j )
          {
            v32 = (void *)*(v30 - 24);
            v30 -= 24;
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v32);
          }
          v33 = ((int (__thiscall *)(GMemoryFile *))v111->__vftable[1].Write)(a1: v111);
          if ( v116 != 0 )
          {
            v37 = *(const char **)(*(_DWORD *)(v33 + 120) + 636);
            v112 |= 2u;
            GASStringManager::CreateStringNode(this: v37);
            v34 = v105;
            ++*(_DWORD *)(v35 + 8);
            v108 = v35;
            v36 = &v108;
          }
          else
          {
            v34 = *(_DWORD *)(*(_DWORD *)(v33 + 120) + 8);
            v35 = v108;
            v112 |= 1u;
            ++*(_DWORD *)(v34 + 8);
            v105 = v34;
            v36 = &v105;
          }
          v106 = *v36;
          ++*(_DWORD *)(v106 + 8);
          if ( (v112 & 2) != 0 )
          {
            v112 &= ~2u;
            v38 = (*(_DWORD *)(v35 + 8))-- == 1;
            if ( v38 )
              GASStringNode::ReleaseNode();
          }
          if ( (v112 & 1) != 0 )
          {
            v112 &= ~1u;
            v38 = (*(_DWORD *)(v34 + 8))-- == 1;
            if ( v38 )
              GASStringNode::ReleaseNode();
          }
          v39 = 4;
          if ( (i[53] & 2) != 0 )
            v39 = 6;
          GFxSprite::AddDisplayObject(
            this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v111,
            name: (_IMAGE_SYMBOL_EX *)&pos,
            a3: (int)&v106,
            a4: (GFxRenderGen *)v115,
            a5: nullptr,
            createFrame: *((GRendererEventHandler **)i + 2),
            addFlags: v39,
            rh: nullptr,
            a9: 0);
          v38 = (*(_DWORD *)(v106 + 8))-- == 1;
          if ( !v38 )
            goto LABEL_100;
          goto LABEL_99;
        case 1u:
          memset(&pos, 0, 12);
          GRenderer::Cxform::Cxform(this: (float *)&pos.m_pMSTActualMesh);
          GMatrix2D::SetIdentity(this: (float *)&pos.m_pIndexData);
          *(float *)&pos.m_pVertexOverride = 0.0;
          v114 = 0;
          v40 = *((_DWORD *)i + 4);
          *((_DWORD *)&pos.m_pIndexOverride + 1) = 0x40000;
          pos.m_pIndexOverride = nullptr;
          (*(void (__thiscall **)(int, CMatQueuedMesh *))(*(_DWORD *)v40 + 32))(a1: v40, a2: &pos);
          v41 = 7;
          v42 = v118;
          do
          {
            *((_DWORD *)v42 - 2) = 0;
            *((_DWORD *)v42 - 1) = 0;
            *(_DWORD *)v42 = 0;
            GRenderer::Cxform::Cxform(this: (float *)v42 + 1);
            GMatrix2D::SetIdentity(this: (float *)v42 + 9);
            *((_DWORD *)v42 + 17) = 0x40000;
            v42[75] = 0;
            *((float *)v42 + 15) = 0.0;
            *((_DWORD *)v42 + 16) = 0;
            *((_WORD *)v42 + 36) = 0;
            v42[74] = 0;
            v42 += 96;
            --v41;
          }
          while ( v41 >= 0 );
          v43 = *((_DWORD *)i + 9);
          if ( v43 != *((_DWORD *)i + 4) )
          {
            (*(void (__thiscall **)(int, IStream *))(*(_DWORD *)v43 + 32))(a1: v43, a2: v117);
            HIBYTE(v114) |= 1u;
            pos.m_pIndexOverride = v119;
          }
          v44 = *((_DWORD *)i + 12);
          if ( v44 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v44 )
            {
              v45 = 0;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 12) + 32))(a1: *((_DWORD *)i + 12), a2: v121);
              v45 = 1;
            }
            v46 = v120[24 * v45];
            HIBYTE(v114) |= 2u;
            *((_DWORD *)&pos.m_pIndexOverride + 1) = v46;
          }
          v47 = *((_DWORD *)i + 5);
          if ( v47 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v47 )
            {
              v48 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v47 )
            {
              v48 = 1;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 5) + 32))(a1: *((_DWORD *)i + 5), a2: v122);
              v48 = 2;
            }
            v49 = 96 * v48;
            v50 = *(float *)&v118[v49 + 36];
            HIBYTE(v114) |= 4u;
            *(float *)&pos.m_pIndexData = v50;
            v51 = &v118[v49 + 36];
            pos.m_nVerts = *((int *)v51 + 1);
            pos.m_nIndices = *((int *)v51 + 2);
            *(float *)&pos.m_VertexSize = *((float *)v51 + 3);
            *(float *)&pos.m_bExternalIB = *((float *)v51 + 4);
            pos.m_Type = *((MaterialPrimitiveType_t *)v51 + 5);
          }
          v52 = *((_DWORD *)i + 6);
          if ( v52 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v52 )
            {
              v53 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v52 )
            {
              v53 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v52 )
            {
              v53 = 2;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 6) + 32))(a1: *((_DWORD *)i + 6), a2: v123);
              v53 = 3;
            }
            qmemcpy(&pos.m_pMSTActualMesh, &v118[96 * v53 + 4], 0x20u);
            HIBYTE(v114) |= 8u;
          }
          v54 = *((_DWORD *)i + 8);
          if ( v54 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v54 )
            {
              v55 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v54 )
            {
              v55 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v54 )
            {
              v55 = 2;
            }
            else if ( *((_DWORD *)i + 6) == v54 )
            {
              v55 = 3;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 8) + 32))(a1: *((_DWORD *)i + 8), a2: v124);
              v55 = 4;
            }
            v56 = BYTE2(v120[24 * v55 + 1]);
            HIBYTE(v114) |= 0x80u;
            BYTE2(v114) = v56;
          }
          v57 = *((_DWORD *)i + 10);
          if ( v57 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v57 )
            {
              v58 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v57 )
            {
              v58 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v57 )
            {
              v58 = 2;
            }
            else if ( *((_DWORD *)i + 6) == v57 )
            {
              v58 = 3;
            }
            else if ( *((_DWORD *)i + 8) == v57 )
            {
              v58 = 4;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 10) + 32))(a1: *((_DWORD *)i + 10), a2: v125);
              v58 = 5;
            }
            v59 = v120[24 * v58 + 1];
            HIBYTE(v114) |= 0x40u;
            LOWORD(v114) = v59;
          }
          v60 = *((_DWORD *)i + 11);
          if ( v60 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v60 )
            {
              v61 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v60 )
            {
              v61 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v60 )
            {
              v61 = 2;
            }
            else if ( *((_DWORD *)i + 6) == v60 )
            {
              v61 = 3;
            }
            else if ( *((_DWORD *)i + 8) == v60 )
            {
              v61 = 4;
            }
            else if ( *((_DWORD *)i + 10) == v60 )
            {
              v61 = 5;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 11) + 32))(a1: *((_DWORD *)i + 11), a2: v126);
              v61 = 6;
            }
            v62 = *(float *)&v118[96 * v61 + 60];
            HIBYTE(v114) |= 0x10u;
            *(float *)&pos.m_pVertexOverride = v62;
          }
          v63 = *((_DWORD *)i + 7);
          if ( v63 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v63 )
            {
              v64 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v63 )
            {
              v64 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v63 )
            {
              v64 = 2;
            }
            else if ( *((_DWORD *)i + 6) == v63 )
            {
              v64 = 3;
            }
            else if ( *((_DWORD *)i + 8) == v63 )
            {
              v64 = 4;
            }
            else if ( *((_DWORD *)i + 10) == v63 )
            {
              v64 = 5;
            }
            else if ( *((_DWORD *)i + 11) == v63 )
            {
              v64 = 6;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 7) + 32))(a1: *((_DWORD *)i + 7), a2: v127);
              v64 = 7;
            }
            GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::operator=(
              a1: &pos,
              this: &v117[24 * v64],
              a: *(_ULARGE_INTEGER *)&v104);
            HIBYTE(v114) |= 0x20u;
          }
          v65 = &v128;
          for ( k = 7; k >= 0; --k )
          {
            v67 = (void *)*(v65 - 24);
            v65 -= 24;
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v67);
          }
          v68 = v111;
          GFxDisplayList::MoveDisplayObject(
            this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)&v111[7],
            (CLateBoundPtr<IMesh>)&pos,
            a3: v104);
          *(_DWORD *)(v68[6].FileIndex + 9332) |= 0x400u;
          goto LABEL_100;
        case 2u:
          memset(&pos, 0, 12);
          GRenderer::Cxform::Cxform(this: (float *)&pos.m_pMSTActualMesh);
          GMatrix2D::SetIdentity(this: (float *)&pos.m_pIndexData);
          v69 = *((_DWORD *)i + 4);
          *(float *)&pos.m_pVertexOverride = 0.0;
          v114 = 0;
          *((_DWORD *)&pos.m_pIndexOverride + 1) = 0x40000;
          pos.m_pIndexOverride = nullptr;
          (*(void (__thiscall **)(int, CMatQueuedMesh *))(*(_DWORD *)v69 + 32))(a1: v69, a2: &pos);
          v70 = 7;
          v71 = v118;
          do
          {
            *((_DWORD *)v71 - 2) = 0;
            *((_DWORD *)v71 - 1) = 0;
            *(_DWORD *)v71 = 0;
            GRenderer::Cxform::Cxform(this: (float *)v71 + 1);
            GMatrix2D::SetIdentity(this: (float *)v71 + 9);
            *((_DWORD *)v71 + 17) = 0x40000;
            v71[75] = 0;
            *((float *)v71 + 15) = 0.0;
            *((_DWORD *)v71 + 16) = 0;
            *((_WORD *)v71 + 36) = 0;
            v71[74] = 0;
            v71 += 96;
            --v70;
          }
          while ( v70 >= 0 );
          v72 = *((_DWORD *)i + 9);
          if ( v72 != *((_DWORD *)i + 4) )
          {
            (*(void (__thiscall **)(int, IStream *))(*(_DWORD *)v72 + 32))(a1: v72, a2: v117);
            HIBYTE(v114) |= 1u;
            pos.m_pIndexOverride = v119;
          }
          v73 = *((_DWORD *)i + 12);
          if ( v73 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v73 )
            {
              v74 = 0;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 12) + 32))(a1: *((_DWORD *)i + 12), a2: v121);
              v74 = 1;
            }
            v75 = v120[24 * v74];
            HIBYTE(v114) |= 2u;
            *((_DWORD *)&pos.m_pIndexOverride + 1) = v75;
          }
          v76 = *((_DWORD *)i + 5);
          if ( v76 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v76 )
            {
              v77 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v76 )
            {
              v77 = 1;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 5) + 32))(a1: *((_DWORD *)i + 5), a2: v122);
              v77 = 2;
            }
            v78 = 96 * v77;
            v79 = *(float *)&v118[v78 + 36];
            HIBYTE(v114) |= 4u;
            *(float *)&pos.m_pIndexData = v79;
            v80 = &v118[v78 + 36];
            pos.m_nVerts = *((int *)v80 + 1);
            pos.m_nIndices = *((int *)v80 + 2);
            *(float *)&pos.m_VertexSize = *((float *)v80 + 3);
            *(float *)&pos.m_bExternalIB = *((float *)v80 + 4);
            pos.m_Type = *((MaterialPrimitiveType_t *)v80 + 5);
          }
          v81 = *((_DWORD *)i + 6);
          if ( v81 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v81 )
            {
              v82 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v81 )
            {
              v82 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v81 )
            {
              v82 = 2;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 6) + 32))(a1: *((_DWORD *)i + 6), a2: v123);
              v82 = 3;
            }
            qmemcpy(&pos.m_pMSTActualMesh, &v118[96 * v82 + 4], 0x20u);
            HIBYTE(v114) |= 8u;
          }
          v83 = *((_DWORD *)i + 8);
          if ( v83 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v83 )
            {
              v84 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v83 )
            {
              v84 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v83 )
            {
              v84 = 2;
            }
            else if ( *((_DWORD *)i + 6) == v83 )
            {
              v84 = 3;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 8) + 32))(a1: *((_DWORD *)i + 8), a2: v124);
              v84 = 4;
            }
            v85 = BYTE2(v120[24 * v84 + 1]);
            HIBYTE(v114) |= 0x80u;
            BYTE2(v114) = v85;
          }
          v86 = *((_DWORD *)i + 10);
          if ( v86 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v86 )
            {
              v87 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v86 )
            {
              v87 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v86 )
            {
              v87 = 2;
            }
            else if ( *((_DWORD *)i + 6) == v86 )
            {
              v87 = 3;
            }
            else if ( *((_DWORD *)i + 8) == v86 )
            {
              v87 = 4;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 10) + 32))(a1: *((_DWORD *)i + 10), a2: v125);
              v87 = 5;
            }
            v88 = v120[24 * v87 + 1];
            HIBYTE(v114) |= 0x40u;
            LOWORD(v114) = v88;
          }
          v89 = *((_DWORD *)i + 11);
          if ( v89 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v89 )
            {
              v90 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v89 )
            {
              v90 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v89 )
            {
              v90 = 2;
            }
            else if ( *((_DWORD *)i + 6) == v89 )
            {
              v90 = 3;
            }
            else if ( *((_DWORD *)i + 8) == v89 )
            {
              v90 = 4;
            }
            else if ( *((_DWORD *)i + 10) == v89 )
            {
              v90 = 5;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 11) + 32))(a1: *((_DWORD *)i + 11), a2: v126);
              v90 = 6;
            }
            v91 = *(float *)&v118[96 * v90 + 60];
            HIBYTE(v114) |= 0x10u;
            *(float *)&pos.m_pVertexOverride = v91;
          }
          v92 = *((_DWORD *)i + 7);
          if ( v92 != *((_DWORD *)i + 4) )
          {
            if ( *((_DWORD *)i + 9) == v92 )
            {
              v93 = 0;
            }
            else if ( *((_DWORD *)i + 12) == v92 )
            {
              v93 = 1;
            }
            else if ( *((_DWORD *)i + 5) == v92 )
            {
              v93 = 2;
            }
            else if ( *((_DWORD *)i + 6) == v92 )
            {
              v93 = 3;
            }
            else if ( *((_DWORD *)i + 8) == v92 )
            {
              v93 = 4;
            }
            else if ( *((_DWORD *)i + 10) == v92 )
            {
              v93 = 5;
            }
            else if ( *((_DWORD *)i + 11) == v92 )
            {
              v93 = 6;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)i + 7) + 32))(a1: *((_DWORD *)i + 7), a2: v127);
              v93 = 7;
            }
            GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::operator=(
              a1: &pos,
              this: &v117[24 * v93],
              a: *(_ULARGE_INTEGER *)&v104);
            HIBYTE(v114) |= 0x20u;
          }
          v94 = &v128;
          for ( m = 7; m >= 0; --m )
          {
            v96 = (void *)*(v94 - 24);
            v94 -= 24;
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v96);
          }
          v97 = ((int (__thiscall *)(GMemoryFile *))v111->__vftable[1].Write)(a1: v111);
          if ( v116 != 0 )
          {
            v101 = *(const char **)(*(_DWORD *)(v97 + 120) + 636);
            v112 |= 8u;
            GASStringManager::CreateStringNode(this: v101);
            v98 = v107;
            v99 = v102;
            ++*(_DWORD *)(v102 + 8);
            v110 = v102;
            v100 = &v110;
          }
          else
          {
            v98 = *(_DWORD *)(*(_DWORD *)(v97 + 120) + 8);
            v112 |= 4u;
            v99 = v110;
            ++*(_DWORD *)(v98 + 8);
            v107 = v98;
            v100 = &v107;
          }
          v109 = *v100;
          ++*(_DWORD *)(v109 + 8);
          if ( (v112 & 8) != 0 )
          {
            v112 &= ~8u;
            v38 = (*(_DWORD *)(v99 + 8))-- == 1;
            if ( v38 )
              GASStringNode::ReleaseNode();
          }
          if ( (v112 & 4) != 0 )
          {
            v112 &= ~4u;
            v38 = (*(_DWORD *)(v98 + 8))-- == 1;
            if ( v38 )
              GASStringNode::ReleaseNode();
          }
          GFxSprite::ReplaceDisplayObject(this: v111, name: (_IMAGE_SYMBOL_EX *)&pos, a3: (int)&v109);
          v38 = (*(_DWORD *)(v109 + 8))-- == 1;
          if ( v38 )
LABEL_99:
            GASStringNode::ReleaseNode();
LABEL_100:
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: pos.IMesh::IVertexBuffer::__vftable);
          break;
        case 3u:
          v103 = v111;
          GFxDisplayList::RemoveDisplayObject(
            this: (GFxDisplayList *)&v111[7],
            depth: *((_DWORD *)i + 3),
            a3: (struct GFxResourceId)0x40000);
          *(_DWORD *)(v103[6].FileIndex + 9332) |= 0x400u;
          break;
        default:
          break;
      }
      result = (const char *)HIDWORD(v104);
      if ( i == *(unsigned __int8 **)HIDWORD(v104) )
        break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BC670
// Name: public: virtual void GFxSprite::GotoFrame(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSprite::GotoFrame(GPtr<GFxZlibSupportBase> *this, GFxZlibSupportBase *targetFrameNumber)
{
  int v3; // eax
  int v4; // eax
  GFxZlibSupportBase *v5; // eax
  GFxZlibSupportBase *v6; // edi
  unsigned int v7; // eax
  const CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *v8; // eax
  int v9; // eax
  GFxZlibSupportBase *i; // ebx
  char psnapshot[4]; // [esp+4h] [ebp-34h] BYREF
  int v12; // [esp+8h] [ebp-30h]
  int v13; // [esp+Ch] [ebp-2Ch]
  int v14; // [esp+10h] [ebp-28h]
  int v15; // [esp+14h] [ebp-24h]
  int v16; // [esp+18h] [ebp-20h]
  int v17; // [esp+1Ch] [ebp-1Ch]
  int v18; // [esp+20h] [ebp-18h]
  int v19; // [esp+24h] [ebp-14h]
  _DWORD v20[4]; // [esp+28h] [ebp-10h] BYREF

  if ( (*((_WORD *)this + 59) & 0x100) == 0 && *((int *)this + 5) >= -1 )
  {
    v3 = *((_DWORD *)this + 112);
    if ( v3 == 0 || *(_BYTE *)(v3 + 24) != 0 )
      v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 46) + 40))(a1: *((_DWORD *)this + 46));
    else
      v4 = *(_DWORD *)(v3 + 16);
    v5 = (GFxZlibSupportBase *)(v4 - 1);
    if ( (int)targetFrameNumber < (int)v5 )
      v5 = targetFrameNumber;
    v6 = (int)v5 < 0 ? nullptr : v5;
    GFxSprite::SetStreamingSound((GFxValue *)this, a2: nullptr);
    v7 = *((_DWORD *)this + 54);
    if ( (unsigned int)v6 >= v7 )
    {
      if ( (unsigned int)v6 > v7 )
      {
        if ( (unsigned int)v6 <= 1 || (unsigned int)v6 <= v7 + 1 )
        {
          *((_DWORD *)this + 54) = v6;
        }
        else
        {
          v9 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 47) + 244))(a1: *((_DWORD *)this + 47));
          GFxTimelineSnapshot::GFxTimelineSnapshot(this: psnapshot, a2: 0, a3: v9, a4: (int)this);
          GFxSprite::MakeSnapshot(
            (GFxSprite *)this,
            a2: (struct GFxTimelineSnapshot *)psnapshot,
            a3: (char *)(*((_DWORD *)this + 54) + 1),
            a4: (char *)&v6[-1].SType + 3);
          for ( i = (GFxZlibSupportBase *)(*((_DWORD *)this + 54) + 1); i < v6; i = (GFxZlibSupportBase *)((char *)i + 1) )
            GFxSprite::ExecuteInitActionFrameTags(this, frame: i);
          *((_DWORD *)this + 54) = v6;
          GFxSprite::ExecuteSnapshot((GFxValue *)this, (const CMatQueuedMesh *)psnapshot, prio: (GFxValue *)4);
          GFxTimelineSnapshot::~GFxTimelineSnapshot(this: (GFxTimelineSnapshot *)psnapshot);
        }
        GFxSprite::ExecuteFrameTags(this, frame: v6);
      }
      *((_DWORD *)this + 53) = 1;
    }
    else
    {
      if ( v6 != nullptr )
        v8 = (const CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *)((char *)&v6[-1].SType + 3);
      else
        v8 = nullptr;
      GFxDisplayList::MarkAllEntriesForRemoval(result: v8);
      if ( v6 != nullptr )
      {
        v15 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 47) + 244))(a1: *((_DWORD *)this + 47));
        v19 = v15;
        v20[0] = v20;
        v20[1] = v20;
        *(_DWORD *)psnapshot = 0;
        v12 = 0;
        v14 = 0;
        v16 = 0;
        v17 = 0;
        v18 = 0;
        v13 = 50;
        v20[2] = this;
        v20[3] = 1;
        GFxSprite::MakeSnapshot(
          (GFxSprite *)this,
          a2: (struct GFxTimelineSnapshot *)psnapshot,
          a3: nullptr,
          a4: (char *)&v6[-1].SType + 3);
        *((_DWORD *)this + 54) = v6;
        GFxSprite::ExecuteSnapshot((GFxValue *)this, (const CMatQueuedMesh *)psnapshot, prio: (GFxValue *)4);
        GFxTimelineSnapshot::~GFxTimelineSnapshot(this: (GFxTimelineSnapshot *)psnapshot);
      }
      else
      {
        *((_DWORD *)this + 54) = 0;
      }
      GFxSprite::ExecuteFrameTags(this, frame: v6);
      GFxDisplayList::UnloadMarkedObjects(this: (GFxDisplayList *)(this + 49));
      *((_DWORD *)this + 53) = 1;
    }
  }
}
