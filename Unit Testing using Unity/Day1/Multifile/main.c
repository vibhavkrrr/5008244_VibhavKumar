#include<stdio.h>
#include "demo.h"




int main(){
    int a = 10 , b = 20 , c, d;
    c = sum(a,b);
    d = square(a);

    printf("Sum is : %d\n", c);
    printf("Square is : %d\n", d);

    
    return 0;
}