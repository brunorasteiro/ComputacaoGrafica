all:
	@ gcc -o exe main.c helice.h -lglut -lGLU -lGL -lm 
	@ ./exe
clear:
	rm exe -f