// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/playerlistcompare.cpp
// Functions: 1
// ============================================================

#include "tracker\adminserver\playerlistcompare.h"

//------------------------------------------------------------------------------
// Address: 0x10003190
// Name: int PlayerTimeCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PlayerTimeCompare(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // edi
  int v5; // esi
  int v6; // eax
  int v7; // ecx
  int v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int v12; // esi
  float v13; // xmm0_4
  float v14; // xmm1_4
  int s2; // [esp+Ch] [ebp-18h] BYREF
  int s1; // [esp+10h] [ebp-14h] BYREF
  int m2; // [esp+14h] [ebp-10h] BYREF
  int h2; // [esp+18h] [ebp-Ch] BYREF
  int h1; // [esp+1Ch] [ebp-8h] BYREF
  int m1; // [esp+20h] [ebp-4h] BYREF

  String = (char *)KeyValues::GetString(this: item1->kv, keyName: "time", defaultValue: defaultValue);
  v4 = (char *)KeyValues::GetString(this: item2->kv, keyName: "time", defaultValue: defaultValue);
  v5 = sscanf(string: String, format: "%i:%i:%i", &h1, &m1, &s1);
  v6 = sscanf(string: v4, format: "%i:%i:%i", &h2, &m2, &s2);
  if ( v5 != 0 )
  {
    if ( v5 == 1 )
    {
      v8 = h1;
      m1 = 0;
      v7 = 0;
    }
    else
    {
      v7 = v5 - 2;
      if ( v5 == 2 )
      {
        v8 = m1;
        m1 = h1;
      }
      else
      {
        v8 = s1;
        v7 = h1;
      }
    }
  }
  else
  {
    v8 = 0;
    m1 = 0;
    v7 = 0;
  }
  if ( v6 != 0 )
  {
    v9 = v6 - 1;
    if ( v9 != 0 )
    {
      v10 = v9 - 1;
      if ( v10 != 0 )
      {
        v11 = s2;
        v12 = m2;
        v10 = h2;
      }
      else
      {
        v11 = m2;
        v12 = h2;
      }
    }
    else
    {
      v11 = h2;
      v12 = 0;
      v10 = 0;
    }
  }
  else
  {
    v11 = 0;
    v12 = 0;
    v10 = 0;
  }
  v13 = (float)(v8 + 60 * (m1 + 60 * v7));
  v14 = (float)(v11 + 60 * (v12 + 60 * v10));
  if ( v14 <= v13 )
    return v13 > v14;
  else
    return -1;
}
