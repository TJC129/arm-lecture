CC	= arm-linux-gnueabihf-gcc
CFLAGS	= -O0 -ggdb -Wall 
LDFLAGS = -fno-stack-protector

objects	= fibseq.o fib.o

default: fibseq

.PHONY: default clean qemu plot

fibseq: $(objects)
	$(CC) $(LDFLAGS) -o $@ $^

fib.o: fib.s
fibseq.o: fibseq.c

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

%.o: %.s
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(objects) fibseq

QEMU_CMD = qemu-arm -L /usr/arm-linux-gnueabihf ./fibseq
qemu:
	rm -f fib.txt
	i=0; while [ $$i -le 47 ]; do echo $$i; \
	yes $$i | $(call QEMU_CMD); \
	i=$$(($$i+1)); done
	
plot: qemu
	gnuplot -e "filename='fib.txt'" plot.gnu
	xdg-open fib.png

