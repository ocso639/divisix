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
    //halt the system
    kputs("Divisix Kernel x86-64 Revision 00:01\n", 0xF);
    for (int i = 0; i < 24; i++) {
        kputs("newlines test\n", 0xF);
    }
    
    while(1) {}
}   