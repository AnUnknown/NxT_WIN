#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include "Motor.h"

void forward(Motor* motorA, Motor* motorC);

void backward(Motor* motorA, Motor* motorC);

void stop(Motor* motorA, Motor* motorC);

void backward(Motor* motorA, Motor* motorC, int time);


#endif // TEST_H_INCLUDED
