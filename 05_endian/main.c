#include <stdio.h>

void mem_inspection(unsigned char* p, int N){
    for(int i=0;i<N;i++){
        printf("mem[%d] is %d at %p\n", i, *(p+i), p+i);
    }
}

int main(){
    typedef struct {
        unsigned int w1;
        unsigned char b;
        unsigned short s;
        unsigned int w2;
    } BLK;
    
    printf("size of unsigned int: %d\n", sizeof(unsigned int));
    printf("size of unsigned char: %d\n", sizeof(unsigned char));
    printf("size of unsigned short: %d\n", sizeof(unsigned short));

    printf("%d bytes is allocated for BLK\n", sizeof(BLK));

    BLK block[2] = {
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };

    printf("%d bytes is allocated for block\n", sizeof(block));

    mem_inspection((unsigned char*)block, sizeof(BLK)*2); // unsigned char로 캐스팅하면 block 배열의 첫 주소를 가리키는 포인터가 됨
    
    struct test{
        int a;
        short b;
        char c;
        char e;
        int d;
        char f;
        char g;
        short h;
    };
    struct test t1 = {
        0, 1, 2, 3, 4, 5, 6, 7
    };
    printf("%d bytes are allocated for struct test\n", sizeof(t1)); // struct 선언부에서 멤버 변수 선언 순서에 따라 sizeof t1을 줄일 수 있음!
    return 0;
}