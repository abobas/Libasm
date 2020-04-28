; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_list_push_front_bonus.s                         :+:    :+:             ;
;                                                      +:+                     ;
;    By: telly <telly@student.codam.nl>               +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/04/16 20:46:53 by telly         #+#    #+#                  ;
;    Updated: 2020/04/23 23:39:08 by telly         ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global  ft_list_push_front
extern  malloc

ft_list_push_front:                                     ; rdi = begin_list, rsi = data
                        cmp         rdi, 0
                        je          error
                        push        rdi
                        push        rsi
allocate_element:
                        mov         rdi, 16             ; t_list = 16 bytes
                        call        malloc              ; allocate new struct
                        pop         rsi
                        pop         rdi
                        cmp         rax, 0              ; malloc protect
                        je          error        
fill_element:
                        mov         [rax + 0], rsi      ; put data in new element
                        mov         rbx, [rdi]          ; 
                        mov         [rax + 8], rbx      ; put pointer to old first element's address as next in new element
                        mov         [rdi], rax          ; change begin_list address to new element
                        ret
error:
                        mov         rax, 0
                        ret

