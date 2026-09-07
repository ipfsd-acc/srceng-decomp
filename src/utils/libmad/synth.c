// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/libmad/synth.c
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0051AD60
// Name: _mad_synth_mute
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_synth_mute(mad_synth *synth)
{
  int *v1; // edi
  int i; // ebx
  int *v3; // eax
  int j; // esi
  int k; // ecx

  v1 = synth->filter[0][1][0][0];
  for ( i = 2; i != 0; --i )
  {
    v3 = v1;
    for ( j = 16; j != 0; --j )
    {
      for ( k = 8; k != 0; --k )
      {
        v3[128] = 0;
        *v3 = 0;
        *(v3 - 128) = 0;
        *(v3 - 256) = 0;
        ++v3;
      }
    }
    v1 += 512;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051ADD0
// Name: dct32
// Source: json
//------------------------------------------------------------------------------
void __usercall dct32(unsigned int slot@<ecx>, int (*hi)[8]@<eax>, const int *in, int (*lo)[8])
{
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // edx
  int v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // eax
  int v26; // edx
  int v27; // eax
  int v28; // eax
  int v29; // edx
  int v30; // eax
  int v31; // esi
  int v32; // eax
  int v33; // esi
  int v34; // eax
  int v35; // edx
  int v36; // eax
  int v37; // edx
  int v38; // eax
  int v39; // edx
  int v40; // edi
  int v41; // eax
  int v42; // edi
  int v43; // edi
  int t89; // [esp+Ch] [ebp-D4h]
  int t96; // [esp+10h] [ebp-D0h]
  int t92; // [esp+14h] [ebp-CCh]
  int t90; // [esp+18h] [ebp-C8h]
  int t91; // [esp+1Ch] [ebp-C4h]
  int t100; // [esp+20h] [ebp-C0h]
  int t97; // [esp+24h] [ebp-BCh]
  int t94; // [esp+28h] [ebp-B8h]
  int t108; // [esp+2Ch] [ebp-B4h]
  int t108a; // [esp+2Ch] [ebp-B4h]
  int t154; // [esp+30h] [ebp-B0h]
  int t107; // [esp+34h] [ebp-ACh]
  int t107a; // [esp+34h] [ebp-ACh]
  int t125; // [esp+38h] [ebp-A8h]
  int t106; // [esp+3Ch] [ebp-A4h]
  int t106a; // [esp+3Ch] [ebp-A4h]
  int t101; // [esp+40h] [ebp-A0h]
  int t101a; // [esp+40h] [ebp-A0h]
  int t132; // [esp+44h] [ebp-9Ch]
  int t43; // [esp+48h] [ebp-98h]
  int t103; // [esp+4Ch] [ebp-94h]
  int t103a; // [esp+4Ch] [ebp-94h]
  int t47; // [esp+50h] [ebp-90h]
  int t47a; // [esp+50h] [ebp-90h]
  int t161; // [esp+54h] [ebp-8Ch]
  int t161a; // [esp+54h] [ebp-8Ch]
  int t69; // [esp+58h] [ebp-88h]
  int t69a; // [esp+58h] [ebp-88h]
  int t71; // [esp+5Ch] [ebp-84h]
  int t71a; // [esp+5Ch] [ebp-84h]
  int t72; // [esp+60h] [ebp-80h]
  int t72a; // [esp+60h] [ebp-80h]
  int t62; // [esp+64h] [ebp-7Ch]
  int t62a; // [esp+64h] [ebp-7Ch]
  int t78; // [esp+68h] [ebp-78h]
  int t74; // [esp+6Ch] [ebp-74h]
  int t74a; // [esp+6Ch] [ebp-74h]
  int t153; // [esp+70h] [ebp-70h]
  int t153a; // [esp+70h] [ebp-70h]
  int t153b; // [esp+70h] [ebp-70h]
  int t111; // [esp+74h] [ebp-6Ch]
  int t111a; // [esp+74h] [ebp-6Ch]
  int t111b; // [esp+74h] [ebp-6Ch]
  int t174; // [esp+78h] [ebp-68h]
  int t174a; // [esp+78h] [ebp-68h]
  int t174b; // [esp+78h] [ebp-68h]
  int t61; // [esp+7Ch] [ebp-64h]
  int t61a; // [esp+7Ch] [ebp-64h]
  int t61b; // [esp+7Ch] [ebp-64h]
  int t128; // [esp+80h] [ebp-60h]
  int t128a; // [esp+80h] [ebp-60h]
  int t128b; // [esp+80h] [ebp-60h]
  int t150; // [esp+84h] [ebp-5Ch]
  int t150a; // [esp+84h] [ebp-5Ch]
  int t81; // [esp+88h] [ebp-58h]
  int t81a; // [esp+88h] [ebp-58h]
  int t81b; // [esp+88h] [ebp-58h]
  int t75; // [esp+8Ch] [ebp-54h]
  int t75a; // [esp+8Ch] [ebp-54h]
  int t135; // [esp+90h] [ebp-50h]
  int t53; // [esp+94h] [ebp-4Ch]
  int t53a; // [esp+94h] [ebp-4Ch]
  int t53b; // [esp+94h] [ebp-4Ch]
  int t59; // [esp+98h] [ebp-48h]
  int t59a; // [esp+98h] [ebp-48h]
  int t59b; // [esp+98h] [ebp-48h]
  int t98; // [esp+9Ch] [ebp-44h]
  int t98a; // [esp+9Ch] [ebp-44h]
  int t98b; // [esp+9Ch] [ebp-44h]
  int t46; // [esp+A0h] [ebp-40h]
  int t46a; // [esp+A0h] [ebp-40h]
  int t46b; // [esp+A0h] [ebp-40h]
  int t172; // [esp+A4h] [ebp-3Ch]
  int t172a; // [esp+A4h] [ebp-3Ch]
  int t172b; // [esp+A4h] [ebp-3Ch]
  int t122; // [esp+A8h] [ebp-38h]
  int t122a; // [esp+A8h] [ebp-38h]
  int t165; // [esp+ACh] [ebp-34h]
  int t165a; // [esp+ACh] [ebp-34h]
  int t165b; // [esp+ACh] [ebp-34h]
  int t163; // [esp+B4h] [ebp-2Ch]
  int t163a; // [esp+B4h] [ebp-2Ch]
  int t169; // [esp+B8h] [ebp-28h]
  int t169a; // [esp+B8h] [ebp-28h]
  int t170; // [esp+BCh] [ebp-24h]
  int t170a; // [esp+BCh] [ebp-24h]
  int t126; // [esp+C0h] [ebp-20h]
  int t162; // [esp+C4h] [ebp-1Ch]
  int t162a; // [esp+C4h] [ebp-1Ch]
  int t162b; // [esp+C4h] [ebp-1Ch]
  int t39; // [esp+C8h] [ebp-18h]
  int t39a; // [esp+C8h] [ebp-18h]
  int t39b; // [esp+C8h] [ebp-18h]
  int t39c; // [esp+C8h] [ebp-18h]
  int t39d; // [esp+C8h] [ebp-18h]
  int t39e; // [esp+C8h] [ebp-18h]
  int t39f; // [esp+C8h] [ebp-18h]
  int t20; // [esp+CCh] [ebp-14h]
  int t20a; // [esp+CCh] [ebp-14h]
  int t20b; // [esp+CCh] [ebp-14h]
  int t20c; // [esp+CCh] [ebp-14h]
  int t20d; // [esp+CCh] [ebp-14h]
  int t20e; // [esp+CCh] [ebp-14h]
  int t20f; // [esp+CCh] [ebp-14h]
  int t20g; // [esp+CCh] [ebp-14h]
  int t20h; // [esp+CCh] [ebp-14h]
  int t88; // [esp+D0h] [ebp-10h]
  int t88a; // [esp+D0h] [ebp-10h]
  int t88b; // [esp+D0h] [ebp-10h]
  int t88c; // [esp+D0h] [ebp-10h]
  int t88d; // [esp+D0h] [ebp-10h]
  int t88e; // [esp+D0h] [ebp-10h]
  int t88f; // [esp+D0h] [ebp-10h]
  int t32; // [esp+D4h] [ebp-Ch]
  int t32a; // [esp+D4h] [ebp-Ch]
  int t32b; // [esp+D4h] [ebp-Ch]
  int t32c; // [esp+D4h] [ebp-Ch]
  int t32d; // [esp+D4h] [ebp-Ch]
  int t18; // [esp+D8h] [ebp-8h]
  int t18a; // [esp+D8h] [ebp-8h]
  int t18b; // [esp+D8h] [ebp-8h]
  int t18c; // [esp+D8h] [ebp-8h]
  int t29; // [esp+DCh] [ebp-4h]
  int t29a; // [esp+DCh] [ebp-4h]
  int t29b; // [esp+DCh] [ebp-4h]
  int t29c; // [esp+DCh] [ebp-4h]
  int t29d; // [esp+DCh] [ebp-4h]
  int t142; // [esp+E8h] [ebp+8h]
  int t142a; // [esp+E8h] [ebp+8h]
  int t142b; // [esp+E8h] [ebp+8h]
  int t142c; // [esp+E8h] [ebp+8h]
  int t142d; // [esp+E8h] [ebp+8h]
  int t142e; // [esp+E8h] [ebp+8h]
  int t142f; // [esp+E8h] [ebp+8h]
  int t139; // [esp+ECh] [ebp+Ch]
  int t139a; // [esp+ECh] [ebp+Ch]
  int t139b; // [esp+ECh] [ebp+Ch]
  int t139c; // [esp+ECh] [ebp+Ch]
  int t139d; // [esp+ECh] [ebp+Ch]

  t20 = *in + in[31];
  t18 = (unsigned __int64)(268112114LL * (*in - in[31])) >> 28;
  v7 = in[15];
  v8 = v7 + in[16];
  t142 = (unsigned __int64)(13171504LL * (v7 - in[16])) >> 28;
  t132 = t18 + t142;
  t59 = (unsigned __int64)(267142866LL * (t18 - t142)) >> 28;
  t108 = t20 + v8;
  t101 = (unsigned __int64)(267142866LL * (t20 - v8)) >> 28;
  v9 = in[7];
  t20a = v9 + in[24];
  t18a = (unsigned __int64)(198897553LL * (v9 - in[24])) >> 28;
  v10 = in[8];
  v11 = v10 + in[23];
  t142a = (unsigned __int64)(180270234LL * (v10 - in[23])) >> 28;
  t74 = t18a + t142a;
  t153 = (unsigned __int64)(26311276LL * (t18a - t142a)) >> 28;
  t142b = t20a + v11;
  t150 = (unsigned __int64)(26311276LL * (t20a - v11)) >> 28;
  v12 = in[3];
  t39 = v12 + in[28];
  t20b = (unsigned __int64)(252743810LL * (v12 - in[28])) >> 28;
  v13 = in[12];
  v14 = v13 + in[19];
  t29 = (unsigned __int64)(90433181LL * (v13 - in[19])) >> 28;
  t43 = t20b + t29;
  t61 = (unsigned __int64)(207503414LL * (t20b - t29)) >> 28;
  t107 = t39 + v14;
  t128 = (unsigned __int64)(207503414LL * (t39 - v14)) >> 28;
  v15 = in[4];
  t39a = v15 + in[27];
  t20c = (unsigned __int64)(242662778LL * (v15 - in[27])) >> 28;
  v16 = in[11];
  v17 = v16 + in[20];
  t29a = (unsigned __int64)(114770946LL * (v16 - in[20])) >> 28;
  t75 = t20c + t29a;
  t62 = (unsigned __int64)(170293651LL * (t20c - t29a)) >> 28;
  t71 = t39a + v17;
  t53 = (unsigned __int64)(170293651LL * (t39a - v17)) >> 28;
  v18 = in[1];
  t39b = v18 + in[30];
  t20d = (unsigned __int64)(265530048LL * (v18 - in[30])) >> 28;
  v19 = in[14];
  v20 = v19 + in[17];
  t29b = (unsigned __int64)(39387662LL * (v19 - in[17])) >> 28;
  t103 = t20d + t29b;
  t162 = (unsigned __int64)(256876715LL * (t20d - t29b)) >> 28;
  t106 = t39b + v20;
  t125 = (unsigned __int64)(256876715LL * (t39b - v20)) >> 28;
  v21 = in[6];
  t39c = v21 + in[25];
  t20e = (unsigned __int64)(215609380LL * (v21 - in[25])) >> 28;
  v22 = in[9];
  v23 = v22 + in[22];
  t29c = (unsigned __int64)(159906814LL * (v22 - in[22])) >> 28;
  t46 = t20e + t29c;
  t163 = (unsigned __int64)(77922700LL * (t20e - t29c)) >> 28;
  t72 = t39c + v23;
  t81 = (unsigned __int64)(77922700LL * (t39c - v23)) >> 28;
  v24 = in[2];
  t39d = v24 + in[29];
  t20f = (unsigned __int64)(260390782LL * (v24 - in[29])) >> 28;
  v25 = in[13];
  v26 = v25 + in[18];
  t29d = (unsigned __int64)(65224495LL * (v25 - in[18])) >> 28;
  t47 = t20f + t29d;
  t88 = (unsigned __int64)(236738937LL * (t20f - t29d)) >> 28;
  v27 = t39d - v26;
  t39e = t39d + v26;
  t111 = (unsigned __int64)(236738937LL * v27) >> 28;
  v28 = in[5];
  t20g = v28 + in[26];
  v29 = in[21];
  t18b = (unsigned __int64)(230244771LL * (v28 - in[26])) >> 28;
  v30 = in[10];
  v31 = v30 + v29;
  v32 = (unsigned __int64)(138003405LL * (v30 - v29)) >> 28;
  t32 = (unsigned __int64)(126539598LL * (t18b - v32)) >> 28;
  t139 = v31 + t20g;
  v33 = (unsigned __int64)(126539598LL * (t20g - v31)) >> 28;
  t69 = t108 + t142b;
  t89 = (unsigned __int64)(263277544LL * (t108 - t142b)) >> 28;
  t142c = t107 + t71;
  t90 = (unsigned __int64)(52369160LL * (t107 - t71)) >> 28;
  t71a = t106 + t72;
  t91 = (unsigned __int64)(223195925LL * (t106 - t72)) >> 28;
  t72a = t39e + t139;
  t92 = (unsigned __int64)(149134749LL * (t39e - t139)) >> 28;
  t139a = t132 + t74;
  t94 = (unsigned __int64)(263277544LL * (t132 - t74)) >> 28;
  t74a = t43 + t75;
  t161 = (unsigned __int64)(52369160LL * (t43 - t75)) >> 28;
  t75a = t103 + t46;
  t96 = (unsigned __int64)(223195925LL * (t103 - t46)) >> 28;
  t46a = t47 + t18b + v32;
  t97 = (unsigned __int64)(149134749LL * (t47 - (t18b + v32))) >> 28;
  t78 = t101 + t150;
  t100 = (unsigned __int64)(263277544LL * (t101 - t150)) >> 28;
  t150a = t128 + t53;
  t101a = (unsigned __int64)(52369160LL * (t128 - t53)) >> 28;
  t53a = t125 + t81;
  t47a = (unsigned __int64)(223195925LL * (t125 - t81)) >> 28;
  t81a = v33 + t111;
  t103a = (unsigned __int64)(149134749LL * (t111 - v33)) >> 28;
  t154 = t153 + t59;
  t106a = (unsigned __int64)(263277544LL * (t59 - t153)) >> 28;
  t59a = t62 + t61;
  t107a = (unsigned __int64)(52369160LL * (t61 - t62)) >> 28;
  t153a = t163 + t162;
  t108a = (unsigned __int64)(223195925LL * (t162 - t163)) >> 28;
  t111a = t32 + t88;
  t39f = (unsigned __int64)(149134749LL * (t88 - t32)) >> 28;
  (*hi)[slot + 120] = t71a + t72a + t69 + t142c;
  (*lo)[slot] = (unsigned __int64)(189812531LL * (t69 + t142c - (t71a + t72a))) >> 28;
  t18c = t139a + t74a;
  t165 = t75a + t46a;
  t32a = t139a + t74a + t75a + t46a;
  (*hi)[slot + 112] = t32a;
  t172 = t53a + t81a;
  t88a = t78 + t150a + t53a + t81a;
  (*hi)[slot + 104] = t88a;
  t20h = t154 + t62 + t61;
  t122 = t163 + t162 + t111a;
  t32b = 2 * (t20h + t122) - t32a;
  (*hi)[slot + 96] = t32b;
  t62a = t89 + t90 + t91 + t92;
  (*hi)[slot + 88] = t62a;
  t128a = t94 + t161;
  t98 = t94 + t161 + t96 + t97;
  t32c = 2 * t98 - t32b;
  (*hi)[slot + 80] = t32c;
  t135 = t100 + t101a + t47a + t103a;
  t163a = 2 * t135 - t88a;
  (*hi)[slot + 72] = t163a;
  t174 = t106a + t107a + t108a + t39f;
  t61a = 2 * t174 - (t20h + t122);
  v34 = 2 * t61a - t32c;
  (*hi)[slot + 64] = v34;
  t88b = (unsigned __int64)(248002024LL * (t69 - t142c)) >> 28;
  t142d = (unsigned __int64)(102725802LL * (t71a - t72a)) >> 28;
  v35 = t88b - t142d;
  t88c = t88b + t142d;
  (*hi)[slot + 56] = t88c;
  (*lo)[slot + 64] = 2 * ((unsigned __int64)(189812531LL * v35) >> 28) - t88c;
  t69a = (unsigned __int64)(248002024LL * (t139a - t74a)) >> 28;
  t46b = (unsigned __int64)(102725802LL * (t75a - t46a)) >> 28;
  t88d = 2 * (t69a + t46b) - v34;
  (*hi)[slot + 48] = t88d;
  t142e = (unsigned __int64)(248002024LL * (t78 - t150a)) >> 28;
  t53b = (unsigned __int64)(102725802LL * (t53a - t81a)) >> 28;
  t81b = 2 * (t142e + t53b) - t163a;
  (*hi)[slot + 40] = t81b;
  t59b = (unsigned __int64)(248002024LL * (t154 - t59a)) >> 28;
  t153b = (unsigned __int64)(102725802LL * (t153a - t111a)) >> 28;
  t111b = 2 * (t59b + t153b) - t61a;
  t61b = 2 * t111b - t88d;
  (*hi)[slot + 32] = t61b;
  t139b = (unsigned __int64)(248002024LL * (t89 - t90)) >> 28;
  t162a = (unsigned __int64)(102725802LL * (t91 - t92)) >> 28;
  t88e = 2 * (t139b + t162a) - t62a;
  (*hi)[slot + 24] = t88e;
  t32d = 2 * ((unsigned __int64)(189812531LL * (t89 + t90 - (t91 + t92))) >> 28) - t88e;
  (*lo)[slot + 32] = t32d;
  (*lo)[slot + 96] = 2 * (2 * ((unsigned __int64)(189812531LL * (t139b - t162a)) >> 28) - (t139b + t162a)) - t32d;
  t161a = (unsigned __int64)(248002024LL * (t94 - t161)) >> 28;
  t162b = (unsigned __int64)(102725802LL * (t96 - t97)) >> 28;
  t98a = 2 * (t161a + t162b) - t98;
  t88f = 2 * t98a - t61b;
  (*hi)[slot + 16] = t88f;
  t128b = 2 * ((unsigned __int64)(189812531LL * (t128a - (t96 + t97))) >> 28) - t98a;
  t139c = (unsigned __int64)(248002024LL * (t100 - t101a)) >> 28;
  t126 = (unsigned __int64)(102725802LL * (t47a - t103a)) >> 28;
  t98b = 2 * (t139c + t126) - t135;
  t169 = 2 * t98b - t81b;
  (*hi)[slot + 8] = t169;
  v36 = 2 * ((unsigned __int64)(189812531LL * (t78 + t150a - t172)) >> 28) - t169;
  (*lo)[slot + 16] = v36;
  t169a = 2 * ((unsigned __int64)(189812531LL * (t100 + t101a - (t47a + t103a))) >> 28) - t98b;
  t172a = 2 * t169a - v36;
  (*lo)[slot + 48] = t172a;
  t170 = 2 * (2 * ((unsigned __int64)(189812531LL * (t142e - t53b)) >> 28) - (t142e + t53b)) - t172a;
  (*lo)[slot + 80] = t170;
  (*lo)[slot + 112] = 2 * (2 * (2 * ((unsigned __int64)(189812531LL * (t139c - t126)) >> 28) - (t139c + t126)) - t169a)
                    - t170;
  t142f = (unsigned __int64)(248002024LL * (t106a - t107a)) >> 28;
  t172b = (unsigned __int64)(102725802LL * (t108a - t39f)) >> 28;
  t170a = 2 * (t142f + t172b) - t174;
  v37 = 2 * t170a - t111b;
  t139d = 2 * ((unsigned __int64)(189812531LL * (t20h - t122)) >> 28) - v37;
  t174a = 2 * v37 - t88f;
  (*hi)[slot] = t174a;
  v38 = 2 * ((unsigned __int64)(189812531LL * (t18c - t165)) >> 28) - t174a;
  v39 = 2 * t139d - v38;
  (*lo)[slot + 8] = v38;
  v40 = 2 * t128b - v39;
  (*lo)[slot + 24] = v39;
  (*lo)[slot + 40] = v40;
  t174b = 2 * ((unsigned __int64)(189812531LL * (t106a + t107a - (t108a + t39f))) >> 28) - t170a;
  v41 = 2 * t174b - t139d;
  t165a = 2 * v41 - v40;
  (*lo)[slot + 56] = t165a;
  v42 = 2 * (2 * ((unsigned __int64)(189812531LL * (t69a - t46b)) >> 28) - (t69a + t46b)) - t165a;
  (*lo)[slot + 72] = v42;
  t122a = 2 * (2 * ((unsigned __int64)(189812531LL * (t59b - t153b)) >> 28) - (t59b + t153b)) - v41;
  t165b = 2 * t122a - v42;
  (*lo)[slot + 88] = t165b;
  v43 = 2 * (2 * (2 * ((unsigned __int64)(189812531LL * (t161a - t162b)) >> 28) - (t161a + t162b)) - t128b) - t165b;
  (*lo)[slot + 104] = v43;
  (*lo)[slot + 120] = 2
                    * (2
                     * (2 * (2 * ((unsigned __int64)(189812531LL * (t142f - t172b)) >> 28) - (t142f + t172b)) - t174b)
                     - t122a)
                    - v43;
}

//------------------------------------------------------------------------------
// Address: 0x0051BC00
// Name: synth_full
// Source: json
//------------------------------------------------------------------------------
void __cdecl synth_full(mad_synth *synth, const mad_frame *frame, unsigned int nch, unsigned int ns)
{
  mad_synth *v4; // eax
  mad_synth *v5; // edi
  unsigned int v6; // esi
  int *v7; // ecx
  int v8; // ebx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int *v12; // ebx
  int *v13; // esi
  const int *v14; // ebx
  int v15; // eax
  const int *v16; // edi
  const int *v17; // eax
  int v18; // edx
  bool v19; // zf
  unsigned int po; // [esp+0h] [ebp-74h]
  unsigned int v21; // [esp+10h] [ebp-64h]
  int v22; // [esp+14h] [ebp-60h]
  int v23; // [esp+18h] [ebp-5Ch]
  int v24; // [esp+1Ch] [ebp-58h]
  int v25; // [esp+20h] [ebp-54h]
  int v26; // [esp+24h] [ebp-50h]
  int v27; // [esp+24h] [ebp-50h]
  int v28; // [esp+28h] [ebp-4Ch]
  int v29; // [esp+28h] [ebp-4Ch]
  int v30; // [esp+2Ch] [ebp-48h]
  int v31; // [esp+30h] [ebp-44h]
  int v32; // [esp+30h] [ebp-44h]
  int v33; // [esp+34h] [ebp-40h]
  int v34; // [esp+38h] [ebp-3Ch]
  int v35; // [esp+38h] [ebp-3Ch]
  int v36; // [esp+3Ch] [ebp-38h]
  int v37; // [esp+3Ch] [ebp-38h]
  int v38; // [esp+40h] [ebp-34h]
  int v39; // [esp+40h] [ebp-34h]
  int v40; // [esp+44h] [ebp-30h]
  int v41; // [esp+44h] [ebp-30h]
  unsigned int v42; // [esp+48h] [ebp-2Ch]
  unsigned int v43; // [esp+4Ch] [ebp-28h]
  int v44; // [esp+50h] [ebp-24h]
  unsigned int pcm2a; // [esp+54h] [ebp-20h]
  int *pcm2; // [esp+54h] [ebp-20h]
  int *v47; // [esp+58h] [ebp-1Ch]
  int *v48; // [esp+5Ch] [ebp-18h]
  mad_synth *v49; // [esp+60h] [ebp-14h]
  int *in; // [esp+64h] [ebp-10h]
  unsigned int phase; // [esp+68h] [ebp-Ch]
  int *pcm1; // [esp+6Ch] [ebp-8h]
  int *pcm1a; // [esp+6Ch] [ebp-8h]
  int v54; // [esp+70h] [ebp-4h]
  const int *ncha; // [esp+84h] [ebp+10h]

  if ( nch != 0 )
  {
    v4 = synth;
    v47 = synth->pcm.samples[0];
    v5 = synth;
    v49 = synth;
    v48 = frame->sbsample[0][0];
    v42 = nch;
    do
    {
      v6 = v4->phase;
      pcm1 = v47;
      LOBYTE(phase) = v6;
      if ( ns != 0 )
      {
        in = v48;
        v43 = ns;
        dct32(
          slot: v4->phase >> 1,
          hi: v5->filter[0][1][v4->phase & 1],
          in: v48,
          lo: (int (*)[8])((int *)v5 + 16 * (v4->phase & 1)));
        while ( 1 )
        {
          pcm2a = v6 & 0xFFFFFFFE;
          v7 = (int *)((char *)v5 + 512 * (v6 & 1));
          v8 = (v6 & 1) == 0;
          v9 = ((_BYTE)v6 - 1) & 0xE;
          v10 = v8 + 2;
          v8 <<= 9;
          v11 = *(int *)((char *)v5->filter[0][0][0][0] + v8);
          v12 = (int *)((char *)v5 + v8);
          v13 = (int *)((char *)v5 + 512 * v10);
          po = v9 | 1;
          v31 = (unsigned __int64)((int)D[0][(v9 | 1) + 14] * (__int64)v12[1]) >> 28;
          v33 = (unsigned __int64)((int)D[0][(v9 | 1) + 12] * (__int64)v12[2]) >> 28;
          v34 = (unsigned __int64)((int)D[0][(v9 | 1) + 10] * (__int64)v12[3]) >> 28;
          v36 = (unsigned __int64)((int)D[0][(v9 | 1) + 8] * (__int64)v12[4]) >> 28;
          v38 = (unsigned __int64)((int)D[0][(v9 | 1) + 6] * (__int64)v12[5]) >> 28;
          v40 = (unsigned __int64)((int)D[0][(v9 | 1) + 4] * (__int64)v12[6]) >> 28;
          v54 = (unsigned __int64)((int)D[0][(v9 | 1) + 2] * (__int64)v12[7]) >> 28;
          v21 = 4 * pcm2a;
          v22 = (unsigned __int64)((int)D[0][pcm2a] * (__int64)*v7) >> 28;
          v23 = (unsigned __int64)((int)D[0][pcm2a + 14] * (__int64)v7[1]) >> 28;
          v24 = (unsigned __int64)((int)D[0][pcm2a + 12] * (__int64)v7[2]) >> 28;
          v25 = (unsigned __int64)((int)D[0][pcm2a + 10] * (__int64)v7[3]) >> 28;
          v26 = (unsigned __int64)((int)D[0][pcm2a + 8] * (__int64)v7[4]) >> 28;
          v28 = (unsigned __int64)((int)D[0][pcm2a + 6] * (__int64)v7[5]) >> 28;
          v14 = &D[0][-(v9 | 1) + 27];
          pcm1a = pcm1 + 1;
          v15 = ((unsigned __int64)((int)D[0][pcm2a + 4] * (__int64)v7[6]) >> 28)
              + ((unsigned __int64)((int)D[0][pcm2a + 2] * (__int64)v7[7]) >> 28)
              - v54
              - v40
              - v38
              - v36
              - v34
              - v33
              - v31
              - ((unsigned __int64)((int)D[0][v9 | 1] * (__int64)v11) >> 28);
          pcm2 = pcm1a + 30;
          *(pcm1a - 1) = v22 + v23 + v24 + v25 + v26 + v28 + v15;
          v16 = &D[0][v21 / 0xFFFFFFFC + 17];
          ncha = &D[0][v21 / 4 + 4];
          v17 = &D[0][po + 12];
          v44 = 15;
          while ( 1 )
          {
            ncha += 32;
            v7 += 8;
            v16 += 32;
            v14 += 32;
            v32 = (unsigned __int64)(v17[20] * (__int64)*v13) >> 28;
            v30 = (unsigned __int64)(v17[34] * (__int64)v13[1]) >> 28;
            v29 = (unsigned __int64)(v17[32] * (__int64)v13[2]) >> 28;
            v27 = (unsigned __int64)(v17[30] * (__int64)v13[3]) >> 28;
            *pcm1a++ = ((unsigned __int64)(*(ncha - 2) * (__int64)v7[7]) >> 28)
                     + ((unsigned __int64)(*ncha * (__int64)v7[6]) >> 28)
                     + ((unsigned __int64)(ncha[2] * (__int64)v7[5]) >> 28)
                     + ((unsigned __int64)(ncha[4] * (__int64)v7[4]) >> 28)
                     + ((unsigned __int64)(ncha[6] * (__int64)v7[3]) >> 28)
                     + ((unsigned __int64)(ncha[8] * (__int64)v7[2]) >> 28)
                     + ((unsigned __int64)(ncha[10] * (__int64)v7[1]) >> 28)
                     + ((unsigned __int64)(*(ncha - 4) * (__int64)*v7) >> 28)
                     - ((unsigned __int64)(v17[22] * (__int64)v13[7]) >> 28)
                     - ((unsigned __int64)(v17[24] * (__int64)v13[6]) >> 28)
                     - ((unsigned __int64)(v17[26] * (__int64)v13[5]) >> 28)
                     - ((unsigned __int64)(v17[28] * (__int64)v13[4]) >> 28)
                     - v27
                     - v29
                     - v30
                     - v32;
            v41 = (unsigned __int64)(*(v16 - 2) * (__int64)*v7) >> 28;
            v39 = (unsigned __int64)(*v16 * (__int64)v7[1]) >> 28;
            v37 = (unsigned __int64)(v16[2] * (__int64)v7[2]) >> 28;
            v35 = (unsigned __int64)(v16[4] * (__int64)v7[3]) >> 28;
            v18 = v41
                + v39
                + v37
                + v35
                + ((unsigned __int64)(v16[6] * (__int64)v7[4]) >> 28)
                + ((unsigned __int64)(v16[8] * (__int64)v7[5]) >> 28)
                + ((unsigned __int64)(v16[10] * (__int64)v7[6]) >> 28)
                + ((unsigned __int64)(v16[12] * (__int64)v7[7]) >> 28)
                + ((unsigned __int64)(v14[2] * (__int64)v13[7]) >> 28)
                + ((unsigned __int64)(*v14 * (__int64)v13[6]) >> 28)
                + ((unsigned __int64)(*(v14 - 2) * (__int64)v13[5]) >> 28)
                + ((unsigned __int64)(*(v14 - 4) * (__int64)v13[4]) >> 28)
                + ((unsigned __int64)(*(v14 - 6) * (__int64)v13[3]) >> 28)
                + ((unsigned __int64)(*(v14 - 8) * (__int64)v13[2]) >> 28)
                + ((unsigned __int64)(*(v14 - 12) * (__int64)*v13) >> 28)
                + ((unsigned __int64)(*(v14 - 10) * (__int64)v13[1]) >> 28);
            v13 += 8;
            v19 = v44-- == 1;
            *pcm2-- = v18;
            if ( v19 )
              break;
            v17 += 32;
          }
          in += 32;
          v5 = v49;
          *pcm1a = -(((unsigned __int64)((int)D[16][po] * (__int64)*v13) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 14] * (__int64)v13[1]) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 12] * (__int64)v13[2]) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 10] * (__int64)v13[3]) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 8] * (__int64)v13[4]) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 6] * (__int64)v13[5]) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 2] * (__int64)v13[7]) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 4] * (__int64)v13[6]) >> 28));
          v19 = v43-- == 1;
          pcm1 = pcm1a + 16;
          phase = ((_BYTE)phase + 1) & 0xF;
          if ( v19 )
            break;
          v6 = phase;
          dct32(slot: v6 >> 1, hi: v49->filter[0][1][v6 & 1], in, lo: (int (*)[8])((int *)v49 + 16 * (v6 & 1)));
        }
        v4 = synth;
      }
      v48 += 1152;
      v47 += 1152;
      v5 = (mad_synth *)((char *)v5 + 2048);
      v19 = v42-- == 1;
      v49 = v5;
    }
    while ( !v19 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051C410
// Name: synth_half
// Source: json
//------------------------------------------------------------------------------
void __cdecl synth_half(mad_synth *synth, const mad_frame *frame, unsigned int nch, unsigned int ns)
{
  mad_synth *v4; // eax
  mad_synth *v5; // ebx
  unsigned int v6; // esi
  int *v7; // ecx
  int v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int *v12; // edi
  int *v13; // esi
  const int *v14; // ebx
  int v15; // eax
  const int *v16; // edi
  const int *v17; // eax
  bool v18; // zf
  unsigned int po; // [esp+0h] [ebp-74h]
  unsigned int v20; // [esp+10h] [ebp-64h]
  int v21; // [esp+18h] [ebp-5Ch]
  int v22; // [esp+1Ch] [ebp-58h]
  int v23; // [esp+20h] [ebp-54h]
  int v24; // [esp+24h] [ebp-50h]
  int v25; // [esp+28h] [ebp-4Ch]
  int v26; // [esp+28h] [ebp-4Ch]
  int v27; // [esp+2Ch] [ebp-48h]
  int v28; // [esp+30h] [ebp-44h]
  int v29; // [esp+34h] [ebp-40h]
  int v30; // [esp+38h] [ebp-3Ch]
  int v31; // [esp+3Ch] [ebp-38h]
  int v32; // [esp+40h] [ebp-34h]
  int v33; // [esp+44h] [ebp-30h]
  unsigned int v34; // [esp+48h] [ebp-2Ch]
  unsigned int v35; // [esp+4Ch] [ebp-28h]
  int *pcm2; // [esp+50h] [ebp-24h]
  int *v37; // [esp+54h] [ebp-20h]
  int *v38; // [esp+58h] [ebp-1Ch]
  mad_synth *v39; // [esp+5Ch] [ebp-18h]
  int *in; // [esp+60h] [ebp-14h]
  unsigned int phase; // [esp+64h] [ebp-10h]
  unsigned int sba; // [esp+68h] [ebp-Ch]
  unsigned int sb; // [esp+68h] [ebp-Ch]
  int *pcm1; // [esp+6Ch] [ebp-8h]
  int *pcm1a; // [esp+6Ch] [ebp-8h]
  const int *ncha; // [esp+84h] [ebp+10h]

  if ( nch != 0 )
  {
    v4 = synth;
    v37 = synth->pcm.samples[0];
    v5 = synth;
    v39 = synth;
    v38 = frame->sbsample[0][0];
    v34 = nch;
    do
    {
      v6 = v4->phase;
      pcm1 = v37;
      LOBYTE(phase) = v6;
      if ( ns != 0 )
      {
        in = v38;
        v35 = ns;
        dct32(
          slot: v4->phase >> 1,
          hi: v5->filter[0][1][v4->phase & 1],
          in: v38,
          lo: (int (*)[8])((int *)v5 + 16 * (v4->phase & 1)));
        while ( 1 )
        {
          sba = v6 & 0xFFFFFFFE;
          v7 = (int *)((char *)v5 + 512 * (v6 & 1));
          v8 = (v6 & 1) == 0;
          v9 = ((_BYTE)v6 - 1) & 0xE;
          v10 = v8 + 2;
          v8 <<= 9;
          v11 = *(int *)((char *)v5->filter[0][0][0][0] + v8);
          v12 = (int *)((char *)v5 + v8);
          v13 = (int *)((char *)v5 + 512 * v10);
          po = v9 | 1;
          v20 = sba;
          v21 = (unsigned __int64)((int)D[0][sba] * (__int64)*v7) >> 28;
          v22 = (unsigned __int64)((int)D[0][sba + 14] * (__int64)v7[1]) >> 28;
          v23 = (unsigned __int64)((int)D[0][sba + 12] * (__int64)v7[2]) >> 28;
          v24 = (unsigned __int64)((int)D[0][sba + 10] * (__int64)v7[3]) >> 28;
          v25 = (unsigned __int64)((int)D[0][sba + 8] * (__int64)v7[4]) >> 28;
          pcm1a = pcm1 + 1;
          pcm2 = pcm1a + 14;
          v14 = &D[0][-sba + 17];
          v15 = ((unsigned __int64)((int)D[0][sba + 6] * (__int64)v7[5]) >> 28)
              + ((unsigned __int64)((int)D[0][sba + 4] * (__int64)v7[6]) >> 28)
              + ((unsigned __int64)((int)D[0][sba + 2] * (__int64)v7[7]) >> 28)
              - ((unsigned __int64)((int)D[0][po + 2] * (__int64)v12[7]) >> 28)
              - ((unsigned __int64)((int)D[0][po + 4] * (__int64)v12[6]) >> 28)
              - ((unsigned __int64)((int)D[0][(v9 | 1) + 6] * (__int64)v12[5]) >> 28)
              - ((unsigned __int64)((int)D[0][(v9 | 1) + 8] * (__int64)v12[4]) >> 28)
              - ((unsigned __int64)((int)D[0][(v9 | 1) + 10] * (__int64)v12[3]) >> 28)
              - ((unsigned __int64)((int)D[0][(v9 | 1) + 12] * (__int64)v12[2]) >> 28)
              - ((unsigned __int64)((int)D[0][(v9 | 1) + 14] * (__int64)v12[1]) >> 28)
              - ((unsigned __int64)((int)D[0][v9 | 1] * (__int64)v11) >> 28);
          sb = 1;
          *(pcm1a - 1) = v21 + v22 + v23 + v24 + v25 + v15;
          v16 = &D[0][-po + 27];
          ncha = &D[0][v20 + 4];
          v17 = &D[0][po + 12];
          do
          {
            ncha += 32;
            v17 += 32;
            v7 += 8;
            v16 += 32;
            v14 += 32;
            if ( (sb & 1) == 0 )
            {
              v29 = (unsigned __int64)(*(v17 - 12) * (__int64)*v13) >> 28;
              v28 = (unsigned __int64)(v17[2] * (__int64)v13[1]) >> 28;
              v27 = (unsigned __int64)(*v17 * (__int64)v13[2]) >> 28;
              v26 = (unsigned __int64)(*(v17 - 2) * (__int64)v13[3]) >> 28;
              *pcm1a++ = ((unsigned __int64)(*(ncha - 2) * (__int64)v7[7]) >> 28)
                       + ((unsigned __int64)(*ncha * (__int64)v7[6]) >> 28)
                       + ((unsigned __int64)(ncha[2] * (__int64)v7[5]) >> 28)
                       + ((unsigned __int64)(ncha[4] * (__int64)v7[4]) >> 28)
                       + ((unsigned __int64)(ncha[6] * (__int64)v7[3]) >> 28)
                       + ((unsigned __int64)(ncha[8] * (__int64)v7[2]) >> 28)
                       + ((unsigned __int64)(ncha[10] * (__int64)v7[1]) >> 28)
                       + ((unsigned __int64)(*(ncha - 4) * (__int64)*v7) >> 28)
                       - ((unsigned __int64)(*(v17 - 10) * (__int64)v13[7]) >> 28)
                       - ((unsigned __int64)(*(v17 - 8) * (__int64)v13[6]) >> 28)
                       - ((unsigned __int64)(*(v17 - 6) * (__int64)v13[5]) >> 28)
                       - ((unsigned __int64)(*(v17 - 4) * (__int64)v13[4]) >> 28)
                       - v26
                       - v27
                       - v28
                       - v29;
              v33 = (unsigned __int64)(v16[2] * (__int64)v13[7]) >> 28;
              v32 = (unsigned __int64)(*v16 * (__int64)v13[6]) >> 28;
              v31 = (unsigned __int64)(*(v16 - 2) * (__int64)v13[5]) >> 28;
              v30 = (unsigned __int64)(*(v16 - 4) * (__int64)v13[4]) >> 28;
              *pcm2-- = v33
                      + v32
                      + v31
                      + v30
                      + ((unsigned __int64)(*(v16 - 6) * (__int64)v13[3]) >> 28)
                      + ((unsigned __int64)(*(v16 - 8) * (__int64)v13[2]) >> 28)
                      + ((unsigned __int64)(*(v16 - 10) * (__int64)v13[1]) >> 28)
                      + ((unsigned __int64)(*(v16 - 12) * (__int64)*v13) >> 28)
                      + ((unsigned __int64)(*(v14 - 2) * (__int64)*v7) >> 28)
                      + ((unsigned __int64)(*v14 * (__int64)v7[1]) >> 28)
                      + ((unsigned __int64)(v14[2] * (__int64)v7[2]) >> 28)
                      + ((unsigned __int64)(v14[4] * (__int64)v7[3]) >> 28)
                      + ((unsigned __int64)(v14[6] * (__int64)v7[4]) >> 28)
                      + ((unsigned __int64)(v14[8] * (__int64)v7[5]) >> 28)
                      + ((unsigned __int64)(v14[12] * (__int64)v7[7]) >> 28)
                      + ((unsigned __int64)(v14[10] * (__int64)v7[6]) >> 28);
            }
            ++sb;
            v13 += 8;
          }
          while ( sb < 0x10 );
          in += 32;
          v5 = v39;
          *pcm1a = -(((unsigned __int64)((int)D[16][po] * (__int64)*v13) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 14] * (__int64)v13[1]) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 12] * (__int64)v13[2]) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 10] * (__int64)v13[3]) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 8] * (__int64)v13[4]) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 6] * (__int64)v13[5]) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 2] * (__int64)v13[7]) >> 28)
                   + ((unsigned __int64)((int)D[16][po + 4] * (__int64)v13[6]) >> 28));
          v18 = v35-- == 1;
          pcm1 = pcm1a + 8;
          phase = ((_BYTE)phase + 1) & 0xF;
          if ( v18 )
            break;
          v6 = phase;
          dct32(slot: v6 >> 1, hi: v39->filter[0][1][v6 & 1], in, lo: (int (*)[8])((int *)v39 + 16 * (v6 & 1)));
        }
        v4 = synth;
      }
      v38 += 1152;
      v37 += 1152;
      v5 = (mad_synth *)((char *)v5 + 2048);
      v18 = v34-- == 1;
      v39 = v5;
    }
    while ( !v18 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051CC20
// Name: _mad_synth_frame
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_synth_frame(mad_synth *synth, const mad_frame *frame)
{
  int v2; // ebx
  unsigned int v3; // edi
  void (__cdecl *v4)(mad_synth *, const mad_frame *, unsigned int, unsigned int); // edx

  v2 = (frame->header.mode != MAD_MODE_SINGLE_CHANNEL) + 1;
  if ( frame->header.layer == MAD_LAYER_I )
  {
    v3 = 12;
  }
  else if ( frame->header.layer != MAD_LAYER_III || (v3 = 18, (frame->header.flags & 0x1000) == 0) )
  {
    v3 = 36;
  }
  synth->pcm.samplerate = frame->header.samplerate;
  synth->pcm.channels = v2;
  synth->pcm.length = 32 * v3;
  v4 = synth_full;
  if ( (frame->options & 2) != 0 )
  {
    synth->pcm.samplerate >>= 1;
    synth->pcm.length = (unsigned __int16)(32 * v3) >> 1;
    v4 = synth_half;
  }
  v4(synth, frame, nch: v2, ns: v3);
  synth->phase = ((_BYTE)v3 + (unsigned __int8)synth->phase) & 0xF;
}

//------------------------------------------------------------------------------
// Address: 0x0051CCC0
// Name: _mad_synth_init
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_synth_init(mad_synth *synth)
{
  mad_synth_mute(synth);
  synth->phase = 0;
  synth->pcm.samplerate = 0;
  *(_DWORD *)&synth->pcm.channels = 0;
}
