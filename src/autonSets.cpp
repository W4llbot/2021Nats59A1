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

double offset = 0;
double ramPow = 40;

void goal8() {
  intake(-127);
  baseMove(-17, 0.3, 0);
  waitBase(1000);
  baseTurn(-43.5 + offset, 1.85, 0);
  waitBase(1000);
  baseMove(-48, 0.25, 0);
  shootBall();
  waitShooter();
  delay(100);
  shootBall();
  waitBase(2000);
  baseTurn(43 + offset, 1.35, 0);
  waitBase(1500);
  baseMove(9, 0.4, 0);
  waitBase(1000);

  powerBase(ramPow, ramPow);
  intake(127);
  shootBall();
  waitLoaded();
  intake(-127);
  unPauseBase();

  baseMove(-32, 0.27, 0);
  waitBase(1500);
  shootBall();
  intake(0);
  baseTurn(-133 + offset, 1, 0);
  waitBase(2000);
  baseMove(9, 0.4, 0);
  waitBase(1000);
  scoreFinal();
}


void skillsRoute() {
  // intake 2 balls
  intake(127);
  baseMove(48, 0.26, 0);
  waitBase(2000);
  // delay(100);
  baseMove(-13, 0.32, 0);
  waitBase(1000);
  delay(10);
  intake(0);

  // turn to tower 1
  baseTurn(-63, 1.5, 0);
  waitBase(1000);
  // delay(100);
  baseMove(17, 0.32, 0);
  waitBase(1000);

  // score tower 1
  printf("Scoring Tower 1\n\n\n");
  powerBase(ramPow, ramPow);
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
  baseMove(-32, 0.27, 0);
  delay(200);
  forceOuttake(true);
  delay(500);
  forceOuttake(false);
  waitBase(1500);
  baseTurn(-86, 2.75, 0);
  waitBase(1500);
  baseMove(-40.3, 0.26, 0);
  waitBase(1500);
  baseTurn(-18, 1.37, 0);
  waitBase(1500);
  baseMove(29, 0.29, 0);
  intake(127);
  waitBase(1500);

  // score tower 2
  printf("Scoring Tower 2\n\n\n");
  powerBase(ramPow, ramPow);
  shootBall();
  waitShooter();
  delay(10);
  shootBall();
  waitLoaded();
  intake(-127);
  unPauseBase();

  // collect 2 balls
  baseMove(-10, 0.35, 0);
  waitBase(1000);
  baseTurn(-92, 1.42, 0);
  waitBase(1000);
  shootBall();
  baseMove(-45, 0.25, 0);
  waitBase(1500);
  baseTurn(-33, 1.45, 0);
  intake(127);
  waitBase(1000);
  baseMove(22, 0.3, 0);
  waitBase(1500);
  baseMove(-13, 0.35, 0);
  waitBase(1000);
  baseTurn(28, 1.5, 0);
  waitBase(1500);
  baseMove(19, 0.35, 0);
  waitBase(1000);

  // score tower 3
  printf("Scoring Tower 3\n\n\n");
  powerBase(ramPow, ramPow);
  intake(127);
  shootBall();
  waitShooter();
  delay(10);
  shootBall();
  waitShooter();
  waitLoaded();
  intake(-127);
  unPauseBase();

  baseMove(-32, 0.27, 0);
  delay(100);
  forceOuttake(true);
  delay(500);
  forceOuttake(false);
  waitBase(1000);
  baseTurn(4, 2.7, 0);
  waitBase(1000);
  baseMove(-39, 0.27, 0);
  waitBase(1500);
  baseTurn(70, 1.40, 0);
  waitBase(1500);
  baseMove(28, 0.3, 0);
  waitBase(1000);

  printf("Scoring Tower 4\n\n\n");
  powerBase(ramPow, ramPow);
  intake(127);
  shootBall();
  waitLoaded();
  intake(-127);
  unPauseBase();

  baseMove(-10, 0.35, 0);
  waitBase(1000);
  baseTurn(40, 2.27, 0);
  delay(200);
  shootBall();
  waitBase(500);
  delay(200);
  baseTurn(160, 1.15, 0);
  waitBase(1500);
  intake(127);
  baseMove(36, 0.27, 0);
  waitBase(1500);
  baseTurn(180, 2.5, 0);
  waitBase(1000);
  baseMove(22, 0.3, 0);
  waitBase(1000);
  baseMove(-14, 0.3, 0);
  waitBase(1000);

  // second half
  //
  //
  //
  //

  // turn to tower 1
  baseTurn(-63 + 180, 1.5, 0);
  waitBase(1000);
  // delay(100);
  baseMove(17, 0.32, 0);
  waitBase(1000);

  // score tower 1
  printf("Scoring Tower 1\n\n\n");
  powerBase(ramPow, ramPow);
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
  baseMove(-32, 0.27, 0);
  delay(200);
  forceOuttake(true);
  delay(500);
  forceOuttake(false);
  waitBase(2000);
  baseTurn(-86 + 180, 2.7, 0);
  waitBase(1500);
  baseMove(-40, 0.26, 0);
  waitBase(1500);
  baseTurn(-18 + 180, 1.37, 0);
  waitBase(1500);
  baseMove(30, 0.29, 0);
  intake(127);
  waitBase(1500);

  // score tower 2
  printf("Scoring Tower 2\n\n\n");
  powerBase(ramPow, ramPow);
  shootBall();
  waitShooter();
  delay(10);
  shootBall();
  waitLoaded();
  intake(-127);
  unPauseBase();

  // collect 2 balls
  baseMove(-10, 0.35, 0);
  waitBase(1000);
  baseTurn(-92 + 180, 1.42, 0);
  waitBase(1000);
  shootBall();
  baseMove(-45, 0.25, 0);
  waitBase(1500);
  baseTurn(-33 + 180, 1.45, 0);
  intake(127);
  waitBase(1000);
  baseMove(22, 0.3, 0);
  waitBase(1500);
  baseMove(-11.5, 0.35, 0);
  waitBase(1000);
  baseTurn(28 + 180, 1.5, 0);
  waitBase(1500);
  baseMove(19, 0.35, 0);
  waitBase(1000);

  // score tower 3
  printf("Scoring Tower 3\n\n\n");
  powerBase(ramPow, ramPow);
  intake(127);
  shootBall();
  waitShooter();
  delay(10);
  shootBall();
  waitShooter();
  waitLoaded();
  intake(-127);
  unPauseBase();

  offset = bearing;
  goal8();
}
