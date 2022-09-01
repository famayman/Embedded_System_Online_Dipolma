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
		*(.Vectors*)
		*(.text*)
	} >flash
	
	.data :
        {
		*(.data)        
	}>flash
	
	.bss : 
        {
	*(.bss*)
	. = . + 0x1000;
	stack_top = .; 
	}>sram
}