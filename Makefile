all: compile run

compile:
	g++ main.cpp src/*.cpp -o run-x64.exe -Isrc/ -m64 -lraylib -lgdi32 -lwinmm -Wall

run:
	run-x64.exe
