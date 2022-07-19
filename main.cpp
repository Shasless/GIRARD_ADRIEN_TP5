#include <iostream>
#include "Stack.h"

template<class T>
void deleteStack(StackNode<T>* stack){
    if (stack!= nullptr){
        deleteStack(stack->next);
        delete stack;
    }
}


int main() {
    Stack<int> stack;
    stack.push(2);
    stack.push(8);
    std::cout<<"We create stack and push 2 then 8 : "<<std::endl;
    std::cout<<"Stack = "<<stack<<std::endl;
    Stack<int> stack1(stack);
    std::cout<<"We create stack1 by copying stack : "<<std::endl;
    std::cout<<"Stack1 = "<<stack1<<std::endl;
    stack1.push(3);
    std::cout<<"We push 3 in stack 1 : "<<std::endl;
    std::cout<<"Stack1 = "<<stack1<<std::endl;
    stack=stack1;
    std::cout<<"we define stack as =stack1"<<std::endl;
    std::cout<<"Stack = "<<stack<<std::endl;
    std::cout<<"'"<<stack1.pop()<<"' has been popped from the stack 1 which is now :"<<std::endl;
    std::cout<<"Stack1 = "<<stack1<<std::endl;
    stack.clean();
    std::cout<<"We clean stack and try to pop it"<<std::endl;
    try {
        stack.pop();
    }catch (const std::length_error & e){
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<"Length of stack : "<<stack.getSize()<<std::endl;
    std::cout<<"Length of stack1 : "<<stack1.getSize()<<std::endl;
    std::cout<<"Is stack empty ? "<<stack.isEmpty()<<std::endl;
    std::cout<<"Is stack1 empty ? "<<stack1.isEmpty()<<std::endl;
    return 0;
}
