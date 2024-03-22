global start
;extern kernel_main

section .text
bits 32

; Constants for magic numbers
VIDEO_MEMORY equ 0xb8000
VIDEO_MEMORY_SIZE equ 80*25*2
MULTIBOOT_HEADER_MAGIC equ 0x36d76289
CPUID_EXTENDED_FUNCTION equ 0x80000000
CPUID_EXTENDED_FUNCTION_LIMIT equ 0x80000001
PAGE_SIZE equ 0x200000
PAGE_TABLE_ENTRY_FLAGS equ 0b10000011

start:
	mov esp, stack_top

	call check_multiboot
	call check_cpuid
	call check_long_mode

	mov edi, VIDEO_MEMORY
    mov ecx, VIDEO_MEMORY_SIZE
    mov ax, 0x0720

    rep stosw


	call setup_page_tables
	call enable_paging

	lgdt [gdt64.pointer]

	jmp gdt64.code_segment:long_mode_start

	hlt

; Check if the bootloader is multiboot compliant
check_multiboot:
	cmp eax, MULTIBOOT_HEADER_MAGIC
	jne .no_multiboot
	ret
.no_multiboot:
	mov al, 'M'
	jmp error

; Check if the CPU supports the CPUID instruction
check_cpuid:
	pushfd
	pop eax
	mov ecx, eax
	xor eax, 1 << 21
	push eax
	popfd
	pushfd
	pop eax
	push ecx
	popfd
	cmp eax, ecx
	je .no_cpuid
	ret
.no_cpuid:
	mov al, 'C'
	jmp error

; Check if the CPU supports long mode
check_long_mode:
	mov eax, CPUID_EXTENDED_FUNCTION
	cpuid
	cmp eax, CPUID_EXTENDED_FUNCTION_LIMIT
	jb .no_long_mode

	mov eax, CPUID_EXTENDED_FUNCTION_LIMIT
	cpuid
	test edx, 1 << 29
	jz .no_long_mode
	
	ret
.no_long_mode:
	mov al, 'L'
	jmp error

; Set up the page tables
setup_page_tables:
	mov eax, page_table_l3
	or eax, 0b11
	mov [page_table_l4], eax
	
	mov eax, page_table_l2
	or eax, 0b11 
	mov [page_table_l3], eax

	mov ecx, 0 
.loop:

	mov eax, PAGE_SIZE
	mul ecx
	or eax, PAGE_TABLE_ENTRY_FLAGS
	mov [page_table_l2 + ecx * 8], eax

	inc ecx 
	cmp ecx, 512
	jne .loop

	ret

; Enable paging
enable_paging:
	mov eax, page_table_l4
	mov cr3, eax

	mov eax, cr4
	or eax, 1 << 5
	mov cr4, eax

	mov ecx, 0xC0000080
	rdmsr
	or eax, 1 << 8
	wrmsr

	mov eax, cr0
	or eax, 1 << 31
	mov cr0, eax

	ret

error:
	mov dword [0xb8000], 0x4f524f45
	mov dword [0xb8004], 0x4f3a4f52
	mov dword [0xb8008], 0x4f204f20
	mov byte  [0xb800a], al
	hlt

section .bss
align 4096
page_table_l4:
	resb 4096
page_table_l3:
	resb 4096
page_table_l2:
	resb 4096
stack_bottom:
	resb 4096 * 4
stack_top:

section .rodata
gdt64:
	dq 0
.code_segment: equ $ - gdt64
	dq (1 << 43) | (1 << 44) | (1 << 47) | (1 << 53)
.pointer:
	dw $ - gdt64 - 1
	dq gdt64 

section .text
bits 64
long_mode_start:
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

	;call kernel_main
    hlt
