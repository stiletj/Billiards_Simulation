#ifndef TEXTURES_H_INCLUDED
#define TEXTURES_H_INCLUDED


/** @brief Turns an image into a texture.
 *
 * @param filename const char
 * @param widths int*
 * @param heights int*
 * @return unsigned char*
 *
 */
void LoadTextures(const char filenames[][20], int* widths, int* heights, unsigned char* imageData[]);

/** @brief Draws a sphere with a texture on it.
 *
 * @param index int
 * @param radius float
 * @param sliceNum int
 * @param stackNum int
 * @return void
 *
 */
void DrawTexturedSphere(int index, float radius, int sliceNum, int stackNum);


/** @brief Initialises the Texture Parameters.
 *
 * @param imageData[] unsigned char*
 * @param width int*
 * @param height int*
 * @return void
 *
 */
void InitTextures(unsigned char* imageData[], int* width, int* height);
#endif // TEXTURES_H_INCLUDED
