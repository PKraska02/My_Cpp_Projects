.code
ProcessImageASM proc
    push rbp
    mov rbp,rsp
    mov rax,[rbp+16]          ;Adresy argument�w do rejestr�w
    mov rbx,[rbp+24]

    vmovups ymm0,[rax]        ;Pobranie argument�w
    vmovups ymm1,[rbx]

    vmulps ymm0, ymm0, ymm1  ;Mno�enie wektorowe

    mov rax,[rbp+32]
    vmovups [rax],ymm0        ;Zapisanie wyniku do pami�ci

    ; Resetowanie u�ywanych rejestr�w
    ;xor rax, rax
    ;xor rbx, rbx
    ;vzeroall

    pop rbp
    ret
ProcessImageASM endp
end