// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_entityreport.cpp
// Functions: 38
// ============================================================

#include "engine\cl_entityreport.h"

//------------------------------------------------------------------------------
// Address: 0x100843F0
// Name: MungeColorValue
// Source: json
//------------------------------------------------------------------------------
int __cdecl MungeColorValue(float cycle)
{
  int *value; // ecx
  char v2; // bl
  int v3; // eax
  int result; // eax

  v2 = 0;
  if ( *value < 128 )
  {
    v2 = 1;
    *value = 255 - *value;
  }
  v3 = (int)(float)((float)((*value - *value / 2) / 2 + *value / 2) + (float)((float)((*value - *value / 2) / 2) * cycle));
  *value = v3;
  if ( v2 != 0 )
    *value = 255 - v3;
  result = *value < 0 ? 0 : *value;
  *value = result;
  if ( result > 255 )
    result = 255;
  *value = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10084470
// Name: private: char const __near * CEntityReportPanel::MaybeTruncateName(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEntityReportPanel::MaybeTruncateName(CEntityReportPanel *this, int maxname, const char *pchName)
{
  const char *v3; // edi
  int v4; // eax
  int v5; // ebx
  char *v6; // esi
  int i; // eax
  char v8; // al

  v3 = pchName;
  v4 = _V_strlen(str: pchName);
  if ( *pchName == 67 )
  {
    --v4;
    v3 = pchName + 1;
  }
  v5 = v4 - maxname;
  v6 = truncated;
  if ( *v3 != 0 )
  {
    for ( i = 1 - (_DWORD)truncated; (unsigned int)&v6[i] < 0x40; i = 1 - (_DWORD)truncated )
    {
      v8 = tolower(c: *v3);
      if ( v5 >= 0 && this->m_BreakSetVowels.set[v8] != 0 )
      {
        ++v3;
        --v5;
      }
      else
      {
        *v6++ = v8;
        ++v3;
      }
      if ( *v3 == 0 )
        break;
    }
  }
  *v6 = 0;
  return truncated;
}

//------------------------------------------------------------------------------
// Address: 0x100844F0
// Name: public: static char const __near * vgui::Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Panel::GetPanelClassName()
{
  return "Panel";
}

//------------------------------------------------------------------------------
// Address: 0x10084530
// Name: public: virtual bool CEntityReportPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEntityReportPanel::ShouldDraw(CEntityReportPanel *this)
{
  return cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10084550
// Name: public: virtual void CEntityReportPanel::ApplyEffect(class CEntityBits __near *,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportPanel::ApplyEffect(CEntityReportPanel *this, CEntityBits *entry, int *r, int *g, int *b)
{
  float effectfinishtime; // xmm1_4
  float v6; // xmm1_4
  double v7; // st7
  int flags; // eax
  long double v9; // st7
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // ecx
  int v14; // eax
  int *v15; // ecx
  int v16; // eax
  int *v17; // ecx
  int v18; // eax
  int *v19; // ecx
  float v20; // [esp-4h] [ebp-4h]
  float v21; // [esp-4h] [ebp-4h]
  float v22; // [esp-4h] [ebp-4h]
  float v23; // [esp-4h] [ebp-4h]
  float v24; // [esp-4h] [ebp-4h]

  effectfinishtime = entry->effectfinishtime;
  if ( effectfinishtime >= realtime )
  {
    v6 = effectfinishtime - realtime;
    if ( (float)((float)(1.5 - v6) * 0.66666669) <= 1.0 )
      v7 = (float)((float)(1.5 - v6) * 0.66666669);
    else
      v7 = 1.0;
    if ( v7 < 0.0 )
      v7 = 0.0;
    flags = entry->flags;
    v9 = sin(v7 * 6.283185307179586 * 3.0);
    if ( (flags & 2) != 0 )
    {
      v20 = v9;
      v10 = MungeColorValue(cycle: v20, value: r);
      *v11 = v10;
    }
    else if ( (flags & 1) != 0 )
    {
      v21 = v9;
      v12 = MungeColorValue(cycle: v21, value: g);
      *v13 = v12;
    }
    else if ( (flags & 4) != 0 )
    {
      v22 = v9;
      v14 = MungeColorValue(cycle: v22, value: r);
      v23 = v9;
      *v15 = v14;
      v16 = MungeColorValue(cycle: v23, value: g);
      v24 = v9;
      *v17 = v16;
      v18 = MungeColorValue(cycle: v24, value: b);
      *v19 = v18;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084620
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Panel::GetMessageMap(vgui::Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetMessageMap'::`2'::s_pMap;
  `vgui::Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Panel");
  `vgui::Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10084660
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::GetKBMap(vgui::Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetKBMap'::`2'::s_pMap;
  `vgui::Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  `vgui::Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10084690
// Name: public: CEntityReportPanel::CEntityReportPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CEntityReportPanel *__thiscall CEntityReportPanel::CEntityReportPanel(CEntityReportPanel *this, vgui::Panel *parent)
{
  int v3; // edi
  int v4; // eax

  CBasePanel::CBasePanel(this, parent, panelName: "CEntityReportPanel");
  this->__vftable = (CEntityReportPanel_vtbl *)&CEntityReportPanel::`vftable';
  v3 = videomode->GetModeWidth(this: videomode);
  v4 = videomode->GetModeHeight(this: videomode);
  vgui::Panel::SetSize(this, wide: v3, tall: v4);
  vgui::Panel::SetPos(this, x: 0, y: 0);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetCursor(this, cursor: 0);
  this->m_hFont = 0;
  CBaseDemoAction::SetTimingType(this, color: (Color)-16777216);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  CharacterSetBuild(pSetBuffer: &this->m_BreakSetVowels, pszSetString: "aeiou");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10084740
// Name: public: virtual void CEntityReportPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEntityReportPanel::Paint(CEntityReportPanel *this@<ecx>, int *p_b@<edi>)
{
  float m_fValue; // xmm0_4
  int v4; // edi
  float *p_effectfinishtime; // esi
  int v6; // eax
  bool v7; // bl
  int m_nValue; // eax
  int v9; // esi
  int v10; // ebx
  int v11; // edi
  char v12; // al
  int *v13; // ebx
  const char *v14; // eax
  int v15; // edi
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  int v22; // ebx
  vgui::ISurface_vtbl *v23; // edx
  int v24; // esi
  int v25; // kr00_4
  void (__thiscall *DrawFilledRect)(vgui::ISurface *, int, int, int, int); // edx
  int v27; // ecx
  wchar_t unicode[256]; // [esp+8h] [ebp-360h] BYREF
  char text[256]; // [esp+208h] [ebp-160h] BYREF
  int v31; // [esp+308h] [ebp-60h]
  int v32; // [esp+30Ch] [ebp-5Ch]
  float fracs[3]; // [esp+310h] [ebp-58h]
  int screenw; // [esp+31Ch] [ebp-4Ch]
  int wide; // [esp+320h] [ebp-48h]
  int maxname; // [esp+324h] [ebp-44h]
  int v37; // [esp+328h] [ebp-40h]
  float graphfrac; // [esp+32Ch] [ebp-3Ch]
  CEntityReportPanel *v39; // [esp+330h] [ebp-38h]
  CEntityBits *list; // [esp+334h] [ebp-34h]
  int row; // [esp+338h] [ebp-30h]
  int b; // [esp+33Ch] [ebp-2Ch] BYREF
  int g; // [esp+340h] [ebp-28h] BYREF
  int i; // [esp+344h] [ebp-24h]
  int screenh; // [esp+348h] [ebp-20h]
  int v46; // [esp+34Ch] [ebp-1Ch]
  int colwidth; // [esp+350h] [ebp-18h]
  int r; // [esp+354h] [ebp-14h] BYREF
  float *p_average; // [esp+358h] [ebp-10h]
  int rowheight; // [esp+35Ch] [ebp-Ch]
  int lastused; // [esp+360h] [ebp-8h]
  bool inpvs; // [esp+367h] [ebp-1h]

  v39 = this;
  if ( this->m_hFont != 0 && GetBaseLocalClient()->m_nSignonState == 6 && entitylist != nullptr )
  {
    row = 0;
    if ( er_colwidth.m_pParent != nullptr )
      colwidth = er_colwidth.m_pParent->m_Value.m_nValue;
    else
      colwidth = 0;
    if ( er_maxname.m_pParent != nullptr )
      maxname = er_maxname.m_pParent->m_Value.m_nValue;
    else
      maxname = 0;
    rowheight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFont);
    screenw = videomode->GetModeWidth(this: videomode);
    *(float *)&screenh = COERCE_FLOAT(videomode->GetModeHeight(this: videomode));
    m_fValue = er_graphwidthfrac.m_pParent->m_Value.m_fValue;
    if ( m_fValue >= 0.1 )
    {
      if ( m_fValue <= 1.0 )
        graphfrac = er_graphwidthfrac.m_pParent->m_Value.m_fValue;
      else
        graphfrac = 1.0;
    }
    else
    {
      graphfrac = 0.1;
    }
    v4 = g_EntityReportMgr.m_EntityBits.m_Size - 1;
    lastused = g_EntityReportMgr.m_EntityBits.m_Size - 1;
    list = g_EntityReportMgr.m_EntityBits.m_Memory.m_pMemory;
    if ( g_EntityReportMgr.m_EntityBits.m_Size - 1 > 0 )
    {
      p_effectfinishtime = &g_EntityReportMgr.m_EntityBits.m_Memory.m_pMemory[v4].effectfinishtime;
      do
      {
        v6 = entitylist->GetClientNetworkable(this: entitylist, a2: v4);
        v7 = *p_effectfinishtime >= realtime;
        if ( v6 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6) != 0 )
          break;
        if ( v7 )
          break;
        --v4;
        p_effectfinishtime -= 7;
      }
      while ( v4 > 0 );
      lastused = v4;
    }
    m_nValue = 0;
    if ( cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue > 1 )
      m_nValue = cl_entityreport.m_pParent->m_Value.m_nValue;
    i = m_nValue;
    if ( m_nValue <= v4 )
    {
      v32 = screenh - rowheight;
      p_average = &list[m_nValue].average;
      v9 = colwidth + 3;
      v46 = colwidth + 3;
      v31 = 2 - colwidth;
      while ( 1 )
      {
        v10 = entitylist->GetClientNetworkable(this: entitylist, a2: i);
        if ( v10 != 0 )
          break;
LABEL_54:
        v27 = ++row * rowheight + 5;
        if ( v27 <= v32 || (v9 += colwidth, row = 0, v46 = v9, v9 + 2 <= screenw) )
        {
          p_average += 7;
          if ( ++i <= v4 )
            continue;
        }
        return;
      }
      v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      if ( v11 == 0 )
      {
LABEL_53:
        v4 = lastused;
        goto LABEL_54;
      }
      v12 = (*(int (__thiscall **)(int, int *))(*(_DWORD *)v10 + 36))(a1: v10, a2: p_b);
      inpvs = v12 == 0;
      if ( v12 != 0 )
      {
        r = 255;
        g = 150;
      }
      else
      {
        if ( *p_average >= 5.0 )
        {
          r = 200;
          g = 200;
          b = 250;
          goto LABEL_35;
        }
        r = 200;
        g = 255;
      }
      b = 100;
LABEL_35:
      p_b = &b;
      v13 = (int *)(p_average - 1);
      ((void (__thiscall *)(CEntityReportPanel *, float *, int *, int *))v39->ApplyEffect)(
        a1: v39,
        a2: p_average - 1,
        a3: &r,
        a4: &g);
      v14 = CEntityReportPanel::MaybeTruncateName(this: v39, maxname, pchName: *(const char **)(v11 + 8));
      V_snprintf(pDest: text, maxLen: 256, pFormat: "%i %s", i, v14);
      g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: text, a3: unicode, a4: 512);
      v15 = row * rowheight + 5;
      DrawColoredText(font: v39->m_hFont, x: v9 + v31, y: v15, r, g, b, a: 255, text: unicode);
      if ( inpvs )
      {
        v16 = (float)(*v13 >> 3) * 0.0099999998;
        v17 = (float)(*((int *)p_average + 1) >> 3) * 0.0099999998;
        v18 = (float)((int)*p_average >> 3) * 0.0099999998;
        if ( v16 < 0.0 )
          v16 = 0.0;
        if ( v16 > 1.0 )
          v16 = 1.0;
        fracs[0] = v16;
        if ( v17 >= 0.0 )
          v19 = v17;
        else
          v19 = 0.0;
        if ( v19 > 1.0 )
          v19 = 1.0;
        fracs[1] = v19;
        if ( v18 >= 0.0 )
          v20 = v18;
        else
          v20 = 0.0;
        if ( v20 > 1.0 )
          v20 = 1.0;
        fracs[2] = v20;
        v21 = (float)colwidth * graphfrac;
        if ( v21 < 1.0 )
          v21 = 1.0;
        v22 = v15 + rowheight - 1;
        v23 = g_pVGuiSurface->__vftable;
        wide = (int)v21;
        v24 = v9 - (int)v21;
        v23->DrawSetColor_2(this: g_pVGuiSurface, a2: 63, a3: 63, a4: 63, a5: 127);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v24, a3: v15, a4: v46, a5: v22);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 200, a3: 200, a4: 200, a5: 127);
        g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v24, a3: v15, a4: v46, a5: v22);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 200, a3: 255, a4: 100, a5: 192);
        v25 = rowheight;
        DrawFilledRect = g_pVGuiSurface->DrawFilledRect;
        v37 = v22 - 1;
        *(float *)&list = (float)wide;
        *(float *)&screenh = (float)v24;
        DrawFilledRect(
          this: g_pVGuiSurface,
          a2: v24,
          a3: rowheight / 2 + v15,
          a4: (int)(float)((float)((float)wide * fracs[0]) + (float)v24),
          a5: v22 - 1);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 192, a3: 192, a4: 192, a5: 255);
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)(float)((float)(*(float *)&list * fracs[2]) + *(float *)&screenh),
          a3: v25 / 2 + v15,
          a4: (int)(float)((float)((float)(*(float *)&list * fracs[2]) + *(float *)&screenh) + 1.0),
          a5: v37);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 192, a3: 0, a4: 0, a5: 255);
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)(float)((float)(*(float *)&list * fracs[1]) + *(float *)&screenh),
          a3: v15 + 1,
          a4: (int)(float)((float)((float)(*(float *)&list * fracs[1]) + *(float *)&screenh) + 1.0),
          a5: v25 / 2 + v15);
        v9 = v46;
      }
      goto LABEL_53;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084C80
// Name: void CL_ResetEntityBits(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ResetEntityBits()
{
  g_EntityReportMgr.m_EntityBits.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10084C90
// Name: void CL_CreateEntityReportPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_CreateEntityReportPanel(vgui::Panel *parent)
{
  CEntityReportPanel *v1; // eax

  v1 = (CEntityReportPanel *)MemAlloc_Alloc(nSize: 0x250u);
  if ( v1 != nullptr )
    g_pEntityReportPanel = CEntityReportPanel::CEntityReportPanel(this: v1, parent);
  else
    g_pEntityReportPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10084E70
// Name: public: void CEntityReportManager::Record(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportManager::Record(CEntityReportManager *this, unsigned int entnum, int bitcount)
{
  CEntityBits *v4; // eax
  float v5; // xmm0_4

  if ( entnum <= 0x7FF )
  {
    if ( this->m_EntityBits.m_Size < (signed int)(entnum + 1) )
      CUtlVector<CEntityBits,CUtlMemory<CEntityBits,int>>::InsertMultipleBefore(
        this: &this->m_EntityBits,
        elem: this->m_EntityBits.m_Size,
        num: entnum + 1 - this->m_EntityBits.m_Size);
    v4 = &this->m_EntityBits.m_Memory.m_pMemory[entnum];
    v5 = (float)((float)bitcount * 0.050000012) + (float)(v4->average * 0.94999999);
    v4->bits = bitcount;
    v4->average = v5;
    if ( realtime >= v4->peaktime )
    {
      v4->peak = 0;
      v4->peaktime = realtime + 2.0;
    }
    if ( bitcount > v4->peak )
      v4->peak = bitcount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084F10
// Name: void CL_RecordAddEntity(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RecordAddEntity(unsigned int entnum)
{
  CEntityBits *v1; // eax

  if ( cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue != 0 && entnum <= 0x7FF )
  {
    if ( g_EntityReportMgr.m_EntityBits.m_Size < (int)(entnum + 1) )
      CUtlVector<CEntityBits,CUtlMemory<CEntityBits,int>>::InsertMultipleBefore(
        this: &g_EntityReportMgr.m_EntityBits,
        elem: g_EntityReportMgr.m_EntityBits.m_Size,
        num: entnum + 1 - g_EntityReportMgr.m_EntityBits.m_Size);
    v1 = &g_EntityReportMgr.m_EntityBits.m_Memory.m_pMemory[entnum];
    v1->flags = 1;
    v1->effectfinishtime = realtime + 1.5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084F80
// Name: void CL_RecordEntityBits(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RecordEntityBits(unsigned int entnum, int bitcount)
{
  CEntityReportManager::Record(this: &g_EntityReportMgr, entnum, bitcount);
}

//------------------------------------------------------------------------------
// Address: 0x10084FB0
// Name: void CL_RecordLeavePVS(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RecordLeavePVS(unsigned int entnum)
{
  CEntityBits *v1; // eax

  if ( cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue != 0 && entnum <= 0x7FF )
  {
    if ( g_EntityReportMgr.m_EntityBits.m_Size < (int)(entnum + 1) )
      CUtlVector<CEntityBits,CUtlMemory<CEntityBits,int>>::InsertMultipleBefore(
        this: &g_EntityReportMgr.m_EntityBits,
        elem: g_EntityReportMgr.m_EntityBits.m_Size,
        num: entnum + 1 - g_EntityReportMgr.m_EntityBits.m_Size);
    v1 = &g_EntityReportMgr.m_EntityBits.m_Memory.m_pMemory[entnum];
    v1->flags = 2;
    v1->effectfinishtime = realtime + 1.5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085020
// Name: void CL_RecordDeleteEntity(int,class ClientClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RecordDeleteEntity(unsigned int entnum, ClientClass *pclass)
{
  CEntityBits *v2; // eax

  if ( cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue != 0 && entnum <= 0x7FF )
  {
    if ( g_EntityReportMgr.m_EntityBits.m_Size < (int)(entnum + 1) )
      CUtlVector<CEntityBits,CUtlMemory<CEntityBits,int>>::InsertMultipleBefore(
        this: &g_EntityReportMgr.m_EntityBits,
        elem: g_EntityReportMgr.m_EntityBits.m_Size,
        num: entnum + 1 - g_EntityReportMgr.m_EntityBits.m_Size);
    v2 = &g_EntityReportMgr.m_EntityBits.m_Memory.m_pMemory[entnum];
    v2->flags = 4;
    v2->effectfinishtime = realtime + 1.5;
    v2->deletedclientclass = pclass;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10284C20
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetParent(vgui::Panel *this)
{
  vgui::IPanel *v1; // esi
  vgui::IPanel_vtbl *v2; // edi
  int v3; // eax
  int v4; // esi
  vgui::IPanel *v5; // edi
  vgui::IPanel_vtbl *v6; // ebx
  const char *ControlsModuleName; // eax

  v1 = g_pVGuiPanel;
  if ( g_pVGuiPanel == nullptr )
    return nullptr;
  v2 = g_pVGuiPanel->__vftable;
  v3 = this->GetVPanel(this);
  v4 = v2->GetParent(this: v1, a2: v3);
  if ( v4 == 0 )
    return nullptr;
  v5 = g_pVGuiPanel;
  v6 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v6->GetPanel(this: v5, a2: v4, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x10284FB0
// Name: public: class vgui::Panel __near * vgui::Panel::FindSiblingByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindSiblingByName(vgui::Panel *this, const char *siblingName)
{
  vgui::Panel *result; // eax
  vgui::IPanel *v4; // edi
  vgui::IPanel_vtbl *v5; // esi
  unsigned int v6; // eax
  vgui::IPanel *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  int v9; // eax
  int v10; // eax
  vgui::IPanel *v11; // edi
  vgui::IPanel_vtbl *v12; // esi
  char *ControlsModuleName; // eax
  int v14; // esi
  const char *v15; // eax
  int siblingCount; // [esp+4h] [ebp-Ch]
  unsigned int sibling; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  result = (vgui::Panel *)this->GetVParent(this);
  if ( result != nullptr )
  {
    v4 = g_pVGuiPanel;
    v5 = g_pVGuiPanel->__vftable;
    v6 = this->GetVParent(this);
    siblingCount = v5->GetChildCount(this: v4, a2: v6);
    i = 0;
    if ( siblingCount <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        v7 = g_pVGuiPanel;
        v8 = g_pVGuiPanel->__vftable;
        v9 = ((int (__thiscall *)(vgui::Panel *, int))this->GetVParent)(a1: this, a2: i);
        v10 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetChild)(a1: v7, a2: v9);
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        sibling = v10;
        ControlsModuleName = vgui::GetControlsModuleName();
        v14 = (int)v12->GetPanel(this: v11, a2: sibling, a3: ControlsModuleName);
        v15 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 72))(a1: v14);
        if ( _V_stricmp(s1: v15, s2: siblingName) == 0 )
          break;
        if ( ++i >= siblingCount )
          return nullptr;
      }
      return (vgui::Panel *)v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102859E0
// Name: public: class vgui::Panel __near * vgui::Panel::GetChild(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetChild(vgui::Panel *this, int index)
{
  vgui::IPanel *v2; // edi
  vgui::IPanel *v4; // ebx
  char *ControlsModuleName; // eax
  int v6; // eax
  int v7; // eax
  vgui::IPanel_vtbl *v9; // [esp+Ch] [ebp-8h]
  vgui::IPanel_vtbl *v10; // [esp+10h] [ebp-4h]

  v2 = g_pVGuiPanel;
  v4 = g_pVGuiPanel;
  v9 = g_pVGuiPanel->__vftable;
  v10 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  v6 = ((int (__thiscall *)(vgui::Panel *, int, char *))this->GetVPanel)(a1: this, a2: index, a3: ControlsModuleName);
  v7 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v2, a2: v6);
  return ((vgui::Panel *(__thiscall *)(vgui::IPanel *, int))v9->GetPanel)(a1: v4, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10285CA0
// Name: public: virtual class vgui::IBorder __near * vgui::Panel::GetBorder(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Panel::GetBorder(vgui::Panel *this)
{
  return this->_border;
}

//------------------------------------------------------------------------------
// Address: 0x10286060
// Name: public: enum vgui::Panel::PinCorner_e vgui::Panel::GetPinCorner(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetPinCorner(vgui::Panel *this)
{
  return *((_BYTE *)this + 166) & 0xF;
}

//------------------------------------------------------------------------------
// Address: 0x10286090
// Name: public: enum vgui::Panel::AutoResize_e vgui::Panel::GetAutoResize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetAutoResize(vgui::Panel *this)
{
  return *((unsigned __int8 *)this + 166) >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x10286510
// Name: public: virtual struct vgui::PanelMap_t __near * vgui::Panel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall vgui::Panel::GetPanelMap(vgui::Panel *this)
{
  return &vgui::Panel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x10287DA0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDropTarget(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDropTarget(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  vgui::Panel *v4; // eax

  if ( this->m_pDragDrop->m_bDropEnabled && this->IsDroppable(this, a2: msglist) )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDropTarget(this: v4, a2: msglist);
}

//------------------------------------------------------------------------------
// Address: 0x10287E10
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDragPanel(vgui::Panel *this)
{
  vgui::DragDrop_t *m_pDragDrop; // eax
  vgui::Panel *v4; // eax

  m_pDragDrop = this->m_pDragDrop;
  if ( m_pDragDrop->m_bPreventChaining )
    return nullptr;
  if ( m_pDragDrop->m_bDragEnabled )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDragPanel(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10288B60
// Name: public: class vgui::Panel __near * vgui::Panel::FindChildByName(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindChildByName(vgui::Panel *this, const char *childName, bool recurseDown)
{
  vgui::IPanel *v3; // ebx
  vgui::IPanel_vtbl *v4; // esi
  int v5; // eax
  int v6; // eax
  vgui::IPanel_vtbl *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  char *ControlsModuleName; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  vgui::Panel *v13; // esi
  const char *v14; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v16; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v16 = this;
  for ( i = 0; ; ++i )
  {
    v3 = g_pVGuiPanel;
    if ( g_pVGuiPanel != nullptr )
    {
      v4 = g_pVGuiPanel->__vftable;
      v5 = this->GetVPanel(this);
      v6 = v4->GetChildCount(this: v3, a2: v5);
      v3 = g_pVGuiPanel;
    }
    else
    {
      v6 = 0;
    }
    if ( i >= v6 )
      break;
    v7 = v3->__vftable;
    v8 = v3->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v10 = ((int (__thiscall *)(vgui::Panel *, int, char *))v16->GetVPanel)(a1: v16, a2: i, a3: ControlsModuleName);
    v11 = ((int (__thiscall *)(vgui::IPanel *, int))v7->GetChild)(a1: v3, a2: v10);
    v12 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetPanel)(a1: v3, a2: v11);
    v13 = (vgui::Panel *)v12;
    if ( v12 != 0 )
    {
      v14 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 72))(a1: v12);
      if ( _V_stricmp(s1: v14, s2: childName) == 0 )
        return v13;
      if ( recurseDown )
      {
        result = vgui::Panel::FindChildByName(this: v13, childName, recurseDown);
        if ( result != nullptr )
          return result;
      }
    }
    this = v16;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10289CB0
// Name: public: class vgui::Tooltip __near * vgui::Panel::GetTooltip(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Panel::GetTooltip(vgui::Panel *this)
{
  vgui::Tooltip *v2; // eax
  vgui::Tooltip *result; // eax
  bool v4; // zf

  if ( this->m_pTooltips != nullptr )
    return this->m_pTooltips;
  v2 = (vgui::Tooltip *)MemAlloc_Alloc(nSize: 0x24u);
  if ( v2 != nullptr )
    result = vgui::Tooltip::Tooltip(this: v2, parent: this, text: nullptr);
  else
    result = nullptr;
  v4 = (*((_BYTE *)this + 172) & 8) == 0;
  this->m_pTooltips = result;
  if ( !v4 )
  {
    vgui::Tooltip::SetEnabled(this: result, bState: false);
    return this->m_pTooltips;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028A4A0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavUp(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavUp(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavUp; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  CDragDropHelperPanel *ChildByName; // eax
  unsigned int v11; // edi
  vgui::IPanel *v12; // esi
  vgui::IPanel_vtbl *v13; // ebx
  char *v14; // eax
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // edi
  vgui::IPanel *v18; // esi
  vgui::IPanel_vtbl *v19; // ebx
  char *v20; // eax
  unsigned int v21; // eax
  vgui::PHandle *v22; // ebx
  unsigned int v23; // edi
  vgui::IPanel *v24; // esi
  vgui::IPanel_vtbl *v25; // ebx
  char *v26; // eax
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  const char *v31; // [esp-8h] [ebp-20h]
  vgui::PHandle *v33; // [esp+10h] [ebp-8h]
  vgui::Panel *v34; // [esp+14h] [ebp-4h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavUp.m_iPanelID;
  p_m_NavUp = &this->m_NavUp;
  v33 = &this->m_NavUp;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v34 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, char *))v34->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavUp = v33,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavUpName) > 0 )
    {
      v31 = CUtlString::operator char const *(this: &this->m_sNavUpName);
      v9 = this->GetParent(this);
      ChildByName = (CDragDropHelperPanel *)vgui::Panel::FindChildByName(this: v9, childName: v31, recurseDown: true);
      if ( ChildByName != nullptr )
        vgui::PHandle::operator=(this: p_m_NavUp, pPanel: ChildByName);
    }
  }
  if ( p_m_NavUp->m_iPanelID == -1 || (v11 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID)) == 0 )
  {
    v35 = nullptr;
    v16 = 0;
  }
  else
  {
    v12 = g_pVGuiPanel;
    v13 = g_pVGuiPanel->__vftable;
    v14 = vgui::GetControlsModuleName();
    v15 = (int)v13->GetPanel(this: v12, a2: v11, a3: v14);
    p_m_NavUp = v33;
    v16 = v15;
    v35 = (vgui::Panel *)v15;
  }
  if ( p_m_NavUp->m_iPanelID == -1 )
    return (vgui::Panel *)v16;
  v17 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID);
  if ( v17 == 0 )
    return (vgui::Panel *)v16;
  v18 = g_pVGuiPanel;
  v19 = g_pVGuiPanel->__vftable;
  v20 = vgui::GetControlsModuleName();
  if ( v19->GetPanel(this: v18, a2: v17, a3: v20) == nullptr )
    return v35;
  v21 = this->m_NavUp.m_iPanelID;
  v22 = &this->m_NavUp;
  if ( v21 == -1 || (v23 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v21)) == 0 )
  {
    v27 = nullptr;
  }
  else
  {
    v24 = g_pVGuiPanel;
    v25 = g_pVGuiPanel->__vftable;
    v26 = vgui::GetControlsModuleName();
    v27 = v25->GetPanel(this: v24, a2: v23, a3: v26);
    v22 = &this->m_NavUp;
  }
  if ( v27 == first )
    return v35;
  v28 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v22);
  if ( v28->IsVisible(this: v28) )
    return v35;
  v29 = this;
  if ( first != nullptr )
    v29 = first;
  return vgui::Panel::GetNavUp(this: v35, first: v29);
}

//------------------------------------------------------------------------------
// Address: 0x1028A660
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavDown(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavDown(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavDown; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  CDragDropHelperPanel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavDown.m_iPanelID;
  p_m_NavDown = &this->m_NavDown;
  v34 = &this->m_NavDown;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavDown = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavDownName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavDownName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = (CDragDropHelperPanel *)ChildByName->GetPanel(this: ChildByName);
        vgui::PHandle::operator=(this: p_m_NavDown, pPanel: v11);
      }
    }
  }
  if ( p_m_NavDown->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavDown = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavDown->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavDown.m_iPanelID;
  v23 = &this->m_NavDown;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavDown;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavDown(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x1028A830
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavLeft(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavLeft; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  CDragDropHelperPanel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavLeft.m_iPanelID;
  p_m_NavLeft = &this->m_NavLeft;
  v34 = &this->m_NavLeft;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavLeft = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavLeftName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavLeftName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = (CDragDropHelperPanel *)ChildByName->GetPanel(this: ChildByName);
        vgui::PHandle::operator=(this: p_m_NavLeft, pPanel: v11);
      }
    }
  }
  if ( p_m_NavLeft->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavLeft = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavLeft->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavLeft.m_iPanelID;
  v23 = &this->m_NavLeft;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavLeft;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavLeft(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x1028AA00
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavRight(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavRight; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  CDragDropHelperPanel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavRight.m_iPanelID;
  p_m_NavRight = &this->m_NavRight;
  v34 = &this->m_NavRight;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavRight = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavRightName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavRightName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = (CDragDropHelperPanel *)ChildByName->GetPanel(this: ChildByName);
        vgui::PHandle::operator=(this: p_m_NavRight, pPanel: v11);
      }
    }
  }
  if ( p_m_NavRight->m_iPanelID == -1
    || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavRight = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavRight->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavRight.m_iPanelID;
  v23 = &this->m_NavRight;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavRight;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavRight(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x1028B180
// Name: public: struct vgui::PanelKeyBindingMap __near * vgui::Panel::LookupMapForBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::LookupMapForBinding(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *v2; // ebx
  int v3; // edi
  int v4; // esi
  int c; // [esp+Ch] [ebp-4h]

  v2 = this->GetKBMap(this);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    v3 = 0;
    c = v2->entries.m_Size;
    if ( c > 0 )
      break;
LABEL_6:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  v4 = 0;
  while ( _V_stricmp(s1: v2->entries.m_Memory.m_pMemory[v4].bindingname, s2: bindingName) != 0 )
  {
    ++v3;
    ++v4;
    if ( v3 >= c )
      goto LABEL_6;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1028B1E0
// Name: public: struct vgui::KeyBindingMap_t __near * vgui::Panel::LookupBindingByKeyCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingMap_t *__thiscall vgui::Panel::LookupBindingByKeyCode(
        vgui::Panel *this,
        ButtonCode_t code,
        int modifiers)
{
  vgui::Panel *v3; // esi
  vgui::PanelKeyBindingMap *v4; // ebx
  int m_Size; // edi
  vgui::BoundKey_t *v6; // eax
  vgui::PanelKeyBindingMap *v7; // eax
  int v8; // ebx
  int v9; // edi
  const char **p_bindingname; // esi
  int c; // [esp+Ch] [ebp-20h]
  int v14; // [esp+14h] [ebp-18h]
  char *s2; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  vgui::PanelKeyBindingMap *map; // [esp+20h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-8h]
  vgui::PanelKeyBindingMap *baseMap; // [esp+28h] [ebp-4h]

  v3 = this;
  map = (vgui::PanelKeyBindingMap *)((int (__fastcall *)(vgui::Panel *))this->GetKBMap)(a1: this);
  if ( map == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = map;
    m_Size = map->boundkeys.m_Size;
    c = m_Size;
    i = 0;
    if ( m_Size > 0 )
      break;
LABEL_17:
    map = v4->baseMap;
    if ( map == nullptr )
      return nullptr;
  }
  v18 = 0;
  while ( 1 )
  {
    v6 = &v4->boundkeys.m_Memory.m_pMemory[v18];
    if ( v6->keycode == code && v6->modifiers == modifiers )
    {
      s2 = (char *)v6->bindingname;
      v7 = v3->GetKBMap(this: v3);
      baseMap = v7;
      if ( v7 != nullptr )
        break;
    }
LABEL_16:
    ++v18;
    if ( ++i >= m_Size )
      goto LABEL_17;
  }
  while ( 1 )
  {
    v8 = 0;
    v14 = v7->entries.m_Size;
    if ( v14 > 0 )
      break;
LABEL_14:
    baseMap = v7->baseMap;
    if ( baseMap == nullptr )
    {
      m_Size = c;
      v4 = map;
      goto LABEL_16;
    }
    v7 = v7->baseMap;
  }
  v9 = 0;
  while ( 1 )
  {
    p_bindingname = &v7->entries.m_Memory.m_pMemory[v9].bindingname;
    if ( _V_stricmp(s1: *p_bindingname, s2) == 0 )
      return (vgui::KeyBindingMap_t *)p_bindingname;
    v7 = baseMap;
    ++v8;
    ++v9;
    if ( v8 >= v14 )
    {
      v3 = this;
      goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028C5E0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateUp(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateUp(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavUp(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_UP;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028C620
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateDown(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateDown(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavDown(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_DOWN;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028C660
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateLeft(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateLeft(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavLeft(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_LEFT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028C6A0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateRight(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateRight(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavRight(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_RIGHT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10291990
// Name: private: class vgui::Panel __near * vgui::Panel::FindDropTargetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindDropTargetPanel(vgui::Panel *this)
{
  unsigned int v1; // ebx
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // esi
  char *ControlsModuleName; // eax
  unsigned int v5; // ebx
  vgui::IPanel *v6; // edi
  vgui::IPanel_vtbl *v7; // esi
  char *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // ebx
  int v11; // edi
  int m_Size; // eax
  unsigned int v13; // eax
  unsigned int v14; // esi
  int v15; // eax
  vgui::IPanel *v17; // edi
  vgui::IPanel_vtbl *v18; // esi
  unsigned int *v19; // ebx
  const char *v20; // eax
  int v21; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > hits; // [esp+Ch] [ebp-24h] BYREF
  int nCount; // [esp+20h] [ebp-10h]
  vgui::Panel *v24; // [esp+24h] [ebp-Ch]
  int x; // [esp+28h] [ebp-8h] BYREF
  int y; // [esp+2Ch] [ebp-4h] BYREF

  v24 = this;
  if ( s_DragDropHelper.m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  if ( v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName) == nullptr )
    return nullptr;
  memset(&hits, 0, sizeof(hits));
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  nCount = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  if ( s_DragDropHelper.m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID)) == 0 )
  {
    v9 = nullptr;
  }
  else
  {
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    v8 = vgui::GetControlsModuleName();
    v9 = v7->GetPanel(this: v6, a2: v5, a3: v8);
  }
  v10 = v9->GetVPanel(this: v9);
  if ( g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface)
    && g_pVGuiSurface->IsWithin(this: g_pVGuiSurface, a2: x, a3: y) )
  {
    v11 = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1;
    if ( v11 >= 0 )
    {
      do
      {
        m_Size = hits.m_Size;
        if ( hits.m_Size != 0 )
          goto LABEL_20;
        v13 = g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: v11);
        v14 = v13;
        if ( v13 != nCount && v13 != v10 && g_pVGuiPanel->IsFullyVisible(this: g_pVGuiPanel, a2: v13) )
          vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: v14);
      }
      while ( --v11 >= 0 );
    }
    m_Size = hits.m_Size;
    if ( hits.m_Size != 0 )
      goto LABEL_20;
    vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: nCount);
  }
  m_Size = hits.m_Size;
  if ( hits.m_Size == 0 )
  {
LABEL_21:
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&hits);
    return nullptr;
  }
LABEL_20:
  v15 = m_Size - 1;
  nCount = v15;
  if ( v15 < 0 )
    goto LABEL_21;
  while ( 1 )
  {
    v17 = g_pVGuiPanel;
    v18 = g_pVGuiPanel->__vftable;
    v19 = &hits.m_Memory.m_pMemory[v15];
    v20 = v24->GetModuleName(this: v24);
    v21 = (int)v18->GetPanel(this: v17, a2: *v19, a3: v20);
    if ( v21 != 0 )
      break;
    if ( --nCount < 0 )
    {
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&hits);
      return nullptr;
    }
    v15 = nCount;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&hits);
  return (vgui::Panel *)v21;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10084130
// Name: MungeColorValue
// Source: json
//------------------------------------------------------------------------------
int __cdecl MungeColorValue(float cycle)
{
  int *value; // ecx
  char v2; // bl
  int v3; // eax
  int result; // eax

  v2 = 0;
  if ( *value < 128 )
  {
    v2 = 1;
    *value = 255 - *value;
  }
  v3 = (int)(float)((float)((*value - *value / 2) / 2 + *value / 2) + (float)((float)((*value - *value / 2) / 2) * cycle));
  *value = v3;
  if ( v2 != 0 )
    *value = 255 - v3;
  result = *value < 0 ? 0 : *value;
  *value = result;
  if ( result > 255 )
    result = 255;
  *value = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100841B0
// Name: private: char const __near * CEntityReportPanel::MaybeTruncateName(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEntityReportPanel::MaybeTruncateName(CEntityReportPanel *this, int maxname, const char *pchName)
{
  const char *v3; // edi
  int v4; // eax
  int v5; // ebx
  char *v6; // esi
  int i; // eax
  char v8; // al

  v3 = pchName;
  v4 = _V_strlen(str: pchName);
  if ( *pchName == 67 )
  {
    --v4;
    v3 = pchName + 1;
  }
  v5 = v4 - maxname;
  v6 = truncated;
  if ( *v3 != 0 )
  {
    for ( i = 1 - (_DWORD)truncated; (unsigned int)&v6[i] < 0x40; i = 1 - (_DWORD)truncated )
    {
      v8 = tolower(c: *v3);
      if ( v5 >= 0 && this->m_BreakSetVowels.set[v8] != 0 )
      {
        ++v3;
        --v5;
      }
      else
      {
        *v6++ = v8;
        ++v3;
      }
      if ( *v3 == 0 )
        break;
    }
  }
  *v6 = 0;
  return truncated;
}

//------------------------------------------------------------------------------
// Address: 0x10084230
// Name: public: static char const __near * vgui::Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Panel::GetPanelClassName()
{
  return "Panel";
}

//------------------------------------------------------------------------------
// Address: 0x10084270
// Name: public: virtual bool CEntityReportPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEntityReportPanel::ShouldDraw(CEntityReportPanel *this)
{
  return cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10084290
// Name: public: virtual void CEntityReportPanel::ApplyEffect(class CEntityBits __near *,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportPanel::ApplyEffect(CEntityReportPanel *this, CEntityBits *entry, int *r, int *g, int *b)
{
  float effectfinishtime; // xmm1_4
  float v6; // xmm1_4
  double v7; // st7
  int flags; // eax
  long double v9; // st7
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // ecx
  int v14; // eax
  int *v15; // ecx
  int v16; // eax
  int *v17; // ecx
  float cycle; // [esp+0h] [ebp-4h]
  float cyclea; // [esp+0h] [ebp-4h]
  float cycleb; // [esp+0h] [ebp-4h]
  float cyclec; // [esp+0h] [ebp-4h]

  effectfinishtime = entry->effectfinishtime;
  if ( effectfinishtime >= realtime )
  {
    v6 = effectfinishtime - realtime;
    if ( (float)((float)(1.5 - v6) * 0.66666669) <= 1.0 )
      v7 = (float)((float)(1.5 - v6) * 0.66666669);
    else
      v7 = 1.0;
    if ( v7 < 0.0 )
      v7 = 0.0;
    flags = entry->flags;
    v9 = sin(v7 * 6.283185307179586 * 3.0);
    if ( (flags & 2) != 0 || (flags & 1) != 0 )
    {
      cycle = v9;
      v10 = MungeColorValue(cycle);
      *v11 = v10;
    }
    else if ( (flags & 4) != 0 )
    {
      cyclea = v9;
      v12 = MungeColorValue(cycle: cyclea);
      cycleb = v9;
      *v13 = v12;
      v14 = MungeColorValue(cycle: cycleb);
      cyclec = v9;
      *v15 = v14;
      v16 = MungeColorValue(cycle: cyclec);
      *v17 = v16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084360
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Panel::GetMessageMap(vgui::Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetMessageMap'::`2'::s_pMap;
  `vgui::Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Panel");
  `vgui::Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100843A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::GetKBMap(vgui::Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetKBMap'::`2'::s_pMap;
  `vgui::Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  `vgui::Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100843D0
// Name: public: CEntityReportPanel::CEntityReportPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CEntityReportPanel *__thiscall CEntityReportPanel::CEntityReportPanel(CEntityReportPanel *this, vgui::Panel *parent)
{
  int v3; // edi
  int v4; // eax

  CBasePanel::CBasePanel(this, parent, panelName: "CEntityReportPanel");
  this->__vftable = (CEntityReportPanel_vtbl *)&CEntityReportPanel::`vftable';
  v3 = videomode->GetModeWidth(this: videomode);
  v4 = videomode->GetModeHeight(this: videomode);
  vgui::Panel::SetSize(this, wide: v3, tall: v4);
  vgui::Panel::SetPos(this, x: 0, y: 0);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Panel::SetCursor(this, cursor: 0);
  this->m_hFont = 0;
  CBaseDemoAction::SetTimingType(this, color: (Color)-16777216);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  CharacterSetBuild(pSetBuffer: &this->m_BreakSetVowels, pszSetString: "aeiou");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10084480
// Name: public: virtual void CEntityReportPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEntityReportPanel::Paint(CEntityReportPanel *this@<ecx>, int *p_b@<edi>)
{
  float m_fValue; // xmm0_4
  int v4; // edi
  float *p_effectfinishtime; // esi
  int v6; // eax
  bool v7; // bl
  int m_nValue; // eax
  int v9; // esi
  int v10; // ebx
  int v11; // edi
  char v12; // al
  int *v13; // ebx
  char *v14; // eax
  int v15; // edi
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  int v22; // ebx
  vgui::ISurface_vtbl *v23; // edx
  int v24; // esi
  int v25; // kr00_4
  void (__thiscall *DrawFilledRect)(vgui::ISurface *, int, int, int, int); // edx
  int v27; // ecx
  wchar_t unicode[256]; // [esp+8h] [ebp-360h] BYREF
  char text[256]; // [esp+208h] [ebp-160h] BYREF
  int v31; // [esp+308h] [ebp-60h]
  int v32; // [esp+30Ch] [ebp-5Ch]
  float fracs[3]; // [esp+310h] [ebp-58h]
  int screenw; // [esp+31Ch] [ebp-4Ch]
  int wide; // [esp+320h] [ebp-48h]
  int maxname; // [esp+324h] [ebp-44h]
  int v37; // [esp+328h] [ebp-40h]
  float graphfrac; // [esp+32Ch] [ebp-3Ch]
  CEntityReportPanel *v39; // [esp+330h] [ebp-38h]
  CEntityBits *list; // [esp+334h] [ebp-34h]
  int row; // [esp+338h] [ebp-30h]
  int b; // [esp+33Ch] [ebp-2Ch] BYREF
  int g; // [esp+340h] [ebp-28h] BYREF
  int i; // [esp+344h] [ebp-24h]
  int screenh; // [esp+348h] [ebp-20h]
  int v46; // [esp+34Ch] [ebp-1Ch]
  int colwidth; // [esp+350h] [ebp-18h]
  int r; // [esp+354h] [ebp-14h] BYREF
  float *p_average; // [esp+358h] [ebp-10h]
  int rowheight; // [esp+35Ch] [ebp-Ch]
  int lastused; // [esp+360h] [ebp-8h]
  bool inpvs; // [esp+367h] [ebp-1h]

  v39 = this;
  if ( this->m_hFont != 0 && GetBaseLocalClient()->m_nSignonState == 6 && entitylist != nullptr )
  {
    row = 0;
    if ( er_colwidth.m_pParent != nullptr )
      colwidth = er_colwidth.m_pParent->m_Value.m_nValue;
    else
      colwidth = 0;
    if ( er_maxname.m_pParent != nullptr )
      maxname = er_maxname.m_pParent->m_Value.m_nValue;
    else
      maxname = 0;
    rowheight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFont);
    screenw = videomode->GetModeWidth(this: videomode);
    *(float *)&screenh = COERCE_FLOAT(videomode->GetModeHeight(this: videomode));
    m_fValue = er_graphwidthfrac.m_pParent->m_Value.m_fValue;
    if ( m_fValue >= 0.1 )
    {
      if ( m_fValue <= 1.0 )
        graphfrac = er_graphwidthfrac.m_pParent->m_Value.m_fValue;
      else
        graphfrac = 1.0;
    }
    else
    {
      graphfrac = 0.1;
    }
    v4 = g_EntityReportMgr.m_EntityBits.m_Size - 1;
    lastused = g_EntityReportMgr.m_EntityBits.m_Size - 1;
    list = g_EntityReportMgr.m_EntityBits.m_Memory.m_pMemory;
    if ( g_EntityReportMgr.m_EntityBits.m_Size - 1 > 0 )
    {
      p_effectfinishtime = &g_EntityReportMgr.m_EntityBits.m_Memory.m_pMemory[v4].effectfinishtime;
      do
      {
        v6 = entitylist->GetClientNetworkable(this: entitylist, a2: v4);
        v7 = *p_effectfinishtime >= realtime;
        if ( v6 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6) != 0 )
          break;
        if ( v7 )
          break;
        --v4;
        p_effectfinishtime -= 7;
      }
      while ( v4 > 0 );
      lastused = v4;
    }
    m_nValue = 0;
    if ( cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue > 1 )
      m_nValue = cl_entityreport.m_pParent->m_Value.m_nValue;
    i = m_nValue;
    if ( m_nValue <= v4 )
    {
      v32 = screenh - rowheight;
      p_average = &list[m_nValue].average;
      v9 = colwidth + 3;
      v46 = colwidth + 3;
      v31 = 2 - colwidth;
      while ( 1 )
      {
        v10 = entitylist->GetClientNetworkable(this: entitylist, a2: i);
        if ( v10 != 0 )
          break;
LABEL_54:
        v27 = ++row * rowheight + 5;
        if ( v27 <= v32 || (v9 += colwidth, row = 0, v46 = v9, v9 + 2 <= screenw) )
        {
          p_average += 7;
          if ( ++i <= v4 )
            continue;
        }
        return;
      }
      v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      if ( v11 == 0 )
      {
LABEL_53:
        v4 = lastused;
        goto LABEL_54;
      }
      v12 = (*(int (__thiscall **)(int, int *))(*(_DWORD *)v10 + 36))(a1: v10, a2: p_b);
      inpvs = v12 == 0;
      if ( v12 != 0 )
      {
        r = 255;
        g = 150;
      }
      else
      {
        if ( *p_average >= 5.0 )
        {
          r = 200;
          g = 200;
          b = 250;
          goto LABEL_35;
        }
        r = 200;
        g = 255;
      }
      b = 100;
LABEL_35:
      p_b = &b;
      v13 = (int *)(p_average - 1);
      ((void (__thiscall *)(CEntityReportPanel *, float *, int *, int *))v39->ApplyEffect)(
        a1: v39,
        a2: p_average - 1,
        a3: &r,
        a4: &g);
      v14 = CEntityReportPanel::MaybeTruncateName(this: v39, maxname, pchName: *(const char **)(v11 + 8));
      V_snprintf(pDest: text, maxLen: 256, pFormat: "%i %s", i, v14);
      g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: text, a3: unicode, a4: 512);
      v15 = row * rowheight + 5;
      DrawColoredText(font: v39->m_hFont, x: v9 + v31, y: v15, r, g, b, a: 255, text: unicode);
      if ( inpvs )
      {
        v16 = (float)(*v13 >> 3) * 0.0099999998;
        v17 = (float)(*((int *)p_average + 1) >> 3) * 0.0099999998;
        v18 = (float)((int)*p_average >> 3) * 0.0099999998;
        if ( v16 < 0.0 )
          v16 = 0.0;
        if ( v16 > 1.0 )
          v16 = 1.0;
        fracs[0] = v16;
        if ( v17 >= 0.0 )
          v19 = v17;
        else
          v19 = 0.0;
        if ( v19 > 1.0 )
          v19 = 1.0;
        fracs[1] = v19;
        if ( v18 >= 0.0 )
          v20 = v18;
        else
          v20 = 0.0;
        if ( v20 > 1.0 )
          v20 = 1.0;
        fracs[2] = v20;
        v21 = (float)colwidth * graphfrac;
        if ( v21 < 1.0 )
          v21 = 1.0;
        v22 = v15 + rowheight - 1;
        v23 = g_pVGuiSurface->__vftable;
        wide = (int)v21;
        v24 = v9 - (int)v21;
        v23->DrawSetColor_2(this: g_pVGuiSurface, a2: 63, a3: 63, a4: 63, a5: 127);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v24, a3: v15, a4: v46, a5: v22);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 200, a3: 200, a4: 200, a5: 127);
        g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v24, a3: v15, a4: v46, a5: v22);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 200, a3: 255, a4: 100, a5: 192);
        v25 = rowheight;
        DrawFilledRect = g_pVGuiSurface->DrawFilledRect;
        v37 = v22 - 1;
        *(float *)&list = (float)wide;
        *(float *)&screenh = (float)v24;
        DrawFilledRect(
          this: g_pVGuiSurface,
          a2: v24,
          a3: rowheight / 2 + v15,
          a4: (int)(float)((float)((float)wide * fracs[0]) + (float)v24),
          a5: v22 - 1);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 192, a3: 192, a4: 192, a5: 255);
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)(float)((float)(*(float *)&list * fracs[2]) + *(float *)&screenh),
          a3: v25 / 2 + v15,
          a4: (int)(float)((float)((float)(*(float *)&list * fracs[2]) + *(float *)&screenh) + 1.0),
          a5: v37);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 192, a3: 0, a4: 0, a5: 255);
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)(float)((float)(*(float *)&list * fracs[1]) + *(float *)&screenh),
          a3: v15 + 1,
          a4: (int)(float)((float)((float)(*(float *)&list * fracs[1]) + *(float *)&screenh) + 1.0),
          a5: v25 / 2 + v15);
        v9 = v46;
      }
      goto LABEL_53;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100849C0
// Name: void CL_ResetEntityBits(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ResetEntityBits()
{
  g_EntityReportMgr.m_EntityBits.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100849D0
// Name: void CL_CreateEntityReportPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_CreateEntityReportPanel(vgui::Panel *parent)
{
  CEntityReportPanel *v1; // eax

  v1 = (CEntityReportPanel *)MemAlloc_Alloc(nSize: 0x250u);
  if ( v1 != nullptr )
    g_pEntityReportPanel = CEntityReportPanel::CEntityReportPanel(this: v1, parent);
  else
    g_pEntityReportPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10084BB0
// Name: public: void CEntityReportManager::Record(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportManager::Record(CEntityReportManager *this, unsigned int entnum, int bitcount)
{
  CEntityBits *v4; // eax
  float v5; // xmm0_4

  if ( entnum <= 0x7FF )
  {
    if ( this->m_EntityBits.m_Size < (signed int)(entnum + 1) )
      CUtlVector<CEntityBits,CUtlMemory<CEntityBits,int>>::InsertMultipleBefore(
        this: &this->m_EntityBits,
        elem: this->m_EntityBits.m_Size,
        num: entnum + 1 - this->m_EntityBits.m_Size);
    v4 = &this->m_EntityBits.m_Memory.m_pMemory[entnum];
    v5 = (float)((float)bitcount * 0.050000012) + (float)(v4->average * 0.94999999);
    v4->bits = bitcount;
    v4->average = v5;
    if ( realtime >= v4->peaktime )
    {
      v4->peak = 0;
      v4->peaktime = realtime + 2.0;
    }
    if ( bitcount > v4->peak )
      v4->peak = bitcount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084C50
// Name: void CL_RecordAddEntity(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RecordAddEntity(unsigned int entnum)
{
  CEntityBits *v1; // eax

  if ( cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue != 0 && entnum <= 0x7FF )
  {
    if ( g_EntityReportMgr.m_EntityBits.m_Size < (int)(entnum + 1) )
      CUtlVector<CEntityBits,CUtlMemory<CEntityBits,int>>::InsertMultipleBefore(
        this: &g_EntityReportMgr.m_EntityBits,
        elem: g_EntityReportMgr.m_EntityBits.m_Size,
        num: entnum + 1 - g_EntityReportMgr.m_EntityBits.m_Size);
    v1 = &g_EntityReportMgr.m_EntityBits.m_Memory.m_pMemory[entnum];
    v1->flags = 1;
    v1->effectfinishtime = realtime + 1.5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084CC0
// Name: void CL_RecordEntityBits(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RecordEntityBits(unsigned int entnum, int bitcount)
{
  CEntityReportManager::Record(this: &g_EntityReportMgr, entnum, bitcount);
}

//------------------------------------------------------------------------------
// Address: 0x10084CE0
// Name: void CL_RecordLeavePVS(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RecordLeavePVS(unsigned int entnum)
{
  CEntityBits *v1; // eax

  if ( cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue != 0 && entnum <= 0x7FF )
  {
    if ( g_EntityReportMgr.m_EntityBits.m_Size < (int)(entnum + 1) )
      CUtlVector<CEntityBits,CUtlMemory<CEntityBits,int>>::InsertMultipleBefore(
        this: &g_EntityReportMgr.m_EntityBits,
        elem: g_EntityReportMgr.m_EntityBits.m_Size,
        num: entnum + 1 - g_EntityReportMgr.m_EntityBits.m_Size);
    v1 = &g_EntityReportMgr.m_EntityBits.m_Memory.m_pMemory[entnum];
    v1->flags = 2;
    v1->effectfinishtime = realtime + 1.5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084D50
// Name: void CL_RecordDeleteEntity(int,class ClientClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RecordDeleteEntity(unsigned int entnum, ClientClass *pclass)
{
  CEntityBits *v2; // eax

  if ( cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue != 0 && entnum <= 0x7FF )
  {
    if ( g_EntityReportMgr.m_EntityBits.m_Size < (int)(entnum + 1) )
      CUtlVector<CEntityBits,CUtlMemory<CEntityBits,int>>::InsertMultipleBefore(
        this: &g_EntityReportMgr.m_EntityBits,
        elem: g_EntityReportMgr.m_EntityBits.m_Size,
        num: entnum + 1 - g_EntityReportMgr.m_EntityBits.m_Size);
    v2 = &g_EntityReportMgr.m_EntityBits.m_Memory.m_pMemory[entnum];
    v2->flags = 4;
    v2->effectfinishtime = realtime + 1.5;
    v2->deletedclientclass = pclass;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10284D70
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetParent(vgui::Panel *this)
{
  vgui::IPanel *v1; // esi
  vgui::IPanel_vtbl *v2; // edi
  int v3; // eax
  int v4; // esi
  vgui::IPanel *v5; // edi
  vgui::IPanel_vtbl *v6; // ebx
  const char *ControlsModuleName; // eax

  v1 = g_pVGuiPanel;
  if ( g_pVGuiPanel == nullptr )
    return nullptr;
  v2 = g_pVGuiPanel->__vftable;
  v3 = this->GetVPanel(this);
  v4 = v2->GetParent(this: v1, a2: v3);
  if ( v4 == 0 )
    return nullptr;
  v5 = g_pVGuiPanel;
  v6 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v6->GetPanel(this: v5, a2: v4, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x10285100
// Name: public: class vgui::Panel __near * vgui::Panel::FindSiblingByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindSiblingByName(vgui::Panel *this, const char *siblingName)
{
  vgui::Panel *result; // eax
  vgui::IPanel *v4; // edi
  vgui::IPanel_vtbl *v5; // esi
  unsigned int v6; // eax
  vgui::IPanel *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  int v9; // eax
  int v10; // eax
  vgui::IPanel *v11; // edi
  vgui::IPanel_vtbl *v12; // esi
  const char *ControlsModuleName; // eax
  int v14; // esi
  const char *v15; // eax
  int siblingCount; // [esp+4h] [ebp-Ch]
  unsigned int sibling; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  result = (vgui::Panel *)this->GetVParent(this);
  if ( result != nullptr )
  {
    v4 = g_pVGuiPanel;
    v5 = g_pVGuiPanel->__vftable;
    v6 = this->GetVParent(this);
    siblingCount = v5->GetChildCount(this: v4, a2: v6);
    i = 0;
    if ( siblingCount <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        v7 = g_pVGuiPanel;
        v8 = g_pVGuiPanel->__vftable;
        v9 = ((int (__thiscall *)(vgui::Panel *, int))this->GetVParent)(a1: this, a2: i);
        v10 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetChild)(a1: v7, a2: v9);
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        sibling = v10;
        ControlsModuleName = vgui::GetControlsModuleName();
        v14 = (int)v12->GetPanel(this: v11, a2: sibling, a3: ControlsModuleName);
        v15 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 72))(a1: v14);
        if ( _V_stricmp(s1: v15, s2: siblingName) == 0 )
          break;
        if ( ++i >= siblingCount )
          return nullptr;
      }
      return (vgui::Panel *)v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10285B30
// Name: public: class vgui::Panel __near * vgui::Panel::GetChild(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetChild(vgui::Panel *this, int index)
{
  vgui::IPanel *v2; // edi
  vgui::IPanel *v4; // ebx
  const char *ControlsModuleName; // eax
  int v6; // eax
  int v7; // eax
  vgui::IPanel_vtbl *v9; // [esp+Ch] [ebp-8h]
  vgui::IPanel_vtbl *v10; // [esp+10h] [ebp-4h]

  v2 = g_pVGuiPanel;
  v4 = g_pVGuiPanel;
  v9 = g_pVGuiPanel->__vftable;
  v10 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  v6 = ((int (__thiscall *)(vgui::Panel *, int, const char *))this->GetVPanel)(
         a1: this,
         a2: index,
         a3: ControlsModuleName);
  v7 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v2, a2: v6);
  return ((vgui::Panel *(__thiscall *)(vgui::IPanel *, int))v9->GetPanel)(a1: v4, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10285DF0
// Name: public: virtual class vgui::IBorder __near * vgui::Panel::GetBorder(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Panel::GetBorder(vgui::Panel *this)
{
  return this->_border;
}

//------------------------------------------------------------------------------
// Address: 0x102861B0
// Name: public: enum vgui::Panel::PinCorner_e vgui::Panel::GetPinCorner(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetPinCorner(vgui::Panel *this)
{
  return *((_BYTE *)this + 166) & 0xF;
}

//------------------------------------------------------------------------------
// Address: 0x102861E0
// Name: public: enum vgui::Panel::AutoResize_e vgui::Panel::GetAutoResize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetAutoResize(vgui::Panel *this)
{
  return *((unsigned __int8 *)this + 166) >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x10286670
// Name: public: virtual struct vgui::PanelMap_t __near * vgui::Panel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall vgui::Panel::GetPanelMap(vgui::Panel *this)
{
  return &vgui::Panel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x10287F10
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDropTarget(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDropTarget(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  vgui::Panel *v4; // eax

  if ( this->m_pDragDrop->m_bDropEnabled && this->IsDroppable(this, a2: msglist) )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDropTarget(this: v4, a2: msglist);
}

//------------------------------------------------------------------------------
// Address: 0x10287F80
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDragPanel(vgui::Panel *this)
{
  vgui::DragDrop_t *m_pDragDrop; // eax
  vgui::Panel *v4; // eax

  m_pDragDrop = this->m_pDragDrop;
  if ( m_pDragDrop->m_bPreventChaining )
    return nullptr;
  if ( m_pDragDrop->m_bDragEnabled )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDragPanel(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10288CE0
// Name: public: class vgui::Panel __near * vgui::Panel::FindChildByName(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindChildByName(vgui::Panel *this, const char *childName, bool recurseDown)
{
  vgui::IPanel *v3; // ebx
  vgui::IPanel_vtbl *v4; // esi
  int v5; // eax
  int v6; // eax
  vgui::IPanel_vtbl *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  const char *ControlsModuleName; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  vgui::Panel *v13; // esi
  const char *v14; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v16; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v16 = this;
  for ( i = 0; ; ++i )
  {
    v3 = g_pVGuiPanel;
    if ( g_pVGuiPanel != nullptr )
    {
      v4 = g_pVGuiPanel->__vftable;
      v5 = this->GetVPanel(this);
      v6 = v4->GetChildCount(this: v3, a2: v5);
      v3 = g_pVGuiPanel;
    }
    else
    {
      v6 = 0;
    }
    if ( i >= v6 )
      break;
    v7 = v3->__vftable;
    v8 = v3->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v10 = ((int (__thiscall *)(vgui::Panel *, int, const char *))v16->GetVPanel)(a1: v16, a2: i, a3: ControlsModuleName);
    v11 = ((int (__thiscall *)(vgui::IPanel *, int))v7->GetChild)(a1: v3, a2: v10);
    v12 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetPanel)(a1: v3, a2: v11);
    v13 = (vgui::Panel *)v12;
    if ( v12 != 0 )
    {
      v14 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 72))(a1: v12);
      if ( _V_stricmp(s1: v14, s2: childName) == 0 )
        return v13;
      if ( recurseDown )
      {
        result = vgui::Panel::FindChildByName(this: v13, childName, recurseDown);
        if ( result != nullptr )
          return result;
      }
    }
    this = v16;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10289E30
// Name: public: class vgui::Tooltip __near * vgui::Panel::GetTooltip(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Panel::GetTooltip(vgui::Panel *this)
{
  vgui::Tooltip *v2; // eax
  vgui::Tooltip *result; // eax
  bool v4; // zf

  if ( this->m_pTooltips != nullptr )
    return this->m_pTooltips;
  v2 = (vgui::Tooltip *)MemAlloc_Alloc(nSize: 0x24u);
  if ( v2 != nullptr )
    result = vgui::Tooltip::Tooltip(this: v2, parent: this, text: nullptr);
  else
    result = nullptr;
  v4 = (*((_BYTE *)this + 172) & 8) == 0;
  this->m_pTooltips = result;
  if ( !v4 )
  {
    vgui::Tooltip::SetEnabled(this: result, bState: false);
    return this->m_pTooltips;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028A620
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavUp(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavUp(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavUp; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  unsigned int v11; // edi
  vgui::IPanel *v12; // esi
  vgui::IPanel_vtbl *v13; // ebx
  const char *v14; // eax
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // edi
  vgui::IPanel *v18; // esi
  vgui::IPanel_vtbl *v19; // ebx
  const char *v20; // eax
  unsigned int v21; // eax
  vgui::PHandle *v22; // ebx
  unsigned int v23; // edi
  vgui::IPanel *v24; // esi
  vgui::IPanel_vtbl *v25; // ebx
  const char *v26; // eax
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  const char *v31; // [esp-8h] [ebp-20h]
  vgui::PHandle *v33; // [esp+10h] [ebp-8h]
  vgui::Panel *v34; // [esp+14h] [ebp-4h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavUp.m_iPanelID;
  p_m_NavUp = &this->m_NavUp;
  v33 = &this->m_NavUp;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v34 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v34->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavUp = v33,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavUpName) > 0 )
    {
      v31 = CUtlString::operator char const *(this: &this->m_sNavUpName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v31, recurseDown: true);
      if ( ChildByName != nullptr )
        vgui::PHandle::operator=(this: p_m_NavUp, pPanel: ChildByName);
    }
  }
  if ( p_m_NavUp->m_iPanelID == -1 || (v11 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID)) == 0 )
  {
    v35 = nullptr;
    v16 = 0;
  }
  else
  {
    v12 = g_pVGuiPanel;
    v13 = g_pVGuiPanel->__vftable;
    v14 = vgui::GetControlsModuleName();
    v15 = (int)v13->GetPanel(this: v12, a2: v11, a3: v14);
    p_m_NavUp = v33;
    v16 = v15;
    v35 = (vgui::Panel *)v15;
  }
  if ( p_m_NavUp->m_iPanelID == -1 )
    return (vgui::Panel *)v16;
  v17 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID);
  if ( v17 == 0 )
    return (vgui::Panel *)v16;
  v18 = g_pVGuiPanel;
  v19 = g_pVGuiPanel->__vftable;
  v20 = vgui::GetControlsModuleName();
  if ( v19->GetPanel(this: v18, a2: v17, a3: v20) == nullptr )
    return v35;
  v21 = this->m_NavUp.m_iPanelID;
  v22 = &this->m_NavUp;
  if ( v21 == -1 || (v23 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v21)) == 0 )
  {
    v27 = nullptr;
  }
  else
  {
    v24 = g_pVGuiPanel;
    v25 = g_pVGuiPanel->__vftable;
    v26 = vgui::GetControlsModuleName();
    v27 = v25->GetPanel(this: v24, a2: v23, a3: v26);
    v22 = &this->m_NavUp;
  }
  if ( v27 == first )
    return v35;
  v28 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v22);
  if ( v28->IsVisible(this: v28) )
    return v35;
  v29 = this;
  if ( first != nullptr )
    v29 = first;
  return vgui::Panel::GetNavUp(this: v35, first: v29);
}

//------------------------------------------------------------------------------
// Address: 0x1028A7E0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavDown(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavDown(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavDown; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavDown.m_iPanelID;
  p_m_NavDown = &this->m_NavDown;
  v34 = &this->m_NavDown;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavDown = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavDownName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavDownName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::PHandle::operator=(this: p_m_NavDown, pPanel: v11);
      }
    }
  }
  if ( p_m_NavDown->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavDown = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavDown->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavDown.m_iPanelID;
  v23 = &this->m_NavDown;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavDown;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavDown(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x1028A9B0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavLeft(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavLeft; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavLeft.m_iPanelID;
  p_m_NavLeft = &this->m_NavLeft;
  v34 = &this->m_NavLeft;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavLeft = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavLeftName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavLeftName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::PHandle::operator=(this: p_m_NavLeft, pPanel: v11);
      }
    }
  }
  if ( p_m_NavLeft->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavLeft = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavLeft->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavLeft.m_iPanelID;
  v23 = &this->m_NavLeft;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavLeft;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavLeft(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x1028AB80
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavRight(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavRight; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavRight.m_iPanelID;
  p_m_NavRight = &this->m_NavRight;
  v34 = &this->m_NavRight;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavRight = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavRightName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavRightName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::PHandle::operator=(this: p_m_NavRight, pPanel: v11);
      }
    }
  }
  if ( p_m_NavRight->m_iPanelID == -1
    || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavRight = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavRight->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavRight.m_iPanelID;
  v23 = &this->m_NavRight;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavRight;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavRight(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x1028B300
// Name: public: struct vgui::PanelKeyBindingMap __near * vgui::Panel::LookupMapForBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::LookupMapForBinding(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *v2; // ebx
  int v3; // edi
  int v4; // esi
  int c; // [esp+Ch] [ebp-4h]

  v2 = this->GetKBMap(this);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    v3 = 0;
    c = v2->entries.m_Size;
    if ( c > 0 )
      break;
LABEL_6:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  v4 = 0;
  while ( _V_stricmp(s1: v2->entries.m_Memory.m_pMemory[v4].bindingname, s2: bindingName) != 0 )
  {
    ++v3;
    ++v4;
    if ( v3 >= c )
      goto LABEL_6;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1028B360
// Name: public: struct vgui::KeyBindingMap_t __near * vgui::Panel::LookupBindingByKeyCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingMap_t *__thiscall vgui::Panel::LookupBindingByKeyCode(
        vgui::Panel *this,
        ButtonCode_t code,
        int modifiers)
{
  vgui::Panel *v3; // esi
  vgui::PanelKeyBindingMap *v4; // ebx
  int m_Size; // edi
  vgui::BoundKey_t *v6; // eax
  vgui::PanelKeyBindingMap *v7; // eax
  int v8; // ebx
  int v9; // edi
  const char **p_bindingname; // esi
  int c; // [esp+Ch] [ebp-20h]
  int v14; // [esp+14h] [ebp-18h]
  char *s2; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  vgui::PanelKeyBindingMap *map; // [esp+20h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-8h]
  vgui::PanelKeyBindingMap *baseMap; // [esp+28h] [ebp-4h]

  v3 = this;
  map = (vgui::PanelKeyBindingMap *)((int (__fastcall *)(vgui::Panel *))this->GetKBMap)(a1: this);
  if ( map == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = map;
    m_Size = map->boundkeys.m_Size;
    c = m_Size;
    i = 0;
    if ( m_Size > 0 )
      break;
LABEL_17:
    map = v4->baseMap;
    if ( map == nullptr )
      return nullptr;
  }
  v18 = 0;
  while ( 1 )
  {
    v6 = &v4->boundkeys.m_Memory.m_pMemory[v18];
    if ( v6->keycode == code && v6->modifiers == modifiers )
    {
      s2 = (char *)v6->bindingname;
      v7 = v3->GetKBMap(this: v3);
      baseMap = v7;
      if ( v7 != nullptr )
        break;
    }
LABEL_16:
    ++v18;
    if ( ++i >= m_Size )
      goto LABEL_17;
  }
  while ( 1 )
  {
    v8 = 0;
    v14 = v7->entries.m_Size;
    if ( v14 > 0 )
      break;
LABEL_14:
    baseMap = v7->baseMap;
    if ( baseMap == nullptr )
    {
      m_Size = c;
      v4 = map;
      goto LABEL_16;
    }
    v7 = v7->baseMap;
  }
  v9 = 0;
  while ( 1 )
  {
    p_bindingname = &v7->entries.m_Memory.m_pMemory[v9].bindingname;
    if ( _V_stricmp(s1: *p_bindingname, s2) == 0 )
      return (vgui::KeyBindingMap_t *)p_bindingname;
    v7 = baseMap;
    ++v8;
    ++v9;
    if ( v8 >= v14 )
    {
      v3 = this;
      goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028C760
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateUp(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateUp(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavUp(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_UP;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028C7A0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateDown(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateDown(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavDown(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_DOWN;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028C7E0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateLeft(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateLeft(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavLeft(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_LEFT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028C820
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateRight(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateRight(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavRight(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_RIGHT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10291AF0
// Name: private: class vgui::Panel __near * vgui::Panel::FindDropTargetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindDropTargetPanel(vgui::Panel *this)
{
  unsigned int v1; // ebx
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // esi
  const char *ControlsModuleName; // eax
  unsigned int v5; // ebx
  vgui::IPanel *v6; // edi
  vgui::IPanel_vtbl *v7; // esi
  const char *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // ebx
  int v11; // edi
  int m_Size; // eax
  unsigned int v13; // eax
  unsigned int v14; // esi
  int v15; // eax
  vgui::IPanel *v17; // edi
  vgui::IPanel_vtbl *v18; // esi
  unsigned int *v19; // ebx
  const char *v20; // eax
  int v21; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > hits; // [esp+Ch] [ebp-24h] BYREF
  int nCount; // [esp+20h] [ebp-10h]
  vgui::Panel *v24; // [esp+24h] [ebp-Ch]
  int x; // [esp+28h] [ebp-8h] BYREF
  int y; // [esp+2Ch] [ebp-4h] BYREF

  v24 = this;
  if ( s_DragDropHelper.m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  if ( v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName) == nullptr )
    return nullptr;
  memset(&hits, 0, sizeof(hits));
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  nCount = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  if ( s_DragDropHelper.m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID)) == 0 )
  {
    v9 = nullptr;
  }
  else
  {
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    v8 = vgui::GetControlsModuleName();
    v9 = v7->GetPanel(this: v6, a2: v5, a3: v8);
  }
  v10 = v9->GetVPanel(this: v9);
  if ( g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface)
    && g_pVGuiSurface->IsWithin(this: g_pVGuiSurface, a2: x, a3: y) )
  {
    v11 = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1;
    if ( v11 >= 0 )
    {
      do
      {
        m_Size = hits.m_Size;
        if ( hits.m_Size != 0 )
          goto LABEL_20;
        v13 = g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: v11);
        v14 = v13;
        if ( v13 != nCount && v13 != v10 && g_pVGuiPanel->IsFullyVisible(this: g_pVGuiPanel, a2: v13) )
          vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: v14);
      }
      while ( --v11 >= 0 );
    }
    m_Size = hits.m_Size;
    if ( hits.m_Size != 0 )
      goto LABEL_20;
    vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: nCount);
  }
  m_Size = hits.m_Size;
  if ( hits.m_Size == 0 )
  {
LABEL_21:
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&hits);
    return nullptr;
  }
LABEL_20:
  v15 = m_Size - 1;
  nCount = v15;
  if ( v15 < 0 )
    goto LABEL_21;
  while ( 1 )
  {
    v17 = g_pVGuiPanel;
    v18 = g_pVGuiPanel->__vftable;
    v19 = &hits.m_Memory.m_pMemory[v15];
    v20 = v24->GetModuleName(this: v24);
    v21 = (int)v18->GetPanel(this: v17, a2: *v19, a3: v20);
    if ( v21 != 0 )
      break;
    if ( --nCount < 0 )
    {
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&hits);
      return nullptr;
    }
    v15 = nCount;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&hits);
  return (vgui::Panel *)v21;
}

} // namespace engine_xlsp
