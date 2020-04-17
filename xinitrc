#!/bin/sh

export PATH=$PATH:~/.local/bin

#Default Programs:
export BROWSER="qutebrowser"
export EDITOR="nvim"
export FILE="nnn"
export READER="zathura"
export TERMINAL="st"
export VIDEO="mpv"
export VISUAL="nvim"

#~/ Clean-up:
export GTK2_RC_FILES="$HOME/.config/gtk-2.0/gtkrc-2.0"
export LESSHISTFILE="$HOME/.config/lesshst"

#nnn file manager:
export NNN_COLORS='6537'
export NNN_BMS='m:/media;h:~/;e:/etc'
export NNN_PLUG='b:~/.local/bin/setbg'

#Startup:
setxkbmap -layout us,it -option grp:ctrl_alt_toggle
setxkbmap -option caps:escape
blueman-applet &
dunst &
systemctl --user import-envoironment DISPLAY
unclutter -b &
devmon --no-gui &
picom &
~/.local/bin/dwmbar &
mpd ~/.config/mpd/mpd.conf
~/.local/bin/setbg &

while true; do
	/usr/local/bin/dwm 2> /dev/null
done

#start
if [ -d /etc/X11/xinit/xinitrc.d ] ; then
 for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
  [ -x "$f" ] && . "$f"
 done
 unset f
fi
