#pragma once
#include "../types.h"

int strcmp(const char* s1, const char* s2) {
    const char* large_str = (s1 > s2) ? s2 : s1;
    const char* small_str = (s1 > s2) ? s1 : s2;
    //int compare0 = (int)(large_str - small_str);
    //return (compare0 > 0) || (compare0 < 0);
    return (sizeof(large_str) - sizeof(small_str));
}