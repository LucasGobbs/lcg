#ifndef GLAL_H
#define GLAL_H

/*
Usage

gcc -Wall -pedantic -std=c99 -o exe glal_example.c -lm
gcc -Wno-missing-braces -Wall -pedantic -std=c99 -o exe glal_example.c -lm
*/
#include <stdio.h>
#include <stdarg.h>

#ifndef GLAL_PREFIX
	#define GLAL_PREFIX glal_
#endif // GLAL_PREFIX

#ifndef TYPE
	#define TYPE float
#endif //TYPE
// =============================================================================
// Utility macro helpers
#define GLAL_STRINGIFY(a) GLAL__STRINGIFY(a)
#define GLAL_CONCAT(a, b) GLAL__CONCAT(a,b)
#define GLAL_CONCAT3(a, b, c) GLAL__CONCAT3(a,b,c)
#define GLAL_CONCAT4(a, b, c, d) GLAL__CONCAT4(a,b,c,d)

#define GLAL__CONCAT(a, b) a ## b
#define GLAL__CONCAT3(a,b,c) a ## b ## c
#define GLAL__CONCAT4(a, b, c, d) a ## b ## c ## d
#define GLAL__STRINGIFY(a) #a
#define ns(a) GLAL_CONCAT(GLAL_PREFIX,a)
#define GLAL_NS_CONCAT(a, b) GLAL_CONCAT3(GLAL_PREFIX,a,b)
#define GLAL_NS_CONCAT3(a, b, c) GLAL_CONCAT4(GLAL_PREFIX,a,b,c)

#define GLAL_ABS(a) ((a)>0.0?(a):-(a))
#define GLAL_PI 3.1415926535
#define GLAL_EPSILON 0.00000001 // i think its smol but you can prove me wrong
// =============================================================================
// Type
// TODO change this workarounf of (GCC bug # 53119, missing braces around inicializer)  to something better
#define GLAL_MATRIX_TYPE(mat_type, rows, colums) typedef struct {\
	unsigned short int just_to_gcc_dont_complay_about_missing_braces;\
	TYPE data[rows][colums];\
}ns(mat_type)\

GLAL_MATRIX_TYPE(Mat2,2,2); 
GLAL_MATRIX_TYPE(Mat3,3,3); 
GLAL_MATRIX_TYPE(Mat4,4,4); 

GLAL_MATRIX_TYPE(Vec2,2,1); 
GLAL_MATRIX_TYPE(Vec3,3,1); 
GLAL_MATRIX_TYPE(Vec4,4,1); 


// =============================================================================
// Utility function helpers
#define ITER(size, i) i=0;i<size;i++
#define FOREACH(size, i) for(ITER(size, i))
#define MGET(mat, i, j) mat.data[i][j]

#define GLAL_isType(type, x) (__builtin_types_compatible_p(__typeof__(x), type))
#define GLAL_isMat2(Mat2)(mat) (GLAL_isType(ns(Mat2), mat))
#define GLAL_isMat3(Mat3)(mat) (GLAL_isType(ns(Mat3), mat))
#define GLAL_isMat4(Mat4)(mat) (GLAL_isType(ns(Mat4), mat))


// =============================================================================
// Functions

/* Template to function def and impl
#define Mat_FUNCTIONNAME_def(mat_type, rows, colums) RETURNTYPE GLAL_NS_CONCAT(mat_type, _FUNCTIONNAME)()
#define Mat_FUNCTIONNAME_impl(mat_type, rows, colums) Mat_FUNCTIONNAME_def(mat_type, rows, colums){\
	blablabla\
}\
*/
#define GLAL_EXPAND_DEF_MAT(def) def(Mat2, 2, 2); def(Mat3, 3, 3); def(Mat4, 4, 4);
#define GLAL_EXPAND_IMPL_MAT(impl) impl(Mat2, 2, 2) impl(Mat3, 3, 3) impl(Mat4, 4, 4)

#define GLAL_EXPAND_DEF_VEC(def) def(Vec2, 2, 1); def(Vec3, 3, 1); def(Vec4, 4, 1);
#define GLAL_EXPAND_IMPL_VEC(impl) impl(Vec2, 2, 1) impl(Vec3, 3, 1) impl(Vec4, 4, 1)

#define GLAL_EXPAND_DEF_ALL(def) GLAL_EXPAND_DEF_MAT(def) GLAL_EXPAND_DEF_VEC(def)
#define GLAL_EXPAND_IMPL_ALL(def) GLAL_EXPAND_IMPL_MAT(def) GLAL_EXPAND_IMPL_VEC(def)
// Create Simple matrix
#define Mat_create_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create)()
#define Mat_create_impl(mat_type, rows, colums) Mat_create_def(mat_type, rows, colums){\
	ns(mat_type) a = {0}; return a; \
}\

// Print matrix
#define Mat_print_def(mat_type, rows, colums) void GLAL_NS_CONCAT(mat_type, _print)(ns(mat_type) mat)
#define Mat_print_impl(mat_type, rows, colums) Mat_print_def(mat_type, rows, colums){\
	int i, j;\
	printf(""#mat_type "\n");\
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
#define Mat_prints_def(mat_type, rows, colums) void GLAL_NS_CONCAT(mat_type, _prints)(ns(mat_type) mat, char* txt)
#define Mat_prints_impl(mat_type, rows, colums) Mat_prints_def(mat_type, rows, colums){\
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

#define Mat_create_identity_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_identity)()
#define Mat_create_identity_impl(mat_type, rows, colums) Mat_create_identity_def(mat_type, rows, colums){\
	int i;\
	ns(mat_type) mat = {0};\
	FOREACH(rows, i){\
		MGET(mat, i, i) = 1.0;\
	}\
	return mat;\
}\

#define Mat_create_copy_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_copy)(ns(mat_type) mat)
#define Mat_create_copy_impl(mat_type, rows, colums) Mat_create_copy_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			MGET(rt, i, j) = MGET(mat, i, j);\
		}\
	}\
	return rt;\
}\

#define Mat_create_fill_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_fill)(TYPE value)
#define Mat_create_fill_impl(mat_type, rows, colums) Mat_create_fill_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			MGET(rt, i, j) = value;\
		}\
	}\
	return rt;\
}\

#define Mat_create_fill_op_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_fill_op)(TYPE (*operation)(size_t i, size_t j, size_t x))
#define Mat_create_fill_op_impl(mat_type, rows, colums) Mat_create_fill_op_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	int i, j, x = 0;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			MGET(rt, i, j) = operation(i, j, x);\
			x++;\
		}\
	}\
	return rt;\
}\

#define Mat_create_fromArray_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_fromArray)(TYPE* data)
#define Mat_create_fromArray_impl(mat_type, rows, colums) Mat_create_fromArray_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	int i, j, x = 0;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			MGET(rt, i, j) = data[x];\
			x++;\
		}\
	}\
	return rt;\
}\

#define Mat_create_fromArg_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_fromArg)(TYPE first, ...)
#define Mat_create_fromArg_impl(mat_type, rows, colums) Mat_create_fromArg_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	int i, j;\
	va_list list;\
	va_start(list, first);\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			if(i==0 && j==0){\
				MGET(rt, i, j) = first;\
 			} else {\
				MGET(rt, i, j) = va_arg(list, double);\
			}\
		}\
	}\
	return rt;\
}\

// TODO check for more cache friendly solutions
#define Mat_create_transpose_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_transpose)(ns(mat_type) mat)
#define Mat_create_transpose_impl(mat_type, rows, colums) Mat_create_transpose_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			MGET(rt, i, j) = MGET(mat, j, i);\
		}\
	}\
	return rt;\
}\

//
#define Mat_naive_equals_def(mat_type, rows, colums) int GLAL_NS_CONCAT(mat_type, _naive_equals)(ns(mat_type) a, ns(mat_type) b)
#define Mat_naive_equals_impl(mat_type, rows, colums) Mat_naive_equals_def(mat_type, rows, colums){\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			if(MGET(a, i, j) != MGET(b, j, i)){\
				return 0;\
			}\
		}\
	}\
	return 1;\
}\

#define Mat_equals_def(mat_type, rows, colums) int GLAL_NS_CONCAT(mat_type, _equals)(ns(mat_type) a, ns(mat_type) b)
#define Mat_equals_impl(mat_type, rows, colums) Mat_equals_def(mat_type, rows, colums){\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			TYPE value = MGET(a, i, j) - MGET(b, j, i);\
			value = GLAL_ABS(value);\
			if(value >= GLAL_EPSILON){\
				return 0;\
			}\
		}\
	}\
	return 1;\
}\

// OPERATIONS
#define Mat_create_op_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_op)(ns(mat_type) a, ns(mat_type) b, TYPE (*operation)(TYPE a, TYPE b))
#define Mat_create_op_impl(mat_type, rows, colums) Mat_create_op_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			TYPE a_value = MGET(a, i, j);\
			TYPE b_value = MGET(b, i, j);\
			MGET(rt, i, j) = operation(a_value, b_value);\
		}\
	}\
	return rt;\
}\

#define Mat_create_add_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_add)(ns(mat_type) a, ns(mat_type) b)
#define Mat_create_add_impl(mat_type, rows, colums) Mat_create_add_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			MGET(rt, i, j) = MGET(a, i, j) + MGET(b, i, j);\
		}\
	}\
	return rt;\
}\

#define Mat_create_sub_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_sub)(ns(mat_type) a, ns(mat_type) b)
#define Mat_create_sub_impl(mat_type, rows, colums) Mat_create_sub_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			MGET(rt, i, j) = MGET(a, i, j) - MGET(b, i, j);\
		}\
	}\
	return rt;\
}\

#define Mat_create_scalar_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_scalar)(ns(mat_type) a, TYPE value)
#define Mat_create_scalar_impl(mat_type, rows, colums) Mat_create_scalar_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			MGET(rt, i, j) = MGET(a, i, j) * value;\
		}\
	}\
	return rt;\
}\

#define Mat_create_schur_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_schur)(ns(mat_type) a, ns(mat_type) b)
#define Mat_create_schur_impl(mat_type, rows, colums) Mat_create_schur_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			MGET(rt, i, j) = MGET(a, i, j) *  MGET(b, i, j);\
		}\
	}\
	return rt;\
}\

#define Mat_naive_mult_Mat_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _naive_mult_mat)(ns(mat_type) a, ns(mat_type) b)
#define Mat_naive_mult_Mat_impl(mat_type, rows, colums) Mat_naive_mult_Mat_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	int i, j, k;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			FOREACH(colums, k){\
				MGET(rt, i, j) += MGET(a, i, k) *  MGET(b, k, j);\
			}\
		}\
	}\
	return rt;\
}\


// TODO create strassen multiplication
#define Mat_strassen_mult_Mat_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _strassen_mult_mat)(ns(mat_type) a, ns(mat_type) b)
#define Mat_strassen_mult_Mat_impl(mat_type, rows, colums) Mat_strassen_mult_Mat_def(mat_type, rows, colums){\
	ns(mat_type) rt = {0};\
	return rt;\
}\

#define Mat_mult_Mat_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _mult_mat)(ns(mat_type) a, ns(mat_type) b)
#define Mat_mult_Mat_impl(mat_type, rows, colums) Mat_mult_Mat_def(mat_type, rows, colums){\
	return GLAL_NS_CONCAT(mat_type, _naive_mult_mat)(a,b);\
}\

#define Mat_op_def(mat_type, rows, colums) void GLAL_NS_CONCAT(mat_type, _op)(ns(mat_type) *a, ns(mat_type) b, TYPE (*operation)(TYPE a, TYPE b))
#define Mat_op_impl(mat_type, rows, colums) Mat_op_def(mat_type, rows, colums){\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			TYPE a_value = MGET((*a), i, j);\
			TYPE b_value = MGET(b, i, j);\
			MGET((*a), i, j) = operation(a_value, b_value);\
		}\
	}\
}\

#define Mat_add_def(mat_type, rows, colums) void GLAL_NS_CONCAT(mat_type, _add)(ns(mat_type) *a, ns(mat_type) b)
#define Mat_add_impl(mat_type, rows, colums) Mat_add_def(mat_type, rows, colums){\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			TYPE a_value = MGET((*a), i, j);\
			TYPE b_value = MGET(b, i, j);\
			MGET((*a), i, j) = a_value + b_value;\
		}\
	}\
}\

#define Mat_sub_def(mat_type, rows, colums) void GLAL_NS_CONCAT(mat_type, _sub)(ns(mat_type) *a, ns(mat_type) b)
#define Mat_sub_impl(mat_type, rows, colums) Mat_sub_def(mat_type, rows, colums){\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			TYPE a_value = MGET((*a), i, j);\
			TYPE b_value = MGET(b, i, j);\
			MGET((*a), i, j) = a_value - b_value;\
		}\
	}\
}\

#define Mat_scalar_def(mat_type, rows, colums) void GLAL_NS_CONCAT(mat_type, _scalar)(ns(mat_type) *a, TYPE  value)
#define Mat_scalar_impl(mat_type, rows, colums) Mat_scalar_def(mat_type, rows, colums){\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			TYPE a_value = MGET((*a), i, j);\
			MGET((*a), i, j) = a_value * value;\
		}\
	}\
}\

#define Mat_schur_def(mat_type, rows, colums) void GLAL_NS_CONCAT(mat_type, _schur)(ns(mat_type) *a, ns(mat_type) b)
#define Mat_schur_impl(mat_type, rows, colums) Mat_schur_def(mat_type, rows, colums){\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			TYPE a_value = MGET((*a), i, j);\
			TYPE b_value = MGET(b, i, j);\
			MGET((*a), i, j) = a_value * b_value;\
		}\
	}\
}\


// Template to function def and impl
/*
#define Mat_FUNCTIONNAME_def(mat_type, rows, colums) RETURNTYPE GLAL_NS_CONCAT(mat_type, _FUNCTIONNAME)()
#define Mat_FUNCTIONNAME_impl(mat_type, rows, colums) Mat_FUNCTIONNAME_def(mat_type, rows, colums){\
	blablabla\
}\



*/
// TODO Mat_create #
// TODO Mat_create_identity #
// TODO Mat_create_copy #
// TODO Mat_create_transpose #
// TODO Mat_create_inverse
// TODO Mat_create_fill #
// TODO Mat_create_fill_op #
// TODO Mat_create_fromArray #

// TODO Mat_naive_equals #
// TODO Mat_equals #
// TODO Mat_determinant

// TODO Mat_create_op #
// TODO Mat_create_add #
// TODO Mat_create_sub #
// TODO Mat_create_mult
// TODO Mat_create_naive_mult
// TODO Mat_create_strassen_mult
// TODO Mat_scalar #
// TODO Mat_schur #

// TODO Mat_print #
// TODO Mat_prints #
/*
void mat_add(ns(Mat2)* mata, ns(Mat2) matb ){
	(*mata).data[0][0] += matb.data[0][0];
}
*/
// TODO Mat_add
// TODO Mat_sub
// TODO Mat_factor
// TODO Mat_op

//#define Mat_op_def(mat_type, rows, colums) void GLAL_CONCAT(mat_type, _create_identity)(mat_type* self, mat_type other, )
//

//Mat_create_def(Mat2, 2, 2);

GLAL_EXPAND_DEF_ALL(Mat_create_def)
GLAL_EXPAND_DEF_ALL(Mat_print_def)
GLAL_EXPAND_DEF_ALL(Mat_prints_def)
GLAL_EXPAND_DEF_ALL(Mat_create_identity_def)
GLAL_EXPAND_DEF_ALL(Mat_create_copy_def)
GLAL_EXPAND_DEF_ALL(Mat_create_fill_def)
GLAL_EXPAND_DEF_ALL(Mat_create_fill_op_def)
GLAL_EXPAND_DEF_ALL(Mat_create_fromArray_def)
GLAL_EXPAND_DEF_ALL(Mat_create_fromArg_def)
GLAL_EXPAND_DEF_ALL(Mat_create_transpose_def)
GLAL_EXPAND_DEF_ALL(Mat_create_op_def)
GLAL_EXPAND_DEF_ALL(Mat_op_def)
GLAL_EXPAND_DEF_ALL(Mat_create_add_def)
GLAL_EXPAND_DEF_ALL(Mat_add_def)
GLAL_EXPAND_DEF_ALL(Mat_create_sub_def)
GLAL_EXPAND_DEF_ALL(Mat_sub_def)
GLAL_EXPAND_DEF_ALL(Mat_create_scalar_def)
GLAL_EXPAND_DEF_ALL(Mat_scalar_def)
GLAL_EXPAND_DEF_ALL(Mat_create_schur_def)
GLAL_EXPAND_DEF_ALL(Mat_schur_def)
GLAL_EXPAND_DEF_ALL(Mat_naive_equals_def)
GLAL_EXPAND_DEF_ALL(Mat_equals_def)
GLAL_EXPAND_DEF_MAT(Mat_mult_Mat_def)
GLAL_EXPAND_DEF_MAT(Mat_naive_mult_Mat_def)

void ns(Matx_print)(int type, void* vp);

#define Mat_print(mat) {\
	if(GLAL_isType(ns(Mat2), mat)){\
		ns(Matx_print)(2, &mat);\
	} else if(GLAL_isType(ns(Mat3), mat)){\
		ns(Matx_print)(3, &mat);\
	} else if(GLAL_isType(ns(Mat4), mat)){\
		ns(Matx_print)(4, &mat);\
	}\
	}\


#ifdef GLAL_IMPLEMENTATION
//=================================================================================================================
// START IMPLEMENTATIOn

GLAL_EXPAND_IMPL_ALL(Mat_print_impl)

GLAL_EXPAND_IMPL_ALL(Mat_create_impl)
GLAL_EXPAND_IMPL_ALL(Mat_prints_impl)
GLAL_EXPAND_IMPL_ALL(Mat_create_identity_impl)
GLAL_EXPAND_IMPL_ALL(Mat_create_copy_impl)
GLAL_EXPAND_IMPL_ALL(Mat_create_fill_impl)
GLAL_EXPAND_IMPL_ALL(Mat_create_fill_op_impl)
GLAL_EXPAND_IMPL_ALL(Mat_create_fromArray_impl)
GLAL_EXPAND_IMPL_ALL(Mat_create_fromArg_impl)
GLAL_EXPAND_IMPL_ALL(Mat_create_transpose_impl)
GLAL_EXPAND_IMPL_ALL(Mat_create_op_impl)
GLAL_EXPAND_IMPL_ALL(Mat_op_impl)
GLAL_EXPAND_IMPL_ALL(Mat_create_add_impl)
GLAL_EXPAND_IMPL_ALL(Mat_add_impl)
GLAL_EXPAND_IMPL_ALL(Mat_create_sub_impl)
GLAL_EXPAND_IMPL_ALL(Mat_sub_impl)
GLAL_EXPAND_IMPL_ALL(Mat_create_scalar_impl)
GLAL_EXPAND_IMPL_ALL(Mat_scalar_impl)
GLAL_EXPAND_IMPL_ALL(Mat_create_schur_impl)
GLAL_EXPAND_IMPL_ALL(Mat_schur_impl)
GLAL_EXPAND_IMPL_ALL(Mat_naive_equals_impl)
GLAL_EXPAND_IMPL_ALL(Mat_equals_impl)
GLAL_EXPAND_IMPL_MAT(Mat_mult_Mat_impl)
GLAL_EXPAND_IMPL_MAT(Mat_naive_mult_Mat_impl)

void ns(Matx_print)(int type, void* vp){
	switch (type){
	case 2:
		ns(Mat2_print)(*((ns(Mat2)*)vp));
	  break;
	case 3:
		ns(Mat3_print)(*((ns(Mat3)*)vp));
	  break;
	case 4:
		ns(Mat4_print)(*((ns(Mat4)*)vp));
	  break;
	}
}

#endif //GLAL_IMPLEMENTATION

#endif //GLAL_H
