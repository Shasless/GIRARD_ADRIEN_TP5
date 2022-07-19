//
// Created by jonat on 19/07/2022.
//

#include "Stack.h"
template<class T>
Stack<T>::Stack() {
    list= nullptr;
}

template<class T>
Stack<T>::Stack(const Stack<T> &stack) {
    Stack<T>();
    StackNode<T>* temp =stack.list;
    while (temp!= nullptr){
        addNode(temp->val);
        temp=temp->next;
    }
}

template<class T>
StackNode<T> Stack<T>::createNode(T value) {
    StackNode<T>* newNode = new StackNode<T>;
    newNode->val=value;
    newNode->next= nullptr;
    return newNode;
}

template<class T>
void Stack<T>::addNode(T value) {
    if(list!= nullptr) {
        StackNode<T> *temp = list;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next= createNode(value);
    } else{
        list= createNode(value);
    }
}

template<class T>
std::ostream &Stack<T>::print(std::ostream &os) {
    StackNode<T> *temp = list;
    while (temp!= nullptr){
        os<<temp->val<<" ";
        temp=temp->next;
    }
    return os;
}

template<class T>
std::ostream & operator<<(std::ostream& os,Stack<T> & stack){
    return stack.print(os);
}