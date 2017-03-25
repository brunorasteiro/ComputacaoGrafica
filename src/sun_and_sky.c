#include <math.h>
#include <GL/glut.h>
#include "interface.h"
#include "sun_and_sky.h"

const double pi = 3.1415926535;

double toRad(double degrees)
{
	return degrees * (pi / 180);
}

void drawSunAndSky()
{
	GLfloat top[] =
	{
		 53 / 255.0,
		113 / 255.0,
		237 / 255.0
	};

	GLfloat bot[] =
	{
		184 / 255.0,
		224 / 255.0,
		216 / 255.0
	};

	/*
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	*/

	glBegin(GL_QUADS);
	{
		glColor3f(top[0], top[1], top[2]);
		glVertex2f(VIEW_MINX, VIEW_MAXY);
		glVertex2f(VIEW_MAXX, VIEW_MAXY);

		glColor3f(bot[0], bot[1], bot[2]);
		glVertex2f(VIEW_MAXX, VIEW_MINY);
		glVertex2f(VIEW_MINX, VIEW_MINY);
	}
	glEnd();

	GLfloat cx = VIEW_MINX / 2;
	GLfloat cy = VIEW_MAXY * 2 / 3;
	GLfloat r = 48;
	GLint count = 24;


	GLint x[2] = {0, 0};
	GLint y[2] = {0, 0};

	for(int i = 0; i < count; i++)
	{
		// O offset de 5 graus faz parecer mais redondo
		double aux0 = toRad(10) + 2*pi * i/count;
		double aux1 = toRad(10) + 2*pi * (i+1)/count;

		x[0] = cx + r * sin(aux0);
		x[1] = cx + r * sin(aux1);

		y[0] = cy + r * cos(aux0);
		y[1] = cy + r * cos(aux1);

		glBegin(GL_TRIANGLES);
		{
			glColor3f(1.0, 1.0, 0.875);
			glVertex2f(cx, cy);

			glColor3f(1.0, 1.0, 0.375);
			glVertex2f(x[0], y[0]);
			glVertex2f(x[1], y[1]);
		}
		glEnd();
	}

}
