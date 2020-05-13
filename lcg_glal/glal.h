#ifndef GLAL_H
#define GLAL_H


#ifndef GLAL_PREFIX 
	#define GLAL_PREFIX glal_
#endif // GLAL_PREFIX

#ifndef TYPE
	#define TYPE float
#endif //TYPE

#define GLAL_STRINGIFY(a) #a
#define GLAL_CONCAT(a, b) GLAL__CONCAT(a,b)
#define GLAL__CONCAT(a, b) a ## b
#define ns(a) GLAL_CONCAT(GLAL_PREFIX,a)
#define MATRIX_NAME(rows, colums) GLAL_CONCAT(Mat, GLAL_CONCAT(rows, colums))
#define GLAL_MATRIX_TYPE(name, rows, colums) typedef struct {\
	TYPE data[rows][colums];\
}ns(name)\


#define ITER(size, i) i=0;i<size;i++
#define FOREACH(size, i) for(ITER(size, i))
#define MGET(mat, i, j) mat.data[i][j]

#define GLAL_isType(type, x) (__builtin_types_compatible_p(__typeof__(x), type))
#define GLAL_isMat2(mat) (GLAL_isType(Mat2, mat))
#define GLAL_isMat3(mat) (GLAL_isType(Mat3, mat))
#define GLAL_isMat4(mat) (GLAL_isType(Mat4, mat))

GLAL_MATRIX_TYPE(Mat2,2,2);
GLAL_MATRIX_TYPE(Mat3,3,3);
GLAL_MATRIX_TYPE(Mat4,4,4);

#define EXPAND_DEF(def) def(Mat2, 2, 2); def(Mat3, 3, 3); def(Mat4, 4, 4);
#define EXPAND_IMPL(impl) impl(Mat2, 2, 2) impl(Mat3, 3, 3) impl(Mat4, 4, 4)

// Create Simple matrix
#define Mat_create_def(name, rows, colums) name GLAL_CONCAT(name, _create)()
#define Mat_create_impl(name, rows, colums) Mat_create_def(name, 4, 4){\
	name a = { { 0 }  }; return a; \
}\

// Print matrix
#define Mat_print_def(name, rows, colums) void GLAL_CONCAT(name, _print)(name mat)
#define Mat_print_impl(name, rows, colums) Mat_print_def(name, rows, colums){\
	int i, j;\
	printf(""#name "\n");\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			TYPE data = MGET(mat, i, j);\
			if(data==0.0){\
				printf("0\t");\
			} else {\
				printf("%.3f\t", data);\
			}\
		}\
		printf("\n");\
	}\
	printf("\n");\
}\
// Print String befor printinf matrix
#define Mat_prints_def(name, rows, colums) void GLAL_CONCAT(name, _prints)(name mat, char* txt)
#define Mat_prints_impl(name, rows, colums) Mat_prints_def(name, rows, colums){\
	int i, j;\
	printf("%s\n",txt);\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			TYPE data = MGET(mat, i, j);\
			if(data==0.0){\
				printf("0\t");\
			} else {\
				printf("%.3f\t", data);\
			}\
		}\
		printf("\n");\
	}\
	printf("\n");\
}\

#define Mat_create_identity_def(name, rows, colums) name GLAL_CONCAT(name, _create_identity)()
#define Mat_create_identity_impl(name, rows, colums) Mat_create_identity_def(name, rows, colums){\
	int i;\
	name mat = { {0} };\
	FOREACH(rows, i){\
		MGET(mat, i, i) = 1.0;\
	}\
	return mat;\
}\

#define Mat_create_copy_def(name, rows, colums) name GLAL_CONCAT(name, _create_copy)(name mat)
#define Mat_create_copy_impl(name, rows, colums) Mat_create_copy_def(name, rows, colums){\
	name rt = { {0} };\
	return rt;\
}\

#define Mat_create_fill_def(name, rows, colums) name GLAL_CONCAT(name, _create_fill)(TYPE value)
#define Mat_create_fill_impl(name, rows, colums) Mat_create_fill(name, rows, colums){\
	name rt = { { 0 } };\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			MGET(rt, i, j) = value;\
		}\
	}\
	return rt;\
}\
// TODO Mat_create #
// TODO Mat_create_identity #
// TODO Mat_create_copy
// TODO Mat_create_transpose
// TODO Mat_create_inverse
// TODO Mat_create_fill
// TODO Mat_create_fill_op
// TODO Mat_create_fromArray

// TODO Mat_create_op
// TODO Mat_create_add
// TODO Mat_create_sub
// TODO Mat_create_mult
// TODO Mat_create_naive_mult
// TODO Mat_create_strassen_mult

// TODO Mat_print #
// TODO Mat_prints #
/*
void mat_add(Mat2* mata, Mat2 matb ){
	(*mata).data[0][0] += matb.data[0][0];
}
*/
// TODO Mat_add
// TODO Mat_sub
// TODO Mat_factor
// TODO Mat_op

//#define Mat_op_def(name, rows, colums) void GLAL_CONCAT(name, _create_identity)(name* self, name other, )
// 
EXPAND_DEF(Mat_create_def)

EXPAND_DEF(Mat_print_def)

void Matx_print(int type, void* vp);

EXPAND_DEF(Mat_prints_def)

EXPAND_DEF(Mat_create_identity_def)

EXPAND_DEF(Mat_create_copy_def)


#define _GENERIC_CALL(type, func, arg) type##func(arg)
#define GENERIC_CALL(type, func, arg) _GENERIC_CALL(type, func, arg)
//a = Mat3_create_copy(mat);

#define teste(type, mat) GENERIC_CALL(type,_create_copy, mat)

#define Mat_print(mat) {\
	if(GLAL_isType(Mat2, mat)){\
		Matx_print(2, &mat);\
	} else if(GLAL_isType(Mat3, mat)){\
		Matx_print(3, &mat);\
	} else if(GLAL_isType(Mat4, mat)){\
		Matx_print(4, &mat);\
	}\
	}\

#ifdef GLAL_IMPLEMENTATION
//=================================================================================================================
// START IMPLEMENTATIOn
EXPAND_IMPL(Mat_create_impl)

EXPAND_IMPL(Mat_print_impl)
void Matx_print(int type, void* vp){
	switch (type){
	case 2:
		Mat2_print(*((Mat2*)vp));
	  break;
	case 3:
		Mat3_print(*((Mat3*)vp));
	  break;
	case 4:
		Mat4_print(*((Mat4*)vp));
	  break;
	}
}

EXPAND_IMPL(Mat_prints_impl)


EXPAND_IMPL(Mat_create_identity_impl)

EXPAND_IMPL(Mat_create_copy_impl)

#endif //GLAL_IMPLEMENTATION

#endif //GLAL_H
