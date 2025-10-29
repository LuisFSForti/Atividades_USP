ORG 0000h
        JMP init

        ORG 0030h

init:   MOV P1, #0FFh                      ; Apaga display (todos segmentos em 1)
        MOV DPTR, #lut                     ; Ponteiro para tabela
        MOV R0, #00h                       ; R0 = índice do contador (0..9)
        MOVC A, @A+DPTR                    ; Pega a formatação do número de R0
        MOV P1, A                          ; Ativa o LCD com a cor desejada

wait_key:
        JNB P2.0, up_count                 ; Se botão de contagem crescente pressionado
        JNB P2.1, down_count               ; Se botão de contagem decrescente pressionado
        SJMP wait_key                      ; Senão, fica esperando


; ---------- Contagem crescente ----------
up_count:
        CLR PSW.5                          ; Define delay rápido para contagem crescente
        ACALL delay                        ; Chama o delay
        JNB P2.1, down_count               ; Troca se botão decrescente estiver pressionado

        INC R0                             ; Aumenta R0 em 1
        MOV A, R0
        CJNE A, #0Ah, atualiza_up_count    ; Se A diferente de 10, reinicia o loop
        MOV R0, #00h                       ; Se A igual a 10, R0 volta pra 0

atualiza_up_count:
        MOV A, R0
        MOVC A, @A+DPTR                    ; Pega a formatação do número de R0
        MOV P1, A                          ; Ativa o LCD com a cor desejada
        SJMP up_count                      ; Reinicia o loop

; ---------- Contagem decrescente ----------
down_count:
        SETB PSW.5                         ; Define delay lento para contagem decrescente
        ACALL delay                        ; Chama o delay
        JNB P2.0, up_count                 ; Troca se botão crescente estiver pressionado

        DEC R0                             ; Diminui R0 em 1
        MOV A, R0
        CJNE A, #0FFh, atualiza_down_count ; Se A diferente de -1, atualiza o LCD
        MOV R0, #09h                       ; Se A igual a -1, volta para 9

atualiza_down_count:
        MOV A, R0
        MOVC A, @A+DPTR                    ; Pega a formatação do número de R0
        MOV P1, A                          ; Ativa o LCD com a cor desejada
        SJMP down_count                    ; Reinicia o loop

delay:
        JNB PSW.5, delay_fast              ; Se F0 valer zero, vai para delay rápido

        ; ----- delay lento -----
        ; delay = 1s
        MOV R1, #10
d1s:    MOV R2, #200
d2s:    MOV R3, #250
d3s:    DJNZ R3, d3s
        DJNZ R2, d2s
        DJNZ R1, d1s
        RET

delay_fast:
        ; ----- delay rápido -----
        ; delay = 0.5s
        MOV R1, #5
d1f:    MOV R2, #200
d2f:    MOV R3, #250
d3f:    DJNZ R3, d3f
        DJNZ R2, d2f
        DJNZ R1, d1f
        RET
; ---------- LUT de 7 segmentos ----------
        ORG 0200h
        ; Cria uma tabela com as formatações de todos os números na LCD
lut:    DB 0C0h,0F9h,0A4h,0B0h,99h,92h,82h,0F8h,80h,90h

        END