#ifdef _WIN32
#include <gl/freeglut.h>        // For Windows
#ifdef _WIN64
// define something for Windows (64-bit only)
#endif
#elif __APPLE__
#include <GLUT/glut.h>          // for Mac OS
#endif

#define STB_IMAGE_IMPLEMENTATION
#include "Textures.h"
#include "geometry.h"
#include "stb_image.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_TEXTURES 16

void LoadTextures(const char filenames[][20], int* widths, int* heights, unsigned char* imageData[])
{
    int ImageChannels;

    for (int i = 0; i < NUM_TEXTURES; i++)
    {

        //printf("TEST2\n");
        imageData[i] = stbi_load(filenames[i], &widths[i], &heights[i], ImageChannels, STBI_rgb_alpha);

        if (!imageData[i])
        {
            printf("Error in the image load\n");
        }
    }
}

GLuint* textureIDs = NULL;

void InitTextures(unsigned char* imageData[], int* width, int* height)
{

    if (textureIDs != NULL)
    {
        glDeleteTextures(NUM_TEXTURES, textureIDs);
        free(textureIDs);
    }


    textureIDs = (GLuint*)malloc(NUM_TEXTURES * sizeof(GLuint));

    glGenTextures(NUM_TEXTURES, textureIDs);

    for (int i = 0; i < NUM_TEXTURES; i++)
    {
        glBindTexture(GL_TEXTURE_2D, textureIDs[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width[i], height[i], 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }
}

void DrawTexturedSphere(int index, float radius, int sliceNum, int stackNum)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureIDs[index]);
    glColor3f(1.f, 1.f, 1.f);

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);

    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

    glutSolidSphere(radius, sliceNum, stackNum);

    glDisable(GL_TEXTURE_2D);
}
