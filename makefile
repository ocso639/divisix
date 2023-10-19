ARCH = x86_64
TARGET = compiled/boot/kdivisix
MODULES = multiboot-header.o kernel-main.o video-main.o serial-main.o serial.o long-mode.o

ifeq ($(USE_GCC),)
LD = ld
else
LD = $(ARCH)-elf-ld
endif

all:
	make -C ./kernel-module/
	make -C ./video-module/
	make -C ./serial-module/
	$(LD) --script=linker.ld -nostdlib -z max-page-size=0x1000 *.o -o $(TARGET)
clean:
	rm *.o ./kdivisix 2>/dev/null || true
