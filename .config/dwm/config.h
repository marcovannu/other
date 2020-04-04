/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 18;       /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=8" };
static const char dmenufont[]       = "monospace:size=8";
static const char col_gray1[]       = "#282828";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#689D6A";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       1 << 4,           0,           -1 },
	/*{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },*/
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ 0, XF86XK_AudioMute,		           spawn,    	   SHCMD("amixer set Master toggle") },
	{ 0, XF86XK_AudioRaiseVolume,	           spawn,	   SHCMD("amixer set Master 1%+") },
	{ 0, XF86XK_AudioLowerVolume,	           spawn,          SHCMD("amixer set Master 1%-") },

	{ 0, XF86XK_AudioPrev,		           spawn,	   SHCMD("mpc prev") },
	{ 0, XF86XK_AudioNext,		           spawn,	   SHCMD("mpc next") },
	{ 0, XF86XK_AudioPlay,		           spawn,	   SHCMD("mpc toggle") },
	{ 0, XF86XK_AudioStop,		           spawn,	   SHCMD("mpc stop") },

	{ 0, XF86XK_MonBrightnessUp,	           spawn,	   SHCMD("sudo xbacklight -inc 5") },
	{ 0, XF86XK_MonBrightnessDown,	           spawn,	   SHCMD("sudo xbacklight -dec 5") },

	{ MODKEY,			XK_F1,	   spawn,	   SHCMD("[ \"$(printf \"No\\nYes\" | dmenu -i -nb darkred -sb red -sf white -nf gray -p \"Shutdown computer?\")\" = Yes ] &&  shutdown -h now") },
	{ MODKEY,			XK_F2,	   spawn,	   SHCMD("[ \"$(printf \"No\\nYes\" | dmenu -i -nb darkred -sb red -sf white -nf gray -p \"Reboot computer?\")\" = Yes ] && reboot") },
	{ MODKEY,			XK_F3,		spawn,	   SHCMD("st -e nmtui") },
	{ MODKEY|ShiftMask,		XK_F3,		spawn,	   SHCMD("st -e nmcli device wifi rescan") },
	{ MODKEY,			XK_F5,		spawn,	   SHCMD("bash .local/bin/displayselect") },
	{ MODKEY,			XK_F9,		spawn,	   SHCMD("st -e pamix") },
	{ MODKEY,			XK_F10,		spawn,	   SHCMD("blueman-manager") },
	{ MODKEY,			XK_F12,		spawn,	   SHCMD("bash .local/bin/USB") },

	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_e,      spawn,          SHCMD("st -e nnn") },
	{ MODKEY,                       XK_i,      spawn,          SHCMD("st -e htop") },
	{ MODKEY,                       XK_w,      spawn,          SHCMD("qutebrowser") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("qutebrowser https://web.telegram.org/im --target window") },
	{ MODKEY,                       XK_y,      spawn,          SHCMD("bash .local/bin/youtubedl") },
	{ MODKEY,                       XK_b,      spawn,          SHCMD("mpc prev") },
	{ MODKEY,                       XK_n,      spawn,          SHCMD("mpc prev") },
	{ MODKEY,                       XK_p,      spawn,          SHCMD("mpc toggle") },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("scrot -s /home/marco/Immagini/Schermate/n.png") },
	{ MODKEY,                       XK_m,      spawn,          SHCMD("st -e ncmpcpp") },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          SHCMD("st -e ncmpcpp -s visualizer") },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	/*{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },*/
	{ MODKEY,                       XK_f,      fullscreen,     {0} },
	/*{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },*/
	{ MODKEY,                       XK_a,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,                       XK_Escape, spawn,          SHCMD("slock") },
	{ MODKEY|ShiftMask,             XK_Escape, quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};



