all: compile run

compile:
	g++ main.cpp src/*.cpp -o run.exe -lraylib -lgdi32 -lwinmm -Wall

run:
	run.exe
