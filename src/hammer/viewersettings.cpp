// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/viewersettings.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100BA910
// Name: _InitViewerSettings
// Source: json
//------------------------------------------------------------------------------
void InitViewerSettings()
{
  memset(dst: (unsigned __int8 *)&g_viewerSettings, value: 0, count: sizeof(g_viewerSettings));
  g_viewerSettings.rot[0] = -90.0;
  g_viewerSettings.gColor[0] = 0.85000002;
  g_viewerSettings.gColor[1] = 0.85000002;
  g_viewerSettings.renderMode = 3;
  g_viewerSettings.transparency = 1.0;
  g_viewerSettings.gColor[2] = 0.69;
  g_viewerSettings.lColor[0] = 1.0;
  g_viewerSettings.lColor[1] = 1.0;
  g_viewerSettings.lColor[2] = 1.0;
  g_viewerSettings.speedScale = 1.0;
  g_viewerSettings.textureLimit = 256;
  g_viewerSettings.textureScale = 1.0;
}
