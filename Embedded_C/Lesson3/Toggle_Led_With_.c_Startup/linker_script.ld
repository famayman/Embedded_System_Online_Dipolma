/*perpared by
ENG FAM
*/
MEMORY
{
	flash(RX) : ORIGIN = 0x08000000 , LENGTH = 128k
	sram(RWX) : ORIGIN = 0x20000000 , LENGTH = 20k
}

SECTIONS
{
	.text : 
        {
		*(.vectors*)
		*(.text*)
		E_text = . ;
	} >flash
	
	.data :
        {
		S_data = .;
		*(.data)
                . = ALIGN(4) ;
		E_data = .;
	}>sram AT>flash
	
	.bss : 
        {
	S_bss = . ;
	*(.bss*)
	E_bss = .;
	. = ALIGN(4);
	. = . + 0x1000;
	stack_top = .; 
	} > sram
}