TARGET := catavento


# Flags para Linux
LIB_OPTIONS := -lglut -lGLU -lGL -lm

# Flags para Windows
ifeq ($(OS),Windows_NT)
    INC_PATH := -Ideps_windows/include
    LIB_PATH := -Ldeps_windows/lib/x64
    LIBS     := -lfreeglut -lglu32 -lopengl32 -lm

    LIB_OPTIONS := $(INC_PATH) $(LIB_PATH) $(LIBS)
endif

SOURCES = $(wildcard src/*.c)

.PHONY: all
all:
	echo $(OS)
	mkdir -p bin/
	gcc $(SOURCES) -Wall -Wextra -Isrc -o bin/$(TARGET) $(LIB_OPTIONS)
ifeq ($(OS),Windows_NT)
	cp deps_windows/bin/x64/freeglut.dll bin/
endif

.PHONY: run
run:
	./bin/$(TARGET)

.PHONY: clean
clean:
	rm -f bin/$(TARGET)
