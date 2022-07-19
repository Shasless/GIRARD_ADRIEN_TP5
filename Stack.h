//
// Created by jonat on 19/07/2022.
//

#ifndef WITT_JONATHAN_TP5_STACK_H
#define WITT_JONATHAN_TP5_STACK_H
#include "iostream"
template<class T>

struct StackNode{
    StackNode* next;
    T val;
};
template<class T>
class Stack {
public:
    Stack();
    Stack(const Stack& stack);
    StackNode<T> createNode(T value);
    void addNode(T value);
    std::ostream & print(std::ostream& os);
    friend std::ostream & operator<<(std::ostream& os,Stack<T> & stack);

private:
    StackNode<T>* list;
};


#endif //WITT_JONATHAN_TP5_STACK_H
