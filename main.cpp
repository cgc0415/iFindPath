#include <glut.h>
#include <cstdio>
#include <cstdlib>
#include"iFindPath.h"

using namespace std;

#define TIMER_INTERVAL_VALUE 800
#define WINDOW_SIZE_X 600
#define WINDOW_SIZE_Y 600

struct I_BLock g_Block;

GLfloat rtx = -0.5f, rty = -0.5f, rtz = 0.0f;
GLfloat step = 0.05;
GLfloat exp = 1e-3;

void init()
{
	
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	g_Block.leftUp_x = 0.05;
	g_Block.leftUp_y = 0.95;
	g_Block.rightDown_x = 0.15;
	g_Block.rightDown_y = 0.85;

	
}

void draMaze()
{
	struct I_BLock tmpBlock;

	glColor3f(1,1,1);
	tmpBlock.leftUp_x = 0.2;
	tmpBlock.leftUp_y = 1;
	tmpBlock.rightDown_x = 0.4;
	tmpBlock.rightDown_y = 0.8;

	glRectf(tmpBlock.leftUp_x, tmpBlock.leftUp_y, tmpBlock.rightDown_x, tmpBlock.rightDown_y);

	tmpBlock.leftUp_x = 0.2;
	tmpBlock.leftUp_y = 0.8;
	tmpBlock.rightDown_x = 0.4;
	tmpBlock.rightDown_y = 0.6;
	glRectf(tmpBlock.leftUp_x, tmpBlock.leftUp_y, tmpBlock.rightDown_x, tmpBlock.rightDown_y);

	tmpBlock.leftUp_x = 0.6;
	tmpBlock.leftUp_y = 0.8;
	tmpBlock.rightDown_x = 0.8;
	tmpBlock.rightDown_y = 0.4;
	glRectf(tmpBlock.leftUp_x, tmpBlock.leftUp_y, tmpBlock.rightDown_x, tmpBlock.rightDown_y);

	tmpBlock.leftUp_x = 0.2;
	tmpBlock.leftUp_y = 0.4;
	tmpBlock.rightDown_x = 0.8;
	tmpBlock.rightDown_y = 0.2;
	glRectf(tmpBlock.leftUp_x, tmpBlock.leftUp_y, tmpBlock.rightDown_x, tmpBlock.rightDown_y);

	tmpBlock.leftUp_x = 0.6;
	tmpBlock.leftUp_y = 0.2;
	tmpBlock.rightDown_x = 0.8;
	tmpBlock.rightDown_y = 0;
	glRectf(tmpBlock.leftUp_x, tmpBlock.leftUp_y, tmpBlock.rightDown_x, tmpBlock.rightDown_y);
}

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);

	glPushMatrix();
	printf("%f %f %f\n", rtx, rty, rtz);
	glTranslatef(rtx, rty, rtz);

	glBegin(GL_LINE_STRIP);	    
		glVertex2f(0, 1);
		glVertex2f(0, 0);
		glVertex2f(1, 0);
		glVertex2f(1, 1);
		glVertex2f(0, 1);
	glEnd();

	glColor3f(1,0,0);
	glRectf(g_Block.leftUp_x, g_Block.leftUp_y, g_Block.rightDown_x, g_Block.rightDown_y);

	draMaze();	

	glPopMatrix();
	glutSwapBuffers();
}

void timerFunction(int value)
{
	g_Block.leftUp_x -= 0.05;
	g_Block.rightDown_x -= 0.05;
	
	glutPostRedisplay();
	glutTimerFunc(TIMER_INTERVAL_VALUE, timerFunction, 1);
}

void processKeyBoard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (rtx - step > -0.53)rtx -= step;
		break;
	case GLUT_KEY_RIGHT:
		if (rtx + step < 0.53)rtx += step;
		break;
	case GLUT_KEY_UP:
		if (rty + step < 0.53)rty += step;
		break;
	case GLUT_KEY_DOWN:
		if (rty - step > -0.53)rty -= step;
		break;
	default:
		break;
	}
		
	glutPostRedisplay();
	return;
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WINDOW_SIZE_X, WINDOW_SIZE_Y);
	glutCreateWindow("test");

	init();

	glutDisplayFunc(draw);
	
	//glutIdleFunc(move);
	glutSpecialFunc(processKeyBoard);

	glutTimerFunc(TIMER_INTERVAL_VALUE, timerFunction, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}