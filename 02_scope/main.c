#include <stdio.h>
#include "hyundai.h"

extern int status;

int main(){
    printf("hello world\n");

    int a = 10;
    printf("a is %d\n", incre(a));

    printf("status is %d\n", status);
    status = 0xFF5A;
    printf("status is %d\n", status);
}