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
  baseMove(50);
  waitBase(2000);
  // delay(100);
  baseMove(-15);
  waitBase(1000);
  delay(10);
  intake(0);

  // turn to tower 1
  baseTurn(-63, 1.5, 0.75);
  waitBase(1000);
  // delay(100);
  baseMove(18);
  waitBase(1000);

  // score tower 1
  powerBase(60, 60);
  intake(127);
  shootBall();
  waitShooter();
  delay(10);
  shootBall();
  waitShooter();
  waitLoaded();
  intake(-127);
  unPauseBase();

  //get next 2 balls
  baseMove(-49);
  delay(500);
  shootBall();
  waitBase(1500);
  shootBall();
  baseTurn(-108, 1.8, 0.9);
  waitBase(1500);
  shootBall();
  baseMove(-26.5);
  waitBase(1500);
  baseTurn(-18, 1.25, 0.6);
  waitBase(1500);
  baseMove(30);
  intake(127);
  waitBase(1500);

  // score tower 2
  powerBase(60, 60);
  shootBall();
  waitShooter();
  delay(10);
  shootBall();
  waitLoaded();
  intake(-127);
  unPauseBase();

  // collect 2 balls
  baseMove(-10);
  waitBase(1000);
  baseTurn(-95, 1.4, 0.7);
  waitBase(1000);
  shootBall();
  baseMove(-45);
  waitBase(1500);
  baseTurn(-33, 1.4, 0.7);
  intake(127);
  waitBase(1000);
  baseMove(21);
  waitBase(1000);
  baseMove(-11);
  waitBase(1000);
  baseTurn(30, 1.4, 0.7);
  waitBase(1500);
  baseMove(15);
  waitBase(1000);

  powerBase(60, 60);
  intake(127);
  shootBall();
  waitShooter();
  delay(10);
  shootBall();
  waitShooter();
  waitLoaded();
  intake(-127);
  unPauseBase();
  baseMove(-10);
  waitBase(1000);
}
