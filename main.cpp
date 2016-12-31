#include <glut.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define TIMER_INTERVAL_VALUE 800
#define WINDOW_SIZE_X 400
#define WINDOW_SIZE_Y 400

GLfloat rtx = 0.8f, rty = 0.0f, rtz = 0.0f;
GLfloat step = 0.05;
GLfloat exp = 1e-3;

void init()
{
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	printf("%f %f %f\n", rtx, rty, rtz);
	glTranslatef(rtx, rty, rtz);

	/*glBegin(GL_LINE_STRIP);	    
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
	glEnd();*/

	glRectf(-0.25,0.25,0.25,-0.25);

	glPopMatrix();
	glutSwapBuffers();
}

void timerFunction(int value)
{
	if(rtx + 0.7 <= 0.001)
		rtx = 0;
	rtx -= 0.1;
	
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