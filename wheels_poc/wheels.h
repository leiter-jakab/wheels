#include <Arduino.h>

#ifndef WHEELS_H
#define WHEELS_H

void initWheels();
void tickWheels();

void updateRootWheel(byte node);
void updateTypeWheel(byte node);
void updateInversionWheel(byte node);

void triggerRootWheel();
void triggerTypeWheel();
void triggerInversionWheel();

void triggerAllWheels();

void resetRootWheel();
void resetTypeWheel();
void resetInversionWheel();

void resetAllWheels();

void triggerRootWheelReverse();
void triggerTypeWheelReverse();
void triggerInversionWheelReverse();

void triggerAllWheelsReverse();

#endif
