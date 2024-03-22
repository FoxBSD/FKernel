ENTRY(start)

SECTIONS
{
	. = 1M;

	.boot : ALIGN(4K)
	{
		KEEP(*(.multiboot_header))
	}

	.text : ALIGN(4K)
	{
		*(.text .text.*)
	}

	.rodata : ALIGN(4K)
	{
		*(.rodata .rodata.*)
	}

	.data : ALIGN(4K)
	{
		*(.data .data.*)
	}

	.bss : ALIGN(4K)
	{
		*(.bss .bss.* COMMON)
	}

	. = ALIGN(4K);
	_end = .;
}
