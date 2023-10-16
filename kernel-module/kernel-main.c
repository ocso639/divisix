// DIVISIX μK
#include "../types.h"
#include "errors.h"
#include "arguments.h"
#include "string.h"
#include "serial.h"
#include "video.h"
#define look_amount 255

/*
 *  argument types:
 *  --fat-disable
 *  --silent-boot
 *  --default-shell         (path to shell)
 *  --verbose-message 
 *  --end                               (REQUIRED)
 */

void _kentry(const char* arg0, ...) {
    //
    // argument detection
    //
    boolean_t   fat_disable, 
                terminal_hide, 
                verbose_message = FALSE;

    const char* default_shell;
    //uint64_t    *framebuffer_address;
    //int         framebuffer_width;
    //int         framebuffer_height;

    serial_start(); // start logging

    //unsigned long *text = 0x2f592f412f4b2f4f;

    // we could be reading irrelevant data
    for (int i = 0; i < look_amount; i++) {
        const char* arg = (const char*)get_argument(&arg0, i);
        if (strcmp(arg0, "--fat-disable"))
            fat_disable = TRUE;
        if (strcmp(arg0, "--silent-boot"))
            terminal_hide = TRUE;
        if (strcmp(arg0, "--default-shell"))
            default_shell = (const char*)get_argument(&arg0, i++);
        if (strcmp(arg0, "--verbose-message"))
            verbose_message = TRUE;
        if (strcmp(arg0, "--end"))
            break;
    }


    puts("DIVISIX KERNEL", 7);
    //halt the system
    while(1) {}
}