// to compile under Mac, use the following command
// gcc exo_3_3.c -framework GLUT -framework OpenGL -framework Cocoa -o exo_3_3

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
#include "Ball.h"
#include "Stick.h"
#include "Table.h"
#include "menu.h"
#include "stdio.h"

#define ballNum 16
#define TIMERSECS 10
#define OffCentre 4.65

int menuStart = 1;
int menuBalls = 0;
int menuFriction = 0;
int menuGameOver = 0;
int initBalls = 0;
int showStick = 1;
int score = 0;

float friction = 0.3;
const float smooth = 0.15;
const float normal = 0.3;
const float rough = 0.45;
float prevTime;
float mass[ballNum];

StickData stick;
BallData balls[ballNum];
char textures[ballNum][20];
Vector3 forces[2] = {0.0f, 0.0f, 0.0f};
Point3 positions[ballNum];
const char* imageData[15];

int texWidth[ballNum];
int texHeight[ballNum];

Point3 m_pos;

enum {
    ORTHO2D, PERSPECTIVE, FRUSTUM, ORTHO
} cameraMode = PERSPECTIVE;

Camera camera;

void triPosition(float radius)
{
    radius = radius + 0.01;

    Point3 pos[16] = {{-OffCentre, radius, 0},//0 (CUE)
                                    {OffCentre, radius, 0},//1
                                    {OffCentre + (2.f * radius), radius, radius},//2
                                    {OffCentre + (2.f * radius), radius, -radius},//3
                                    {OffCentre + (4.f * radius), radius, 2.f * radius},//4
                                    {OffCentre + (6.f * radius), radius, radius},//5
                                    {OffCentre + (4.f * radius), radius, -(2.f * radius)},//6
                                    {OffCentre + (6.f * radius), radius, 3.f * radius},//7
                                    {OffCentre + (4.f * radius), radius, 0},//8
                                    {OffCentre + (6.f * radius), radius, -radius},//9
                                    {OffCentre + (6.f * radius), radius, -(3.f * radius)},//10
                                    {OffCentre + (8.f * radius), radius, 4.f * radius},//11
                                    {OffCentre + (8.f * radius), radius, 2.f * radius},//12
                                    {OffCentre + (8.f * radius), radius, 0},//13
                                    {OffCentre + (8.f * radius), radius, -(2.f * radius)},//14
                                    {OffCentre + (8.f * radius), radius, -(4.f * radius)}};//15

    for(int i = 0; i < 16; i++)
    {
        positions[i][0] = pos[i][0];
        positions[i][1] = pos[i][1];
        positions[i][2] = pos[i][2];
    }
}

void recPosition(float radius)
{
    radius += 0.01;

    Point3 pos[16] = {{-OffCentre,radius,0},//0 (CUE)
                                    {OffCentre, radius, 4 * radius},//1
                                    {OffCentre, radius, 2 * radius},//2
                                    {OffCentre, radius, 0},//3
                                    {OffCentre, radius, -2 * radius},//4
                                    {OffCentre, radius, -4 * radius},//5
                                    {OffCentre + (2 * radius), radius, 4 * radius},//6
                                    {OffCentre + (2 * radius), radius, 2 * radius},//7
                                    {OffCentre + (2 * radius), radius, 0},//8
                                    {OffCentre + (2 * radius), radius, -2 * radius},//9
                                    {OffCentre + (2 * radius), radius, -4 * radius},//10
                                    {OffCentre + (4 * radius), radius, 4 * radius},//11
                                    {OffCentre + (4 * radius), radius, 2 * radius},//12
                                    {OffCentre + (4 * radius), radius, 0},//13
                                    {OffCentre + (4 * radius), radius, -2 * radius},//14
                                    {OffCentre + (4 * radius), radius, -4 * radius}};//15

    for(int i = 0; i < 16; i++)
    {
        positions[i][0] = pos[i][0];
        positions[i][1] = pos[i][1];
        positions[i][2] = pos[i][2];
    }
}

void scoreUpdate(int num)
{
    int valid = 1;

    if(num == 0)
    {
        if(score != 0)
        {
            score--;
        }
        printf("Cue Ball Pocketed!\n");
        return;
    }
    else if(num == 8)
    {
        for(int i=1; i<ballNum; i++)
        {
            if(i == 8)
            {
                continue;
            }
            if(balls[i].ball_pos[1] >= 0.0f)
            {
                valid = 0;
            }
        }
        if(valid == 0)
        {
            printf("8-Ball Pocketed Early!\n");
            menuGameOver = 1;
            score = 0;
        }
        else
        {
            menuGameOver = 1;
        }
    }
    else
    {
        score++;
    }
}

void setLight(void){

		// Define RGBA specular colours for object material
		GLfloat  mat_specular[]  =  {1.0, 1.0, 1.0, 1.0 };

		// How shiny material is
		GLfloat  mat_shininess[] =  {50.0};

		GLfloat  light_position[] =  {1.0, 1.0, 2.0, 0.0 };
		GLfloat  lmodel_ambient[] =  {0.2, 0.2, 0.2, 1.0};

		// Define position of light source
		glLightfv (GL_LIGHT0, GL_POSITION, light_position);

		// Define lighting model
		glLightModelfv (GL_LIGHT_MODEL_AMBIENT,  lmodel_ambient);

		// Define material properties
		glMaterialfv (GL_FRONT, GL_SPECULAR,   mat_specular);
		glMaterialfv (GL_FRONT, GL_SHININESS,  mat_shininess);

		glEnable(GL_COLOR_MATERIAL);

		//Enable lighting
		glEnable (GL_LIGHTING); // as in turn on power for
		//all lights
		glEnable (GL_LIGHT0); // as in flip on the light switch

		glEnable (GL_DEPTH_TEST);

}

void setCamera(int cameraMode){

     if (cameraMode == ORTHO2D){
        // 2D viwwing (no Z coordnates
        gluOrtho2D(0.0,1000.0, 0.0,1000.0);

    }if (cameraMode == ORTHO){
        // This is orthographic projection
        GLdouble left    = -2;
        GLdouble right   = 2;
        GLdouble bottom  = -1;
        GLdouble top     = 1;
        GLdouble nearVal = 0.1;
        GLdouble farVal  = 100;     // near and far clipping planes
        glOrtho(left,  right,
                bottom,  top,
                nearVal,  farVal);

    }else if (cameraMode == PERSPECTIVE){
        //
        GLdouble fov	 = 60;		// degrees
        GLdouble aspect	 = 1;		// aspect ratio aspect = height/width
        GLdouble nearVal = 0.1;
        GLdouble farVal  = 100;     // near and far clipping planes
        gluPerspective(fov, aspect, nearVal, farVal);

    }else if (cameraMode == FRUSTUM){
        GLdouble left = -1;
        GLdouble right= 1;
        GLdouble bottom = -1;
        GLdouble top    = 1;
        GLdouble nearVal = .05;
        GLdouble farVal  = 100;     // near and far clipping planes
        glFrustum(left,  right,
				  bottom,  top,
                  nearVal,  farVal);
    }
}


void init(void) {

    // Setting the lights
	setLight();

    // attributes
    glClearColor(0.0, 0.0, 0.0, 1.0); // draw on white background
    glColor3f(1.0, 0.0, 0.0);         // draw in red
    glLineWidth(1.0);                 // draw using lines 5 pixels wide

    // Setting the camera extrinsic parameter (position, lookat and up vector)
    camera.position[0] = 0.f;
    camera.position[1] = 17.f;
    camera.position[2] = 0.1f;

    camera.lookat[0] = 0.f;
    camera.lookat[1] = 0.f;
    camera.lookat[2] = 0.f;

    camera.up[0] = 0.f;
    camera.up[1] = 1.f;
    camera.up[2] = 0.f;

    // switch matrix mode to 'projection' and load an identity matrix as the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Let's test 3 different modes of viewing
    cameraMode = PERSPECTIVE;
    setCamera(cameraMode);

    for(int i = 0; i < ballNum; i++)
    {
        mass[i] = 0.3;
        balls[i].ball_radius = 0.2;
    }

    strcpy(textures[0], "Textures/0Ball.png");
    strcpy(textures[1], "Textures/1Ball.png");
    strcpy(textures[2], "Textures/2Ball.png");
    strcpy(textures[3], "Textures/3Ball.png");
    strcpy(textures[4], "Textures/4Ball.png");
    strcpy(textures[5], "Textures/5Ball.png");
    strcpy(textures[6], "Textures/6Ball.png");
    strcpy(textures[7], "Textures/7Ball.png");
    strcpy(textures[8], "Textures/8Ball.png");
    strcpy(textures[9], "Textures/9Ball.png");
    strcpy(textures[10], "Textures/10Ball.png");
    strcpy(textures[11], "Textures/11Ball.png");
    strcpy(textures[12], "Textures/12Ball.png");
    strcpy(textures[13], "Textures/13Ball.png");
    strcpy(textures[14], "Textures/14Ball.png");
    strcpy(textures[15], "Textures/15Ball.png");
}


void mydisplay( void ){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* switch matrix mode back to 'model view', i.e. in world coordinate syst */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();               // start with identity transformation

    // now setting the camera
	gluLookAt(camera.position[0], camera.position[1], camera.position[2], // eye location
              camera.lookat[0],   camera.lookat[1],   camera.lookat[2],   // looking at
              camera.up[0],       camera.up[1],       camera.up[2]        // up vector
             );

    showStick = 1;

    glPushMatrix();

    drawTable();

    glPopMatrix();
    glPushMatrix();
    if (menuStart)
    {
        glTranslatef(0, 8, 0);
        DrawMenuStart();
        printf("Draw menu start\n");
    }
    else if (menuBalls)
    {
        glTranslatef(0, 8, 0);
        DrawMenuBalls();
        printf("Draw menu balls\n");
    }
    else if (menuFriction)
    {
        glTranslatef(0, 8, 0);
        DrawMenuFriction();
        printf("Draw menu friction\n");
    }
    else if(menuGameOver)
    {
        glTranslatef(0, 8, 0);
        DrawMenuGameOver(score);
        printf("Draw menu game over\n");
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 8, -4.5);
    DrawMenuScore(score);
    glPopMatrix();

    if (initBalls == 1)
    {
        InitialiseBalls(balls, ballNum, positions, textures, mass, forces, 2);

        initialiseStick(&stick, balls[0]);

        initBalls = 0;

        printf("Draw balls at start\n");
    }

    if (initBalls == 0 && menuStart == 0 && menuBalls == 0 && menuFriction == 0)
    {
        for(int i = 0; i < ballNum; i++)
        {
            DrawBall(balls[i], i);
            if(balls[i].isMoving == 1)
            {
                showStick = 0;
            }
        }
    }

    if(showStick == 1 && menuStart == 0 && menuBalls == 0 && menuFriction == 0)
    {
        drawStick(&stick, balls[0]);
    }

    glutSwapBuffers(); // flush buffers
}

void MousePosition(int x, int y)
{
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    m_pos[0] = ((float)x - w/2)/(48.387);
    m_pos[1] = 0.f;
    m_pos[2] = ((float)y - h/2)/(48.387);
}

void animate(void)
{
    glutTimerFunc(TIMERSECS, animate, 0);

    glutPassiveMotionFunc(MousePosition);

    if (menuStart == 0 && menuBalls == 0 && menuFriction == 0)
    {
        updateStick(&stick, &balls[0], m_pos, &prevTime);

        PositionUpdate(balls, &prevTime, ballNum, forces, 2, friction);

        for(int i = 0; i < ballNum; i++)
        {
            if (BalltoPocketCheck(balls[i]))
            {
                if (i == 0)
                {
                    balls[i].ball_pos[0] = -OffCentre;
                    balls[i].ball_pos[1] = balls[i].ball_radius;
                    balls[i].ball_pos[2] = 0.f;
                    balls[i].ball_vel[0] = 0.f;
                    balls[i].ball_vel[1] = 0.f;
                    balls[i].ball_vel[2] = 0.f;
                }
                else
                {
                    PocketCollisionResolve(&balls[i]);
                }
                scoreUpdate(i);
            }
        }

        glutPostRedisplay();
    }
}

void keys(unsigned char key, int x, int y) {  //Taks unsigned char key

    // Exit keys
	if(key == 'q') exit(0);
    if(key == 'Q') exit(0);

    //Transformation Keys
    if (menuStart == 1)
    {
        if ((int)key == 13)
        {
            menuStart = 0;
            menuBalls = 1;
        }
    }
    else if (menuBalls == 1)
    {
        if (key == '1')
        {
            menuFriction = 1;
            menuBalls = 0;

            triPosition(balls[0].ball_radius);
        }
        else if (key == '2')
        {
            menuFriction = 1;
            menuBalls = 0;

            recPosition(balls[0].ball_radius);
        }
    }
    else if (menuFriction == 1)
    {
        if (key == '1')
        {
            menuFriction = 0;
            menuStart = 0;
            menuBalls = 0;
            friction = smooth;
            initBalls = 1;
        }
        else if (key == '2')
        {
            menuFriction = 0;
            menuStart = 0;
            menuBalls = 0;
            friction = normal;
            initBalls = 1;
        }
        else if (key == '3')
        {
            menuFriction = 0;
            menuStart = 0;
            menuBalls = 0;
            friction = rough;
            initBalls = 1;
        }
    }
    else if (menuGameOver == 1)
    {
        if ((int)key == 13)
        {
            menuStart = 1;
            menuGameOver = 0;
        }
    }

	// Redisplay the window content
    glutPostRedisplay();
}

void mouse(float x, float y)
{
    if(showStick == 0)
    {
        return;
    }

    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    m_pos[0] = ((float)x - w/2)/(48.387);
    m_pos[1] = 0.f;
    m_pos[2] = ((float)y - h/2)/(48.387);

    shootStick(&stick, balls[0], m_pos);
}

void myReshape(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (h==0)
        h = 1.0;
    if (w==0)
        w = 1.0;

    if (cameraMode == ORTHO){
        // This is orthographic projection
        GLdouble left    = -2;
        GLdouble right   = 2;
        GLdouble bottom  = -1;
        GLdouble top     = 1;
        GLdouble nearVal = 0.1;
        GLdouble farVal  = 100;     // near and far clipping planes

        if (w <= h){
            GLfloat aspect = (GLfloat) h / (GLfloat) w;
            glOrtho(left,  right, bottom * aspect,  top*aspect, nearVal,  farVal);
        }else{
            GLfloat aspect = (GLfloat) w / (GLfloat) h;
            glOrtho(left * aspect,  right * aspect, bottom,  top, nearVal,  farVal);
        }

    }else if (cameraMode == PERSPECTIVE){
        //
        GLdouble fov	 = 60;		// degrees
        GLdouble aspect	 = 1.0* w / h;		// aspect ratio aspect = width / height
        GLdouble nearVal = 0.1;
        GLdouble farVal  = 100;     // near and far clipping planes

        gluPerspective(fov, aspect, nearVal, farVal);

    }else if (cameraMode == FRUSTUM){
        GLdouble left = -1;
        GLdouble right= 1;
        GLdouble bottom = -1;
        GLdouble top    = 1;
        GLdouble nearVal = .05;
        GLdouble farVal  = 100;     // near and far clipping planes
        glFrustum(left,  right,
				  bottom,  top,
                  nearVal,  farVal);
    }


    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {

    /* Standard GLUT initialization */
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB  | GLUT_DEPTH);

    glutInitWindowSize(1000,1000); /* 500 x 500 pixel window */
    glutInitWindowPosition(0,0); /* place window top left on display */
    glutCreateWindow("Billiards");  /* window title */

    // Initialization
    init(); 		/* set attributes */

    glutDisplayFunc(mydisplay);  /* display callback invoked when window is opened */

    // Add reshape function
    glutReshapeFunc(myReshape);

    // Add mouse motion detection
	glutPassiveMotionFunc(MousePosition);

	// Add mouse interaction
    glutMouseFunc(mouse);
	// Add keyboard interaction
	glutKeyboardFunc(keys);

	LoadTextures(textures, &texWidth, &texHeight, &imageData);
	InitTextures(&imageData, &texWidth, &texHeight);

	prevTime = glutGet(GLUT_ELAPSED_TIME) / 1000.f;
    glutTimerFunc(TIMERSECS, animate, 0);

    // Entering the main loop
    glutMainLoop(); /* enter event loop */

    return 0;
}

