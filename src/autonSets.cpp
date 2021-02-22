#include "main.h"
#include "autonSets.hpp"

void scoreTower() {
  intake(127);
  shootBall();
  waitShooter();
  shootBall();
  waitShooter();
  waitLoaded();
  intake(0);
}


void skillsRoute() {
  intake(127);
  baseMove(47);
  waitBase(1000);
  delay(100);

  baseMove(-16);
  waitBase(500);
  delay(100);
  intake(0);
  baseTurn(-63);
  waitBase(1000);
  delay(100);
  baseMove(18);
  waitBase(1000);

  powerBase(60, 60);
  intake(127);
  shootBall();
  waitShooter();
  delay(200);
  shootBall();
  waitShooter();
  waitLoaded();
  intake(0);
  unPauseBase();
  baseMove(-10);
  waitBase(1000);
  delay(100);
}
