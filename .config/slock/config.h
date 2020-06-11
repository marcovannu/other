/* user and group to drop privileges to */
static const char *user  = "marco";
static const char *group = "wheel";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#282828",    /* after initialization */
	[INPUT] =  "#282828",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;
