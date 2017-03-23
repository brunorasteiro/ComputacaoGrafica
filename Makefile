all:
	@ gcc -o helice helice.c -lglut -lGLU -lGL -lm 
	@ ./helice
clear:
	rm helice -f