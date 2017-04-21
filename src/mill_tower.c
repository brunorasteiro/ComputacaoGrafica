#include <math.h>
#include <GL/glut.h>
#include "interface.h"

void drawMillTower() {
	// desenha o triangulo do teto
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(130, -50);
	glVertex2f(200, 0);
	glVertex2f(270, -50);
	glEnd();

	// desenha a base do moinho
	glColor3f(1.47f, 0.39f, 0.36f);
	glBegin(GL_POLYGON);
	glVertex2f(150, -200);
	glVertex2f(250, -200);
	glVertex2f(250, -100);
	glVertex2f(150,-100);
	glEnd();	
	// desenha o topo da torre, onde o moinho esta
	glColor3f(1.0f, 0.6f, 0.2f);
	glBegin(GL_POLYGON);
	glVertex2f(130, -100);
	glVertex2f(270, -100);
	glVertex2f(270, -50);
	glVertex2f(130,-50);
	glEnd();
	//desenha as janelas
	//Janela 1
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(220, -150);
	glVertex2f(240, -150);
	glVertex2f(240, -130);
	glVertex2f(220,-130);
	glEnd();
	//janela 2
	glBegin(GL_POLYGON);
	glVertex2f(160, -180);
	glVertex2f(180, -180);
	glVertex2f(180, -160);
	glVertex2f(160,-160);
	glEnd();
	glColor3f(1.5f, 1.5f, 1.5f);
	// "X" da janela 1
	glBegin(GL_POLYGON);
	glVertex2f(229, -150);
	glVertex2f(231, -150);
	glVertex2f(231, -130);
	glVertex2f(229,-130);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220, -141);
	glVertex2f(240, -141);
	glVertex2f(240, -139);
	glVertex2f(220,-139);
	glEnd();
	//"X" da janela 2
	glBegin(GL_POLYGON);
	glVertex2f(171, -180);
	glVertex2f(169, -180);
	glVertex2f(169, -160);
	glVertex2f(171,-160);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(160, -171);
	glVertex2f(180, -171);
	glVertex2f(180, -169);
	glVertex2f(160,-169);
	glEnd();
	//desenha a porta
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(190, -200);
	glVertex2f(210, -200);
	glVertex2f(210, -170);
	glVertex2f(190,-170);
	glEnd();
	
	//desenha tijolos
	//tijolos lado esquerdo
	glColor3f(1.5f, 0.75f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(150, -120);
	glVertex2f(160, -120);
	glVertex2f(160, -125);
	glVertex2f(150,-125);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(165, -125);
	glVertex2f(155, -125);
	glVertex2f(155, -130);
	glVertex2f(165,-130);
	glEnd();
	
	//tijolos lado direito
	glBegin(GL_POLYGON);
	glVertex2f(150 + 85, -165);
	glVertex2f(160 + 85, -165);
	glVertex2f(160 + 85, -170);
	glVertex2f(150 + 85,-170);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(155 + 85, -170);
	glVertex2f(165 + 85, -170);
	glVertex2f(165 + 85, -175);
	glVertex2f(155 + 85,-175);
	glEnd();
	
	//desenha maçaneta
	int i;
	int lineAmount = 100;
	int x = 195, y = -190;
	GLfloat radius = 1.8f;
	GLfloat twicePi = 2.0f * 3.1415;
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) { 
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)), 
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}
