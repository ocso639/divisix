#include "../types.h"
#define text_buffer 0xb8000

extern void puts(const char *str, char color_code) {
    unsigned char *video_iterator = ((unsigned char*)text_buffer);
    while (*str != '\0') {
        *(video_iterator++) = *str++;
        *(video_iterator++) = color_code;
    }
}