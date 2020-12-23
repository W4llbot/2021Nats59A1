/**
 * Odometry functions and task that constantly updates the robot's position
 * - Retrieve & package encoder values function
 * - Odometry task
 */
#include "main.h"
/** to test odometry in opcontrol() when not in competition */
#define COMPETITION_MODE false
#define USING_LATERAL_ENCD true

/** declare encoders */
// ADIEncoder encoderL(encdL_port, encdL_port + 1);
// ADIEncoder encoderR(encdR_port, encdR_port + 1);
// ADIEncoder encoderLat(encdLat_port, encdLat_port + 1);

#define inPerDegLat 0.0241043549920626 //determine empirically

/** encdL, encdR = value of respective encoders */
double encdL = 0, encdR = 0;
/** position: object of class Coordinates - position of the robot */
Coordinates position;
/**
 * Retrive encoder values.
 * @param processed
 * whether the returned values should be in inches (default) or encoder degrees
 *
 * @return
 * encoder values packaged in a pair
 */
std::pair<double, double> getEncdVals(bool rawData = false){
  /** declare motors */
  Motor FL (fLPort);
  Motor BL (bLPort);
  Motor FR (fRPort);
  Motor BR (bRPort);

  if(!rawData) return std::make_pair((double) BL.get_position()*inPerDeg, (double) BR.get_position()*inPerDeg);
  else return std::make_pair((double)BL.get_position(), (double)BR.get_position());
}
/** Update the robot's position using side encoders values. */
void baseOdometry(void * ignore){
  /** previous encoder values; to be used in calculations */
  double prevEncdL = 0;
  double prevEncdR = 0;
  double prevEncdLat = 0;
  double prevAngle = 0;
  /** indexer */
  int count = 0;
  while(!COMPETITION_MODE || competition::is_autonomous()){
    /** retrieve & update encoder values */
    encdL = getEncdVals().first;
    encdR = getEncdVals().second;
    /** refer to Odometry Documentation.docx for mathematical proof */
    double encdChangeL = (encdL-prevEncdL);
    double encdChangeR = (encdR-prevEncdR);
    /** refer to Odometry Documentation.docx for mathematical proof */
    double sumEncdChange = encdChangeL + encdChangeR;
    double deltaAngle = (encdChangeL - encdChangeR)/baseWidth;
    double halfDeltaAngle = deltaAngle/2;
    position.angle += deltaAngle;
    /** update x- and y-coordinates */
    if(deltaAngle == 0) {
      /** handle 0 as the formula involves division by deltaAngle */
      /** refer to Odometry Documentation.docx for mathematical proof */
			position.x += sumEncdChange/2*sin(position.angle);
			position.y += sumEncdChange/2*cos(position.angle);
		}
		else {
      /** refer to Odometry Documentation.docx for mathematical proof */
			position.x += (sumEncdChange/deltaAngle)*sin(halfDeltaAngle)*sin(prevAngle+halfDeltaAngle);
			position.y += (sumEncdChange/deltaAngle)*sin(halfDeltaAngle)*cos(prevAngle+halfDeltaAngle);
		}

    // #if USING_LATERAL_ENCD
		// 	double encdLat = (double)encoderLat.get_value()*inPerDegLat;
		// 	double encdChangeLat = encdLat - prevEncdLat;
		// 	double latShift = encdChangeLat;
		// 	if(deltaAngle) latShift = (encdChangeLat/deltaAngle)*sin(halfDeltaAngle)*2.0;
    //
		// 	double xShift = latShift * cos(prevAngle+halfDeltaAngle);
		// 	double yShift = latShift * -sin(prevAngle+halfDeltaAngle);
		// 	position.x += xShift;
		// 	position.y += yShift;
    //
		// 	prevEncdLat = encdLat;
		// #endif

    /** Update prev variables */
		prevEncdL = encdL;
		prevEncdR = encdR;
		prevAngle = position.angle;
    /** print to assist debugging */
    if(!COMPETITION_MODE) position.printCoordsMaster();
    if((DEBUG_MODE == 1) && (count++ % 100 == 0)){
      position.printCoordsTerminal();
      // printf("Encds: %.2f %.2f targetEncds: %.2f %.2f \n", encdL, encdR, targetEncdL, targetEncdR);
    }
    if(DEBUG_MODE == 4) printf("Encoder values %4.0f \t %4.0f\n",getEncdVals(true).first,getEncdVals(true).second);
    /** refresh rate of Task */
    Task::delay(5);
  }
}