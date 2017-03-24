#include <GL/glut.h>
#include "interface.h"

void draw(void)
{
    // Define cor de fundo da cena
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Pinta a tela com a cor definida acima
    glClear(GL_COLOR_BUFFER_BIT);

	drawMillHead();

    glFlush();
}

int main(int argc, char* argv[])
{
	// Criacao de janela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Trabalho 1");

	// Bindings
    glutDisplayFunc(draw);
    glutMouseFunc(on_mouse_click);

	// Projecao 2D
    gluOrtho2D(-400, 400, -300, 300);

    glutMainLoop();
}
