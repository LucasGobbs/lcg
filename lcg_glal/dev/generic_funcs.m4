changequote(`'', `'')
changecom("//")
dnl Iterators   --------------------------------------------------------------
define(FOREACH, 'for($1 = 0 ; $1  < $2 ; $1++ )')dnl
define(MAT_FOREACH, 'FOREACH(i,$1)
        FOREACH(j,$2)')dnl


dnl Acessing object     --------------------------------------------------------------
define(MEMBER, 'self.data[i][j]')dnl
define(MEMBER_A, 'a.data[i][j]')dnl
define(MEMBER_B, 'b.data[i][j]')dnl
define(MEMBER_C, 'c.data[i][j]')dnl
define(OTHER , 'other.data[i][j]')dnl

dnl ===== Expansions of macros ====================================================================
dnl To expand single definition ------------
dnl   exp_s_def(create_fill,Mat2) 
dnl ----------------------------------------
dnl To expand definition to Mat2, Mat3, Mat4
dnl   expand_definition_mat(create_fill)
dnl ----------------------------------------
dnl To expand single implementation
dnl   exp_s_impl(create_fill,Mat2,2,2)
dnl ----------------------------------------
dnl To expand implementation to Mat2, Mat3, Mat4
dnl   expand_implementation_mat(create_fill)
dnl ----------------------------------------
dnl ==============================================================================================

define(expand_single_definition,'Mat_$1_fdef($2, $1);')dnl
define(expand_single_implementation,'Mat_$1_fimpl($2, $1, $3, $4)')dnl

define(expand_definition_mat,
'expand_single_definition($1,Mat2) 
expand_single_definition($1,Mat3)
expand_single_definition($1,Mat4)'
)dnl

define(expand_definition_vec,
'expand_single_definition($1,Vec2) 
expand_single_definition($1,Vec3)
expand_single_definition($1,Vec4)'
)dnl


define(expand_implementation_mat,
'expand_single_implementation($1,Mat2,2,2)
expand_single_implementation($1,Mat3,3,3)
expand_single_implementation($1,Mat4,4,4)'
)dnl

define(expand_implementation_vec,
'expand_single_implementation($1,Vec2,2,1)
expand_single_implementation($1,Vec3,3,1)
expand_single_implementation($1,Vec4,4,1)'
)dnl

define(delimiter,'//======================================================================')
define(doc,
'delimiter
//  $1
/*
    $2
*/')dnl



dnl --------------------------------------------------------------------------
dnl Functions 

dnl Matx_create_fill 
define(Mat_create_fill_fdef,'ns($1) ns($1_$2)(TYPE value)')dnl
define(Mat_create_fill_fimpl,
'Mat_create_fill_fdef($1, create_fill){
    int i, j;
    ns($1) self;
    MAT_FOREACH($3, $4){
            member = value;
        }
    return self;
}
')dnl

dnl Matx_print
define(Mat_print_fdef,'void ns($1_$2)(ns($1) self)')dnl
define(Mat_print_fimpl,'Mat_print_fdef($1, print){
    int i, j;
    ns(mat_type) self;
    FOREACH(i,$3){
        FOREACH(j,$4){
            printf("%f ",member);
        }
        printf("\n");
    }
}
')dnl

dnl Matx_prints
define(Mat_prints_fdef,'void ns($1_$2)(ns($1) self, char* info)')dnl
define(Mat_prints_fimpl,'Mat_prints_fdef($1, prints){
    printf("%s\n",info);
    ns($1_print)(self);
}
')dnl
