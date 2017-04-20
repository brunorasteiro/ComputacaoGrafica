#include <GL/glut.h>
#include <math.h>
#include "interface.h"

void drawGround();
void drawMountains();


/*
  Wrapper do drawGround e drawMountains
 */
void drawTerrain()
{
	drawGround();
	drawMountains();
}

void drawGround()
{
	glBegin(GL_QUADS);
	// Vertices de cima azulados

	glColor3f(0.5f, 0.35f, 0.05f);
	glVertex2f(VIEW_MINX, TERRAIN_AREA);
	glVertex2f(VIEW_MAXX, TERRAIN_AREA);

	glColor3f(0.5f, 0.35f, 0.05f);
	glVertex2f(VIEW_MAXX, VIEW_MINY);
	glVertex2f(VIEW_MINX, VIEW_MINY);
	glEnd();

}
void drawMountains()
{

	// desenho primeiro triangulo
	glColor3f(0, 0.6f, 0.2f);
	glBegin(GL_POLYGON);
	glVertex2f(TERRAIN_AREA, TERRAIN_AREA);
	glVertex2f(1.4f, -100);
	glVertex2f(VIEW_MAXX, TERRAIN_AREA);
	glEnd();

	// desenho segundo triangulo
	glBegin(GL_POLYGON);
	glVertex2f(TERRAIN_AREA,TERRAIN_AREA);
	glVertex2f(1.4f, -100);
	glVertex2f(-100,-1);
	glEnd();

	// desenho terceiro triangulo
	glBegin(GL_POLYGON);
	glVertex2f(-300, -200);
	glVertex2f(-1, -200);
	glVertex2f(-200,-100);
	glEnd();
}
