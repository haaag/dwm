/* Constants */
#define TERMINAL "kitty"

/* appearance */
// static const unsigned int ulinepad	= 5;	    /* horizontal padding between the underline and tag */
// static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
// static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
// static const int ulineall 		= 0;	        /* 1 to show underline on all tags, 0 for just the active ones */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const char *fonts[]          = { "RobotoMono Nerd Font:size=10", "Material:size=12", "FontAwesome:size=11", "Font Awesome 5 Free:size=11"};
static const char dmenufont[]       = "monospace:size=10";
// static const char *fonts[]          = { "Iosevka:size=10", "Material:size=12", "FontAwesome:size=11", "Font Awesome 5 Free:size=11"};

// TokyoNight {{{
static const char col_gray1[]       = "#4abaaf";
static const char col_gray2[]       = "#414868";
static const char col_gray3[]       = "#a9b1d6";
static const char col_gray4[]       = "#c0caf5";
// static const char col_cyan[]        = "#4abaaf";
static const char col_cyan[]        = "#1f2335";
static const char col_background[]  = "#24283b";
// }}}
// Gruvbox
/* static const char col_gray1[]       = "#1f2335";
static const char col_gray2[]       = "#a89984";
static const char col_gray3[]       = "#bdae93";
static const char col_gray4[]       = "#d5c4a1";
static const char col_cyan[]        = "#458588";
static const char col_organge[]     = "#d65d0e";
static const char col_background[]  = "#32302f"; */
//
// Gruvbox
/* static const char col_gray1[]       = "#89b482";
static const char col_gray2[]       = "#a89984";
static const char col_gray3[]       = "#bdae93";
static const char col_gray4[]       = "#d4be98";
static const char col_cyan[]        = "#32302f";
static const char col_red[]         = "#ea6962";
static const char col_background[]  = "#1D2021";
// */
/* // Catppuccin
static const char col_gray1[]       = "#B3E1A3";
static const char col_gray2[]       = "#D7DAE0";
static const char col_gray3[]       = "#D7DAE0";
static const char col_gray4[]       = "#C6AAE8";
static const char col_cyan[]        = "#1E1E28";
static const char col_red[]         = "#E28C8C";
static const char col_background[]  = "#1E1E28";
// */
/* // Onedark
static const char col_gray1[]       = "#98C379";
static const char col_gray2[]       = "#ABB2BF";
static const char col_gray3[]       = "#ABB2BF";
static const char col_gray4[]       = "#C678DD";
static const char col_cyan[]        = "#282C34";
static const char col_red[]         = "#E06C75";
static const char col_background[]  = "#282C34";
// */
/* // rose-pine
// static const char col_gray1[]       = "#31748f";
static const char col_gray1[]       = "#9ccfd8";
static const char col_gray2[]       = "#6e6a86";
static const char col_gray3[]       = "#6e6a86";
static const char col_gray4[]       = "#c4a7e7";
static const char col_cyan[]        = "#191724";
static const char col_red[]         = "#eb6f92";
static const char col_background[]  = "#191724";
// static const char col_cyan[]        = "#9ccfd8";
// */
static const unsigned int baralpha  = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3] = {
	/*                    fg                bg            border   */
	[SchemeNorm]  = { col_gray3,    col_background,     col_gray2   },
	[SchemeSel]   = { col_gray1,    col_cyan,           col_gray1   },
    [SchemeTitle] = { col_cyan,     col_background,     col_gray1   },
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeTitle]  = { OPAQUE, baralpha, borderalpha },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;

// const char *spcmd1[] = {"st", "-n", "spterm", "-g", "125x34", NULL };
const char *spcmd1[] = {"kitty", "--class", "stratchpad", "--name", "stratchpad", "-e", "zsh", NULL };
const char *spcmd2[] = {"kitty", "--class", "spipython", "--name", "spipython", "-e", "ipython", NULL };
const char *spcmd3[] = {"kitty", "--class", "pulsemixer", "--name", "pulsemixer", "-e", "pulsemixer", NULL };
static Sp scratchpads[] = {
	/* name          	cmd  */
	{"stratchpad",   	spcmd1},
	{"spipython",    	spcmd2},
	{"pulsemixer",   	spcmd3},
};
/* tagging */
/*    */
// static const char *tags[] = { "a", "s", "d", "f", "z", "x", "c", "v" };
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };
// static const char *tags[] = {"", "", "", "", "", "", "", "", };
/* static const char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }; */
/* static const char *tags[] = { "", "", "", "", "", "", "", "", "" }; */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *  use tags mask to point an application to a specific workspace
	 */
	/* class                instance    	title           	tags mask     	isfloating    monitor   float x,y,w,h     floatbord */
	{ "Gimp",               NULL,       	NULL,               0,                0,            -1, 				                 },
	{ "firefox",            NULL,       	NULL,               1,        	      0,            -1, 				                 },
	{ "Brave-browser",      NULL,       	NULL,               1,        	      0,            -1, 				                 },
	{ "Navigator",          NULL,       	NULL,               0,        	      0,            -1, 				                 },
	{ "TelegramDesktop",    NULL,           NULL,          1 << 6,                0,            -1, 				                 },
	{ "Signal",             NULL,           NULL,          1 << 6,                0,            -1, 				                 },
	{ "tidal-hifi",       "tidal-hifi", 	"tidal-hifi",  1 << 3,                0,            -1,                                  },
	{ "Galculator",       "galculator", 	"galculator",       0,                1,            -1,              1612,773,306,305,  1},
	{ "Gucharmap",          NULL,           NULL,               0,                1,            -1,              381,221,1101,709,  1},
	{ "mpv",                NULL,           NULL,               0,                1,            -1,               450,208,958,539,  1},
	{ "spterm",           "spterm",         NULL,        SPTAG(0),                1,            -1,                 50,50,500,500,  1},
	{ "spipython",        "spipython",      NULL,        SPTAG(1),                1,            -1,              1325,134,593,944,  1},
	{ "pulsemixer",       "pulsemixer",     NULL,        SPTAG(2),                1,            -1,               1081,20,837,202,  1},
	{ "spipython2",       "spipython2",     NULL,        SPTAG(3),                1,            -1,              1325,134,593,944,  1},
	{ "Sxiv",               NULL,       	NULL,          	    0,                1,         	  -1,            1079,424,839,654,  1}
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "layouts.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },     		/* first entry is default */
	{ "HHH",      grid },
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },		/* Master in middle, slaves on sides */
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },     		/* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_background, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *terminal[]  = { "kitty", NULL };
static const char *rofi_run[]  = { "rofi", "-width", "300", "-lines", "10", "-show", "run", NULL };

#include "selfrestart.c"
#include "shiftview.c"


static Key keys[] = {
	/* modifier                     key        function        argument */
	// { MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_r,      spawn,          {.v = rofi_run } },
	{ MODKEY,                       XK_Return, spawn,          {.v = terminal } },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Right,  focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Left,   focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|ControlMask,           XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_space,  cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_p,      togglesticky,   {0} },
	{ MODKEY|ShiftMask,             XK_p,      fullscreen,     {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	// { MODKEY,                       XK_F11,    togglescratch,  {.ui = 1 } },
	{ MODKEY,                       XK_F11,    togglescratch,  {.ui = 0 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_r,      self_restart,   {0} },
	{ Mod1Mask|ControlMask,         XK_Right,  shiftview,      {.i =  1 } },
	{ Mod1Mask|ControlMask,         XK_Left,   shiftview,      {.i = -1 } },
	{ Mod1Mask|ControlMask,         XK_Up,     shiftview,      {.i =  1 } },
	{ Mod1Mask|ControlMask,         XK_Down,   shiftview,      {.i = -1 } },
	{ Mod1Mask,                     XK_Tab,    shiftview,      {.i =  1 } },
	{ Mod1Mask|ShiftMask,           XK_Tab,    shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_Tab,    shiftview,      {.i =  1 } },
	{ MODKEY|ShiftMask,             XK_Tab,    shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, /* tile */
	{ MODKEY,                       XK_y,      setlayout,      {.v = &layouts[1]} }, /* grid */
	{ MODKEY|ShiftMask,             XK_y,      setlayout,      {.v = &layouts[2]} }, /* monocle */
	{ MODKEY,                       XK_i,      setlayout,      {.v = &layouts[3]} }, /* centeredmaster */
	{ MODKEY|ShiftMask,             XK_i,      setlayout,      {.v = &layouts[4]} }, /* centeredfloatingmaster */


	TAGKEYS(                        XK_a,                      0)
	TAGKEYS(                        XK_s,                      1)
	TAGKEYS(                        XK_d,                      2)
	TAGKEYS(                        XK_f,                      3)
	TAGKEYS(                        XK_z,                      4)
	TAGKEYS(                        XK_x,                      5)
	TAGKEYS(                        XK_c,                      6)
	TAGKEYS(                        XK_v,                      7)
	TAGKEYS(                        XK_9,                      8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	/* { ClkStatusText,        0,              Button1,        spawn,          {.v = taskmanager } },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = filecmd } },
	{ ClkStatusText,        0,              Button3,        spawn,          {.v = calendar } }, */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
