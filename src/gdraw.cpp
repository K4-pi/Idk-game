#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <iostream>

#include <raylib.h> // Version 5.5
#include "gdraw.h"

/*
 * 0 = nothing :)
 * 1 = obstacle
 */

void DrawBorders(std::ifstream *file, Texture2D *borderTexture)
{
    Vector2 drawPos = { 0 };
    int previousRand = -1;
    int rNum = 0;
    std::string line;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 2);

    while(std::getline(*file, line))
    {
        for(int i = 0; i < (int)line.size(); i++)
        {
            while (rNum == previousRand) // Prevents texture repetition
            {
                rNum = distribution(generator);
            }
            if(line[i] == '1')
            {
                DrawTexture(borderTexture[rNum], drawPos.x, drawPos.y, WHITE);
            }
            drawPos.x += 32;
            previousRand = rNum;
        }
        drawPos.x = 0;
        drawPos.y += 32;
    }
    drawPos = {0, 0};

    file->clear(); // clears error flags
    file->seekg(0, std::ios::beg); // Puts cursor at the beginning of the file
}
