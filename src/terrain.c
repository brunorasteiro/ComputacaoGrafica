#include <GL/glut.h>
#include <math.h>
#include "interface.h"


void drawTerrain()
{
	glBegin(GL_QUADS);
	// Vertices de cima azulados

	glColor3f(0.5f, 0.35f, 0.05f); // um marrom mais terroso
	glVertex2f(VIEW_MINX, TERRAIN_AREA);
	glVertex2f(VIEW_MAXX, TERRAIN_AREA);

	glColor3f(0.5f, 0.35f, 0.05f); // um marrom mais terroso
	glVertex2f(VIEW_MAXX, VIEW_MINY);
	glVertex2f(VIEW_MINX, VIEW_MINY);
	glEnd();
}
