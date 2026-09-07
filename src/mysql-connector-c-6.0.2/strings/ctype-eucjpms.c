// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-eucjpms.c
// Functions: 17
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00435540
// Name: my_mb_wc_jisx0201
// Source: json
//------------------------------------------------------------------------------
int __fastcall my_mb_wc_jisx0201(_BYTE *a1, _DWORD *a2)
{
  int v2; // eax

  v2 = (unsigned __int16)tab_jisx0201_uni[(unsigned __int8)*a1];
  *a2 = v2;
  if ( v2 != 0 || *a1 == 0 )
    return 1;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00435560
// Name: my_wc_mb_jisx0201
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall my_wc_mb_jisx0201@<eax>(int wc@<eax>, _BYTE *a2@<ecx>)
{
  if ( wc > 125 )
  {
    if ( (unsigned int)(wc - 65377) > 0x3E )
    {
      return false;
    }
    else
    {
      *a2 = wc + 64;
      return true;
    }
  }
  else
  {
    *a2 = wc;
    return wc != 92;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435590
// Name: my_jisx0208_uni_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall my_jisx0208_uni_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 8481) <= 0x5D )
    return *((unsigned __int16 *)&loc_4E4166 + a1);
  if ( (unsigned int)(a1 - 8737) <= 0x5D )
    return *((unsigned __int16 *)&loc_4E402E + a1);
  if ( (unsigned int)(a1 - 9008) <= 0x4A )
    return (unsigned __int16)word_4E3ED0[a1];
  if ( (unsigned int)(a1 - 9249) <= 0x52 )
    return (unsigned __int16)word_4E3D86[a1];
  if ( (unsigned int)(a1 - 9505) <= 0x55 )
    return *((unsigned __int16 *)&loc_4E3C2E + a1);
  if ( (unsigned int)(a1 - 9761) <= 0x37 )
    return (unsigned __int16)word_4E3B06[a1];
  if ( (unsigned int)(a1 - 10017) <= 0x50 )
    return (unsigned __int16)word_4E3976[a1];
  if ( (unsigned int)(a1 - 10273) <= 0x1F )
    return (unsigned __int16)word_4E381E[a1];
  if ( (unsigned int)(a1 - 12321) <= 0x5D )
    return *((unsigned __int16 *)&loc_4E285E + a1);
  if ( (unsigned int)(a1 - 12577) <= 0x5D )
    return *((unsigned __int16 *)&loc_4E271E + a1);
  if ( (unsigned int)(a1 - 12833) <= 0x5D )
    return (unsigned __int16)word_4E25DE[a1];
  if ( (unsigned int)(a1 - 13089) <= 0x5D )
    return (unsigned __int16)word_4E249E[a1];
  if ( (unsigned int)(a1 - 13345) <= 0x5D )
    return *((unsigned __int16 *)&loc_4E235E + a1);
  if ( (unsigned int)(a1 - 13601) <= 0x5D )
    return *((unsigned __int16 *)&loc_4E224E + a1);
  if ( (unsigned int)(a1 - 13857) <= 0x5D )
    return (unsigned __int16)word_4E2116[a1];
  if ( (unsigned int)(a1 - 14113) <= 0x5D )
    return (unsigned __int16)word_4E1FD6[a1];
  if ( (unsigned int)(a1 - 14369) <= 0x5D )
    return *((unsigned __int16 *)&sub_4E1E96 + a1);
  if ( (unsigned int)(a1 - 14625) <= 0x5D )
    return *(unsigned __int16 *)((char *)&loc_4E1D53 + 2 * a1 + 3);
  if ( (unsigned int)(a1 - 14881) <= 0x5D )
    return (unsigned __int16)word_4E1C16[a1];
  if ( (unsigned int)(a1 - 15137) <= 0x5D )
    return (unsigned __int16)word_4E1ADE[a1];
  if ( (unsigned int)(a1 - 15393) <= 0x5D )
    return (unsigned __int16)word_4E19D6[a1];
  if ( (unsigned int)(a1 - 15649) <= 0x5D )
    return *(unsigned __int16 *)((char *)&loc_4E189D + 2 * a1 + 1);
  if ( (unsigned int)(a1 - 15905) <= 0x5D )
    return (unsigned __int16)word_4E175E[a1];
  if ( (unsigned int)(a1 - 16161) <= 0x5D )
    return (unsigned __int16)word_4E161E[a1];
  if ( (unsigned int)(a1 - 16417) <= 0x5D )
    return (unsigned __int16)word_4E14F6[a1];
  if ( (unsigned int)(a1 - 16673) <= 0x5D )
    return *((unsigned __int16 *)&loc_4E13CE + a1);
  if ( (unsigned int)(a1 - 16929) <= 0x5D )
    return (unsigned __int16)word_4E12A6[a1];
  if ( (unsigned int)(a1 - 17185) <= 0x5D )
    return (unsigned __int16)word_4E117E[a1];
  if ( (unsigned int)(a1 - 17441) <= 0x5D )
    return (unsigned __int16)word_4E1066[a1];
  if ( (unsigned int)(a1 - 17697) <= 0x5D )
    return *((unsigned __int16 *)&loc_4E0F3E + a1);
  if ( (unsigned int)(a1 - 17953) <= 0x5D )
    return *(unsigned __int16 *)((char *)&loc_4E0E15 + 2 * a1 + 1);
  if ( (unsigned int)(a1 - 18209) <= 0x5D )
    return (unsigned __int16)word_4E0CFE[a1];
  if ( (unsigned int)(a1 - 18465) <= 0x5D )
    return (unsigned __int16)word_4E0BBE[a1];
  if ( (unsigned int)(a1 - 18721) <= 0x5D )
    return *((unsigned __int16 *)&sub_4E0A7E + a1);
  if ( (unsigned int)(a1 - 18977) <= 0x5D )
    return *((unsigned __int16 *)&loc_4E093E + a1);
  if ( (unsigned int)(a1 - 19233) <= 0x5D )
    return (unsigned __int16)word_4E07FE[a1];
  if ( (unsigned int)(a1 - 19489) <= 0x5D )
    return (unsigned __int16)word_4E06BE[a1];
  if ( (unsigned int)(a1 - 19745) <= 0x5D )
    return *(unsigned __int16 *)((char *)&loc_4E057D + 2 * a1 + 1);
  if ( (unsigned int)(a1 - 20001) <= 0x5D )
    return *((unsigned __int16 *)&loc_4E043E + a1);
  if ( (unsigned int)(a1 - 20257) <= 0x32 )
    return (unsigned __int16)word_4E02FE[a1];
  if ( (unsigned int)(a1 - 20513) <= 0x5D )
    return (unsigned __int16)word_4E0166[a1];
  if ( (unsigned int)(a1 - 20769) <= 0x5D )
    return *((unsigned __int16 *)&loc_4E0026 + a1);
  if ( (unsigned int)(a1 - 21025) <= 0x5D )
    return *((unsigned __int16 *)&loc_4DFEE6 + a1);
  if ( (unsigned int)(a1 - 21281) <= 0x5D )
    return (unsigned __int16)word_4DFDA6[a1];
  if ( (unsigned int)(a1 - 21537) <= 0x5D )
    return *((unsigned __int16 *)&loc_4DFC66 + a1);
  if ( (unsigned int)(a1 - 21793) <= 0x5D )
    return *((unsigned __int16 *)&sub_4DFB26 + a1);
  if ( (unsigned int)(a1 - 22049) <= 0x5D )
    return *((unsigned __int16 *)&loc_4DF9E6 + a1);
  if ( (unsigned int)(a1 - 22305) <= 0x5D )
    return (unsigned __int16)word_4DF8A6[a1];
  if ( (unsigned int)(a1 - 22561) <= 0x5D )
    return (unsigned __int16)word_4DF766[a1];
  if ( (unsigned int)(a1 - 22817) <= 0x5D )
    return (unsigned __int16)word_4DF626[a1];
  if ( (unsigned int)(a1 - 23073) <= 0x5D )
    return *((unsigned __int16 *)&loc_4DF4E6 + a1);
  if ( (unsigned int)(a1 - 23329) <= 0x5D )
    return (unsigned __int16)word_4DF3A6[a1];
  if ( (unsigned int)(a1 - 23585) <= 0x5D )
    return (unsigned __int16)word_4DF266[a1];
  if ( (unsigned int)(a1 - 23841) <= 0x5D )
    return (unsigned __int16)word_4DF126[a1];
  if ( (unsigned int)(a1 - 24097) <= 0x5D )
    return *((unsigned __int16 *)&loc_4DEFE6 + a1);
  if ( (unsigned int)(a1 - 24353) <= 0x5D )
    return *((unsigned __int16 *)&loc_4DEEA6 + a1);
  if ( (unsigned int)(a1 - 24609) <= 0x5D )
    return (unsigned __int16)word_4DED66[a1];
  if ( (unsigned int)(a1 - 24865) <= 0x5D )
    return (unsigned __int16)word_4DEC26[a1];
  if ( (unsigned int)(a1 - 25121) <= 0x5D )
    return (unsigned __int16)word_4DEAE6[a1];
  if ( (unsigned int)(a1 - 25377) <= 0x5D )
    return *((unsigned __int16 *)&loc_4DE9A6 + a1);
  if ( (unsigned int)(a1 - 25633) <= 0x5D )
    return (unsigned __int16)word_4DE866[a1];
  if ( (unsigned int)(a1 - 25889) <= 0x5D )
    return (unsigned __int16)word_4DE726[a1];
  if ( (unsigned int)(a1 - 26145) <= 0x5D )
    return (unsigned __int16)word_4DE5E6[a1];
  if ( (unsigned int)(a1 - 26401) <= 0x5D )
    return *((unsigned __int16 *)&loc_4DE4A6 + a1);
  if ( (unsigned int)(a1 - 26657) <= 0x5D )
    return (unsigned __int16)word_4DE366[a1];
  if ( (unsigned int)(a1 - 26913) <= 0x5D )
    return (unsigned __int16)word_4DE226[a1];
  if ( (unsigned int)(a1 - 27169) <= 0x5D )
    return (unsigned __int16)word_4DE0E6[a1];
  if ( (unsigned int)(a1 - 27425) <= 0x5D )
    return (unsigned __int16)word_4DDFA6[a1];
  if ( (unsigned int)(a1 - 27681) <= 0x5D )
    return (unsigned __int16)word_4DDE66[a1];
  if ( (unsigned int)(a1 - 27937) <= 0x5D )
    return *((unsigned __int16 *)&loc_4DDD22 + a1 + 2);
  if ( (unsigned int)(a1 - 28193) <= 0x5D )
    return (unsigned __int16)word_4DDBE6[a1];
  if ( (unsigned int)(a1 - 28449) <= 0x5D )
    return (unsigned __int16)word_4DDAA6[a1];
  if ( (unsigned int)(a1 - 28705) <= 0x5D )
    return (unsigned __int16)word_4DD966[a1];
  if ( (unsigned int)(a1 - 28961) <= 0x5D )
    return *((unsigned __int16 *)sub_4DD826 + a1);
  if ( (unsigned int)(a1 - 29217) <= 0x5D )
    return (unsigned __int16)word_4DD6E6[a1];
  if ( (unsigned int)(a1 - 29473) <= 0x5D )
    return *(unsigned __int16 *)((char *)&loc_4DD5A5 + 2 * a1 + 1);
  if ( (unsigned int)(a1 - 29729) > 5 )
    return 0;
  return (unsigned __int16)word_4D9C22[a1];
}

//------------------------------------------------------------------------------
// Address: 0x00435BA0
// Name: my_uni_jisx0208_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall my_uni_jisx0208_onechar@<eax>(int a1@<eax>)
{
  if ( a1 == 92 )
    return (unsigned __int16)tab_uni_jisx02080;
  if ( (unsigned int)(a1 - 162) <= 0x14 )
    return (unsigned __int16)word_4E85D8[a1];
  if ( a1 == 215 )
    return (unsigned __int16)tab_uni_jisx02082;
  if ( a1 == 247 )
    return (unsigned __int16)tab_uni_jisx02083;
  if ( (unsigned int)(a1 - 913) <= 0x38 )
    return (unsigned __int16)word_4EB586[a1];
  if ( (unsigned int)(a1 - 1025) <= 0x50 )
    return (unsigned __int16)word_4EB51E[a1];
  if ( (unsigned int)(a1 - 8208) <= 0x2B )
    return (unsigned __int16)word_4E7DA8[a1];
  if ( a1 == 8451 )
    return (unsigned __int16)tab_uni_jisx02087;
  if ( a1 == 8491 )
    return (unsigned __int16)tab_uni_jisx02088;
  if ( (unsigned int)(a1 - 8592) <= 3 )
    return (unsigned __int16)word_4E7B00[a1];
  if ( (unsigned int)(a1 - 8658) <= 2 )
    return (unsigned __int16)word_4E7A84[a1];
  if ( (unsigned int)(a1 - 8704) <= 0x3D )
    return (unsigned __int16)word_4E7A30[a1];
  if ( (unsigned int)(a1 - 8786) <= 0x19 )
    return (unsigned __int16)word_4E47B8[a1];
  if ( (unsigned int)(a1 - 8834) <= 5 )
    return (unsigned __int16)word_4E4848[a1];
  if ( a1 == 8869 )
    return (unsigned __int16)tab_uni_jisx020814;
  if ( a1 == 8978 )
    return (unsigned __int16)tab_uni_jisx020815;
  if ( (unsigned int)(a1 - 9472) <= 0x4B )
    return (unsigned __int16)word_4E74B0[a1];
  if ( (unsigned int)(a1 - 9632) <= 0x2F )
    return (unsigned __int16)word_4E7408[a1];
  if ( a1 == 9711 )
    return (unsigned __int16)tab_uni_jisx020818;
  if ( (unsigned int)(a1 - 9733) <= 1 )
    return (unsigned __int16)word_4E444A[a1];
  if ( (unsigned int)(a1 - 9792) <= 2 )
    return *((unsigned __int16 *)&off_4E7328 + a1);
  if ( (unsigned int)(a1 - 9834) <= 5 )
    return (unsigned __int16)word_4E4440[a1];
  if ( (unsigned int)(a1 - 12288) <= 0x1C )
    return *(unsigned __int16 *)((char *)&loc_4E31DB + 2 * a1 + 1);
  if ( (unsigned int)(a1 - 12353) <= 0xBD )
    return (unsigned __int16)word_4E5F2E[a1];
  if ( (unsigned int)(a1 - 19968) <= 0x716 )
    return (unsigned __int16)word_4E2530[a1];
  if ( (unsigned int)(a1 - 21806) <= 0x35 )
    return (unsigned __int16)word_4E2504[a1];
  if ( (unsigned int)(a1 - 21883) <= 0x1EF )
    return (unsigned __int16)word_4E24DA[a1];
  if ( (unsigned int)(a1 - 22399) <= 0x31C )
    return (unsigned __int16)word_4E24B2[a1];
  if ( (unsigned int)(a1 - 23228) <= 0x26D )
    return (unsigned __int16)word_4E2478[a1];
  if ( (unsigned int)(a1 - 23883) <= 0xEA8 )
    return (unsigned __int16)word_4E243A[a1];
  if ( (unsigned int)(a1 - 27656) <= 0xEB )
    return (unsigned __int16)word_4E2418[a1];
  if ( (unsigned int)(a1 - 27915) <= 0x6FE )
    return *((unsigned __int16 *)&loc_4E23EA + a1);
  if ( (unsigned int)(a1 - 29730) <= 0x423 )
    return (unsigned __int16)word_4E23BC[a1];
  if ( (unsigned int)(a1 - 30813) <= 0x63F )
    return *((unsigned __int16 *)&loc_4E238A + a1 + 2);
  if ( (unsigned int)(a1 - 32566) <= 0x422 )
    return *(unsigned __int16 *)((char *)&loc_4E225B + 2 * a1 + 1);
  if ( (unsigned int)(a1 - 33651) <= 0x827 )
    return *((unsigned __int16 *)&loc_4E222A + a1);
  if ( (unsigned int)(a1 - 35895) <= 0xDF )
    return (unsigned __int16)word_4E20F2[a1];
  if ( (unsigned int)(a1 - 36196) <= 0x200 )
    return (unsigned __int16)word_4E2058[a1];
  if ( (unsigned int)(a1 - 36763) <= 0x197 )
    return (unsigned __int16)word_4E1FF2[a1];
  if ( (unsigned int)(a1 - 37193) <= 0x170 )
    return (unsigned __int16)word_4E1FC6[a1];
  if ( (unsigned int)(a1 - 37583) <= 0x119 )
    return (unsigned __int16)word_4E1FA2[a1];
  if ( (unsigned int)(a1 - 37891) <= 0x7E )
    return (unsigned __int16)word_4E1F72[a1];
  if ( (unsigned int)(a1 - 38263) <= 0x6E )
    return *(unsigned __int16 *)((char *)&loc_4E1D89 + 2 * a1 + 1);
  if ( (unsigned int)(a1 - 38428) <= 0x258 )
    return *((unsigned __int16 *)&loc_4E1D20 + a1);
  if ( (unsigned int)(a1 - 39080) <= 0x1E )
    return (unsigned __int16)word_4E1CBC[a1];
  if ( (unsigned int)(a1 - 39131) <= 0x7C )
    return (unsigned __int16)word_4E1C9A[a1];
  if ( (unsigned int)(a1 - 39318) <= 0xD5 )
    return (unsigned __int16)word_4E1C24[a1];
  if ( (unsigned int)(a1 - 39592) <= 0xB2 )
    return (unsigned __int16)word_4E1BB0[a1];
  if ( (unsigned int)(a1 - 39791) <= 0x109 )
    return (unsigned __int16)word_4E1B8A[a1];
  if ( (unsigned int)(a1 - 40165) <= 0x118 )
    return (unsigned __int16)word_4E1AB6[a1];
  if ( (unsigned int)(a1 - 40474) <= 4 )
    return (unsigned __int16)word_4D56A0[a1];
  if ( (unsigned int)(a1 - 40565) <= 0x102 )
    return (unsigned __int16)word_4E19CE[a1];
  if ( (unsigned int)(a1 - 40845) <= 0x13 )
    return (unsigned __int16)word_4E19A6[a1];
  if ( (unsigned int)(a1 - 65281) <= 0x5C )
    return *((unsigned __int16 *)&loc_4D5AE6 + a1);
  if ( (unsigned int)(a1 - 65507) > 2 )
    return 0;
  return *((unsigned __int16 *)&loc_4D59DE + a1);
}

//------------------------------------------------------------------------------
// Address: 0x00436030
// Name: my_uni_jisx0212_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall my_uni_jisx0212_onechar@<eax>(int a1@<eax>)
{
  if ( a1 == 126 )
    return (unsigned __int16)tab_uni_jisx02120;
  if ( (unsigned int)(a1 - 161) <= 0xDD )
    return (unsigned __int16)word_4F586E[a1];
  if ( (unsigned int)(a1 - 461) <= 0xF )
    return (unsigned __int16)word_4F57D2[a1];
  if ( a1 == 501 )
    return (unsigned __int16)tab_uni_jisx02123;
  if ( (unsigned int)(a1 - 711) <= 0x16 )
    return (unsigned __int16)word_4F55FE[a1];
  if ( (unsigned int)(a1 - 900) <= 0xC )
    return *((unsigned __int16 *)&tab_uni_jisx020814 + a1);
  if ( (unsigned int)(a1 - 938) <= 0x24 )
    return (unsigned __int16)word_4F546C[a1];
  if ( (unsigned int)(a1 - 1026) <= 0xD )
    return (unsigned __int16)word_4E8DF0[a1];
  if ( (unsigned int)(a1 - 1106) <= 0xD )
    return (unsigned __int16)word_4E8E28[a1];
  if ( (unsigned int)(a1 - 8470) <= 0xC )
    return *((unsigned __int16 *)&sub_4E5578 + a1);
  if ( (unsigned int)(a1 - 19970) <= 0x117 )
    return (unsigned __int16)word_4EC00C[a1];
  if ( (unsigned int)(a1 - 20270) <= 0x238 )
    return (unsigned __int16)word_4EBFE4[a1];
  if ( (unsigned int)(a1 - 20862) <= 0x397 )
    return (unsigned __int16)word_4EBFBC[a1];
  if ( (unsigned int)(a1 - 21802) <= 0x3C )
    return (unsigned __int16)word_4EBF94[a1];
  if ( (unsigned int)(a1 - 21887) <= 0x6B7 )
    return (unsigned __int16)word_4EBF6A[a1];
  if ( (unsigned int)(a1 - 23641) <= 0x292 )
    return (unsigned __int16)word_4EBF26[a1];
  if ( (unsigned int)(a1 - 24322) <= 0x247 )
    return (unsigned __int16)word_4EBEFC[a1];
  if ( (unsigned int)(a1 - 24926) <= 0x132 )
    return (unsigned __int16)word_4EBED4[a1];
  if ( (unsigned int)(a1 - 25254) <= 0x4F5 )
    return (unsigned __int16)word_4EBEAC[a1];
  if ( (unsigned int)(a1 - 26544) <= 0x49 )
    return (unsigned __int16)word_4EBE88[a1];
  if ( (unsigned int)(a1 - 26644) <= 0x103 )
    return *((unsigned __int16 *)&tab_uni_jisx020811.ArgList.dNameBuffer[9] + a1);
  if ( (unsigned int)(a1 - 26929) <= 0x40E )
    return (unsigned __int16)word_4EBE26[a1];
  if ( (unsigned int)(a1 - 27991) <= 0xAD )
    return (unsigned __int16)word_4EBDFA[a1];
  if ( (unsigned int)(a1 - 28190) <= 0xB1 )
    return (unsigned __int16)word_4EBDCC[a1];
  if ( (unsigned int)(a1 - 28395) <= 0x1F9 )
    return (unsigned __int16)word_4EBD9A[a1];
  if ( (unsigned int)(a1 - 28922) <= 0xE2 )
    return (unsigned __int16)word_4EBD74[a1];
  if ( (unsigned int)(a1 - 29176) <= 0xCA6 )
    return (unsigned __int16)word_4EBD40[a1];
  if ( (unsigned int)(a1 - 32571) <= 0x109 )
    return (unsigned __int16)word_4EBC0A[a1];
  if ( (unsigned int)(a1 - 32864) <= 0x2F7 )
    return (unsigned __int16)word_4EBBD8[a1];
  if ( (unsigned int)(a1 - 33648) <= 0xA9 )
    return (unsigned __int16)word_4EBBA8[a1];
  if ( (unsigned int)(a1 - 33839) <= 0x451 )
    return (unsigned __int16)word_4EBB82[a1];
  if ( (unsigned int)(a1 - 34968) <= 0x124 )
    return (unsigned __int16)word_4EBB58[a1];
  if ( (unsigned int)(a1 - 35284) <= 0x1CB )
    return (unsigned __int16)word_4EBB30[a1];
  if ( (unsigned int)(a1 - 35896) <= 0x6C )
    return (unsigned __int16)word_4EBA00[a1];
  if ( (unsigned int)(a1 - 36025) <= 0x62 )
    return (unsigned __int16)word_4EB9DE[a1];
  if ( (unsigned int)(a1 - 36197) <= 0x200 )
    return (unsigned __int16)word_4EB94E[a1];
  if ( (unsigned int)(a1 - 36765) <= 0x4E7 )
    return (unsigned __int16)word_4EB8E6[a1];
  if ( (unsigned int)(a1 - 38264) <= 0x6E )
    return (unsigned __int16)word_4EB700[a1];
  if ( (unsigned int)(a1 - 38429) <= 0x24F )
    return (unsigned __int16)word_4EB696[a1];
  if ( (unsigned int)(a1 - 39083) <= 0x21 )
    return (unsigned __int16)word_4EB61A[a1];
  if ( (unsigned int)(a1 - 39137) <= 0x7F )
    return (unsigned __int16)word_4EB5F6[a1];
  if ( (unsigned int)(a1 - 39323) <= 0xC2 )
    return (unsigned __int16)word_4EB582[a1];
  if ( (unsigned int)(a1 - 39594) <= 0x1D1 )
    return (unsigned __int16)word_4EB4EC[a1];
  if ( (unsigned int)(a1 - 40166) <= 0x137 )
    return (unsigned __int16)word_4EB41C[a1];
  if ( (unsigned int)(a1 - 40570) > 0x12B )
    return 0;
  return (unsigned __int16)word_4EB364[a1];
}

//------------------------------------------------------------------------------
// Address: 0x00436410
// Name: my_jisx0212_uni_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall my_jisx0212_uni_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 8751) <= 0x15 )
    return (unsigned __int16)word_4E541E[a1];
  if ( (unsigned int)(a1 - 8811) <= 6 )
    return (unsigned __int16)word_4FADDA[a1];
  if ( (unsigned int)(a1 - 9825) <= 0x1B )
    return (unsigned __int16)word_4FA5FE[a1];
  if ( (unsigned int)(a1 - 10050) <= 0xC )
    return *((unsigned __int16 *)&sub_4E4AE0 + a1);
  if ( (unsigned int)(a1 - 10098) <= 0xC )
    return *((unsigned __int16 *)&loc_4E4B58 + a1);
  if ( (unsigned int)(a1 - 10529) <= 0x2F )
    return (unsigned __int16)word_4FA0B6[a1];
  if ( (unsigned int)(a1 - 10785) <= 0x56 )
    return (unsigned __int16)word_4F9F16[a1];
  if ( (unsigned int)(a1 - 11041) <= 0x56 )
    return (unsigned __int16)word_4F9DC6[a1];
  if ( (unsigned int)(a1 - 12321) <= 0x5D )
    return (unsigned __int16)word_4F9476[a1];
  if ( (unsigned int)(a1 - 12577) <= 0x5D )
    return (unsigned __int16)word_4F9336[a1];
  if ( (unsigned int)(a1 - 12833) <= 0x5D )
    return (unsigned __int16)word_4F91F6[a1];
  if ( (unsigned int)(a1 - 13089) <= 0x5D )
    return (unsigned __int16)word_4F90B6[a1];
  if ( (unsigned int)(a1 - 13345) <= 0x5D )
    return (unsigned __int16)word_4F8F76[a1];
  if ( (unsigned int)(a1 - 13601) <= 0x5D )
    return (unsigned __int16)word_4F8E36[a1];
  if ( (unsigned int)(a1 - 13857) <= 0x5D )
    return (unsigned __int16)word_4F8CF6[a1];
  if ( (unsigned int)(a1 - 14113) <= 0x5D )
    return (unsigned __int16)word_4F8BB6[a1];
  if ( (unsigned int)(a1 - 14369) <= 0x5D )
    return (unsigned __int16)word_4F8A76[a1];
  if ( (unsigned int)(a1 - 14625) <= 0x5D )
    return (unsigned __int16)word_4F8936[a1];
  if ( (unsigned int)(a1 - 14881) <= 0x5D )
    return (unsigned __int16)word_4F87F6[a1];
  if ( (unsigned int)(a1 - 15137) <= 0x5D )
    return (unsigned __int16)word_4F86B6[a1];
  if ( (unsigned int)(a1 - 15393) <= 0x5D )
    return (unsigned __int16)word_4F8576[a1];
  if ( (unsigned int)(a1 - 15649) <= 0x5D )
    return (unsigned __int16)word_4F8436[a1];
  if ( (unsigned int)(a1 - 15905) <= 0x5D )
    return (unsigned __int16)word_4F82F6[a1];
  if ( (unsigned int)(a1 - 16161) <= 0x5D )
    return (unsigned __int16)word_4F81B6[a1];
  if ( (unsigned int)(a1 - 16417) <= 0x5D )
    return (unsigned __int16)word_4F8076[a1];
  if ( (unsigned int)(a1 - 16673) <= 0x5D )
    return (unsigned __int16)word_4F7F36[a1];
  if ( (unsigned int)(a1 - 16929) <= 0x5D )
    return (unsigned __int16)word_4F7DF6[a1];
  if ( (unsigned int)(a1 - 17185) <= 0x5D )
    return (unsigned __int16)word_4F7CB6[a1];
  if ( (unsigned int)(a1 - 17441) <= 0x5D )
    return (unsigned __int16)word_4F7B76[a1];
  if ( (unsigned int)(a1 - 17697) <= 0x5D )
    return (unsigned __int16)word_4F7A36[a1];
  if ( (unsigned int)(a1 - 17953) <= 0x5D )
    return (unsigned __int16)word_4F78F6[a1];
  if ( (unsigned int)(a1 - 18209) <= 0x5D )
    return (unsigned __int16)word_4F77B6[a1];
  if ( (unsigned int)(a1 - 18465) <= 0x5D )
    return (unsigned __int16)word_4F7676[a1];
  if ( (unsigned int)(a1 - 18721) <= 0x5D )
    return (unsigned __int16)word_4F7536[a1];
  if ( (unsigned int)(a1 - 18977) <= 0x5D )
    return (unsigned __int16)word_4F73F6[a1];
  if ( (unsigned int)(a1 - 19233) <= 0x5D )
    return (unsigned __int16)word_4F72B6[a1];
  if ( (unsigned int)(a1 - 19489) <= 0x5D )
    return (unsigned __int16)word_4F7176[a1];
  if ( (unsigned int)(a1 - 19745) <= 0x5D )
    return (unsigned __int16)word_4F7036[a1];
  if ( (unsigned int)(a1 - 20001) <= 0x5D )
    return (unsigned __int16)word_4F6EF6[a1];
  if ( (unsigned int)(a1 - 20257) <= 0x5D )
    return (unsigned __int16)word_4F6DB6[a1];
  if ( (unsigned int)(a1 - 20513) <= 0x5D )
    return (unsigned __int16)word_4F6C76[a1];
  if ( (unsigned int)(a1 - 20769) <= 0x5D )
    return (unsigned __int16)word_4F6B36[a1];
  if ( (unsigned int)(a1 - 21025) <= 0x5D )
    return (unsigned __int16)word_4F69F6[a1];
  if ( (unsigned int)(a1 - 21281) <= 0x5D )
    return (unsigned __int16)word_4F68B6[a1];
  if ( (unsigned int)(a1 - 21537) <= 0x5D )
    return (unsigned __int16)word_4F6776[a1];
  if ( (unsigned int)(a1 - 21793) <= 0x5D )
    return (unsigned __int16)word_4F6636[a1];
  if ( (unsigned int)(a1 - 22049) <= 0x5D )
    return (unsigned __int16)word_4F64F6[a1];
  if ( (unsigned int)(a1 - 22305) <= 0x5D )
    return (unsigned __int16)word_4F63B6[a1];
  if ( (unsigned int)(a1 - 22561) <= 0x5D )
    return (unsigned __int16)word_4F6276[a1];
  if ( (unsigned int)(a1 - 22817) <= 0x5D )
    return (unsigned __int16)word_4F6136[a1];
  if ( (unsigned int)(a1 - 23073) <= 0x5D )
    return (unsigned __int16)word_4F5FF6[a1];
  if ( (unsigned int)(a1 - 23329) <= 0x5D )
    return (unsigned __int16)word_4F5EB6[a1];
  if ( (unsigned int)(a1 - 23585) <= 0x5D )
    return (unsigned __int16)word_4F5D76[a1];
  if ( (unsigned int)(a1 - 23841) <= 0x5D )
    return (unsigned __int16)word_4F5C36[a1];
  if ( (unsigned int)(a1 - 24097) <= 0x5D )
    return (unsigned __int16)word_4F5AF6[a1];
  if ( (unsigned int)(a1 - 24353) <= 0x5D )
    return (unsigned __int16)word_4F59B6[a1];
  if ( (unsigned int)(a1 - 24609) <= 0x5D )
    return (unsigned __int16)word_4F5876[a1];
  if ( (unsigned int)(a1 - 24865) <= 0x5D )
    return (unsigned __int16)word_4F5736[a1];
  if ( (unsigned int)(a1 - 25121) <= 0x5D )
    return (unsigned __int16)word_4F55F6[a1];
  if ( (unsigned int)(a1 - 25377) <= 0x5D )
    return (unsigned __int16)word_4F54B6[a1];
  if ( (unsigned int)(a1 - 25633) <= 0x5D )
    return (unsigned __int16)word_4F5376[a1];
  if ( (unsigned int)(a1 - 25889) <= 0x5D )
    return (unsigned __int16)word_4F5236[a1];
  if ( (unsigned int)(a1 - 26145) <= 0x5D )
    return (unsigned __int16)word_4F50F6[a1];
  if ( (unsigned int)(a1 - 26401) <= 0x5D )
    return (unsigned __int16)word_4F4FB6[a1];
  if ( (unsigned int)(a1 - 26657) <= 0x5D )
    return (unsigned __int16)word_4F4E76[a1];
  if ( (unsigned int)(a1 - 26913) <= 0x5D )
    return (unsigned __int16)word_4F4D36[a1];
  if ( (unsigned int)(a1 - 27169) <= 0x5D )
    return (unsigned __int16)word_4F4BF6[a1];
  if ( (unsigned int)(a1 - 27425) <= 0x5D )
    return (unsigned __int16)word_4F4AB6[a1];
  if ( (unsigned int)(a1 - 27681) <= 0x5D )
    return (unsigned __int16)word_4F4976[a1];
  if ( (unsigned int)(a1 - 27937) > 0x42 )
    return 0;
  return (unsigned __int16)word_4F4836[a1];
}

//------------------------------------------------------------------------------
// Address: 0x00436A20
// Name: my_mb_wc_euc_jp
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_euc_jp(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // eax

  if ( (unsigned int)a3 >= a4 )
    return -101;
  v5 = *a3;
  if ( v5 <= 0x7F )
  {
    *a2 = v5;
    return 1;
  }
  if ( (unsigned int)(a3 + 2) > a4 )
    return -102;
  v6 = a3[1];
  if ( v5 - 161 <= 0x5D )
  {
    if ( (unsigned int)(v6 - 161) <= 0x5D )
    {
      if ( *a3 >= 0xF5u )
      {
        *a2 = 94 * (v5 - 245) + v6 + 57183;
      }
      else
      {
        v7 = my_jisx0208_uni_onechar(a1: (v5 << 8) + v6 - 32896);
        *a2 = v7;
        if ( v7 == 0 )
          return -2;
      }
      return 2;
    }
    return 0;
  }
  if ( v5 == 142 )
  {
    if ( (unsigned int)(v6 - 161) <= 0x3E )
      return my_mb_wc_jisx0201(a1: a3 + 1, a2) != 1 ? -2 : 2;
    return 0;
  }
  if ( v5 != 143 || (unsigned int)(v6 - 161) > 0x5D )
    return 0;
  if ( (unsigned int)(a3 + 3) > a4 )
    return -103;
  v8 = a3[2];
  if ( (unsigned int)(v8 - 161) > 0x5D )
    return 0;
  if ( a3[1] >= 0xF5u )
  {
    *a2 = 94 * (v6 - 245) + v8 + 58123;
  }
  else
  {
    v9 = my_jisx0212_uni_onechar(a1: (v6 << 8) + v8 - 32896);
    *a2 = v9;
    if ( v9 == 0 )
      return -3;
  }
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x00436B80
// Name: my_wc_mb_euc_jp
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_euc_jp(LIST_ENTRY32 *c, int wc, unsigned __int8 *s, unsigned __int8 *e, ...)
{
  int v5; // eax
  __int16 v6; // ax
  int v7; // eax
  __int16 v8; // ax

  if ( s >= e )
    return -101;
  if ( wc < 128 )
  {
    *s = wc;
    return 1;
  }
  v5 = my_uni_jisx0208_onechar(a1: wc);
  if ( v5 != 0 )
  {
    if ( s + 2 <= e )
    {
      v6 = v5 - 32640;
      s[1] = v6;
      *s = HIBYTE(v6);
      return 2;
    }
    return -102;
  }
  if ( my_wc_mb_jisx0201(wc, a2: s) )
  {
    if ( s + 2 <= e )
    {
      s[1] = *s;
      *s = -114;
      return 2;
    }
    return -102;
  }
  v7 = my_uni_jisx0212_onechar(a1: wc);
  if ( v7 != 0 )
  {
    if ( s + 3 <= e )
    {
      v8 = v7 - 32640;
      s[2] = v8;
      *s = -113;
      s[1] = HIBYTE(v8);
      return 3;
    }
    return -103;
  }
  if ( (unsigned int)wc >= 0xE000 )
  {
    if ( (unsigned int)wc < 0xE3AC )
    {
      if ( s + 2 > e )
        return -102;
      *s = (wc - 57344) / 0x5Eu - 11;
      s[1] = (wc - 57344) % 0x5Eu - 95;
      return 2;
    }
    if ( (unsigned int)wc < 0xE758 )
    {
      if ( s + 3 > e )
        return -103;
      *s = -113;
      s[1] = (wc - 58284) / 0x5Eu - 11;
      s[2] = (wc - 58284) % 0x5Eu - 95;
      return 3;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00438360
// Name: my_mb_wc_jisx0201_0
// Source: json
//------------------------------------------------------------------------------
int __fastcall my_mb_wc_jisx0201_0(_BYTE *a1, _DWORD *a2)
{
  int v2; // eax

  v2 = (unsigned __int16)tab_jisx0201_uni_0[(unsigned __int8)*a1];
  *a2 = v2;
  if ( v2 != 0 || *a1 == 0 )
    return 1;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00438380
// Name: my_jisx0208_uni_onechar_0
// Source: json
//------------------------------------------------------------------------------
int __usercall my_jisx0208_uni_onechar_0@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 8481) <= 0x5D )
    return (unsigned __int16)word_56E6BE[a1];
  if ( (unsigned int)(a1 - 8737) <= 0x5D )
    return (unsigned __int16)word_56E586[a1];
  if ( (unsigned int)(a1 - 9008) <= 0x4A )
    return (unsigned __int16)word_56E428[a1];
  if ( (unsigned int)(a1 - 9249) <= 0x52 )
    return (unsigned __int16)word_56E2DE[a1];
  if ( (unsigned int)(a1 - 9505) <= 0x55 )
    return (unsigned __int16)word_56E186[a1];
  if ( (unsigned int)(a1 - 9761) <= 0x37 )
    return (unsigned __int16)word_56E05E[a1];
  if ( (unsigned int)(a1 - 10017) <= 0x50 )
    return (unsigned __int16)word_56DECE[a1];
  if ( (unsigned int)(a1 - 10273) <= 0x1F )
    return (unsigned __int16)word_56DD76[a1];
  if ( (unsigned int)(a1 - 12321) <= 0x5D )
    return (unsigned __int16)word_56CDB6[a1];
  if ( (unsigned int)(a1 - 12577) <= 0x5D )
    return (unsigned __int16)word_56CC76[a1];
  if ( (unsigned int)(a1 - 12833) <= 0x5D )
    return (unsigned __int16)word_56CB36[a1];
  if ( (unsigned int)(a1 - 13089) <= 0x5D )
    return (unsigned __int16)word_56CA06[a1];
  if ( (unsigned int)(a1 - 13345) <= 0x5D )
    return (unsigned __int16)word_56C8F6[a1];
  if ( (unsigned int)(a1 - 13601) <= 0x5D )
    return (unsigned __int16)word_56C7BE[a1];
  if ( (unsigned int)(a1 - 13857) <= 0x5D )
    return (unsigned __int16)word_56C67E[a1];
  if ( (unsigned int)(a1 - 14113) <= 0x5D )
    return (unsigned __int16)word_56C53E[a1];
  if ( (unsigned int)(a1 - 14369) <= 0x5D )
    return (unsigned __int16)word_56C3FE[a1];
  if ( (unsigned int)(a1 - 14625) <= 0x5D )
    return (unsigned __int16)word_56C2C6[a1];
  if ( (unsigned int)(a1 - 14881) <= 0x5D )
    return (unsigned __int16)word_56C196[a1];
  if ( (unsigned int)(a1 - 15137) <= 0x5D )
    return (unsigned __int16)word_56C066[a1];
  if ( (unsigned int)(a1 - 15393) <= 0x5D )
    return (unsigned __int16)word_56BF2E[a1];
  if ( (unsigned int)(a1 - 15649) <= 0x5D )
    return (unsigned __int16)word_56BDF6[a1];
  if ( (unsigned int)(a1 - 15905) <= 0x5D )
    return (unsigned __int16)word_56BCB6[a1];
  if ( (unsigned int)(a1 - 16161) <= 0x5D )
    return (unsigned __int16)word_56BB8E[a1];
  if ( (unsigned int)(a1 - 16417) <= 0x5D )
    return (unsigned __int16)word_56BA66[a1];
  if ( (unsigned int)(a1 - 16673) <= 0x5D )
    return (unsigned __int16)word_56B93E[a1];
  if ( (unsigned int)(a1 - 16929) <= 0x5D )
    return (unsigned __int16)word_56B7FE[a1];
  if ( (unsigned int)(a1 - 17185) <= 0x5D )
    return (unsigned __int16)word_56B6CE[a1];
  if ( (unsigned int)(a1 - 17441) <= 0x5D )
    return (unsigned __int16)word_56B58E[a1];
  if ( (unsigned int)(a1 - 17697) <= 0x5D )
    return (unsigned __int16)word_56B44E[a1];
  if ( (unsigned int)(a1 - 17953) <= 0x5D )
    return (unsigned __int16)word_56B30E[a1];
  if ( (unsigned int)(a1 - 18209) <= 0x5D )
    return (unsigned __int16)word_56B1F6[a1];
  if ( (unsigned int)(a1 - 18465) <= 0x5D )
    return (unsigned __int16)word_56B0CE[a1];
  if ( (unsigned int)(a1 - 18721) <= 0x5D )
    return (unsigned __int16)word_56AFA6[a1];
  if ( (unsigned int)(a1 - 18977) <= 0x5D )
    return (unsigned __int16)word_56AE7E[a1];
  if ( (unsigned int)(a1 - 19233) <= 0x5D )
    return (unsigned __int16)word_56AD66[a1];
  if ( (unsigned int)(a1 - 19489) <= 0x5D )
    return (unsigned __int16)word_56AC26[a1];
  if ( (unsigned int)(a1 - 19745) <= 0x5D )
    return (unsigned __int16)word_56AAE6[a1];
  if ( (unsigned int)(a1 - 20001) <= 0x5D )
    return (unsigned __int16)word_56A9A6[a1];
  if ( (unsigned int)(a1 - 20257) <= 0x32 )
    return (unsigned __int16)word_56A866[a1];
  if ( (unsigned int)(a1 - 20513) <= 0x5D )
    return (unsigned __int16)word_56A6CE[a1];
  if ( (unsigned int)(a1 - 20769) <= 0x5D )
    return (unsigned __int16)word_56A58E[a1];
  if ( (unsigned int)(a1 - 21025) <= 0x5D )
    return (unsigned __int16)word_56A44E[a1];
  if ( (unsigned int)(a1 - 21281) <= 0x5D )
    return (unsigned __int16)word_56A30E[a1];
  if ( (unsigned int)(a1 - 21537) <= 0x5D )
    return (unsigned __int16)word_56A1CE[a1];
  if ( (unsigned int)(a1 - 21793) <= 0x5D )
    return (unsigned __int16)word_56A08E[a1];
  if ( (unsigned int)(a1 - 22049) <= 0x5D )
    return (unsigned __int16)word_569F4E[a1];
  if ( (unsigned int)(a1 - 22305) <= 0x5D )
    return (unsigned __int16)word_569E0E[a1];
  if ( (unsigned int)(a1 - 22561) <= 0x5D )
    return (unsigned __int16)word_569CCE[a1];
  if ( (unsigned int)(a1 - 22817) <= 0x5D )
    return (unsigned __int16)word_569B8E[a1];
  if ( (unsigned int)(a1 - 23073) <= 0x5D )
    return (unsigned __int16)word_569A4E[a1];
  if ( (unsigned int)(a1 - 23329) <= 0x5D )
    return (unsigned __int16)word_56990E[a1];
  if ( (unsigned int)(a1 - 23585) <= 0x5D )
    return (unsigned __int16)word_5697CE[a1];
  if ( (unsigned int)(a1 - 23841) <= 0x5D )
    return (unsigned __int16)word_56968E[a1];
  if ( (unsigned int)(a1 - 24097) <= 0x5D )
    return (unsigned __int16)word_56954E[a1];
  if ( (unsigned int)(a1 - 24353) <= 0x5D )
    return (unsigned __int16)word_56940E[a1];
  if ( (unsigned int)(a1 - 24609) <= 0x5D )
    return (unsigned __int16)word_5692CE[a1];
  if ( (unsigned int)(a1 - 24865) <= 0x5D )
    return (unsigned __int16)word_56918E[a1];
  if ( (unsigned int)(a1 - 25121) <= 0x5D )
    return (unsigned __int16)word_56904E[a1];
  if ( (unsigned int)(a1 - 25377) <= 0x5D )
    return (unsigned __int16)word_568F0E[a1];
  if ( (unsigned int)(a1 - 25633) <= 0x5D )
    return (unsigned __int16)word_568DCE[a1];
  if ( (unsigned int)(a1 - 25889) <= 0x5D )
    return (unsigned __int16)word_568C8E[a1];
  if ( (unsigned int)(a1 - 26145) <= 0x5D )
    return (unsigned __int16)word_568B4E[a1];
  if ( (unsigned int)(a1 - 26401) <= 0x5D )
    return (unsigned __int16)word_568A0E[a1];
  if ( (unsigned int)(a1 - 26657) <= 0x5D )
    return (unsigned __int16)word_5688CE[a1];
  if ( (unsigned int)(a1 - 26913) <= 0x5D )
    return (unsigned __int16)word_56878E[a1];
  if ( (unsigned int)(a1 - 27169) <= 0x5D )
    return (unsigned __int16)word_56864E[a1];
  if ( (unsigned int)(a1 - 27425) <= 0x5D )
    return (unsigned __int16)word_56850E[a1];
  if ( (unsigned int)(a1 - 27681) <= 0x5D )
    return (unsigned __int16)word_5683CE[a1];
  if ( (unsigned int)(a1 - 27937) <= 0x5D )
    return (unsigned __int16)word_56828E[a1];
  if ( (unsigned int)(a1 - 28193) <= 0x5D )
    return (unsigned __int16)word_56814E[a1];
  if ( (unsigned int)(a1 - 28449) <= 0x5D )
    return (unsigned __int16)word_56800E[a1];
  if ( (unsigned int)(a1 - 28705) <= 0x5D )
    return (unsigned __int16)word_567ECE[a1];
  if ( (unsigned int)(a1 - 28961) <= 0x5D )
    return (unsigned __int16)word_567D8E[a1];
  if ( (unsigned int)(a1 - 29217) <= 0x5D )
    return (unsigned __int16)word_567C4E[a1];
  if ( (unsigned int)(a1 - 29473) <= 0x5D )
    return (unsigned __int16)word_567B0E[a1];
  if ( (unsigned int)(a1 - 29729) <= 5 )
    return (unsigned __int16)word_56417A[a1];
  if ( (unsigned int)(a1 - 11553) > 0x5B )
    return 0;
  return (unsigned __int16)word_5707CE[a1];
}

//------------------------------------------------------------------------------
// Address: 0x004389A0
// Name: my_uni_jisx0208_onechar_0
// Source: json
//------------------------------------------------------------------------------
int __usercall my_uni_jisx0208_onechar_0@<eax>(int a1@<eax>)
{
  if ( a1 == 92 )
    return (unsigned __int16)tab_uni_jisx02080_0;
  if ( (unsigned int)(a1 - 162) <= 0x14 )
    return (unsigned __int16)word_572B30[a1];
  if ( a1 == 215 )
    return (unsigned __int16)tab_uni_jisx02082_0;
  if ( a1 == 247 )
    return (unsigned __int16)tab_uni_jisx02083_0;
  if ( (unsigned int)(a1 - 913) <= 0x38 )
    return (unsigned __int16)word_575BA6[a1];
  if ( (unsigned int)(a1 - 1025) <= 0x50 )
    return (unsigned __int16)word_575B3E[a1];
  if ( (unsigned int)(a1 - 8208) <= 0x2B )
    return (unsigned __int16)word_5723C8[a1];
  if ( (unsigned int)(a1 - 8448) <= 0x16 )
    return *((unsigned __int16 *)&off_572240 + a1);
  if ( (unsigned int)(a1 - 8480) <= 0xB )
    return *((unsigned __int16 *)&off_572230 + a1);
  if ( (unsigned int)(a1 - 8544) <= 9 )
    return (unsigned __int16)word_56ED74[a1];
  if ( (unsigned int)(a1 - 8592) <= 3 )
    return (unsigned __int16)word_572168[a1];
  if ( (unsigned int)(a1 - 8658) <= 2 )
    return (unsigned __int16)word_5720EC[a1];
  if ( (unsigned int)(a1 - 8704) <= 0x3D )
    return (unsigned __int16)word_572098[a1];
  if ( (unsigned int)(a1 - 8786) <= 0x19 )
    return (unsigned __int16)word_56EC60[a1];
  if ( (unsigned int)(a1 - 8834) <= 5 )
    return (unsigned __int16)word_56ECF0[a1];
  if ( (unsigned int)(a1 - 8864) <= 0x1F )
    return (unsigned __int16)word_571FD8[a1];
  if ( a1 == 8978 )
    return (unsigned __int16)tab_uni_jisx020816_0;
  if ( (unsigned int)(a1 - 9312) <= 0x13 )
    return (unsigned __int16)word_571C98[a1];
  if ( (unsigned int)(a1 - 9472) <= 0x4B )
    return (unsigned __int16)word_571B80[a1];
  if ( (unsigned int)(a1 - 9632) <= 0x2F )
    return (unsigned __int16)word_571AD8[a1];
  if ( a1 == 9711 )
    return (unsigned __int16)tab_uni_jisx020820_0;
  if ( (unsigned int)(a1 - 9733) <= 1 )
    return (unsigned __int16)word_56E832[a1];
  if ( (unsigned int)(a1 - 9792) <= 2 )
    return (unsigned __int16)word_5719F8[a1];
  if ( (unsigned int)(a1 - 9834) <= 5 )
    return (unsigned __int16)word_56E828[a1];
  if ( (unsigned int)(a1 - 12288) <= 0x1F )
    return (unsigned __int16)word_570680[a1];
  if ( (unsigned int)(a1 - 12353) <= 0xBD )
    return (unsigned __int16)word_57063E[a1];
  if ( (unsigned int)(a1 - 12848) <= 9 )
    return (unsigned __int16)word_56D164[a1];
  if ( (unsigned int)(a1 - 12960) <= 8 )
    return (unsigned __int16)word_56D154[a1];
  if ( (unsigned int)(a1 - 13056) <= 0xCD )
    return (unsigned __int16)word_570240[a1];
  if ( (unsigned int)(a1 - 19968) <= 0x716 )
    return (unsigned __int16)word_56CDE0[a1];
  if ( (unsigned int)(a1 - 21806) <= 0x35 )
    return (unsigned __int16)word_56CDB4[a1];
  if ( (unsigned int)(a1 - 21883) <= 0x1EF )
    return (unsigned __int16)word_56CD8A[a1];
  if ( (unsigned int)(a1 - 22399) <= 0x31C )
    return (unsigned __int16)word_56CD62[a1];
  if ( (unsigned int)(a1 - 23228) <= 0x26D )
    return (unsigned __int16)word_56CD28[a1];
  if ( (unsigned int)(a1 - 23883) <= 0xEA8 )
    return (unsigned __int16)word_56CCEA[a1];
  if ( (unsigned int)(a1 - 27656) <= 0xEB )
    return (unsigned __int16)word_56CCC8[a1];
  if ( (unsigned int)(a1 - 27915) <= 0x6FE )
    return (unsigned __int16)word_56CC9A[a1];
  if ( (unsigned int)(a1 - 29730) <= 0x423 )
    return (unsigned __int16)word_56CC6C[a1];
  if ( (unsigned int)(a1 - 30813) <= 0x63F )
    return (unsigned __int16)word_56CC3E[a1];
  if ( (unsigned int)(a1 - 32566) <= 0x422 )
    return (unsigned __int16)word_56CB0C[a1];
  if ( (unsigned int)(a1 - 33651) <= 0x827 )
    return (unsigned __int16)word_56CADA[a1];
  if ( (unsigned int)(a1 - 35895) <= 0xDF )
    return (unsigned __int16)word_56C9A2[a1];
  if ( (unsigned int)(a1 - 36196) <= 0x200 )
    return (unsigned __int16)word_56C908[a1];
  if ( (unsigned int)(a1 - 36763) <= 0x197 )
    return (unsigned __int16)word_56C8A2[a1];
  if ( (unsigned int)(a1 - 37193) <= 0x170 )
    return (unsigned __int16)word_56C876[a1];
  if ( (unsigned int)(a1 - 37583) <= 0x119 )
    return (unsigned __int16)word_56C852[a1];
  if ( (unsigned int)(a1 - 37891) <= 0x7E )
    return (unsigned __int16)word_56C822[a1];
  if ( (unsigned int)(a1 - 38263) <= 0x6E )
    return (unsigned __int16)word_56C63A[a1];
  if ( (unsigned int)(a1 - 38428) <= 0x258 )
    return (unsigned __int16)word_56C5D0[a1];
  if ( (unsigned int)(a1 - 39080) <= 0x1E )
    return (unsigned __int16)word_56C56C[a1];
  if ( (unsigned int)(a1 - 39131) <= 0x7C )
    return (unsigned __int16)word_56C54A[a1];
  if ( (unsigned int)(a1 - 39318) <= 0xD5 )
    return (unsigned __int16)word_56C4D4[a1];
  if ( (unsigned int)(a1 - 39592) <= 0xB2 )
    return (unsigned __int16)word_56C460[a1];
  if ( (unsigned int)(a1 - 39791) <= 0x109 )
    return (unsigned __int16)word_56C43A[a1];
  if ( (unsigned int)(a1 - 40165) <= 0x118 )
    return (unsigned __int16)word_56C366[a1];
  if ( (unsigned int)(a1 - 40474) <= 4 )
    return (unsigned __int16)word_55FB30[a1];
  if ( (unsigned int)(a1 - 40565) <= 0x102 )
    return (unsigned __int16)word_56C27E[a1];
  if ( (unsigned int)(a1 - 40845) <= 0x13 )
    return (unsigned __int16)word_56C256[a1];
  if ( (unsigned int)(a1 - 65281) <= 0x5D )
    return (unsigned __int16)word_560396[a1];
  if ( (unsigned int)(a1 - 65504) > 5 )
    return 0;
  return (unsigned __int16)word_55386C[a1];
}

//------------------------------------------------------------------------------
// Address: 0x00438EA0
// Name: my_uni_jisx0212_onechar_0
// Source: json
//------------------------------------------------------------------------------
int __usercall my_uni_jisx0212_onechar_0@<eax>(int a1@<eax>)
{
  if ( a1 == 126 )
    return (unsigned __int16)tab_uni_jisx02120_0;
  if ( (unsigned int)(a1 - 161) <= 0xDD )
    return (unsigned __int16)word_580116[a1];
  if ( (unsigned int)(a1 - 461) <= 0xF )
    return (unsigned __int16)word_58007A[a1];
  if ( a1 == 501 )
    return (unsigned __int16)tab_uni_jisx02123_0;
  if ( (unsigned int)(a1 - 711) <= 0x16 )
    return (unsigned __int16)word_57FEA6[a1];
  if ( (unsigned int)(a1 - 900) <= 0xC )
    return (unsigned __int16)word_5732AC[a1];
  if ( (unsigned int)(a1 - 938) <= 0x24 )
    return (unsigned __int16)word_57FD14[a1];
  if ( (unsigned int)(a1 - 1026) <= 0xD )
    return (unsigned __int16)word_573288[a1];
  if ( (unsigned int)(a1 - 1106) <= 0xD )
    return *((unsigned __int16 *)&tab_jisx0208_uni14_0 + a1);
  if ( a1 == 8482 )
    return (unsigned __int16)tab_uni_jisx02129_0;
  if ( (unsigned int)(a1 - 8560) <= 9 )
    return (unsigned __int16)word_56FA1C[a1];
  if ( (unsigned int)(a1 - 19970) <= 0x117 )
    return (unsigned __int16)word_5768B4[a1];
  if ( (unsigned int)(a1 - 20270) <= 0x238 )
    return (unsigned __int16)word_57688C[a1];
  if ( (unsigned int)(a1 - 20862) <= 0x397 )
    return (unsigned __int16)word_576864[a1];
  if ( (unsigned int)(a1 - 21802) <= 0x3C )
    return (unsigned __int16)word_57683C[a1];
  if ( (unsigned int)(a1 - 21887) <= 0x6B7 )
    return (unsigned __int16)word_576812[a1];
  if ( (unsigned int)(a1 - 23641) <= 0x292 )
    return (unsigned __int16)word_5767CE[a1];
  if ( (unsigned int)(a1 - 24322) <= 0x247 )
    return (unsigned __int16)word_5767A4[a1];
  if ( (unsigned int)(a1 - 24926) <= 0x132 )
    return (unsigned __int16)word_57677C[a1];
  if ( (unsigned int)(a1 - 25254) <= 0x4F5 )
    return (unsigned __int16)word_576754[a1];
  if ( (unsigned int)(a1 - 26544) <= 0x51 )
    return (unsigned __int16)word_576730[a1];
  if ( (unsigned int)(a1 - 26644) <= 0x103 )
    return (unsigned __int16)word_576710[a1];
  if ( (unsigned int)(a1 - 26929) <= 0x40E )
    return (unsigned __int16)word_5766DE[a1];
  if ( (unsigned int)(a1 - 27991) <= 0xAD )
    return (unsigned __int16)word_5766B2[a1];
  if ( (unsigned int)(a1 - 28190) <= 0xB1 )
    return (unsigned __int16)word_576684[a1];
  if ( (unsigned int)(a1 - 28395) <= 0x1F9 )
    return (unsigned __int16)word_576652[a1];
  if ( (unsigned int)(a1 - 28922) <= 0xE2 )
    return (unsigned __int16)word_57662C[a1];
  if ( (unsigned int)(a1 - 29176) <= 0xCA6 )
    return (unsigned __int16)word_5765F8[a1];
  if ( (unsigned int)(a1 - 32571) <= 0x109 )
    return *((unsigned __int16 *)&tab_uni_jisx020812_0.ArgList.dNameBuffer[9] + a1 + 1);
  if ( (unsigned int)(a1 - 32864) <= 0x302 )
    return *((unsigned __int16 *)&tab_uni_jisx020811_0.__vftable + a1);
  if ( (unsigned int)(a1 - 33648) <= 0xA9 )
    return *((unsigned __int16 *)&tab_uni_jisx02088_0.pForwardCompat + a1);
  if ( (unsigned int)(a1 - 33839) <= 0x451 )
    return (unsigned __int16)word_576452[a1];
  if ( (unsigned int)(a1 - 34968) <= 0x124 )
    return (unsigned __int16)word_576428[a1];
  if ( (unsigned int)(a1 - 35284) <= 0x1CB )
    return (unsigned __int16)word_576400[a1];
  if ( (unsigned int)(a1 - 35896) <= 0x6C )
    return (unsigned __int16)word_5762D0[a1];
  if ( (unsigned int)(a1 - 36025) <= 0x62 )
    return (unsigned __int16)word_5762AE[a1];
  if ( (unsigned int)(a1 - 36197) <= 0x200 )
    return (unsigned __int16)word_57621E[a1];
  if ( (unsigned int)(a1 - 36765) <= 0x4E7 )
    return (unsigned __int16)word_5761B6[a1];
  if ( (unsigned int)(a1 - 38264) <= 0x6E )
    return *((unsigned __int16 *)&tab_jisx0208_uni73_0 + a1);
  if ( (unsigned int)(a1 - 38429) <= 0x24F )
    return (unsigned __int16)word_575F66[a1];
  if ( (unsigned int)(a1 - 39083) <= 0x21 )
    return (unsigned __int16)word_575EEA[a1];
  if ( (unsigned int)(a1 - 39137) <= 0x7F )
    return (unsigned __int16)word_575EC6[a1];
  if ( (unsigned int)(a1 - 39323) <= 0xC2 )
    return *((unsigned __int16 *)&tab_jisx0208_uni71_0 + a1 + 1);
  if ( (unsigned int)(a1 - 39594) <= 0x1D1 )
    return (unsigned __int16)word_575DBC[a1];
  if ( (unsigned int)(a1 - 40166) <= 0x137 )
    return (unsigned __int16)word_575CEC[a1];
  if ( (unsigned int)(a1 - 40570) <= 0x12B )
    return (unsigned __int16)word_575C34[a1];
  if ( a1 == 63785 )
    return (unsigned __int16)tab_uni_jisx021246;
  if ( a1 == 63964 )
    return (unsigned __int16)tab_uni_jisx021247;
  if ( (unsigned int)(a1 - 64000) <= 0x2D )
    return (unsigned __int16)word_56A780[a1];
  if ( (unsigned int)(a1 - 65280) <= 7 )
    return (unsigned __int16)word_569DDC[a1];
  if ( a1 == 65508 )
    return (unsigned __int16)tab_uni_jisx021250;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004392F0
// Name: my_jisx0212_uni_onechar_0
// Source: json
//------------------------------------------------------------------------------
int __usercall my_jisx0212_uni_onechar_0@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 8751) <= 0x15 )
    return (unsigned __int16)word_56FBAE[a1];
  if ( (unsigned int)(a1 - 8811) <= 6 )
    return (unsigned __int16)word_585716[a1];
  if ( (unsigned int)(a1 - 9825) <= 0x1B )
    return (unsigned __int16)word_584F3A[a1];
  if ( (unsigned int)(a1 - 10050) <= 0xC )
    return (unsigned __int16)word_56F270[a1];
  if ( (unsigned int)(a1 - 10098) <= 0xC )
    return (unsigned __int16)word_56F2E8[a1];
  if ( (unsigned int)(a1 - 10529) <= 0x2F )
    return *((unsigned __int16 *)&tab_uni_jisx021227_0.ArgList.dNameBuffer[2] + a1 + 1);
  if ( (unsigned int)(a1 - 10785) <= 0x56 )
    return (unsigned __int16)word_584856[a1];
  if ( (unsigned int)(a1 - 11041) <= 0x56 )
    return (unsigned __int16)word_584706[a1];
  if ( (unsigned int)(a1 - 12321) <= 0x5D )
    return (unsigned __int16)word_583DB6[a1];
  if ( (unsigned int)(a1 - 12577) <= 0x5D )
    return (unsigned __int16)word_583C76[a1];
  if ( (unsigned int)(a1 - 12833) <= 0x5D )
    return (unsigned __int16)word_583B36[a1];
  if ( (unsigned int)(a1 - 13089) <= 0x5D )
    return (unsigned __int16)word_5839F6[a1];
  if ( (unsigned int)(a1 - 13345) <= 0x5D )
    return (unsigned __int16)word_5838B6[a1];
  if ( (unsigned int)(a1 - 13601) <= 0x5D )
    return (unsigned __int16)word_583776[a1];
  if ( (unsigned int)(a1 - 13857) <= 0x5D )
    return (unsigned __int16)word_583636[a1];
  if ( (unsigned int)(a1 - 14113) <= 0x5D )
    return (unsigned __int16)word_5834F6[a1];
  if ( (unsigned int)(a1 - 14369) <= 0x5D )
    return (unsigned __int16)word_5833B6[a1];
  if ( (unsigned int)(a1 - 14625) <= 0x5D )
    return (unsigned __int16)word_583276[a1];
  if ( (unsigned int)(a1 - 14881) <= 0x5D )
    return (unsigned __int16)word_583136[a1];
  if ( (unsigned int)(a1 - 15137) <= 0x5D )
    return (unsigned __int16)word_582FF6[a1];
  if ( (unsigned int)(a1 - 15393) <= 0x5D )
    return (unsigned __int16)word_582EB6[a1];
  if ( (unsigned int)(a1 - 15649) <= 0x5D )
    return (unsigned __int16)word_582D76[a1];
  if ( (unsigned int)(a1 - 15905) <= 0x5D )
    return (unsigned __int16)word_582C36[a1];
  if ( (unsigned int)(a1 - 16161) <= 0x5D )
    return (unsigned __int16)word_582AF6[a1];
  if ( (unsigned int)(a1 - 16417) <= 0x5D )
    return (unsigned __int16)word_5829B6[a1];
  if ( (unsigned int)(a1 - 16673) <= 0x5D )
    return (unsigned __int16)word_582876[a1];
  if ( (unsigned int)(a1 - 16929) <= 0x5D )
    return (unsigned __int16)word_582736[a1];
  if ( (unsigned int)(a1 - 17185) <= 0x5D )
    return (unsigned __int16)word_5825F6[a1];
  if ( (unsigned int)(a1 - 17441) <= 0x5D )
    return (unsigned __int16)word_5824B6[a1];
  if ( (unsigned int)(a1 - 17697) <= 0x5D )
    return (unsigned __int16)word_582376[a1];
  if ( (unsigned int)(a1 - 17953) <= 0x5D )
    return (unsigned __int16)word_582236[a1];
  if ( (unsigned int)(a1 - 18209) <= 0x5D )
    return (unsigned __int16)word_5820F6[a1];
  if ( (unsigned int)(a1 - 18465) <= 0x5D )
    return (unsigned __int16)word_581FB6[a1];
  if ( (unsigned int)(a1 - 18721) <= 0x5D )
    return (unsigned __int16)word_581E76[a1];
  if ( (unsigned int)(a1 - 18977) <= 0x5D )
    return (unsigned __int16)word_581D36[a1];
  if ( (unsigned int)(a1 - 19233) <= 0x5D )
    return (unsigned __int16)word_581BF6[a1];
  if ( (unsigned int)(a1 - 19489) <= 0x5D )
    return (unsigned __int16)word_581AB6[a1];
  if ( (unsigned int)(a1 - 19745) <= 0x5D )
    return (unsigned __int16)word_581976[a1];
  if ( (unsigned int)(a1 - 20001) <= 0x5D )
    return (unsigned __int16)word_581836[a1];
  if ( (unsigned int)(a1 - 20257) <= 0x5D )
    return (unsigned __int16)word_5816F6[a1];
  if ( (unsigned int)(a1 - 20513) <= 0x5D )
    return (unsigned __int16)word_5815B6[a1];
  if ( (unsigned int)(a1 - 20769) <= 0x5D )
    return (unsigned __int16)word_581476[a1];
  if ( (unsigned int)(a1 - 21025) <= 0x5D )
    return (unsigned __int16)word_581336[a1];
  if ( (unsigned int)(a1 - 21281) <= 0x5D )
    return (unsigned __int16)word_5811F6[a1];
  if ( (unsigned int)(a1 - 21537) <= 0x5D )
    return (unsigned __int16)word_5810B6[a1];
  if ( (unsigned int)(a1 - 21793) <= 0x5D )
    return (unsigned __int16)word_580F76[a1];
  if ( (unsigned int)(a1 - 22049) <= 0x5D )
    return (unsigned __int16)word_580E36[a1];
  if ( (unsigned int)(a1 - 22305) <= 0x5D )
    return (unsigned __int16)word_580CF6[a1];
  if ( (unsigned int)(a1 - 22561) <= 0x5D )
    return (unsigned __int16)word_580BB6[a1];
  if ( (unsigned int)(a1 - 22817) <= 0x5D )
    return (unsigned __int16)word_580A76[a1];
  if ( (unsigned int)(a1 - 23073) <= 0x5D )
    return (unsigned __int16)word_580936[a1];
  if ( (unsigned int)(a1 - 23329) <= 0x5D )
    return (unsigned __int16)word_5807F6[a1];
  if ( (unsigned int)(a1 - 23585) <= 0x5D )
    return (unsigned __int16)word_5806B6[a1];
  if ( (unsigned int)(a1 - 23841) <= 0x5D )
    return (unsigned __int16)word_580576[a1];
  if ( (unsigned int)(a1 - 24097) <= 0x5D )
    return (unsigned __int16)word_580436[a1];
  if ( (unsigned int)(a1 - 24353) <= 0x5D )
    return (unsigned __int16)word_5802F6[a1];
  if ( (unsigned int)(a1 - 24609) <= 0x5D )
    return (unsigned __int16)word_5801B6[a1];
  if ( (unsigned int)(a1 - 24865) <= 0x5D )
    return (unsigned __int16)word_580076[a1];
  if ( (unsigned int)(a1 - 25121) <= 0x5D )
    return (unsigned __int16)word_57FF36[a1];
  if ( (unsigned int)(a1 - 25377) <= 0x5D )
    return (unsigned __int16)word_57FDF6[a1];
  if ( (unsigned int)(a1 - 25633) <= 0x5D )
    return (unsigned __int16)word_57FCB6[a1];
  if ( (unsigned int)(a1 - 25889) <= 0x5D )
    return (unsigned __int16)word_57FB76[a1];
  if ( (unsigned int)(a1 - 26145) <= 0x5D )
    return (unsigned __int16)word_57FA36[a1];
  if ( (unsigned int)(a1 - 26401) <= 0x5D )
    return (unsigned __int16)word_57F8F6[a1];
  if ( (unsigned int)(a1 - 26657) <= 0x5D )
    return (unsigned __int16)word_57F7B6[a1];
  if ( (unsigned int)(a1 - 26913) <= 0x5D )
    return (unsigned __int16)word_57F676[a1];
  if ( (unsigned int)(a1 - 27169) <= 0x5D )
    return (unsigned __int16)word_57F536[a1];
  if ( (unsigned int)(a1 - 27425) <= 0x5D )
    return (unsigned __int16)word_57F3F6[a1];
  if ( (unsigned int)(a1 - 27681) <= 0x5D )
    return (unsigned __int16)word_57F2B6[a1];
  if ( (unsigned int)(a1 - 27937) <= 0x42 )
    return (unsigned __int16)word_57F176[a1];
  if ( (unsigned int)(a1 - 29553) <= 0xD )
    return (unsigned __int16)word_565BC2[a1];
  if ( (unsigned int)(a1 - 29729) > 0x5D )
    return 0;
  return (unsigned __int16)word_57E3FE[a1];
}

//------------------------------------------------------------------------------
// Address: 0x004398A0
// Name: my_well_formed_len_eucjpms
// Source: json
//------------------------------------------------------------------------------
int my_well_formed_len_eucjpms(
        LIST_ENTRY32 *cs,
        const char *beg,
        tagShutdownType end,
        unsigned int pos,
        int *error,
        ...)
{
  unsigned int v5; // edi
  const char *v6; // ecx
  unsigned int v7; // edx
  const char *v8; // eax
  bool v9; // cc

  v5 = pos;
  v6 = beg;
  *error = 0;
  if ( pos != 0 )
  {
    while ( (unsigned int)v6 < end )
    {
      v7 = *(unsigned __int8 *)v6;
      if ( v7 > 0x7F )
      {
        v8 = v6++;
        if ( (unsigned int)v6 >= end )
          return v8 - beg;
        if ( v7 == 142 )
        {
          if ( *v6 < 0xA0u )
            goto LABEL_17;
          v9 = *v6 <= 0xDFu;
        }
        else
        {
          if ( v7 == 143 && (v7 = *(unsigned __int8 *)v6, ++v6, (unsigned int)v6 >= end)
            || v7 - 161 > 0x5D
            || *v6 < 0xA1u )
          {
LABEL_17:
            *error = 1;
            return v8 - beg;
          }
          v9 = *v6 != 0xFF;
        }
        if ( !v9 )
          goto LABEL_17;
      }
      --v5;
      ++v6;
      if ( v5 == 0 )
        break;
    }
  }
  v8 = v6;
  return v8 - beg;
}

//------------------------------------------------------------------------------
// Address: 0x00439930
// Name: my_numcells_eucjp
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_numcells_eucjp(int a1, char *a2, unsigned int a3)
{
  char *v3; // ecx
  int result; // eax
  char v5; // dl

  v3 = a2;
  result = 0;
  while ( (unsigned int)v3 < a3 )
  {
    v5 = *v3;
    if ( *v3 == -114 )
    {
      ++result;
      v3 += 2;
    }
    else if ( v5 == -113 )
    {
      result += 2;
      v3 += 3;
    }
    else if ( v5 >= 0 )
    {
      ++result;
      ++v3;
    }
    else
    {
      result += 2;
      v3 += 2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439970
// Name: my_mb_wc_euc_jp_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_euc_jp_0(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // eax

  if ( (unsigned int)a3 >= a4 )
    return -101;
  v5 = *a3;
  if ( v5 <= 0x7F )
  {
    *a2 = v5;
    return 1;
  }
  if ( (unsigned int)(a3 + 2) > a4 )
    return -102;
  v6 = a3[1];
  if ( v5 - 161 <= 0x5D )
  {
    if ( (unsigned int)(v6 - 161) <= 0x5D )
    {
      if ( *a3 >= 0xF5u )
      {
        *a2 = 94 * (v5 - 245) + v6 + 57183;
      }
      else
      {
        v7 = my_jisx0208_uni_onechar_0(a1: (v5 << 8) + v6 - 32896);
        *a2 = v7;
        if ( v7 == 0 )
          return -2;
      }
      return 2;
    }
    return 0;
  }
  if ( v5 == 142 )
  {
    if ( (unsigned int)(v6 - 161) <= 0x3E )
      return my_mb_wc_jisx0201_0(a1: a3 + 1, a2) != 1 ? -2 : 2;
    return 0;
  }
  if ( v5 != 143 || (unsigned int)(v6 - 161) > 0x5D )
    return 0;
  if ( (unsigned int)(a3 + 3) > a4 )
    return -103;
  v8 = a3[2];
  if ( (unsigned int)(v8 - 161) > 0x5D )
    return 0;
  if ( a3[1] >= 0xF5u )
  {
    *a2 = 94 * (v6 - 245) + v8 + 58123;
  }
  else
  {
    v9 = my_jisx0212_uni_onechar_0(a1: (v6 << 8) + v8 - 32896);
    *a2 = v9;
    if ( v9 == 0 )
      return -3;
  }
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x00439AD0
// Name: my_wc_mb_euc_jp_0
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_euc_jp_0(LIST_ENTRY32 *c, int wc, unsigned __int8 *s, unsigned __int8 *e, ...)
{
  int v5; // eax
  __int16 v6; // ax
  int v7; // eax
  __int16 v8; // ax

  if ( s >= e )
    return -101;
  if ( wc < 128 )
  {
    *s = wc;
    return 1;
  }
  v5 = my_uni_jisx0208_onechar_0(a1: wc);
  if ( v5 != 0 )
  {
    if ( s + 2 <= e )
    {
      v6 = v5 - 32640;
      s[1] = v6;
      *s = HIBYTE(v6);
      return 2;
    }
    return -102;
  }
  if ( my_wc_mb_jisx0201(wc, a2: s) )
  {
    if ( s + 2 <= e )
    {
      s[1] = *s;
      *s = -114;
      return 2;
    }
    return -102;
  }
  v7 = my_uni_jisx0212_onechar_0(a1: wc);
  if ( v7 != 0 )
  {
    if ( s + 3 <= e )
    {
      v8 = v7 - 32640;
      s[2] = v8;
      *s = -113;
      s[1] = HIBYTE(v8);
      return 3;
    }
    return -103;
  }
  if ( (unsigned int)wc >= 0xE000 )
  {
    if ( (unsigned int)wc < 0xE3AC )
    {
      if ( s + 2 > e )
        return -102;
      *s = (wc - 57344) / 0x5Eu - 11;
      s[1] = (wc - 57344) % 0x5Eu - 95;
      return 2;
    }
    if ( (unsigned int)wc < 0xE758 )
    {
      if ( s + 3 > e )
        return -103;
      *s = -113;
      s[1] = (wc - 58284) / 0x5Eu - 11;
      s[2] = (wc - 58284) % 0x5Eu - 95;
      return 3;
    }
  }
  return 0;
}
