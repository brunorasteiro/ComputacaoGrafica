# Catavento - SCC0250

## Compilação

O executavel é criado na pasta bin, então dá pra botar os .dlls lá.
Se precisar usar opções de compilação diferentes pro seu pc, só precisa criar um ifdef no makefile:

	ifdef NOME
		# exemplo
		LIB_OPTIONS = -lfreeglut -lglu -lopengl32 -lm
	endif

e depois setar a variavel na hora de compilar:

	make NOME=1

## Arquivos

**interface.h** declara umas constantes, por exemplo tamanho da tela, coordenadas dos cantos, posição do moinho etc,
e os protótipos das funções que cada um tem que fazer:

* void drawSunAndSky(); -> Hugo
* void drawTerrain(); -> M Vinicius
* void drawMillTower(); -> Raul
* void drawMillHead(); -> Rasteiro

**main.c** dá include em **interface.h** e chama essas funções em sequência.
Os outros 2 arquivos contém **void drawSunAndSky()** e **voidDrawMillHead()**. Cada um implementa uma das duas.

## Bugs

O desenho inteiro tá girando junto com o catavento.
