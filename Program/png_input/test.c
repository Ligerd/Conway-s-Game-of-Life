#include "stdlib.h"
#include "stdio.h"
#include "../matrix_of_cells/matrix_of_cells.h"
#include "png_input.h"
int main(int argc, char** argv)
{
    matrix_s* test;
    test = malloc(sizeof(struct matrix));
    int tablica[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0 || i == 1 || i == 2) {
                if (j == 2) {
                    tablica[i][j] = 1;
                    continue;
                }
            }
            else {
                tablica[i][j] = 0;
            }

            if (i == 3) {
                if (j == 1)
                    tablica[i][j] = 1;
            }
            else {

                tablica[i][j] = 0;
            }
            if (i == 4)
                tablica[i][j] = 1;
        }
    }
    read_png(argv[1], test);

    for (int i = 0; i < test->height; i++)
        for (int j = 0; j < test->width; j++) {
            if (tablica[i][j] == test->matrix[i][j]) {
                continue;
            }
            else {
                printf("Test modułu PNG_INPUT został nie zaakceptowany\n");
                return 1;
            }
        }

    printf("Test modułu PNG_INPUT został zakończony pomyślnie\n");
    free_T(test);
    return 0;
}
