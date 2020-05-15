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
#define GLAL_CONCAT3(a, b, c) GLAL__CONCAT3(a,b,c)

#define GLAL__CONCAT(a, b) a ## b
#define GLAL__CONCAT3(a,b,c) a ## b ## c

#define ns(a) GLAL_CONCAT(GLAL_PREFIX,a)
#define GLAL_NS_CONCAT(a, b) GLAL_CONCAT3(GLAL_PREFIX,a,b)
#define MATRIX_mat_type(rows, colums) GLAL_CONCAT(Mat, GLAL_CONCAT(rows, colums))
#define GLAL_MATRIX_TYPE(mat_type, rows, colums) typedef struct {\
	TYPE data[rows][colums];\
}ns(mat_type)\


#define ITER(size, i) i=0;i<size;i++
#define FOREACH(size, i) for(ITER(size, i))
#define MGET(mat, i, j) mat.data[i][j]

#define GLAL_isType(type, x) (__builtin_types_compatible_p(__typeof__(x), type))
#define GLAL_isMat2(Mat2)(mat) (GLAL_isType(ns(Mat2), mat))
#define GLAL_isMat3(Mat3)(mat) (GLAL_isType(ns(Mat3), mat))
#define GLAL_isMat4(Mat4)(mat) (GLAL_isType(ns(Mat4), mat))

GLAL_MATRIX_TYPE(Mat2,2,2);
GLAL_MATRIX_TYPE(Mat3,3,3);
GLAL_MATRIX_TYPE(Mat4,4,4);

#define EXPAND_DEF(def) def(Mat2, 2, 2); def(Mat3, 3, 3); def(Mat4, 4, 4);
#define EXPAND_IMPL(impl) impl(Mat2, 2, 2) impl(Mat3, 3, 3) impl(Mat4, 4, 4)

// Create Simple matrix
#define Mat_create_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create)()
#define Mat_create_impl(mat_type, rows, colums) Mat_create_def(mat_type, rows, colums){\
	ns(mat_type) a = { { 0 }  }; return a; \
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
	ns(mat_type) mat = { {0} };\
	FOREACH(rows, i){\
		MGET(mat, i, i) = 1.0;\
	}\
	return mat;\
}\

#define Mat_create_copy_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_copy)(ns(mat_type) mat)
#define Mat_create_copy_impl(mat_type, rows, colums) Mat_create_copy_def(mat_type, rows, colums){\
	ns(mat_type) rt = { {0} };\
	return rt;\
}\

#define Mat_create_fill_def(mat_type, rows, colums) ns(mat_type) GLAL_NS_CONCAT(mat_type, _create_fill)(TYPE value)
#define Mat_create_fill_impl(mat_type, rows, colums) Mat_create_fill(mat_type, rows, colums){\
	mat_type rt = { { 0 } };\
	int i, j;\
	FOREACH(rows, i){\
		FOREACH(colums, j){\
			MGET(rt, i, j) = value;\
		}\
	}\
	return rt;\
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

EXPAND_DEF(Mat_create_def)

EXPAND_DEF(Mat_print_def)

void ns(Matx_print)(int type, void* vp);

EXPAND_DEF(Mat_prints_def)

EXPAND_DEF(Mat_create_identity_def)

EXPAND_DEF(Mat_create_copy_def)


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
//Mat_create_impl(Mat2, 2, 2)

EXPAND_IMPL(Mat_create_impl)

EXPAND_IMPL(Mat_print_impl)
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

EXPAND_IMPL(Mat_prints_impl)


EXPAND_IMPL(Mat_create_identity_impl)

EXPAND_IMPL(Mat_create_copy_impl)

#endif //GLAL_IMPLEMENTATION

#endif //GLAL_H
