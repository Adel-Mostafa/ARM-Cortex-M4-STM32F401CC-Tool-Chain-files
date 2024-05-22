## variables to easily implememnt rules
ACC = arm-none-eabi-gcc		
MACH = cortex-m4
CFLAGS = -c -mcpu=$(MACH) -std=gun11 -mthumb -Wall			## $ -> means get inside the variable 
LN = -T stm32f401cc_linkerscript.ld -nostdlib

## for makefile functionlaity check
hello:
	echo "Hello , world"

## $^ -> dependancy
## $@ -> target (rule name)
main.a:main.c
	$(ACC) -S main.c -o main.asm

main.o:main.c
	$(ACC) -c $^ -o $@

mrcc.o:MRCC_Program.c
	$(ACC) -c $^ -o $@

mgpio.o:MGPIO_Program.c
	$(ACC) -c $^ -o $@

stm32f401_startupfile.o : STM32F401_Startupfile.c
	$(ACC) -c $^ -o $@

all :main.o mrcc.o mgpio.o stm32f401_startupfile.o

file.elf :
	$(ACC) *.o $(LN) -o file.elf

file.map :
	$(ACC) *.o $(LN) -o file.elf -Wl,-Map=file.Map

analsis:
	arm-none-eabi-objdump -h file.elf

symboltable.txt :
	arm-none-eabi-nm file.elf >symboltable.txt

## linux commands for Git Bash
## rm -> remove 
## r  -> remove the content of the files
## f  -> ignore noneexistent files and arguments
clean:
	rm -f -r *.o *.elf *.Map *.txt

change format :
	aarm-none-eabi-objcopy 





