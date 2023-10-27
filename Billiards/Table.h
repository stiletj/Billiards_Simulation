//Table.h

#ifndef TABLE_H
#define TABLE_H

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
#include <math.h>
#include "geometry.h"
#include "Ball.h"

/**
* @brief Contains functions regarding the table
* @author Jacob Mondi
* @version - 02
*
*	-fixed miscalculations
*
* @date 03/05/2023
*/


/**
* @brief Draw the Table
*
* @return void
*/
void drawTable();

/** @brief Detects if the ball goes into one of the pockets.
 *
 * @param ball BallData
 * @return int
 *
 */
int BalltoPocketCheck(BallData ball);

/** @brief Detects if the ball hits a wall.
 *
 * @param ball BallData
 * @return int
 *
 */
int BalltoWallCheck(BallData *ball);

/** @brief Detects which wall the ball hit.
 *
 * @param plane[] Point3
 * @param ball BallData
 * @return int
 *
 */
int WallCollisionCalculation(Point3 plane[], BallData *ball);

void tableDetails();

#endif // TABLE_H
