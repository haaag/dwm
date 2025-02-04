/* See LICENSE file for copyright and license details. */

/* constants */
#define TERMINAL "st"
#define TERMCLASS "St"
#define SHELL "zsh"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const int startwithgaps[]    = { 1 };	/* 1 means gaps are used by default, this can be customized for each tag */
static const unsigned int gappx[]   = { 15 };   /* default gap between windows in pixels, this can be customized for each tag */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {
    "MapleMono NF:size=10:antialias=true:autohint=true",
    "RobotoMono Nerd Font:size=10:antialias=true:autohint=true",
    "Material:size=12:antialias=true:autohint=true",
    "FontAwesome:size=14:antialias=true:autohint=true",
    "Font Awesome 5 Free:size=14:antialias=true:autohint=true",
    "Weather Icons:size=10:antialias=true:autohint=true"
};
static const char dmenufont[]       = "Maple Mono NF:size=10:antialias=true:autohint=true";
static const unsigned int baralpha  = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
    /*                  fg           bg           border   */
    [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
    [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};
static const unsigned int alphas[][3]   = {
    /*               fg      bg        border*/
    [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
    [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

typedef struct {
    const char *name;
    const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-c", "spterm", "-g", "110x30", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spfm", "-g", "120x25", "-e", SHELL, "-c", "nnn.sh", NULL };
const char *spcmd3[] = {TERMINAL, "-n", "spmusic", "-c", "spmusic", "-g", "120x25", "-e", "ncmpcpp-ueberzug", NULL};
const char *spcmd4[] = {TERMINAL, "-n", "spnews", "-c", "spnews", "-g", "130x30", "-e", SHELL,  "-c", "newsboat", NULL};
const char *spcmd5[] = {TERMINAL, "-n", "sphtop", "-c", "sphtop", "-g", "130x30", "-e", SHELL, "-c", "htop", NULL };
const char *spcmd6[] = {TERMINAL, "-n", "spmarks", "-c", "spmarks", "-g", "110x22", "-e", SHELL, "-c", "gms", NULL };
const char *spcmd7[] = {TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "28x8", "-e", "bc", "-lq", NULL };
const char *spcmd8[] = {TERMINAL, "-n", "spai", "-c", "spai", "-g", "130x30", "-e", SHELL, "-c", "ollama.sh", NULL };
const char *spcmd9[] = {TERMINAL, "-n", "spsf", "-g", "50x20", "-e", SHELL, "-c", "share-files", NULL };
const char *spcmd10[] = {TERMINAL, "-n", "spsf", "-g", "50x20", "-e", SHELL, "-c", "share-files --send", NULL };
const char *spcmd11[] = {TERMINAL, "-n", "spvim", "-g", "105x28", "-e", SHELL, "-c", "pad", NULL };
static Sp scratchpads[] = {
    /* name          cmd  */
    {"spterm",      spcmd1},
    {"spfm",        spcmd2},
    {"spmusic",     spcmd3},
    {"spnews",      spcmd4},
    {"sphtop",      spcmd5},
    {"spmarks",     spcmd6},
    {"spcalc",      spcmd7},
    {"spai",        spcmd8},
    {"spsf",        spcmd9},
    {"spsf",        spcmd10},
    {"spvim",       spcmd11},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class                instance        title               tags mask   iscentered  isfloating  monitor */
    { "Gimp",               NULL,           NULL,               0,          0,          1,          -1 },
    { "Firefox",            NULL,           NULL,               1 << 8,     0,          0,          -1 },
    { "zen",                NULL,           NULL,               1 << 8,     0,          0,          -1 },
    { "zen",                NULL,           "About Zen Browser",1 << 8,     1,          1,          -1 },
    { "LibreWolf",          NULL,           NULL,               1 << 7,     0,          0,          -1 },
    { "Chromium",           NULL,           NULL,               1 << 7,     0,          0,          -1 },
    { "Tor Browser",        NULL,           NULL,               1 << 7,     0,          0,          -1 },
    { "Tor Browser",        NULL,           "About Tor Browser",1 << 7,     1,          1,          -1 },
    { "TelegramDesktop",    NULL,           NULL,               1 << 6,     0,          0,          -1 },
    { "Signal",             NULL,           NULL,               1 << 6,     0,          0,          -1 },
    { "mpv",                NULL,           NULL,               1 << 5,     0,          0,          -1 },
    { "tidal-hifi",         "tidal-hifi",   NULL,               1 << 3,     0,          0,          -1 },
    { "Galculator",         "galculator",   NULL,               0,          0,          1,          -1 },
    { "Gucharmap",          NULL,           NULL,               0,          1,          1,          -1 },
    { "Peek",               "peek",         NULL,               0,          0,          1,          -1 },
    { "Tk",                 "tk",           NULL,               0,          1,          1,          -1 },
    { "Sxiv",               NULL,           NULL,               0,          0,          1,          -1 },
    { "Nitrogen",           NULL,           NULL,               0,          1,          1,          -1 },
    { "Nsxiv",              NULL,           NULL,               0,          0,          1,          -1 },
    { "GoWindow",           NULL,           NULL,               0,          0,          1,          -1 },
    { NULL,                 "screensaver",  NULL,               0,          0,          0,          -1 },
    { NULL,                 "splogs",       "splogs",           0,          1,          1,          -1 },
    { "Display",            "display",      NULL,               0,          1,          1,          -1 },
    { "Nsxiv",              "nsxiv",        NULL,               0,          1,          1,          -1 },
    { "Nsxiv",              "fontpreview",  NULL,               0,          0,          0,          -1 },
    { "Dragon-drop",        "dragon-drop",  NULL,               ~0,         0,          0,          -1 },
    { "sptransen",          "sptransen",    NULL,               0,          1,          1,          -1 },
    { NULL,                 "sptrans",      "term-trans.sh",    0,          1,          1,          -1 },
    { "spfloat",            "spfloat",      NULL,               0,          1,          1,          -1 },
    { "sppass",             "sppass",      NULL,               0,          1,          1,          -1 },
    // scratchpads
    { NULL,                 "spterm",       NULL,               SPTAG(0),   0,          1,          -1 },
    { NULL,                 "spfm",         NULL,               SPTAG(1),   0,          1,          -1 },
    { NULL,                 "spmusic",      NULL,               SPTAG(2),   1,          1,          -1 },
    { NULL,                 "spnews",       NULL,               SPTAG(3),   0,          1,          -1 },
    { NULL,                 "sphtop",       NULL,               SPTAG(4),   0,          1,          -1 },
    { NULL,                 "spmarks",      NULL,               SPTAG(5),   1,          1,          -1 },
    { TERMCLASS,            "spcalc",       NULL,               SPTAG(6),   1,          1,          -1 },
    { NULL,                 "spai",         NULL,               SPTAG(7),   0,          1,          -1 },
    { NULL,                 "spsf",         NULL,               SPTAG(8),   0,          1,          -1 },
    { NULL,                 "spsf",         NULL,               SPTAG(9),   0,          1,          -1 },
    { NULL,                 "spvim",        NULL,               SPTAG(10),  1,          1,          -1 },
};

/* layout(s) */
static const float mfact        = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "horizgrid.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
    { "###",      horizgrid },
    { "[D]",      deck },
    { "|||",      col },
    { "|M|",      centeredmaster },
    { ">M>",      centeredfloatingmaster },
};

/* key definitions */
#define MODKEY Mod1Mask
#define SUPERMODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu-run", "-h", "22", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { TERMINAL, NULL };
static const char *dwmquit[] = { "wmprompt", NULL};

static const Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_p,       spawn,          {.v = dmenucmd } },
    { MODKEY|ShiftMask,             XK_Return,  spawn,          {.v = termcmd } },
    { MODKEY,                       XK_b,       togglebar,      {0} },
    { MODKEY|ShiftMask,             XK_k,       rotatestack,    {.i = -1 } },
    { MODKEY|ShiftMask,             XK_j,       rotatestack,    {.i = +1 } },
    { MODKEY,                       XK_j,       focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,       focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_d,       incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,       incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,       setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,       setmfact,       {.f = +0.05} },
    { MODKEY|ShiftMask,             XK_h,       setcfact,       {.f = +0.25} },
    { MODKEY|ShiftMask,             XK_l,       setcfact,       {.f = -0.25} },
    { MODKEY|ShiftMask,             XK_o,       setcfact,       {.f =  0.00} },
    { MODKEY,                       XK_Return,  zoom,           {0} },
    { MODKEY,                       XK_Tab,     view,           {0} },
    { MODKEY|ShiftMask,             XK_c,       killclient,     {0} },
    { MODKEY,                       XK_t,       setlayout,      {.v = &layouts[0]} }, /* tile-layout */
    { MODKEY,                       XK_f,       setlayout,      {.v = &layouts[1]} }, /* floating-layout */
    { MODKEY,                       XK_m,       setlayout,      {.v = &layouts[2]} }, /* monocle-layout */
    { MODKEY,                       XK_o,       setlayout,      {.v = &layouts[3]} }, /* horizgrid-layout */
    { MODKEY,                       XK_r,       setlayout,      {.v = &layouts[4]} }, /* deck-layout */
    { MODKEY,                       XK_g,       setlayout,      {.v = &layouts[5]} }, /* columns-layout */
    { MODKEY,                       XK_u,       setlayout,      {.v = &layouts[6]} }, /* centeredmaster-layout */
    { MODKEY|ShiftMask,             XK_u,       setlayout,      {.v = &layouts[7]} }, /* centeredfloatingmaster-layout */
    { MODKEY,                       XK_space,   setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,   togglefloating, {0} },
    { MODKEY,                       XK_0,       view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,       tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,   focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period,  focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,   tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period,  tagmon,         {.i = +1 } },
    { MODKEY,                       XK_minus,   setgaps,        {.i = -5 } },
    { MODKEY,                       XK_equal,   setgaps,        {.i = +5 } },
    { MODKEY|ShiftMask,             XK_minus,   setgaps,        {.i = GAP_RESET } },
    { MODKEY|ShiftMask,             XK_equal,   setgaps,        {.i = GAP_TOGGLE} },
    { MODKEY,                       XK_F5,      xrdb,           {.v = NULL } },
    { SUPERMODKEY,                  XK_s,       togglesticky,   {0} },
    { MODKEY,                       XK_y,       togglescratch,  {.ui = 0 } }, // terminal
    { MODKEY|ShiftMask,             XK_y,       togglescratch,  {.ui = 1 } }, // nnn.sh
    { MODKEY,                       XK_x,       togglescratch,  {.ui = 2 } }, // mpd
    { MODKEY|ShiftMask,             XK_x,       togglescratch,  {.ui = 3 } }, // newsboat
    { SUPERMODKEY,                  XK_y,       togglescratch,  {.ui = 10 } }, // spvim
    { SUPERMODKEY|ShiftMask,        XK_y,       togglescratch,  {.ui = 4 } }, // sphtop
    { SUPERMODKEY,                  XK_n,       togglescratch,  {.ui = 5 } }, // bookmarks
    { SUPERMODKEY,                  XK_c,       togglescratch,  {.ui = 6 } }, // spcalc
    { SUPERMODKEY,                  XK_i,       togglescratch,  {.ui = 7 } }, // spai
    { SUPERMODKEY,                  XK_o,       togglescratch,  {.ui = 8 } }, // spsf
    { SUPERMODKEY|ShiftMask,        XK_o,       togglescratch,  {.ui = 9 } }, // spsf localsend
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
    { MODKEY,                       XK_q,      spawn,          {.v = dwmquit } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
