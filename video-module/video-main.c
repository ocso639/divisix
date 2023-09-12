#include "../types.h"

unsigned int *framebuffer;
int framebuffer_width;
int framebuffer_height;

extern void video_set_framebuffer(uint64_t *ptr, int width, int height) {
    framebuffer = (unsigned int*)ptr;
    framebuffer_width = width;
    framebuffer_height = height;
}

extern void video_clear(int color) {
    for (int i = 0; i < (framebuffer_width * framebuffer_height); i++) {
        framebuffer[i] = color;
    } return;
}

