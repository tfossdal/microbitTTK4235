#include "uart.h"
#include <stdio.h>
#include <unistd.h>


ssize_t _write(int fd, const void *buf, size_t count){
    char * letter = (char *)(buf);
    for(int i = 0; i < count; i++){
        uart_send(*letter);
        letter++;
    }
    return count;
}
int main(){
    int ledOn = 0;

    iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235,2019,2018,'C');
    
    while(1){

        if (!(GPIO0->IN & (1 << 23))){ // B_btn
        uart_send('B');
        }
        if (!(GPIO0->IN & (1 << 14))){ // A_btn
        uart_send('A');
        }

        if (UART0->EVENTS_RXDRDY){
            if(!ledOn){

                GPIO0->OUTSET = 1 << 21;
			    GPIO0->OUTSET = 1 << 22;
			    GPIO0->OUTSET = 1 << 15;
			    GPIO0->OUTSET = 1 << 24;
			    GPIO0->OUTSET = 1 << 19;
                ledOn = 1;
            }
            else{
                GPIO0->OUTCLR = 1 << 21;
			    GPIO0->OUTCLR = 1 << 22;
			    GPIO0->OUTCLR = 1 << 15;
			    GPIO0->OUTCLR = 1 << 24;
			    GPIO0->OUTCLR = 1 << 19;
                ledOn = 0;
            }

        }

       
    }

    return 0;
}