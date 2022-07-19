#include <iostream>
#include "Stack.h"

using namespace std;

template<typename T>
void deleteStack(StackNode<T>* stack){
    if (stack!= nullptr){
        deleteStack(stack->next);
        delete stack;
    }
}


int main() {
    Stack<int> stack;
    stack.push(55);
    stack.push(7);
    cout<<"We create stack and push 55 then 7 : "<<endl;
    cout<<"Stack = "<<stack<<endl;
    Stack<int> stack_copy(stack);
    cout<<"We create stack_copy by copying stack : "<<endl;
    cout<<"stack_copy = "<<stack_copy<<endl;
    stack_copy.push(15);
    cout<<"We push 15 in stack_copy : "<<endl;
    cout<<"stack_copy = "<<stack_copy<<endl;
    cout<<"'"<<stack_copy.pop()<<"' has been popped from the stack 15 which is now :"<<endl;
    cout<<"stack_copy = "<<stack_copy<<endl;
    stack.clean();
    cout<<"We clean stack and try to pop it"<<endl;
    stack.pop();
    cout<<"Length of stack : "<<stack.getSize()<<endl;
    cout<<"Length of stack_copy : "<<stack_copy.getSize()<<endl;
    cout<<"Is stack empty ?  "<<boolalpha<<stack.isEmpty()<<endl;
    cout<<"Is stack_copy empty ?  "<<boolalpha<<stack_copy.isEmpty()<<endl;

    Stack<string> stack_str;
    stack_str.push("Hello");
    stack_str.push("World");
    cout<<"We create stack_str "<<endl;
    cout<<"stack_str = "<<stack_str<<endl;

    return 0;
}
