#ifndef INTERFACE_H
#define INTERFACE_H

// Valores da area de desenho
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

// Argumentos do gluOrtho2D
#define VIEW_MINX -400
#define VIEW_MAXX  400
#define VIEW_MINY -300
#define VIEW_MAXY  300

#define VIEW_WIDTH  (VIEW_MAXX - VIEW_MINX)
#define VIEW_HEIGHT (VIEW_MAXY - VIEW_MINY)

#define MILL_CENTERX  200.0
#define MILL_CENTERY - 75.0

#define TERRAIN_AREA -200.0

// Definido em helice.c
void on_mouse_click(int, int, int, int);

// Cada um implementa um desses aqui
void drawSunAndSky();
void drawTerrain();
void drawMillTower();
void drawMillHead();

#endif
