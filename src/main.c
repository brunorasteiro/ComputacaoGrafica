#include"helice.h"

void Draw(void){ 

    // Define cor de fundo da cena
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Pinta a tela com a cor definida acima
    glClear(GL_COLOR_BUFFER_BIT);

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

  glFlush();     
}

void on_mouse_click(int button, int state, int x, int y){
    
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


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Trabalho 1");
    glutDisplayFunc(Draw);
    glutMouseFunc(on_mouse_click);
    gluOrtho2D(-400, 400, -300, 300);
        
    glutMainLoop();
}