#include "stdlib.h"
#include "stdio.h"
#include "../matrix_of_cells/matrix_of_cells.h"
#include "write_png.h"
int main (int argc, char **argv){
matrix_s *test;
test=malloc(sizeof ( struct matrix));
init_T (test,5,5);

for(int i = 0; i < test->height; i++){
    for(int j = 0; j < test->width; j++){
    if(i==0||i==1||i==2){
    if(j==2){
    		test->matrix[i][j]=1;
			continue;
			}
	}
	else {
		test->matrix[i][j]=0;
	}  


    if(i==3){
    	if(j==1)
    		test->matrix[i][j]=1;
    }
    else{
    
    test->matrix[i][j]=0;
    }
    if(i==4)
    	test->matrix[i][j]=1;
    }


}


write_png( test,"wyniki/wynik_testu.png");
free_T (test);
free (test);
return 0;
/*matrix_S *test2;
test2=malloc(sizeof(struct matrix));
init_T(test2,10, 5 );
for(int i=0; i<test2->height; i++){
    for(int j=0;j<test2->width;j++){
        if(i==0 || i==4){
            test2->matrix[i][j]=1;
            continue;
        }

        if (j==0|| j==4|| j==5 || j==9){
            test2->matrix[i][j]=1;
            continue;
        }
        test2->matrix[i][j]=0;

    }
}

write_png(test2,"wynik_testu",2);
free_T(test2); */
}
