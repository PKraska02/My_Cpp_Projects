section .text
global ProcessImageASM

; Wejœcie:
; rdi - wskaŸnik na dane obrazu
; rsi - szerokoœæ obrazu w pikselach
; rdx - wysokoœæ obrazu
; rcx - wskaŸnik na wektor koloru (RGBA)
ProcessImageASM:
    ; Ustawienie wskaŸnika na dane obrazu
    mov r8, rdi

    ; Pêtla po wysokoœci obrazu
    mov r9, 0  ; Licznik wierszy
    outer_loop:
        ; Pêtla po szerokoœci obrazu (ka¿dy piksel to 4 bajty)
        mov r10, 0  ; Licznik pikseli
        inner_loop:
            ; Obliczenie indeksu piksela
            imul r11, r9, rsi  ; r11 = r9 * rsi (numer wiersza * szerokoœæ obrazu)
            add r11, r10       ; r11 = r11 + r10 (indeks piksela)

            ; WskaŸnik na bie¿¹cy piksel
            mov r12, r8        ; r12 = r8 (wskaŸnik na dane obrazu)
            add r12, r11       ; r12 = r12 + r11 (wskaŸnik na bie¿¹cy piksel)

            ; Wczytanie piksela do rejestru YMM
            vmovdqu ymm0, [r12]

            ; Tutaj mo¿na wykonaæ operacje wektorowe na pikselu w ymm0

            ; Przesuniêcie wskaŸnika na kolejny piksel
            add r10, 32         ; Przesuniêcie o 32 bajty (8 pikseli * 4 bajty/piksel)

            ; Sprawdzenie warunku zakoñczenia pêtli wewnêtrznej
            cmp r10, rsi*4
            jl inner_loop

        ; Przesuniêcie wskaŸnika na dane obrazu do nastêpnego wiersza
        add r8, rsi*4

        ; Inkrementacja licznika wierszy
        inc r9

        ; Sprawdzenie warunku zakoñczenia pêtli zewnêtrznej
        cmp r9, rdx
        jl outer_loop

    ; Zakoñczenie funkcji
    ret
