#include "test.h"

void forward(Motor* motorA, Motor* motorC){
     motorC->on(85); //make motor A turn backwards with speed 85
     motorA->on(85); //make motor A turn backwards with speed 85$

}


void backward(Motor* motorA, Motor* motorC){
     motorC->on(-85); //make motor A turn backwards with speed 85
     motorA->on(-85); //make motor A turn backwards with speed 85$

}

void stop(Motor* motorA, Motor* motorC){
    motorC->stop(false);
    motorA->stop(false);

}

void backward(Motor* motorA, Motor* motorC, int time){
     int k = 0;
     while(k <= time){
         backward(motorA, motorC);
         k++;
     }

     stop(motorA,motorC);

}
