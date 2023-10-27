#include "Physics.h"

void BallCollisionResolve(BallData* ballOne, BallData* ballTwo)
{
    //printf("Ball Collision:\nBefore:\n BallOne velocity: %f, %f\n BallTwo velocity: %f, %f\n", ballOne->ball_vel[0], ballOne->ball_vel[2], ballTwo->ball_vel[0], ballTwo->ball_vel[2]);

    float distance = sqrt((ballOne->ball_pos[0] - ballTwo->ball_pos[0]) * (ballOne->ball_pos[0] - ballTwo->ball_pos[0]) + (ballOne->ball_pos[2] - ballTwo->ball_pos[2]) * (ballOne->ball_pos[2] - ballTwo->ball_pos[2]));

    //printf("distance = sqrt((%f - %f)^2 + (%f - %f)^2) = %f\n", ballOne->ball_pos[0], ballTwo->ball_pos[0], ballOne->ball_pos[2], ballTwo->ball_pos[2], distance);

    //printf("distance = %f\n", distance);

    if (distance != ballOne->ball_radius + ballTwo->ball_radius)
    {
        Vector3 distVect;

        distVect[0] = ballOne->ball_pos[0] - ballTwo->ball_pos[0];
        distVect[1] = ballOne->ball_pos[1] - ballTwo->ball_pos[1];
        distVect[2] = ballOne->ball_pos[2] - ballTwo->ball_pos[2];

        //printf("distVect = %f, %f, %f\n", distVect[0], distVect[1], distVect[2]);

        float currMag = sqrt( pow(distVect[0], 2) + pow(distVect[1], 2) + pow(distVect[2], 2) );
        float targetMag = ballOne->ball_radius + ballTwo->ball_radius;

        float magScalar = targetMag/currMag;

        Vector3 newDistVect;

        newDistVect[0] = distVect[0] * magScalar;
        newDistVect[2] = distVect[2] * magScalar;

        ballOne->ball_pos[0] = ballTwo->ball_pos[0];
        ballOne->ball_pos[2] = ballTwo->ball_pos[2];

        ballOne->ball_pos[0] += newDistVect[0];
        ballOne->ball_pos[2] += newDistVect[2];

        distance = sqrt((ballOne->ball_pos[0] - ballTwo->ball_pos[0]) * (ballOne->ball_pos[0] - ballTwo->ball_pos[0]) + (ballOne->ball_pos[2] - ballTwo->ball_pos[2]) * (ballOne->ball_pos[2] - ballTwo->ball_pos[2]));

        //printf("new distance = %f\n", distance);
    }

    if (ballOne->ball_vel[0] == 0.f && ballOne->ball_vel[2] == 0.f && ballTwo->ball_vel[0] == 0.f && ballTwo->ball_vel[2] == 0.f)
    {
        return;
    }

    Vector3 n;
    Vector3 t;

    n[0] = 0.f;
    n[1] = 0.f;
    n[2] = 0.f;
    t[0] = 0.f;
    t[1] = 0.f;
    t[2] = 0.f;

    float m1 = 0.f;
    float m2 = 0.f;
    float ballOneT = 0.f;
    float ballTwoT = 0.f;
    float ballOneN = 0.f;
    float ballTwoN = 0.f;

    //normal vector
    n[0] = (ballTwo->ball_pos[0] - ballOne->ball_pos[0]) / distance;
    n[2] = (ballTwo->ball_pos[2] - ballOne->ball_pos[2]) / distance;

    //tangent vector
    t[0] = -(n[2]);
    t[2] = n[0];

    //printf("n: %f, %f, %f\n", n[0], n[1], n[2]);
    //printf("t: %f, %f, %f\n", t[0], t[1], t[2]);

    //dot product with tangental vector. Gets the scalar representing velocity towards the tangent
    ballOneT = (ballOne->ball_vel[0] * t[0]) + (ballOne->ball_vel[2] * t[2]);
    ballTwoT = (ballTwo->ball_vel[0] * t[0]) + (ballTwo->ball_vel[2] * t[2]);

    //printf("ballT: %f, %f\n", ballOneT, ballTwoT);

    //dot product with normal vector
    ballOneN = (ballOne->ball_vel[0] * n[0]) + (ballOne->ball_vel[2] * n[2]);
    ballTwoN = (ballTwo->ball_vel[0] * n[0]) + (ballTwo->ball_vel[2] * n[2]);

    //printf("ball 1 vel: %f, %f\nball 2 vel: %f, %f\nballN: %f, %f\n",ballOne->ball_vel[0], ballOne->ball_vel[2], ballTwo->ball_vel[0], ballTwo->ball_vel[2], ballOneN, ballTwoN);

    //Censervation of momentum formula. Gets the scalar representing velocity towards the normal vector
    m1 = (ballOneN * (ballOne->ball_mass - ballTwo->ball_mass) + 2.0f * ballTwo->ball_mass * ballTwoN) / (ballOne->ball_mass + ballTwo->ball_mass);
    m2 = (ballTwoN * (ballTwo->ball_mass - ballOne->ball_mass) + 2.0f * ballOne->ball_mass * ballOneN) / (ballOne->ball_mass + ballTwo->ball_mass);

    //printf("m1, m2: %f, %f\n", m1, m2);

    //multiply the scalar with normal vector and add it to the tangental vector multiplied by the tangental dot product
    ballOne->ball_vel[0] = t[0] * ballOneT + n[0] * m1;      //velocity in x direction
    ballOne->ball_vel[2] = t[2] * ballOneT + n[2] * m1;      //velocity in z direction

    //printf("ball1vel: %f, %f\n", ballOne->ball_vel[0], ballOne->ball_vel[2]);

    ballTwo->ball_vel[0] = t[0] * ballTwoT + n[0] * m2;
    ballTwo->ball_vel[2] = t[2] * ballTwoT + n[2] * m2;

    //printf("ball2vel: %f, %f\n", ballTwo->ball_vel[0], ballTwo->ball_vel[2]);

    ballOne->ball_vel[0] = ballOne->ball_vel[0] * 0.99;
    ballOne->ball_vel[2] = ballOne->ball_vel[2] * 0.99;

    ballTwo->ball_vel[0] = ballTwo->ball_vel[0] * 0.99;
    ballTwo->ball_vel[2] = ballTwo->ball_vel[2] * 0.99;

    //printf("After\n BallOne velocity: %f, %f\n BallTwo velocity: %f, %f\n\n", ballOne->ball_vel[0], ballOne->ball_vel[2], ballTwo->ball_vel[0], ballTwo->ball_vel[2]);

    //printf("ball1vel: %f, %f\n", ballOne->ball_vel[0], ballOne->ball_vel[2]);
    //printf("ball2vel: %f, %f\n", ballTwo->ball_vel[0], ballTwo->ball_vel[2]);

    return;
}

void WallCollisionResolve(BallData* ball)
{
    //top and bottom wall
    if (ball->ball_pos[2] >= 4 || ball->ball_pos[2] <= -4)
    {
        ball->ball_vel[0] = ball->ball_vel[0] * 0.9;
        ball->ball_vel[2] = (ball->ball_vel[2] * -1.f) * 0.9;
    }
    //side walls
    if (ball->ball_pos[0] >= 8 || ball->ball_pos[0] <= -8)
    {
        ball->ball_vel[2] = ball->ball_vel[2] * 0.9;
        ball->ball_vel[0] = (ball->ball_vel[0] * -1.f) * 0.9;
    }

    return;
}

void rotateVector(Vector3 vector, float angle, Vector3 axis, Vector3 result) {
    float radians = angle * M_PI / 180.0;
    float cosTheta = cos(radians);
    float sinTheta = sin(radians);

    result[0] = (cosTheta + (1 - cosTheta) * axis[0] * axis[0]) * vector[0] +
                ((1 - cosTheta) * axis[0] * axis[1] - axis[2] * sinTheta) * vector[1] +
                ((1 - cosTheta) * axis[0] * axis[2] + axis[1] * sinTheta) * vector[2];

    result[1] = ((1 - cosTheta) * axis[0] * axis[1] + axis[2] * sinTheta) * vector[0] +
                (cosTheta + (1 - cosTheta) * axis[1] * axis[1]) * vector[1] +
                ((1 - cosTheta) * axis[1] * axis[2] - axis[0] * sinTheta) * vector[2];

    result[2] = ((1 - cosTheta) * axis[0] * axis[2] - axis[1] * sinTheta) * vector[0] +
                ((1 - cosTheta) * axis[1] * axis[2] + axis[0] * sinTheta) * vector[1] +
                (cosTheta + (1 - cosTheta) * axis[2] * axis[2]) * vector[2];
}

void CueCollisionResolve(StickData* cue, BallData* cueBall)
{
    // Define stick's initial direction vector
    Vector3 stickDirection = {0.0, 0.0, -1.0};

    // Define rotation angle and axis
    float rotationAngle = cue->defaultAngle - cue->angle;
    Vector3 rotationAxis = {0.0, 1.0, 0.0};

    // Define the rotated direction vector
    Vector3 rotatedDirection;

    // Apply rotation to stick's direction vector
    rotateVector(stickDirection, rotationAngle, rotationAxis, rotatedDirection);

    // Calculate and print the velocity (magnitude of the rotated direction vector)
    float magnitude = sqrt(rotatedDirection[0] * rotatedDirection[0] + rotatedDirection[1] * rotatedDirection[1] +
                          rotatedDirection[2] * rotatedDirection[2]);

    float velocity = magnitude * sqrt(cue->velocity[0] * cue->velocity[0] +
                                 cue->velocity[1] * cue->velocity[1] +
                                 cue->velocity[2] * cue->velocity[2]);

    // Assign the new velocity to the ball's velocity vector
    cueBall->ball_vel[0] = velocity * rotatedDirection[0];
    cueBall->ball_vel[1] = 0.f;
    cueBall->ball_vel[2] = velocity * rotatedDirection[2];

    cue->position[2] = cueBall->ball_radius;

    cue->velocity[0] = 0.f;
    cue->velocity[1] = 0.f;
    cue->velocity[2] = 0.f;

    return;

}

void PocketCollisionResolve(BallData* ball)
{
    ball->ball_pos[1] = -10;

    ball->ball_vel[0] = 0.f;
    ball->ball_vel[1] = 0.f;
    ball->ball_vel[2] = 0.f;

    return;
}
