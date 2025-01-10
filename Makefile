all: compile run

compile:
	g++ main.cpp src/*.cpp -o run.exe -Isrc/ -lraylib -lgdi32 -lwinmm -Wall

run:
	run.exe
