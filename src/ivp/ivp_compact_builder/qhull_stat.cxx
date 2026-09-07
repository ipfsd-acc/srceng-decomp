// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/qhull_stat.cxx
// Functions: 19
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1005BAE0
// Name: void qh_allstatA(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_allstatA()
{
  qh_qhstat.id[qh_qhstat.next++] = 57;
  qh_qhstat.doc[57] = "precision statistics";
  qh_qhstat.count[57] = -1;
  qh_qhstat.type[57] = 0;
  qh_qhstat.id[qh_qhstat.next++] = 125;
  qh_qhstat.count[125] = -1;
  qh_qhstat.doc[125] = nullptr;
  qh_qhstat.type[125] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 126;
  qh_qhstat.doc[126] = "ave. distance of a new vertex to a facet (not 0s)";
  qh_qhstat.type[126] = 6;
  qh_qhstat.count[126] = 125;
  qh_qhstat.id[qh_qhstat.next++] = 127;
  qh_qhstat.count[127] = -1;
  qh_qhstat.doc[127] = "max. distance of a new vertex to a facet";
  qh_qhstat.type[127] = 7;
  qh_qhstat.id[qh_qhstat.next++] = -74;
  qh_qhstat.count[182] = -1;
  qh_qhstat.doc[182] = "max. distance of an output vertex to a facet";
  qh_qhstat.type[182] = 7;
  qh_qhstat.id[qh_qhstat.next++] = -73;
  qh_qhstat.count[183] = -1;
  qh_qhstat.doc[183] = "min. distance of an output vertex to a facet";
  qh_qhstat.type[183] = 8;
  qh_qhstat.id[qh_qhstat.next++] = 115;
  qh_qhstat.precision = qh_qhstat.next;
  qh_qhstat.count[115] = -1;
  qh_qhstat.doc[115] = "min. denominator in hyperplane computation";
  qh_qhstat.type[115] = 8;
  qh_qhstat.id[qh_qhstat.next++] = 58;
  qh_qhstat.type[58] = 0;
  qh_qhstat.doc[58] = "precision problems";
  qh_qhstat.count[58] = -1;
  qh_qhstat.id[qh_qhstat.next++] = 33;
  qh_qhstat.doc[33] = "coplanar half ridges in output";
  qh_qhstat.count[33] = -1;
  qh_qhstat.type[33] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 23;
  qh_qhstat.count[23] = -1;
  qh_qhstat.doc[23] = "concave half ridges in output";
  qh_qhstat.type[23] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 79;
  qh_qhstat.count[79] = -1;
  qh_qhstat.doc[79] = "flipped facets";
  qh_qhstat.type[79] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 30;
  qh_qhstat.count[30] = -1;
  qh_qhstat.doc[30] = "coplanar horizon facets for new vertices";
  qh_qhstat.type[30] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 32;
  qh_qhstat.count[32] = -1;
  qh_qhstat.doc[32] = "coplanar points during partitioning";
  qh_qhstat.type[32] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 117;
  qh_qhstat.count[117] = -1;
  qh_qhstat.doc[117] = "degenerate hyperplanes recomputed with gaussian elimination";
  qh_qhstat.type[117] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 119;
  qh_qhstat.count[119] = -1;
  qh_qhstat.doc[119] = "nearly singular or axis-parallel hyperplanes";
  qh_qhstat.type[119] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 14;
  qh_qhstat.count[14] = -1;
  qh_qhstat.doc[14] = "zero divisors during back substitute";
  qh_qhstat.type[14] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 80;
  qh_qhstat.doc[80] = "zero divisors during gaussian elimination";
  qh_qhstat.count[80] = -1;
  qh_qhstat.type[80] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 118;
  qh_qhstat.doc[118] = "ridges with multiple neighbors";
  qh_qhstat.count[118] = -1;
  qh_qhstat.type[118] = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005BE30
// Name: void qh_allstatB(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_allstatB()
{
  qh_qhstat.id[qh_qhstat.next++] = 56;
  qh_qhstat.doc[56] = "summary information";
  qh_qhstat.count[56] = -1;
  qh_qhstat.type[56] = 0;
  qh_qhstat.id[qh_qhstat.next++] = -69;
  qh_qhstat.doc[187] = "number of vertices in output";
  qh_qhstat.count[187] = -1;
  qh_qhstat.type[187] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -124;
  qh_qhstat.count[132] = -1;
  qh_qhstat.doc[132] = "number of facets in output";
  qh_qhstat.type[132] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -120;
  qh_qhstat.id[qh_qhstat.next++] = -120;
  qh_qhstat.count[136] = 132;
  qh_qhstat.doc[136] = "average number of ridges per facet";
  qh_qhstat.type[136] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 95;
  qh_qhstat.count[95] = -1;
  qh_qhstat.doc[95] = "maximum number of ridges";
  qh_qhstat.type[95] = 3;
  qh_qhstat.id[qh_qhstat.next++] = -121;
  qh_qhstat.count[135] = 132;
  qh_qhstat.doc[135] = "average number of neighbors per facet";
  qh_qhstat.type[135] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 92;
  qh_qhstat.count[92] = -1;
  qh_qhstat.doc[92] = "maximum number of neighbors";
  qh_qhstat.type[92] = 3;
  qh_qhstat.id[qh_qhstat.next++] = -119;
  qh_qhstat.doc[137] = "average number of vertices per facet";
  qh_qhstat.count[137] = 132;
  qh_qhstat.type[137] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 97;
  qh_qhstat.doc[97] = "maximum number of vertices";
  qh_qhstat.type[97] = 3;
  qh_qhstat.count[97] = -1;
  qh_qhstat.id[qh_qhstat.next++] = -117;
  qh_qhstat.type[139] = 2;
  qh_qhstat.doc[139] = "average number of neighbors per vertex";
  qh_qhstat.count[139] = 187;
  qh_qhstat.id[qh_qhstat.next++] = 98;
  qh_qhstat.doc[98] = "maximum number of neighbors";
  qh_qhstat.count[98] = -1;
  qh_qhstat.type[98] = 3;
  qh_qhstat.id[qh_qhstat.next++] = 34;
  qh_qhstat.count[34] = -1;
  qh_qhstat.doc[34] = "cpu seconds for qhull after input";
  qh_qhstat.type[34] = 6;
  qh_qhstat.id[qh_qhstat.next++] = -76;
  qh_qhstat.count[180] = -1;
  qh_qhstat.doc[180] = "vertices created altogether";
  qh_qhstat.type[180] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -84;
  qh_qhstat.count[172] = -1;
  qh_qhstat.doc[172] = "facets created altogether";
  qh_qhstat.type[172] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -77;
  qh_qhstat.count[179] = -1;
  qh_qhstat.doc[179] = "ridges created altogether";
  qh_qhstat.type[179] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -107;
  qh_qhstat.count[149] = -1;
  qh_qhstat.doc[149] = "facets before post merge";
  qh_qhstat.type[149] = 1;
  qh_qhstat.id[qh_qhstat.next] = -122;
  qh_qhstat.type[134] = 2;
  ++qh_qhstat.next;
  qh_qhstat.doc[134] = "average merges per facet (at most 511)";
  qh_qhstat.count[134] = 132;
  qh_qhstat.id[qh_qhstat.next++] = -123;
  qh_qhstat.doc[133] = "  maximum merges for a facet (at most 511)";
  qh_qhstat.count[133] = -1;
  qh_qhstat.type[133] = 3;
  qh_qhstat.id[qh_qhstat.next++] = 3;
  qh_qhstat.type[3] = 1;
  qh_qhstat.doc[3] = nullptr;
  qh_qhstat.count[3] = -1;
  qh_qhstat.id[qh_qhstat.next] = 4;
  qh_qhstat.count[4] = 3;
  ++qh_qhstat.next;
  qh_qhstat.type[4] = 6;
  qh_qhstat.doc[4] = "average angle (cosine) for all ridges";
  qh_qhstat.id[qh_qhstat.next++] = 5;
  qh_qhstat.count[5] = -1;
  qh_qhstat.doc[5] = "  maximum angle (cosine) of a ridge";
  qh_qhstat.type[5] = 7;
  qh_qhstat.id[qh_qhstat.next++] = 6;
  qh_qhstat.count[6] = -1;
  qh_qhstat.doc[6] = "  minimum angle (cosine) of a ridge";
  qh_qhstat.type[6] = 8;
  qh_qhstat.id[qh_qhstat.next++] = 8;
  qh_qhstat.count[8] = -1;
  qh_qhstat.type[8] = 6;
  qh_qhstat.doc[8] = "total area of facets";
  qh_qhstat.id[qh_qhstat.next++] = 9;
  qh_qhstat.count[9] = -1;
  qh_qhstat.doc[9] = "  maximum facet area";
  qh_qhstat.type[9] = 7;
  qh_qhstat.id[qh_qhstat.next++] = 10;
  qh_qhstat.doc[10] = "  minimum facet area";
  qh_qhstat.count[10] = -1;
  qh_qhstat.type[10] = 8;
}

//------------------------------------------------------------------------------
// Address: 0x1005C2F0
// Name: void qh_allstatC(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_allstatC()
{
  qh_qhstat.id[qh_qhstat.next] = 64;
  qh_qhstat.count[64] = -1;
  ++qh_qhstat.next;
  qh_qhstat.doc[64] = "build hull statistics";
  qh_qhstat.type[64] = 0;
  qh_qhstat.id[qh_qhstat.next] = -105;
  qh_qhstat.count[151] = -1;
  ++qh_qhstat.next;
  qh_qhstat.doc[151] = "points processed";
  qh_qhstat.type[151] = 1;
  qh_qhstat.id[qh_qhstat.next] = -99;
  qh_qhstat.count[157] = -1;
  ++qh_qhstat.next;
  qh_qhstat.doc[157] = "retries due to precision problems";
  qh_qhstat.type[157] = 1;
  qh_qhstat.id[qh_qhstat.next] = -98;
  qh_qhstat.count[158] = -1;
  ++qh_qhstat.next;
  qh_qhstat.doc[158] = "  max. random joggle";
  qh_qhstat.type[158] = 7;
  qh_qhstat.id[qh_qhstat.next++] = 96;
  qh_qhstat.count[96] = -1;
  qh_qhstat.doc[96] = "max. vertices at any one time";
  qh_qhstat.type[96] = 3;
  qh_qhstat.id[qh_qhstat.next++] = -75;
  qh_qhstat.count[181] = 151;
  qh_qhstat.doc[181] = "ave. visible facets per iteration";
  qh_qhstat.type[181] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 86;
  qh_qhstat.count[86] = 151;
  qh_qhstat.doc[86] = "  ave. visible facets without an horizon neighbor";
  qh_qhstat.type[86] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -68;
  qh_qhstat.count[188] = 151;
  qh_qhstat.doc[188] = "  ave. facets deleted per iteration";
  qh_qhstat.type[188] = 2;
  qh_qhstat.id[qh_qhstat.next++] = -67;
  qh_qhstat.doc[189] = "    maximum";
  qh_qhstat.count[189] = -1;
  qh_qhstat.type[189] = 3;
  qh_qhstat.id[qh_qhstat.next++] = -66;
  qh_qhstat.doc[190] = "ave. visible vertices per iteration";
  qh_qhstat.type[190] = 2;
  qh_qhstat.count[190] = 151;
  qh_qhstat.id[qh_qhstat.next] = -65;
  qh_qhstat.doc[191] = "    maximum";
  ++qh_qhstat.next;
  qh_qhstat.type[191] = 3;
  qh_qhstat.count[191] = -1;
  qh_qhstat.id[qh_qhstat.next++] = 45;
  qh_qhstat.doc[45] = "  ave. vertices deleted per iteration";
  qh_qhstat.type[45] = 2;
  qh_qhstat.count[45] = 151;
  qh_qhstat.id[qh_qhstat.next] = 46;
  qh_qhstat.type[46] = 3;
  ++qh_qhstat.next;
  qh_qhstat.doc[46] = "    maximum vertices deleted";
  qh_qhstat.count[46] = -1;
  qh_qhstat.id[qh_qhstat.next++] = -81;
  qh_qhstat.count[175] = 151;
  qh_qhstat.doc[175] = "ave. horizon facets per iteration";
  qh_qhstat.type[175] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 123;
  qh_qhstat.count[123] = 151;
  qh_qhstat.doc[123] = "ave. new or merged facets per iteration";
  qh_qhstat.type[123] = 2;
  qh_qhstat.id[qh_qhstat.next] = 124;
  qh_qhstat.type[124] = 3;
  ++qh_qhstat.next;
  qh_qhstat.count[124] = -1;
  qh_qhstat.doc[124] = "    maximum (includes initial simplex)";
  qh_qhstat.id[qh_qhstat.next++] = 121;
  qh_qhstat.count[121] = 151;
  qh_qhstat.doc[121] = "average new facet balance";
  qh_qhstat.type[121] = 6;
  qh_qhstat.id[qh_qhstat.next++] = 122;
  qh_qhstat.count[122] = -1;
  qh_qhstat.doc[122] = "  standard deviation";
  qh_qhstat.type[122] = 6;
  qh_qhstat.id[qh_qhstat.next++] = -109;
  qh_qhstat.doc[147] = "average partition balance";
  qh_qhstat.count[147] = 146;
  qh_qhstat.type[147] = 6;
  qh_qhstat.id[qh_qhstat.next++] = -108;
  qh_qhstat.type[148] = 6;
  qh_qhstat.doc[148] = "  standard deviation";
  qh_qhstat.count[148] = -1;
  qh_qhstat.id[qh_qhstat.next++] = -110;
  qh_qhstat.count[146] = -1;
  qh_qhstat.doc[146] = "  number of trials";
  qh_qhstat.type[146] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -85;
  qh_qhstat.count[171] = -1;
  qh_qhstat.doc[171] = "searches of all points for initial simplex";
  qh_qhstat.type[171] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 47;
  qh_qhstat.count[47] = -1;
  qh_qhstat.doc[47] = "determinants computed (area & initial hull)";
  qh_qhstat.type[47] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 0x80;
  qh_qhstat.count[128] = -1;
  qh_qhstat.doc[128] = "determinants not computed because vertex too low";
  qh_qhstat.type[128] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -125;
  qh_qhstat.count[131] = -1;
  qh_qhstat.doc[131] = "points ignored (not above max_outside)";
  qh_qhstat.type[131] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -127;
  qh_qhstat.count[129] = -1;
  qh_qhstat.doc[129] = "points ignored (not above a good facet)";
  qh_qhstat.type[129] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -126;
  qh_qhstat.count[130] = -1;
  qh_qhstat.doc[130] = "points ignored (didn't create a good new facet)";
  qh_qhstat.type[130] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 81;
  qh_qhstat.count[81] = -1;
  qh_qhstat.doc[81] = "good facets found";
  qh_qhstat.type[81] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -118;
  qh_qhstat.doc[138] = "distance tests for facet visibility";
  qh_qhstat.count[138] = -1;
  qh_qhstat.type[138] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 54;
  qh_qhstat.count[54] = -1;
  qh_qhstat.doc[54] = "distance tests to report minimum vertex";
  qh_qhstat.type[54] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -82;
  qh_qhstat.doc[174] = "points checked for facets' outer planes";
  qh_qhstat.count[174] = -1;
  qh_qhstat.type[174] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 18;
  qh_qhstat.doc[18] = "  ave. distance tests per check";
  qh_qhstat.count[18] = 174;
  qh_qhstat.type[18] = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005C8C0
// Name: void qh_allstatD(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_allstatD()
{
  qh_qhstat.id[qh_qhstat.next++] = 59;
  qh_qhstat.count[59] = -1;
  qh_qhstat.doc[59] = "partitioning statistics";
  qh_qhstat.type[59] = 0;
  qh_qhstat.id[qh_qhstat.next++] = -114;
  qh_qhstat.count[142] = -1;
  qh_qhstat.doc[142] = "inside points";
  qh_qhstat.type[142] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -111;
  qh_qhstat.count[145] = -1;
  qh_qhstat.doc[145] = "  inside points kept with a facet";
  qh_qhstat.type[145] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 31;
  qh_qhstat.count[31] = -1;
  qh_qhstat.doc[31] = "  inside points that were coplanar with a facet";
  qh_qhstat.type[31] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 93;
  qh_qhstat.count[93] = -1;
  qh_qhstat.doc[93] = "difference in max_outside at final check";
  qh_qhstat.type[93] = 6;
  qh_qhstat.id[qh_qhstat.next++] = -112;
  qh_qhstat.count[144] = -1;
  qh_qhstat.doc[144] = "distance tests for initial partition";
  qh_qhstat.type[144] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -78;
  qh_qhstat.count[178] = -1;
  qh_qhstat.doc[178] = "partitions of a point";
  qh_qhstat.type[178] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -113;
  qh_qhstat.count[143] = -1;
  qh_qhstat.doc[143] = "distance tests for partitioning";
  qh_qhstat.type[143] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 48;
  qh_qhstat.count[48] = -1;
  qh_qhstat.doc[48] = "distance tests for checking flipped facets";
  qh_qhstat.type[48] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 49;
  qh_qhstat.doc[49] = "distance tests for checking convexity";
  qh_qhstat.count[49] = -1;
  qh_qhstat.type[49] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 50;
  qh_qhstat.count[50] = -1;
  qh_qhstat.doc[50] = "distance tests for checking good point";
  qh_qhstat.type[50] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 51;
  qh_qhstat.count[51] = -1;
  qh_qhstat.doc[51] = "distance tests for output";
  qh_qhstat.type[51] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 53;
  qh_qhstat.count[53] = -1;
  qh_qhstat.doc[53] = "distance tests for statistics";
  qh_qhstat.type[53] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 52;
  qh_qhstat.count[52] = -1;
  qh_qhstat.doc[52] = "total number of distance tests";
  qh_qhstat.type[52] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -79;
  qh_qhstat.count[177] = -1;
  qh_qhstat.doc[177] = "partitions of coplanar points or deleted vertices";
  qh_qhstat.type[177] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -115;
  qh_qhstat.doc[141] = "   distance tests for these partitions";
  qh_qhstat.count[141] = -1;
  qh_qhstat.type[141] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 19;
  qh_qhstat.doc[19] = "distance tests for computing furthest";
  qh_qhstat.count[19] = -1;
  qh_qhstat.type[19] = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005CBD0
// Name: void qh_allstatE(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_allstatE()
{
  qh_qhstat.id[qh_qhstat.next++] = 60;
  qh_qhstat.doc[60] = "statistics for matching ridges";
  qh_qhstat.count[60] = -1;
  qh_qhstat.type[60] = 0;
  qh_qhstat.id[qh_qhstat.next++] = 82;
  qh_qhstat.count[82] = -1;
  qh_qhstat.doc[82] = "total lookups for matching ridges of new facets";
  qh_qhstat.type[82] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 85;
  qh_qhstat.doc[85] = "average number of tests to match a ridge";
  qh_qhstat.type[85] = 1;
  qh_qhstat.count[85] = 82;
  qh_qhstat.id[qh_qhstat.next++] = 83;
  qh_qhstat.count[83] = -1;
  qh_qhstat.doc[83] = "total lookups of subridges (duplicates and boundary)";
  qh_qhstat.type[83] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 84;
  qh_qhstat.doc[84] = "average number of tests per subridge";
  qh_qhstat.type[84] = 1;
  qh_qhstat.count[84] = 83;
  qh_qhstat.id[qh_qhstat.next++] = 74;
  qh_qhstat.count[74] = -1;
  qh_qhstat.doc[74] = "duplicated ridges in same merge cycle";
  qh_qhstat.type[74] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 69;
  qh_qhstat.count[69] = -1;
  qh_qhstat.doc[69] = "duplicated ridges with flipped facets";
  qh_qhstat.type[69] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 61;
  qh_qhstat.type[61] = 0;
  qh_qhstat.doc[61] = "statistics for determining merges";
  qh_qhstat.count[61] = -1;
  qh_qhstat.id[qh_qhstat.next++] = 7;
  qh_qhstat.doc[7] = "angles computed for ridge convexity";
  qh_qhstat.count[7] = -1;
  qh_qhstat.type[7] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 15;
  qh_qhstat.doc[15] = "best merges used centrum instead of vertices";
  qh_qhstat.count[15] = -1;
  qh_qhstat.type[15] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 16;
  qh_qhstat.count[16] = -1;
  qh_qhstat.doc[16] = "distance tests for best merge";
  qh_qhstat.type[16] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 17;
  qh_qhstat.count[17] = -1;
  qh_qhstat.doc[17] = "distance tests for centrum convexity";
  qh_qhstat.type[17] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 55;
  qh_qhstat.count[55] = -1;
  qh_qhstat.doc[55] = "distance tests for checking simplicial convexity";
  qh_qhstat.type[55] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 28;
  qh_qhstat.count[28] = -1;
  qh_qhstat.doc[28] = "coplanar angles in getmergeset";
  qh_qhstat.type[28] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 29;
  qh_qhstat.doc[29] = "coplanar centrums in getmergeset";
  qh_qhstat.count[29] = -1;
  qh_qhstat.type[29] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 24;
  qh_qhstat.doc[24] = "concave ridges in getmergeset";
  qh_qhstat.count[24] = -1;
  qh_qhstat.type[24] = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005CEC0
// Name: void qh_allstatF(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_allstatF()
{
  qh_qhstat.id[qh_qhstat.next] = 62;
  qh_qhstat.count[62] = -1;
  ++qh_qhstat.next;
  qh_qhstat.doc[62] = "statistics for merging";
  qh_qhstat.type[62] = 0;
  qh_qhstat.id[qh_qhstat.next] = -106;
  qh_qhstat.count[150] = -1;
  qh_qhstat.doc[150] = "merge iterations";
  qh_qhstat.type[150] = 1;
  ++qh_qhstat.next;
  qh_qhstat.id[qh_qhstat.next++] = 105;
  qh_qhstat.doc[105] = "ave. initial non-convex ridges per iteration";
  qh_qhstat.count[105] = 150;
  qh_qhstat.type[105] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 106;
  qh_qhstat.count[106] = -1;
  qh_qhstat.doc[106] = "  maximum";
  qh_qhstat.type[106] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 110;
  qh_qhstat.doc[110] = "  ave. additional non-convex ridges per iteration";
  qh_qhstat.type[110] = 2;
  qh_qhstat.count[110] = 150;
  qh_qhstat.id[qh_qhstat.next++] = 111;
  qh_qhstat.count[111] = -1;
  qh_qhstat.doc[111] = "  maximum additional in one pass";
  qh_qhstat.type[111] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 107;
  qh_qhstat.count[107] = -1;
  qh_qhstat.doc[107] = "initial non-convex ridges for post merging";
  qh_qhstat.type[107] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 112;
  qh_qhstat.count[112] = -1;
  qh_qhstat.doc[112] = "  additional non-convex ridges";
  qh_qhstat.type[112] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 94;
  qh_qhstat.doc[94] = "max distance of vertex or coplanar point above facet (w/roundoff)";
  qh_qhstat.count[94] = -1;
  qh_qhstat.type[94] = 7;
  qh_qhstat.id[qh_qhstat.next++] = 116;
  qh_qhstat.doc[116] = "max distance of merged vertex below facet (or roundoff)";
  qh_qhstat.count[116] = -1;
  qh_qhstat.type[116] = 8;
  qh_qhstat.id[qh_qhstat.next++] = -64;
  qh_qhstat.count[192] = -1;
  qh_qhstat.doc[192] = "centrums frozen due to a wide merge";
  qh_qhstat.type[192] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -63;
  qh_qhstat.count[193] = -1;
  qh_qhstat.doc[193] = "centrums frozen due to extra vertices";
  qh_qhstat.type[193] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -80;
  qh_qhstat.count[176] = -1;
  qh_qhstat.doc[176] = "total number of facets or cycles of facets merged";
  qh_qhstat.type[176] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 113;
  qh_qhstat.count[113] = -1;
  qh_qhstat.doc[113] = "merged a simplex";
  qh_qhstat.type[113] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -116;
  qh_qhstat.count[140] = -1;
  qh_qhstat.doc[140] = "simplices merged into coplanar horizon";
  qh_qhstat.type[140] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 37;
  qh_qhstat.count[37] = -1;
  qh_qhstat.doc[37] = "cycles of facets merged into coplanar horizon";
  qh_qhstat.type[37] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 36;
  qh_qhstat.count[36] = 37;
  qh_qhstat.doc[36] = "  ave. facets per cycle";
  qh_qhstat.type[36] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 35;
  qh_qhstat.count[35] = -1;
  qh_qhstat.doc[35] = "  max. facets";
  qh_qhstat.type[35] = 3;
  qh_qhstat.id[qh_qhstat.next++] = 108;
  qh_qhstat.count[108] = -1;
  qh_qhstat.doc[108] = "new facets merged into horizon";
  qh_qhstat.type[108] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 109;
  qh_qhstat.doc[109] = "new facets merged";
  qh_qhstat.count[109] = -1;
  qh_qhstat.type[109] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 104;
  qh_qhstat.count[104] = -1;
  qh_qhstat.doc[104] = "horizon facets merged into new facets";
  qh_qhstat.type[104] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 114;
  qh_qhstat.count[114] = -1;
  qh_qhstat.doc[114] = "vertices deleted by merging";
  qh_qhstat.type[114] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 38;
  qh_qhstat.count[38] = -1;
  qh_qhstat.doc[38] = "vertices deleted by merging into coplanar horizon";
  qh_qhstat.type[38] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 42;
  qh_qhstat.count[42] = -1;
  qh_qhstat.doc[42] = "vertices deleted by degenerate facet";
  qh_qhstat.type[42] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 103;
  qh_qhstat.count[103] = -1;
  qh_qhstat.doc[103] = "merges due to flipped facets in duplicated ridge";
  qh_qhstat.type[103] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 120;
  qh_qhstat.count[120] = -1;
  qh_qhstat.doc[120] = "merges due to redundant neighbors";
  qh_qhstat.type[120] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -83;
  qh_qhstat.doc[173] = "non-convex vertex neighbors";
  qh_qhstat.count[173] = -1;
  qh_qhstat.type[173] = 2;
}

//------------------------------------------------------------------------------
// Address: 0x1005D3B0
// Name: void qh_allstatG(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_allstatG()
{
  qh_qhstat.id[qh_qhstat.next++] = 0;
  qh_qhstat.doc[0] = "merges due to angle coplanar facets";
  qh_qhstat.type[0] = 1;
  qh_qhstat.count[0] = -1;
  qh_qhstat.id[qh_qhstat.next++] = 2;
  qh_qhstat.doc[2] = "  average merge distance";
  qh_qhstat.count[2] = 0;
  qh_qhstat.type[2] = 6;
  qh_qhstat.id[qh_qhstat.next++] = 1;
  qh_qhstat.count[1] = -1;
  qh_qhstat.doc[1] = "  maximum merge distance";
  qh_qhstat.type[1] = 7;
  qh_qhstat.id[qh_qhstat.next++] = 25;
  qh_qhstat.count[25] = -1;
  qh_qhstat.doc[25] = "merges due to coplanar facets";
  qh_qhstat.type[25] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 27;
  qh_qhstat.count[27] = 25;
  qh_qhstat.doc[27] = "  average merge distance";
  qh_qhstat.type[27] = 6;
  qh_qhstat.id[qh_qhstat.next++] = 26;
  qh_qhstat.count[26] = -1;
  qh_qhstat.doc[26] = "  maximum merge distance";
  qh_qhstat.type[26] = 7;
  qh_qhstat.id[qh_qhstat.next++] = 20;
  qh_qhstat.count[20] = -1;
  qh_qhstat.doc[20] = "merges due to concave facets";
  qh_qhstat.type[20] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 22;
  qh_qhstat.count[22] = 20;
  qh_qhstat.doc[22] = "  average merge distance";
  qh_qhstat.type[22] = 6;
  qh_qhstat.id[qh_qhstat.next++] = 21;
  qh_qhstat.count[21] = -1;
  qh_qhstat.doc[21] = "  maximum merge distance";
  qh_qhstat.type[21] = 7;
  qh_qhstat.id[qh_qhstat.next++] = 11;
  qh_qhstat.doc[11] = "coplanar/concave merges due to avoiding old merge";
  qh_qhstat.count[11] = -1;
  qh_qhstat.type[11] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 13;
  qh_qhstat.doc[13] = "  average merge distance";
  qh_qhstat.type[13] = 6;
  qh_qhstat.count[13] = 11;
  qh_qhstat.id[qh_qhstat.next++] = 12;
  qh_qhstat.count[12] = -1;
  qh_qhstat.doc[12] = "  maximum merge distance";
  qh_qhstat.type[12] = 7;
  qh_qhstat.id[qh_qhstat.next++] = 39;
  qh_qhstat.count[39] = -1;
  qh_qhstat.doc[39] = "merges due to degenerate facets";
  qh_qhstat.type[39] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 41;
  qh_qhstat.doc[41] = "  average merge distance";
  qh_qhstat.type[41] = 6;
  qh_qhstat.count[41] = 39;
  qh_qhstat.id[qh_qhstat.next++] = 40;
  qh_qhstat.count[40] = -1;
  qh_qhstat.doc[40] = "  maximum merge distance";
  qh_qhstat.type[40] = 7;
  qh_qhstat.id[qh_qhstat.next++] = 76;
  qh_qhstat.count[76] = -1;
  qh_qhstat.doc[76] = "merges due to removing flipped facets";
  qh_qhstat.type[76] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 78;
  qh_qhstat.doc[78] = "  average merge distance";
  qh_qhstat.count[78] = 76;
  qh_qhstat.type[78] = 6;
  qh_qhstat.id[qh_qhstat.next++] = 77;
  qh_qhstat.count[77] = -1;
  qh_qhstat.doc[77] = "  maximum merge distance";
  qh_qhstat.type[77] = 7;
  qh_qhstat.id[qh_qhstat.next++] = 70;
  qh_qhstat.count[70] = -1;
  qh_qhstat.doc[70] = "merges due to duplicated ridges";
  qh_qhstat.type[70] = 1;
  qh_qhstat.id[qh_qhstat.next] = 72;
  qh_qhstat.doc[72] = "  average merge distance";
  ++qh_qhstat.next;
  qh_qhstat.count[72] = 70;
  qh_qhstat.type[72] = 6;
  qh_qhstat.id[qh_qhstat.next++] = 71;
  qh_qhstat.doc[71] = "  maximum merge distance";
  qh_qhstat.count[71] = -1;
  qh_qhstat.type[71] = 7;
}

//------------------------------------------------------------------------------
// Address: 0x1005D750
// Name: void qh_allstatH(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_allstatH()
{
  qh_qhstat.id[qh_qhstat.next++] = 63;
  qh_qhstat.count[63] = -1;
  qh_qhstat.doc[63] = "renamed vertex statistics";
  qh_qhstat.type[63] = 0;
  qh_qhstat.id[qh_qhstat.next++] = -100;
  qh_qhstat.count[156] = -1;
  qh_qhstat.doc[156] = "renamed vertices shared by two facets";
  qh_qhstat.type[156] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -101;
  qh_qhstat.count[155] = -1;
  qh_qhstat.doc[155] = "renamed vertices in a pinched facet";
  qh_qhstat.type[155] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -102;
  qh_qhstat.count[154] = -1;
  qh_qhstat.doc[154] = "renamed vertices shared by multiple facets";
  qh_qhstat.type[154] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 75;
  qh_qhstat.count[75] = -1;
  qh_qhstat.doc[75] = "rename failures due to duplicated ridges";
  qh_qhstat.type[75] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 73;
  qh_qhstat.count[73] = -1;
  qh_qhstat.doc[73] = "  duplicate ridges detected";
  qh_qhstat.type[73] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 44;
  qh_qhstat.count[44] = -1;
  qh_qhstat.doc[44] = "deleted ridges due to renamed vertices";
  qh_qhstat.type[44] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 68;
  qh_qhstat.count[68] = -1;
  qh_qhstat.doc[68] = "dropped neighbors due to renamed vertices";
  qh_qhstat.type[68] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 67;
  qh_qhstat.count[67] = -1;
  qh_qhstat.doc[67] = "degenerate facets due to dropped neighbors";
  qh_qhstat.type[67] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 43;
  qh_qhstat.doc[43] = "  facets deleted because of no neighbors";
  qh_qhstat.count[43] = -1;
  qh_qhstat.type[43] = 1;
  qh_qhstat.id[qh_qhstat.next] = -104;
  qh_qhstat.count[152] = -1;
  ++qh_qhstat.next;
  qh_qhstat.doc[152] = "vertices removed from facets due to no ridges";
  qh_qhstat.type[152] = 1;
  qh_qhstat.id[qh_qhstat.next] = -103;
  qh_qhstat.count[153] = -1;
  ++qh_qhstat.next;
  qh_qhstat.doc[153] = "  deleted";
  qh_qhstat.type[153] = 1;
  qh_qhstat.id[qh_qhstat.next] = 90;
  qh_qhstat.count[90] = -1;
  ++qh_qhstat.next;
  qh_qhstat.doc[90] = "vertex intersections for locating redundant vertices";
  qh_qhstat.type[90] = 1;
  qh_qhstat.id[qh_qhstat.next] = 88;
  qh_qhstat.count[88] = -1;
  ++qh_qhstat.next;
  qh_qhstat.doc[88] = "intersections failed to find a redundant vertex";
  qh_qhstat.type[88] = 1;
  qh_qhstat.id[qh_qhstat.next] = 87;
  qh_qhstat.count[87] = -1;
  ++qh_qhstat.next;
  qh_qhstat.doc[87] = "intersections found redundant vertices";
  qh_qhstat.type[87] = 1;
  qh_qhstat.id[qh_qhstat.next++] = 91;
  qh_qhstat.count[91] = 87;
  qh_qhstat.doc[91] = "   ave. number found per vertex";
  qh_qhstat.type[91] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 89;
  qh_qhstat.count[89] = -1;
  qh_qhstat.doc[89] = "   max. found for a vertex";
  qh_qhstat.type[89] = 3;
  qh_qhstat.id[qh_qhstat.next++] = -72;
  qh_qhstat.count[184] = -1;
  qh_qhstat.doc[184] = nullptr;
  qh_qhstat.type[184] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -71;
  qh_qhstat.count[185] = 184;
  qh_qhstat.doc[185] = "  ave. number of ridges per tested vertex";
  qh_qhstat.type[185] = 2;
  qh_qhstat.id[qh_qhstat.next++] = -70;
  qh_qhstat.doc[186] = "  max. number of ridges per tested vertex";
  qh_qhstat.count[186] = -1;
  qh_qhstat.type[186] = 3;
  qh_qhstat.id[qh_qhstat.next++] = 65;
  qh_qhstat.count[65] = -1;
  qh_qhstat.doc[65] = "memory usage statistics (in bytes)";
  qh_qhstat.type[65] = 0;
  qh_qhstat.id[qh_qhstat.next++] = 99;
  qh_qhstat.count[99] = -1;
  qh_qhstat.doc[99] = "for facets and their normals, neighbor and vertex sets";
  qh_qhstat.type[99] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 102;
  qh_qhstat.count[102] = -1;
  qh_qhstat.doc[102] = "for vertices and their neighbor sets";
  qh_qhstat.type[102] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 100;
  qh_qhstat.count[100] = -1;
  qh_qhstat.doc[100] = "for input points and outside and coplanar sets";
  qh_qhstat.type[100] = 2;
  qh_qhstat.id[qh_qhstat.next++] = 101;
  qh_qhstat.doc[101] = "for ridges and their vertex sets";
  qh_qhstat.count[101] = -1;
  qh_qhstat.type[101] = 2;
}

//------------------------------------------------------------------------------
// Address: 0x1005DBE0
// Name: void qh_allstatI(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_allstatI()
{
  qh_qhstat.vridges = qh_qhstat.next;
  qh_qhstat.id[qh_qhstat.next] = 66;
  qh_qhstat.doc[66] = "Voronoi ridge statistics";
  qh_qhstat.type[66] = 0;
  ++qh_qhstat.next;
  qh_qhstat.count[66] = -1;
  qh_qhstat.id[qh_qhstat.next++] = -97;
  qh_qhstat.doc[159] = "non-simplicial Voronoi vertices for all ridges";
  qh_qhstat.count[159] = -1;
  qh_qhstat.type[159] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -96;
  qh_qhstat.doc[160] = "  ave. distance to ridge";
  qh_qhstat.type[160] = 6;
  qh_qhstat.count[160] = 159;
  qh_qhstat.id[qh_qhstat.next++] = -95;
  qh_qhstat.count[161] = -1;
  qh_qhstat.doc[161] = "  max. distance to ridge";
  qh_qhstat.type[161] = 7;
  qh_qhstat.id[qh_qhstat.next++] = -91;
  qh_qhstat.count[165] = -1;
  qh_qhstat.doc[165] = "bounded ridges";
  qh_qhstat.type[165] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -90;
  qh_qhstat.doc[166] = "  ave. distance of midpoint to ridge";
  qh_qhstat.count[166] = 165;
  qh_qhstat.type[166] = 6;
  qh_qhstat.id[qh_qhstat.next++] = -89;
  qh_qhstat.count[167] = -1;
  qh_qhstat.doc[167] = "  max. distance of midpoint to ridge";
  qh_qhstat.type[167] = 7;
  qh_qhstat.id[qh_qhstat.next++] = -88;
  qh_qhstat.count[168] = -1;
  qh_qhstat.doc[168] = "bounded ridges with ok normal";
  qh_qhstat.type[168] = 1;
  qh_qhstat.id[qh_qhstat.next++] = -87;
  qh_qhstat.doc[169] = "  ave. angle to ridge";
  qh_qhstat.count[169] = 168;
  qh_qhstat.type[169] = 6;
  qh_qhstat.id[qh_qhstat.next++] = -86;
  qh_qhstat.count[170] = -1;
  qh_qhstat.doc[170] = "  max. angle to ridge";
  qh_qhstat.type[170] = 7;
  qh_qhstat.id[qh_qhstat.next++] = -94;
  qh_qhstat.count[162] = -1;
  qh_qhstat.type[162] = 1;
  qh_qhstat.doc[162] = "bounded ridges with near-zero normal";
  qh_qhstat.id[qh_qhstat.next++] = -93;
  qh_qhstat.count[163] = 162;
  qh_qhstat.type[163] = 6;
  qh_qhstat.doc[163] = "  ave. angle to ridge";
  qh_qhstat.id[qh_qhstat.next++] = -92;
  qh_qhstat.doc[164] = "  max. angle to ridge";
  qh_qhstat.count[164] = -1;
  qh_qhstat.type[164] = 7;
}

//------------------------------------------------------------------------------
// Address: 0x1005DE40
// Name: void qh_allstatistics(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_allstatistics()
{
  int i; // eax

  for ( i = 194; i != 0; qh_qhstat.printed[i] = 0 )
    --i;
}

//------------------------------------------------------------------------------
// Address: 0x1005DE60
// Name: void qh_collectstatistics(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_collectstatistics()
{
  facetT *facet_list; // eax
  facetT *next; // ecx
  facetT *v2; // ecx
  facetT *v3; // edx
  facetT *i; // esi
  int v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  setT *neighbors; // eax
  setelemT *e; // edi
  setelemT v11; // eax
  long double *normal; // ecx
  long double *v13; // eax
  setT *vertices; // edi
  setelemT v15; // eax
  setelemT *v16; // edi
  vertexT *vertex_list; // esi
  int v18; // eax
  long double dist; // [esp+0h] [ebp-10h] BYREF
  double dotproduct; // [esp+8h] [ebp-8h]

  qh_qh.old_randomdist = qh_qh.RANDOMdist;
  qh_qh.RANDOMdist = 0;
  qh_qhstat.stats[100].i = qh_qh.num_points * qh_qh.normal_size + 5792;
  qh_qhstat.stats[99].i = 0;
  qh_qhstat.stats[101].i = 0;
  qh_qhstat.stats[102].i = 0;
  qh_qhstat.stats[3].i = 0;
  qh_qhstat.stats[4].r = 0.0;
  qh_qhstat.stats[136].i = 0;
  qh_qhstat.stats[132].i = 0;
  qh_qhstat.stats[135].i = 0;
  qh_qhstat.stats[137].i = 0;
  qh_qhstat.stats[139].i = 0;
  qh_qhstat.stats[134].i = 0;
  qh_qhstat.stats[133].i = 0;
  qh_qhstat.stats[187].i = qh_qh.num_vertices - qh_setsize(set: qh_qh.del_vertices);
  if ( qh_qh.MERGING != 0 || qh_qh.APPROXhull != 0 || qh_qh.JOGGLEmax < 8.988465674311579e307 )
  {
    if ( qh_qh.max_outside > qh_qhstat.stats[94].r )
      qh_qhstat.stats[94].r = qh_qh.max_outside;
    if ( qh_qh.MERGING != 0 && qh_qhstat.stats[116].r > qh_qh.min_vertex )
      qh_qhstat.stats[116].r = qh_qh.min_vertex;
  }
  facet_list = qh_qh.facet_list;
  if ( qh_qh.facet_list != nullptr )
  {
    while ( 1 )
    {
      next = facet_list->next;
      if ( next == nullptr )
        break;
      *((_DWORD *)facet_list + 20) &= ~0x2000u;
      facet_list = next;
    }
  }
  if ( qh_qh.DELAUNAY != 0 )
  {
    v2 = qh_qh.facet_list;
    if ( qh_qh.facet_list != nullptr )
    {
      while ( 1 )
      {
        v3 = v2->next;
        if ( v3 == nullptr )
          break;
        if ( ((*((_DWORD *)v2 + 20) & 0x10000) != 0) != qh_qh.UPPERdelaunay )
          *((_DWORD *)v2 + 20) |= 0x2000u;
        v2 = v3;
      }
    }
  }
  for ( i = qh_qh.facet_list; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    if ( (*((_DWORD *)i + 20) & 0x400) == 0 || qh_qh.NEWfacets == 0 )
    {
      v5 = qh_setsize(set: i->vertices);
      v6 = qh_setsize(set: i->neighbors);
      v7 = qh_setsize(set: i->ridges);
      ++qh_qhstat.stats[132].i;
      qh_qhstat.stats[137].i += v5;
      if ( qh_qhstat.stats[97].i < v5 )
        qh_qhstat.stats[97].i = v5;
      qh_qhstat.stats[135].i += v6;
      if ( qh_qhstat.stats[92].i < v6 )
        qh_qhstat.stats[92].i = v6;
      qh_qhstat.stats[134].i += *((_DWORD *)i + 20) & 0x1FF;
      if ( qh_qhstat.stats[133].i < (*((_DWORD *)i + 20) & 0x1FF) )
        qh_qhstat.stats[133].i = *((_DWORD *)i + 20) & 0x1FF;
      if ( v7 != 0 )
      {
        qh_qhstat.stats[136].i += v7;
        if ( qh_qhstat.stats[95].i < v7 )
          qh_qhstat.stats[95].i = v7;
      }
      qh_qhstat.stats[99].i += qh_qh.normal_size + 4 * (v5 + v6) + 104;
      if ( i->ridges != nullptr )
        qh_qhstat.stats[101].i += ((unsigned int)(4 * v7 * (qh_qh.hull_dim + 5)) >> 1) + 4 * v7 + 8;
      if ( i->outsideset != nullptr )
        qh_qhstat.stats[100].i += 4 * qh_setsize(set: i->outsideset) + 8;
      if ( i->coplanarset != nullptr )
        qh_qhstat.stats[100].i += 4 * qh_setsize(set: i->coplanarset) + 8;
      v8 = *((_DWORD *)i + 20);
      if ( (v8 & 0x2000) == 0 )
      {
        *((_DWORD *)i + 20) = v8 | 0x2000;
        neighbors = i->neighbors;
        if ( neighbors != nullptr )
        {
          e = neighbors->e;
          v11.p = (void *)neighbors->e[0];
          if ( v11.i != 0 )
          {
            do
            {
              ++e;
              if ( v11.i != 1 && v11.i != 2 && (*(_DWORD *)(v11.i + 80) & 0x2000) == 0 )
              {
                normal = i->normal;
                if ( normal != nullptr )
                {
                  v13 = *(long double **)(v11.i + 24);
                  if ( v13 != nullptr )
                  {
                    dotproduct = qh_getangle(vect1: normal, vect2: v13);
                    ++qh_qhstat.stats[3].i;
                    qh_qhstat.stats[4].r = qh_qhstat.stats[4].r + dotproduct;
                    if ( dotproduct > qh_qhstat.stats[5].r )
                      qh_qhstat.stats[5].r = dotproduct;
                    if ( qh_qhstat.stats[6].r > dotproduct )
                      qh_qhstat.stats[6].r = dotproduct;
                  }
                }
              }
              v11.p = e->p;
            }
            while ( e->i != 0 );
          }
        }
        if ( i->normal != nullptr )
        {
          vertices = i->vertices;
          if ( vertices != nullptr )
          {
            v15.p = (void *)vertices->e[0];
            v16 = vertices->e;
            if ( v15.i != 0 )
            {
              do
              {
                ++qh_qhstat.stats[53].i;
                ++v16;
                qh_distplane(point: *(long double **)(v15.i + 8), facet: i, &dist);
                if ( dist > qh_qhstat.stats[182].r )
                  qh_qhstat.stats[182].r = dist;
                if ( qh_qhstat.stats[183].r > dist )
                  qh_qhstat.stats[183].r = dist;
                v15.p = v16->p;
              }
              while ( v16->i != 0 );
            }
          }
        }
      }
    }
  }
  vertex_list = qh_qh.vertex_list;
  if ( qh_qh.vertex_list != nullptr )
  {
    while ( vertex_list->next != nullptr )
    {
      if ( (*((_DWORD *)vertex_list + 5) & 0x8000000) == 0 )
      {
        qh_qhstat.stats[102].i += 24;
        if ( vertex_list->neighbors != nullptr )
        {
          v18 = qh_setsize(set: vertex_list->neighbors);
          qh_qhstat.stats[139].i += v18;
          if ( qh_qhstat.stats[98].i < v18 )
            qh_qhstat.stats[98].i = v18;
          qh_qhstat.stats[102].i += 4 * v18 + 24;
        }
      }
      vertex_list = vertex_list->next;
      if ( vertex_list == nullptr )
      {
        qh_qh.RANDOMdist = qh_qh.old_randomdist;
        return;
      }
    }
    qh_qh.RANDOMdist = qh_qh.old_randomdist;
  }
  else
  {
    qh_qh.RANDOMdist = qh_qh.old_randomdist;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E2B0
// Name: void qh_initstatistics(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_initstatistics()
{
  int i; // eax
  unsigned __int8 v1; // cl
  unsigned __int8 v2; // cl

  qh_qhstat.next = 0;
  qh_allstatA();
  qh_allstatB();
  qh_allstatC();
  qh_allstatD();
  qh_allstatE();
  qh_allstatF();
  qh_allstatG();
  qh_allstatH();
  qh_allstatI();
  if ( qh_qhstat.next > 204 )
  {
    ivp_message(
      templat: "qhull error (qh_initstatistics): increase size of qhstat.id[].\n"
      "      qhstat.next %d should be <= sizeof(qhstat id) %d\n",
      qh_qhstat.next,
      204);
    exit(code: 1);
  }
  qh_qhstat.init[6].r = 0.0;
  qh_qhstat.init[8].r = 1.797693134862316e308;
  qh_qhstat.init[1].i = 0;
  qh_qhstat.init[2].i = 0;
  qh_qhstat.init[4].i = 0x7FFFFFFF;
  qh_qhstat.init[3].i = 0x80000000;
  qh_qhstat.init[7].r = -1.797693134862316e308;
  for ( i = 0; i < 194; i += 2 )
  {
    v1 = qh_qhstat.type[i];
    if ( (char)v1 <= 5 )
    {
      if ( v1 != 0 )
        qh_qhstat.stats[i].i = qh_qhstat.init[v1].i;
    }
    else
    {
      qh_qhstat.stats[i].r = qh_qhstat.init[v1].r;
    }
    v2 = qh_qhstat.type[i + 1];
    if ( (char)v2 <= 5 )
    {
      if ( v2 != 0 )
        *(_DWORD *)&qh_qhstat.id[8 * i - 1544] = qh_qhstat.init[v2].i;
    }
    else
    {
      *(double *)&qh_qhstat.id[8 * i - 1544] = qh_qhstat.init[v2].r;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E3E0
// Name: unsigned int qh_nostatistic(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl qh_nostatistic(int i)
{
  unsigned __int8 v1; // cl
  bool v2; // cc

  v1 = qh_qhstat.type[i];
  v2 = (char)v1 < 5;
  if ( (char)v1 > 5 )
  {
    if ( qh_qhstat.stats[i].r == qh_qhstat.init[v1].r )
      return true;
    v2 = (char)v1 < 5;
  }
  return v2 && qh_qhstat.stats[i].i == qh_qhstat.init[v1].i;
}

//------------------------------------------------------------------------------
// Address: 0x1005E430
// Name: void qh_printstatlevel(struct _iobuf __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printstatlevel(_iobuf *fp, int id)
{
  __int16 v2; // ax

  if ( id < 194 && qh_qhstat.printed[id] == 0 )
  {
    if ( qh_qhstat.type[id] != 0 )
    {
      if ( !qh_nostatistic(i: id) && qh_qhstat.doc[id] != nullptr )
      {
        qh_qhstat.printed[id] = 1;
        v2 = qh_qhstat.count[id];
        if ( v2 == -1 || qh_qhstat.stats[LOBYTE(qh_qhstat.count[id])].i != 0 )
        {
          if ( qh_qhstat.type[id] < 5 )
          {
            if ( v2 == -1 )
              fprintf(str: fp, format: "%7d", qh_qhstat.stats[id].i);
            else
              fprintf(
                str: fp,
                format: "%7.3g",
                (double)qh_qhstat.stats[id].i / (double)qh_qhstat.stats[LOBYTE(qh_qhstat.count[id])].i);
          }
          else if ( v2 == -1 )
          {
            fprintf(str: fp, format: "%7.2g", (double)qh_qhstat.stats[id].r);
          }
          else
          {
            fprintf(
              str: fp,
              format: "%7.2g",
              (double)qh_qhstat.stats[id].r / (double)qh_qhstat.stats[LOBYTE(qh_qhstat.count[id])].i);
          }
        }
        else
        {
          fprintf(str: fp, format: " *0 cnt*");
        }
        fprintf(str: fp, format: " %s\n", qh_qhstat.doc[id]);
      }
    }
    else
    {
      fprintf(str: fp, format: "%s\n", qh_qhstat.doc[id]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E5C0
// Name: double qh_stddev(int,double,double,double __near *)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl qh_stddev(int num, long double tot, long double tot2, long double *ave)
{
  double v5; // [esp+0h] [ebp-8h]
  long double tota; // [esp+14h] [ebp+Ch]

  v5 = 1.0 / (double)num;
  tota = v5 * tot;
  *ave = tota;
  return sqrt(v5 * tot2 - tota * tota);
}

//------------------------------------------------------------------------------
// Address: 0x1005E610
// Name: unsigned int qh_newstats(int,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_newstats(int index, int *nextindex)
{
  int v2; // esi
  int v3; // ebx
  int v4; // edi

  v2 = index;
  v3 = 0;
  if ( qh_qhstat.type[qh_qhstat.id[index]] == 0 )
    v2 = index + 1;
  if ( v2 >= qh_qhstat.next )
  {
    *nextindex = v2;
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = qh_qhstat.id[v2];
      if ( qh_qhstat.type[v4] == 0 )
        break;
      if ( !qh_nostatistic(i: qh_qhstat.id[v2]) && qh_qhstat.printed[v4] == 0 )
        v3 = 1;
      if ( ++v2 >= qh_qhstat.next )
      {
        *nextindex = v2;
        return v3;
      }
    }
    *nextindex = v2;
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E6A0
// Name: void qh_printstats(struct _iobuf __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printstats(_iobuf *fp, int index, int *nextindex)
{
  int v3; // esi
  int v4; // eax
  int v5; // edi
  int nexti; // [esp+8h] [ebp-4h] BYREF

  v3 = index;
  nexti = 0;
  v4 = qh_newstats(index, nextindex: &nexti);
  v5 = nexti;
  if ( v4 != 0 )
  {
    fprintf(str: fp, format: "\n");
    if ( index < v5 )
    {
      do
        qh_printstatlevel(fp, id: qh_qhstat.id[v3++]);
      while ( v3 < v5 );
    }
  }
  if ( nextindex != nullptr )
    *nextindex = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1005E710
// Name: void qh_printstatistics(struct _iobuf __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printstatistics(_iobuf *fp, const char *string)
{
  _iobuf *v2; // esi
  int i; // edi
  _iobuf *v4; // eax
  long double ave; // [esp+3Ch] [ebp-8h] BYREF

  v2 = fp;
  if ( fp != nullptr )
  {
    if ( qh_qh.num_points == qh_qh.num_vertices )
    {
      qh_qhstat.stats[148].r = qh_stddev(
                                 num: qh_qhstat.stats[146].i,
                                 tot: qh_qhstat.stats[147].r,
                                 tot2: qh_qhstat.stats[148].r,
                                 &ave);
    }
    else
    {
      qh_qhstat.stats[147].r = 0.0;
      qh_qhstat.stats[148].r = 0.0;
    }
    qh_qhstat.stats[122].r = qh_stddev(
                               num: qh_qhstat.stats[151].i,
                               tot: qh_qhstat.stats[121].r,
                               tot2: qh_qhstat.stats[122].r,
                               &ave);
    fprintf(
      str: v2,
      format: "\n%s\n qhull invoked by: %s | %s\n%s with options:\n%s\n",
      string,
      qh_qh.rbox_command,
      qh_qh.qhull_command,
      qh_version,
      qh_qh.qhull_options);
    fprintf(
      str: v2,
      format: "\n"
      "precision constants:\n"
      " %6.2g max. abs. coordinate in the (transformed) input ('Qbd:n')\n"
      " %6.2g max. roundoff error for distance computation ('En')\n"
      " %6.2g max. roundoff error for angle computations\n"
      " %6.2g min. distance for outside points ('Wn')\n"
      " %6.2g min. distance for visible facets ('Vn')\n"
      " %6.2g max. distance for coplanar facets ('Un')\n"
      " %6.2g max. facet width for recomputing centrum and area\n",
      (double)qh_qh.MAXabs_coord,
      (double)qh_qh.DISTround,
      (double)qh_qh.ANGLEround,
      (double)qh_qh.MINoutside,
      (double)qh_qh.MINvisible,
      (double)qh_qh.MAXcoplanar,
      (double)qh_qh.WIDEfacet);
    if ( qh_qh.KEEPnearinside != 0 )
      fprintf(str: v2, format: " %6.2g max. distance for near-inside points\n", (double)qh_qh.NEARinside);
    if ( qh_qh.premerge_cos < 8.988465674311579e307 )
      fprintf(str: v2, format: " %6.2g max. cosine for pre-merge angle\n", (double)qh_qh.premerge_cos);
    if ( qh_qh.PREmerge != 0 )
      fprintf(str: v2, format: " %6.2g radius of pre-merge centrum\n", (double)qh_qh.premerge_centrum);
    if ( qh_qh.postmerge_cos < 8.988465674311579e307 )
      fprintf(str: v2, format: " %6.2g max. cosine for post-merge angle\n", (double)qh_qh.postmerge_cos);
    if ( qh_qh.POSTmerge != 0 )
      fprintf(str: v2, format: " %6.2g radius of post-merge centrum\n", (double)qh_qh.postmerge_centrum);
    fprintf(
      str: v2,
      format: " %6.2g max. distance for merging two simplicial facets\n"
      " %6.2g max. roundoff error for arithmetic operations\n"
      " %6.2g min. denominator for divisions\n"
      "  zero diagonal for Gauss: ",
      (double)qh_qh.ONEmerge,
      2.220446049250313e-16,
      (double)qh_qh.MINdenom);
    for ( i = 0; i < qh_qh.hull_dim; ++i )
      fprintf(str: v2, format: "%6.2e ", (double)qh_qh.NEARzero[i]);
    fprintf(str: v2, format: "\n\n");
    v4 = nullptr;
    for ( fp = nullptr; (int)fp < qh_qhstat.next; v4 = fp )
      qh_printstats(fp: v2, index: (int)v4, nextindex: (int *)&fp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E9D0
// Name: void qh_printallstatistics(struct _iobuf __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printallstatistics(_iobuf *fp, const char *string)
{
  qh_allstatistics();
  qh_collectstatistics();
  qh_printstatistics(fp, string);
  qh_memstatistics(fp);
}
