#include <stdio.h>

int main() {

    int a, b, add, sub, mul, quo, rem ;

    printf( "Please Enter two numbers : " );
    scanf( "%d%d", &a, &b );
    
    __asm__ ( 
        "addl %%ebx, %%eax;"
        : "=a" (add)
        : "a" (a) ,
        "b" (b)
        );
    __asm__ (
        "subl %%ebx, %%eax;"
        : "=a" (sub) :
        "a" (a) ,
        "b" (b) 
        );
    __asm__ (
        "imull %%ebx, %%eax;"
        : "=a" (mul) :
        "a" (a) ,
        "b" (b)
        );

    __asm__ (
        "movl $0x0, %%edx;"
        "movl %2, %%eax;"
        "movl %3, %%ebx;"
        "idivl %%ebx;" :
        "=a" (quo),
        "=d" (rem) :
        "g" (a),
        "g" (b)
        );

    printf( "\nAddition= %d\n", add );
    printf( "Subtraction= %d\n",sub );
    printf( "Multiplication= %d\n",mul );
    printf( "Division= %d\n",quo );
    printf( "Modulus= %d\n",rem );

    return 0 ;
}