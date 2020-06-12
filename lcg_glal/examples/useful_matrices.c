#include <stdio.h>
#define GLAL_PREFIX 
#define GLAL_IMPLEMENTATION
#include "../glal.h"
// gcc -Wall -pedantic -std=c99 -o exe lcg_glal/examples/useful_matrices.c -lm
// gcc -Wno-missing-braces -Wall -pedantic -std=c99 -o exe glal_example.c -lm


int main(){
	
   // Mat4 persp = Mat4_create_perspective((45), 1, 0.001, 1000);
    Vec4 dir = Vec4_create_fromArg(1.0, 0.0, 0.0, 0.0);
    Vec4_prints(dir, "Antes");
    Mat4 rotate = Mat4_create_rotationY(20.0);

    Vec3_prints(Vec4_toVec3(Vec4_mult_mat(dir, rotate)), "Matrix");
    Vec3_prints(Vec3_qrotate(Vec4_toVec3(dir),Vec3_create_fromArg(0.0, 1.0, 0.0),20.0), "quaternion");
    //Mat4_print(persp);
    return 0;
}

/* outputs
	
*/