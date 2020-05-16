# GLal 
single header file, linear algebra library for opengl with Mat2, Mat3 and Mat4 types

# Disclaimer 
This is a very in early version, and make extensive usage of the C preprocesor. so for now is very unpredictable

# Usage
drop the glal.h file in your project tree, and define the implementation before the first reference
```c
#define GLAL_IMPLEMENTATION
#include "glal.h"
```
## Types
| Types        | Description       | 
| ------------- |:-------------:| 
| Mat2    | 2 by 2 matrix |
| Mat3     | 3 by 3 matrix      | 
| Mat3 | 4 by 4 matrix      |
### Namespace details
all functions have namespace **glal_** by default, but you can specify other namespace by using
```c
#define GLAL_PREFIX your_namespace
// or for no namespace 
#define GLAL_PREFIX
```
Also functions have the type wich it handles in the prefix
```c
glal_Mat2_create();
//or depending of namespace
Mat2_create();
```
### Matrix Layout
The matrices are stored column major order


### Personalization
By default the data in the matrix is float but you can change to GLfloat or etc using
```c
#define GLAL_TYPE GLfloat
```
## Functions
The functions names are like GlalPrefix_Matx_FunctionName
example:
```c
glal_Mat2_create();
glal_Mat3_create();
...
//or depending of namespace
Mat2_create();
Mat3_create();
```
Also some functions have some generic call, like:
Matx_function((2 or 3 or 4), ...);
```c
Mat2 a;
Mat3 b;
Matx_print(2,a);
Matx_print(3,b);
...
```
and some of them have a short call by macro expansion
```c
Mat2 a;
Mat3 b;
Mat_print(a); // This is a macro
Mat_print(b); // This is a macro
```
| Name        |  Description | Mat2 | Mat3 | Mat4 | Matx/short call macro | Arguments | return | 
| ---------- |----------:| :----------:| :--------| :-------:|  :-------:|  :-------:|  :-------:|
| create |  creates a matrix | **yes** | **yes** | **yes** | **no/no** | **none** |  Mat2 or Mat3 or Mat4 | 
| print | prints a matrix | **yes** | **yes** | **yes** | **yes/yes** | Mat2 or Mat3 or Mat4 |  void| 
| prints| prints a matrix and some text|**yes** | **yes** | **yes** | **no/no** |  Mat2 or Mat3 or Mat4, char*|  void| 
| create_identity|  creates a identity matrix |**yes** | **yes** | **yes** | **no/no** |**none**|  Mat2 or Mat3 or Mat4| 
|create_copy|  creates a copy of a given matrix |**yes** | **yes** | **yes** | **no/no** |  Mat2 or Mat3 or Mat4|  Mat2 or Mat3 or Mat4| 
|create_transpose|  creates a transpose copy of a given matrix |**yes** | **yes** | **yes** | **no/no** |  Mat2 or Mat3 or Mat4|  Mat2 or Mat3 or Mat4| 
|create_fill|  creates a matrix and fill with given value |**yes** | **yes** | **yes** | **no/no** |float|  Mat2 or Mat3 or Mat4| 
|create_fill_op|  creates a matrix and fill with output of given function (more details down) |**yes** | **yes** | **yes** | **no/no** |float(*operation)(size_t i, size_t j, size_t x)|  Mat2 or Mat3 or Mat4| 
|create_fromArray|  creates a matrix with the data given in the array |**yes** | **yes** | **yes** | **no/no** |  float* |  Mat2 or Mat3 or Mat4| 

#### Functions with op in the name
These functions receive by input a function that will be use
example
create_fill_op takes a function that you define
```c
float identity_matrix(size_t i, size_t j, size_t x){
	if(i==j){
		return 1;
	} else {
		return 0;
	}
}
...
glal_mat_create_fill_op(&identity_matrix);
```
and the function works like (pseudocode)
```c
matrix mat;
int i = 0, j = 0, x = 0;
for(i = 0 ; i < rows ; i++){
    for(j = 0; j < colums ; j++){
        mat[i][j] = function_given(i, j, x);
        x++;
    }
}
return mat;
```
so by each member of the matrix i represents their rows coord, j their column coord, and x the linear coord.
every function with op receives a diferent function style


