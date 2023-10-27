#include "menu.h"

void DrawMenuStart()
{
    float borderSize = 6.0f;
    Vector3 bordercolor = {0, 1, 0};
    float borderSize2 = 2.0f;
    Vector3 bordercolor2 = {1, 0, 0};
    char menuStringOne[] = "BILLIARD";
    char menuStringTwo[] = "Play";
    char menuStringThree[] = "press enter";

    DrawMenuBorder(borderSize, bordercolor);
    drawMenuOutline(borderSize);

    outputText(-1.5, 0.1, -1.6, 255.f, 255.f, 255.f, 0.006, GLUT_STROKE_ROMAN, menuStringOne);

    glPushMatrix();
    glTranslatef(0, 0.05, 1);
    glScalef(2.98, 1, 1);
    DrawMenuBorder(borderSize2, bordercolor2);
    glPopMatrix();

    outputText(-0.52, 0.1, 1, 1.f, 0.f, 0.f, 0.004, GLUT_STROKE_ROMAN, menuStringTwo);
    outputText(-0.92, 0.1, 1.5, 255.f, 255.f, 255.f, 0.0025, GLUT_STROKE_ROMAN, menuStringThree);
}

void DrawMenuBalls()
{
    float borderSize = 6.0f;
    Vector3 bordercolor = {0, 1, 0};
    char menuStringOne[] = "BALL PLACEMENT";
    char menuStringTwo[] = "Triangle";
    char menuStringThree[] = "Rectangle";
    char menuStringFour[] = "1";
    char menuStringFive[] = "2";

    glPushMatrix();

    DrawMenuBorder(borderSize, bordercolor);
    drawMenuOutline(borderSize);

    outputText(-2.2, 0.1, -2.2, 255.f, 255.f, 255.f, 0.004, GLUT_STROKE_ROMAN, menuStringOne);

    //Draw Triangle
    Point3 triangleVertices[3] = { {0, 0, -0.4}, {-0.4, 0, 0.4}, {0.4, 0, 0.4} };
    glTranslatef(-1.5, 0.1, -0.5);
    glColor3f(2, 2, 2);
    glBegin(GL_POLYGON);
        glVertex3fv(triangleVertices[0]);
        glVertex3fv(triangleVertices[1]);
        glVertex3fv(triangleVertices[2]);
    glEnd();

    glPopMatrix();
    glPushMatrix();

    outputText(-2.18, 0.1, 0.8, 255.f, 255.f, 255.f, 0.003, GLUT_STROKE_ROMAN, menuStringTwo);
    outputText(-1.6, 0.1, 1.6, 255.f, 255.f, 255.f, 0.0025, GLUT_STROKE_ROMAN, menuStringFour);

    glPopMatrix();
    glPushMatrix();

    //Draw Rectangle
    Point3 rectangleVertices[4] = { {-0.5, 0, -0.3}, {-0.5, 0, 0.3}, {0.5, 0, 0.3}, {0.5, 0, -0.3} };
    glTranslatef(1.3, 0.1, -0.44);
    glColor3f(2, 2, 2);
    glBegin(GL_POLYGON);
        glVertex3fv(rectangleVertices[0]);
        glVertex3fv(rectangleVertices[1]);
        glVertex3fv(rectangleVertices[2]);
        glVertex3fv(rectangleVertices[3]);
    glEnd();

    glPopMatrix();
    glPushMatrix();

    outputText(0.47, 0.1, 0.8, 255.f, 255.f, 255.f, 0.003, GLUT_STROKE_ROMAN, menuStringThree);
    outputText(1.15, 0.1, 1.6, 255.f, 255.f, 255.f, 0.0025, GLUT_STROKE_ROMAN, menuStringFive);

    glPopMatrix();

}


void DrawMenuFriction()
{
    float borderSize = 6.0f;
    Vector3 bordercolor = {0, 1, 0};
    char menuStringOne[] = "Smooth";
    char menuStringTwo[] = "Normal";
    char menuStringThree[] = "Rough";
    char menuStringFour[] = "1";
    char menuStringFive[] = "2";
    char menuStringSix[] = "3";
    char menuStringSeven[] = "Table Roughness";

    DrawMenuBorder(borderSize, bordercolor);

    drawMenuOutline(borderSize);

    outputText(-2.15, 0.1, -2, 255.f, 255.f, 255.f, 0.004, GLUT_STROKE_ROMAN, menuStringSeven);

    outputText(-2.6, 0.1, 0, 255.f, 255.f, 255.f, 0.003, GLUT_STROKE_ROMAN, menuStringOne);
    outputText(-2, 0.1, 1, 255.f, 255.f, 255.f, 0.003, GLUT_STROKE_ROMAN, menuStringFour);

    outputText(-0.6, 0.1, 0, 255.f, 255.f, 255.f, 0.003, GLUT_STROKE_ROMAN, menuStringTwo);
    outputText(-0.1, 0.1, 1, 255.f, 255.f, 255.f, 0.003, GLUT_STROKE_ROMAN, menuStringFive);

    outputText(1.4, 0.1, 0, 255.f, 255.f, 255.f, 0.003, GLUT_STROKE_ROMAN, menuStringThree);
    outputText(1.8, 0.1, 1, 255.f, 255.f, 255.f, 0.003, GLUT_STROKE_ROMAN, menuStringSix);
}

void DrawMenuGameOver(int score)
{
    float borderSize = 6.0f;
    Vector3 bordercolor = {0, 1, 0};
    float borderSize2 = 2.0f;
    Vector3 bordercolor2 = {1, 0, 0};
    char menuStringOne[] = "GAME OVER";
    char menuStringTwo[] = "Play Again";
    char menuStringThree[] = "press enter";
    char menuStringFour[] = "score:";
    char menuStringFive[3];
    sprintf(menuStringFive, "%d", score);

    DrawMenuBorder(borderSize, bordercolor);
    drawMenuOutline(borderSize);

    outputText(-2.36, 0.1, -1.6, 255.f, 255.f, 255.f, 0.006, GLUT_STROKE_ROMAN, menuStringOne);

    glPushMatrix();
    glTranslatef(0, 0.05, 1);
    glScalef(2.98, 1, 1);
    DrawMenuBorder(borderSize2, bordercolor2);
    glPopMatrix();

    outputText(-1.3, 0.1, 1, 1.f, 0.f, 0.f, 0.004, GLUT_STROKE_ROMAN, menuStringTwo);
    outputText(-0.92, 0.1, 1.5, 1.0, 1.0, 1.0, 0.0025, GLUT_STROKE_ROMAN, menuStringThree);
    outputText(-0.6, 0.1, -0.2, 1.0, 1.0, 1.0, 0.0025, GLUT_STROKE_ROMAN, menuStringFour);
    outputText(0.4, 0.1, -0.18, 1.0, 1.0, 1.0, 0.0025, GLUT_STROKE_ROMAN, menuStringFive);
}

void DrawMenuScore(int score)
{
    float borderSize = 1.0f;
    Vector3 bordercolor = {1, 0, 0};
    char menuStringOne[] = "score:";
    char menuStringTwo[3];
    sprintf(menuStringTwo, "%d", score);

    glPushMatrix();
    glScalef(2, 1, 0.5);
    DrawMenuBorder(borderSize, bordercolor);
    glTranslatef(0, 0, 0.1);
    glScalef(1.1, 1, 1);
    drawMenuOutline(borderSize);
    glPopMatrix();

    outputText(-0.5, 0.1, 0.15, 255.f, 255.f, 255.f, 0.002, GLUT_STROKE_ROMAN, menuStringOne);
    outputText(0.5, 0.1, 0.15, 255.f, 255.f, 255.f, 0.002, GLUT_STROKE_ROMAN, menuStringTwo);

}

void DrawMenuBorder(float border_size, Vector3 border_color)
{
    Vector3 borderVertices[4] = { {-border_size/2, 0.0f, -border_size/2}, {-border_size/2, 0.0f, border_size/2}, {border_size/2, 0.0f, border_size/2}, {border_size/2, 0.0f, -border_size/2} };

    glBegin(GL_POLYGON);
        glColor3fv(border_color);
        for(int i=0; i<4; i++) {
            glVertex3fv(borderVertices[i]);
        }
    glEnd();
}

void drawMenuOutline(float border_size)
{
    float size = border_size/2 - 0.05;

    glPushMatrix();

    glColor3f(255, 255, 255);
    glBegin(GL_LINES);
        glVertex3f(-size, 0.1, -size);
        glVertex3f(-size, 0.1, size);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(size, 0.1, size);
        glVertex3f(size, 0.1, -size);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-size, 0.1, -size);
        glVertex3f(size, 0.1, -size);
    glEnd();

    glBegin(GL_LINES);
        glScalef(0, 0, 2);
        glVertex3f(-size, 0.1, size);
        glVertex3f(size, 0.1, size);
    glEnd();

    glPopMatrix();
}

void outputText(float x, float y, float z, float r, float g, float b, float scale, void *font, char *string)
{
	char *c;
	glPushMatrix();
	glColor3f(r, g, b);
	glTranslatef(x,y,z);
	glRotatef(-90, 1, 0, 0);
	glScalef(scale, scale, scale);

	for (c=string; *c != '\0'; c++) {
		glutStrokeCharacter(font, *c);
	}

	glPopMatrix();
}

