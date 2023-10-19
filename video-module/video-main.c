#include "../types.h"
#define text_buffer 0xb8000

char row = 0;
char col = 0;
const int max_col = 80 * 2;
const int max_row = 25;

extern void puts(string_t str, char color_code) {
    uint8_t *video_ptr = ((uint8_t *)text_buffer);
    char len = 0;
     while (*str != '\0') {
        switch (*str) {
            case '\n': {
                row++;
                col = max_col * row; //todo: fix this
                return;
            }
            default: {
                len++;
                *(video_ptr++ + (col)) = *str++;
                *(video_ptr++ + (col)) = color_code;
            }
        }
     }
     col += len * 2;
}   

/*extern void puts(const char *str, char color_code) {
    unsigned char *video_iterator = ((unsigned char*)text_buffer);
    while (*str != '\0') {
        *(video_iterator++) = *str++;
        *(video_iterator++) = color_code;
    }
}*/