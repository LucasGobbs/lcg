#include <stdio.h>
#define GLAL_PREFIX 
#define GLAL_IMPLEMENTATION
#include "glal.h"

// gcc -Wall -pedantic -std=c99 -o exe glal_example.c -lm
// gcc -Wno-missing-braces -Wall -pedantic -std=c99 -o exe glal_example.c -lm
void create();
int main(){
	create();

	return 0;
}
void create(){
	Mat2 a = Mat2_create_identity();
	Mat3 b = Mat3_create();

	Mat2 c = Mat2_create_copy(a);
	Mat4 d = { {0} };

	//c = Mat4_create_identity();
	//mat_add(&a, Mat2_create_identity());
	Mat2_print(a);
	Mat3_print(b);
	Mat2_prints(c, "c");
	Mat4_prints(d, "d");
	Mat_print(b)
}
