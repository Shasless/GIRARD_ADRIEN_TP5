#include <iostream>
#include "Stack.h"
int main() {
    Stack<int> stack;
    stack.addNode(2);
    stack.addNode(8);
    std::cout<<stack<<std::endl;
    return 0;
}
