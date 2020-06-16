//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"📦 ", "checkupdates | wc -l",					1200,		9},

	{"", "~/.local/bin/statusbar/news",				0,		6},

	{"", "~/.local/bin/statusbar/mailbox",				180,		18},

	{"", "~/.local/bin/statusbar/nettraf",				1,		11},

	{"", "ip route get 1 | awk '{print $(NF-2);exit}'",		30,		12},

	/*{"", "~/.local/bin/statusbar/capture",				0,		2},*/

	{"", "~/.local/bin/statusbar/volume",				0,		10},

	{"-[] ", "acpi -b | grep -o 'Charging' | sed 's/Charging/~/' && echo $(acpi -b | grep -o '[0-9]*%')",						10,		0},

	/*{"🌡 ", "sensors | awk '/^temp1:/{print $2}'",		5,		0},*/

	{"", "~/.local/bin/statusbar/clock",				60,		1},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = '|';
