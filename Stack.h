#include "Node.h"
//header file to show commands available
using namespace std;

class Stack{
 public:
  Stack();
  Node* pop();
  Node* peek();
  void push(Node* newNode);
  ~Stack();
 private:
  Node* head;
};
