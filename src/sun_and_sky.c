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
	// Cor dos vertices de cima do fundo
	GLfloat top[] =
	{
		 53 / 255.0,
		113 / 255.0,
		237 / 255.0
	};

	// Cor dos vertices de baixo do fundo
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

	// Desenha o fundo
	glBegin(GL_QUADS);
	{
		// Vertices de cima azulados
		glColor3f(top[0], top[1], top[2]);
		glVertex2f(VIEW_MINX, VIEW_MAXY);
		glVertex2f(VIEW_MAXX, VIEW_MAXY);

		// Vertices de baixo esbranquicados
		glColor3f(bot[0], bot[1], bot[2]);
		glVertex2f(VIEW_MAXX, VIEW_MINY);
		glVertex2f(VIEW_MINX, VIEW_MINY);
	}
	glEnd();

	// Posicao do centro
	GLfloat cx = VIEW_MINX / 2;
	GLfloat cy = VIEW_MAXY * 2 / 3;
	// Raio do sol
	GLfloat r = 32;
	// Raio da luz
	GLfloat light = 32;
	// Numero de triangulos
	GLint count = 32;

	// Vertices da base do triangulo e da parte de dentro dos trapezios da luz
	GLint x[2] = {0, 0};
	GLint y[2] = {0, 0};

	// Vertices da parte de fora dos trapezios da luz
	GLint lx[2] = {0, 0};
	GLint ly[2] = {0, 0};

	// Desenha o sol
	for(int i = 0; i < count; i++)
	{
		double aux0 = 2*pi * i/count;
		double aux1 = 2*pi * (i+1)/count;

		// Calcula a posicao dos vertices dos triangulos do sol e dos trapezios da luz
		x[0] = cx + r * sin(aux0);
		x[1] = cx + r * sin(aux1);

		y[0] = cy + r * cos(aux0);
		y[1] = cy + r * cos(aux1);

		lx[0] = cx + (r+light) * sin(aux0);
		lx[1] = cx + (r+light) * sin(aux1);

		ly[0] = cy + (r+light) * cos(aux0);
		ly[1] = cy + (r+light) * cos(aux1);

		// Desenha triangulos do sol
		glBegin(GL_TRIANGLES);
		{
			// Centro meio branco
			glColor3f(1.0, 1.0, 1.0);
			glVertex2f(cx, cy);

			// Contorno meio amarelo
			glColor3f(1.0, 1.0, 0.625);
			glVertex2f(x[0], y[0]);
			glVertex2f(x[1], y[1]);
		}
		glEnd();

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// Desenha trapezios da luz
		glBegin(GL_QUADS);
		{
			glColor4f(1.0, 1.0, 0.625, 1.0);
			glVertex2f(x[0], y[0]);
			glVertex2f(x[1], y[1]);

			// Transicao de amarelo pra azulado/transparente
			glColor4f(0.5, 0.5, 1.0, 0.0);
			glVertex2f(lx[1], ly[1]);
			glVertex2f(lx[0], ly[0]);
		}
		glEnd();

		glDisable(GL_BLEND);
	}
}
