TARGET := catavento

ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
endif

LIB_OPTIONS := -lglut -lGLU -lGL -lm

-include custom_options.mk
# If you need different libraries to compile the project,
# write LIB_OPTIONS := <your options> inside custom_libs.mk.
# custom_options.mk is also gitignored

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
