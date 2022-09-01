/*Startup_CortexM3
ENG.FAM
*/
.section .Vectors
.word 0x20001000
.word _reset
.word _Vector_Handler  // _NMI_Handler
.word _Vector_Handler  //_Hard_Fault_Handler
//SRAM 0x20000000

.section .text
_reset:
     bl main
     b  .
.thumb_func
_Vector_Handler:
     b _reset
     
	