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

#define MAZE_MAX_ROW 5
#define MAZE_MAX_COL 5

int g_Maze[MAZE_MAX_ROW][MAZE_MAX_COL] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};

#endif