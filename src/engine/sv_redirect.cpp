// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_redirect.cpp
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1012CD00
// Name: void SV_RedirectFlush(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_RedirectFlush()
{
  CRConServer *v0; // eax

  bInFlush = true;
  if ( sv_redirected == RD_PACKET )
  {
    NET_OutOfBandPrintf(sock: sv.m_Socket, adr: &sv_redirectto, format: "%c%s", 108, sv_redirect_buffer);
    bInFlush = false;
    sv_redirect_buffer[0] = 0;
  }
  else if ( sv_redirected == RD_CLIENT )
  {
    host_client->ClientPrintf(this: &host_client->IClient, a2: "%s", sv_redirect_buffer);
    bInFlush = false;
    sv_redirect_buffer[0] = 0;
  }
  else
  {
    if ( sv_redirected == RD_SOCKET )
    {
      v0 = RCONServer();
      CRConServer::FinishRedirect(this: v0, msg: sv_redirect_buffer, adr: &sv_redirectto);
    }
    bInFlush = false;
    sv_redirect_buffer[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012CDA0
// Name: void SV_RedirectStart(enum redirect_t,struct netadr_s const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_RedirectStart(redirect_t rd, const netadr_s *addr)
{
  sv_redirected = rd;
  sv_redirectto = *addr;
  sv_redirect_buffer[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012CDD0
// Name: void SV_RedirectEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_RedirectEnd()
{
  SV_RedirectFlush();
  sv_redirected = RD_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x1012CDE0
// Name: bool SV_RedirectActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SV_RedirectActive()
{
  return sv_redirected != RD_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x1012CDF0
// Name: void SV_RedirectAddText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_RedirectAddText(const char *txt)
{
  if ( strlen(txt) + _V_strlen(str: sv_redirect_buffer) > 0xFFF )
    SV_RedirectFlush();
  V_strncat(pDest: sv_redirect_buffer, pSrc: txt, destBufferSize: 0x1000u, max_chars_to_copy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1012CE40
// Name: __CreateCServerRemoteAccessIGameServerData_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerRemoteAccess *__cdecl _CreateCServerRemoteAccessIGameServerData_interface()
{
  return &g_ServerRemoteAccess;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1012CE70
// Name: void SV_RedirectFlush(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_RedirectFlush()
{
  CRConServer *v0; // eax

  bInFlush = true;
  if ( sv_redirected == RD_PACKET )
  {
    NET_OutOfBandPrintf(sock: sv.m_Socket, adr: &sv_redirectto, format: "%c%s", 108, sv_redirect_buffer);
    bInFlush = false;
    sv_redirect_buffer[0] = 0;
  }
  else if ( sv_redirected == RD_CLIENT )
  {
    host_client->ClientPrintf(this: &host_client->IClient, a2: "%s", sv_redirect_buffer);
    bInFlush = false;
    sv_redirect_buffer[0] = 0;
  }
  else
  {
    if ( sv_redirected == RD_SOCKET )
    {
      v0 = RCONServer();
      CRConServer::FinishRedirect(this: v0, msg: sv_redirect_buffer, adr: &sv_redirectto);
    }
    bInFlush = false;
    sv_redirect_buffer[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012CF10
// Name: void SV_RedirectStart(enum redirect_t,struct netadr_s const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_RedirectStart(redirect_t rd, const netadr_s *addr)
{
  sv_redirected = rd;
  sv_redirectto = *addr;
  sv_redirect_buffer[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012CF40
// Name: void SV_RedirectEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_RedirectEnd()
{
  SV_RedirectFlush();
  sv_redirected = RD_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x1012CF50
// Name: bool SV_RedirectActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SV_RedirectActive()
{
  return sv_redirected != RD_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x1012CF60
// Name: void SV_RedirectAddText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_RedirectAddText(const char *txt)
{
  if ( strlen(txt) + _V_strlen(str: sv_redirect_buffer) > 0xFFF )
    SV_RedirectFlush();
  V_strncat(pDest: sv_redirect_buffer, pSrc: txt, destBufferSize: 0x1000u, max_chars_to_copy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1012CFB0
// Name: __CreateCServerRemoteAccessIGameServerData_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerRemoteAccess *__cdecl _CreateCServerRemoteAccessIGameServerData_interface()
{
  return &g_ServerRemoteAccess;
}

} // namespace engine_xlsp
