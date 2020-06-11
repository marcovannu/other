" Native config
	syntax on
	set encoding=utf-8
	filetype plugin on
	set ic
	set nocompatible
	set nohlsearch
	set path+=**
	set wildmenu
	set wildmode=longest,list,full
	set splitbelow splitright
	set number relativenumber
	set clipboard=unnamedplus
	set foldmethod=manual


" Colorscheme
	colo gruvbox
	set termguicolors

" Gruvbox
	let g:gruvbox_contrast_dark = 'hard'
	let g:gruvbox_invert_tabline = '1'

" Autocmd
	autocmd BufWinLeave * mkview
	autocmd BufWinEnter * silent! loadview
	autocmd BufWritePre * %s/\s\+$//e
	autocmd BufWritePost ~/.Xresources,~/Xdefaults !xrdb %
	autocmd BufRead,BufNewFile *.ms,*.me,*.mom,*.man set filetype=groff
	autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o

" Automatically deletes all trailing whitespace and newlines at end of file on save.
	autocmd BufWritePre * %s/\s\+$//e
	autocmd BufWritepre * %s/\n\+\%$//e

" Run xrdb whenever Xdefaults or Xresources are updated.
	autocmd BufWritePost *Xresources,*Xdefaults !xrdb %

" Save file as sudo on files that require root permission
	cnoremap w!! execute 'silent! write !sudo tee % >/dev/null' <bar> edit!

" Shortcutting split navigation, saving a keypress:
	map <C-h> <C-w>h
	map <C-j> <C-w>j
	map <C-k> <C-w>k
	map <C-l> <C-w>l

" Bindings
	nnoremap S :%s//g<Left><Left>
	map <F6> :setlocal spell! spelllang=it<CR>
	inoremap <F9> <C-O>za
	nnoremap <F9> za
	onoremap <F9> <C-C>za
	vnoremap <F9> zf
	map <F10> :w! \| !/home/marco/.local/bin/compile <c-r>%<CR>
	map <F11> :!/home/marco/.local/bin/output <c-r>%<CR><CR>

"Special Characters Groff
"	imap à \(`a
"	imap è \(`e
"	imap é \('e
"	imap ì \(`i
"	imap ò \(`o
"	imap ù \(`u
