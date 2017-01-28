#include <glut.h>
#include <cstdio>
#include <cstdlib>
#include"iFindPath.h"

using namespace std;

#define TIMER_INTERVAL_VALUE 800
#define WINDOW_SIZE_X 600
#define WINDOW_SIZE_Y 600

extern void Algorithm_BFS();
extern int maze[MAX_ROW][MAX_COL];

struct I_BLock g_Block;
int bkp_maze[MAX_ROW][MAX_COL]; //存放maze中的原始数据

int g_StepIndex = 0; //第几步
int g_Steps = 0; //从初始位置到终点最少需要走的步数
struct PathPoint resultPath[25]; //从BFS算法中得到的结果是倒序排列的
struct PathPoint startToEndPath[25]; //从起点到终点路径


GLfloat rtx = -0.5f, rty = -0.5f, rtz = 0.0f;
GLfloat step = 0.05;
GLfloat exp = 1e-3;
GLfloat g_interval = 1.0 / MAX_ROW;

void init()
{	
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	g_Block.leftUp_x = 0.02;
	g_Block.leftUp_y = 0.98;
	g_Block.rightDown_x = 0.12;
	g_Block.rightDown_y = 0.88;

	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			bkp_maze[i][j] = maze[i][j];
		}
	}

	Algorithm_BFS();

	for(int i = 0; i < g_Steps; i++)
	{
		startToEndPath[i].row = resultPath[g_Steps-i-1].row;
		startToEndPath[i].col = resultPath[g_Steps-i-1].col;
	}
}

void draMaze()
{
	struct I_BLock tmpBlock;

	glColor3f(1,1,1);

	for (int rowIdx = 0; rowIdx < MAX_ROW; rowIdx++)
	{
		for (int colIdx = 0; colIdx < MAX_COL; colIdx++)
		{
			if (bkp_maze[rowIdx][colIdx])
			{
				tmpBlock.leftUp_x = colIdx * g_interval;
				tmpBlock.leftUp_y = (MAX_ROW-rowIdx) * g_interval;

				tmpBlock.rightDown_x = colIdx * g_interval + g_interval;
				tmpBlock.rightDown_y = (MAX_COL-rowIdx-1) * g_interval;
				glRectf(tmpBlock.leftUp_x, tmpBlock.leftUp_y, tmpBlock.rightDown_x, tmpBlock.rightDown_y);
			}

		}

	}
}

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);

	glPushMatrix();
	//printf("%f %f %f\n", rtx, rty, rtz);
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
	if(g_Steps ==  g_StepIndex)
		return;

	int rowOffset = startToEndPath[g_StepIndex+1].row - startToEndPath[g_StepIndex].row;
	int colOffset = startToEndPath[g_StepIndex+1].col - startToEndPath[g_StepIndex].col;

	g_Block.leftUp_x += colOffset * g_interval;
	g_Block.leftUp_y -= rowOffset * g_interval;

	g_Block.rightDown_x += colOffset * g_interval;
	g_Block.rightDown_y -= rowOffset * g_interval;
	
	glutPostRedisplay();

	g_StepIndex++;

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