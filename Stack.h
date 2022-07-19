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
            addNode(temp->val);
            temp=temp->next;
        }
    }
    StackNode<T>* createNode(T value){
        StackNode<T>* newNode = new StackNode<T>;
        newNode->val=value;
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
        while (temp!= nullptr){
            os<<temp->val<<" ";
            temp=temp->next;
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
                 addNode(temp->val);
                 temp=temp->next;
             }
         }
         return *this;
    }

    T pop(){
        if (list != nullptr) {
            StackNode<T> *firstNode = list;
            list=list->next;
            int value = firstNode->val;
            delete firstNode;
            return value;
        }else{
            throw std::length_error("Trying to pop when there is nothing in the list");
        }
    }

    int getSize(){
        int cpt=0;
        StackNode<T>* temp = list;
        while (temp!= nullptr){
            temp = temp->next;
            cpt++;
        }
        return cpt;
    }

    bool isEmpty(){
        if (list == nullptr)
            return true;
        return false;
    }

private:
    StackNode<T>* list;
};


#endif //WITT_JONATHAN_TP5_STACK_H
