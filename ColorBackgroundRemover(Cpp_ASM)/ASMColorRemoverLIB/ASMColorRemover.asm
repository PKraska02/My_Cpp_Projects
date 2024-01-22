
section .data
    power db 0
    new_red db 0
    new_green db 0
    new_blue db 0

section .text
    global ProcessImageASM
    extern printf

ProcessImageASM:
    ; Prolog
    push ebp
    mov ebp, esp

    ; Load arguments
    mov eax, [ebp+8] ; red
    mov ebx, [ebp+12] ; green
    mov ecx, [ebp+16] ; blue

    ; Calculate new values
    sub eax, new_red
    imul eax, power
    idiv byte 100
    cmp eax, 0
    jl .red_lower_bound
    cmp eax, 255
    jg .red_upper_bound
    jmp .green
.red_lower_bound:
    mov eax, 0
    jmp .green
.red_upper_bound:
    mov eax, 255
.green:
    sub ebx, new_green
    imul ebx, power
    idiv byte 100
    cmp ebx, 0
    jl .green_lower_bound
    cmp ebx, 255
    jg .green_upper_bound
    jmp .blue
.green_lower_bound:
    mov ebx, 0
    jmp .blue
.green_upper_bound:
    mov ebx, 255
.blue:
    sub ecx, new_blue
    imul ecx, power
    idiv byte 100
    cmp ecx, 0
    jl .blue_lower_bound
    cmp ecx, 255
    jg .blue_upper_bound
    jmp .end
.blue_lower_bound:
    mov ecx, 0
    jmp .end
.blue_upper_bound:
    mov ecx, 255
.end:
    ; Store results back
    mov [ebp+8], eax ; red
    mov [ebp+12], ebx ; green
    mov [ebp+16], ecx ; blue

    ; Epilog
    mov esp, ebp
    pop ebp
    ret
    end