// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/ime/gfxkoreanime.cpp
// Functions: 1
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\ime\gfxkoreanime.h"

//------------------------------------------------------------------------------
// Address: 0x10141D60
// Name: public: unsigned int GFxMovieRoot::HandleKoreanIME(class GFxIMEEvent const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxMovieRoot::HandleKoreanIME(ISteamRemoteStorage *this, const struct GFxIMEEvent *a2)
{
  int v3; // edi
  IShaderAPI *v4; // eax
  GFxLogBase<GFxLog> *v5; // esi
  GFxEvent::EventType Type; // eax
  __int32 v7; // eax
  GRefCountNTSImpl *v8; // esi
  GRefCountNTSImpl_vtbl *v9; // edi
  int v10; // eax
  int v11; // eax
  GFxEvent::EventType v13; // edi
  int (__stdcall *v14)(int); // eax
  unsigned int v15; // edi
  int (__stdcall *v16)(GStat::StatValue *, int, _DWORD, _DWORD); // eax
  int (__stdcall *v17)(GStat::StatValue *, int, _WORD *, unsigned int); // eax
  int v18; // eax
  GRefCountNTSImpl_vtbl *v19; // eax
  void (__stdcall *v20)(int, GStat::StatValue *); // ebx
  GRefCountNTSImpl_vtbl *v21; // edx
  void (__thiscall *dtr_GRefCountImplCore)(struct GRefCountNTSImpl *); // eax
  int v23; // eax
  unsigned int *v24; // [esp+0h] [ebp-4Ch]
  char **v25; // [esp+4h] [ebp-48h]
  int *v26; // [esp+8h] [ebp-44h]
  CSteamID *IMEEvtType; // [esp+Ch] [ebp-40h]
  int v28; // [esp+Ch] [ebp-40h]
  _WORD v29[2]; // [esp+10h] [ebp-3Ch] BYREF
  unsigned int keyCode; // [esp+14h] [ebp-38h] BYREF
  unsigned int info; // [esp+18h] [ebp-34h] BYREF
  GStat::StatValue *pfocusedCh; // [esp+1Ch] [ebp-30h] BYREF
  _WORD v33[20]; // [esp+20h] [ebp-2Ch] BYREF

  if ( *((_DWORD *)this + 2572) == 0 )
  {
    v3 = *((_DWORD *)this + 2573);
    if ( v3 != 0 )
    {
      v4 = (IShaderAPI *)(*(int (__thiscall **)(ISteamRemoteStorage *, int))(*((_DWORD *)this + 2) + 12))(
                           a1: this + 2,
                           a2: 4);
      v5 = (GFxLogBase<GFxLog> *)v4;
      if ( v4 != nullptr )
      {
        GRefCountImpl::Release(this: v4);
        GFxLogBase<GFxLog>::LogError(this: v5 + 3, pfmt: "Error: IMM32.DLL is not available, error code = 0x%X\n", v3);
      }
      *((_DWORD *)this + 2573) = 0;
    }
    return 0;
  }
  if ( a2->IMEEvtType != IME_PreProcessKeyboard )
  {
    IMEEvtType = (CSteamID *)a2[2].IMEEvtType;
    if ( (unsigned __int16)GetKeyboardLayout(idThread: 0) == 1042 )
    {
      Type = a2[1].Type;
      if ( (unsigned int)Type > (IMEEvent|MouseMove|0x100) )
      {
        if ( Type == 646 )
          return 2;
      }
      else
      {
        if ( Type == (IMEEvent|MouseMove|0x100) )
        {
          GFxMovieRoot::GetFocusedCharacter(
            this,
            controllerIdx: (unsigned int)&info,
            a3: v24,
            a4: v25,
            a5: v26,
            a6: IMEEvtType);
          v8 = (GRefCountNTSImpl *)info;
          if ( info == 0 )
            return 2;
          if ( (*(int (__thiscall **)(unsigned int))(*(_DWORD *)info + 176))(a1: info) != 4 )
            goto LABEL_21;
          ++v8->RefCount;
          v8 = (GRefCountNTSImpl *)info;
          if ( (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)info + 404))(a1: info) != 0 )
          {
            v13 = a2[2].Type;
            keyCode = a2[1].IMEEvtType;
            info = v13;
            if ( (v13 & 0x800) != 0 )
            {
              v14 = *((int (__stdcall **)(int))this + 2565);
              v15 = 0;
              if ( v14 != nullptr )
                pfocusedCh = (GStat::StatValue *)v14(a1: v28);
              else
                pfocusedCh = nullptr;
              v16 = *((int (__stdcall **)(GStat::StatValue *, int, _DWORD, _DWORD))this + 2568);
              if ( v16 != nullptr )
                v15 = v16(a1: pfocusedCh, a2: 2048, a3: 0, a4: 0);
              v17 = *((int (__stdcall **)(GStat::StatValue *, int, _WORD *, unsigned int))this + 2568);
              if ( v17 == nullptr || (v18 = v17(a1: pfocusedCh, a2: 2048, a3: v33, a4: v15)) != -1 && v18 != -2 )
              {
                v19 = v8->__vftable;
                v33[v15 >> 1] = 0;
                ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD))v19[99].dtr_GRefCountImplCore)(a1: v8, a2: 0);
              }
              v20 = *((void (__stdcall **)(int, GStat::StatValue *))this + 2566);
              if ( v20 != nullptr )
                v20(a1: v28, a2: pfocusedCh);
              ((void (__thiscall *)(GRefCountNTSImpl *, _WORD *, int))v8->__vftable[105].dtr_GRefCountImplCore)(
                a1: v8,
                a2: v33,
                a3: -1);
              LOWORD(v13) = info;
            }
            if ( (v13 & 0x2000) != 0 && (v13 & 0x4000) != 0 )
            {
              v21 = v8->__vftable;
              v29[0] = keyCode;
              dtr_GRefCountImplCore = v21[99].dtr_GRefCountImplCore;
              v29[1] = 0;
              ((void (__thiscall *)(GRefCountNTSImpl *, int))dtr_GRefCountImplCore)(a1: v8, a2: 1);
              v23 = ((int (__thiscall *)(GRefCountNTSImpl *))v8->__vftable[95].dtr_GRefCountImplCore)(a1: v8);
              ((void (__thiscall *)(GRefCountNTSImpl *, int))v8->__vftable[107].dtr_GRefCountImplCore)(a1: v8, a2: v23);
              ((void (__thiscall *)(GRefCountNTSImpl *, _WORD *, int))v8->__vftable[106].dtr_GRefCountImplCore)(
                a1: v8,
                a2: v29,
                a3: 1);
              ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD))v8->__vftable[110].dtr_GRefCountImplCore)(a1: v8, a2: 0);
            }
          }
          goto LABEL_20;
        }
        v7 = Type - 269;
        if ( v7 == 0 )
        {
          GFxMovieRoot::GetFocusedCharacter(
            this,
            controllerIdx: (unsigned int)&keyCode,
            a3: v24,
            a4: v25,
            a5: v26,
            a6: IMEEvtType);
          v8 = (GRefCountNTSImpl *)keyCode;
          if ( keyCode != 0 )
          {
            if ( (*(int (__thiscall **)(unsigned int))(*(_DWORD *)keyCode + 176))(a1: keyCode) == 4 )
            {
              ++v8->RefCount;
              v8 = (GRefCountNTSImpl *)keyCode;
              if ( (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)keyCode + 404))(a1: keyCode) != 0 )
              {
                v9 = v8->__vftable;
                v10 = ((int (__thiscall *)(GRefCountNTSImpl *, int))v8->__vftable[97].dtr_GRefCountImplCore)(
                        a1: v8,
                        a2: -1);
                v11 = ((int (__thiscall *)(GRefCountNTSImpl *, int))v8->__vftable[96].dtr_GRefCountImplCore)(
                        a1: v8,
                        a2: v10);
                ((void (__thiscall *)(GRefCountNTSImpl *, const wchar_t *, int))v9[100].dtr_GRefCountImplCore)(
                  a1: v8,
                  a2: &word_1028F3E0,
                  a3: v11);
                v8->__vftable[102].dtr_GRefCountImplCore(this: v8);
              }
              goto LABEL_20;
            }
LABEL_21:
            GRefCountNTSImpl::Release(this: v8);
          }
          return 2;
        }
        if ( v7 == 1 )
        {
          GFxMovieRoot::GetFocusedCharacter(
            this,
            controllerIdx: (unsigned int)&pfocusedCh,
            a3: v24,
            a4: v25,
            a5: v26,
            a6: IMEEvtType);
          v8 = (GRefCountNTSImpl *)pfocusedCh;
          if ( pfocusedCh != nullptr )
          {
            if ( (*(int (__thiscall **)(GStat::StatValue *))(pfocusedCh->Type + 176))(a1: pfocusedCh) == 4 )
            {
              ++v8->RefCount;
              v8 = (GRefCountNTSImpl *)pfocusedCh;
              if ( (*(unsigned __int8 (__thiscall **)(GStat::StatValue *))(pfocusedCh->Type + 404))(a1: pfocusedCh) != 0 )
              {
                ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD))v8->__vftable[99].dtr_GRefCountImplCore)(
                  a1: v8,
                  a2: 0);
                v8->__vftable[103].dtr_GRefCountImplCore(this: v8);
              }
LABEL_20:
              GRefCountNTSImpl::Release(this: v8);
              goto LABEL_21;
            }
            goto LABEL_21;
          }
          return 2;
        }
      }
    }
  }
  return 0;
}
