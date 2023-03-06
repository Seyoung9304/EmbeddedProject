#include <stdio.h>

typedef enum {
    EOC = 1, 
    SOC = 0
}ADC_STATUS;

enum TIMER_MODE{
    TIMER_EN = 1<<7, 
    TIMER_ST = 1<<2
};

ADC_STATUS adc_status(){
    return EOC;
}

int main(){
    if (adc_status()==SOC){
        printf("still on conversion\n");
    }
    if (adc_status()==EOC){
        printf("end of conversion\n");
    }

    unsigned char _TMODE;
    printf("Address of TMODE: %p\n", &_TMODE); // output: 0x0061FF1F
    *((unsigned char*)0x0061FF1F) = 0x88;

    #define TMODE *((unsigned char*) (0x0061FF1F)) // 물리적인 주소 지정해서 해당 위치에 TMODE 할당
    TMODE = 0x88;

    TMODE |= TIMER_EN;
    TMODE |= TIMER_ST;
    printf("TMODE: 0x%2X\n", TMODE);
    TMODE &= ~TIMER_ST;
    printf("TMODE: 0x%2X\n", TMODE);

    return 0;
}