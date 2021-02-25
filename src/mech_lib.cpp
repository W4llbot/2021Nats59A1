#include "main.h"
#include "mech_lib.hpp"

#define VISION_BALL_THRESHOLD 100
#define SHOOTER_BALL_THRESHOLD 2500
#define ROUTER_BALL_THRESHOLD 2850
enum VisionSignature {SIG_EMPTY, SIG_RED, SIG_BLUE};
std::string sigToName[3] = {"Empty", "Red", "Blue"};

Motor shooter(shooterPort);
Motor router(routerPort);
Motor lRoller(lRollerPort);
Motor rRoller(rRollerPort);

ADIAnalogIn shooterLine(shooterLinePort);
ADIAnalogIn routerLine(routerLinePort);

bool forcedOuttake = false;
bool shootTrigger = false;
bool loaded = false;

void routerControl(void * ignore) {
  Controller master(E_CONTROLLER_MASTER);
  router.move(127);
  while(true) {
    if(forcedOuttake == true) router.move(-127);
    else {
      if(shooterLine.get_value() < SHOOTER_BALL_THRESHOLD && routerLine.get_value() < ROUTER_BALL_THRESHOLD) {
        router.move(10);
        loaded = true;
      }else {
        router.move(127);
        loaded = false;
      }
    }
    delay(5);
  }
}

bool isLoaded() {
  return shooterLine.get_value() < SHOOTER_BALL_THRESHOLD;
}

void waitShooter() {
  // while(!isLoaded()) delay(5);
  while(isLoaded()) delay(5);
  while(!isLoaded()) delay(5);
  // while(shooterLine.get_value() < SHOOTER_BALL_THRESHOLD) delay(5);
  // while(shootTrigger) delay(5);
  // while(shooterLine.get_value() < SHOOTER_BALL_THRESHOLD) delay(5);
}

void shooterControl(void * ignore) {
  while(true) {
    if(shootTrigger) {
      shooter.move(127);
      waitShooter();
      shooter.move(-10);
      shootTrigger = false;
    }
    delay(5);
  }
}

void shootBall() {
  shootTrigger = true;
}

void forceOuttake(bool value) {
  forcedOuttake = value;
}
void intake(int speed) {
  lRoller.move(speed);
  rRoller.move(speed);
}


void waitLoaded() {
  while(routerLine.get_value() > ROUTER_BALL_THRESHOLD) delay(5);
}
