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

Vision routerVision(routerVisionPort);
ADIAnalogIn shooterLine(shooterLinePort);
ADIAnalogIn routerLine(routerLinePort);

int discardSig = SIG_BLUE;
bool autosortEnabled = false;
bool forcedOuttake = false;
bool shootTrigger = false;
bool loaded = false;

int oppSig(int sig) {
  return 3 - sig;
}

void toggleDiscardSig() {
  discardSig = oppSig(discardSig);
}

void routerControl(void * ignore) {
  Controller master(E_CONTROLLER_MASTER);
  router.move(127);
  while(true) {
  //   vision_object_s_t visionObject = routerVision.get_by_size(0);
  //   int currSig = visionObject.height > VISION_BALL_THRESHOLD ? visionObject.signature : SIG_EMPTY;
    if(forcedOuttake == true) router.move(-127);
    // else if(autosortEnabled) {
  //     if(currSig == discardSig) router.move(-127);
  //     else if(currSig == oppSig(discardSig)) {
  //       if(shooterLine.get_value() < SHOOTER_BALL_THRESHOLD) router.move(10);
  //       else router.move(127);
  //     }
  //
  //     // master.print(2, 0, "Discard: %S\n", sigToName[discardSig]);
  //     // printf("Current sig: %d\n", currSig);
    else {
      if(shooterLine.get_value() < SHOOTER_BALL_THRESHOLD && routerLine.get_value() < ROUTER_BALL_THRESHOLD) {
        router.move(10);
        loaded = true;
      }else {
        router.move(127);
        loaded = false;
      }

      // master.print(2, 0, "Autosort disabled\n");
    }
    delay(5);
  }
}

void waitShooter() {
  while(shooterLine.get_value() < SHOOTER_BALL_THRESHOLD) delay(5);
  while(shooterLine.get_value() > SHOOTER_BALL_THRESHOLD) delay(5);
  while(shootTrigger) delay(5);
  // while(shooterLine.get_value() < SHOOTER_BALL_THRESHOLD) delay(5);
}

void shooterControl(void * ignore) {
  while(true) {
    // if(autosortEnabled) {
      if(shootTrigger) {
        shooter.move(127);
        while(shooterLine.get_value() < SHOOTER_BALL_THRESHOLD) delay(5);
        while(shooterLine.get_value() > SHOOTER_BALL_THRESHOLD) delay(5);
        shooter.move(-10);
        shootTrigger = false;
      }
    // }
    delay(5);
  }
}

void shootBall() {
  shootTrigger = true;
}

void enableAutosort(bool value) {
  router.move(127);
  autosortEnabled = value;
}
void forceOuttake(bool value) {
  forcedOuttake = value;
}
void intake(int speed) {
  lRoller.move(speed);
  rRoller.move(speed);
}

void waitLoaded() {
  while(!loaded) delay(5);
}
