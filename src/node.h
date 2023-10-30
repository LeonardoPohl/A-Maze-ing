#include <array>

class NodeNeighbours;

class Node {
public:
  Node(int x, int y);
  void setNeighbours(NodeNeighbours neighbours);
  Node* getLeft();
  Node* getRight();
  Node* getUp();
  Node* getDown();

private:
  int x,y;
  
  Node* left = nullptr;
  Node* right = nullptr;
  Node* up = nullptr;
  Node* down = nullptr;
};

class NodeNeighbours {
public:
  Node *left, *right, *up, *down;
  NodeNeighbours(){

        if (x == 0) {
          nn.up = nullptr;
        }else{
          nn.up = &mazeNodes->at(x-1)[y];
        }

        if (x = mazeSize->getHeight() - 1) {
          nn.down = nullptr;
        }else{
          nn.down = &mazeNodes->at(x+1)[y];
        }
  };

};