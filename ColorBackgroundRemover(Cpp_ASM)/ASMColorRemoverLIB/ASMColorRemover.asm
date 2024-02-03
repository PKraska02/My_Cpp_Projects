.code
ProcessImageASM proc
    mov rax, rcx              ; Pierwszy argument przekazywany przez RCX
    mov rbx, rdx              ; Drugi argument przekazywany przez RDX

    vmovups ymm0, [rax]       ; Pobranie argumentów
    vmovups ymm1, [rbx]

    vsubps ymm0, ymm0, ymm1   ; Odejmowanie wektorowe
    vxorps ymm2, ymm2, ymm2   ; Utworzenie wektora zerowego
    vmaxps ymm0, ymm0, ymm2   ; Maksimum z wyniku i zera

    vmovups [rax], ymm0       ; Zapisanie wyniku do pamiêci

    ret
ProcessImageASM endp
end
