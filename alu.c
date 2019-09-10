#include <stdio.h>

int main() {

    int x=2;
    
    __asm__ ( 
        "addl %%ebx, %%eax;"
        : "=a" (x)
        : "a" (x) ,
        "b" (4)
        );

    printf( "%d\n",x );

    return 0 ;
}