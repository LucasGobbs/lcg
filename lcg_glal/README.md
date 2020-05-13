# glal 
single header file, linear algebra library for opengl

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
| Name        |  Description | Mat2 | Mat3 | Mat4 |  Arguments | return |
| ------------- |-------------:| :-------------:| :-------------:| :-------------:|  :-------------:|  :-------------:| 
| create |  creates a matrix | **yes** | **yes** | **yes** |  **none** |  Matx | 
| print | prints a matrix | **yes** | **yes** | **yes** |  Matx |  void| 
| prints| prints a matrix and some text|**yes** | **yes** | **yes** |  Matx, char*|  void| 







