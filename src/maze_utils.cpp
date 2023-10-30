#include <vector>

#include "exceptions/InvalidSizeException.h"
#include "node.h"
#include "maze_utils.h"

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

namespace MazeUtils {
  class Size {
    public:
    Size() : width(-1), height(-1) {}
    Size(int width, int height) : width(width), height(height) {
      if (!this->isValidSize()){
        throw new InvalidSizeException();
      }
    }

    int getWidth(){
      if (!this->isValidSize()){
        throw new InvalidSizeException();
      }

      return width;
    }

    int getHeight(){
      if (!this->isValidSize()){
        throw new InvalidSizeException();
      }

      return height;
    }

    bool isValidSize(){
      return width > 0 && width < MAX_WIDTH &&
             height > 0 && height < MAX_HEIGHT;
    }

    void setSize(int width, int height){
      this->width = width;
      this->height = height;

      if (!this->isValidSize()){
        throw new InvalidSizeException();
      }
    }

    private:
    int width;
    int height;
  };

  void createMazeNodes(std::vector<std::vector<Node>> *mazeNodes, std::shared_ptr<Size> mazeSize){
    for (int x = 0; x < mazeSize->getHeight(); x++) {
      std::vector<Node> row{};
      for (int y = 0; y < mazeSize->getWidth(); y++) {
        row.push_back({x, y});
      }
      mazeNodes->push_back(row);
    }
  }

  void populateMaze(std::vector<std::vector<Node>> *mazeNodes, std::shared_ptr<Size> mazeSize){
    for (int x = 0; x < mazeSize->getHeight(); x++) {
      for (int y = 0; y < mazeSize->getWidth(); y++) {
        NodeNeighbours nn{mazeNodes, x, y, mazeSize};
        

        mazeNodes->at(x)[y].setNeighbours(nn);
      }
    }
  }
}