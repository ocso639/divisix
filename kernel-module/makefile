ARCH = x86_64
SRCS = $(ls *.c)
TARGET = ../kdivisix

all: $(TARGET)
ifeq ($(USE_GCC),)
CC = clang -target $(ARCH)-elf
#LD = ld
else
CC = gcc -m64
#LD = $(ARCH)-elf-ld
endif

$(TARGET): kernel-main.c
	nasm multiboot-header.s -o ../multiboot-header.o -f elf64
	nasm long-mode.s -o ../long-mode.o -f elf64
	$(CC) -ffreestanding -fno-stack-protector -fno-stack-check -D__$(ARCH)__ -I. -c $< -o ../kernel-main.o
#	$(LD) -nostdlib -z max-page-size=0x1000 -Ttext=0x01000000 kernel-main.o -o $(TARGET)

clean:
	rm //*.o $(TARGET) 2>/dev/null || true