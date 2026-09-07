// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxevent.cpp
// Functions: 10
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxevent.h"

//------------------------------------------------------------------------------
// Address: 0x101068F0
// Name: public: void GFxKeyboardState::KeyQueue::Put(short,unsigned char,unsigned long,enum GFxEvent::EventType,class GFxSpecialKeysState)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxKeyboardState::KeyQueue::Put(
        GFxKeyboardState::KeyQueue *this,
        __int16 code,
        unsigned __int8 ascii,
        unsigned int wcharCode,
        enum GFxEvent::EventType event,
        struct GFxSpecialKeysState specialKeysState)
{
  if ( this->Count < 0x64 )
  {
    this->Buffer[this->PutIdx].code = code;
    this->Buffer[this->PutIdx].ascii = ascii;
    this->Buffer[this->PutIdx].wcharCode = wcharCode;
    this->Buffer[this->PutIdx].event = event;
    this->Buffer[this->PutIdx++].specialKeysState = specialKeysState;
    if ( this->PutIdx >= 0x64 )
      this->PutIdx = 0;
    ++this->Count;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106970
// Name: public: void GFxKeyboardState::ResetState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxKeyboardState::ResetState(GFxKeyboardState *this)
{
  this->KeyQueue.PutIdx = 0;
  this->KeyQueue.GetIdx = 0;
  this->KeyQueue.Count = 0;
  memset(dst: (unsigned __int8 *)&this->KeyQueue, value: 0, count: 0x640u);
  *(_DWORD *)this->Keymap = 0;
  *(_DWORD *)&this->Keymap[4] = 0;
  *(_DWORD *)&this->Keymap[8] = 0;
  *(_DWORD *)&this->Keymap[12] = 0;
  *(_DWORD *)&this->Keymap[16] = 0;
  *(_DWORD *)&this->Keymap[20] = 0;
  *(_DWORD *)&this->Keymap[24] = 0;
  this->Keymap[28] = 0;
  *(_WORD *)this->Toggled = 0;
  this->Toggled[2] = false;
}

//------------------------------------------------------------------------------
// Address: 0x101069F0
// Name: public: bool GFxKeyboardState::IsKeyDown(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxKeyboardState::IsKeyDown(GFxKeyboardState *this, int code)
{
  return (unsigned int)code <= 0xE4 && ((unsigned __int8)(1 << (code - 8 * (code >> 3))) & this->Keymap[code >> 3]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10106A30
// Name: public: bool GFxKeyboardState::IsKeyToggled(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxKeyboardState::IsKeyToggled(GFxKeyboardState *this, int code)
{
  switch ( code )
  {
    case 20:
      return this->Toggled[1];
    case 144:
      return this->Toggled[0];
    case 145:
      return this->Toggled[2];
    default:
      break;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10106A70
// Name: public: void GFxKeyboardState::SetKeyToggled(int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxKeyboardState::SetKeyToggled(_BYTE *this, _JOBOBJECT_BASIC_LIMIT_INFORMATION *result, bool toggle)
{
  char v3; // al

  if ( result == (_JOBOBJECT_BASIC_LIMIT_INFORMATION *)20 )
  {
    *(this + 1655) = toggle;
    return toggle;
  }
  else
  {
    v3 = (_BYTE)result + 112;
    if ( result == (_JOBOBJECT_BASIC_LIMIT_INFORMATION *)144 )
    {
      *(this + 1654) = toggle;
    }
    else
    {
      v3 = (_BYTE)result + 111;
      if ( result == (_JOBOBJECT_BASIC_LIMIT_INFORMATION *)145 )
      {
        *(this + 1656) = toggle;
        return toggle;
      }
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10106AB0
// Name: public: void GFxKeyboardState::SetKeyDown(int,unsigned char,class GFxSpecialKeysState)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxKeyboardState::SetKeyDown(
        int this,
        int result,
        unsigned __int8 ascii,
        struct GFxSpecialKeysState specialKeysState)
{
  if ( (unsigned int)result <= 0xE4 )
  {
    *(_BYTE *)((result >> 3) + this + 1625) |= 1 << (result - 8 * (result >> 3));
    GFxKeyboardState::KeyQueue::Put(
      this: (GFxKeyboardState::KeyQueue *)(this + 12),
      code: result,
      ascii,
      wcharCode: 0,
      event: KeyDown,
      specialKeysState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106B00
// Name: public: void GFxKeyboardState::SetKeyUp(int,unsigned char,class GFxSpecialKeysState)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxKeyboardState::SetKeyUp(
        int this,
        int result,
        unsigned __int8 ascii,
        struct GFxSpecialKeysState specialKeysState)
{
  if ( (unsigned int)result <= 0xE4 )
  {
    *(_BYTE *)((result >> 3) + this + 1625) &= ~(1 << (result - 8 * (result >> 3)));
    GFxKeyboardState::KeyQueue::Put(
      this: (GFxKeyboardState::KeyQueue *)(this + 12),
      code: result,
      ascii,
      wcharCode: 0,
      event: KeyUp,
      specialKeysState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106B50
// Name: public: void GFxKeyboardState::NotifyListeners(class GASStringContext __near *,short,unsigned char,unsigned long,enum GFxEvent::EventType)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxKeyboardState::NotifyListeners(
        GFxKeyboardState *this,
        struct GASStringContext *code,
        __int16 a3,
        int ascii,
        unsigned int wcharCode,
        int (__stdcall *event)(HINSTANCE__ *, char *, int))
{
  if ( this->pListener != nullptr )
  {
    if ( event == (int (__stdcall *)(HINSTANCE__ *, char *, int))5 )
    {
      ((void (__stdcall *)(struct GASStringContext *, _DWORD, int, unsigned int, _DWORD))this->pListener->OnKeyDown)(
        a1: code,
        a2: a3,
        a3: ascii,
        a4: wcharCode,
        a5: this->KeyboardIndex);
    }
    else if ( event == (int (__stdcall *)(HINSTANCE__ *, char *, int))6 )
    {
      ((void (__stdcall *)(struct GASStringContext *, _DWORD, int, unsigned int, _DWORD))this->pListener->OnKeyUp)(
        a1: code,
        a2: a3,
        a3: ascii,
        a4: wcharCode,
        a5: this->KeyboardIndex);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106BA0
// Name: public: void GFxKeyboardState::UpdateListeners(short,unsigned char,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxKeyboardState::UpdateListeners(
        GFxKeyboardState *this,
        __int16 code,
        int ascii,
        unsigned int wcharCode)
{
  if ( this->pListener != nullptr )
    this->pListener->Update(this: this->pListener, a2: code, a3: ascii, a4: wcharCode, a5: this->KeyboardIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10106BD0
// Name: public: GFxKeyboardState::GFxKeyboardState(void)
// Source: json
//------------------------------------------------------------------------------
GFxKeyboardState *__thiscall GFxKeyboardState::GFxKeyboardState(GFxKeyboardState *this)
{
  GFxKeyboardState::KeyQueue *p_KeyQueue; // ecx
  int v3; // edx
  GFxSpecialKeysState *p_specialKeysState; // eax

  this->__vftable = (GFxKeyboardState_vtbl *)&GRefCountImplCore::`vftable';
  p_KeyQueue = &this->KeyQueue;
  this->RefCount = 1;
  this->__vftable = (GFxKeyboardState_vtbl *)&GRefCountBaseNTS<GASGlobalContext,323>::`vftable';
  v3 = 99;
  p_specialKeysState = &p_KeyQueue->Buffer[0].specialKeysState;
  do
  {
    p_specialKeysState->States = 0;
    p_specialKeysState += 16;
    --v3;
  }
  while ( v3 >= 0 );
  p_KeyQueue->PutIdx = 0;
  p_KeyQueue->GetIdx = 0;
  p_KeyQueue->Count = 0;
  memset(dst: (unsigned __int8 *)p_KeyQueue, value: 0, count: 0x640u);
  this->pListener = nullptr;
  this->KeyboardIndex = 0;
  *(_DWORD *)this->Keymap = 0;
  *(_DWORD *)&this->Keymap[4] = 0;
  *(_DWORD *)&this->Keymap[8] = 0;
  *(_DWORD *)&this->Keymap[12] = 0;
  *(_DWORD *)&this->Keymap[16] = 0;
  *(_DWORD *)&this->Keymap[20] = 0;
  *(_DWORD *)&this->Keymap[24] = 0;
  this->Keymap[28] = 0;
  *(_WORD *)this->Toggled = 0;
  this->Toggled[2] = false;
  return this;
}
