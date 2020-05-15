#include <stdio.h>

#define A_PREFIX pri

#define _m(a,b,c)  a ## b ## c
#define m(a,b,c) _m(a,b,c)
#define pr(a,b) m(A_PREFIX,a,b)
int main(){


    pr(nt,f)("Hellor world");
    return 0;
}