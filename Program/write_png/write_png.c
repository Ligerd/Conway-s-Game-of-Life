
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "write_png.h"
#include <png.h>
void write_png(matrix_s* generation_t, char* file_name)
{

    png_byte color_type;
    png_structp png_ptr;
    png_infop info_ptr;
    png_bytep* row_pointers;

    color_type = PNG_COLOR_TYPE_GRAY;
    png_byte bit_depth = 8;

    
    if ((row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * generation_t->height)) == NULL)
        abort_("[write_png] Wystopił błąd podczas alokacji pamięci");

    for (int i = 0; i < generation_t->height; i++) {
        if ((row_pointers[i] = (png_byte*)malloc(sizeof(png_byte) * generation_t->width)) == NULL)
            abort_("[write_png] Wystopił błąd podczas alokacji pamięci");
    }

    for (int i = 0; i < generation_t->height; i++) {
        for (int b = 0; b < generation_t->width; b++) {
            if (generation_t->matrix[i][b] == 1) {
                row_pointers[i][b] = 0;
            }
            else {
                row_pointers[i][b] = 255;
            }
        }
    }
    FILE* fp = fopen(file_name, "wb");
    if (!fp)
        abort_("[write_png] Plik %s nie może być otwarty do zapisywania", file_name);

    /* initialize stuff */
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!png_ptr)
        abort_("[write_png] Nie udało się stworzyć  png_create_write_struct ");

    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
        abort_("[write_png] Nie udało się stworzyć png_create_info_struct");

    if (setjmp(png_jmpbuf(png_ptr)))
        abort_("[write_png] Wystopił błąd podczas inicyalizacji init_io");

    png_init_io(png_ptr, fp);

    /* write header */
    if (setjmp(png_jmpbuf(png_ptr)))
        abort_("[write_png] Wystopił bład podczas wypisywania nagłówka");

    png_set_IHDR(png_ptr, info_ptr, generation_t->width, generation_t->height,
        bit_depth, color_type, PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_write_info(png_ptr, info_ptr);

    /* write bytes */
    if (setjmp(png_jmpbuf(png_ptr)))
        abort_("[write_png] Wystopił bład podczas wypisywania ");

    png_write_image(png_ptr, row_pointers);

       /* end write */
    if (setjmp(png_jmpbuf(png_ptr)))
        abort_("[write_png] Wystopił bład podczas zakończenia wypisywania");

    png_write_end(png_ptr, NULL);

    png_destroy_write_struct(&png_ptr, &info_ptr);
    for (int i = 0; i < generation_t->height; i++)
        free(row_pointers[i]);
    free(row_pointers);
    fclose(fp);
}
