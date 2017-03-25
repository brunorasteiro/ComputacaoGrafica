#include <GL/glut.h>
#include "interface.h"
#include "sun_and_sky.h"

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
		glVertex2f(-400,  300);
		glVertex2f( 400,  300);

		glColor3f(bot[0], bot[1], bot[2]);
		glVertex2f( 400, -300);
		glVertex2f(-400, -300);
	}
	glEnd();
}
