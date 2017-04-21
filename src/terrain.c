#include <GL/glut.h>
#include <math.h>
#include "interface.h"

void drawGround();
void drawMountains();

/*
  Wrapper do drawGround, drawMountains
 */
void drawTerrain()
{
	drawGround();
	drawMountains();
}

void drawGround()
{
	glBegin(GL_QUADS);
	glColor3f(0, 0.6f, 0.2f);
	//glColor3f(0.5f, 0.35f, 0.05f);
	glVertex2f(VIEW_MINX, TERRAIN_AREA);
	glVertex2f(VIEW_MAXX, TERRAIN_AREA);

	glColor3f(0, 0.6f, 0.2f);
	glVertex2f(VIEW_MAXX, VIEW_MINY);
	glVertex2f(VIEW_MINX, VIEW_MINY);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0.6f, 0.2f);
	// desenhando parte do fundo do terreno
	glVertex2f(VIEW_MINX, TERRAIN_AREA+100);
	glVertex2f(VIEW_MAXX, TERRAIN_AREA+100);

	// desenhando parte do fundo do terreno
	glColor3f(0, 0.6f, 0.2f);
	glVertex2f(VIEW_MAXX, VIEW_MINY);
	glVertex2f(VIEW_MINX, VIEW_MINY);
	glEnd();

}

void drawMountains()
{

	// desenho primeiro triangulo
	glColor3f(0.5f, 0.35f, 0.05f);
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

	// desenho quarto triangulo
	glColor3f(0.5f, 0.35f, 0.05f);
	glBegin(GL_POLYGON);
	glVertex2f(TERRAIN_AREA+50, TERRAIN_AREA+50);
	glVertex2f(1.4f, 50);
	glVertex2f(VIEW_MAXX-40, TERRAIN_AREA+10);
	glEnd();

	// desenho quinto triangulo (background)
	glColor3f(0.5f, 0.35f, 0.05f);
	glBegin(GL_POLYGON);
	glVertex2f(VIEW_MINX, TERRAIN_AREA+100);
	glVertex2f(VIEW_MINX+150, 100);
	glVertex2f(100, TERRAIN_AREA+100);
	glEnd();

	// desenho quinto triangulo (background)
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.35f, 0.05f);
	glVertex2f(VIEW_MAXX, TERRAIN_AREA+100);
	glVertex2f(VIEW_MINX+500, 100);
	glVertex2f(TERRAIN_AREA+100, TERRAIN_AREA+100);
	glEnd();
}
