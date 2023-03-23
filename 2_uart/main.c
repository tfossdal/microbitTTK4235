#include "uart.h"

int main(){

    int sleep;
    while(1){

        if (!(GPIO0->IN & (1 << 23))){ // B_btn
        uart_send('B');
        }
        if (!(GPIO0->IN & (1 << 14))){ // A_btn
        uart_send('A');
        }

        sleep = 10000;
        while(--sleep);
    }

    return 0;
}