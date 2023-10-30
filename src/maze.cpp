#include "maze.h"

Maze::Maze(int height, int width) {
  mazeSize = std::make_shared<MazeUtils::Size>(height, width);
  this->generateMaze();
}

void Maze::regenerateMaze(){
  MazeUtils::populateMaze(&this->mazeNodes, this->mazeSize);

  MazeUtils::createMazeNodes();

}