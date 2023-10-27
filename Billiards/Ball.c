//Ball.h - Implementation file

#include "Ball.h"

void InitialiseBalls(BallData balls[], int size, Point3 positions[], char textures[][20], float mass[], Vector3 forces[], int numberOfForces)
{
    for(int i=0; i<size; i++)
    {

        //Mass
		balls[i].ball_mass = mass[i];

		//Position
		balls[i].ball_pos[0] = positions[i][0];
        balls[i].ball_pos[1] = positions[i][1];
        balls[i].ball_pos[2] = positions[i][2];

        //Color
		strcpy(balls[i].ball_texture, textures[i]);

        //Force
        balls[i].ball_force[0] = forces[0][0];
        balls[i].ball_force[1] = forces[0][1];
        balls[i].ball_force[2] = forces[0][2];

		//Velocity
		balls[i].ball_vel[0] = 0.0f;
		balls[i].ball_vel[1] = 0.0f;
		balls[i].ball_vel[2] = 0.0f;

		//Rotation Angle
		balls[i].rotationAngleX = 0.0f;
		balls[i].rotationAngleZ = 0.0f;

		balls[i].isMoving = 0;
    }
    return;
}

void PositionUpdate(BallData balls[], float *prevTime, int size, Vector3 forces[], int numberOfForces, float frictionValue)
{
    // 1. Get the elapsed time in seconds
    float currTime = glutGet(GLUT_ELAPSED_TIME) / 1000.f; //Returns time in milliseconds so /1000 is needed to get seconds
    float timeSincePrevFrame = currTime - *prevTime;  // time elapsed since previous frame
    Vector3 friction = {0.0f, 0.0f, 0.0f};

    if(!(timeSincePrevFrame > 0.2f))
    {

        for(int i=0; i<size; i++)
        {
            for(int i1 = i+1; i1<size; i1++)
            {
                if (i == i1)
                {
                    continue;
                }

                if(BallCollision(balls[i], balls[i1]))
                {
                    BallCollisionResolve(&balls[i], &balls[i1]);
                }
            }

            if(BalltoWallCheck(&balls[i]))
            {
                WallCollisionResolve(&balls[i]);
            }
        }

        for(int i=0; i<size; i++)
        {
            balls[i].ball_pos[0] += balls[i].ball_vel[0] * timeSincePrevFrame;
            balls[i].ball_pos[2] += balls[i].ball_vel[2] * timeSincePrevFrame;

            //Calculate balls friction
            calculateFriction(balls[i], &friction, frictionValue);

            //Calculate balls accelaration (F/M)
            for(int i1=0; i1<3; i1++)
            {
                balls[i].ball_acc[i1] = friction[i1]/balls[i].ball_mass;
            }


            //Update balls velocity
            balls[i].ball_vel[0] += balls[i].ball_acc[0] * timeSincePrevFrame;
            balls[i].ball_vel[2] += balls[i].ball_acc[2] * timeSincePrevFrame;


            if (abs(balls[i].ball_vel[0]) < 0.01 && abs(balls[i].ball_vel[2]) < 0.01)
            {
                balls[i].ball_vel[0] = 0.f;
                balls[i].ball_vel[2] = 0.f;
            }

            //Check if ball is moving
            if(balls[i].ball_vel[0] == 0 && balls[i].ball_vel[2] == 0)
            {
                balls[i].isMoving = 0;
            }
            else
            {
                balls[i].isMoving = 1;
            }

            //Update rotation angle of ball
            calculateRotationAngles(&balls[i], timeSincePrevFrame);

        }

    }

    *prevTime = currTime;

    return;
}

void calculateRotationAngles(BallData* ball, float timeSincePrev)
{
        /* Update Rotation Angle for z-axis
        * sqrt of horizontal components of objects linear velocity gives you the horizontal velocity
        * angularVelocity = angular velocity (horizontal velocity/radius)
        * Angular velocity represents how fast the object is rotating around its axis
        */

        float angularVelocityZ = 0.0f;
        if (ball->ball_vel[0] < 0)
        {
            angularVelocityZ = (sqrt(ball->ball_vel[0] * ball->ball_vel[0])) / ball->ball_radius;
        }
        else if (ball->ball_vel[0] > 0)
        {
            angularVelocityZ = -(sqrt(ball->ball_vel[0] * ball->ball_vel[0])) / ball->ball_radius;
        }
        float angleZ = angularVelocityZ * timeSincePrev;
        ball->rotationAngleZ += angleZ * 180.0f/M_PI; //Convert to degrees

        /* Update Rotation Angle for x-axis
        * sqrt of horizontal components of objects linear velocity gives you the horizontal velocity
        * angularVelocity = angular velocity (horizontal velocity/radius)
        * Angular velocity represents how fast the object is rotating around its axis
        */

        float angularVelocityX = 0.0f;
        if (ball->ball_vel[2] < 0)
        {
            angularVelocityX = -(sqrt(ball->ball_vel[2] * ball->ball_vel[2])) / ball->ball_radius;
        }
        else if (ball->ball_vel[2] > 0)
        {
            angularVelocityX = (sqrt(ball->ball_vel[2] * ball->ball_vel[2])) / ball->ball_radius;
        }
        float angleX = angularVelocityX * timeSincePrev;
        ball->rotationAngleX += angleX * 180.0f/M_PI; //Convert to degrees

        return;
}

void calculateFriction(BallData ball, Vector3 *fric, float frictionValue)
{
    // Calculate velocity magnitude
    float velocity_mag = sqrt(ball.ball_vel[0] * ball.ball_vel[0] + ball.ball_vel[1] * ball.ball_vel[1] + ball.ball_vel[2] * ball.ball_vel[2]);

    // Calculate friction force magnitude
    float friction_mag = frictionValue * velocity_mag;

    // Calculate normalized friction force direction
    if(velocity_mag < 0.01) {
        (*fric)[0] = 0.0f;
        (*fric)[1] = 0.0f;
        (*fric)[2] = 0.0f;
    }else{
        float inv_velocity_mag = 1.0f / velocity_mag;
        (*fric)[0] = -ball.ball_vel[0] * inv_velocity_mag * friction_mag;
        (*fric)[1] = 0.0f;
        (*fric)[2] = -ball.ball_vel[2] * inv_velocity_mag * friction_mag;
    }

    return;
}

void DrawBall(BallData ball, int Index)
{
    glPushMatrix();
    glTranslatef(ball.ball_pos[0], ball.ball_pos[1], ball.ball_pos[2]);
    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();
    glRotatef(-ball.rotationAngleX, 1, 0, 0);
    glRotatef(-ball.rotationAngleZ, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    DrawTexturedSphere(Index, ball.ball_radius, 16, 16);
    glPopMatrix();
    return;
}

int BallCollision(BallData ball_1, BallData ball_2)
{
    int valid;
    float distance = sqrt(((ball_1.ball_pos[0] - ball_2.ball_pos[0]) * (ball_1.ball_pos[0] - ball_2.ball_pos[0])) +
                          ((ball_1.ball_pos[1] - ball_2.ball_pos[1]) * (ball_1.ball_pos[1] - ball_2.ball_pos[1])) +
                          ((ball_1.ball_pos[2] - ball_2.ball_pos[2]) * (ball_1.ball_pos[2] - ball_2.ball_pos[2])));
    float length = ball_1.ball_radius + ball_2.ball_radius;

    if(distance <= length)
    {
        valid = 1;
    }
    else
    {
        valid = 0;
    }

    return valid;
}
