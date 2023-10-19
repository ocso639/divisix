// DIVISIX μK
#include "../types.h"
#include "errors.h"
#include "arguments.h"
#include "string.h"
#include "serial.h"
#include "video.h"

void _kentry(const char* arg0, ...) {
    //
    // argument detection
    //
    boolean_t   fat_disable, 
                verbose_message = FALSE;

    const char* default_shell;

    serial_start();

    puts("Divisix Kernel version (00:01)\n", 0xF);
    puts("LOADED", 0xF);
    //halt the system
    while(1) {}
}