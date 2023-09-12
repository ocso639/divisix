ARCH = x86_64
TARGET = kdivisix
MODULES = kernel-main.o video-main.o

ifeq ($(USE_GCC),)
LD = ld
else
LD = $(ARCH)-elf-ld
endif

all:
	make -C ./kernel-module/
	make -C ./video-module/
	$(LD) -nostdlib -z max-page-size=0x1000 -Ttext=0x01000000 $(MODULES) -o $(TARGET)
clean:
	rm *.o ./kdivisix 2>/dev/null || true
