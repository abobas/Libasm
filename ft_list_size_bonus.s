; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_list_size_bonus.s                               :+:    :+:             ;
;                                                      +:+                     ;
;    By: telly <telly@student.codam.nl>               +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/04/16 21:01:28 by telly         #+#    #+#                  ;
;    Updated: 2020/04/16 21:09:20 by telly         ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global  ft_list_size

ft_list_size:                               ;rdi = begin_list address
                mov     rax, 0
                cmp     rdi, 0
                je      return
                mov     rcx, rdi            ; put beginning element in register
                jmp     increment
compare:
                cmp     rcx, 0              ; check if element exists 
                je      return
increment:
                inc     rax
                mov     rcx, [rcx + 8]      ; move to next element
                jmp     compare
return:
                ret