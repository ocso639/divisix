#pragma once
#include "../types.h"

const unsigned int *efi_framebuffer;

//
// sets the framebuffer to the specified 64 bit memory address, allowing useful output
//
const void set_framebuffer(uint64_t *address) {
    efi_framebuffer = (unsigned int*)address;
}

 