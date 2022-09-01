#@CopyRight : Fam
CC=arm-none-eabi-
CFLAGS=  -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
obj = $(SRC:.c=.o)
AS=$(wildcard *.s)
ASobj=$(AS:.s=.o)
Project_name=Learn-in-depth-Cortex-m3
all:$(Project_name).bin
	@echo "build is done"
%.o:%.s
	$(CC)as.exe $(CFLAGS) $< -o $@
%.o:%.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@


$(Project_name).elf: $(obj) $(ASobj)
	$(CC)ld.exe -T  linker_Script.ld -Map=Output.map $(LIBS) $(obj) $(ASobj) -o $@

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@	
clean_all:
	rm *.o *.elf *bin
clean:
	rm *.elf *bin
