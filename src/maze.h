#include <vector>
#include <memory>

#include "node.h"
#include "maze_utils.h"

class Maze {
public:
  Maze(int height = 10, int width = 10);

  void printMaze();
  void regenerateMaze();
private:
  void generateMaze();
  void randomizeConnections(int seed);

  std::shared_ptr<MazeUtils::Size> mazeSize;

  std::vector<std::vector<Node>> mazeNodes{};
};