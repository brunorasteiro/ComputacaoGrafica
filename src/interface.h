#ifndef INTERFACE_H
#define INTERFACE_H

// Vou botar esse no arquivo do rasteiro/suite/duca ja que so a parte dele usa
// Quando mais de uma pessoa precisar usar, a gente quebra ele em mais funcoes
void on_mouse_click(int, int, int, int);

// Cada um implementa um desses aqui
void drawSunAndSky();
void drawBackground();
void drawMillTower();
void drawMillHead();

#endif
