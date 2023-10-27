#include "stick.h"

void initialiseStick(StickData* stick, BallData ball)
{
    stick->position[0] = ball.ball_pos[0];
    stick->position[1] = ball.ball_pos[1];
    stick->position[2] = ball.ball_pos[2] + (2*ball.ball_radius);

    stick->radius = ball.ball_radius/2;

    stick->height = 17.6 * 0.4;

    stick->velocity[0] = 0.0f;
    stick->velocity[1] = 0.0f;
    stick->velocity[2] = 0.0f;

    stick->angle = -180;
    stick->defaultAngle = 90;

    stick->color[0] = 0.6;
    stick->color[1] = 0.4;
    stick->color[2] = 0.2;
}

void calculateStickAngle(StickData* stick, BallData ball, Point3 mousePosition)
{
    float h = calculateHypotenuse(ball.ball_pos, mousePosition);
    float o = mousePosition[2] - ball.ball_pos[2];

    float degrees = (asin(o/h) * 180)/M_PI + 180;

    if(ball.ball_pos[0] > mousePosition[0])
    {
        degrees = 180.f - degrees;
    }
    if(degrees < 0) {
        degrees += 360.f;
    }
    stick->angle = degrees;
}

void calculateStickPosition(StickData* stick, BallData ball, Point3 mousePosition)
{
    float d = calculateHypotenuse(ball.ball_pos, mousePosition);

    stick->position[0] = ball.ball_pos[0];
    stick->position[1] = ball.ball_pos[1];
    stick->position[2] = d;
}

float calculateHypotenuse(Point3 v1, Point3 v2)
{
    float distance = 0.f;
    distance = sqrt( pow(v2[0] - v1[0], 2) + pow(v2[2] - v1[2], 2) );
    return distance;
}

void shootStick(StickData* stick, BallData ball, Point3 mousePosition)
{
    if (stick->velocity[2] == 0.f)
    {
        stick->velocity[2] = -1.f;
        //printf("%f %f %f\n", mousePosition[2], ball.ball_pos[2], mousePosition[2] - ball.ball_pos[2]);
    }
}

void updateStick(StickData* stick, BallData *ball, Point3 mousePosition, float *prevTime)
{
    float acceleration = -20.f;

    // 1. Get the elapsed time in seconds
    float currTime = glutGet(GLUT_ELAPSED_TIME) / 1000.f; //Returns time in milliseconds so /1000 is needed to get seconds
    float timeSincePrevFrame = currTime - *prevTime;  // time elapsed since previous frame

    if (stick->velocity[0] == 0.f && stick->velocity[1] == 0.f && stick->velocity[2] == 0.f)
    {
        calculateStickPosition(stick, *ball, mousePosition);
        calculateStickAngle(stick, *ball, mousePosition);
    }
    else
    {
        stick->position[0] = ball->ball_pos[0];
        stick->position[2] += stick->velocity[2] * timeSincePrevFrame;
        stick->velocity[2] += acceleration * timeSincePrevFrame;
        if (stick->position[2] <= ball->ball_radius)
        {
            CueCollisionResolve(stick, ball);
        }
    }
}

void drawStick(StickData* stick, BallData ball)
{
    glPushMatrix();
    float defaultAngle = 90.0f;
    glTranslatef(ball.ball_pos[0], ball.ball_pos[1], ball.ball_pos[2]);
    glRotatef(stick->defaultAngle - stick->angle, 0, 1, 0);
    glColor3f(stick->color[0], stick->color[1], stick->color[2]);
    glTranslatef(0.0f, 0.0f, stick->position[2]);
    glutSolidCylinder(stick->radius, stick->height, 50, 50);
    glPopMatrix();
}
