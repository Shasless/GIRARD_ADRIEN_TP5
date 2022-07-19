//
// Created by adrie on 19/07/2022.
//

#ifndef GIRARD_ADRIEN_TP5_STACK_H
#define GIRARD_ADRIEN_TP5_STACK_H
#include "iostream"

template<typename T>

struct StackNode{
    T data;
    StackNode* next;
};
template<class T>
class Stack {
public:
    Stack(){
        list= nullptr;
    }

    virtual ~Stack() {
        clean();
        delete list;
    }

    Stack(const Stack& stack){
        list = nullptr;
        StackNode<T>* temp =stack.list;
        while (temp!= nullptr){
            addNode(temp->data);
            temp=temp->next;
        }
    }
    StackNode<T>* createNode(T value){
        StackNode<T>* newNode = new StackNode<T>;
        newNode->data=value;
        newNode->next= nullptr;
        return newNode;
    }

    void push(T value){
        StackNode<T>* newNode = createNode(value);
        newNode->next=list;
        list=newNode;
    }

    void addNode(T value){
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
    std::ostream & print(std::ostream& os){
        StackNode<T> *temp = list;
        while (true){
            os<<temp->data<<" ";
            temp=temp->next;
            if(temp==nullptr) break;
            else os<<"-> ";
        }
        return os;
    }
    friend std::ostream & operator<<(std::ostream& os,Stack<T> & stack){
        return stack.print(os);
    }

    void clean(){
        deleteStack(list);
        list = nullptr;
    }

    friend void deleteStack(StackNode<T>* stack){
        if (stack!= nullptr){
            deleteStack(stack->next);
            delete stack;
        }
    }

     Stack& operator =(const Stack<T>& stack){

         if (&stack != this) {
             deleteStack(list);
             list = nullptr;
             StackNode<T>* temp =stack.list;
             while (temp!= nullptr){
                 addNode(temp->data);
                 temp=temp->next;
             }
         }
         return *this;
    }

    T pop(){
        try {
            popelem();
        }catch (const std::length_error & e){
            std::cout<<e.what()<<std::endl;
        }
    }
    T popelem(){
        if (list != nullptr) {
            StackNode<T> *firstNode = list;
            list=list->next;
            int value = firstNode->data;
            delete firstNode;
            return value;
        }else{
            throw std::length_error("Error try to pop an empty list");
        }
    }
    int getSize(){
        int size=0;
        StackNode<T>* temp = list;
        while (temp!= nullptr){
            temp = temp->next;
            size++;
        }
        return size;
    }

    bool isEmpty(){
        if (list == nullptr)
            return true;
        return false;
    }

private:
    StackNode<T>* list;
};


#endif //GIRARD_ADRIEN_TP5_STACK_H
