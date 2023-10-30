#include <vector>
#include <memory>

class Node;

namespace MazeUtils {
  class Size;

  void createMazeNodes(std::vector<std::vector<Node>> *mazeNodes, std::shared_ptr<Size> mazeSize);
  void populateMaze(std::vector<std::vector<Node>> *mazeNodes, std::shared_ptr<Size> mazeSize);
}