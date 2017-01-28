#ifndef I_FINDPATH_H
#define I_FINDPATH_H

#include <glut.h>

//the moving block coordinations.
struct I_BLock
{
	GLfloat leftUp_x;
	GLfloat leftUp_y;
	GLfloat rightDown_x;
	GLfloat rightDown_y;
};

struct PathPoint
{
	int row;
	int col;
};

#define MAX_ROW 7
#define MAX_COL 7

extern int g_Steps;
extern struct PathPoint resultPath[25];

#endif