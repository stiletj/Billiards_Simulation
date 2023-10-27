#ifndef MENU_H
#define MENU_H

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

/**
* @brief Menu file
*
* Contains functions to display and do menu operations
*
* @author Zack Cornfield
* @version - 01 (10/05/2023)
    *
* @date 10/05/2023
*/

/**
* @brief Draws the primary menu with the play option
*
* @param
* @return void
*/
void DrawMenuStart();

/**
* @brief Draws the secondary menu with the ball setup options (Rectangle or Triangle)
*
* @param
* @return void
*/
void DrawMenuBalls();

/**
* @brief Draws the third menu with the table roughness options
*
* @param
* @return void
*/
void DrawMenuFriction();

/**
* @brief Draws the forth menu which appears when the game finishes
*
* @param score - type int the number of points/score that the player has got
* @return void
*/
void DrawMenuGameOver(int score);

/**
* @brief Draws the score menu in the top right of the screen which showcases the current score
*
* @param score - type int the number of points/score that the player has got
* @return void
*/
void DrawMenuScore(int score);

/**
* @brief Draws the menu border
*
* @param border_size - type float height and length of the border (i.e. size), border_color - type Vector3 color of border
* @return void
*/
void DrawMenuBorder(float border_size, Vector3 border_color);

/**
* @brief Draws outline on menu
*
* @param border_size - type float height and length of the border (i.e. size)
* @return void
*/
void drawMenuOutline(float border_size);

/**
* @brief Displays text
*
* @param x - type float x position, y - type float y position, z - type float z positition, r - type float R colour value, g - type float g colour value,
* b - type float B colour value, scale - type float scale/size of word, font - type void specifies chosen glut font, string - type char pointer stores the string to be outputted
* @return void
*/
void outputText(float x, float y, float z, float r, float g, float b, float scale, void *font, char *string);

#endif // MENU_H
