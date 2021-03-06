{$ifndef ARM9}
  {$error Video is only available on the ARM9}
{$endif ARM9}

{$ifdef NDS_INTERFACE}
var
  mosaicShadow: cuint16; cvar; external;
  mosaicShadowSub: cuint16; cvar; external;

const
  BG_PALETTE          : pcuint16 = pointer($05000000);
  BG_PALETTE_SUB      : pcuint16 = pointer($05000400);

  SPRITE_PALETTE      : pcuint16 = pointer($05000200);
  SPRITE_PALETTE_SUB  : pcuint16 = pointer($05000600);

  BG_GFX			         : pcuint16 = pointer($06000000);
  BG_GFX_SUB		       : pcuint16 = pointer($06200000);
  SPRITE_GFX			     : pcuint16 = pointer($06400000);
  SPRITE_GFX_SUB		   : pcuint16 = pointer($06600000);

  VRAM_0        : pcuint16 = pointer($06000000);
  VRAM          : pcuint16 = pointer($06800000);
  VRAM_A        : pcuint16 = pointer($06800000);
  VRAM_B        : pcuint16 = pointer($06820000);
  VRAM_C        : pcuint16 = pointer($06840000);
  VRAM_D        : pcuint16 = pointer($06860000);
  VRAM_E        : pcuint16 = pointer($06880000);
  VRAM_F        : pcuint16 = pointer($06890000);
  VRAM_G        : pcuint16 = pointer($06894000);
  VRAM_H        : pcuint16 = pointer($06898000);
  VRAM_I        : pcuint16 = pointer($068A0000);

  OAM           : pcuint16 = pointer($07000000);
  OAM_SUB       : pcuint16 = pointer($07000400);

function RGB15(r, g, b: cint): cuint16; inline; 
function RGB5(r, g, b: cint): cuint16; inline;
function RGB8(r, g, b: cint): cuint8; inline;
function ARGB16(a, r, g, b: cint): cuint16; inline;

const
  SCREEN_HEIGHT = 192;
  SCREEN_WIDTH  = 256;
  
//	Vram Control
  VRAM_CR			: pcuint32 = pointer($04000240);
  VRAM_A_CR		: pcuint8 = pointer($04000240);
  VRAM_B_CR		: pcuint8 = pointer($04000241);
  VRAM_C_CR		: pcuint8 = pointer($04000242);
  VRAM_D_CR		: pcuint8 = pointer($04000243);
  VRAM_EFG_CR	: pcuint8 = pointer($04000244);
  VRAM_E_CR		: pcuint8 = pointer($04000244);
  VRAM_F_CR		: pcuint8 = pointer($04000245);
  VRAM_G_CR		: pcuint8 = pointer($04000246);
  WRAM_CR			: pcuint8 = pointer($04000247);
  VRAM_H_CR		: pcuint8 = pointer($04000248);
  VRAM_I_CR		: pcuint8 = pointer($04000249);

  VRAM_ENABLE	= (1 shl 7);

function  VRAM_OFFSET(n: cint): cint; inline;	

type
  VRAM_A_TYPE = cint;
const 
  VRAM_A_LCD                    : VRAM_A_TYPE = 0;
  VRAM_A_MAIN_BG                : VRAM_A_TYPE = 1;
  VRAM_A_MAIN_BG_0x06000000     : VRAM_A_TYPE = 1 or (0 shl 3);
  VRAM_A_MAIN_BG_0x06020000     : VRAM_A_TYPE = 1 or (1 shl 3);
  VRAM_A_MAIN_BG_0x06040000     : VRAM_A_TYPE = 1 or (2 shl 3);
  VRAM_A_MAIN_BG_0x06060000     : VRAM_A_TYPE = 1 or (3 shl 3);
  VRAM_A_MAIN_SPRITE            : VRAM_A_TYPE = 2;
  VRAM_A_MAIN_SPRITE_0x06400000 : VRAM_A_TYPE = 2;
  VRAM_A_MAIN_SPRITE_0x06420000 : VRAM_A_TYPE = 2 or (1 shl 3);  
  VRAM_A_TEXTURE                : VRAM_A_TYPE = 3;
  VRAM_A_TEXTURE_SLOT0          : VRAM_A_TYPE = 3 or (0 shl 3);
  VRAM_A_TEXTURE_SLOT1          : VRAM_A_TYPE = 3 or (1 shl 3);
  VRAM_A_TEXTURE_SLOT2          : VRAM_A_TYPE = 3 or (2 shl 3);
  VRAM_A_TEXTURE_SLOT3          : VRAM_A_TYPE = 3 or (3 shl 3);

type
  VRAM_B_TYPE = cint;
const
  VRAM_B_LCD                    : VRAM_B_TYPE = 0;
  VRAM_B_MAIN_BG                : VRAM_B_TYPE = 1 or (1 shl 3);
  VRAM_B_MAIN_BG_0x06000000     : VRAM_B_TYPE = 1 or (0 shl 3);
  VRAM_B_MAIN_BG_0x06020000     : VRAM_B_TYPE = 1 or (1 shl 3);
  VRAM_B_MAIN_BG_0x06040000     : VRAM_B_TYPE = 1 or (2 shl 3);
  VRAM_B_MAIN_BG_0x06060000     : VRAM_B_TYPE = 1 or (3 shl 3);
  VRAM_B_MAIN_SPRITE            : VRAM_B_TYPE = 2 or (1 shl 3);
  VRAM_B_MAIN_SPRITE_0x06400000 : VRAM_B_TYPE = 2;
  VRAM_B_MAIN_SPRITE_0x06420000 : VRAM_B_TYPE = 2 or (1 shl 3);
  VRAM_B_TEXTURE                : VRAM_B_TYPE = 3 or (1 shl 3);
  VRAM_B_TEXTURE_SLOT0          : VRAM_B_TYPE = 3 or (0 shl 3);
  VRAM_B_TEXTURE_SLOT1          : VRAM_B_TYPE = 3 or (1 shl 3);
  VRAM_B_TEXTURE_SLOT2          : VRAM_B_TYPE = 3 or (2 shl 3);
  VRAM_B_TEXTURE_SLOT3          : VRAM_B_TYPE = 3 or (3 shl 3);


type
  VRAM_C_TYPE = cint;
const
  VRAM_C_LCD                : VRAM_C_TYPE = 0;
  VRAM_C_MAIN_BG            : VRAM_C_TYPE = 1 or (2 shl 3);
  VRAM_C_MAIN_BG_0x06000000 : VRAM_C_TYPE = 1 or (0 shl 3);
  VRAM_C_MAIN_BG_0x06020000 : VRAM_C_TYPE = 1 or (1 shl 3);
  VRAM_C_MAIN_BG_0x06040000 : VRAM_C_TYPE = 1 or (2 shl 3);
  VRAM_C_MAIN_BG_0x06060000 : VRAM_C_TYPE = 1 or (3 shl 3);
  VRAM_C_ARM7               : VRAM_C_TYPE = 2;
  VRAM_C_ARM7_0x06000000    : VRAM_C_TYPE = 2;
  VRAM_C_ARM7_0x06020000    : VRAM_C_TYPE = 2 or (1 shl 3);  
  VRAM_C_SUB_BG             : VRAM_C_TYPE = 4;
  VRAM_C_SUB_BG_0x06200000  : VRAM_C_TYPE = 4 or (0 shl 3);
  VRAM_C_TEXTURE            : VRAM_C_TYPE = 3 or (2 shl 3);
  VRAM_C_TEXTURE_SLOT0      : VRAM_C_TYPE = 3 or (0 shl 3);
  VRAM_C_TEXTURE_SLOT1      : VRAM_C_TYPE = 3 or (1 shl 3);
  VRAM_C_TEXTURE_SLOT2      : VRAM_C_TYPE = 3 or (2 shl 3);
  VRAM_C_TEXTURE_SLOT3      : VRAM_C_TYPE = 3 or (3 shl 3);


type
  VRAM_D_TYPE = cint;
const
  VRAM_D_LCD                : VRAM_D_TYPE = 0;
  VRAM_D_MAIN_BG            : VRAM_D_TYPE = 1 or (3 shl 3);
  VRAM_D_MAIN_BG_0x06000000 : VRAM_D_TYPE = 1 or (0 shl 3);
  VRAM_D_MAIN_BG_0x06020000 : VRAM_D_TYPE = 1 or (1 shl 3);
  VRAM_D_MAIN_BG_0x06040000 : VRAM_D_TYPE = 1 or (2 shl 3);
  VRAM_D_MAIN_BG_0x06060000 : VRAM_D_TYPE = 1 or (3 shl 3);
  VRAM_D_ARM7               : VRAM_D_TYPE = 2 or (1 shl 3);
  VRAM_D_ARM7_0x06000000    : VRAM_D_TYPE = 2;
  VRAM_D_ARM7_0x06020000    : VRAM_D_TYPE = 2 or (1 shl 3);  
  VRAM_D_SUB_SPRITE         : VRAM_D_TYPE = 4;
  VRAM_D_TEXTURE            : VRAM_D_TYPE = 3 or (3 shl 3);
  VRAM_D_TEXTURE_SLOT0      : VRAM_D_TYPE = 3 or (0 shl 3);
  VRAM_D_TEXTURE_SLOT1      : VRAM_D_TYPE = 3 or (1 shl 3);
  VRAM_D_TEXTURE_SLOT2      : VRAM_D_TYPE = 3 or (2 shl 3);
  VRAM_D_TEXTURE_SLOT3      : VRAM_D_TYPE = 3 or (3 shl 3);

type
  VRAM_E_TYPE = cint;
const
  VRAM_E_LCD            : VRAM_E_TYPE = 0;
  VRAM_E_MAIN_BG        : VRAM_E_TYPE = 1;
  VRAM_E_MAIN_SPRITE    : VRAM_E_TYPE = 2;
  VRAM_E_TEX_PALETTE    : VRAM_E_TYPE = 3;
  VRAM_E_BG_EXT_PALETTE : VRAM_E_TYPE = 4;

type
  VRAM_F_TYPE = cint;
const
  VRAM_F_LCD                    : VRAM_F_TYPE = 0;
  VRAM_F_MAIN_BG                : VRAM_F_TYPE = 1;
  VRAM_F_MAIN_BG_0x06000000     : VRAM_F_TYPE = 1;
  VRAM_F_MAIN_BG_0x06004000     : VRAM_F_TYPE = 1 or (1 shl 3);
  VRAM_F_MAIN_BG_0x06010000     : VRAM_F_TYPE = 1 or (2 shl 3);
  VRAM_F_MAIN_BG_0x06014000     : VRAM_F_TYPE = 1 or (3 shl 3);  
  VRAM_F_MAIN_SPRITE            : VRAM_F_TYPE = 2;
  VRAM_F_MAIN_SPRITE_0x06400000 : VRAM_F_TYPE = 2;
  VRAM_F_MAIN_SPRITE_0x06404000 : VRAM_F_TYPE = 2 or (1 shl 3);
  VRAM_F_MAIN_SPRITE_0x06410000 : VRAM_F_TYPE = 2 or (2 shl 3);
  VRAM_F_MAIN_SPRITE_0x06414000 : VRAM_F_TYPE = 2 or (3 shl 3); 
  VRAM_F_TEX_PALETTE            : VRAM_F_TYPE = 3;
  VRAM_F_TEX_PALETTE_SLOT0      : VRAM_F_TYPE = 3;
  VRAM_F_TEX_PALETTE_SLOT1      : VRAM_F_TYPE = 3 or (1 shl 3);
  VRAM_F_TEX_PALETTE_SLOT4      : VRAM_F_TYPE = 3 or (2 shl 3);
  VRAM_F_TEX_PALETTE_SLOT5      : VRAM_F_TYPE = 3 or (3 shl 3);
  VRAM_F_BG_EXT_PALETTE         : VRAM_F_TYPE = 4;
  VRAM_F_BG_EXT_PALETTE_SLOT01  : VRAM_F_TYPE = 4 or (0 shl 3);
  VRAM_F_BG_EXT_PALETTE_SLOT23  : VRAM_F_TYPE = 4 or (1 shl 3);
  VRAM_F_SPRITE_EXT_PALETTE     : VRAM_F_TYPE = 5;

type
  VRAM_G_TYPE = cint;
const
  VRAM_G_LCD                    : VRAM_G_TYPE = 0;
  VRAM_G_MAIN_BG                : VRAM_G_TYPE = 1;
  VRAM_G_MAIN_BG_0x06000000     : VRAM_G_TYPE = 1;
  VRAM_G_MAIN_BG_0x06004000     : VRAM_G_TYPE = 1 or (1 shl 3);
  VRAM_G_MAIN_BG_0x06010000     : VRAM_G_TYPE = 1 or (2 shl 3);
  VRAM_G_MAIN_BG_0x06014000     : VRAM_G_TYPE = 1 or (3 shl 3);  
  VRAM_G_MAIN_SPRITE            : VRAM_G_TYPE = 2;
  VRAM_G_MAIN_SPRITE_0x06400000 : VRAM_G_TYPE = 2;
  VRAM_G_MAIN_SPRITE_0x06404000 : VRAM_G_TYPE = 2 or (1 shl 3);
  VRAM_G_MAIN_SPRITE_0x06410000 : VRAM_G_TYPE = 2 or (2 shl 3);
  VRAM_G_MAIN_SPRITE_0x06414000 : VRAM_G_TYPE = 2 or (3 shl 3);    
  VRAM_G_TEX_PALETTE            : VRAM_G_TYPE = 3;
  VRAM_G_TEX_PALETTE_SLOT0      : VRAM_G_TYPE = 3;
  VRAM_G_TEX_PALETTE_SLOT1      : VRAM_G_TYPE = 3 or (1 shl 3);
  VRAM_G_TEX_PALETTE_SLOT4      : VRAM_G_TYPE = 3 or (2 shl 3);
  VRAM_G_TEX_PALETTE_SLOT5      : VRAM_G_TYPE = 3 or (3 shl 3);
  VRAM_G_BG_EXT_PALETTE         : VRAM_G_TYPE = 4;
  VRAM_G_BG_EXT_PALETTE_SLOT01  : VRAM_G_TYPE = 4 or (0 shl 3);
  VRAM_G_BG_EXT_PALETTE_SLOT23  : VRAM_G_TYPE = 4 or (1 shl 3);  
  VRAM_G_SPRITE_EXT_PALETTE     : VRAM_G_TYPE = 5;

type
  VRAM_H_TYPE = cint;
const
  VRAM_H_LCD                : VRAM_H_TYPE = 0;
  VRAM_H_SUB_BG             : VRAM_H_TYPE = 1;
  VRAM_H_SUB_BG_EXT_PALETTE : VRAM_H_TYPE = 2;

type
  VRAM_I_TYPE = cint;
const
  VRAM_I_LCD                    : VRAM_I_TYPE = 0;
  VRAM_I_SUB_BG_0x06208000      : VRAM_I_TYPE = 1;
  VRAM_I_SUB_SPRITE             : VRAM_I_TYPE = 2;
  VRAM_I_SUB_SPRITE_EXT_PALETTE : VRAM_I_TYPE = 3;

type
  _palette = array [0..255] of cuint16;
  _ext_palette = array [0..15] of _palette;
  P_palette = ^_palette;
  P_ext_palette = ^_ext_palette;

var
  VRAM_E_EXT_PALETTE : P_ext_palette absolute VRAM_E;
  VRAM_F_EXT_PALETTE : P_ext_palette absolute VRAM_F;
  VRAM_G_EXT_PALETTE : P_ext_palette absolute VRAM_G;
  VRAM_H_EXT_PALETTE : P_ext_palette absolute VRAM_H;

function vramSetPrimaryBanks(a: VRAM_A_TYPE; b: VRAM_B_TYPE; c: VRAM_C_TYPE; d: VRAM_D_TYPE): cuint32; cdecl; external; 
function vramSetMainBanks(a: VRAM_A_TYPE; b: VRAM_B_TYPE; c: VRAM_C_TYPE; d: VRAM_D_TYPE): cuint32; cdecl; external; deprecated;
function vramDefault(): cuint32; cdecl; external;
procedure vramRestorePrimaryBanks(vramTemp: cuint32); cdecl; external;
procedure vramRestoreMainBanks(vramTemp: cuint32); cdecl; external; deprecated;
procedure vramRestoreBanks_EFG(vramTemp: cuint32); cdecl; external;

procedure vramSetBankA(a: VRAM_A_TYPE); inline;
procedure vramSetBankB(b: VRAM_B_TYPE); inline;
procedure vramSetBankC(c: VRAM_C_TYPE); inline;
procedure vramSetBankD(d: VRAM_D_TYPE); inline;
procedure vramSetBankE(e: VRAM_E_TYPE); inline;
procedure vramSetBankF(f: VRAM_F_TYPE); inline;
procedure vramSetBankG(g: VRAM_G_TYPE); inline;
procedure vramSetBankH(h: VRAM_H_TYPE); inline;
procedure vramSetBankI(i: VRAM_I_TYPE); inline;

const
  REG_DISPCNT       : pcuint32 = pointer($04000000);
  REG_DISPCNT_SUB   : pcuint32 = pointer($04001000);

  ENABLE_3D      = (1 shl 3);
  DISPLAY_ENABLE_SHIFT = 8;
  DISPLAY_BG0_ACTIVE    = (1 shl 8);
  DISPLAY_BG1_ACTIVE    = (1 shl 9);
  DISPLAY_BG2_ACTIVE    = (1 shl 10);
  DISPLAY_BG3_ACTIVE    = (1 shl 11);
  DISPLAY_SPR_ACTIVE    = (1 shl 12);
  DISPLAY_WIN0_ON       = (1 shl 13);
  DISPLAY_WIN1_ON       = (1 shl 14);
  DISPLAY_SPR_WIN_ON    = (1 shl 15);

 
type
  VideoMode = integer;
const   
  MODE_0_2D: VideoMode = $10000;
  MODE_1_2D: VideoMode = $10001;
  MODE_2_2D: VideoMode = $10002;
  MODE_3_2D: VideoMode = $10003;
  MODE_4_2D: VideoMode = $10004;
  MODE_5_2D: VideoMode = $10005;
  MODE_6_2D: VideoMode = $10006;
  MODE_0_3D: VideoMode = ($10000 or DISPLAY_BG0_ACTIVE or ENABLE_3D);
  MODE_1_3D: VideoMode = ($10001 or DISPLAY_BG0_ACTIVE or ENABLE_3D);
  MODE_2_3D: VideoMode = ($10002 or DISPLAY_BG0_ACTIVE or ENABLE_3D);
  MODE_3_3D: VideoMode = ($10003 or DISPLAY_BG0_ACTIVE or ENABLE_3D);
  MODE_4_3D: VideoMode = ($10004 or DISPLAY_BG0_ACTIVE or ENABLE_3D);
  MODE_5_3D: VideoMode = ($10005 or DISPLAY_BG0_ACTIVE or ENABLE_3D);
  MODE_6_3D: VideoMode = ($10006 or DISPLAY_BG0_ACTIVE or ENABLE_3D);
  MODE_FIFO: VideoMode = (3 shl 16);
  MODE_FB0 : VideoMode = ($00020000);
  MODE_FB1 : VideoMode = ($00060000);
  MODE_FB2 : VideoMode = ($000A0000);
  MODE_FB3 : VideoMode = ($000E0000);

  DISPLAY_SPR_HBLANK	  = (1 shl 23);

  DISPLAY_SPR_1D_LAYOUT	= (1 shl 4);

  DISPLAY_SPR_1D				  = (1 shl 4);
  DISPLAY_SPR_2D				  = (0 shl 4);
  DISPLAY_SPR_1D_BMP			= (4 shl 4);
  DISPLAY_SPR_2D_BMP_128	= (0 shl 4);
  DISPLAY_SPR_2D_BMP_256	= (2 shl 4);


  DISPLAY_SPR_1D_SIZE_32		  = (0 shl 20);
  DISPLAY_SPR_1D_SIZE_64		  = (1 shl 20);
  DISPLAY_SPR_1D_SIZE_128		  = (2 shl 20);
  DISPLAY_SPR_1D_SIZE_256		  = (3 shl 20);
  DISPLAY_SPR_1D_BMP_SIZE_128	= (0 shl 22);
  DISPLAY_SPR_1D_BMP_SIZE_256	= (1 shl 22);

  DISPLAY_SPRITE_ATTR_MASK = ((7 shl 4) or (7 shl 20) or (1 shl 31));

  DISPLAY_SPR_EXT_PALETTE		  = (1 shl 31);
  DISPLAY_BG_EXT_PALETTE		  = (1 shl 30);

  DISPLAY_SCREEN_OFF     = (1 shl 7);

function DISPLAY_CHAR_BASE(n: cuint32): cuint32; inline;
function DISPLAY_SCREEN_BASE(n: cuint32): cuint32; inline;

procedure videoSetMode(mode: cuint32); inline;  
procedure videoSetModeSub(mode: cuint32); inline;  

function videoGetMode(): cint; inline;	 	 
function videoGetModeSub(): cint; inline;	 	 
function video3DEnabled(): cbool; inline;	 	 
procedure videoBgEnable(number: cint); inline;	 	 
procedure videoBgEnableSub(number: cint); inline;	 	 
procedure videoBgDisable(number: cint); inline;	 	 
procedure videoBgDisableSub(number: cint); inline;
procedure setBrightness(screen, level: cint); cdecl; external;
procedure setBackdropColor(const color: cuint16); inline;
procedure setBackdropColorSub(const color: cuint16); inline;

const
  REG_MASTER_BRIGHT     : pcuint16 = pointer($0400006C);
  REG_MASTER_BRIGHT_SUB : pcuint16 = pointer($0400106C);

// Window 0
  WIN0_X0        : pcuint8 = pointer($04000041);
  WIN0_X1        : pcuint8 = pointer($04000040);
  WIN0_Y0        : pcuint8 = pointer($04000045);
  WIN0_Y1        : pcuint8 = pointer($04000044);

// Window 1
  WIN1_X0        : pcuint8 = pointer($04000043);
  WIN1_X1        : pcuint8 = pointer($04000042);
  WIN1_Y0        : pcuint8 = pointer($04000047);
  WIN1_Y1        : pcuint8 = pointer($04000046);

  WIN_IN         : pcuint16 = pointer($04000048);
  WIN_OUT        : pcuint16 = pointer($0400004A);

// Window 0
  SUB_WIN0_X0    : pcuint8 = pointer($04001041);
  SUB_WIN0_X1    : pcuint8 = pointer($04001040);
  SUB_WIN0_Y0    : pcuint8 = pointer($04001045);
  SUB_WIN0_Y1    : pcuint8 = pointer($04001044);

// Window 1
  SUB_WIN1_X0    : pcuint8 = pointer($04001043);
  SUB_WIN1_X1    : pcuint8 = pointer($04001042);
  SUB_WIN1_Y0    : pcuint8 = pointer($04001047);
  SUB_WIN1_Y1    : pcuint8 = pointer($04001046);

  SUB_WIN_IN     : pcuint16 = pointer($04001048);
  SUB_WIN_OUT    : pcuint16 = pointer($0400104A);

  REG_MOSAIC     : pcuint16 = pointer($0400004C);
  REG_MOSAIC_SUB : pcuint16 = pointer($0400104C);

  REG_BLDCNT     : pcuint16 = pointer($04000050);
  REG_BLDY       : pcuint16 = pointer($04000054);
  REG_BLDALPHA   : pcuint16 = pointer($04000052);

  REG_BLDCNT_SUB    : pcuint16 = pointer($04001050);
  REG_BLDALPHA_SUB  : pcuint16 = pointer($04001052);
  REG_BLDY_SUB      : pcuint16 = pointer($04001054);

  BLEND_NONE          = (0 shl 6);
  BLEND_ALPHA         = (1 shl 6);
  BLEND_FADE_WHITE    = (2 shl 6);
  BLEND_FADE_BLACK    = (3 shl 6);

  BLEND_SRC_BG0       = (1 shl 0);
  BLEND_SRC_BG1       = (1 shl 1);
  BLEND_SRC_BG2       = (1 shl 2);
  BLEND_SRC_BG3       = (1 shl 3);
  BLEND_SRC_SPRITE    = (1 shl 4);
  BLEND_SRC_BACKDROP  = (1 shl 5);

  BLEND_DST_BG0       = (1 shl 8);
  BLEND_DST_BG1       = (1 shl 9);
  BLEND_DST_BG2       = (1 shl 10);
  BLEND_DST_BG3       = (1 shl 11);
  BLEND_DST_SPRITE    = (1 shl 12);
  BLEND_DST_BACKDROP  = (1 shl 13);

  REG_DISPCAPCNT: pcuint32 = pointer($04000064);
  REG_DISP_MMEM_FIFO: pcuint32 = pointer($04000068);

  DCAP_ENABLE    = (1 shl 31);

function DCAP_MODE(n: cint): cint; inline;   
function DCAP_SRC_ADDR(n: cint): cint; inline;    
function DCAP_SRC(n: cint): cint; inline;    
function DCAP_SRC_A(n: cint): cint;
function DCAP_SRC_B(n: cint): cint;
function DCAP_SIZE(n: cint): cint; inline;   
function DCAP_OFFSET(n: cint): cint; inline; 
function DCAP_BANK(n: cint): cint; inline;   
function DCAP_B(n: cint): cint; inline;      
function DCAP_A(n: cint): cint; inline;      

const
  DCAP_MODE_A           = 0;
  DCAP_MODE_B           = 1;
  DCAP_MODE_BLEND       = 2;
  DCAP_SRC_A_COMPOSITED = 0;
  DCAP_SRC_A_3DONLY     = 1;
  DCAP_SRC_B_VRAM       = 0;
  DCAP_SRC_B_DISPFIFO   = 1;
  DCAP_SIZE_128x128     = 0;
  DCAP_SIZE_256x64      = 1;
  DCAP_SIZE_256x128     = 2;
  DCAP_SIZE_256x192     = 3;
  DCAP_BANK_VRAM_A      = 0;
  DCAP_BANK_VRAM_B      = 1;
  DCAP_BANK_VRAM_C      = 2;
  DCAP_BANK_VRAM_D      = 3;

const
  GFX_CONTROL           : pcuint16 = pointer($04000060);

  GFX_FIFO              : pcuint32 = pointer($04000400);
  GFX_STATUS            : pcuint32 = pointer($04000600);
  GFX_COLOR             : pcuint32 = pointer($04000480);

  GFX_VERTEX10          : pcuint32 = pointer($04000490);
  GFX_VERTEX_XY         : pcuint32 = pointer($04000494);
  GFX_VERTEX_XZ         : pcuint32 = pointer($04000498);
  GFX_VERTEX_YZ         : pcuint32 = pointer($0400049C);
  GFX_VERTEX_DIFF       : pcuint32 = pointer($040004A0);

  GFX_VERTEX16          : pcuint32 = pointer($0400048C);
  GFX_TEX_COORD         : pcuint32 = pointer($04000488);
  GFX_TEX_FORMAT        : pcuint32 = pointer($040004A8);
  GFX_PAL_FORMAT        : pcuint32 = pointer($040004AC);

  GFX_CLEAR_COLOR       : pcuint32 = pointer($04000350);
  GFX_CLEAR_DEPTH       : pcuint16 = pointer($04000354);

  GFX_LIGHT_VECTOR      : pcuint32 = pointer($040004C8);
  GFX_LIGHT_COLOR       : pcuint32 = pointer($040004CC);
  GFX_NORMAL            : pcuint32 = pointer($04000484);

  GFX_DIFFUSE_AMBIENT   : pcuint32 = pointer($040004C0);
  GFX_SPECULAR_EMISSION : pcuint32 = pointer($040004C4);
  GFX_SHININESS         : pcuint32 = pointer($040004D0);

  GFX_POLY_FORMAT       : pcuint32 = pointer($040004A4);
  GFX_ALPHA_TEST        : pcuint16 = pointer($04000340);

  GFX_BEGIN             : pcuint32 = pointer($04000500);
  GFX_END               : pcuint32 = pointer($04000504);
  GFX_FLUSH             : pcuint32 = pointer($04000540);
  GFX_VIEWPORT          : pcuint32 = pointer($04000580);
  GFX_TOON_TABLE        : pcuint16 = pointer($04000380);
  GFX_EDGE_TABLE        : pcuint16 = pointer($04000330);
  GFX_FOG_COLOR         : pcuint32 = pointer($04000358);
  GFX_FOG_OFFSET        : pcuint32 = pointer($0400035C);
  GFX_FOG_TABLE         : pcuint8 = pointer($04000360);
  GFX_BOX_TEST          : pcint32 = pointer($040005C0);
  GFX_POS_TEST          : pcint32 = pointer($040005C4);
  GFX_POS_RESULT        : pcint32 = pointer($04000620);
  GFX_VEC_TEST          : pcuint32 = pointer($040005C8);
  GFX_VEC_RESULT        : pcint16 = pointer($04000630);

function GFX_BUSY: boolean; inline;

const
  GFX_VERTEX_RAM_USAGE	: pcuint16 = pointer($04000606);
  GFX_POLYGON_RAM_USAGE	: pcuint16 = pointer($04000604);

  GFX_CUTOFF_DEPTH		  : pcuint16 = pointer($04000610);

// Matrix processor control

  MATRIX_CONTROL		: pcuint32 = pointer($04000440);
  MATRIX_PUSH			  : pcuint32 = pointer($04000444);
  MATRIX_POP        : pcuint32 = pointer($04000448);
  MATRIX_SCALE		  : pcint32 = pointer($0400046C);
  MATRIX_TRANSLATE	: pcint32 = pointer($04000470);
  MATRIX_RESTORE		: pcuint32 = pointer($04000450);
  MATRIX_STORE		  : pcuint32 = pointer($0400044C);
  MATRIX_IDENTITY		: pcuint32 = pointer($04000454);
  MATRIX_LOAD4x4		: pcint32 = pointer($04000458);
  MATRIX_LOAD4x3		: pcint32 = pointer($0400045C);
  MATRIX_MULT4x4		: pcint32 = pointer($04000460);
  MATRIX_MULT4x3		: pcint32 = pointer($04000464);
  MATRIX_MULT3x3		: pcint32 = pointer($04000468);

//matrix operation results
  MATRIX_READ_CLIP   : pcint32 = pointer($04000640);
  MATRIX_READ_VECTOR : pcint32 = pointer($04000680);
  POINT_RESULT       : pcint32 = pointer($04000620);
  VECTOR_RESULT      : pcuint16 = pointer($04000630);

{$endif NDS_INTERFACE}

{$ifdef NDS_IMPLEMENTATION}
function RGB15(r, g, b: cint): cuint16; inline;
begin
  RGB15 := ((r) or ((g) shl 5) or ((b) shl 10));
end;
  
function RGB5(r, g, b: cint): cuint16; inline;
begin
  RGB5 := ((r) or ((g) shl 5) or ((b) shl 10));
end;

function RGB8(r, g, b: cint): cuint8; inline;
begin
  RGB8 := (((r) shr 3) or (((g) shr 3) shl 5) or (((b) shr 3) shl 10));
end;

function ARGB16(a, r, g, b: cint): cuint16; inline;
begin
  ARGB16 := ((a shl 15) or r or (g shl 5) or (b shl 10));
end;

function  VRAM_OFFSET(n: cint): cint; inline;	
begin
  VRAM_OFFSET := ((n) shl 3);
end;

function videoGetMode(): cint; inline; 
begin
  result := (REG_DISPCNT^ and $30007);
end;	 	 

function videoGetModeSub(): cint; inline;  
begin
  result := (REG_DISPCNT_SUB^ and $30007);
end;

function video3DEnabled(): cbool; inline;  
begin
  result := (REG_DISPCNT^ and ENABLE_3D) <> 0;
end;
	 	 
procedure videoBgEnable(number: cint); inline; 
begin
  REG_DISPCNT^ :=  REG_DISPCNT^ or (1 shl (DISPLAY_ENABLE_SHIFT + number));
end;
	 	 	 	 
procedure videoBgEnableSub(number: cint); inline; 
begin
  REG_DISPCNT_SUB^ := REG_DISPCNT_SUB^ or (1 shl (DISPLAY_ENABLE_SHIFT + number));
end;
	 	 	 	 
procedure videoBgDisable(number: cint); inline; 
begin
  REG_DISPCNT^ := REG_DISPCNT^ and not (1 shl (DISPLAY_ENABLE_SHIFT + number));
end;
	 	 	 	 
procedure videoBgDisableSub(number: cint); inline; 
begin
  REG_DISPCNT_SUB^ := REG_DISPCNT_SUB^ and not (1 shl (DISPLAY_ENABLE_SHIFT + number));
end;

function DISPLAY_CHAR_BASE(n: cuint32): cuint32; inline;
begin
  DISPLAY_CHAR_BASE := ((n) and 7) shl 24;
end;

function DISPLAY_SCREEN_BASE(n: cuint32): cuint32; inline;
begin 
  DISPLAY_SCREEN_BASE := ((n) and 7) shl 27;
end;	 
	 
procedure videoSetMode(mode: cuint32); inline;  
begin
  REG_DISPCNT^ := mode;
end;

procedure videoSetModeSub(mode: cuint32); inline;  
begin
  REG_DISPCNT_SUB^ := mode;
end;

function DCAP_MODE(n: cint): cint; inline;   
begin
  DCAP_MODE := (((n) and 3) shl 29);
end;

function DCAP_SRC_ADDR(n: cint): cint; inline;    
begin
  DCAP_SRC_ADDR := (((n) and 3) shl 26);
end;

function DCAP_SRC(n: cint): cint; inline;    
begin
  DCAP_SRC := (((n) and 3) shl 24);
end;

function DCAP_SRC_A(n: cint): cint;
begin
  DCAP_SRC_A := (((n) and 1) shl 24);
end;

function DCAP_SRC_B(n: cint): cint;
begin
  DCAP_SRC_B := (((n) and 1) shl 25);
end;

function DCAP_SIZE(n: cint): cint; inline;   
begin
  DCAP_SIZE := (((n) and 3) shl 20);
end;

function DCAP_OFFSET(n: cint): cint; inline; 
begin
  DCAP_OFFSET := (((n) and 3) shl 18);
end;

function DCAP_BANK(n: cint): cint; inline;   
begin
  DCAP_BANK := (((n) and 3) shl 16);
end;

function DCAP_B(n: cint): cint; inline;      
begin
  DCAP_B := (((n) and $1F) shl 8);
end;

function DCAP_A(n: cint): cint; inline;      
begin
  DCAP_A := (((n) and $1F) shl 0);
end;

function GFX_BUSY: boolean; inline;
begin
	GFX_BUSY := GFX_STATUS^ and (1 shl 27) <> 0;
end;

procedure vramSetBankA(a: VRAM_A_TYPE); inline;
begin
  VRAM_A_CR^ := VRAM_ENABLE or a;
end;

procedure vramSetBankB(b: VRAM_B_TYPE); inline;
begin
  VRAM_B_CR^ := VRAM_ENABLE or b;
end;

procedure vramSetBankC(c: VRAM_C_TYPE); inline;
begin
  VRAM_C_CR^ := VRAM_ENABLE or c;
end;

procedure vramSetBankD(d: VRAM_D_TYPE); inline;
begin
  VRAM_D_CR^ := VRAM_ENABLE or d;
end;

procedure vramSetBankE(e: VRAM_E_TYPE); inline;
begin
  VRAM_E_CR^ := VRAM_ENABLE or e;
end;

procedure vramSetBankF(f: VRAM_F_TYPE); inline;
begin
  VRAM_F_CR^ := VRAM_ENABLE or f;
end;

procedure vramSetBankG(g: VRAM_G_TYPE); inline;
begin
  VRAM_G_CR^ := VRAM_ENABLE or g;
end;

procedure vramSetBankH(h: VRAM_H_TYPE); inline;
begin
  VRAM_H_CR^ := VRAM_ENABLE or h;
end;

procedure vramSetBankI(i: VRAM_I_TYPE); inline;
begin
  VRAM_I_CR^ := VRAM_ENABLE or i;
end;

procedure setBackdropColor(const color: cuint16); inline;
begin
  BG_PALETTE[0] := color;
end;

procedure setBackdropColorSub(const color: cuint16); inline;
begin
  BG_PALETTE_SUB[0] := color;
end;

{$endif NDS_IMPLEMENTATION}
