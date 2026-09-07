// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/border.cpp
// Functions: 8
// ============================================================

#include "vgui2\src\border.h"

//------------------------------------------------------------------------------
// Address: 0x100014C0
// Name: public: virtual void vgui::Border::Paint(int,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Border::Paint(
        vgui::Border *this,
        int x,
        int y,
        int wide,
        int tall,
        int breakSide,
        int breakStart,
        int breakEnd)
{
  vgui::Border::line_t *v10; // esi
  vgui::Border::line_t *v11; // esi
  int v12; // eax
  vgui::Border::line_t *v13; // esi
  int v14; // ebx
  vgui::Border::line_t *v15; // esi
  int i; // [esp+Ch] [ebp-4h]
  int ia; // [esp+Ch] [ebp-4h]
  int ib; // [esp+Ch] [ebp-4h]
  int ic; // [esp+Ch] [ebp-4h]
  int ya; // [esp+1Ch] [ebp+Ch]
  int yb; // [esp+1Ch] [ebp+Ch]
  int breakSidea; // [esp+28h] [ebp+18h]
  int breakEnda; // [esp+30h] [ebp+20h]
  int breakEndb; // [esp+30h] [ebp+20h]

  i = 0;
  if ( this->_sides[0].count > 0 )
  {
    ya = 0;
    do
    {
      v10 = &this->_sides[0].lines[ya];
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))vgui::g_pSurface->DrawSetColor_2)(
        a1: v10->col._color[0],
        a2: v10->col._color[1],
        a3: v10->col._color[2],
        a4: v10->col._color[3]);
      if ( breakSide != 0 )
      {
        vgui::g_pSurface->DrawFilledRect(
          this: vgui::g_pSurface,
          a2: x + i,
          a3: y + v10->startOffset,
          a4: i + x + 1,
          a5: tall - v10->endOffset);
      }
      else
      {
        if ( breakStart > 0 )
          vgui::g_pSurface->DrawFilledRect(
            this: vgui::g_pSurface,
            a2: x + i,
            a3: y + v10->startOffset,
            a4: i + x + 1,
            a5: y + breakStart);
        if ( breakEnd < tall - v10->endOffset )
          vgui::g_pSurface->DrawFilledRect(
            this: vgui::g_pSurface,
            a2: x + i,
            a3: y + breakEnd + 1,
            a4: i + x + 1,
            a5: tall - v10->endOffset);
      }
      ++ya;
      ++i;
    }
    while ( i < this->_sides[0].count );
  }
  ia = 0;
  if ( this->_sides[1].count > 0 )
  {
    yb = 0;
    do
    {
      v11 = &this->_sides[1].lines[yb];
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))vgui::g_pSurface->DrawSetColor_2)(
        a1: v11->col._color[0],
        a2: v11->col._color[1],
        a3: v11->col._color[2],
        a4: v11->col._color[3]);
      if ( breakSide == 1 )
      {
        if ( breakStart > 0 )
          vgui::g_pSurface->DrawFilledRect(
            this: vgui::g_pSurface,
            a2: x + v11->startOffset,
            a3: y + ia,
            a4: x + breakStart,
            a5: ia + y + 1);
        v12 = wide - v11->endOffset;
        if ( breakEnd < v12 )
          ((void (__stdcall *)(int, int, int, int))vgui::g_pSurface->DrawFilledRect)(
            a1: x + breakEnd + 1,
            a2: y + ia,
            a3: v12,
            a4: ia + y + 1);
      }
      else
      {
        ((void (__stdcall *)(int, int, int, int))vgui::g_pSurface->DrawFilledRect)(
          a1: x + v11->startOffset,
          a2: y + ia,
          a3: wide - v11->endOffset,
          a4: ia + y + 1);
      }
      ++yb;
      ++ia;
    }
    while ( ia < this->_sides[1].count );
  }
  ib = 0;
  if ( this->_sides[2].count > 0 )
  {
    breakEnda = 0;
    breakSidea = wide;
    do
    {
      v13 = &this->_sides[2].lines[breakEnda];
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))vgui::g_pSurface->DrawSetColor_2)(
        a1: v13->col._color[0],
        a2: v13->col._color[1],
        a3: v13->col._color[2],
        a4: v13->col._color[3]);
      vgui::g_pSurface->DrawFilledRect(
        this: vgui::g_pSurface,
        a2: breakSidea - 1,
        a3: y + v13->startOffset,
        a4: breakSidea,
        a5: tall - v13->endOffset);
      ++breakEnda;
      --breakSidea;
      ++ib;
    }
    while ( ib < this->_sides[2].count );
  }
  ic = 0;
  if ( this->_sides[3].count > 0 )
  {
    v14 = tall;
    breakEndb = 0;
    do
    {
      v15 = &this->_sides[3].lines[breakEndb];
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))vgui::g_pSurface->DrawSetColor_2)(
        a1: v15->col._color[0],
        a2: v15->col._color[1],
        a3: v15->col._color[2],
        a4: v15->col._color[3]);
      vgui::g_pSurface->DrawFilledRect(
        this: vgui::g_pSurface,
        a2: x + v15->startOffset,
        a3: v14 - 1,
        a4: wide - v15->endOffset,
        a5: v14);
      ++breakEndb;
      --v14;
      ++ic;
    }
    while ( ic < this->_sides[3].count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001780
// Name: public: virtual void vgui::Border::Paint(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Border::Paint(vgui::Border *this, int panel)
{
  int wide; // [esp+4h] [ebp-4h] BYREF

  (*(void (__thiscall **)(int, int *, int *))(*(_DWORD *)panel + 52))(a1: panel, a2: &wide, a3: &panel);
  this->Paint(this, a2: 0, a3: 0, a4: wide, a5: panel, a6: -1, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100017C0
// Name: public: virtual enum vgui::IBorder::backgroundtype_e vgui::Border::GetBackgroundType(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder::backgroundtype_e __thiscall vgui::Border::GetBackgroundType(vgui::Border *this)
{
  return this->m_eBackgroundType;
}

//------------------------------------------------------------------------------
// Address: 0x100017D0
// Name: public: vgui::Border::Border(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Border *__thiscall vgui::Border::Border(vgui::Border *this)
{
  this->__vftable = (vgui::Border_vtbl *)&vgui::Border::`vftable';
  this->_inset[0] = 0;
  this->_inset[1] = 0;
  this->_inset[2] = 0;
  this->_inset[3] = 0;
  this->_name = nullptr;
  this->m_eBackgroundType = BACKGROUND_FILLED;
  this->_sides[0] = 0;
  this->_sides[1] = 0;
  this->_sides[2] = 0;
  this->_sides[3] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001810
// Name: private: void vgui::Border::ParseSideSettings(int,class KeyValues __near *,class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Border::ParseSideSettings(
        vgui::Border *this,
        int side_index,
        KeyValues *inResourceData,
        vgui::IScheme *pScheme)
{
  int v5; // edi
  KeyValues *i; // eax
  int v7; // esi
  vgui::Border::line_t *v8; // eax
  int v9; // edi
  vgui::Border::line_t *j; // ecx
  KeyValues *FirstSubKey; // edi
  vgui::IScheme *v12; // ebx
  vgui::Border::line_t *v13; // esi
  const char *String; // eax
  const char *v15; // eax
  _BYTE v16[4]; // [esp+4h] [ebp-10h] BYREF
  vgui::Border *v17; // [esp+8h] [ebp-Ch]
  int end; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v19; // [esp+10h] [ebp-4h]

  v17 = this;
  if ( inResourceData != nullptr )
  {
    v5 = 0;
    for ( i = KeyValues::GetFirstSubKey(this: inResourceData); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      ++v5;
    v7 = side_index;
    this->_sides[side_index].count = v5;
    v8 = (vgui::Border::line_t *)operator new(nSize: 12 * v5);
    if ( v8 != nullptr )
    {
      v9 = v5 - 1;
      for ( j = v8; v9 >= 0; --v9 )
      {
        j->col = 0;
        ++j;
      }
    }
    else
    {
      v8 = nullptr;
    }
    this->_sides[side_index].lines = v8;
    FirstSubKey = KeyValues::GetFirstSubKey(this: inResourceData);
    if ( FirstSubKey != nullptr )
    {
      v12 = pScheme;
      v19 = 0;
      while ( 1 )
      {
        v13 = &v17->_sides[v7].lines[v19 / 0xC];
        String = KeyValues::GetString(this: FirstSubKey, keyName: "color", defaultValue: nullptr);
        v13->col = *(Color *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v12->GetColor)(
                               a1: v12,
                               a2: v16,
                               a3: String,
                               a4: 0);
        v15 = KeyValues::GetString(this: FirstSubKey, keyName: "offset", defaultValue: nullptr);
        pScheme = nullptr;
        end = 0;
        if ( v15 != nullptr )
          sscanf(string: v15, format: "%d %d", &pScheme, &end);
        v19 += 12;
        v13->startOffset = (int)pScheme;
        v13->endOffset = end;
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        if ( FirstSubKey == nullptr )
          break;
        v7 = side_index;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001940
// Name: public: virtual void vgui::Border::ApplySchemeSettings(class vgui::IScheme __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Border::ApplySchemeSettings(
        vgui::Border *this,
        vgui::IScheme *pScheme,
        KeyValues *inResourceData)
{
  KeyValues *v3; // edi
  const char *String; // ebx
  KeyValues *Key; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  int left; // [esp+Ch] [ebp-Ch] BYREF
  int top; // [esp+10h] [ebp-8h] BYREF
  int right; // [esp+14h] [ebp-4h] BYREF

  v3 = inResourceData;
  String = KeyValues::GetString(this: inResourceData, keyName: "inset", defaultValue: "0 0 0 0");
  this->GetInset(this, a2: &left, a3: &top, a4: &right, a5: (int *)&inResourceData);
  sscanf(string: String, format: "%d %d %d %d", &left, &top, &right, &inResourceData);
  this->SetInset(this, a2: left, a3: top, a4: right, a5: (int)inResourceData);
  Key = KeyValues::FindKey(this: v3, keyName: "Left", bCreate: false);
  vgui::Border::ParseSideSettings(this, side_index: 0, inResourceData: Key, pScheme);
  v7 = KeyValues::FindKey(this: v3, keyName: "Top", bCreate: false);
  vgui::Border::ParseSideSettings(this, side_index: 1, inResourceData: v7, pScheme);
  v8 = KeyValues::FindKey(this: v3, keyName: "Right", bCreate: false);
  vgui::Border::ParseSideSettings(this, side_index: 2, inResourceData: v8, pScheme);
  v9 = KeyValues::FindKey(this: v3, keyName: "Bottom", bCreate: false);
  vgui::Border::ParseSideSettings(this, side_index: 3, inResourceData: v9, pScheme);
  this->m_eBackgroundType = KeyValues::GetInt(this: v3, keyName: "backgroundtype", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10001F30
// Name: public: virtual char const __near * vgui::Border::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Border::GetName(vgui::Border *this)
{
  char *result; // eax

  result = this->_name;
  if ( result == nullptr )
    return (char *)pHelpString;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001F40
// Name: public: virtual void vgui::Border::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Border::SetName(vgui::Border *this, const char *name)
{
  int v3; // esi
  char *v4; // eax

  if ( this->_name != nullptr )
    free(pMem: this->_name);
  v3 = _V_strlen(str: name) + 1;
  v4 = (char *)operator new(nSize: v3);
  this->_name = v4;
  V_strncpy(pDest: v4, pSrc: name, maxLen: v3);
}
