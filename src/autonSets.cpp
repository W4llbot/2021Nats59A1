#include "main.h"
#include "autonSets.hpp"

void scoreTower() {
  powerBase(70, 70);
  intake(127);
  shootBall();
  waitShooter();
  intake(0);
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
    /*scoreTower();

    // Reverse to collect 2 balls
    delay(300);
    baseMove(-68);
    // delay(300);
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
    intake(-50);
    baseMove(-10);
    waitBase(500);
    delay(stdDelay);
    baseTurn(-30);
    waitBase(1000);
    shootBall();
    delay(stdDelay);
    baseMove(-52);
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
    shootBall();
    delay(stdDelay);
    baseMove(-49);
    waitShooter();
    // delay(350);
    shootBall();
    waitBase(2000);
    delay(stdDelay);

    // turn and score tower 4
    baseTurn(152);
    waitBase(1000);
    delay(stdDelay);
    baseMove(5);
    waitBase(500);
    scoreTower();
    intake(-127);

    // reverse 30 move 10 turn 245 move 40 turn 195 move 25

    // turn and collect ball
    baseMove(-30);
    waitBase(1500);
    shootBall();
    delay(stdDelay);
    baseMove(10);
    waitBase(1000);
    delay(stdDelay);
    baseTurn(245);
    waitBase(1500);
    delay(stdDelay);
    intake(127);
    baseMove(39);
    waitBase(1500);
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
    resetCoords(0, 0, 0);*/

    // reverse -55 turn -60 reverse -18 turn 90 move forward 31

     //reverse and eject + collect ball
     // add 188 deg to everything after merge
    baseMove(-54);
    shootBall();
    waitBase(2000);
    delay(stdDelay);
    shootBall();
    baseTurn(-38, 1.0, 0.3);
    waitBase(1000);
    delay(stdDelay);
    // intake(127);
    baseMove(-19);
    waitBase(2000);
    delay(stdDelay);

    //turn and score tower 6
    baseTurn(50);
    waitBase(1000);
    delay(stdDelay);
    baseMove(31);
    waitBase(1000);
    delay(stdDelay);

    scoreTower();
    intake(-127);

    // turn and collect ball
    delay(stdDelay);
    intake(-50);
    baseMove(-10);
    waitBase(500);
    delay(stdDelay);
    baseTurn(-38);
    waitBase(1000);
    shootBall();
    delay(stdDelay);
    baseMove(-49);
    waitBase(2000);
    delay(stdDelay);

    // score tower 7
    baseTurn(93);
    waitBase(1000);
    delay(stdDelay);
    baseMove(15);
    waitBase(500);
    scoreTower();

    // turn and collect ball
    baseMove(-18);
    waitBase(1000);
    delay(stdDelay);
    baseTurn(53, 1.0, 0.3);
    waitBase(1000);
    intake(-50);
    shootBall();
    delay(stdDelay);
    baseMove(-49);
    waitShooter();
    // delay(350);
    shootBall();
    waitBase(2000);
    delay(stdDelay);

    // turn and score tower 4
    baseTurn(141);
    waitBase(1000);
    delay(stdDelay);
    baseMove(5);
    waitBase(500);
    scoreTower();
    intake(-127);

    baseMove(-30);
    waitBase(1500);
    shootBall();
    delay(stdDelay);
    baseTurn(315);
    waitBase(1500);
    delay(stdDelay);
    intake(127);
    powerBase(80, 80);
    delay(1000);
    powerBase(0, 0);

    waitLoaded();
    shootBall();
    delay(500);
    powerBase(-127, -127);
    delay(1000);
    powerBase(0, 0);
}
