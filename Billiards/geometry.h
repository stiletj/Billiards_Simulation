#ifndef GEOMETRY_H_INCLUDED
#define GEOMETRY_H_INCLUDED

#include <gl/freeglut.h>

typedef GLfloat Point2[2];
typedef GLfloat Point3[3];
typedef Point3 Vector3;     // Vector in 3D


// Camera
typedef struct Camera{
    Point3  position;
    Point3  lookat;
    Vector3 up;          // the up vector
}Camera;

// Drawing


#endif // GEOMETRY_H_INCLUDED
