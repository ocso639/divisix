#include "../types.h"
#include "errors.h"
#include "arguments.h"
#include "string.h"
#define look_amount 255
/*
 *  argument types:
 *  --fat-disable
 *  --silent-boot
 *  --default-shell=(path to shell)
 *  --verbose-message
 *  --end (REQUIRED)
 */

void _start(const char* arg0, ...) {
    //
    // argument detection
    //
    boolean_t fat_disable, terminal_hide, verbose_message = FALSE;
    const char* default_shell;

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
        if (i == look_amount & (strcmp(arg0, "--end") != 0))
            __unconditional_panic();
    }

    
}