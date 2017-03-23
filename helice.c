#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

#define DEG_TO_RAD M_PI/180

GLfloat R = 0.0f;
GLfloat G = 0.0f;
GLfloat B = 0.0f;

GLfloat sorteia_cor() {
    return (rand()*1.0f) / (RAND_MAX*1.0f);
}

void drawOriginMill(int x, int y, int n, int r){

    //******************************//
    //  DESENHA O CENTRO DO MOINHO  //
    //******************************//

    // x = Coordenada x do centro da circunferência
    // y = Coordenada y do centro da circunferência
    // n = Número de triangulos para aproximação do círculo
    // r = Raio do círculo
    GLfloat ang    = 0.0f;     // Ângulo para ir construindo os triângulos
    GLfloat varAng = 2*M_PI/n; // Incremento do ângulo proporcional ao número de triângulos

    // Define uma como de desenho
    glColor3f(R, G, B);  

    for (; n > 0; n--){
        // Define os vértices do triângulo
        glBegin(GL_TRIANGLES);
            glVertex2f(x, y);
            glVertex2f(x + r*cos(ang), y + r*sin(ang));
            glVertex2f(x + r*cos(ang + varAng), y + r*sin(ang + varAng));
        glEnd();

        // Incrementa o angulo até 2*PI
        ang += varAng;
    }
    //------------------------------//
}


void drawPropeller(int x, int y, int n, int h, float angH){
    //******************************//
    // DESENHA AS HÉLICES DO MOINHO //
    //******************************//
    
    // x    = coordenada x do centro das hélices
    // y    = coordenada y do centro das hélices
    // n    = número de hélices
    // h    = altura de cada hélice
    // angH = ângulo abertura de cada hélice
    GLfloat     angE = (360 - (angH*n)) / n; // Angulo de espaçamento entre as hélices 
    GLfloat     angETemp = angE/2;
    
    // Convertendo angulos para radiano
    angH     *= DEG_TO_RAD;
    angE     *= DEG_TO_RAD;
    angETemp *= DEG_TO_RAD;

    // Define uma como de desenho
    glColor3f(R, G, B);  

    for (; n > 0; n--){
        // Define os vértices do triângulo
        glBegin(GL_TRIANGLES);
            glVertex2f(x, y);
            glVertex2f(x + h*cos(angETemp), y + h*sin(angETemp));
            glVertex2f(x + h*cos(angETemp + angH), y + h*sin(angETemp + angH));
        glEnd();
        
        angETemp += angH + angE; 
    }
}

void Draw(void){ 

    // Define cor de fundo da cena
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Pinta a tela com a cor definida acima
    glClear(GL_COLOR_BUFFER_BIT);

    // Inicia a matriz de transformações da openGL
    //glMatrixMode(GL_MODELVIEW); 
    //glLoadIdentity();

    // Define a cor preto para desenhar os eixos cartesianos
    glColor3f(0.0f, 0.0f, 0.0f);  
    glBegin(GL_LINES);
        glVertex2f(-400, 0);
        glVertex2f(400, 0);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0, -300);
        glVertex2f(0, 300);
    glEnd();


    // Desenha o centro do moinho
    drawOriginMill(200, -150, 20, 7);
    // Desenha as hélices do moinho
    drawPropeller(200, -150, 4, 60, 40.0);

  glFlush();     
}

void on_mouse_click(int button, int state, int x, int y){
    
    if (state == GLUT_DOWN) {

        if (button == GLUT_LEFT_BUTTON) {
            //glRotatef(10.0f,0.0f,0.0f,1.0f);
            
            R = sorteia_cor();
            G = sorteia_cor();
            B = sorteia_cor();
        }
        else if (button == GLUT_RIGHT_BUTTON) {
            R = 0.0f;
            G = 0.0f;
            B = 0.0f;
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
    glutCreateWindow("Exemplo OpenGL");
    glutDisplayFunc(Draw);

    glutMouseFunc(on_mouse_click);

    gluOrtho2D(-400, 400, -300, 300);
        
    glutMainLoop();
}