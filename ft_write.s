; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_write.s                                         :+:    :+:             ;
;                                                      +:+                     ;
;    By: telly <telly@student.codam.nl>               +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/04/16 15:02:25 by telly         #+#    #+#                  ;
;    Updated: 2020/04/16 15:13:45 by telly         ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global  ft_write

ft_write:                               ;rdi = file descriptor, rsi = string, rdx = byte count
            cmp         rsi, 0          ;check string to write
            je          error
            mov         rax, 1          ;syscall rax 1 = write
            syscall                   
            cmp         rax, 0          ;check syscall return
            jl          error           ;negative means error
            ret
error:
            mov         rax, -1         ;error return
            ret