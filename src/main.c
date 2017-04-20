#include <GL/glut.h>
#include "interface.h"

void draw(void)
{

    GLfloat mRot[16]; 
    
    // Inicia a matriz de transformações da openGL
    glMatrixMode(GL_MODELVIEW);

    // Salva a matriz com as rotações do moinho 
    glGetFloatv(GL_MODELVIEW_MATRIX, mRot);

    // Carrega matriz identidade para que as rotações não afetem todo o cenário
    glLoadIdentity();

    // Define cor de fundo da cena
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Pinta a tela com a cor definida acima
    glClear(GL_COLOR_BUFFER_BIT);

	drawSunAndSky();
	// drawGround();
	// drawMillTower();

    // Carrega a matriz com as rotações do moinho
    glLoadMatrixf(mRot);

    // Desenha a parte superior do moinho
    drawMillHead();

    glFlush();
}

int main(int argc, char* argv[])
{
	// Criacao de janela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Trabalho 1");

	// Bindings
    glutDisplayFunc(draw);
    glutMouseFunc(on_mouse_click);

	// Projecao 2D
	glMatrixMode(GL_PROJECTION);
    gluOrtho2D(
		VIEW_MINX, VIEW_MAXX,
		VIEW_MINY, VIEW_MAXY
	);

    glutMainLoop();
}
