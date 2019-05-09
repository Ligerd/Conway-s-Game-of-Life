#ifndef MATRIX_OF_CELLS_H
#define MATRIX_OF_CELLS_H
#include <png.h>
typedef struct matrix {
	int width;
	int height;
	int **matrix;
} matrix_s;
int init_T (matrix_s * generation_t, int w, int h);
void free_T (matrix_s *generation_t);
void abort_(const char * s, ...);
#endif 