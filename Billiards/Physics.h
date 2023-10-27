/** @brief Deals with physics that are involved with a pool game.
 *
 *  @author Thomas Stile
 *  @date 26/04/2023
 *  @version 01
 *  Added function definitions and started to implement BallCollisionResolve.
 */

#ifndef PHYSICS_H
#define PHYSICS_H

#ifdef _WIN32
	//define something for Windows (32-bit and 64-bit, this part is common)
	#include <gl/freeglut.h>		// For windows
	#ifdef _WIN64
		//define something for Windows (64-bit only)
	#endif
#elif __APPLE__
	#include <GLUT/glut.h>			// for Mac OS
#endif

#include "Ball.h"
#include "Stick.h"
#include "geometry.h"
#include <math.h>

/** @brief Deals with the physics of the ball if it collides with another ball.
 *
 * @param ballOne BallData*
 * @param ballTwo BallData*
 * @return void
 *
 */
void BallCollisionResolve(BallData* ballOne, BallData* ballTwo);

/** @brief Deals with the physics of the ball if it collides with a wall.
 *
 * @param ball BallData*
 * @return void
 *
 */
void WallCollisionResolve(BallData* ball);

/** @brief Gets the rotation angle that the stick is currently at.
 *
 * @param vector Vector3
 * @param angle float
 * @param axis Vector3
 * @param result Vector3
 * @return void
 *
 */
void rotateVector(Vector3 vector, float angle, Vector3 axis, Vector3 result);

/** @brief Deals with the physics of the ball if it is hit by the cue.
 *
 * @param cue StickData*
 * @param cueBall BallData*
 * @return void
 *
 */
void CueCollisionResolve(StickData* cue, BallData* cueBall);

/** @brief Makes the balls disappear when they go into the pockets.
 *
 * @param ball BallData*
 * @return void
 *
 */
void PocketCollisionResolve(BallData* ball);

#endif // PHYSICS_H
