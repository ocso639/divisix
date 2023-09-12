// error handling and panic code
#pragma once
#include "../types.h"

// 10 GOTO 10
void __unconditional_panic() {
    asm volatile("cli\n"
                "hlt");
}

