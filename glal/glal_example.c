#include <stdio.h>
#define GLAL_PREFIX 
#define GLAL_IMPLEMENTATION
#include "glal.h"

//gcc -Wall -pedantic -std=c99 -o exe example.c -lm
void create();
int main(){
	create();

	return 0;
}
void create(){
	Mat2 a = Mat2_create_identity();
	Mat3 b = Mat3_create();

	Mat4 c = Mat4_create();
	// Same of this
	Mat4 d = { 0 };

	c = Mat4_create_identity();
	mat_add(&a, Mat2_create_identity());
	Mat2_print(a);
	Mat3_print(b);
	Mat4_prints(c, "c");
	Mat4_prints(d, "d");
}
