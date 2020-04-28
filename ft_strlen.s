; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strlen.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: telly <telly@student.codam.nl>               +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/04/16 14:48:39 by telly         #+#    #+#                  ;
;    Updated: 2020/04/16 14:48:43 by telly         ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global ft_strlen

ft_strlen:                                  ;rdi = char string
                mov     rax, 0
                cmp     rdi, 0              ;check input string
                je      return
                jmp     compare
increment:
                inc     rax                 ;increment return value
                inc     rdi                 ;increment char in string
compare:
                cmp     byte[rdi], 0        ;check delimiter
                jne     increment
return:
                ret
