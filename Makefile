TARGET := catavento

ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
endif

LIB_OPTIONS := -lglut -lGLU -lGL -lm

ifdef HUGO
    INC_PATH := -Ic:/tools/include
    LIB_PATH := -Lc:/tools/lib/x64
    LIBS     := -lfreeglut -lglu32 -lopengl32 -lm

    LIB_OPTIONS := $(INC_PATH) $(LIB_PATH) $(LIBS)
endif

SOURCES = $(wildcard src/*.c)

.PHONY: all
all:
	gcc $(SOURCES) -Isrc -o bin/$(TARGET) $(LIB_OPTIONS)

.PHONY: run
run:
	./bin/$(TARGET)

.PHONY: clean
clean:
	rm -f bin/$(TARGET)
