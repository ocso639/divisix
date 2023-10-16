#include "codes.h"
#include "../types.h"
extern void init_serial();
extern void outs(uint64_t a, uint64_t b);

extern void serial_start() {
    init_serial();
}

// output to serial/terminal
extern void t_puts(const char *s) {
    
}