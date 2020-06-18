#!/bin/zsh

#export PATH="$PATH:$(du "$HOME/.local/bin/" | cut -f2 | tr '\n' ':' | sed 's/:*$//')"
	export PATH="$PATH:$(du "$HOME/.local/bin/" | cut -f2 | paste -sd ':')"

#Default Programs:
	export BROWSER="qutebrowser"
	export EDITOR="nvim"
	export READER="zathura"
	export TERMINAL="st"

#~/ Clean-up:
	export XDG_CONFIG_HOME="$HOME/.config"
	export XDG_DATA_HOME="$HOME/.local/share"
	export GTK2_RC_FILES="${XDG_CONFIG_HOME:-$HOME/.config}/gtk-2.0/gtkrc-2.0"
	export LESSHISTFILE="${XDG_CONFIG_HOME:-$HOME/.config}/lesshst"
	export MBSYNCRC="${XDG_CONFIG_HOME:-$HOME/.config}/.mbsyncrc"
	export ZDOTDIR="${XDG_CONFIG_HOME:-$HOME/.config}/zsh"
	export NPM_CONFIG_USERCONFIG="${XDG_CONFIG_HOME:-$HOME/.config}/npm"
	export ANDROID_SDK_HOME="${XDG_CONFIG_HOME:-$HOME/.config}/android"
	#export VIMINIT=":source $XDG_CONFIG_HOME"/vim/vimrc
	export VIMINFO="${XDG_DATA_HOME:-$HOME/.cache}/viminfo"
	export PASSWORD_STORE_DIR="${XDG_DATA_HOME:-$HOME/.local/share}/password-store"
	export NOTMUCH_CONFIG="${XDG_CONFIG_HOME:-$HOME/.config}/notmuch-config"
	export HISTFILE="${XDG_DATA_HOME:-$HOME/.local/share}/history"

# Start graphical server on tty1 if not already running.
	[ "$(tty)" = "/dev/tty1" ] && ! ps -e | grep -qw Xorg && exec startx
