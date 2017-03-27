#include <GL/glut.h>
#include <math.h>
#include "interface.h"

// Prototipos das funcoes
void drawOriginMill(int, int);
void drawHelix(int, int, float);

#define DEG_TO_RAD M_PI/180

GLfloat xc = MILL_CENTERX;
GLfloat yc = MILL_CENTERY;

void drawMillHead()
{
	// Inicia a matriz de transformações da openGL
    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    // Define uma cor para o desenho
    glColor3f(0.238f, 0.173f, 0.14f);
    // Desenha as hélices do moinho
    drawHelix(4, 60, 40.0);

    // Define uma cor para o desenho
    glColor3f(0.0f, 0.0f, 0.0f);
    // Desenha o centro do moinho
    drawOriginMill(20, 7);
}

// Achei melhor tirar do main e botar aqui por causa das globais xc, yc
// BUG: Ta girando a imagem inteira em vez de so a helice do catavento
void on_mouse_click(int button, int state, int x, int y){

	// Pra tirar warning de variavel nao usada
	(void) x;
	(void) y;

    if (state == GLUT_DOWN) {

        if (button == GLUT_LEFT_BUTTON) {

            // Rotaciona 15º anti-horário
            glTranslatef(xc * (1.0f), yc * (1.0f), 0.0f);
            glRotatef(15.0f, 0.0f, 0.0f, 1.0f);
            glTranslatef(xc * (-1.0f), yc * (-1.0f), 0.0f);
        }
        else if (button == GLUT_RIGHT_BUTTON) {

            // Rotaciona 15º horário
            glTranslatef(xc * (1.0f), yc * (1.0f), 0.0f);
            glRotatef(-15.0f, 0.0f, 0.0f, 1.0f);
            glTranslatef(xc * (-1.0f), yc * (-1.0f), 0.0f);
        }

        // Força a glut redesenhar a cena
        glutPostRedisplay();
    }
}

void drawOriginMill(int n, int r){

    //******************************//
    //  DESENHA O CENTRO DO MOINHO  //
    //******************************//

    // x = Coordenada x do centro da circunferência
    // y = Coordenada y do centro da circunferência
    // n = Número de triangulos para aproximação do círculo
    // r = Raio do círculo
    GLfloat ang    = 0.0f;     // Ângulo para ir construindo os triângulos
    GLfloat varAng = 2*M_PI/n; // Incremento do ângulo proporcional ao número de triângulos


    for (; n > 0; n--){
        // Define os vértices do triângulo
        glBegin(GL_TRIANGLES);
            glVertex2f(xc, yc);
            glVertex2f(xc + r*cos(ang), yc + r*sin(ang));
            glVertex2f(xc + r*cos(ang + varAng), yc + r*sin(ang + varAng));
        glEnd();

        // Incrementa o angulo até 2*PI
        ang += varAng;
    }
    //------------------------------//
}


void drawHelix(int n, int h, float angH){
    //******************************//
    // DESENHA AS HÉLICES DO MOINHO //
    //******************************//

    // xc   = coordenada x do centro das hélices
    // yc   = coordenada y do centro das hélices
    // n    = número de hélices
    // h    = altura de cada hélice
    // angH = ângulo abertura de cada hélice
    // dir  = 0 - Não rotaciona; 1 - Anti-horário; 2 - Horário
    GLfloat     angE = (360 - (angH*n)) / n; // Angulo de espaçamento entre as hélices
    GLfloat     angETemp = angE/2;

    // Convertendo angulos para radiano
    angH     *= DEG_TO_RAD;
    angE     *= DEG_TO_RAD;
    angETemp *= DEG_TO_RAD;


    for (; n > 0; n--){
        // Define os vértices do triângulo
        glBegin(GL_TRIANGLES);
            glVertex2f(xc, yc);
            glVertex2f(xc + h*cos(angETemp), yc + h*sin(angETemp));
            glVertex2f(xc + h*cos(angETemp + angH), yc + h*sin(angETemp + angH));
        glEnd();

        angETemp += angH + angE;
    }
}
