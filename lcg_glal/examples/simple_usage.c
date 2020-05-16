#include <stdio.h>
#define GLAL_PREFIX a_
#define GLAL_IMPLEMENTATION
#include "../glal.h"
// gcc -Wall -pedantic -std=c99 -o exe glal_example.c -lm
// gcc -Wno-missing-braces -Wall -pedantic -std=c99 -o exe glal_example.c -lm
float identity_mult_scalar(size_t i, size_t j, size_t x);

int main(){
	a_Mat2 mat2 = a_Mat2_create();
	a_Mat3 mat3 = a_Mat3_create_identity();
	a_Mat4 mat4 = a_Mat4_create_fill(2.0);
	a_Mat4 copy = a_Mat4_create_copy(mat4);
	a_Mat4 other_mat4 = a_Mat4_create_fill_op(&identity_mult_scalar);

    float data[4] = {0.0, 1.0, 2.0, 3.0};
    a_Mat2 mat_fromArray = a_Mat2_create_fromArray(data);
    a_Mat2 mat_fromArray_transposed = a_Mat2_create_transpose(mat_fromArray);
    
	Mat_print(mat2);
	Mat_print(mat3);
	a_Mat4_prints(mat4, "Original Mat4");
	a_Mat4_prints(copy, "Copy Mat4");
	a_Mat4_prints(other_mat4, "Identity * scalar");
    a_Mat2_prints(mat_fromArray, "Mat from array data");
    a_Mat2_prints(mat_fromArray_transposed, "Mat from array data transposed");
    return 0;
}
float identity_mult_scalar(size_t i, size_t j, size_t x){
	if(i==j){
		return 1 * x;
	} else {
		return 0;
	}
}
/* outputs
	Mat2
    0       0
    0       0

    Mat3
    1.000   0       0
    0       1.000   0
    0       0       1.000

    Original Mat4
    2.000   2.000   2.000   2.000
    2.000   2.000   2.000   2.000
    2.000   2.000   2.000   2.000
    2.000   2.000   2.000   2.000

    Copy Mat4
    2.000   2.000   2.000   2.000
    2.000   2.000   2.000   2.000
    2.000   2.000   2.000   2.000
    2.000   2.000   2.000   2.000

    Identity * scalar
    0       0       0       0
    0       5.000   0       0
    0       0       10.000  0
    0       0       0       15.000

    Mat from array data
    0       1.000
    2.000   3.000

    Mat from array data transposed
    0       2.000
    1.000   3.000
*/