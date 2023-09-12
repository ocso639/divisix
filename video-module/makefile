ARCH = x86_64
SRCS = $(ls *.c)
TARGET = ../kdivisix
OBJCOPY = objcopy

all: $(TARGET)
ifeq ($(USE_GCC),)
CC = clang -target $(ARCH)-elf
else
CC = gcc -m64
endif


$(TARGET): video-main.c
	objcopy -O elf64-x86-64 -B i386 -I binary font.psf ../font.o
	$(CC) -ffreestanding -fno-stack-protector -fno-stack-check -D__$(ARCH)__ -I. -c $< -o ../video-main.o
#	$(LD) -nostdlib -z max-page-size=0x1000 -Ttext=0x01000000 kernel-main.o -o $(TARGET)

clean:
	rm //*.o $(TARGET) 2>/dev/null || true