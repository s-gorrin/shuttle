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

" Gets standard function prototype
function s:_getproto ()
"requires 'runtime! ftplugin/man.vim'
    if expand("%:t") =~ '\.c$'
        execute "normal I" . s:_signature() . "\<CR>{\<CR>}\<ESC>O\<ESC>a\<Tab>"
    elseif expand("%:t") =~ '\.h$'
        execute "normal I" . s:_signature() . ";"
    endif
endfunction
function s:_signature ()
    let basename = substitute(expand("%:r"), "ft_", "", "")
    execute "Man ." basename
    execute '/' . basename . '(\C'
    normal "ay$k^"by$
    execute 'q'
    let sig = @b . @a
    let sig = substitute(sig, basename, "ft_" . basename, "")
    let sig = substitute(sig, '\(\w\) *\(\**ft\)', '\1\t\2', "")
    let sig = substitute(sig, 'restrict \|;', "", "g")
    return sig
endfunction
command Getproto :call s:_getproto()
