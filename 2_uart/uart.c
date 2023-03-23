#include "uart.h"
#include "gpio.h"

// TXD som out 1.08
// RXD som in 0.06

void uart_init(){
    GPIO0->PIN_CNF[6] = 0;  // RXD
    GPIO1->PIN_CNF[8] = 1;  // TXD
    UART0->PSELTXD = 0x6;   // sel pin 0.00110 = 0x6
    UART0->PSELRXD = 0x28;
    UART0->BAUDRATE = 0x00275000;
    UART0->PSELRTS =~ 0;
    UART0->PSELCTS =~ 0;
    UART0->ENABLE = 4;
    UART0->TASKS_STARTRX = 1;
    return;
}

void uart_send(char letter){
    UART0->TASKS_STARTTX = 1;
    UART0->TXD = letter;
    while (UART0->EVENTS_TXDRDY==0);
    UART0->TASKS_STOPTX = 1;
    return;
}

char uart_read(){
    UART0->EVENTS_RXDRDY = 0;
    char letter = UART0->RXD;
    if(letter == 0){
        return '\0';
    }
    return letter;
}