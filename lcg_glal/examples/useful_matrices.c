#include <stdio.h>
#define GLAL_PREFIX 
#define GLAL_IMPLEMENTATION
#include "../glal.h"
// gcc -Wall -pedantic -std=c99 -o exe glal_example.c -lm
// gcc -Wno-missing-braces -Wall -pedantic -std=c99 -o exe glal_example.c -lm


int main(){
	
    Mat4 persp = Mat4_create_perspective((45), 1, 0.001, 1000);
    Mat4_print(persp);
    return 0;
}

/* outputs
	
*/