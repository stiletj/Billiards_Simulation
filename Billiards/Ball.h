//Ball.h

#ifndef BALL_H
#define BALL_H

#ifdef _WIN32
	//define something for Windows (32-bit and 64-bit, this part is common)
	#include <gl/freeglut.h>		// For windows
	#ifdef _WIN64
		//define something for Windows (64-bit only)
	#endif
#elif __APPLE__
	#include <GLUT/glut.h>			// for Mac OS
#endif

#include <stdio.h>
#include "geometry.h"
#include "math.h"
#include "Textures.h"

/**
* @brief Contains ball functions and ball struct
*
* Stores ball information in a struct ballData
* Contains functions related to ball
*
* @author Zack Cornfield
* @version - 03 (01/05/2023)
    * Reworked update function to calculate force on balls
    * Put friction calculate into seperate function
    * Put rotatation angle calculation into seperate function
    * Improved modularity of update function
* @date 01/05/2023
*/

/**
* BallData struct
* Stores properties/related data of ball
*/
typedef struct BallData{
    // Ball properties
    float ball_radius;
    char ball_texture[20];
    Point3 ball_pos;

    //Forces
    Vector3 ball_vel;
    Vector3 ball_acc;
    Vector3 ball_force;

    //Rotation
    float rotationAngleX;
    float rotationAngleZ;

    //Mass
    float ball_mass;


    //Moving
    int isMoving;
}BallData;

/**
* @brief Initialises the balls
*
* Initialises partially using the provided parameters (positions, colors, mass, forces)
*
* @param ball - Array of type BallData containing the data of balls, positions - Array of type Point3 containing position vectors for balls,
* colors - 2D array of type char containing textures for balls, mass - Array of type float containing mass for balls, force - Array of type Vector3 stores the force acting upon the balls, numberOfForces - type int stores number of forces
* @return void
*/
void InitialiseBalls(BallData balls[], int size, Point3 positions[], char textures[][20], float mass[], Vector3 forces[], int numberOfForces);

/**
* @brief Updates the position of the ball
*
* Checks for collision with table
*
* @param balls - array of type Ball data containing ball data, prevTime - type float storing previous time of positionUpdate, size - type int size of balls array,  array of type Vector3 containing colors for balls,
* force - Array of type Vector3 stores the force acting upon the balls, numberOfForces - type int stores number of forces, frictionValue - type float stores the level of friction
* @return void
*/
void PositionUpdate(BallData balls[], float *prevTime, int size, Vector3 forces[], int numberOfForces, float frictionValue);

/**
* @brief Updates the rotation angle of the ball (X and Z axis)
*
* @param ball - type Ball data containing ball data, timeSincePrev - type float storing time since previous update, s
* @return void
*/
void calculateRotationAngles(BallData* ball, float timeSincePrev);

/**
* @brief Updates the friction of the ball
*
* Calculates the friction vector
*
* @param ball - Type Ball data containing ball data, fric - Type Vector3 stores the friction vector to be modified, frictionValue - type float stores the level of friction
* @return void
*/
void calculateFriction(BallData ball, Vector3 *fric, float frictionValue);

/**
* @brief Draws the ball
*
* Draws the ball provided to the function
*
* @param ball - type Ball data containing ball data, prevTime - type float time of previous frame
* @return void
*/
void DrawBall(BallData ball, int Index);

/**
* @brief Checks if balls are colliding
*
* Checks for collision between ball_1 and ball_2
*
* @param ball_1 - type Ball data containing ball data, ball_2 - type Ball data containing ball data
* @return valid
*/
int BallCollision(BallData ball_1, BallData ball_2);


#endif // BALL_H

