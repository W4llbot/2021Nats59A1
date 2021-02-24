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

void scoreFinal() {
  intake(127);
  timerBase(50, 50, 700);
  powerBase(0, 0);
  shootBall();
  waitShooter();
  delay(100);
  waitLoaded();
  intake(0);
  timerBase(-80, -80, 500);
}

void skillsRoute() {
  // intake 2 balls
  intake(127);
  baseMove(47);
  waitBase(1000);
  // delay(100);
  baseMove(-16);
  waitBase(500);
  delay(100);
  intake(0);

  // turn to tower 1
  baseTurn(-63);
  waitBase(1000);
  // delay(100);
  baseMove(18);
  waitBase(1000);

  // score tower 1
  powerBase(60, 60);
  intake(127);
  shootBall();
  waitShooter();
  delay(100);
  shootBall();
  waitShooter();
  waitLoaded();
  intake(-127);
  unPauseBase();


  baseMove(-10);
  waitBase(1000);
  baseTurn(-20);
  waitBase(1000);
  baseMove(-58);
  waitBase(2000);
  baseTurn(60);
  waitBase(1000);
}
