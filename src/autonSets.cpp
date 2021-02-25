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
  baseMove(-16);
  waitBase(1000);
  delay(100);
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
  delay(100);
  shootBall();
  waitShooter();
  waitLoaded();
  intake(-127);
  unPauseBase();


  //get next 2 balls
  baseMove(-49);
  waitBase(1500);
  shootBall();
  delay(500);
  baseTurn(-109, 1.65, 0.8);
  waitBase(1500);
  shootBall();
  delay(500);
  baseMove(-26);
  waitBase(1500);
  baseTurn(-17, 1.25, 0.6);
  waitBase(1500);
  baseMove(30);
  intake(127);
  waitBase(1500);

  // score tower 2
  powerBase(60, 60);
  shootBall();
  waitShooter();
  delay(100);
  shootBall();
  delay(100);
  intake(127);
  waitLoaded();
  intake(-127);
  unPauseBase();

}
