#include <glut.h>

void myDisplay(void)
{
     glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(1.0f, 0.0f, 0.0f);
     glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
     glFlush();
}

int main(int argc, char *argv[])
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
     glutInitWindowPosition(100, 100);
     glutInitWindowSize(400, 400);
     glutCreateWindow("第一个OpenGL程序");
     glutDisplayFunc(&myDisplay);
     glutMainLoop();

     return 0;

}

