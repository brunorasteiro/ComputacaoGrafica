all:
	@ gcc -o prog.exe main.c helice.h -lglut -lGLU -lGL -lm 
	@ ./prog.exe
clear:
	rm prog.exe -f