# makfile configuration

COMMON_OBJECTS  =

CPU             = msp430g2553

CFLAGS          = -mmcu=${CPU} -I../h

LDFLAGS		= -L/opt/ti/msp430_gcc/include



#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc

AS              = msp430-elf-as



all: bomb.elf



#additional rules for files

bomb.elf: ${COMMON_OBJECTS} buzzer.o stateMachine.o wdInterruptHandler.o p2Interrupt.o leds.o switches.o main.o ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^



load: bomb.elf

	msp430loader.sh bomb.elf



clean:

	rm -f *.o *.elf



leds.o: leds.c leds.h



buzzer.c: buzzer.h



wdInterruptHandler.o: stateMachine.h



stateMachine.o: leds.h stateMachine.h

