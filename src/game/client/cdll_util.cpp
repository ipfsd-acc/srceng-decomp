// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cdll_util.cpp
// Functions: 28
// ============================================================

#include "game\client\cdll_util.h"

//------------------------------------------------------------------------------
// Address: 0x1009F540
// Name: char __near * VarArgs(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *VarArgs(const char *format, ...)
{
  va_list params; // [esp+Ch] [ebp+Ch] BYREF

  va_start(params, format);
  V_vsnprintf(pDest: string_0, maxLen: 1024, pFormat: format, params);
  return string_0;
}

//------------------------------------------------------------------------------
// Address: 0x1009F570
// Name: bool IsPlayerIndex(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPlayerIndex(int index)
{
  return index >= 1 && index <= *(_DWORD *)(gpGlobals.m_Index + 20);
}

//------------------------------------------------------------------------------
// Address: 0x1009F590
// Name: int GetLocalPlayerIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetLocalPlayerIndex()
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
    return LocalPlayer->entindex(this: &LocalPlayer->IClientNetworkable);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009F5B0
// Name: int GetSpectatorMode(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetSpectatorMode()
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
    return LocalPlayer->GetObserverMode(this: LocalPlayer);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009F5D0
// Name: int GetSpectatorTarget(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetSpectatorTarget()
{
  C_BasePlayer *LocalPlayer; // eax
  int v1; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr && (v1 = (int)LocalPlayer->GetObserverTarget(this: LocalPlayer)) != 0 )
    return (*(int (__thiscall **)(int))(*(_DWORD *)(v1 + 8) + 40))(a1: v1 + 8);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009F600
// Name: int GetLocalPlayerTeam(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetLocalPlayerTeam()
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
    return LocalPlayer->GetTeamNumber(this: LocalPlayer);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009F620
// Name: struct client_textmessage_t __near * TextMessageGet(char const __near *)
// Source: json
//------------------------------------------------------------------------------
client_textmessage_t *__cdecl TextMessageGet(const char *pName)
{
  return engine->TextMessageGet(this: engine, a2: pName);
}

//------------------------------------------------------------------------------
// Address: 0x1009F640
// Name: int ScreenHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ScreenHeight()
{
  int w; // [esp+0h] [ebp-8h] BYREF
  int h; // [esp+4h] [ebp-4h] BYREF

  GetHudSize(&w, &h);
  return h;
}

//------------------------------------------------------------------------------
// Address: 0x1009F660
// Name: int ScreenWidth(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ScreenWidth()
{
  int h; // [esp+0h] [ebp-8h] BYREF
  int w; // [esp+4h] [ebp-4h] BYREF

  GetHudSize(&w, &h);
  return w;
}

//------------------------------------------------------------------------------
// Address: 0x1009F680
// Name: void UTIL_ImpactTrace(class CGameTrace __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ImpactTrace(CGameTrace *pTrace, int iDamageType, char *pCustomImpactName)
{
  struct CBaseEntity *m_pEnt; // ecx
  unsigned __int16 flags; // bx

  m_pEnt = pTrace->m_pEnt;
  if ( m_pEnt != nullptr )
  {
    flags = pTrace->surface.flags;
    if ( (flags & 4) == 0 && pTrace->fraction != 1.0 && (flags & 0x80u) == 0 )
      (*(void (__thiscall **)(struct CBaseEntity *, CGameTrace *, int, char *))(*(_DWORD *)m_pEnt + 520))(
        a1: m_pEnt,
        a2: pTrace,
        a3: iDamageType,
        a4: pCustomImpactName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F6D0
// Name: int UTIL_PrecacheDecal(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_PrecacheDecal(char *name)
{
  return effects->Draw_DecalIndexFromName(this: effects, a2: name);
}

//------------------------------------------------------------------------------
// Address: 0x1009F6F0
// Name: public: class C_BaseEntity __near * CEntitySphereQuery::GetCurrentEntity(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall CEntitySphereQuery::GetCurrentEntity(CEntitySphereQuery *this)
{
  if ( this->m_listIndex >= this->m_listCount )
    return nullptr;
  else
    return this->m_pList[this->m_listIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1009F700
// Name: char const __near * nexttoken(char __near *,char const __near *,char)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl nexttoken(char *token, char *str, char sep)
{
  char *result; // eax
  char v4; // cl
  char *v5; // esi

  result = str;
  if ( str != nullptr && (v4 = *str, *str != 0) )
  {
    v5 = token;
    if ( v4 != sep )
    {
      do
      {
        if ( v4 == 0 )
          break;
        ++result;
        *v5 = v4;
        v4 = *result;
        ++v5;
      }
      while ( *result != sep );
    }
    *v5 = 0;
    if ( *result != 0 )
      ++result;
  }
  else
  {
    *token = 0;
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009F750
// Name: void UTIL_MakeSafeName(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_MakeSafeName(const char *oldName, char *newName, int newNameBufSize)
{
  const char *v3; // edi
  int v4; // eax
  int v5; // esi
  char v6; // dl

  v3 = oldName;
  v4 = 0;
  if ( *oldName != 0 )
  {
    v5 = 2;
    while ( 1 )
    {
      if ( v4 >= newNameBufSize - 1 )
      {
LABEL_15:
        newName[v4] = 0;
        return;
      }
      if ( v3 == oldName && *v3 == 35 )
      {
        newName[v4] = 42;
      }
      else
      {
        v6 = *v3;
        if ( *v3 == 37 )
        {
          newName[v4] = 42;
        }
        else
        {
          if ( v6 == 38 )
          {
            if ( v5 < newNameBufSize )
            {
              *(_WORD *)&newName[v4] = 9766;
              v4 += 2;
              v5 += 2;
            }
            goto LABEL_14;
          }
          newName[v4] = v6;
        }
      }
      ++v4;
      ++v5;
LABEL_14:
      if ( *++v3 == 0 )
        goto LABEL_15;
    }
  }
  *newName = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009F7C0
// Name: char const __near * UTIL_SafeName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl UTIL_SafeName(const char *oldName)
{
  UTIL_MakeSafeName(oldName, newName: safeName, newNameBufSize: 65);
  return safeName;
}

//------------------------------------------------------------------------------
// Address: 0x1009F7E0
// Name: void UTIL_ReplaceKeyBindings(wchar_t const __near *,int,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_ReplaceKeyBindings(char *a1@<esi>, const wchar_t *inbuf, int inbufsizebytes, wchar_t *outbuf)
{
  const wchar_t *v4; // ebx
  int v5; // edi
  wchar_t *v6; // esi
  int v7; // eax
  unsigned __int16 *v8; // eax
  unsigned int v9; // esi
  char *v10; // eax
  const char *v11; // eax
  __int16 *v12; // eax
  char *v13; // ecx
  __int16 v14; // dx
  unsigned int v15; // edx
  wchar_t *v16; // edi
  wchar_t v17; // cx
  _WORD *v18; // edx
  __int16 v19; // cx
  wchar_t token[64]; // [esp+8h] [ebp-108h] BYREF
  char friendlyName[64]; // [esp+88h] [ebp-88h] BYREF
  char binding[68]; // [esp+C8h] [ebp-48h] BYREF
  const wchar_t *inbufend; // [esp+10Ch] [ebp-4h]
  int pos; // [esp+118h] [ebp+8h]

  v4 = inbuf;
  v5 = 0;
  if ( inbuf != nullptr && *inbuf != 0 )
  {
    v6 = outbuf;
    *outbuf = 0;
    pos = 0;
    inbufend = nullptr;
    if ( inbufsizebytes > 0 )
      inbufend = &v4[inbufsizebytes / 2];
    for ( ; v4 != inbufend; ++v4 )
    {
      v7 = *v4;
      if ( (_WORD)v7 == 0 )
        break;
      if ( v7 == 37 )
      {
        v8 = wcschr(string: ++v4, ch: 0x25u);
        if ( v8 != nullptr && v8 != v4 )
        {
          v9 = v8 - v4;
          wcsncpy(dest: token, source: v4, count: v9);
          token[v9] = 0;
          v4 += v9;
          ((void (__thiscall *)(vgui::ILocalize *, wchar_t *, char *, int, char *))g_pVGuiLocalize->ConvertUnicodeToANSI)(
            a1: g_pVGuiLocalize,
            a2: token,
            a3: binding,
            a4: 64,
            a5: a1);
          v10 = &binding[1];
          if ( binding[0] != 43 )
            v10 = binding;
          v11 = engine->Key_LookupBindingEx(this: engine, a2: v10, a3: 0, a4: 0, a5: -1);
          if ( v11 == nullptr )
            v11 = "< not bound >";
          V_snprintf(pDest: friendlyName, maxLen: 64, pFormat: "%s", v11);
          _V_strupr(start: friendlyName);
          a1 = friendlyName;
          v12 = (__int16 *)((int (__thiscall *)(vgui::ILocalize *))g_pVGuiLocalize->Find)(a1: g_pVGuiLocalize);
          if ( v12 != nullptr && wcslen((const unsigned __int16 *)v12) != 0 )
          {
            outbuf[v5] = 0;
            v13 = (char *)v12;
            do
            {
              v14 = *(_WORD *)v13;
              v13 += 2;
            }
            while ( v14 != 0 );
            v15 = v13 - (char *)v12;
            v16 = outbuf - 1;
            do
            {
              v17 = v16[1];
              ++v16;
            }
            while ( v17 != 0 );
            qmemcpy(v16, v12, v15);
            v18 = v12 + 1;
            do
              v19 = *v12++;
            while ( v19 != 0 );
            v6 = outbuf;
            pos += v12 - v18;
            v5 = pos;
          }
          else
          {
            g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: friendlyName, a3: token, a4: 128);
            outbuf[v5] = 0;
            wcscat(outbuf, token);
            v6 = outbuf;
            pos += wcslen(token);
            v5 = pos;
          }
          continue;
        }
        v6[v5] = *v4;
      }
      else
      {
        v6[v5] = v7;
      }
      pos = ++v5;
    }
    v6[v5] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FA30
// Name: unsigned char __near * UTIL_LoadFileForMe(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall UTIL_LoadFileForMe@<eax>(int a1@<edi>, const char *filename, int *pLength)
{
  void *v3; // esi
  int v5; // edi
  _BYTE *v6; // ebx

  v3 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: filename, a3: "rb", a4: "GAME");
  if ( v3 != nullptr )
  {
    v5 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))filesystem->Size_2)(
           a1: &filesystem->IBaseFileSystem,
           a2: v3,
           a3: a1);
    v6 = MemAlloc_Alloc(nSize: v5 + 1);
    if ( v6 != nullptr )
    {
      ((void (__thiscall *)(IBaseFileSystem *, _BYTE *, int))filesystem->Read)(
        a1: &filesystem->IBaseFileSystem,
        a2: v6,
        a3: v5);
      filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v3);
      v6[v5] = 0;
      if ( pLength != nullptr )
        *pLength = v5;
      return v6;
    }
    else
    {
      _Warning(a1: "UTIL_LoadFileForMe:  Couldn't allocate buffer of size %i for file %s\n", v5 + 1, filename);
      filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v3);
      return nullptr;
    }
  }
  else
  {
    if ( pLength != nullptr )
      *pLength = 0;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FB10
// Name: void UTIL_FreeFile(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_FreeFile(unsigned __int8 *buffer)
{
  C_BaseEntity::operator delete(pMem: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x1009FB20
// Name: class C_BasePlayer __near * UTIL_PlayerByUserId(int)
// Source: json
//------------------------------------------------------------------------------
C_BasePlayer *__cdecl UTIL_PlayerByUserId(int userID)
{
  int v1; // edi
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // esi

  v1 = 1;
  if ( *(int *)(gpGlobals.m_Index + 20) < 1 )
    return nullptr;
  while ( 1 )
  {
    v2 = UTIL_PlayerByIndex(entindex: v1);
    v3 = v2;
    if ( v2 != nullptr && C_BasePlayer::GetUserID(this: v2) == userID )
      break;
    if ( ++v1 > *(_DWORD *)(gpGlobals.m_Index + 20) )
      return nullptr;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1009FB70
// Name: void UTIL_ClearTrace(class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ClearTrace(CGameTrace *trace)
{
  const char *name; // eax
  int v2; // ecx

  memset(dst: (int)trace, value: nullptr, count: sizeof(CGameTrace));
  name = g_NullSurface.name;
  v2 = *(_DWORD *)&g_NullSurface.surfaceProps;
  trace->fraction = 1.0;
  trace->fractionleftsolid = 0.0;
  trace->surface.name = name;
  *(_DWORD *)&trace->surface.surfaceProps = v2;
}

//------------------------------------------------------------------------------
// Address: 0x1009FBB0
// Name: bool CanControlSpectatedTarget(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CanControlSpectatedTarget@<al>(int a1@<edi>)
{
  C_BasePlayer *LocalPlayer; // eax
  _DWORD *v2; // esi
  IGameResources *v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // esi
  bool result; // al

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  result = false;
  if ( LocalPlayer != nullptr )
  {
    v2 = (_DWORD *)((int (__thiscall *)(C_BasePlayer *, int))LocalPlayer->GetObserverTarget)(a1: LocalPlayer, a2: a1);
    v3 = GameResources();
    v4 = v3 != nullptr ? (int)&v3[-608] : 0;
    v5 = (*(int (__thiscall **)(_DWORD *))(v2[2] + 40))(a1: v2 + 2);
    if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)(v4 + 2432) + 24))(a1: v4 + 2432, a2: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v2 + 576))(a1: v2) != 0 )
    {
      v6 = (*(int (__thiscall **)(_DWORD *))(*v2 + 332))(a1: v2);
      if ( v6 == GetLocalPlayerTeam() )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009FC40
// Name: void NormalizeAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NormalizeAngles(QAngle *angles)
{
  float x; // xmm0_4
  float v2; // xmm0_4
  float y; // xmm0_4
  float v4; // xmm0_4
  float z; // xmm0_4

  x = angles->x;
  if ( angles->x <= 180.0 )
  {
    if ( x >= -180.0 )
      goto LABEL_6;
    v2 = angles->x + 360.0;
  }
  else
  {
    v2 = x - 360.0;
  }
  angles->x = v2;
LABEL_6:
  y = angles->y;
  if ( y <= 180.0 )
  {
    if ( y >= -180.0 )
      goto LABEL_11;
    v4 = angles->y + 360.0;
  }
  else
  {
    v4 = y - 360.0;
  }
  angles->y = v4;
LABEL_11:
  z = angles->z;
  if ( z <= 180.0 )
  {
    if ( z < -180.0 )
      angles->z = angles->z + 360.0;
  }
  else
  {
    angles->z = z - 360.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FCD0
// Name: void InterpolateAngles(class QAngle const __near &,class QAngle const __near &,class QAngle __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InterpolateAngles(const QAngle *start, const QAngle *end, QAngle *output, float frac)
{
  Quaternion result; // [esp+8h] [ebp-30h] BYREF
  Quaternion src; // [esp+18h] [ebp-20h] BYREF
  Quaternion dest; // [esp+28h] [ebp-10h] BYREF

  AngleQuaternion(angles: start, outQuat: &src);
  AngleQuaternion(angles: end, outQuat: &dest);
  QuaternionSlerp(p: &src, q: &dest, t: frac, qt: &result);
  QuaternionAngles(q: &result, angles: output);
}

//------------------------------------------------------------------------------
// Address: 0x1009FD30
// Name: void UTIL_Smoke(class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_Smoke(const Vector *origin, float scale, float framerate)
{
  CPVSFilter filter; // [esp+18h] [ebp-20h] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin);
  ((void (__stdcall *)(CPVSFilter *, _DWORD, const Vector *, int, _DWORD, int))te->Smoke)(
    a1: &filter,
    a2: 0,
    a3: origin,
    a4: g_sModelIndexSmoke,
    a5: LODWORD(scale),
    a6: (int)framerate);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1009FDA0
// Name: void UTIL_PrecacheOther(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_PrecacheOther(const char *szClassname)
{
  C_BaseEntity *EntityByName; // eax
  C_BaseEntity *v2; // esi

  EntityByName = CreateEntityByName(className: szClassname);
  v2 = EntityByName;
  if ( EntityByName != nullptr )
  {
    EntityByName->Precache(this: EntityByName);
    C_BaseEntity::Remove(this: v2);
  }
  else
  {
    _Warning(a1: "NULL Ent in UTIL_PrecacheOther\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FDE0
// Name: bool GetVectorInScreenSpace(class Vector,int __near &,int __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetVectorInScreenSpace(Vector pos, int *iX, int *iY, Vector *vecOffset)
{
  int v4; // eax
  int *v5; // ecx
  float v6; // xmm2_4
  double v7; // xmm0_8
  __m128i v8; // xmm1
  int *v9; // edx
  Vector screen; // [esp+0h] [ebp-20h] BYREF
  int x; // [esp+Ch] [ebp-14h] BYREF
  int y; // [esp+10h] [ebp-10h] BYREF
  int insetY; // [esp+14h] [ebp-Ch] BYREF
  int insetX; // [esp+18h] [ebp-8h] BYREF
  int screenHeight; // [esp+1Ch] [ebp-4h] BYREF

  if ( vecOffset != nullptr )
  {
    pos.x = vecOffset->x + pos.x;
    pos.y = vecOffset->y + pos.y;
    pos.z = vecOffset->z + pos.z;
  }
  VGui_GetEngineRenderBounds(slot: 0, &x, &y, w: (int *)&vecOffset, h: &screenHeight, &insetX, &insetY);
  v4 = ScreenTransform(point: &pos, &screen);
  v5 = iX;
  v6 = screen.y * -0.5;
  v7 = (double)(int)vecOffset;
  v8 = _mm_cvtsi32_si128(screenHeight);
  *iX = (int)((float)(screen.x * 0.5) * (double)(int)vecOffset);
  v9 = iY;
  *(double *)v8.m128i_i64 = _mm_cvtepi32_pd(v8).m128d_f64[0];
  *iY = (int)(v6 * *(double *)v8.m128i_i64);
  *v5 = (int)(v7 * 0.5 + (double)*v5);
  *v9 = (int)(*(double *)v8.m128i_i64 * 0.5 + (double)*v9);
  *v5 += insetX;
  *v9 += insetY;
  if ( v4 == 0 )
    return 1;
  *v5 = -640;
  *v9 = -640;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009FEF0
// Name: int UTIL_EntitiesInBox(class C_BaseEntity __near * __near *,int,class Vector const __near &,class Vector const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_EntitiesInBox(
        C_BaseEntity **pList,
        int listMax,
        const Vector *mins,
        const Vector *maxs,
        int flagMask,
        int partitionMask)
{
  CFlaggedEntitiesEnum boxEnum; // [esp+0h] [ebp-14h] BYREF

  CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(this: &boxEnum, pList, listMax, flagMask);
  partition->EnumerateElementsInBox(this: partition, a2: partitionMask, a3: mins, a4: maxs, a5: false, a6: &boxEnum);
  return boxEnum.m_count;
}

//------------------------------------------------------------------------------
// Address: 0x1009FF30
// Name: public: CEntitySphereQuery::CEntitySphereQuery(class Vector const __near &,float,int,int)
// Source: json
//------------------------------------------------------------------------------
CEntitySphereQuery *__thiscall CEntitySphereQuery::CEntitySphereQuery(
        CEntitySphereQuery *this,
        const Vector *center,
        float radius,
        int flagMask,
        int partitionMask)
{
  CFlaggedEntitiesEnum v7; // [esp+10h] [ebp-14h] BYREF

  this->m_listIndex = 0;
  CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(this: &v7, pList: this->m_pList, listMax: 256, flagMask);
  ((void (__stdcall *)(int, const Vector *, _DWORD, _DWORD, CFlaggedEntitiesEnum *))partition->EnumerateElementsInSphere)(
    a1: partitionMask,
    a2: center,
    a3: LODWORD(radius),
    a4: 0,
    a5: &v7);
  this->m_listCount = v7.m_count;
  return this;
}
