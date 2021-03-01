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
  baseMove(-32, 0.27, 0);
  delay(200);
  forceOuttake(true);
  delay(500);
  forceOuttake(false);
  waitBase(1500);
  baseTurn(-88, 2.4, 0);
  waitBase(1500);
  baseMove(-40.5, 0.26, 0);
  waitBase(1500);
  baseTurn(-18, 1.37, 0);
  waitBase(1500);
  baseMove(29, 0.29, 0);
  intake(127);
  waitBase(1500);

  // score tower 2
  printf("Scoring Tower 2\n\n\n");
  powerBase(60, 60);
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
  baseTurn(30, 1.45, 0);
  waitBase(1500);
  baseMove(19, 0.31, 0);
  waitBase(1000);

  // score tower 3
  printf("Scoring Tower 3\n\n\n");
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

  baseMove(-32, 0.27, 0);
  delay(100);
  forceOuttake(true);
  delay(500);
  forceOuttake(false);
  waitBase(1000);
  baseTurn(4, 2.5, 0);
  waitBase(1000);
  baseMove(-39, 0.25, 0);
  waitBase(1000);
  baseTurn(70, 1.5, 0);
  waitBase(1500);
  baseMove(30, 0.28, 0);
  waitBase(1000);

  printf("Scoring Tower 4\n\n\n");
  powerBase(60, 60);
  intake(127);
  shootBall();
  waitLoaded();
  intake(-127);
  unPauseBase();

  baseMove(-10, 0.35, 0);
  waitBase(1000);
  baseTurn(40, 2.2, 0);
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
  baseMove(23, 0.27, 0);
  waitBase(1000);
  baseMove(-16, 0.3, 0);
  waitBase(1000);

  // second half
  //
  //
  //
  //

  baseTurn(-63 + 180, 1.55, 0);
  waitBase(1000);
  baseMove(17, 0.32, 0);
  waitBase(1000);

  // score tower 5
  printf("Scoring Tower 5\n\n\n");
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
  baseMove(-32, 0.27, 0);
  delay(100);
  forceOuttake(true);
  delay(500);
  forceOuttake(false);
  waitBase(1500);
  baseTurn(-88 + 180, 2.4, 0);
  waitBase(1500);
  baseMove(-39, 0.26, 0);
  waitBase(1500);
  baseTurn(-18 + 180, 1.37, 0);
  waitBase(1500);
  baseMove(29, 0.29, 0);
  intake(127);
  waitBase(1500);

  // score tower 6
  printf("Scoring Tower 6\n\n\n");
  powerBase(60, 60);
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
  baseMove(-12, 0.35, 0);
  waitBase(1000);
  baseTurn(30 + 180, 1.45, 0);
  waitBase(1500);
  baseMove(19, 0.31, 0);
  waitBase(1000);

  // score tower 8
  printf("Scoring Tower 8\n\n\n");
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
}
