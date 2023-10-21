#include "../types.h"
#define text_buffer 0xb8000

int row = 0;
int col = 0;
const int max_col = 80 * 2;
const int max_row = 25;

extern void kputs(string_t str, char color_code) {
    uint8_t *video_ptr = ((uint8_t *)text_buffer + col);
    char len = 0;
    while (*str != '\0') {
        switch (*str) {
            case '\n': {
                row++;
                col = (max_col * row);
                return;
            }
            default: {
                len++;
                *(video_ptr++) = *str++;
                *(video_ptr++) = color_code;
            }
        }
    }
    col += len * 2;
    return;
}   