#include <stdio.h>

void mem_inspection(unsigned char* p, int N){
    for(int i=0;i<5;i++){
        printf("mem[%d] is 0x%2x at %p\n", i, *(p+i), p+i);
    }
}

int main(){
    unsigned int arr[5] = {0x12345678, 2, 3, 4, 5};
    
    for (int i=0; i<5; i++){
        printf("arr[%d] is 0x%4x\n", i, arr[i]);
    }

    printf("%p\n", &arr[0]);
    printf("%p\n", arr);
    printf("%p\n", arr+1); // 주소상 1 증가가 아닌, 다음 칸 (4 바이트 뒤) 의미
    printf("%p\n", &arr);
    printf("%p\n", &arr+1);

    mem_inspection((unsigned char*)arr, 4*5);

    unsigned int mat[3][4] = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 0, 1, 2}
    };
    for (int i=0;i<3;i++){
        for (int j=0;j<4;j++){
            printf("m[%d][%d] is 0x%2X\n", i, j, mat[i][j]);
        }
    }
    unsigned int* mp = (unsigned int*)mat;
    for (int i=0;i<3;i++){
        for (int j=0;j<4;j++){
            printf("m[%d][%d] is 0x%2X\n", i, j, *(mp+i*4+j));
        }
    }

    unsigned int x0[5] = {1, 2, 3, 4, 5};
    unsigned int x1[5] = {6, 7, 8, 9, 10};
    unsigned int x2[5] = {0, 9, 8, 7, 6};

    unsigned int* col[3] = {x0, x1, x2};
    // unsigned int col[][3] 이랑 같은 표현임
    // unsigned int** col 이랑 같은 표현임

    return 0;
}