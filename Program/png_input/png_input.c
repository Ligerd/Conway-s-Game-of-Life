#include "png_input.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <png.h>

int read_png(char* file_name, matrix_s* generation_t)
{

    int width = 0;
    int height = 0;
    png_byte color_type;
    png_byte bit_depth;

    png_structp png_ptr;
    png_infop info_ptr;
    int number_of_passes;
    png_bytep* row_pointers;

    char header[8]; // 8 is the maximum size that can be checked

    /* open file and test for it being a png */
    FILE* fp = fopen(file_name, "rb");
    if (!fp)
        abort_("[png_input] Plik %s nie może być otwarty do czytania", file_name);
    fread(header, 1, 8, fp);
    if (png_sig_cmp(header, 0, 8))
        abort_("[png_input] Plik %s nie jest rozpoznany jako PNG file", file_name);

    /* initialize stuff */
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!png_ptr)
        abort_("[png_input] Nie udało się stworzyć png_create_read_struct ");

    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
        abort_("[png_input] Nie udało się stworzyć png_create_info_struct ");

    if (setjmp(png_jmpbuf(png_ptr)))
        abort_("[png_input] Wystopił błąd podczas inicyalizacji init_io");
    png_infop end_info = png_create_info_struct(png_ptr);
    png_init_io(png_ptr, fp);
    png_set_sig_bytes(png_ptr, 8);

    png_read_info(png_ptr, info_ptr);

    width = png_get_image_width(png_ptr, info_ptr);
    height = png_get_image_height(png_ptr, info_ptr);
    color_type = png_get_color_type(png_ptr, info_ptr);
    bit_depth = png_get_bit_depth(png_ptr, info_ptr);

    number_of_passes = png_set_interlace_handling(png_ptr);
    png_read_update_info(png_ptr, info_ptr);

    /* read file */
    if (setjmp(png_jmpbuf(png_ptr)))
        abort_("[png_input] Błąd podczas wczytywania obrazu");

    if ((row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height)) == NULL) {
        abort_("[png_intput] Wystopił błąd podczas alokacji pamięci");
    }
    for (int y = 0; y < height; y++) {
        if ((row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png_ptr, info_ptr))) == NULL)
            abort_("[png_intput] Wystopił błąd podczas alokacji pamięci");
    }
    png_read_image(png_ptr, row_pointers);

    fclose(fp);

    init_T(generation_t, width, height);

    for (int i = 0; i < generation_t->height; i++) {
        for (int b = 0; b < generation_t->width; b++) {
            if (row_pointers[i][b * (png_get_rowbytes(png_ptr, info_ptr) / generation_t->width)] == 0) {
                generation_t->matrix[i][b] = 1;
            }
            else {
                generation_t->matrix[i][b] = 0;
            }
        }
    }
    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
    for (int i = 0; i < generation_t->height; i++)
        free(row_pointers[i]);
    free(row_pointers);
}

