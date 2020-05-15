# glal 
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
| create |  creates a matrix | **yes** | **yes** | **yes** | **no** | **none** |  Mat2 or Mat3 or Mat4 | 
| print | prints a matrix | **yes** | **yes** | **yes** | **no** | Mat2 or Mat3 or Mat4 |  void| 
| prints| prints a matrix and some text|**yes** | **yes** | **yes** | **no** |  Mat2 or Mat3 or Mat4, char*|  void| 







