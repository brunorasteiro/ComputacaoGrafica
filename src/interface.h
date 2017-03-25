#ifndef INTERFACE_H
#define INTERFACE_H


// Valores da area de desenho
static const GLint WINDOW_WIDTH  = 800;
static const GLint WINDOW_HEIGHT = 600;

static const GLint VIEW_WIDTH  = 800;
static const GLint VIEW_HEIGHT = 600;

static const GLint VIEW_MINX = -400;
static const GLint VIEW_MAXX = 400;
static const GLint VIEW_MINY = -300;
static const GLint VIEW_MAXY = 300;



// Vou botar esse no arquivo do rasteiro/suite/duca ja que so a parte dele usa
// Quando mais de uma pessoa precisar usar, a gente quebra ele em mais funcoes
void on_mouse_click(int, int, int, int);

// Cada um implementa um desses aqui
void drawSunAndSky();
void drawBackground();
void drawMillTower();
void drawMillHead();

#endif
