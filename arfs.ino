
#include "UnoJoy.h"

struct Buttons{
  int A;
  int B;
  int X;
  int Y;
  int Z;
  int R;
  int L;
  int LS;
  int TAUNT;
  int BONUS;
  int CDOWN;
  int CLEFT;
  int CRIGHT;
  int CUP;
  int UP;
  int DOWN;
  int LEFT;
  int RIGHT;
  int START;
  int X1;
  int X2;
  int Y1;
  int Y2;
  int CTRL_1;
  int CTRL_2;
  int CTRL_3;
};

//Right Side
const int A = 37;
const int CLEFT = 25;
const int CUP = 27;
const int CRIGHT = 29;
const int CDOWN = 31;

const int B = 33;
const int X = 35;
const int Z = 23;
const int LS = 39;
const int R = 41;
const int Y = 43;
const int TAUNT = 45;
const int BONUS = 47;

//Left Side
const int X2 = 22;
const int X1= 24;
const int Y2 = 26;
const int Y1 = 28;
const int START = 30;
const int RIGHT = 32;
const int DOWN = 34;
const int UP = 38;
const int LEFT = 36;
const int L = 40;
const int CTRL_1 = 42;
const int CTRL_2 = 44;
const int CTRL_3 = 46;

void setup(){
  pinMode(A, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
  pinMode(X, INPUT_PULLUP);
  pinMode(Y, INPUT_PULLUP);
  pinMode(Z, INPUT_PULLUP);
  pinMode(START, INPUT_PULLUP);
  pinMode(R, INPUT_PULLUP);
  pinMode(L, INPUT_PULLUP);
  pinMode(LS, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(X1, INPUT_PULLUP);
  pinMode(X2, INPUT_PULLUP);
  pinMode(Y1, INPUT_PULLUP);
  pinMode(Y2, INPUT_PULLUP);
  pinMode(CLEFT, INPUT_PULLUP);
  pinMode(CRIGHT, INPUT_PULLUP);
  pinMode(CUP, INPUT_PULLUP);
  pinMode(CDOWN, INPUT_PULLUP);
  pinMode(TAUNT, INPUT_PULLUP);
  pinMode(BONUS, INPUT_PULLUP);
  pinMode(CTRL_1, INPUT_PULLUP);
  pinMode(CTRL_2, INPUT_PULLUP);
  pinMode(CTRL_3, INPUT_PULLUP);
  setupUnoJoy();
}

void loop(){
  // Always be getting fresh data
    Buttons toProf;
    
    toProf.START = (digitalRead(START) == LOW)?1:0;
    toProf.LS = (digitalRead(LS) == LOW)?1:0;
    toProf.L = (digitalRead(L) == LOW)?1:0;
    toProf.Y = (digitalRead(Y) == LOW)?1:0;
    toProf.R = (digitalRead(R) == LOW)?1:0;
    toProf.B = (digitalRead(B) == LOW)?1:0;
    toProf.A = (digitalRead(A) == LOW)?1:0;
    toProf.X = (digitalRead(X) == LOW)?1:0;
    toProf.Z = (digitalRead(Z) == LOW)?1:0;
    toProf.CUP = (digitalRead(CUP) == LOW)?1:0;
    toProf.CLEFT = (digitalRead(CLEFT) == LOW)?1:0;
    toProf.CDOWN = (digitalRead(CDOWN) == LOW)?1:0;
    toProf.CRIGHT = (digitalRead(CRIGHT) == LOW)?1:0;
    toProf.TAUNT = (digitalRead(TAUNT) == LOW)?1:0;
    toProf.BONUS = (digitalRead(BONUS) == LOW)?1:0;
    toProf.UP = (digitalRead(UP) == LOW)?1:0;
    toProf.LEFT = (digitalRead(LEFT) == LOW)?1:0;
    toProf.DOWN = (digitalRead(DOWN) == LOW)?1:0;
    toProf.RIGHT = (digitalRead(RIGHT) == LOW)?1:0;
    toProf.Y1 = (digitalRead(Y1) == LOW)?1:0;
    toProf.Y2 = (digitalRead(Y2) == LOW)?1:0;
    toProf.X1 = (digitalRead(X1) == LOW)?1:0;
    toProf.X2 = (digitalRead(X2) == LOW)?1:0;
    toProf.CTRL_1 = (digitalRead(CTRL_1) == LOW)?1:0;
    toProf.CTRL_2 = (digitalRead(CTRL_2) == LOW)?1:0;
    toProf.CTRL_3 = (digitalRead(CTRL_3) == LOW)?1:0;
    
  dataForController_t controllerData = getControllerData(toProf);
  setControllerData(controllerData);
}

dataForController_t getControllerData(Buttons toProf){
  
  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins

  
  controllerData.triangleOn = toProf.Y;
  controllerData.circleOn = toProf.X;
  controllerData.squareOn = toProf.R;
  controllerData.crossOn = toProf.B;
  
  controllerData.r1On = toProf.BONUS;
  controllerData.r2On = toProf.LS;
  controllerData.l1On = toProf.TAUNT;
  controllerData.l2On = toProf.A;

  int toUP = toProf.Y1 || toProf.Y2 || toProf.X1 || toProf.X2;

  if(toUP){
    controllerData.dpadUpOn = toUP;
    controllerData.dpadDownOn = 0;
  }
  else{
    controllerData.dpadUpOn = toUP;
    controllerData.dpadDownOn = toProf.DOWN;
  }

  if(toProf.LEFT && toProf.RIGHT){
    controllerData.dpadLeftOn = 0;
    controllerData.dpadRightOn = 0;
  }
  else{
    controllerData.dpadLeftOn = toProf.LEFT;
    controllerData.dpadRightOn = toProf.RIGHT;
  }
  
  controllerData.startOn = toProf.START;
  controllerData.selectOn = toProf.Z;
  
  // And return the data!
  return controllerData;
}
