// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/keyboard.cpp
// Functions: 10
// ============================================================

#include "hammer\keyboard.h"

//------------------------------------------------------------------------------
// Address: 0x10048480
// Name: public: CKeyboard::CKeyboard(void)
// Source: json
//------------------------------------------------------------------------------
CKeyboard *__thiscall CKeyboard::CKeyboard(CKeyboard *this)
{
  this->g_uKeyMaps = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10048490
// Name: public: void CKeyboard::AddKeyMap(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyboard::AddKeyMap(
        CKeyboard *this,
        unsigned int uChar,
        unsigned int uModifierKeys,
        unsigned int uLogicalKey)
{
  this->g_uKeyMap[this->g_uKeyMaps].uChar = uChar;
  this->g_uKeyMap[this->g_uKeyMaps].uModifierKeys = uModifierKeys;
  this->g_uKeyMap[this->g_uKeyMaps++].uLogicalKey = uLogicalKey;
}

//------------------------------------------------------------------------------
// Address: 0x100484E0
// Name: public: void CKeyboard::ClearImpulseFlags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyboard::ClearImpulseFlags(CKeyboard *this)
{
  unsigned int i; // eax
  unsigned int *g_uLogicalKeyState; // eax
  int j; // ecx

  for ( i = 0; i < 0x100; ++i )
    this->g_uPhysicalKeyState[i] &= 0xFFFCFFFF;
  g_uLogicalKeyState = this->g_uLogicalKeyState;
  for ( j = 256; j != 0; --j )
    *g_uLogicalKeyState++ &= 0xFFFCFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10048510
// Name: public: void CKeyboard::ClearKeyStates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyboard::ClearKeyStates(CKeyboard *this)
{
  memset(this, 0, 0x400u);
  memset(this->g_uLogicalKeyState, 0, sizeof(this->g_uLogicalKeyState));
}

//------------------------------------------------------------------------------
// Address: 0x10048530
// Name: public: float CKeyboard::GetKeyScale(unsigned int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CKeyboard::GetKeyScale(CKeyboard *this, unsigned int uLogicalKey)
{
  int v3; // xmm0_4
  unsigned int v4; // ecx
  float fValue; // [esp+8h] [ebp+8h]

  if ( uLogicalKey >= 0x100 )
    return 0.0;
  v3 = 0;
  v4 = this->g_uLogicalKeyState[uLogicalKey];
  fValue = 0.0;
  if ( (v4 & 0x10000) != 0 )
  {
    if ( (v4 & 0x20000) == 0 )
    {
      if ( (_WORD)v4 != 0 )
        return 0.5;
      return fValue;
    }
    if ( (_WORD)v4 != 0 )
      return 0.75;
    v3 = 1048576000;
  }
  else
  {
    if ( (v4 & 0x20000) != 0 )
    {
      if ( (_WORD)v4 == 0 )
        return 0.0;
      return fValue;
    }
    if ( (_WORD)v4 != 0 )
      return 1.0;
  }
  return *(float *)&v3;
}

//------------------------------------------------------------------------------
// Address: 0x100485E0
// Name: protected: bool CKeyboard::IsKeyPressed(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CKeyboard::IsKeyPressed(CKeyboard *this, unsigned int uChar, unsigned int uModifierKeys)
{
  bool result; // al

  if ( LOWORD(this->g_uPhysicalKeyState[uChar]) == 0 )
    return false;
  result = true;
  if ( LOWORD(this->g_uPhysicalKeyState[ModifierKeyTable[0].uChar]) != 0 )
  {
    if ( (uModifierKeys & ModifierKeyTable[0].uModifierKeys) != 0 )
      goto LABEL_7;
  }
  else if ( (uModifierKeys & ModifierKeyTable[0].uModifierKeys) == 0 )
  {
    goto LABEL_7;
  }
  result = false;
LABEL_7:
  if ( LOWORD(this->g_uPhysicalKeyState[ModifierKeyTable[1].uChar]) != 0 )
  {
    if ( (uModifierKeys & ModifierKeyTable[1].uModifierKeys) != 0 )
      goto LABEL_12;
  }
  else if ( (uModifierKeys & ModifierKeyTable[1].uModifierKeys) == 0 )
  {
    goto LABEL_12;
  }
  result = false;
LABEL_12:
  if ( LOWORD(this->g_uPhysicalKeyState[ModifierKeyTable[2].uChar]) == 0 )
  {
    if ( (uModifierKeys & ModifierKeyTable[2].uModifierKeys) == 0 )
      return result;
    return false;
  }
  if ( (uModifierKeys & ModifierKeyTable[2].uModifierKeys) == 0 )
    return false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048670
// Name: protected: void CKeyboard::UpdateLogicalKeys(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyboard::UpdateLogicalKeys(CKeyboard *this, unsigned int uChar, bool bPressed)
{
  unsigned int v3; // edx
  bool v5; // al
  int v6; // ecx
  unsigned int v7; // eax
  unsigned int *p_uModifierKeys; // ebx
  unsigned int v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int nKey; // [esp+8h] [ebp-8h]
  unsigned int uModifierKeyBit; // [esp+Ch] [ebp-4h]

  v3 = uChar;
  v5 = uChar == 16 || uChar == 17 || uChar == 18;
  uModifierKeyBit = 0;
  if ( v5 )
  {
    v6 = 0;
    v7 = 0;
    while ( ModifierKeyTable[v7].uChar != uChar )
    {
      ++v7;
      ++v6;
      if ( v7 >= 3 )
      {
        uModifierKeyBit = 0;
        goto LABEL_11;
      }
    }
    uModifierKeyBit = ModifierKeyTable[v6].uModifierKeys;
  }
LABEL_11:
  nKey = 0;
  if ( this->g_uKeyMaps != 0 )
  {
    p_uModifierKeys = &this->g_uKeyMap[0].uModifierKeys;
    do
    {
      v9 = p_uModifierKeys[1];
      if ( *(p_uModifierKeys - 1) == v3 || (uModifierKeyBit & *p_uModifierKeys) != 0 )
      {
        if ( bPressed )
        {
          if ( CKeyboard::IsKeyPressed(this, uChar: *(p_uModifierKeys - 1), uModifierKeys: *p_uModifierKeys) )
          {
            v10 = this->g_uLogicalKeyState[v9];
            if ( (_WORD)v10 == 0 )
              this->g_uLogicalKeyState[v9] = v10 | 0x10000;
            ++this->g_uLogicalKeyState[v9];
          }
          v3 = uChar;
        }
        else
        {
          v11 = this->g_uLogicalKeyState[v9];
          if ( (_WORD)v11 != 0 )
            this->g_uLogicalKeyState[v9] = v11 - 1;
          v12 = this->g_uLogicalKeyState[v9];
          if ( (_WORD)v12 == 0 )
            this->g_uLogicalKeyState[v9] = v12 | 0x20000;
        }
      }
      p_uModifierKeys += 3;
      ++nKey;
    }
    while ( nKey < this->g_uKeyMaps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048780
// Name: public: void CKeyboard::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyboard::OnKeyDown(CKeyboard *this, unsigned int nChar, unsigned int nRepCnt, __int16 nFlags)
{
  if ( (nFlags & 0x4000) == 0 || LOWORD(this->g_uPhysicalKeyState[nChar]) == 0 )
  {
    this->g_uPhysicalKeyState[nChar] |= 0x1FFFFu;
    CKeyboard::UpdateLogicalKeys(this, uChar: nChar, bPressed: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100487B0
// Name: public: void CKeyboard::OnKeyUp(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyboard::OnKeyUp(CKeyboard *this, unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags)
{
  if ( LOWORD(this->g_uPhysicalKeyState[nChar]) != 0 )
    LOWORD(this->g_uPhysicalKeyState[nChar]) = 0;
  this->g_uPhysicalKeyState[nChar] |= 0x20000u;
  CKeyboard::UpdateLogicalKeys(this, uChar: nChar, bPressed: false);
}

//------------------------------------------------------------------------------
// Address: 0x100487E0
// Name: public: void CKeyboard::RemoveAllKeyMaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyboard::RemoveAllKeyMaps(CKeyboard *this)
{
  this->g_uKeyMaps = 0;
}
