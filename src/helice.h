#include<GL/glut.h>
#include<math.h>

#define DEG_TO_RAD M_PI/180

GLfloat xc = 200.0f;
GLfloat yc = -150.0f;


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