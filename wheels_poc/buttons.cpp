#include <Arduino.h>
#include "wheels.h"

#define COL_COUNT 2
#define ROW_COUNT 2

// buttons of column 0
#define BUTTON_0 1
#define BUTTON_1 2

// buttons of column 1
#define BUTTON_2 257
#define BUTTON_3 258

const byte COLS[] = {6, 7};
const byte ROWS[] = {4, 5};

byte matrixMaskPrev[COL_COUNT] = {0};

void initButtons() {
  for (byte x = 0; x < COL_COUNT; x++) {
    pinMode(COLS[x], INPUT_PULLUP);
  }

  for (byte x = 0; x < COL_COUNT; x++) {
    pinMode(ROWS[x], INPUT);
  }
}

void doButtonAction(int buttonCode) {
  switch (buttonCode) {
    case BUTTON_0:
      triggerAllWheels();
      Serial.println("button 0 pressed");
      break;
    case BUTTON_1:
      updateRootWheel(0);
      Serial.println("button 1 pressed");
      break;
    case BUTTON_2:
      updateTypeWheel(0);
      Serial.println("button 2 pressed");
      break;
    case BUTTON_3:
      updateInversionWheel(0);
      Serial.println("button 3 pressed");
      break;
  }
}

void tickButtons() {
  for (byte colIndex = 0; colIndex < COL_COUNT; colIndex++) {
    byte matrixColNew = 0;
    byte curCol = COLS[colIndex];
    pinMode(curCol, OUTPUT);
    digitalWrite(curCol, LOW);

    for (byte rowIndex = 0; rowIndex < ROW_COUNT; rowIndex++) {
      byte rowCol = ROWS[rowIndex];
      pinMode(rowCol, INPUT_PULLUP);
      if (digitalRead(rowCol) == LOW) {
        int colBits = int(colIndex) << 8;
        byte rowBits = 0;
        bitSet(rowBits, rowIndex);
        int buttonCode = colBits + (~matrixMaskPrev[colIndex] & rowBits);
        doButtonAction(buttonCode);
        matrixColNew ^= rowBits;
      }
      pinMode(rowCol, INPUT);
    }
    pinMode(curCol, INPUT);

    matrixMaskPrev[colIndex] = matrixColNew;
  }
}
