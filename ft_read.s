; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_read.s                                          :+:    :+:             ;
;                                                      +:+                     ;
;    By: telly <telly@student.codam.nl>               +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/04/16 15:33:27 by telly         #+#    #+#                  ;
;    Updated: 2020/04/16 15:33:30 by telly         ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global  ft_read

ft_read:                                ;rdi = fd, rsi = bufferstring, rdx = bytes to read
            cmp         rsi, 0          ;check bufferstring
            je          error
            mov         rax, 0          ;syscall 0 = read
            syscall
            cmp         rax, 0          ;check return value of syscall
            jl          error
            ret
error:
            mov         rax, -1
            ret
