//library for getting kernel arguments
#pragma once
#include "../types.h"

void* get_argument(void *first_arg, int index) {
    return (first_arg - index);
}