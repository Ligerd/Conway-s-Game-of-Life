#ifndef READ_ARGUMENTS_H
#define READ_ARGUMENTS_H

typedef struct
{
    int gen_nr;
    int series_or_one;
    char input_name[100];
    char output_name[100];
    int if_gif;
    int png_or_txt;

} arguments_s;

int read_arguments( int n, char ** t, arguments_s * s);

#endif
