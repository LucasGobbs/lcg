#include <stdio.h>
#define GLAL_PREFIX
#define GLAL_IMPLEMENTATION
#include "../glal.h"
// gcc -Wall -pedantic -std=c99 -o exe glal_example.c -lm
// gcc -Wno-missing-braces -Wall -pedantic -std=c99 -o exe glal_example.c -lm
float a_div_b(float a, float b){
    if(a==0){return 0;}
    return (a/b);
}
void operations_a();
void operations_b();
int main(){
    operations_b();
    return 0;
}
void operations_a(){
    Mat3 a = Mat3_create_fill(2.0);
    Mat3 b = Mat3_create_scalar(a, 3.0);
    Mat3_prints(a, "a:");
    Mat3_prints(b, "b: (a * 3)");

    Mat3 c = Mat3_create_add(a,b);
    Mat3 d = Mat3_create_sub(a,b);
    Mat3_prints(c, "c: (a + b)");
    Mat3_prints(d, "d: (a - b)");

    Mat3 e = Mat3_create_op(a, b, &a_div_b);
    Mat3_prints(e, "e: (a / b)");

    Mat3 f = Mat3_create_schur(a, e);
    Mat3_prints(f, "f: (a * e), schur multiplication");
}
void operations_b(){
    Mat3 a = Mat3_create_identity();
    Mat3 b = Mat3_create_fill(3.0);
    Mat3 c = Mat3_create();
    Mat3_print(a);
    Mat3_print(b);
    Mat3_op(&a, b, &a_div_b);
    Mat3_print(a);
    Mat3_print(b);
}
/* outputs
 operations_a and operations_b prints the same
a:
2.000   2.000   2.000
2.000   2.000   2.000
2.000   2.000   2.000

b: (a * 3)
6.000   6.000   6.000
6.000   6.000   6.000
6.000   6.000   6.000

c: (a + b)
8.000   8.000   8.000
8.000   8.000   8.000
8.000   8.000   8.000

d: (a - b)
-4.000  -4.000  -4.000
-4.000  -4.000  -4.000
-4.000  -4.000  -4.000

e: (a / b)
0.333   0.333   0.333
0.333   0.333   0.333
0.333   0.333   0.333

f: (a * e), schur multiplication
0.667   0.667   0.667
0.667   0.667   0.667
0.667   0.667   0.667

*/