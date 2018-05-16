" Line numbering
set number

" Enable syntax highlighting
syntax enable

" Ruler
set ruler

" <Ctrl-l> redraws the screen and removes any search highlighting.
nnoremap <silent> <C-l> :nohl<CR><C-l

" Ask confim unsaved changes
set confirm

" Remove curly error
let c_no_curly_error=1

" Whitespace characters
set list
set listchars=tab:\›\ ,eol:·

" Normed comments
set comments=sr:/*,mb:**,ex:*/

" column 80 highlight
highlight ColorColumn ctermbg=white
call matchadd('ColorColumn', '\%81v', 100)

" Macros
}ommand Voidmain :normal  aint	main(void)

" F-key
map <F6> :set relativenumber!<CR>



" 42 vimrc:
" " 42 vim info/files/plugins can be found in /usr/share/vim/
"Activate indentation
filetype off
filetype plugin indent on
set smartindent

"Non-expanded, 4-wide tabulations
set tabstop=4
set shiftwidth=4
set noexpandtab

"Disable vi-compatibility
set nocompatible

"Real-world encoding
set encoding=utf-8

"Interpret modelines in files
set modelines=1

"Do not abandon buffers
set hidden

"Don't bother throttling tty
set ttyfast

"More useful backspace behavior
set backspace=indent,eol,start

"Use statusbar on all windows
set laststatus=2

"Better search
set ignorecase
set smartcase
set incsearch
set showmatch
set hlsearch

"Prevent backups when editing system files
au BufWrite /private/tmp/crontab.* set nowritebackup
au BufWrite /private/etc/pw.* set nowritebackup

"Source user configuration
if filereadable(expand("~/.myvimrc"))
        source ~/.myvimrc
endif
