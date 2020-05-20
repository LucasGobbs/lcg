#include <stdio.h>
#define GLAL_PREFIX
#define GLAL_IMPLEMENTATION
#include "../glal.h"
// gcc -Wall -pedantic -std=c99 -o exe glal_example.c -lm
// gcc -Wno-missing-braces -Wall -pedantic -std=c99 -o exe glal_example.c -lm

int main(){
    float data[4] = {1, 4, 3, 3};
    Mat2 a = Mat2_create_fromArray(data);
    Mat2 b = Mat2_create_fromArray(data);
    Mat2 c = Mat2_naive_mult_mat(a,b);
    Mat2_print(c);
    return 0;
}

/* outputs



*/