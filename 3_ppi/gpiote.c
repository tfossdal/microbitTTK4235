#include "gpiote.h"

void init_gpiote(void){
    GPIOTE->CONFIG[5] = (1<<16 | 14<<8 | 1);
    GPIOTE->CONFIG[0] = (3<<16 | 21<<8 | 3);
    GPIOTE->CONFIG[1] = (3<<16 | 22<<8 | 3);
    GPIOTE->CONFIG[2] = (3<<16 | 15<<8 | 3);
    GPIOTE->CONFIG[3] = (3<<16 | 24<<8 | 3);
    GPIOTE->CONFIG[4] = (3<<16 | 19<<8 | 3);
    return;
}