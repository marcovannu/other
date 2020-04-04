#!/bin/sh


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
export NNN_BMS='m:/media;h:/home/marco;e:/etc'
export NNN_USE_READER=1
export NNN_PLUG='w:makewall'

#userresources=$HOME/.Xresources
#usermodmap=$HOME/.Xmodmap
#sysresources=/etc/X11/xinit/.Xresources
#sysmodmap=/etc/X11/xinit/.Xmodmap

# merge in defaults and keymaps

#if [ -f $sysresources ]; then
#    xrdb -merge $sysresources
#fi

#if [ -f $sysmodmap ]; then
#    xmodmap $sysmodmap
#fi

#if [ -f "$userresources" ]; then
#    xrdb -merge "$userresources"
#fi

#if [ -f "$usermodmap" ]; then
#    xmodmap "$usermodmap"
#fi

if [ -d /etc/X11/xinit/xinitrc.d ] ; then
 for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
  [ -x "$f" ] && . "$f"
 done
 unset f
fi


setxkbmap -layout it
unclutter -b &
devmon --no-gui &
picom &
~/.local/bin/dwmbar &
mpd ~/.config/mpd/mpd.conf
~/.fehbg &

exec dwm

#exec dwm in loop
#while true; do
#	/usr/local/bin/dwm 2> /dev/null
#done

