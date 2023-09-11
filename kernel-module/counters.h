#pragma once
#include "../types.h"

unsigned long long time_stamp_counter() {
    unsigned high, low;
    asm volatile("rdtsc" : "=a"(low), "=d"(high));
    return ((unsigned long long)low) | ((unsigned long long)high << 32);
}