#pragma once
#include "../types.h"
#define psf1_magic      0x0436
#define psf_magic       0x864ab572

unsigned int *framebuffer;
int framebuffer_width;
int framebuffer_height;

int foreground_color;
int background_color;

extern char _binary_font_psf_start;
extern char _binary_font_psf_end;

typedef struct {
    uint16_t magic_number;
    uint8_t font_mode;
    uint8_t character_size;
} psf1_header;

typedef struct {
    uint32_t magic_number;
    uint32_t version;
    uint32_t header_size;
    uint32_t flags;
    uint32_t number_of_glyphs;
    uint32_t bytes_per_glyph;
    uint32_t height;
    uint32_t width;
} psf_font;

psf_font *font = (psf_font*)&_binary_font_psf_start;

void put_char_from_index(int index, int x, int y) {
    unsigned char *glyph = (unsigned char*)&_binary_font_psf_start + font->header_size + (index * font->bytes_per_glyph);
    
    int line;
    for (int i = 0; i < (font->width * font->height); i++) {
                
    }
}