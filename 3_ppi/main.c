#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"


int main(void){
    init_gpiote();
    init_PPI();
    gpio_init();
    int teit_tal = 1;
    while(1){
        if(teit_tal == 1){
            --teit_tal;
        } else{++teit_tal;}
    }

    return 0;
}