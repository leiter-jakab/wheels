#include <Arduino.h>
#include <Adafruit_MCP4725.h>
#include "leds.h"

#define NUM_NODES 8
#define ROOT_WHEEL_LIMIT 36
#define TYPE_WHEEL_LIMIT 8
#define INVERSION_WHEEL_LIMIT 3

Adafruit_MCP4725 dac;

byte rootWheelPos = 0;
byte typeWheelPos = 0;
byte inversionWheelPos = 0;

byte rootWheelNodes[NUM_NODES] = {0};
byte typeWheelNodes[NUM_NODES] = {0};
byte inversionWheelNodes[NUM_NODES] = {0};

byte rootWheelPosPrev = 0;
byte typeWheelPosPrev = 0;
byte inversionWheelPosPrev = 0;

int note1 = 0;
int note2 = 0;
int note3 = 0;
int note4 = 0;

const int NOTE_VOLTAGES[] = {
  0, 68, 137, 205, 273, 341, 410, 478, 546, 614, 682, 751, 817, 887, 956, 1024, 1097, 1170
};

void initWheels() {
  dac.begin(0x62);
  dac.setVoltage(0, false);
}

void updateRootWheel(byte node) {
  if (rootWheelNodes[node] == ROOT_WHEEL_LIMIT - 1) {
    rootWheelNodes[node] = 0;
  } else {
    rootWheelNodes[node]++;
  }
  setLed(0, rootWheelNodes[node]);
}

void updateTypeWheel(byte node) {
  if (typeWheelNodes[node] == TYPE_WHEEL_LIMIT - 1) {
    typeWheelNodes[node] = 0;
  } else {
    typeWheelNodes[node]++;
  }
  setLed(1, typeWheelNodes[node]);
}

void updateInversionWheel(byte node) {
  if (inversionWheelNodes[node] == INVERSION_WHEEL_LIMIT - 1) {
    inversionWheelNodes[node] = 0;
  } else {
    inversionWheelNodes[node]++;
  }
  setLed(2, inversionWheelNodes[node]);
}

void triggerRootWheel() {
  if (rootWheelPos == NUM_NODES - 1) {
    rootWheelPos = 0;
  } else {
    rootWheelPos++;
  }
}

void triggerTypeWheel() {
  if (typeWheelPos == NUM_NODES - 1) {
    typeWheelPos = 0;
  } else {
    typeWheelPos++;
  }
}

void triggerInversionWheel() {
  if (inversionWheelPos == NUM_NODES - 1) {
    inversionWheelPos = 0;
  } else {
    inversionWheelPos++;
  }
}

void triggerAllWheels() {
  triggerRootWheel();
  triggerTypeWheel();
  triggerInversionWheel();
}

void resetRootWheel() {
  rootWheelPos = 0;
}

void resetTypeWheel() {
  typeWheelPos = 0;
}

void resetInversionWheel() {
  inversionWheelPos = 0;
}

void resetAllWheels() {
  resetRootWheel();
  resetTypeWheel();
  resetInversionWheel();
}

void triggerRootWheelReverse() {
  if (rootWheelPos == 0) {
    rootWheelPos = ROOT_WHEEL_LIMIT - 1;
  } else {
    rootWheelPos--;
  }
}

void triggerTypeWheelReverse() {
  if (typeWheelPos == 0) {
    typeWheelPos = TYPE_WHEEL_LIMIT - 1;
  } else {
    typeWheelPos--;
  }
}

void triggerInversionWheelReverse() {
  if (inversionWheelPos == 0) {
    inversionWheelPos = INVERSION_WHEEL_LIMIT - 1;
  } else {
    inversionWheelPos--;
  }
}

void triggerAllWheelsReverse() {
  triggerRootWheelReverse();
  triggerTypeWheelReverse();
  triggerInversionWheelReverse();
}

void tickWheels() {
  if (rootWheelPos != rootWheelPosPrev) {
    int note1 = NOTE_VOLTAGES[10];
    int note2 = NOTE_VOLTAGES[12];
    int note3 = NOTE_VOLTAGES[14];
    int note4 = NOTE_VOLTAGES[15];
    dac.setVoltage(note1, false);
    delay(2000);
    dac.setVoltage(note2, false);
    delay(2000);
    dac.setVoltage(note3, false);
    delay(2000);
    dac.setVoltage(note4, false);
  } else if (typeWheelPos != typeWheelPosPrev) {
    // cal new notes other than root
  } else if (inversionWheelPos != inversionWheelPosPrev) {
    // calc new position of notes
  }
  rootWheelPosPrev = rootWheelPos;
  typeWheelPosPrev = typeWheelPos;
  inversionWheelPosPrev = inversionWheelPosPrev;
}
