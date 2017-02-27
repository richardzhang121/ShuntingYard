//ZhangRichard P.7
//converts infix to postfix

#include "Node.h"
#include "Stack.h"
#include <cstdlib>
#include <cstring>
using namespace std;

bool isOperator(char c);
int precedence(char c);
Stack* shuntingYard(char* input);
int main(){
  cout << "Input a string to convert it to postfix" << endl;
  char input[50];
  cin.get(input, 50); //gets input
  shuntingYard(input);
}
Stack* shuntingYard(char* input){ //starts the shunting yard
  int i = 0;
  Stack* operatorStack = new Stack(); 
  Stack* outputStack = new Stack();
  while (input[i]){ //goes through the string
    if(isdigit(input[i])){ //if  number --> output
      outputStack->push(new Node(atoi(&input[i])));
      cout << outputStack->peek()->getIntData() << " "; //print at runtime
      while(isdigit(input[i+1])){ //moves off number
	i++;
      }
    }
    else if (isOperator(input[i])){ 
      while(operatorStack->peek()){ //number with lower precedence, move to operator
	if (precedence(input[i]) >= precedence(operatorStack->peek()->getCharData())){
	    break;
	  }
	outputStack->push(operatorStack->pop()); //add operator to stack
	cout << outputStack->peek()->getCharData() << " ";
	  }
      operatorStack->push(new Node(input[i]));
      }
    else if (input[i] == '('){ //add ( to operator
      operatorStack->push(new Node(input[i]));
    }
    else if (input[i] == ')'){ // if ) then add to output
      while(operatorStack->peek()->getCharData() != '('){ // theres a ()
	outputStack->push(operatorStack->pop());
	cout << outputStack->peek()->getCharData() <<  " ";
      }
      delete operatorStack->pop();
    }
    i++;
  }
  while(operatorStack->peek()){ // operatorstack on output
    outputStack->push(operatorStack->pop());
    cout <<  outputStack->peek()->getCharData() << " ";
  }
  cout << endl;
  delete operatorStack;
  return outputStack;
}
bool isOperator(char c){
  if (c == '-' ||
      c == '+' ||
      c == '^' ||
      c == '*' ||
      c == '/'){
    return true;
  }
  return false;
}
int precedence(char c){ // creates precedence according to pemdas
  int precedence[256];
  precedence['-'] = 1;
  precedence['+'] = 1;
  precedence['*'] = 2;
  precedence['/'] = 2;
  precedence['^'] = 3;
  precedence['('] = -1;
  return precedence[c];
}
}