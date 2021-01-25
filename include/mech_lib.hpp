#ifndef MECH_LIB_HPP
#define MECH_LIB_HPP

void toggleDiscardSig();
void routerControl(void * ignore);

void shootBall();
void enableAutosort(bool value);
void shooterControl(void * ignore);
void forceOuttake(bool value);
void waitShooter();
void intake(int speed);
void waitLoaded();

#endif
