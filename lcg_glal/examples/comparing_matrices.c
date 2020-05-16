#include <stdio.h>
#define GLAL_PREFIX 
#define GLAL_IMPLEMENTATION
#include "../glal.h"
// gcc -Wall -pedantic -std=c99 -o exe glal_example.c -lm
// gcc -Wno-missing-braces -Wall -pedantic -std=c99 -o exe glal_example.c -lm
int main(){
    Mat2 a = Mat2_create();
    Mat2 b = Mat2_create_identity();
    printf("a == b? %d\n", Mat2_equals(a, b));

    b = Mat2_create_copy(a);
    printf("now, a == b? %d\n", Mat2_equals(a, b));
    printf("you sure, a==b? %d\n", Mat2_naive_equals(a,b));
    return 0;
}

/* outputs
a == b? 0
now, a == b? 1
you sure, a==b? 1
*/