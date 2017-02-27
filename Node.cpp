#include <iostream>
#include "Node.h"
//Node that creates a stack that holds a char, int, or pointer to the next node

using namespace std;

Node::Node(char d){
  next = NULL;
  data.c = d;
  type = 1;
}
Node::Node(int d){
  next = NULL;
  data.i = d;
  type = 2;
}
//deconstructor which clears memory
Node::~Node(){

}
//pointer to next node
Node* Node::getNext(){
  return next;
}
//sets the pointer to the next node
void Node::setNext(Node* n){
  next = n;
}
//returns a pointer to the Stack class
int Node::getIntData(){
  return data.i;
}
char Node::getCharData(){
  if (type == 1){
    return data.c;
  }
  else return 0;
}
int Node::getType(){
  return type;
}