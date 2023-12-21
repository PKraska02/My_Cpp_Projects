section .text
global ProcessImageASM

; Wej�cie:
; rdi - wska�nik na dane obrazu
; rsi - szeroko�� obrazu w pikselach
; rdx - wysoko�� obrazu
; rcx - wska�nik na wektor koloru (RGBA)
ProcessImageASM:
    ; Ustawienie wska�nika na dane obrazu
    mov r8, rdi

    ; P�tla po wysoko�ci obrazu
    mov r9, 0  ; Licznik wierszy
    outer_loop:
        ; P�tla po szeroko�ci obrazu (ka�dy piksel to 4 bajty)
        mov r10, 0  ; Licznik pikseli
        inner_loop:
            ; Obliczenie indeksu piksela
            imul r11, r9, rsi  ; r11 = r9 * rsi (numer wiersza * szeroko�� obrazu)
            add r11, r10       ; r11 = r11 + r10 (indeks piksela)

            ; Wska�nik na bie��cy piksel
            mov r12, r8        ; r12 = r8 (wska�nik na dane obrazu)
            add r12, r11       ; r12 = r12 + r11 (wska�nik na bie��cy piksel)

            ; Wczytanie piksela do rejestru YMM
            vmovdqu ymm0, [r12]

            ; Tutaj mo�na wykona� operacje wektorowe na pikselu w ymm0

            ; Przesuni�cie wska�nika na kolejny piksel
            add r10, 32         ; Przesuni�cie o 32 bajty (8 pikseli * 4 bajty/piksel)

            ; Sprawdzenie warunku zako�czenia p�tli wewn�trznej
            cmp r10, rsi*4
            jl inner_loop

        ; Przesuni�cie wska�nika na dane obrazu do nast�pnego wiersza
        add r8, rsi*4

        ; Inkrementacja licznika wierszy
        inc r9

        ; Sprawdzenie warunku zako�czenia p�tli zewn�trznej
        cmp r9, rdx
        jl outer_loop

    ; Zako�czenie funkcji
    ret
