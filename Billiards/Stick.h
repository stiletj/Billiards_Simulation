#ifndef STICKS_H
#define STICKS_H

#ifdef _WIN32
	//define something for Windows (32-bit and 64-bit, this part is common)
	#include <gl/freeglut.h>		// For windows
	#ifdef _WIN64
		//define something for Windows (64-bit only)
	#endif
#elif __APPLE__
	#include <GLUT/glut.h>			// for Mac OS
#endif

#include "geometry.h"
#include "Ball.h"
#include <math.h>


/**
* @brief Contains stick functions and stick struct
*
* Stores stick information in a struct StickData
* Contains functions related to stick
*
* @author Zack Cornfield
* @version - 01 (03/05/2023)
    * Added initialiseStick function
    * Added calculateAngle function
    * Added calculatePosition function
    * Added calculateHypotenuse function
    * Added shoot function
    * Added update function
* @version - 02 (10/05/2023)
    * Added draw function
* @date 03/05/2023
*/

typedef struct StickData
{
    float radius;
    float height;
    float angle;
    float defaultAngle;
    Point3 position;
    Vector3 velocity;
    Vector3 color;
}StickData;

/**
* @brief Initialises the stick
*
* Initialises to default position at start of game
*
* @param stick - Type StickData store stick information, ball - Type BallData contains the information of the white ball
* @return void
*/
void initialiseStick(StickData* stick, BallData ball);

/**
* @brief Calculates the angle of the stick from the ball
*
* @param stick - Type StickData store stick information, ball - Type BallData contains the information of the white ball, mousePosition - Type Point3 stores the position of the mouse
* @return degrees
*/
void calculateStickAngle(StickData* stick, BallData ball, Point3 mousePosition);

/**
* @brief Calculates the position of the stick
*
* @param stick - Type StickData store stick information, ball - Type BallData contains the information of the white ball, mousePosition - Type Point3 stores the position of the mouse
* @return void
*/
void calculateStickPosition(StickData* stick, BallData ball, Point3 mousePosition);

/**
* @brief Calculates the hypotenuse given two points
*
* @param - v1 - Type Point3 contains coordinates of point 1, v2 - Type Point3 contains coordinates of point 2
* @return hypotenuse
*/
float calculateHypotenuse(Point3 v1, Point3 v2);

/**
* @brief Shoots the stick
*
* @param stick - Type StickData store stick information, ball - Type BallData contains the information of the white ball, mousePosition - Type Point3 stores the position of the mouse
* @return
*/
void shootStick(StickData* stick, BallData ball, Point3 mousePosition);

/**
* @brief Updates the position of the stick
*
* @param - stick - Type StickData store stick information, ball - Type BallData contains the information of the white ball
* @return
*/
void updateStick(StickData* stick, BallData *ball, Point3 mousePosition, float *prevTime);

/**
* @brief Draws the stick
*
* @param - stick - Type StickData store stick information, ball - Type BallData contains the information of the white ball
* @return
*/
void drawStick(StickData* stick, BallData ball);

#endif //STICKS_H
