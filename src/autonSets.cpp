#include "main.h"
#include "autonSets.hpp"

void scoreTower() {
  powerBase(70, 70);
  intake(127);
  shootBall();
  waitShooter();
  // intake(0);
  powerBase(0, 0);
  pauseBase(false);
  resetCoords(0, 0, 0);
}

// void scoreTower2() {
//   powerBase(70, 70);
//   intake(127);
//   shootBall();
//   waitShooter();
//   delay(300);
//   shootBall();
//   waitShooter();
//   intake(-50);
//   powerBase(0, 0);
//   pauseBase(false);
//   resetCoords(0, 0, 0);
// }

void skillsRoute() {
    // score tower 1
    double stdDelay = 300;
    resetCoords(0, 0, 0);
    scoreTower();

    // Reverse to collect 2 balls
    delay(300);
    baseMove(-68);
    delay(300);
    shootBall();
    waitShooter();
    intake(-50);
    // delay(450);
    shootBall();
    waitBase(2000);
    delay(stdDelay);

    // turn and move to 2nd goal
    baseTurn(65);
    waitBase(1000);
    delay(stdDelay);
    baseMove(28);
    waitBase(1000);

    // score tower 2
    powerBase(70, 70);
    intake(127);
    shootBall();
    waitShooter();
    delay(300);
    intake(0);
    shootBall();
    waitShooter();
    powerBase(0, 0);
    pauseBase(false);
    resetCoords(0, 0, 0);

    // turn and collect ball
    delay(stdDelay);
    baseMove(-10);
    waitBase(500);
    delay(stdDelay);
    baseTurn(-30);
    waitBase(1000);
    shootBall();
    delay(stdDelay);
    baseMove(-54);
    waitBase(2000);
    delay(stdDelay);

    // score tower 3
    baseTurn(105);
    waitBase(1000);
    delay(stdDelay);
    baseMove(15);
    waitBase(500);
    scoreTower();

    // turn and collect ball
    baseMove(-18);
    waitBase(1000);
    delay(stdDelay);
    baseTurn(65, 1.0, 0.3);
    waitBase(1000);
    intake(-50);
    delay(stdDelay);
    baseMove(-48);
    shootBall();
    waitShooter();
    // delay(350);
    shootBall();
    waitBase(2000);
    delay(stdDelay);

    // turn and sore score tower
    baseTurn(155);
    waitBase(1000);
    delay(stdDelay);
    baseMove(5);
    waitBase(500);
    scoreTower();

    // reverse 10 turn 102 move 33 turn -70 12

    // turn and collect ball
    baseMove(-10);
    waitBase(500);
    delay(stdDelay);
    baseTurn(257);
    waitBase(1500);
    delay(stdDelay);
    intake(127);
    baseMove(42);
    waitBase(1500);
    shootBall();
    delay(stdDelay);

    // turn and score scoreTower
    baseTurn(195, 1.0, 0.3);
    waitBase(1000);
    delay(stdDelay);
    baseMove(25);
    waitBase(1000);

    powerBase(70, 70);
    intake(127);
    shootBall();
    waitShooter();
    delay(300);
    intake(0);
    shootBall();
    waitShooter();
    powerBase(0, 0);
    pauseBase(false);
    resetCoords(0, 0, 0);

}
