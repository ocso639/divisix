#include "psf.h"

extern void video_set_framebuffer(uint64_t *ptr, int width, int height) {
    framebuffer = (unsigned int*)ptr;
    framebuffer_width = width;
    framebuffer_height = height;
}

extern void video_set_foreground_color(int color) {
    foreground_color = color;
}

extern void video_set_background_color(int color) {
    background_color = color;
}


extern void video_clear() {
    for (int i = 0; i < (framebuffer_width * framebuffer_height); i++) {
        framebuffer[i] = background_color;
    } return;
}

