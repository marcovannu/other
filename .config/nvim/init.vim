" All system-wide defaults are set in $VIMRUNTIME/archlinux.vim (usually just
" /usr/share/vim/vimfiles/archlinux.vim) and sourced by the call to :runtime
" you can find below.  If you wish to change any of those settings, you should
" do it in this file (/etc/vimrc), since archlinux.vim will be overwritten
" everytime an upgrade of the vim packages is performed.  It is recommended to
" make changes after sourcing archlinux.vim since it alters the value of the
" 'compatible' option.

"filetype detect

"enter the current millennium
set nocompatible

"enable syntax and plugin
syntax enable
filetype plugin on

"FINDING FILES
"Cerca anche nelle sottocartelle
set path+=**

"Mostra tutti i file cercati con tab e shift tab
set wildmenu

"filetype plugin indent on

set wildmode=longest,list,full

set splitbelow splitright

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages.
runtime! archlinux.vim
colo elflord


map <F6> :setlocal spell! spelllang=it<CR>
inoremap <F9> <C-O>za
nnoremap <F9> za
onoremap <F9> <C-C>za
vnoremap <F9> zf
map <F10> :w! \| !/home/marco/.local/bin/compile <c-r>%<CR>
map <F11> :!/home/marco/.local/bin/output <c-r>%<CR><CR>

set number relativenumber
set clipboard=unnamedplus

set foldmethod=manual

autocmd BufWinLeave * mkview
autocmd BufWinEnter * silent! loadview

autocmd BufWritePre * %s/\s\+$//e

autocmd BufWritePost ~/.Xresources,~/Xdefaults !xrdb %

" If you prefer the old-style vim functionalty, add 'runtime! vimrc_example.vim'
" Or better yet, read /usr/share/vim/vim80/vimrc_example.vim or the vim manual
" and configure vim to your own liking!

" do not load defaults if ~/.vimrc is missing
"let skip_defaults_vim=1


"Special Characters Groff

imap à \(`a
imap è \(`e
imap é \('e
imap ì \(`i
imap ò \(`o
imap ù \(`u

