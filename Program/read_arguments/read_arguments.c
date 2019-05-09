#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "read_arguments.h"
#include "../matrix_of_cells/matrix_of_cells.h"
#define domyslna_ilosc_generacji 50

int read_arguments( int n, char ** t, arguments_s * s)
{
    int check1 = 0, check2 = 0;
    s->series_or_one = 1;
    s->if_gif = 1;
    s->gen_nr = domyslna_ilosc_generacji;
    strcpy ( s->output_name, "wynik" );
    strcpy ( s->input_name, "" );

    if ( n < 2 )
    {
        printf("Brak argumentow wymaganych do uruchomienia programu. \n");
                    return -1;
    }

    for ( int i = 1; i < n; ++i)
    {
        if (strcmp ("-gif", t[i]) == 0 )
        {
            if ( check1 == 0 )
            {
                if ((++i) == n)
               {
                   printf("Brak liczby generacji!.\n");
                   return -1;
               }

                if ( atoi(t[i]) > 0 )
               {
                   s->gen_nr = atoi (t[i]);
                   s->series_or_one = 1;
                   s->if_gif = 1;
                   check1 = 1;
                }
                else
                {
                    printf("%s nie jest poprawna liczba generacji.\n", t[i]);
                    return -1;
                }
            }
            else
            {
                printf("Blad! Przed argumentem -gif wystapil juz argument -k lub -s! Podaj tylko jeden z tych argumentow!\n");
                return -1;
            }

        }
        else
        if (strcmp ("-k", t[i]) == 0)
        {
            if ( check1 == 0 )
            {
               if ((++i) == n)
               {
                   printf("Brak liczby generacji!.\n");
                   return -1;
               }
               if ( atoi(t[i]) > 0 )
               {
                   s->gen_nr = atoi (t[i]);
                   s->series_or_one = 0;
                   s->if_gif = 0;
                   check1 = 1;
                }
                else
                {
                    printf("%s nie jest poprawna liczba generacji.\n", t[i]);
                    return -1;
                }
            }
            else
            {
              printf("Blad! Przed argumentem -k wystapil juz argument -gif lub -s! Podaj tylko jeden z tych argumentow!\n");
              return -1;
            }
        }
        else
        if (strcmp ("-s", t[i]) == 0)
        {
            if ( check1 == 0 )
            {
               if ((++i) == n)
               {
                   printf("Brak liczby generacji!.\n");
                   return -1;
               }
               if ( atoi(t[i]) > 0 )
               {
                   s->gen_nr = atoi (t[i]);
                   s->series_or_one = 1;
                   s->if_gif = 0;
                   check1 = 1;
                }
                else
                {
                    printf("%s nie jest poprawna liczba generacji.\n", t[i]);
                    return -1;
                }

            }
            else
            {
                printf("Blad! Przed argumentem -s wystapil juz argument -gif lub -k! Podaj tylko jeden z tych argumentow!\n");
                return -1;
            }
        }
        else
        if (strcmp ("-fo", t[i]) == 0)
        {
           i++;
           strcpy( s->output_name, t[i] );
        }
        else
        if (strcmp ("?", t[i]) == 0)
        {
            printf ("Program mozemy wywolac z argumentami:\n");
            printf("Nazwe pliku wejsciowego podajemy bez poprzedzania go zadnym argumentem.\n");
            printf ("-gif ilosc_generacji <- tryb generowania wszystkich generacji do serii plikow PNG oraz pliku GIF \n");
            printf ("-s ilosc_generacji <- tryb generowania wszystkich generacji do serii plików PNG\n");
            printf ("-k ilosc_generacji <- tryb generowania konkretnej generacji do pliku PNG.\n");
            printf ("-fo nazwa_pliku_wyjsciowego.\n");
            return -1;
        }
        else
        if ( strstr(t[i], ".png") != NULL )
        {
            if ( check2 == 0 )
            {
               strcpy( s->input_name, t[i] );
               s->png_or_txt = 1;
               check2 = 1;
            }
            else
            {
              printf("Podano dwa pliki zrodlowe!\n");
            }
        }
        else
        if (strstr(t[i], ".txt") != NULL )
        {
            if ( check2 == 0 )
            {
               strcpy( s->input_name, t[i] );
               s->png_or_txt = 0;
               check2 = 1;
            }
            else
            {
                printf("Podano dwa pliki zrodlowe!\n");
                return -1;
            }
        }
        else
        {
            printf("Flaga %s jest niepoprawna. Podaj poprawne argumenty.\n", t[i]);
            printf ("Program mozemy wywolac z argumentami:\n");
            printf("Nazwe pliku wejsciowego podajemy bez poprzedzania go zadnym argumentem.\n");
            printf ("-gif ilosc_generacji <- tryb generowania wszystkich generacji do serii plikow PNG oraz pliku GIF \n");
            printf ("-s ilosc_generacji <- tryb generowania wszystkich generacji do serii plików PNG\n");
            printf ("-k ilosc_generacji <- tryb generowania konkretnej generacji do pliku PNG.\n");
            printf ("-fo nazwa_pliku_wyjsciowego.\n");
            return -1;

        }

        if ( strcmp ( "", s->input_name ) == 0 && i == n-1)
        {
            printf("Brak argumentu okreslajacego nazwe pliku.\n");
            return -1;
        }


    }
}


