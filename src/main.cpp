//main.cpp

#include <iostream>

#include "maze.h"

int main(int argc, char **argv)
{
    Maze maze{10, 10};
    maze.printMaze();
    maze.regenerateMaze();

    std::cin.get()
}