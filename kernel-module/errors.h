// error handling and panic code
#pragma once
#include "../types.h"

void __unconditional_panic() {
    asm volatile("cli\n"
                "hlt");
}


