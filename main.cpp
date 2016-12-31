#include <glut.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

GLfloat rtx = 0.0f, rty = 0.0f, rtz = 0.0f;
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

	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.5f, 0.5f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.5f, 0.5f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.5f, -0.5f);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
	glEnd();

	glPopMatrix();
	glutSwapBuffers();
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
	glutInitWindowSize(200, 200);
	glutCreateWindow("test");

	init();

	glutDisplayFunc(draw);
	//glutIdleFunc(move);
	glutSpecialFunc(processKeyBoard);
	glutMainLoop();
	return 0;
}