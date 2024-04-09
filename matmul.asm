section .data
    N equ 4 ; Change this value to match the size of your square matrix
    matrix dd 1, 2, 3, 4
           dd 5, 6, 7, 8
           dd 9, 10, 11, 12
           dd 13, 14, 15, 16
    transposed_matrix dd N*N dup(0)

section .text
    global _start
    
_start:
    mov ecx, N
    mov esi, 0  ; Source index
outer_loop:
    mov edi, esi  ; Destination index
    mov edx, ecx  ; Counter for inner loop
inner_loop:
    mov eax, [matrix + esi * 4]         ; Load element from matrix
    mov [transposed_matrix + edi * 4], eax  ; Store element in transposed_matrix
    add edi, N                           ; Move to next column in transposed matrix
    add esi, 4                           ; Move to next row in original matrix
    dec edx
    jnz inner_loop
    add esi, N * 4                       ; Move to next row in original matrix
    sub esi, ecx * 4                     ; Reset to beginning of next row
    dec ecx
    jnz outer_loop

    ; Display transposed matrix
    mov ecx, N
    mov esi, 0
print_loop:
    mov edx, N
print_inner_loop:
    mov eax, [transposed_matrix + esi * 4]
    ; Output the number
    ; Code for outputting the number goes here (e.g., using printf in C or system calls)
    add esi, N
    dec edx
    jnz print_inner_loop
    ; Output a newline
    ; Code for outputting newline goes here
    add esi, 4
    dec ecx
    jnz print_loop

    ; Exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80
