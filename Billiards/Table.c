#include "Table.h"
#define WALL_HEIGHT 0.2

//create a point at each pocket
                   //x = 0, y = 1, z = 2


    Point3 PocketPos[6] = {{-8.6,0.1,-4.2}, //TopLeft    //0
                            {0,0.1,-4.9},    //TopMiddle  //1
                            {8.6,0.1,-4.2},  //TopRight   //2
                            {-8.6,0.1,4.2},  //BotLeft    //3
                            {0,0.1,4.9},     //BotMiddle  //4
                            {8.6,0.1,4.2}};  //BotRight   //5

    /*Right Wall*/
    Point3 RightWall[8] = {{8.8,WALL_HEIGHT,3.6},//0
                        {8.8,WALL_HEIGHT,-3.6},//1
                        {8.8,0,-3.6},//2
                        {8.8,0,3.6},//3
                        {9.8,WALL_HEIGHT,4.9},//4
                        {9.8,WALL_HEIGHT,-4.9},//5
                        {9.8,0,-4.9},//6
                        {9.8,0,4.9}};//7
    /*Left Wall*/
    Point3 LeftWall[8] = {{-8.8,WALL_HEIGHT,3.6},//0
                        {-8.8,WALL_HEIGHT,-3.6},//1
                        {-8.8,0,-3.6},//2
                        {-8.8,0,3.6},//3
                        {-9.8,WALL_HEIGHT,4.9},//4
                        {-9.8,WALL_HEIGHT,-4.9},//5
                        {-9.8,0,-4.9},//6
                        {-9.8,0,4.9}};//7
    /*-Z Wall*/
    Point3 NegZWall[8]={
                        {-9.2,WALL_HEIGHT,-5.4},//0
                        {9.2,WALL_HEIGHT,-5.4},//1
                        {9.2,0,-5.4},//2
                        {-9.2,0,-5.4},//3
                        {-0.25,WALL_HEIGHT,-5.4},//4
                        {0.25,WALL_HEIGHT,-5.4},//5
                        {-0.25,0,-5.4},//6
                        {0.25,0,-5.4}};//7

    Point3 NegZLeftPlayWall[4] = {{-7.9,WALL_HEIGHT,-4.4}, //0
                                  {-0.7,WALL_HEIGHT,-4.4}, //1
                                  {-0.7,0,-4.4}, //2
                                  {-7.9,0,-4.4}}; //3

    Point3 NegZRightPlayWall[4] = {{0.7,WALL_HEIGHT,-4.4},//0
                                   {7.9,WALL_HEIGHT,-4.4},//1
                                   {7.9,0,-4.4},//2
                                   {0.7,0,-4.4}};//3

    /*+Z Wall*/
    Point3 ZWall[8]={
                        {-9.2,WALL_HEIGHT,5.4},//4
                        {9.2,WALL_HEIGHT,5.4},//5
                        {9.2,0,5.4},//6
                        {-9.2,0,5.4},//7
                        {-0.25,WALL_HEIGHT,5.4},//12
                        {0.25,WALL_HEIGHT,5.4},//13
                        {0.25,0,5.4},//14
                        {-0.25,0,5.4}};//15

    Point3 ZLeftPlayWall[4] = {{-7.9,WALL_HEIGHT,4.4},
                               {-0.7,WALL_HEIGHT,4.4},
                               {-0.7,0,4.4},
                               {-7.9,0,4.4}};

    Point3 ZRightPlayWall[4] = {{0.7,WALL_HEIGHT,4.4},
                                {7.9,WALL_HEIGHT,4.4},
                                {7.9,0,4.4},
                                {0.7,0,4.4}};

    Point3 BaseTable[4]={{-9.8,0,-5.4},
                        {9.8,0,-5.4},
                        {9.8,0,5.4},
                        {-9.8,0,5.4}};

    /*Collision Detection Points for the pocket sides*/
    /*Point3 TopLeftLeft[4] = {{-8.8,0.4,-3.6},{-9.8,0.4,-4.9},{-9.8,0,-4.9},{-8.8,0,-3.6}};
    Point3 TopLeftRight[4] = {{-9.2,0.4,-5.4},{-7.9,0.4,-4.4},{-7.9,0,-4.4},{-9.2,0,-5.4}};

    Point3 TopMiddleLeft[4] = {{-0.7,0.4,-4.4},{-0.25,0.4,-5.4},{-0.25,0,-5.4},{9.2,0,-5.4}};
    Point3 TopMiddleRight[4] = {{0.7,0.4,-4.4},{0.25,0.4,-5.4},{0.25,0,-5.4},{0.7,0,-4.4}};

    Point3 TopRightLeft[4] = {{7.9,0.4,-4.4},{9.2,0.4,-5.4},{9.2,0,-5.4},{7.9,0,-4.4}};
    Point3 TopRightRight[4] = {{8.8,0.4,-3.6},{9.8,0.4,-4.9},{9.8,0,-4.9}, {8.8,0,-3.6}};

    Point3 BotRightRight[4] = {{9.8,0.4,4.9},{8.8,0.4,3.6},{9.8,0,4.9},{8.8,0,3.6}};
    Point3 BotRightLeft[4] = {{0.7,0.4,4.4},{9.2,0.4,5.4},{9.2,0,5.4},{7.9,0,4.4}};

    Point3 BotMiddleRight[4] = {{0.25,0.4,5.4},{0.7,0.4,4.4},{0.7,0,4.4},{0.25,0,5.4}};
    Point3 BotMiddleLeft[4] = {{-0.25,0.4,5.4},{-0.7,0.4,4.4},{-0.7,0,4.4},{-0.25,0,5.4}};

    Point3 BotLeftRight[4] = {{-9.2,0.4,5.4},{-7.9,0.4,4.4},{-7.9,0,4.4},{-9.2,0,5.4}};
    Point3 BotLeftLeft[4] = {{-9.8,0.4,4.9},{-8.8,0.4,3.6},{-8.8,0,3.6},{-9.8,0,4.9}};*/


void drawTable(){

    //Base
    glBegin(GL_POLYGON);
        glColor3f(0.4f, 0.9f, 0.2f);     //table base is green
        glVertex3fv(BaseTable[0]);
        glVertex3fv(BaseTable[1]);
        glVertex3fv(BaseTable[2]);
        glVertex3fv(BaseTable[3]);
    glEnd();
    //Base

    //Walls

    /*Right Wall*/
    //Table Facing Wall
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(RightWall[0]);
        glVertex3fv(RightWall[1]);
        glVertex3fv(RightWall[2]);
        glVertex3fv(RightWall[3]);
    glEnd();

    //Top Wall
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(RightWall[4]);
        glVertex3fv(RightWall[5]);
        glVertex3fv(RightWall[1]);
        glVertex3fv(RightWall[0]);
    glEnd();

    //-Z Pocket Facing
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(RightWall[4]);
        glVertex3fv(RightWall[0]);
        glVertex3fv(RightWall[3]);
        glVertex3fv(RightWall[7]);
    glEnd();

    //Z Pocket Facing
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(RightWall[1]);
        glVertex3fv(RightWall[5]);
        glVertex3fv(RightWall[6]);
        glVertex3fv(RightWall[2]);
    glEnd();


    /*Left Wall*/
    //table facing
     glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(LeftWall[0]);
        glVertex3fv(LeftWall[1]);
        glVertex3fv(LeftWall[2]);
        glVertex3fv(LeftWall[3]);
    glEnd();

    //top
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(LeftWall[4]);
        glVertex3fv(LeftWall[5]);
        glVertex3fv(LeftWall[1]);
        glVertex3fv(LeftWall[0]);
    glEnd();
    //bottom pocket facing
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(LeftWall[4]);
        glVertex3fv(LeftWall[0]);
        glVertex3fv(LeftWall[3]);
        glVertex3fv(LeftWall[7]);
    glEnd();
    //top pocket facing
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(LeftWall[1]);
        glVertex3fv(LeftWall[5]);
        glVertex3fv(LeftWall[6]);
        glVertex3fv(LeftWall[2]);
    glEnd();

    /*-Z Wall*/

    //table facing wall Left
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(NegZLeftPlayWall[0]);
        glVertex3fv(NegZLeftPlayWall[1]);
        glVertex3fv(NegZLeftPlayWall[2]);
        glVertex3fv(NegZLeftPlayWall[3]);
    glEnd();

    //table facing wall right
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(NegZRightPlayWall[0]);
        glVertex3fv(NegZRightPlayWall[1]);
        glVertex3fv(NegZRightPlayWall[2]);
        glVertex3fv(NegZRightPlayWall[3]);
    glEnd();


    //Top wall left
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(NegZWall[0]);
        glVertex3fv(NegZWall[4]);
        glVertex3fv(NegZLeftPlayWall[1]);
        glVertex3fv(NegZLeftPlayWall[0]);
    glEnd();

    //Top Wall right
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(NegZWall[5]);
        glVertex3fv(NegZWall[1]);
        glVertex3fv(NegZRightPlayWall[1]);
        glVertex3fv(NegZRightPlayWall[0]);
    glEnd();

    //right pocket facing
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(NegZRightPlayWall[1]);
        glVertex3fv(NegZWall[1]);
        glVertex3fv(NegZWall[2]);
        glVertex3fv(NegZRightPlayWall[2]);
    glEnd();

    //inside left pocket facing
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(NegZLeftPlayWall[1]);
        glVertex3fv(NegZWall[4]);
        glVertex3fv(NegZWall[6]);
        glVertex3fv(NegZLeftPlayWall[2]);
    glEnd();

    //left pocket facing
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(NegZWall[0]);
        glVertex3fv(NegZLeftPlayWall[0]);
        glVertex3fv(NegZLeftPlayWall[3]);
        glVertex3fv(NegZWall[3]);
    glEnd();
    //inside right pocket facing
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(NegZRightPlayWall[0]);
        glVertex3fv(NegZWall[5]);
        glVertex3fv(NegZWall[7]);
        glVertex3fv(NegZRightPlayWall[3]);
    glEnd();


    /*+Z Wall*/

    //table facing wall left
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(ZLeftPlayWall[0]);
        glVertex3fv(ZLeftPlayWall[1]);
        glVertex3fv(ZLeftPlayWall[2]);
        glVertex3fv(ZLeftPlayWall[3]);
    glEnd();

    //table facing wall right
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(ZRightPlayWall[0]);
        glVertex3fv(ZRightPlayWall[1]);
        glVertex3fv(ZRightPlayWall[2]);
        glVertex3fv(ZRightPlayWall[3]);
    glEnd();

    //top wall left
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(ZLeftPlayWall[0]);
        glVertex3fv(ZLeftPlayWall[1]);
        glVertex3fv(ZWall[4]);
        glVertex3fv(ZWall[0]);
    glEnd();

    //top wall right
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(ZRightPlayWall[0]);
        glVertex3fv(ZRightPlayWall[1]);
        glVertex3fv(ZWall[1]);
        glVertex3fv(ZWall[5]);
    glEnd();

    //right pocket facing
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(ZRightPlayWall[1]);
        glVertex3fv(ZWall[1]);
        glVertex3fv(ZWall[2]);
        glVertex3fv(ZRightPlayWall[2]);
    glEnd();

    //inside right pocket facing
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(ZWall[5]);
        glVertex3fv(ZRightPlayWall[0]);
        glVertex3fv(ZRightPlayWall[3]);
        glVertex3fv(ZWall[6]);
    glEnd();

    //left pocket facing
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(ZWall[0]);
        glVertex3fv(ZLeftPlayWall[0]);
        glVertex3fv(ZLeftPlayWall[3]);
        glVertex3fv(ZWall[3]);
    glEnd();

    //inside left pocket facing
   glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(ZWall[4]);
        glVertex3fv(ZLeftPlayWall[1]);
        glVertex3fv(ZLeftPlayWall[2]);
        glVertex3fv(ZWall[7]);
    glEnd();

    tableDetails();

    /*Pockets*/
    //top middle
    glPushMatrix();
    glTranslatef(0,0.01,-4.9);
    glRotatef(90,1,0,0);

    glColor3f(-2,-2,-2);
    glutSolidCylinder(0.5,2,20,20);


    //top left
    glTranslatef(-8.8,0.45,0);
    glutSolidCylinder(0.5,2,20,20);

    //Top right
    glTranslatef(17.6,0,0);
    glutSolidCylinder(0.5,2,20,20);

    //bottom middle
    glPopMatrix();
    glTranslatef(0,0.01,4.9);
    glRotatef(90,1,0,0);

    glColor3f(-5,-5,-5);
    glutSolidCylinder(0.5,2,20,20);

    //bottom left
    glTranslatef(-8.8,-0.45,0);
    glutSolidCylinder(0.5,2,20,20);

    //bottom right
    glTranslatef(17.6,0,0);
    glutSolidCylinder(0.5,2,20,20);

    glPopMatrix();

}

int BalltoPocketCheck(BallData ball){

    //get the distance between the 3D point of the ball and each Pocket
        for (int i = 0; i<6; i++){


                if (sqrt((PocketPos[i][0] - ball.ball_pos[0])*(PocketPos[i][0] - ball.ball_pos[0]) + (PocketPos[i][1] - ball.ball_pos[1])*(PocketPos[i][1] - ball.ball_pos[1]) + (PocketPos[i][2] - ball.ball_pos[2])*(PocketPos[i][2] - ball.ball_pos[2])) <= 0.75)
                {
                    return 1;
                }

        }
        return 0;


}

int BalltoWallCheck(BallData *Ball){


    if (WallCollisionCalculation(LeftWall, Ball) == 1){
        return 1;
    }
    if (WallCollisionCalculation(RightWall, Ball) == 1){
        return 1;
    }
    if (WallCollisionCalculation(NegZLeftPlayWall, Ball) == 1){
        return 1;
    }
    if (WallCollisionCalculation(NegZRightPlayWall, Ball) == 1){
        return 1;
    }
    if (WallCollisionCalculation(ZLeftPlayWall, Ball) == 1){
        return 1;
    }
    if (WallCollisionCalculation(ZRightPlayWall, Ball) == 1){
        return 1;
    }
    return 0;

}


int WallCollisionCalculation (Point3 plane[], BallData *ball)
{
    //Collision Detection
    //= {x2-x1,y2-y1,z2-z1}
    Point3 v1 = {plane[1][0] - plane[0][0], plane[1][1] - plane[0][1], plane[1][2] - plane[0][2]};
            //= {x3-x1,y3-y1,z3-z1}
    Point3 v2 = {plane[2][0] - plane[0][0], plane[2][1] - plane[0][1], plane[2][2] - plane[0][2]};
      //calculate the normal vector
    Point3 normal = {v1[1] * v2[2] - v1[2] * v2[1], v1[2] * v2[0] - v1[0] * v2[2], v1[0] * v2[1] - v1[1] * v2[0]};
    //Point3 normal = {plane[0][1] * plane[1][2] -plane[0][2] *plane[1][1], plane[0][2] * plane[1][0] - plane[0][0] * plane[1][2], plane[0][0] * plane[1][1] - plane[0][1] * plane[1][0]};

      //Find the magnitude of the vector
    GLfloat mag = sqrt(normal[0]*normal[0] + normal[1]*normal[1] + normal[2]*normal[2]);
    normal[0] /= mag;
    normal[1] /= mag;
    normal[2] /= mag;

    float distance = normal[0] * ball->ball_pos[0] + normal[1] * ball->ball_pos[1] + normal[2] * ball->ball_pos[2] - (normal[0] * plane[0][0] + normal[1] * plane[0][1] + normal[2] * plane[0][2]);
    distance = fabs(distance);

    //printf("ball pos: %f, %f    distance: %f\n", ball->ball_pos[0], ball->ball_pos[2], distance);

    if (distance <= ball->ball_radius)
    {
        float push = ball->ball_radius + 0.5f;
        //if pos <= plane max and pos > plane min (x and z)
        if (plane ==  RightWall || plane == LeftWall)
        {
            if (ball->ball_pos[2] <= plane[3][2] && ball->ball_pos[2] >= plane[2][2])
            {
                if (ball->ball_pos[0] > 0)
                {
                    ball->ball_pos[0] = plane[1][0] - ball->ball_radius;
                    //ball->ball_pos[0] -= push;
                }
                else
                {
                    ball->ball_pos[0] = plane[1][0] + ball->ball_radius;
                    //ball->ball_pos[0] += push;
                }

                return 1;
            }

        }
        else if (plane == ZLeftPlayWall || plane == ZRightPlayWall || plane == NegZLeftPlayWall || plane == NegZRightPlayWall)
        {
            if (ball->ball_pos[0] >= plane[3][0] && ball->ball_pos[0] <= plane[2][0])
            {
                if (ball->ball_pos[2] > 0)
                {
                    ball->ball_pos[2] = plane[1][2] - ball->ball_radius;
                    //ball->ball_pos[2] -= push;
                }
                else
                {
                    ball->ball_pos[2] = plane[1][2] + ball->ball_radius;
                    //ball->ball_pos[2] += push;
                }
                return 1;
            }

        }
    }

    return 0;
}

void tableDetails(){

    Point3 TopRightPocketCorner[9] = {{8,WALL_HEIGHT,-4.8},//0
                                      {9.2,WALL_HEIGHT,-4.8},//1
                                      {9.2,WALL_HEIGHT,-4},//2
                                      {9.2,0,-4},//3
                                      {9.2,0,-4.8},//4
                                      {8,0,-4.8},//5

                                      {9,WALL_HEIGHT,-5.4},//6
                                      {9.8,WALL_HEIGHT,-5.4},//7
                                      {9.8,WALL_HEIGHT,-4.9}};//8


   glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(TopRightPocketCorner[0]);
        glVertex3fv(TopRightPocketCorner[1]);
        glVertex3fv(TopRightPocketCorner[4]);
        glVertex3fv(TopRightPocketCorner[5]);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(TopRightPocketCorner[1]);
        glVertex3fv(TopRightPocketCorner[2]);
        glVertex3fv(TopRightPocketCorner[3]);
        glVertex3fv(TopRightPocketCorner[4]);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(TopRightPocketCorner[6]);
        glVertex3fv(TopRightPocketCorner[7]);
        glVertex3fv(TopRightPocketCorner[1]);
        glVertex3fv(TopRightPocketCorner[0]);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(TopRightPocketCorner[7]);
        glVertex3fv(TopRightPocketCorner[8]);
        glVertex3fv(TopRightPocketCorner[2]);
        glVertex3fv(TopRightPocketCorner[1]);
    glEnd();

    Point3 BottomRightPocketCorner[9] = {{8.1,WALL_HEIGHT,4.7},//0
                                      {9.1,WALL_HEIGHT,4.7},//1
                                      {9.1,WALL_HEIGHT,3.7},//2
                                      {9.1,0,3.7},//3
                                      {9.1,0,4.7},//4
                                      {8.1,0,4.7},//5

                                      {8,WALL_HEIGHT,5.4},//6
                                      {9.8,WALL_HEIGHT,5.4},//7
                                      {9.8,WALL_HEIGHT,4.9}};//8


   glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(BottomRightPocketCorner[0]);
        glVertex3fv(BottomRightPocketCorner[1]);
        glVertex3fv(BottomRightPocketCorner[4]);
        glVertex3fv(BottomRightPocketCorner[5]);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(BottomRightPocketCorner[1]);
        glVertex3fv(BottomRightPocketCorner[2]);
        glVertex3fv(BottomRightPocketCorner[3]);
        glVertex3fv(BottomRightPocketCorner[4]);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(BottomRightPocketCorner[6]);
        glVertex3fv(BottomRightPocketCorner[7]);
        glVertex3fv(BottomRightPocketCorner[1]);
        glVertex3fv(BottomRightPocketCorner[0]);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(BottomRightPocketCorner[7]);
        glVertex3fv(BottomRightPocketCorner[8]);
        glVertex3fv(BottomRightPocketCorner[2]);
        glVertex3fv(BottomRightPocketCorner[1]);
    glEnd();

    Point3 TopLeftPocketCorner[9] = {{-8,WALL_HEIGHT,-4.8},//0
                                      {-9.2,WALL_HEIGHT,-4.8},//1
                                      {-9.2,WALL_HEIGHT,-4},//2
                                      {-9.2,0,-4},//3
                                      {-9.2,0,-4.8},//4
                                      {-8,0,-4.8},//5

                                      {-9,WALL_HEIGHT,-5.4},//6
                                      {-9.8,WALL_HEIGHT,-5.4},//7
                                      {-9.8,WALL_HEIGHT,-4.9}};//8


   glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(TopLeftPocketCorner[0]);
        glVertex3fv(TopLeftPocketCorner[1]);
        glVertex3fv(TopLeftPocketCorner[4]);
        glVertex3fv(TopLeftPocketCorner[5]);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(TopLeftPocketCorner[1]);
        glVertex3fv(TopLeftPocketCorner[2]);
        glVertex3fv(TopLeftPocketCorner[3]);
        glVertex3fv(TopLeftPocketCorner[4]);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(TopLeftPocketCorner[6]);
        glVertex3fv(TopLeftPocketCorner[7]);
        glVertex3fv(TopLeftPocketCorner[1]);
        glVertex3fv(TopLeftPocketCorner[0]);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(TopLeftPocketCorner[7]);
        glVertex3fv(TopLeftPocketCorner[8]);
        glVertex3fv(TopLeftPocketCorner[2]);
        glVertex3fv(TopLeftPocketCorner[1]);
    glEnd();

     Point3 BottomLeftPocketCorner[9] = {{-8.1,WALL_HEIGHT,4.7},//0
                                      {-9.1,WALL_HEIGHT,4.7},//1
                                      {-9.1,WALL_HEIGHT,3.7},//2
                                      {-9.1,0,3.7},//3
                                      {-9.1,0,4.7},//4
                                      {-8.1,0,4.7},//5

                                      {-8,WALL_HEIGHT,5.4},//6
                                      {-9.8,WALL_HEIGHT,5.4},//7
                                      {-9.8,WALL_HEIGHT,4.9}};//8


   glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(BottomLeftPocketCorner[0]);
        glVertex3fv(BottomLeftPocketCorner[1]);
        glVertex3fv(BottomLeftPocketCorner[4]);
        glVertex3fv(BottomLeftPocketCorner[5]);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(BottomLeftPocketCorner[1]);
        glVertex3fv(BottomLeftPocketCorner[2]);
        glVertex3fv(BottomLeftPocketCorner[3]);
        glVertex3fv(BottomLeftPocketCorner[4]);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(BottomLeftPocketCorner[6]);
        glVertex3fv(BottomLeftPocketCorner[7]);
        glVertex3fv(BottomLeftPocketCorner[1]);
        glVertex3fv(BottomLeftPocketCorner[0]);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(BottomLeftPocketCorner[2]);
        glVertex3fv(BottomLeftPocketCorner[1]);
        glVertex3fv(BottomLeftPocketCorner[7]);
        glVertex3fv(BottomLeftPocketCorner[8]);
    glEnd();

    Point3 TopMiddlePocketCover[6] = {{-0.4,WALL_HEIGHT,-5.1},//0
                                   {0.4,WALL_HEIGHT,-5.1},//1
                                   {0.4,0,-5.1},//2
                                   {-0.4,0,-5.1},//3
                                   {-0.4,WALL_HEIGHT,-5.4},//4
                                   {0.4,WALL_HEIGHT,-5.4}};//5
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(TopMiddlePocketCover[0]);
        glVertex3fv(TopMiddlePocketCover[1]);
        glVertex3fv(TopMiddlePocketCover[2]);
        glVertex3fv(TopMiddlePocketCover[3]);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(TopMiddlePocketCover[4]);
        glVertex3fv(TopMiddlePocketCover[5]);
        glVertex3fv(TopMiddlePocketCover[1]);
        glVertex3fv(TopMiddlePocketCover[0]);
    glEnd();

    Point3 BottomMiddlePocketCover[6] = {{-0.4,WALL_HEIGHT,5.1},//0
                                   {0.4,WALL_HEIGHT,5.1},//1
                                   {0.4,0,5.1},//2
                                   {-0.4,0,5.1},//3
                                   {-0.4,WALL_HEIGHT,5.4},//4
                                   {0.4,WALL_HEIGHT,5.4}};//5
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(BottomMiddlePocketCover[0]);
        glVertex3fv(BottomMiddlePocketCover[1]);
        glVertex3fv(BottomMiddlePocketCover[2]);
        glVertex3fv(BottomMiddlePocketCover[3]);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.8,0.3,0);
        glVertex3fv(BottomMiddlePocketCover[4]);
        glVertex3fv(BottomMiddlePocketCover[5]);
        glVertex3fv(BottomMiddlePocketCover[1]);
        glVertex3fv(BottomMiddlePocketCover[0]);
    glEnd();


}

