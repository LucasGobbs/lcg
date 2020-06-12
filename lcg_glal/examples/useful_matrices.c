#include <stdio.h>
#define GLAL_PREFIX 
#define GLAL_IMPLEMENTATION
#include "../glal.h"
// gcc -Wall -pedantic -std=c99 -o exe lcg_glal/examples/useful_matrices.c -lm
// gcc -Wno-missing-braces -Wall -pedantic -std=c99 -o exe glal_example.c -lm
void model_view_projection();
void rotation_matrix();
void rotation_quaternion();
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
void model_view_projection(){
    Vec3 camera_pos = Vec3_create_fromArg(-10.0, 0.0, 0.0);
    Vec3 camera_target = Vec3_create_fromArg(0.0, 0.0, 0.0);
    Vec3 camera_up = Vec3_create_fromArg(0.0, 1.0, 0.0);

    Mat4 projection = Mat4_create_perspective(45.0, 1920/1080, 0.1, 1000);
    Mat4 view = Mat4_create_lookAt(camera_pos, camera_target, camera_up);
    Mat4 model = Mat4_create_rotationX(45.0);
    
    

}
void rotation_matrix(){

}
void rotation_quaternion(){

}

/* outputs
	
*/