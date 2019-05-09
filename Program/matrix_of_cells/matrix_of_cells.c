
#include <stdlib.h>
#include "matrix_of_cells.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int init_T(matrix_s* generation_t, int w, int h)
{
    generation_t->width = w;
    generation_t->height = h;
    if ((generation_t->matrix = malloc(sizeof *generation_t->matrix * h)) == NULL) {
        abort_("[Plik:matrix_of_cellular] Wystąpił błąd podczas alokacji pamięci");
        return 0;
    }
    for (int i = 0; i < h; i++) {
        if ((generation_t->matrix[i] = malloc(sizeof(int) * w)) == NULL) {
            abort_("[Plik:matrix_of_cellular] Wystąpił błąd podczas alokacji pamięci");
            return 0;
        }
    }
    return 1;

}
void free_T(matrix_s* generation_t)
{
    for (int i = 0; i < generation_t->height; i++)
        free(generation_t->matrix[i]);
    free(generation_t->matrix);
   
}

void abort_(const char* s, ...)
{
        va_list args;
        va_start(args, s);
        vfprintf(stderr, s, args);
        fprintf(stderr, "\n");
        va_end(args);
        abort();
}
