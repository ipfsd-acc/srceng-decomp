// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/amp/gfxampmessage.cpp
// Functions: 62
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\amp\gfxampmessage.h"

//------------------------------------------------------------------------------
// Address: 0x100FC540
// Name: public: class GFxAmpMessage __near * GFxAmpThreadMgr::GFxAmpMsgQueue::PopFront(void)
// Source: json
//------------------------------------------------------------------------------
struct GFxAmpMessage *__thiscall GFxAmpThreadMgr::GFxAmpMsgQueue::PopFront(_RTL_CRITICAL_SECTION *this)
{
  _DWORD *v2; // esi
  void **p_LockSemaphore; // ecx
  struct GMemoryHeap *v4; // ebx

  v2 = nullptr;
  EnterCriticalSection(lpCriticalSection: this);
  if ( this == (_RTL_CRITICAL_SECTION *)-24 )
    p_LockSemaphore = nullptr;
  else
    p_LockSemaphore = &this->LockSemaphore;
  if ( *((void ***)this + 7) != p_LockSemaphore )
  {
    v2 = *((_DWORD **)this + 7);
    v4 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: v2);
    *(_DWORD *)(v2[2] + 12) = v2[3];
    *(_DWORD *)(v2[3] + 8) = v2[2];
    InterlockedExchangeAdd(Addend: (volatile LONG *)this + 8, Value: -1);
    GFxAmpThreadMgr::GFxAmpMsgQueue::CheckSize((GFxAmpThreadMgr::GFxAmpMsgQueue *)this, a2: v4);
  }
  LeaveCriticalSection(lpCriticalSection: this);
  return (struct GFxAmpMessage *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x100FD5E0
// Name: public: virtual void GFxAmpMessage::Read(class GFxAmpStream __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxAmpMessage::Read@<eax>(IShaderDynamicAPI *this@<ecx>, int str, float *a3, int a4, int a5, int *a6)
{
  int v6; // esi
  void (__thiscall *v7)(int, unsigned __int8 *, int); // edx
  void (__thiscall *v9)(int, int *, int); // edx
  int result; // eax
  unsigned __int8 v11; // [esp+Bh] [ebp-1h] BYREF

  v6 = str;
  v7 = *(void (__thiscall **)(int, unsigned __int8 *, int))(*(_DWORD *)str + 40);
  v11 = 0;
  v7(a1: str, a2: &v11, a3: 1);
  *((_DWORD *)this + 4) = v11;
  v9 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)v6 + 40);
  str = 0;
  v9(a1: v6, a2: &str, a3: 4);
  result = str;
  *((_DWORD *)this + 5) = str;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FD630
// Name: public: virtual void GFxAmpMessage::Write(class GFxAmpStream __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessage::Write(GFxAmpMessage *this, struct GFxAmpStream *Version)
{
  struct GFxAmpStream *v2; // esi
  void (__thiscall *v3)(struct GFxAmpStream *, _BYTE *, int); // edx
  void (__thiscall *v5)(struct GFxAmpStream *, struct GFxAmpStream **, int); // edx
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  v2 = Version;
  v3 = *(void (__thiscall **)(struct GFxAmpStream *, _BYTE *, int))(*(_DWORD *)Version + 36);
  v6[0] = this->MsgType;
  v3(a1: Version, a2: v6, a3: 1);
  v5 = *(void (__thiscall **)(struct GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  Version = (struct GFxAmpStream *)this->Version;
  v5(a1: v2, a2: &Version, a3: 4);
}

//------------------------------------------------------------------------------
// Address: 0x100FD670
// Name: public: virtual void GFxAmpMessageText::Read(class GFxAmpStream __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageText::Read(ITextureInternal *this, GFxAmpStream *a2)
{
  GFxAmpStream *v2; // esi
  void (__thiscall *v3)(GFxAmpStream *, unsigned __int8 *, int); // edx
  void (__thiscall *v5)(GFxAmpStream *, GFxAmpStream **, int); // edx
  unsigned __int8 v6; // [esp+Bh] [ebp-1h] BYREF

  v2 = a2;
  v3 = *(void (__thiscall **)(GFxAmpStream *, unsigned __int8 *, int))(*(_DWORD *)a2 + 40);
  v6 = 0;
  v3(a1: a2, a2: &v6, a3: 1);
  *((_DWORD *)this + 4) = v6;
  v5 = *(void (__thiscall **)(GFxAmpStream *, GFxAmpStream **, int))(*(_DWORD *)v2 + 40);
  a2 = nullptr;
  v5(a1: v2, &a2, a3: 4);
  *((_DWORD *)this + 5) = a2;
  GFxAmpStream::ReadString(this: v2, a2: (struct GString *)this + 6);
}

//------------------------------------------------------------------------------
// Address: 0x100FD6D0
// Name: public: virtual void GFxAmpMessageText::Write(class GFxAmpStream __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageText::Write(ITextureInternal *this, GFxAmpStream *str)
{
  GFxAmpStream *v2; // esi
  void (__thiscall *v3)(GFxAmpStream *, _BYTE *, int); // edx
  void (__thiscall *v5)(GFxAmpStream *, GFxAmpStream **, int); // edx
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  v2 = str;
  v3 = *(void (__thiscall **)(GFxAmpStream *, _BYTE *, int))(*(_DWORD *)str + 36);
  v6[0] = *((_BYTE *)this + 16);
  v3(a1: str, a2: v6, a3: 1);
  v5 = *(void (__thiscall **)(GFxAmpStream *, GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  str = *((GFxAmpStream **)this + 5);
  v5(a1: v2, a2: &str, a3: 4);
  GFxAmpStream::WriteString(this: v2, Length: (struct GString *)this + 6);
}

//------------------------------------------------------------------------------
// Address: 0x100FD720
// Name: public: virtual bool GFxAmpMessageLog::AcceptHandler(class GFxAmpMsgHandler __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageLog::AcceptHandler(
        CMemberFuncProxyBase<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(unsigned int,float),CFuncMemPolicyNone> *this,
        int a2)
{
  (*(void (__thiscall **)(int, CMemberFuncProxyBase<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(unsigned int,float),CFuncMemPolicyNone> *))(*(_DWORD *)a2 + 28))(
    a1: a2,
    a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100FD740
// Name: public: virtual void GFxAmpMessageLog::Read(class GFxAmpStream __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpMessageLog::Read(
        CMemberFuncProxyBase<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(unsigned int,float),CFuncMemPolicyNone> *this@<ecx>,
        IColorCorrectionSystem *str,
        __int128 a3)
{
  GFxAmpStream *v3; // esi
  void (__thiscall *UnlockLookup_2)(IColorCorrectionSystem *); // edx
  void (__thiscall *v6)(GFxAmpStream *, IColorCorrectionSystem **, int); // edx
  void (__thiscall *v7)(GFxAmpStream *, IColorCorrectionSystem **, int); // edx
  int i; // edi
  void (__thiscall *v9)(GFxAmpStream *, IColorCorrectionSystem **, int); // edx
  unsigned __int8 v10; // [esp+Fh] [ebp-1h] BYREF

  v3 = (GFxAmpStream *)str;
  UnlockLookup_2 = str->UnlockLookup_2;
  v10 = 0;
  ((void (__thiscall *)(IColorCorrectionSystem *, unsigned __int8 *, int))UnlockLookup_2)(a1: str, a2: &v10, a3: 1);
  this->m_pObject = (IColorCorrectionSystem *)v10;
  v6 = *(void (__thiscall **)(GFxAmpStream *, IColorCorrectionSystem **, int))(*(_DWORD *)v3 + 40);
  str = nullptr;
  v6(a1: v3, a2: &str, a3: 4);
  (&this->m_pObject)[1] = str;
  GFxAmpStream::ReadString(this: v3, a2: (struct GString *)this + 6);
  v7 = *(void (__thiscall **)(GFxAmpStream *, IColorCorrectionSystem **, int))(*(_DWORD *)v3 + 40);
  str = nullptr;
  v7(a1: v3, a2: &str, a3: 4);
  *((_DWORD *)this + 7) = str;
  GFxAmpStream::ReadString(this: v3, a2: (struct GString *)this + 8);
  if ( (&this->m_pObject)[1] <= (IColorCorrectionSystem *)2 )
  {
    for ( i = 128; i != 0; --i )
    {
      v9 = *(void (__thiscall **)(GFxAmpStream *, IColorCorrectionSystem **, int))(*(_DWORD *)v3 + 40);
      str = nullptr;
      v9(a1: v3, a2: &str, a3: 4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD7E0
// Name: public: virtual void GFxAmpMessageLog::Write(class GFxAmpStream __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageLog::Write(
        CMemberFuncProxyBase<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(unsigned int,float),CFuncMemPolicyNone> *this,
        IColorCorrectionSystem *str)
{
  GFxAmpStream *v2; // esi
  void (__thiscall *UnlockLookup)(IColorCorrectionSystem *, unsigned int, bool); // edx
  void (__thiscall *v5)(GFxAmpStream *, IColorCorrectionSystem **, int); // edx
  void (__thiscall *v6)(GFxAmpStream *, IColorCorrectionSystem **, int); // edx
  int i; // edi
  void (__thiscall *v8)(GFxAmpStream *, IColorCorrectionSystem **, int); // edx
  _BYTE v9[4]; // [esp+8h] [ebp-4h] BYREF

  v2 = (GFxAmpStream *)str;
  UnlockLookup = str->UnlockLookup;
  v9[0] = this->m_pObject;
  UnlockLookup(this: str, a2: (unsigned int)v9, a3: true);
  v5 = *(void (__thiscall **)(GFxAmpStream *, IColorCorrectionSystem **, int))(*(_DWORD *)v2 + 36);
  str = (&this->m_pObject)[1];
  v5(a1: v2, a2: &str, a3: 4);
  GFxAmpStream::WriteString(this: v2, Length: (struct GString *)this + 6);
  v6 = *(void (__thiscall **)(GFxAmpStream *, IColorCorrectionSystem **, int))(*(_DWORD *)v2 + 36);
  str = *((IColorCorrectionSystem **)this + 7);
  v6(a1: v2, a2: &str, a3: 4);
  GFxAmpStream::WriteString(this: v2, Length: (struct GString *)this + 8);
  if ( (&this->m_pObject)[1] <= (IColorCorrectionSystem *)2 )
  {
    for ( i = 128; i != 0; --i )
    {
      v8 = *(void (__thiscall **)(GFxAmpStream *, IColorCorrectionSystem **, int))(*(_DWORD *)v2 + 36);
      str = nullptr;
      v8(a1: v2, a2: &str, a3: 4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD880
// Name: public: virtual bool GFxAmpMessageCurrentState::AcceptHandler(class GFxAmpMsgHandler __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageCurrentState::AcceptHandler(void *this, void *a2)
{
  (*(void (__thiscall **)(void *, void *))(*(_DWORD *)a2 + 24))(a1: a2, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100FD8A0
// Name: public: virtual bool GFxAmpMessageProfileFrame::AcceptHandler(class GFxAmpMsgHandler __near *)const
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *__thiscall GFxAmpMessageProfileFrame::AcceptHandler(
        void *this,
        const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *result)
{
  return (*(const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *(__thiscall **)(const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *, void *))(LODWORD(result->m_pfnProxied) + 20))(
           a1: result,
           a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100FD8C0
// Name: public: virtual bool GFxAmpMessageSwdFile::AcceptHandler(class GFxAmpMsgHandler __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageSwdFile::AcceptHandler(CJob *this, int handler)
{
  (*(void (__thiscall **)(int, CJob *))(*(_DWORD *)handler + 4))(a1: handler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100FD8E0
// Name: public: virtual bool GFxAmpMessageSourceFile::AcceptHandler(class GFxAmpMsgHandler __near *)const
// Source: json
//------------------------------------------------------------------------------
ICvar *__thiscall GFxAmpMessageSourceFile::AcceptHandler(void *this, ICvar *result)
{
  return ((ICvar *(__thiscall *)(ICvar *, void *))result->Init)(a1: result, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100FD900
// Name: public: virtual bool GFxAmpMessageSwdRequest::AcceptHandler(class GFxAmpMsgHandler __near *)const
// Source: json
//------------------------------------------------------------------------------
const ICvar::ICVarIteratorInternal *__thiscall GFxAmpMessageSwdRequest::AcceptHandler(
        void *this,
        const ICvar::ICVarIteratorInternal *result)
{
  return ((const ICvar::ICVarIteratorInternal *(__thiscall *)(const ICvar::ICVarIteratorInternal *, void *))result->IsValid)(
           a1: result,
           a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100FD920
// Name: public: virtual void GFxAmpMessageSwdRequest::Read(class GFxAmpStream __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageSwdRequest::Read(
        ICvar::ICVarIteratorInternal *this,
        const ICvar::ICVarIteratorInternal *str)
{
  const ICvar::ICVarIteratorInternal *v2; // esi
  bool (__thiscall *IsValid)(ICvar::ICVarIteratorInternal *); // edx
  bool (__thiscall *v5)(ICvar::ICVarIteratorInternal *); // edx
  bool (__thiscall *v6)(ICvar::ICVarIteratorInternal *); // edx
  bool (__thiscall *v7)(ICvar::ICVarIteratorInternal *); // edx
  unsigned __int8 v8; // [esp+Fh] [ebp-1h] BYREF

  v2 = str;
  IsValid = str->__vftable[2].IsValid;
  v8 = 0;
  ((void (__thiscall *)(const ICvar::ICVarIteratorInternal *, unsigned __int8 *, int))IsValid)(a1: str, a2: &v8, a3: 1);
  *((_DWORD *)this + 4) = v8;
  v5 = v2->__vftable[2].IsValid;
  str = nullptr;
  ((void (__thiscall *)(const ICvar::ICVarIteratorInternal *, const ICvar::ICVarIteratorInternal **, int))v5)(
    a1: v2,
    a2: &str,
    a3: 4);
  *((_DWORD *)this + 5) = str;
  v6 = v2->__vftable[2].IsValid;
  str = nullptr;
  ((void (__thiscall *)(const ICvar::ICVarIteratorInternal *, const ICvar::ICVarIteratorInternal **, int))v6)(
    a1: v2,
    a2: &str,
    a3: 4);
  *((_DWORD *)this + 6) = str;
  v7 = v2->__vftable[2].IsValid;
  HIBYTE(str) = 0;
  ((void (__thiscall *)(const ICvar::ICVarIteratorInternal *, char *, int))v7)(a1: v2, a2: (char *)&str + 3, a3: 1);
  *((_BYTE *)this + 28) = HIBYTE(str) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FD9A0
// Name: public: virtual void GFxAmpMessageSwdRequest::Write(class GFxAmpStream __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageSwdRequest::Write(ICvar::ICVarIteratorInternal *this, int a2)
{
  int v2; // esi
  void (__thiscall *v3)(int, _BYTE *, int); // edx
  void (__thiscall *v5)(int, int *, int); // edx
  void (__thiscall *v6)(int, int *, int); // edx
  void (__thiscall *v7)(int, int *, int); // edx
  _BYTE v8[4]; // [esp+8h] [ebp-4h] BYREF

  v2 = a2;
  v3 = *(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a2 + 36);
  v8[0] = *((_BYTE *)this + 16);
  v3(a1: a2, a2: v8, a3: 1);
  v5 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)v2 + 36);
  a2 = *((_DWORD *)this + 5);
  v5(a1: v2, &a2, a3: 4);
  v6 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)v2 + 36);
  a2 = *((_DWORD *)this + 6);
  v6(a1: v2, &a2, a3: 4);
  v7 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)v2 + 36);
  LOBYTE(a2) = *((_BYTE *)this + 28) != 0;
  v7(a1: v2, &a2, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100FDA10
// Name: public: bool GFxAmpMessageSwdRequest::IsRequestContents(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxAmpMessageSwdRequest::IsRequestContents(GFxAmpMessageSwdRequest *this)
{
  return this->RequestContents;
}

//------------------------------------------------------------------------------
// Address: 0x100FDA20
// Name: public: virtual bool GFxAmpMessageSourceRequest::AcceptHandler(class GFxAmpMsgHandler __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxAmpMessageSourceRequest::AcceptHandler(
        GFxAmpMessageSourceRequest *this,
        struct GFxAmpMsgHandler *a2)
{
  return a2->HandleSourceRequest(this: a2, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100FDA40
// Name: public: virtual void GFxAmpMessageSourceRequest::Read(class GFxAmpStream __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxAmpMessageSourceRequest::Read(TableVector *this, int a2)
{
  int v2; // esi
  void (__thiscall *v3)(int, unsigned __int8 *, int); // edx
  void (__thiscall *v5)(int, int *, int); // edx
  void (__thiscall *v6)(int, int *, int); // edx
  int v7; // ecx
  void (__thiscall *v8)(int, char *, int); // edx
  bool result; // al
  int v10; // [esp+Ch] [ebp-Ch] BYREF
  int v11; // [esp+10h] [ebp-8h]
  unsigned __int8 v12; // [esp+17h] [ebp-1h] BYREF

  v2 = a2;
  v3 = *(void (__thiscall **)(int, unsigned __int8 *, int))(*(_DWORD *)a2 + 40);
  v12 = 0;
  v3(a1: a2, a2: &v12, a3: 1);
  *((_DWORD *)this + 4) = v12;
  v5 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)v2 + 40);
  a2 = 0;
  v5(a1: v2, &a2, a3: 4);
  *((_DWORD *)this + 5) = a2;
  v6 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)v2 + 40);
  v10 = 0;
  v11 = 0;
  v6(a1: v2, a2: &v10, a3: 8);
  v7 = v11;
  *((_DWORD *)this + 6) = v10;
  *((_DWORD *)this + 7) = v7;
  v8 = *(void (__thiscall **)(int, char *, int))(*(_DWORD *)v2 + 40);
  HIBYTE(a2) = 0;
  v8(a1: v2, a2: (char *)&a2 + 3, a3: 1);
  result = HIBYTE(a2) != 0;
  *((_BYTE *)this + 32) = HIBYTE(a2) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FDAD0
// Name: public: virtual void GFxAmpMessageSourceRequest::Write(class GFxAmpStream __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageSourceRequest::Write(GFxAmpMessageSourceRequest *this, struct GFxAmpStream *Version)
{
  struct GFxAmpStream *v2; // esi
  void (__thiscall *v3)(struct GFxAmpStream *, _BYTE *, int); // edx
  void (__thiscall *v5)(struct GFxAmpStream *, struct GFxAmpStream **, int); // edx
  int FileHandle_high; // ecx
  void (__thiscall *v7)(struct GFxAmpStream *, _DWORD *, int); // edx
  void (__thiscall *v8)(struct GFxAmpStream *, struct GFxAmpStream **, int); // edx
  _DWORD v9[2]; // [esp+8h] [ebp-Ch] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = Version;
  v3 = *(void (__thiscall **)(struct GFxAmpStream *, _BYTE *, int))(*(_DWORD *)Version + 36);
  v10[0] = this->MsgType;
  v3(a1: Version, a2: v10, a3: 1);
  v5 = *(void (__thiscall **)(struct GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  Version = (struct GFxAmpStream *)this->Version;
  v5(a1: v2, a2: &Version, a3: 4);
  FileHandle_high = HIDWORD(this->FileHandle);
  v7 = *(void (__thiscall **)(struct GFxAmpStream *, _DWORD *, int))(*(_DWORD *)v2 + 36);
  v9[0] = this->FileHandle;
  v9[1] = FileHandle_high;
  v7(a1: v2, a2: v9, a3: 8);
  v8 = *(void (__thiscall **)(struct GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  LOBYTE(Version) = this->RequestContents;
  v8(a1: v2, a2: &Version, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100FDB50
// Name: public: unsigned __int64 GFxAmpMessageSourceRequest::GetFileHandle(void)const
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall GFxAmpMessageSourceRequest::GetFileHandle(_QWORD *this)
{
  return *(this + 3);
}

//------------------------------------------------------------------------------
// Address: 0x100FDB60
// Name: public: bool GFxAmpMessageSourceRequest::IsRequestContents(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxAmpMessageSourceRequest::IsRequestContents(TableVector *this)
{
  return *((_BYTE *)this + 32);
}

//------------------------------------------------------------------------------
// Address: 0x100FDB70
// Name: public: virtual bool GFxAmpMessageAppControl::AcceptHandler(class GFxAmpMsgHandler __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxAmpMessageAppControl::AcceptHandler(GFxAmpMessageAppControl *this, struct GFxAmpMsgHandler *a2)
{
  return a2->HandleAppControl(this: a2, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100FDB90
// Name: public: virtual void GFxAmpMessageAppControl::Read(class GFxAmpStream __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageAppControl::Read(struct GString *this, CThreadEvent *result)
{
  GFxAmpStream *v2; // esi
  void (__thiscall *v3)(CThreadEvent *, unsigned __int8 *, int); // edx
  void (__thiscall *v5)(GFxAmpStream *, CThreadEvent **, int); // edx
  void (__thiscall *v6)(GFxAmpStream *, CThreadEvent **, int); // edx
  unsigned __int8 v7; // [esp+Bh] [ebp-1h] BYREF

  v2 = (GFxAmpStream *)result;
  v3 = *((void (__thiscall **)(CThreadEvent *, unsigned __int8 *, int))result->m_hSyncObject + 10);
  v7 = 0;
  v3(a1: result, a2: &v7, a3: 1);
  *((_DWORD *)this + 4) = v7;
  v5 = *(void (__thiscall **)(GFxAmpStream *, CThreadEvent **, int))(*(_DWORD *)v2 + 40);
  result = nullptr;
  v5(a1: v2, a2: &result, a3: 4);
  *((_DWORD *)this + 5) = result;
  v6 = *(void (__thiscall **)(GFxAmpStream *, CThreadEvent **, int))(*(_DWORD *)v2 + 40);
  result = nullptr;
  v6(a1: v2, a2: &result, a3: 4);
  *((_DWORD *)this + 6) = result;
  GFxAmpStream::ReadString(this: v2, a2: this + 7);
}

//------------------------------------------------------------------------------
// Address: 0x100FDC00
// Name: public: virtual void GFxAmpMessageAppControl::Write(class GFxAmpStream __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageAppControl::Write(GFxAmpMessageAppControl *this, struct GFxAmpStream *Version)
{
  GFxAmpStream *v2; // esi
  void (__thiscall *v3)(struct GFxAmpStream *, _BYTE *, int); // edx
  void (__thiscall *v5)(GFxAmpStream *, struct GFxAmpStream **, int); // edx
  void (__thiscall *v6)(GFxAmpStream *, struct GFxAmpStream **, int); // edx
  _BYTE v7[4]; // [esp+8h] [ebp-4h] BYREF

  v2 = Version;
  v3 = *(void (__thiscall **)(struct GFxAmpStream *, _BYTE *, int))(*(_DWORD *)Version + 36);
  v7[0] = this->MsgType;
  v3(a1: Version, a2: v7, a3: 1);
  v5 = *(void (__thiscall **)(GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  Version = (struct GFxAmpStream *)this->Version;
  v5(a1: v2, a2: &Version, a3: 4);
  v6 = *(void (__thiscall **)(GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  Version = (struct GFxAmpStream *)this->BaseValue;
  v6(a1: v2, a2: &Version, a3: 4);
  GFxAmpStream::WriteString(this: v2, Length: &this->LoadMovieFile);
}

//------------------------------------------------------------------------------
// Address: 0x100FDC60
// Name: public: bool GFxAmpMessageAppControl::IsForceInstructionProfile(void)const
// Source: json
//------------------------------------------------------------------------------
const CThreadEvent *__thiscall GFxAmpMessageAppControl::IsForceInstructionProfile(_DWORD *this)
{
  return (const CThreadEvent *)((*(this + 6) & 0x800) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x100FDC80
// Name: public: bool GFxAmpMessageAppControl::IsToggleInstructionProfile(void)const
// Source: json
//------------------------------------------------------------------------------
const CThreadEvent *__thiscall GFxAmpMessageAppControl::IsToggleInstructionProfile(_DWORD *this)
{
  return (const CThreadEvent *)((*(this + 6) & 0x10) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x100FDC90
// Name: public: bool GFxAmpMessageAppControl::IsToggleMemReport(void)const
// Source: json
//------------------------------------------------------------------------------
const CThreadEvent *__thiscall GFxAmpMessageAppControl::IsToggleMemReport(_DWORD *this)
{
  return (const CThreadEvent *)((*(this + 6) & 0x40000) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x100FDCA0
// Name: public: virtual bool GFxAmpMessagePort::AcceptHandler(class GFxAmpMsgHandler __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxAmpMessagePort::AcceptHandler(GFxAmpMessagePort *this, struct GFxAmpMsgHandler *a2)
{
  return a2->HandlePort(this: a2, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100FDCC0
// Name: public: virtual void GFxAmpMessagePort::Read(class GFxAmpStream __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessagePort::Read(
        struct GString *this,
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *result)
{
  GFxAmpStream *v2; // esi
  void (__thiscall *v3)(CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *, unsigned __int8 *, int); // edx
  void (__thiscall *v5)(GFxAmpStream *, CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > **, int); // edx
  void (__thiscall *v6)(GFxAmpStream *, CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > **, int); // edx
  void (__thiscall *v7)(GFxAmpStream *, CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > **, int); // edx
  unsigned __int8 v8; // [esp+Fh] [ebp-1h] BYREF

  v2 = (GFxAmpStream *)result;
  v3 = *(void (__thiscall **)(CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *, unsigned __int8 *, int))(*(_DWORD *)&result->m_LessFunc + 40);
  v8 = 0;
  v3(a1: result, a2: &v8, a3: 1);
  *((_DWORD *)this + 4) = v8;
  v5 = *(void (__thiscall **)(GFxAmpStream *, CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > **, int))(*(_DWORD *)v2 + 40);
  result = nullptr;
  v5(a1: v2, a2: &result, a3: 4);
  *((_DWORD *)this + 5) = result;
  v6 = *(void (__thiscall **)(GFxAmpStream *, CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > **, int))(*(_DWORD *)v2 + 40);
  result = nullptr;
  v6(a1: v2, a2: &result, a3: 4);
  *((_DWORD *)this + 6) = result;
  GFxAmpStream::ReadString(this: v2, a2: this + 8);
  if ( *((_DWORD *)this + 5) >= 5u )
  {
    v7 = *(void (__thiscall **)(GFxAmpStream *, CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > **, int))(*(_DWORD *)v2 + 40);
    result = nullptr;
    v7(a1: v2, a2: &result, a3: 4);
    *((_DWORD *)this + 7) = result;
    GFxAmpStream::ReadString(this: v2, a2: this + 9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FDD60
// Name: public: virtual void GFxAmpMessagePort::Write(class GFxAmpStream __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessagePort::Write(GFxAmpMessagePort *this, struct GFxAmpStream *Version)
{
  GFxAmpStream *v2; // esi
  void (__thiscall *v3)(struct GFxAmpStream *, _BYTE *, int); // edx
  void (__thiscall *v5)(GFxAmpStream *, struct GFxAmpStream **, int); // edx
  void (__thiscall *v6)(GFxAmpStream *, struct GFxAmpStream **, int); // edx
  void (__thiscall *v7)(GFxAmpStream *, struct GFxAmpStream **, int); // edx
  _BYTE v8[4]; // [esp+8h] [ebp-4h] BYREF

  v2 = Version;
  v3 = *(void (__thiscall **)(struct GFxAmpStream *, _BYTE *, int))(*(_DWORD *)Version + 36);
  v8[0] = this->MsgType;
  v3(a1: Version, a2: v8, a3: 1);
  v5 = *(void (__thiscall **)(GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  Version = (struct GFxAmpStream *)this->Version;
  v5(a1: v2, a2: &Version, a3: 4);
  v6 = *(void (__thiscall **)(GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  Version = (struct GFxAmpStream *)this->BaseValue;
  v6(a1: v2, a2: &Version, a3: 4);
  GFxAmpStream::WriteString(this: v2, Length: &this->AppName);
  if ( this->Version >= 5 )
  {
    v7 = *(void (__thiscall **)(GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
    Version = (struct GFxAmpStream *)this->Platform;
    v7(a1: v2, a2: &Version, a3: 4);
    GFxAmpStream::WriteString(this: v2, Length: &this->FileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FDDF0
// Name: public: virtual void GFxAmpMessageCurrentState::Read(class GFxAmpStream __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageCurrentState::Read(GFxAmpMessageCurrentState *this, struct GFile *a2)
{
  struct GFile *v2; // esi
  int (__thiscall *Read)(GFile *, unsigned __int8 *, int); // edx
  int (__thiscall *v5)(GFile *, unsigned __int8 *, int); // edx
  GFxAmpCurrentState *pObject; // ecx
  struct GFxAmpStream *v7; // [esp-4h] [ebp-10h]
  unsigned __int8 v8; // [esp+Bh] [ebp-1h] BYREF

  v2 = a2;
  Read = a2->Read;
  v8 = 0;
  Read(this: a2, a2: &v8, a3: 1);
  this->MsgType = v8;
  v5 = v2->Read;
  a2 = nullptr;
  v5(this: v2, (unsigned __int8 *)&a2, a3: 4);
  pObject = this->State.pObject;
  v7 = (struct GFxAmpStream *)a2;
  this->Version = (unsigned int)a2;
  GFxAmpCurrentState::Read(this: pObject, a2: v2, a3: (unsigned int)v7);
}

//------------------------------------------------------------------------------
// Address: 0x100FDE50
// Name: public: virtual void GFxAmpMessageCurrentState::Write(class GFxAmpStream __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageCurrentState::Write(GFxAmpMessageCurrentState *this, struct GFile *Version)
{
  struct GFile *v3; // edi
  int (__thiscall *Write)(GFile *, const unsigned __int8 *, int); // edx
  int (__thiscall *v5)(GFile *, const unsigned __int8 *, int); // edx
  unsigned __int8 v6[4]; // [esp+8h] [ebp-4h] BYREF

  v3 = Version;
  Write = Version->Write;
  v6[0] = this->MsgType;
  Write(this: Version, a2: v6, a3: 1);
  v5 = v3->Write;
  Version = (struct GFile *)this->Version;
  v5(this: v3, a2: (const unsigned __int8 *)&Version, a3: 4);
  GFxAmpCurrentState::Write(this: this->State.pObject, a2: v3, a3: this->Version);
}

//------------------------------------------------------------------------------
// Address: 0x100FDEA0
// Name: public: virtual void GFxAmpMessageProfileFrame::Read(class GFxAmpStream __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageProfileFrame::Read(GFxAmpMessageProfileFrame *this, unsigned int str)
{
  unsigned int v2; // edi
  void (__thiscall *v3)(unsigned int, unsigned __int8 *, int); // edx
  void (__thiscall *v5)(unsigned int, unsigned int *, int); // edx
  GFxAmpProfileFrame *v6; // ebx
  CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v7; // eax
  GFxAmpProfileFrame *v8; // eax
  IShaderAPI *pObject; // ecx
  unsigned __int16 v10; // [esp+0h] [ebp-10h]
  unsigned __int16 v11; // [esp+4h] [ebp-Ch]
  bool v12; // [esp+8h] [ebp-8h]
  unsigned __int8 v13; // [esp+Fh] [ebp-1h] BYREF

  v2 = str;
  v3 = *(void (__thiscall **)(unsigned int, unsigned __int8 *, int))(*(_DWORD *)str + 40);
  v13 = 0;
  v3(a1: str, a2: &v13, a3: 1);
  this->MsgType = v13;
  v5 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v2 + 40);
  v6 = nullptr;
  str = 0;
  v5(a1: v2, a2: &str, a3: 4);
  this->Version = str;
  str = 2;
  v7 = (CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 208, a4: &str);
  if ( v7 != nullptr )
  {
    GFxAmpProfileFrame::GFxAmpProfileFrame(this: v7, a2: v10, a3: v11, a4: v12);
    v6 = v8;
  }
  pObject = (IShaderAPI *)this->FrameInfo.pObject;
  if ( pObject != nullptr )
    GRefCountImpl::Release(this: pObject);
  this->FrameInfo.pObject = v6;
  GFxAmpProfileFrame::Read(
    this: (CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)v6,
    str: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100FDF30
// Name: public: virtual void GFxAmpMessageProfileFrame::Write(class GFxAmpStream __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageProfileFrame::Write(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *this,
        const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *str)
{
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *v3; // edi
  void (__thiscall *v4)(const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *, _BYTE *, int); // edx
  void (__thiscall *v5)(const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *, const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> **, int); // edx
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  v3 = str;
  v4 = *(void (__thiscall **)(const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *, _BYTE *, int))(LODWORD(str->m_pfnProxied) + 36);
  v6[0] = this->m_pObject;
  v4(a1: str, a2: v6, a3: 1);
  v5 = *(void (__thiscall **)(const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *, const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> **, int))(LODWORD(v3->m_pfnProxied) + 36);
  str = *((const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> **)&this->m_pObject
        + 1);
  v5(a1: v3, a2: &str, a3: 4);
  GFxAmpProfileFrame::Write(
    this: *((CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > **)this
    + 6),
    str: (unsigned __int16)v3,
    version: *((CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> >::NodeColor_t *)&this->m_pObject
    + 1));
}

//------------------------------------------------------------------------------
// Address: 0x100FDF80
// Name: public: virtual void GFxAmpMessageSwdFile::Write(class GFxAmpStream __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageSwdFile::Write(CJob *this, GFxAmpStream *m_ownerID)
{
  GFxAmpStream *v2; // esi
  void (__thiscall *v3)(GFxAmpStream *, _BYTE *, int); // edx
  void (__thiscall *v5)(GFxAmpStream *, GFxAmpStream **, int); // edx
  void (__thiscall *v6)(GFxAmpStream *, GFxAmpStream **, int); // edx
  void (__thiscall *v7)(GFxAmpStream *, GFxAmpStream **, int); // edx
  ThreadPoolData_t__ *i; // ebx
  void (__thiscall *v9)(GFxAmpStream *, GFxAmpStream **, int); // edx
  _BYTE v10[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = m_ownerID;
  v3 = *(void (__thiscall **)(GFxAmpStream *, _BYTE *, int))(*(_DWORD *)m_ownerID + 36);
  v10[0] = this->m_priority;
  v3(a1: m_ownerID, a2: v10, a3: 1);
  v5 = *(void (__thiscall **)(GFxAmpStream *, GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  m_ownerID = (GFxAmpStream *)this->m_mutex.m_ownerID;
  v5(a1: v2, a2: &m_ownerID, a3: 4);
  v6 = *(void (__thiscall **)(GFxAmpStream *, GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  m_ownerID = (GFxAmpStream *)this->m_mutex.m_depth;
  v6(a1: v2, a2: &m_ownerID, a3: 4);
  v7 = *(void (__thiscall **)(GFxAmpStream *, GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  m_ownerID = (GFxAmpStream *)this->m_ThreadPoolData;
  v7(a1: v2, a2: &m_ownerID, a3: 4);
  for ( i = nullptr; i < this->m_ThreadPoolData; i = (ThreadPoolData_t__ *)((char *)i + 1) )
  {
    v9 = *(void (__thiscall **)(GFxAmpStream *, GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
    LOBYTE(m_ownerID) = *((_BYTE *)i + *(_DWORD *)&this->m_flags);
    v9(a1: v2, a2: &m_ownerID, a3: 1);
  }
  GFxAmpStream::WriteString(this: v2, Length: (struct GString *)&this->m_CompleteEvent);
}

//------------------------------------------------------------------------------
// Address: 0x100FE020
// Name: public: virtual void GFxAmpMessageSourceFile::Write(class GFxAmpStream __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageSourceFile::Write(GFxAmpMessageSourceFile *this, struct GFxAmpStream *Version)
{
  GFxAmpStream *v2; // esi
  void (__thiscall *v3)(struct GFxAmpStream *, _BYTE *, int); // edx
  void (__thiscall *v5)(GFxAmpStream *, struct GFxAmpStream **, int); // edx
  int FileHandle_high; // ecx
  void (__thiscall *v7)(GFxAmpStream *, _DWORD *, int); // edx
  void (__thiscall *v8)(GFxAmpStream *, struct GFxAmpStream **, int); // edx
  unsigned int i; // ebx
  void (__thiscall *v10)(GFxAmpStream *, struct GFxAmpStream **, int); // edx
  _DWORD v11[2]; // [esp+Ch] [ebp-Ch] BYREF
  _BYTE v12[4]; // [esp+14h] [ebp-4h] BYREF

  v2 = Version;
  v3 = *(void (__thiscall **)(struct GFxAmpStream *, _BYTE *, int))(*(_DWORD *)Version + 36);
  v12[0] = this->MsgType;
  v3(a1: Version, a2: v12, a3: 1);
  v5 = *(void (__thiscall **)(GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  Version = (struct GFxAmpStream *)this->Version;
  v5(a1: v2, a2: &Version, a3: 4);
  FileHandle_high = HIDWORD(this->FileHandle);
  v7 = *(void (__thiscall **)(GFxAmpStream *, _DWORD *, int))(*(_DWORD *)v2 + 36);
  v11[0] = this->FileHandle;
  v11[1] = FileHandle_high;
  v7(a1: v2, a2: v11, a3: 8);
  v8 = *(void (__thiscall **)(GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
  Version = (struct GFxAmpStream *)this->FileData.Data.Size;
  v8(a1: v2, a2: &Version, a3: 4);
  for ( i = 0; i < this->FileData.Data.Size; ++i )
  {
    v10 = *(void (__thiscall **)(GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v2 + 36);
    LOBYTE(Version) = this->FileData.Data.Data[i];
    v10(a1: v2, a2: &Version, a3: 1);
  }
  GFxAmpStream::WriteString(this: v2, Length: &this->Filename);
}

//------------------------------------------------------------------------------
// Address: 0x100FE150
// Name: public: virtual class GString GFxAmpMessage::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpMessage::ToString(IShaderDynamicAPI *this@<ecx>, GString *a2, int a3, bool *a4)
{
  GString::GString(this: a2, src: (int)"Unknown message");
}

//------------------------------------------------------------------------------
// Address: 0x100FE1D0
// Name: public: virtual class GString GFxAmpMessageProfileFrame::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *__stdcall GFxAmpMessageProfileFrame::ToString(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *result)
{
  GString::GString(this: (GString *)result, src: (int)"Frame data");
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FE1F0
// Name: public: GFxAmpMessageHeartbeat::GFxAmpMessageHeartbeat(void)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxy4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int,int,int),int,int,int,int,CFuncMemPolicyNone> *__thiscall GFxAmpMessageHeartbeat::GFxAmpMessageHeartbeat(
        _DWORD *this)
{
  *this = &GRefCountImplCore::`vftable';
  *(this + 1) = 1;
  *(this + 4) = 1;
  *(this + 5) = 11;
  *this = &GFxAmpMessageHeartbeat::`vftable';
  return (CMemberFuncProxy4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int,int,int),int,int,int,int,CFuncMemPolicyNone> *)this;
}

//------------------------------------------------------------------------------
// Address: 0x100FE220
// Name: public: virtual class GString GFxAmpMessageHeartbeat::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpMessageHeartbeat::ToString(
        CMemberFuncProxy4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int,int,int),int,int,int,int,CFuncMemPolicyNone> *this@<ecx>,
        GString *a2,
        const int *a3,
        const int *a4,
        const int *a5)
{
  GString::GString(this: a2, src: (int)"Heartbeat");
}

//------------------------------------------------------------------------------
// Address: 0x100FE240
// Name: public: GFxAmpMessageLog::GFxAmpMessageLog(class GString const __near &,unsigned long,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageLog::GFxAmpMessageLog(
        IColorCorrectionSystem *this,
        const CFixedBitVecBase<128> *logText,
        float logCategory,
        CUtlMap<char const *,int,unsigned short>::CKeyLess timeStamp,
        unsigned int a5)
{
  char destsize[12]; // [esp+14h] [ebp-10h] BYREF

  this->__vftable = (IColorCorrectionSystem_vtbl *)&GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 4) = 2;
  *((_DWORD *)this + 5) = 11;
  this->__vftable = (IColorCorrectionSystem_vtbl *)&GFxAmpMessageText::`vftable';
  GStringLH::CopyConstructHelper(this: (CCountedStringPoolBase<unsigned int> *)(this + 6), result: logText);
  this->__vftable = (IColorCorrectionSystem_vtbl *)&GFxAmpMessageLog::`vftable';
  *((float *)this + 7) = logCategory;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)this + 2);
  G_sprintf(
    dest: (unsigned __int16)destsize,
    destsize,
    destsizea: 9u,
    format: "%02u:%02u:%02u",
    ap: __PAIR64__(a5, (unsigned int)timeStamp.m_LessFunc) / 0xE10 % 0x18);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 8),
    a2: (unsigned __int8 *)destsize);
}

//------------------------------------------------------------------------------
// Address: 0x100FE320
// Name: public: virtual class GString GFxAmpMessageLog::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
struct GString __thiscall GFxAmpMessageLog::ToString(GFxAmpMessageLog *this, GString *a2)
{
  GString::GString(this: a2, src: (int)"Log");
  return (struct GString)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100FE340
// Name: public: virtual GFxAmpMessageLog::~GFxAmpMessageLog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageLog::~GFxAmpMessageLog(GFxAmpMessageLog *this)
{
  volatile LONG *v2; // edi
  volatile LONG *v3; // edi

  v2 = (volatile LONG *)(this->TimeStamp.HeapTypeBits & 0xFFFFFFFC);
  this->__vftable = (GFxAmpMessageLog_vtbl *)&GFxAmpMessageLog::`vftable';
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = (volatile LONG *)(this->TextValue.HeapTypeBits & 0xFFFFFFFC);
  this->__vftable = (GFxAmpMessageLog_vtbl *)&GFxAmpMessageText::`vftable';
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  this->__vftable = (GFxAmpMessageLog_vtbl *)&GFxAmpMessage::`vftable';
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100FE3E0
// Name: public: GFxAmpMessageCurrentState::GFxAmpMessageCurrentState(class GFxAmpCurrentState const __near *)
// Source: json
//------------------------------------------------------------------------------
IShaderAPI **__thiscall GFxAmpMessageCurrentState::GFxAmpMessageCurrentState(IShaderAPI **this, unsigned int a2)
{
  GFxAmpCurrentState *v3; // eax
  CCheckerboardTexture *v4; // edi
  IShaderAPI *v5; // ecx
  int v7; // [esp+8h] [ebp-4h] BYREF

  *this = (IShaderAPI *)&GRefCountImplCore::`vftable';
  *(this + 1) = (IShaderAPI *)1;
  *(this + 4) = (IShaderAPI *)3;
  *(this + 5) = (IShaderAPI *)11;
  *this = (IShaderAPI *)&GFxAmpMessageCurrentState::`vftable';
  *(this + 6) = nullptr;
  v7 = 2;
  v3 = (GFxAmpCurrentState *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                               this: GMemory::pGlobalHeap,
                               a2: this,
                               a3: 80,
                               a4: &v7);
  if ( v3 != nullptr )
    v4 = (CCheckerboardTexture *)GFxAmpCurrentState::GFxAmpCurrentState(this: v3);
  else
    v4 = nullptr;
  v5 = *(this + 6);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  *(this + 6) = (IShaderAPI *)v4;
  if ( a2 != 0 )
    GFxAmpCurrentState::operator=(this: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FE470
// Name: public: virtual class GString GFxAmpMessageCurrentState::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
struct GString __thiscall GFxAmpMessageCurrentState::ToString(GFxAmpMessageCurrentState *this, GString *a2)
{
  GString::GString(this: a2, src: (int)"Current state");
  return (struct GString)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100FE4D0
// Name: public: GFxAmpMessageProfileFrame::GFxAmpMessageProfileFrame(class GPtr<class GFxAmpProfileFrame>)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxAmpMessageProfileFrame::GFxAmpMessageProfileFrame(_DWORD *this, IShaderDevice *a2)
{
  IShaderAPI *v3; // ecx

  v3 = (IShaderAPI *)a2;
  *this = &GRefCountImplCore::`vftable';
  *(this + 1) = 1;
  *(this + 4) = 4;
  *(this + 5) = 11;
  *this = &GFxAmpMessageProfileFrame::`vftable';
  if ( a2 != nullptr )
  {
    GRefCountImpl::AddRef(this: a2);
    v3 = (IShaderAPI *)a2;
  }
  *(this + 6) = v3;
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FE560
// Name: public: GFxAmpMessageSwdRequest::GFxAmpMessageSwdRequest(unsigned long,bool)
// Source: json
//------------------------------------------------------------------------------
ICvar::ICVarIteratorInternal *__thiscall GFxAmpMessageSwdRequest::GFxAmpMessageSwdRequest(
        ICvar::ICVarIteratorInternal *this,
        unsigned int swfHandle,
        bool requestContents)
{
  this->__vftable = (ICvar::ICVarIteratorInternal_vtbl *)&GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 4) = 7;
  *((_DWORD *)this + 5) = 11;
  *((_DWORD *)this + 6) = swfHandle;
  this->__vftable = (ICvar::ICVarIteratorInternal_vtbl *)&GFxAmpMessageSwdRequest::`vftable';
  *((_BYTE *)this + 28) = requestContents;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FE5A0
// Name: public: virtual class GString GFxAmpMessageSwdRequest::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
struct GString __thiscall GFxAmpMessageSwdRequest::ToString(GFxAmpMessageSwdRequest *this, GString *a2)
{
  GString::GString(this: a2, src: (int)"SWD request");
  return (struct GString)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100FE5C0
// Name: public: GFxAmpMessageSourceRequest::GFxAmpMessageSourceRequest(unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
BGRA8888_t *__thiscall GFxAmpMessageSourceRequest::GFxAmpMessageSourceRequest(
        BGRA8888_t *this,
        int handle,
        int handle_4,
        bool requestContents)
{
  *((_DWORD *)this + 6) = handle;
  *this = (BGRA8888_t)&GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 4) = 8;
  *((_DWORD *)this + 5) = 11;
  *this = (BGRA8888_t)&GFxAmpMessageSourceRequest::`vftable';
  *((_DWORD *)this + 7) = handle_4;
  *((_BYTE *)this + 32) = requestContents;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FE600
// Name: public: virtual class GString GFxAmpMessageSourceRequest::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
TableVector *__stdcall GFxAmpMessageSourceRequest::ToString(TableVector *result)
{
  GString::GString(this: (GString *)result, src: (int)"Source request");
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FE650
// Name: public: GFxAmpMessageAppControl::GFxAmpMessageAppControl(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageAppControl::GFxAmpMessageAppControl(ICachedPerFrameMeshData *this, unsigned int flags)
{
  this->__vftable = (ICachedPerFrameMeshData_vtbl *)&GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 4) = 9;
  *((_DWORD *)this + 5) = 11;
  *((_DWORD *)this + 6) = flags;
  this->__vftable = (ICachedPerFrameMeshData_vtbl *)&GFxAmpMessageAppControl::`vftable';
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(this + 7));
}

//------------------------------------------------------------------------------
// Address: 0x100FE690
// Name: public: virtual class GString GFxAmpMessageAppControl::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
struct GString __thiscall GFxAmpMessageAppControl::ToString(GFxAmpMessageAppControl *this, GString *a2)
{
  GString::GString(this: a2, src: (int)"App control");
  return (struct GString)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100FE710
// Name: public: GFxAmpMessagePort::GFxAmpMessagePort(unsigned long,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CThreadEvent *__thiscall GFxAmpMessagePort::GFxAmpMessagePort(
        CThreadEvent *this,
        unsigned int port,
        unsigned __int8 *a3,
        unsigned __int8 *a4)
{
  this->m_hSyncObject = &GRefCountImplCore::`vftable';
  *(_DWORD *)&this->m_bCreatedHandle = 1;
  *((_DWORD *)this + 4) = 10;
  *((_DWORD *)this + 5) = 11;
  *((_DWORD *)this + 6) = port;
  this->m_hSyncObject = &GFxAmpMessagePort::`vftable';
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)this + 2);
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)((char *)this + 36));
  if ( a3 != nullptr )
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 4),
      a2: a3);
  if ( a4 != nullptr )
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 36),
      a2: a4);
  *((_DWORD *)this + 7) = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FE780
// Name: public: virtual GFxAmpMessagePort::~GFxAmpMessagePort(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessagePort::~GFxAmpMessagePort(GFxAmpMessagePort *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi

  v2 = (volatile LONG *)(this->FileName.HeapTypeBits & 0xFFFFFFFC);
  this->__vftable = (GFxAmpMessagePort_vtbl *)&GFxAmpMessagePort::`vftable';
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = (volatile LONG *)(this->AppName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  this->__vftable = (GFxAmpMessagePort_vtbl *)&GFxAmpMessage::`vftable';
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100FE810
// Name: public: GFxAmpMessageSwdFile::GFxAmpMessageSwdFile(unsigned long,unsigned char __near *,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const CJob *__thiscall GFxAmpMessageSwdFile::GFxAmpMessageSwdFile(
        char *this,
        const CJob *result,
        unsigned __int8 *bufferData,
        unsigned int bufferSize,
        char *pdata)
{
  _DWORD *v6; // esi
  unsigned int v7; // eax
  float v9; // [esp+0h] [ebp-Ch]

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 6) = result;
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 4) = 5;
  *((_DWORD *)this + 5) = 11;
  *(_DWORD *)this = &GFxAmpMessageSwdFile::`vftable';
  v6 = this + 28;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(this + 40), pdata);
  if ( bufferSize >= *((_DWORD *)this + 8) )
  {
    if ( bufferSize >= *((_DWORD *)this + 9) )
      GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
        this: (ICvar *)this + 7,
        pheapAddr: (ConVar *)(this + 28),
        newCapacity: bufferSize + (bufferSize >> 2),
        a4: v9);
  }
  else if ( bufferSize < *((_DWORD *)this + 9) >> 1 )
  {
    GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
      this: (ICvar *)this + 7,
      pheapAddr: (ConVar *)(this + 28),
      newCapacity: bufferSize,
      a4: v9);
  }
  v7 = 0;
  for ( *((_DWORD *)this + 8) = bufferSize; v7 < bufferSize; ++v7 )
    *(_BYTE *)(v7 + *v6) = bufferData[v7];
  return (const CJob *)this;
}

//------------------------------------------------------------------------------
// Address: 0x100FE8B0
// Name: public: virtual class GString GFxAmpMessageSwdFile::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
GString *__thiscall GFxAmpMessageSwdFile::ToString(CJob *this, GString *a2)
{
  GString::GString(this: a2, src: (int)"SWD file");
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100FE940
// Name: public: virtual void GFxAmpMessageSwdFile::Read(class GFxAmpStream __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageSwdFile::Read(CJob *this, GFxAmpStream *a2)
{
  GFxAmpStream *v2; // esi
  void (__thiscall *v3)(GFxAmpStream *, unsigned __int8 *, int); // edx
  void (__thiscall *v5)(GFxAmpStream *, GFxAmpStream **, int); // edx
  void (__thiscall *v6)(GFxAmpStream *, GFxAmpStream **, int); // edx
  void (__thiscall *v7)(GFxAmpStream *, unsigned int *, int); // edx
  unsigned int v8; // ebx
  ICvar *p_m_flags; // edi
  unsigned int i; // ebx
  void (__thiscall *v11)(GFxAmpStream *, char *, int); // edx
  float v12; // [esp+0h] [ebp-18h]
  unsigned int v14; // [esp+10h] [ebp-8h] BYREF
  unsigned __int8 v15; // [esp+17h] [ebp-1h] BYREF

  v2 = a2;
  v3 = *(void (__thiscall **)(GFxAmpStream *, unsigned __int8 *, int))(*(_DWORD *)a2 + 40);
  v15 = 0;
  v3(a1: a2, a2: &v15, a3: 1);
  this->m_priority = v15;
  v5 = *(void (__thiscall **)(GFxAmpStream *, GFxAmpStream **, int))(*(_DWORD *)v2 + 40);
  a2 = nullptr;
  v5(a1: v2, &a2, a3: 4);
  this->m_mutex.m_ownerID = (volatile unsigned int)a2;
  v6 = *(void (__thiscall **)(GFxAmpStream *, GFxAmpStream **, int))(*(_DWORD *)v2 + 40);
  a2 = nullptr;
  v6(a1: v2, &a2, a3: 4);
  this->m_mutex.m_depth = (int)a2;
  v7 = *(void (__thiscall **)(GFxAmpStream *, unsigned int *, int))(*(_DWORD *)v2 + 40);
  v14 = 0;
  v7(a1: v2, a2: &v14, a3: 4);
  v8 = v14;
  p_m_flags = (ICvar *)&this->m_flags;
  if ( (ICvar_vtbl *)v14 >= p_m_flags[1].__vftable )
  {
    if ( (ICvar_vtbl *)v14 >= p_m_flags[2].__vftable )
      GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
        this: p_m_flags,
        pheapAddr: (ConVar *)p_m_flags,
        newCapacity: v14 + (v14 >> 2),
        a4: v12);
  }
  else if ( v14 < (unsigned int)p_m_flags[2].__vftable >> 1 )
  {
    GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
      this: p_m_flags,
      pheapAddr: (ConVar *)p_m_flags,
      newCapacity: v14,
      a4: v12);
  }
  p_m_flags[1].__vftable = (ICvar_vtbl *)v8;
  for ( i = 0; i < v14; ++i )
  {
    v11 = *(void (__thiscall **)(GFxAmpStream *, char *, int))(*(_DWORD *)v2 + 40);
    HIBYTE(a2) = 0;
    v11(a1: v2, a2: (char *)&a2 + 3, a3: 1);
    *((_BYTE *)&p_m_flags->Connect + i) = HIBYTE(a2);
  }
  GFxAmpStream::ReadString(this: v2, a2: (struct GString *)&this->m_CompleteEvent);
}

//------------------------------------------------------------------------------
// Address: 0x100FEA20
// Name: public: GFxAmpMessageSourceFile::GFxAmpMessageSourceFile(unsigned __int64,unsigned char __near *,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxAmpMessageSourceFile *__thiscall GFxAmpMessageSourceFile::GFxAmpMessageSourceFile(
        GFxAmpMessageSourceFile *this,
        unsigned __int64 a2,
        unsigned __int8 *a3,
        unsigned int a4,
        char *pdata)
{
  GArrayLH<unsigned char,2,GArrayDefaultPolicy> *p_FileData; // esi
  unsigned int v7; // eax
  float v9; // [esp+0h] [ebp-Ch]

  this->__vftable = (GFxAmpMessageSourceFile_vtbl *)&GRefCountImplCore::`vftable';
  this->FileHandle = a2;
  this->RefCount = 1;
  this->MsgType = Msg_SourceFile;
  this->Version = 11;
  this->__vftable = (GFxAmpMessageSourceFile_vtbl *)&GFxAmpMessageSourceFile::`vftable';
  p_FileData = &this->FileData;
  this->FileData.Data.Data = nullptr;
  this->FileData.Data.Size = 0;
  this->FileData.Data.Policy.Capacity = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)&this->Filename, pdata);
  if ( a4 >= this->FileData.Data.Size )
  {
    if ( a4 >= this->FileData.Data.Policy.Capacity )
      GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
        this: (ICvar *)&this->FileData,
        pheapAddr: (ConVar *)&this->FileData,
        newCapacity: a4 + (a4 >> 2),
        a4: v9);
  }
  else if ( a4 < this->FileData.Data.Policy.Capacity >> 1 )
  {
    GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
      this: (ICvar *)&this->FileData,
      pheapAddr: (ConVar *)&this->FileData,
      newCapacity: a4,
      a4: v9);
  }
  v7 = 0;
  for ( this->FileData.Data.Size = a4; v7 < a4; ++v7 )
    p_FileData->Data.Data[v7] = a3[v7];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FEAC0
// Name: public: virtual class GString GFxAmpMessageSourceFile::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
GString *__thiscall GFxAmpMessageSourceFile::ToString(ICvar *this, GString *a2)
{
  GString::GString(this: a2, src: (int)"Source file");
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100FEB50
// Name: public: virtual void GFxAmpMessageSourceFile::Read(class GFxAmpStream __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpMessageSourceFile::Read(GFxAmpMessageSourceFile *this, struct GFxAmpStream *a2)
{
  GFxAmpStream *v2; // esi
  void (__thiscall *v3)(struct GFxAmpStream *, unsigned __int8 *, int); // edx
  void (__thiscall *v5)(GFxAmpStream *, struct GFxAmpStream **, int); // edx
  void (__thiscall *v6)(GFxAmpStream *, unsigned __int64 *, int); // edx
  void (__thiscall *v7)(GFxAmpStream *, char *, int); // edx
  ICvar_vtbl *v8; // ebx
  ICvar *p_FileData; // edi
  unsigned int i; // ebx
  void (__thiscall *v11)(GFxAmpStream *, char *, int); // edx
  float v12; // [esp+0h] [ebp-1Ch]
  unsigned __int64 v14; // [esp+10h] [ebp-Ch] BYREF
  unsigned __int8 v15; // [esp+1Bh] [ebp-1h] BYREF

  v2 = a2;
  v3 = *(void (__thiscall **)(struct GFxAmpStream *, unsigned __int8 *, int))(*(_DWORD *)a2 + 40);
  v15 = 0;
  v3(a1: a2, a2: &v15, a3: 1);
  this->MsgType = v15;
  v5 = *(void (__thiscall **)(GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v2 + 40);
  a2 = nullptr;
  v5(a1: v2, &a2, a3: 4);
  this->Version = (unsigned int)a2;
  v6 = *(void (__thiscall **)(GFxAmpStream *, unsigned __int64 *, int))(*(_DWORD *)v2 + 40);
  v14 = 0;
  v6(a1: v2, a2: &v14, a3: 8);
  this->FileHandle = v14;
  v7 = *(void (__thiscall **)(GFxAmpStream *, char *, int))(*(_DWORD *)v2 + 40);
  HIDWORD(v14) = 0;
  v7(a1: v2, a2: (char *)&v14 + 4, a3: 4);
  v8 = (ICvar_vtbl *)HIDWORD(v14);
  p_FileData = (ICvar *)&this->FileData;
  if ( (ICvar_vtbl *)HIDWORD(v14) >= p_FileData[1].__vftable )
  {
    if ( (ICvar_vtbl *)HIDWORD(v14) >= p_FileData[2].__vftable )
      GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
        this: p_FileData,
        pheapAddr: (ConVar *)p_FileData,
        newCapacity: HIDWORD(v14) + (HIDWORD(v14) >> 2),
        a4: v12);
  }
  else if ( HIDWORD(v14) < (unsigned int)p_FileData[2].__vftable >> 1 )
  {
    GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
      this: p_FileData,
      pheapAddr: (ConVar *)p_FileData,
      newCapacity: SHIDWORD(v14),
      a4: v12);
  }
  p_FileData[1].__vftable = v8;
  for ( i = 0; i < HIDWORD(v14); ++i )
  {
    v11 = *(void (__thiscall **)(GFxAmpStream *, char *, int))(*(_DWORD *)v2 + 40);
    HIBYTE(a2) = 0;
    v11(a1: v2, a2: (char *)&a2 + 3, a3: 1);
    *((_BYTE *)&p_FileData->Connect + i) = HIBYTE(a2);
  }
  GFxAmpStream::ReadString(this: v2, a2: &this->Filename);
}

//------------------------------------------------------------------------------
// Address: 0x100FEC40
// Name: protected: static class GFxAmpMessage __near * GFxAmpMessage::CreateMessage(enum GFxAmpMessage::MessageType,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GFxAmpMessage::CreateMessage(const CFixedBitVecBase<128> logText)
{
  char v1; // bl
  int (__thiscall *v2)(unsigned int, int, int *); // eax
  _DWORD *v3; // eax
  int (__thiscall *v4)(unsigned int, int, int *); // edx
  IColorCorrectionSystem *v5; // esi
  int (__thiscall *v6)(unsigned int, int, int *); // edx
  IShaderAPI **v7; // eax
  int (__thiscall *v8)(unsigned int, int, int *); // eax
  _DWORD *v9; // eax
  int (__thiscall *v10)(unsigned int, int, int *); // edx
  char *v11; // eax
  int (__thiscall *v12)(unsigned int, int, int *); // eax
  GFxAmpMessageSourceFile *v13; // eax
  int (__thiscall *v14)(unsigned int, int, int *); // edx
  ICvar::ICVarIteratorInternal *v15; // eax
  int (__thiscall *v16)(unsigned int, int, int *); // eax
  BGRA8888_t *v17; // eax
  int (__thiscall *v18)(unsigned int, int, int *); // edx
  ICachedPerFrameMeshData *v19; // eax
  int (__thiscall *v20)(unsigned int, int, int *); // eax
  CFixedBitVecBase<128> *v21; // eax
  CFixedBitVecBase<128> *v22; // esi
  int v23; // [esp+8h] [ebp-28h] BYREF
  int v24; // [esp+Ch] [ebp-24h] BYREF
  int v25; // [esp+10h] [ebp-20h] BYREF
  int v26; // [esp+14h] [ebp-1Ch] BYREF
  int v27; // [esp+18h] [ebp-18h] BYREF
  int v28; // [esp+1Ch] [ebp-14h] BYREF
  int v29; // [esp+20h] [ebp-10h] BYREF
  int v30; // [esp+24h] [ebp-Ch] BYREF
  int v31; // [esp+28h] [ebp-8h] BYREF
  int v32; // [esp+2Ch] [ebp-4h] BYREF

  v1 = 0;
  v23 = 0;
  switch ( logText.m_Ints[0] )
  {
    case 1u:
      v2 = *(int (__thiscall **)(unsigned int, int, int *))(*(_DWORD *)logText.m_Ints[1] + 40);
      v32 = 2;
      v3 = (_DWORD *)v2(a1: logText.m_Ints[1], a2: 24, a3: &v32);
      if ( v3 != nullptr )
        GFxAmpMessageHeartbeat::GFxAmpMessageHeartbeat(this: v3);
      break;
    case 2u:
      v4 = *(int (__thiscall **)(unsigned int, int, int *))(*(_DWORD *)logText.m_Ints[1] + 40);
      v31 = 2;
      v5 = (IColorCorrectionSystem *)v4(a1: logText.m_Ints[1], a2: 36, a3: &v31);
      if ( v5 != nullptr )
      {
        GString::GString(this: (GString *)&logText, src: (int)&pMem);
        v1 = 1;
        GFxAmpMessageLog::GFxAmpMessageLog(this: v5, &logText, logCategory: 0.0, timeStamp: 0, a5: 0);
      }
      if ( (v1 & 1) != 0 )
        GString::~GString(this: (GString *)&logText);
      break;
    case 3u:
      v6 = *(int (__thiscall **)(unsigned int, int, int *))(*(_DWORD *)logText.m_Ints[1] + 40);
      v30 = 2;
      v7 = (IShaderAPI **)v6(a1: logText.m_Ints[1], a2: 28, a3: &v30);
      if ( v7 != nullptr )
        GFxAmpMessageCurrentState::GFxAmpMessageCurrentState(this: v7, a2: 0);
      break;
    case 4u:
      v8 = *(int (__thiscall **)(unsigned int, int, int *))(*(_DWORD *)logText.m_Ints[1] + 40);
      v29 = 2;
      v9 = (_DWORD *)v8(a1: logText.m_Ints[1], a2: 28, a3: &v29);
      if ( v9 != nullptr )
        GFxAmpMessageProfileFrame::GFxAmpMessageProfileFrame(this: v9, a2: nullptr);
      break;
    case 5u:
      v10 = *(int (__thiscall **)(unsigned int, int, int *))(*(_DWORD *)logText.m_Ints[1] + 40);
      v28 = 2;
      v11 = (char *)v10(a1: logText.m_Ints[1], a2: 44, a3: &v28);
      if ( v11 != nullptr )
        GFxAmpMessageSwdFile::GFxAmpMessageSwdFile(
          this: v11,
          result: nullptr,
          bufferData: nullptr,
          bufferSize: 0,
          pdata: (char *)&pMem);
      break;
    case 6u:
      v12 = *(int (__thiscall **)(unsigned int, int, int *))(*(_DWORD *)logText.m_Ints[1] + 40);
      v27 = 2;
      v13 = (GFxAmpMessageSourceFile *)v12(a1: logText.m_Ints[1], a2: 48, a3: &v27);
      if ( v13 != nullptr )
        GFxAmpMessageSourceFile::GFxAmpMessageSourceFile(this: v13, a2: 0, a3: nullptr, a4: 0, pdata: (char *)&pMem);
      break;
    case 7u:
      v14 = *(int (__thiscall **)(unsigned int, int, int *))(*(_DWORD *)logText.m_Ints[1] + 40);
      v26 = 2;
      v15 = (ICvar::ICVarIteratorInternal *)v14(a1: logText.m_Ints[1], a2: 32, a3: &v26);
      if ( v15 != nullptr )
        GFxAmpMessageSwdRequest::GFxAmpMessageSwdRequest(this: v15, swfHandle: 0, requestContents: false);
      break;
    case 8u:
      v16 = *(int (__thiscall **)(unsigned int, int, int *))(*(_DWORD *)logText.m_Ints[1] + 40);
      v25 = 2;
      v17 = (BGRA8888_t *)v16(a1: logText.m_Ints[1], a2: 40, a3: &v25);
      if ( v17 != nullptr )
        GFxAmpMessageSourceRequest::GFxAmpMessageSourceRequest(
          this: v17,
          handle: 0,
          handle_4: 0,
          requestContents: false);
      break;
    case 9u:
      v18 = *(int (__thiscall **)(unsigned int, int, int *))(*(_DWORD *)logText.m_Ints[1] + 40);
      v24 = 2;
      v19 = (ICachedPerFrameMeshData *)v18(a1: logText.m_Ints[1], a2: 32, a3: &v24);
      if ( v19 != nullptr )
        GFxAmpMessageAppControl::GFxAmpMessageAppControl(this: v19, flags: 0);
      break;
    case 0xAu:
      v20 = *(int (__thiscall **)(unsigned int, int, int *))(*(_DWORD *)logText.m_Ints[1] + 40);
      v23 = 2;
      v21 = (CFixedBitVecBase<128> *)v20(a1: logText.m_Ints[1], a2: 40, a3: &v23);
      v22 = v21;
      if ( v21 != nullptr )
      {
        v21->m_Ints[0] = (unsigned int)&GRefCountImplCore::`vftable';
        v21->m_Ints[1] = 1;
        v21[1].m_Ints[0] = 10;
        v21[1].m_Ints[1] = 11;
        v21[1].m_Ints[2] = 0;
        v21->m_Ints[0] = (unsigned int)&GFxAmpMessagePort::`vftable';
        GStringLH::GStringLH(this: v21 + 2);
        GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)((char *)v22 + 36));
        v22[1].m_Ints[3] = 1;
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FEEF0
// Name: public: static class GFxAmpMessage __near * GFxAmpMessage::CreateAndReadMessage(class GFxAmpStream __near &,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
static int __usercall GFxAmpMessage::CreateAndReadMessage@<eax>(
        unsigned int a1@<edi>,
        struct GFxAmpStream *a2,
        struct GMemoryHeap *a3)
{
  GFxAmpStream *v3; // esi
  void (__thiscall *v4)(struct GFxAmpStream *, unsigned __int8 *, int); // edx
  void (__thiscall *v5)(GFxAmpStream *, struct GFxAmpStream **, int); // edx
  int v7; // eax
  int v8; // edi
  CFixedBitVecBase<128> v9; // [esp-Ch] [ebp-14h]
  unsigned __int8 v10; // [esp+7h] [ebp-1h] BYREF

  v3 = a2;
  v4 = *(void (__thiscall **)(struct GFxAmpStream *, unsigned __int8 *, int))(*(_DWORD *)a2 + 40);
  v10 = 0;
  v4(a1: a2, a2: &v10, a3: 1);
  v5 = *(void (__thiscall **)(GFxAmpStream *, struct GFxAmpStream **, int))(*(_DWORD *)v3 + 40);
  a2 = nullptr;
  v5(a1: v3, &a2, a3: 4);
  if ( (unsigned int)a2 > 0xB )
    return 0;
  v9.m_Ints[2] = a1;
  GFxAmpStream::Rewind(this: v3);
  v9.m_Ints[1] = (unsigned int)a3;
  v9.m_Ints[0] = v10;
  GFxAmpMessage::CreateMessage(logText: v9);
  v8 = v7;
  if ( v7 != 0 )
    (*(void (__thiscall **)(int, GFxAmpStream *))(*(_DWORD *)v7 + 12))(a1: v7, a2: v3);
  return v8;
}
