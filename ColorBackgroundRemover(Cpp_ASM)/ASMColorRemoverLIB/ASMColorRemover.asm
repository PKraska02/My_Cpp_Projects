.code
ProcessImageASM proc
    push rbp
    mov rbp,rsp
    mov rax,[rbp+16]          ;Adresy argumentów do rejestrów
    mov rbx,[rbp+24]

    vmovups ymm0,[rax]        ;Pobranie argumentów
    vmovups ymm1,[rbx]

    vmulps ymm0, ymm0, ymm1  ;Mno¿enie wektorowe

    mov rax,[rbp+32]
    vmovups [rax],ymm0        ;Zapisanie wyniku do pamiêci

    ; Resetowanie u¿ywanych rejestrów
    ;xor rax, rax
    ;xor rbx, rbx
    ;vzeroall

    pop rbp
    ret
ProcessImageASM endp
end