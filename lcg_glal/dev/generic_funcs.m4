changequote(`'', `'')
changecom("//")
// Iterators   --------------------------------------------------------------
define(foreach, 'for($1 = 0 ; $1  < $2 ; $1++ )')dnl
define(mat_foreach, 'foreach(i,$1)
        foreach(j,$2)')dnl

// Acessing object     --------------------------------------------------------------
define(member, 'self.data[i][j]')dnl
define(member_a, 'a.data[i][j]')dnl
define(member_b, 'b.data[i][j]')dnl
define(member_c, 'c.data[i][j]')dnl
define(other , 'other.data[i][j]')dnl

// ===== Expansions of macros ====================================================================
// To expand single definition ------------
//   exp_s_def(create_fill,Mat2) 
// ----------------------------------------
// To expand definition to Mat2, Mat3, Mat4
//   expand_definition_mat(create_fill)
// ----------------------------------------
// To expand single implementation
//   exp_s_impl(create_fill,Mat2,2,2)
// ----------------------------------------
// To expand implementation to Mat2, Mat3, Mat4
//   expand_implementation_mat(create_fill)
// ----------------------------------------
// ==============================================================================================

define(exp_s_def,'Mat_$1_fdef($2, $1);')dnl
define(exp_s_impl,'Mat_$1_fimpl($2, $1, $3, $4)')dnl

    define(expand_definition_mat,
'exp_s_def($1,Mat2) 
exp_s_def($1,Mat3)
exp_s_def($1,Mat4)')dnl

    define(expand_implementation_mat,
'exp_s_impl($1,Mat2,2,2)
exp_s_impl($1,Mat3,3,3)
exp_s_impl($1,Mat4,4,4)')dnl


define(comment, '//======================================================================
//$1
/*
    $2
*/')dnl
//Functions
// Matx_create_fill
define(Mat_create_fill_fdef,'ns($1) ns($1_$2)(TYPE value)')dnl

define(Mat_create_fill_fimpl,'Mat_create_fill_fdef($1, create_fill){
    int i, j;
    ns($1) self;
    mat_foreach($3, $4){
            member = value;
        }
    return self;
}
')dnl

// Matx_print
define(Mat_print_fdef,'void ns($1_$2)(ns($1) self)')dnl

define(Mat_print_fimpl,'Mat_print_fdef($1, print){
    int i, j;
    ns($1) self;
    foreach(i,$3){
        foreach(j,$4){
            printf("%f ",member);
        }
        printf("\n");
    }
}
')dnl

define(Mat_prints_fdef,'void ns($1_$2)(ns($1) self, char* info)')dnl

define(Mat_prints_fimpl,'Mat_prints_fdef($1, prints){
    printf("%s\n",info);
    ns($1_print)(self);
}
')dnl