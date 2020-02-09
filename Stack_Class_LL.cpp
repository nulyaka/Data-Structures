  
//
//  Stack_Class_LL.cpp
//  Stack
//
//  Created by Nulyaka on 2/5/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>

class Node {
public:
    int data;
    Node *next;
};

class Stack {
private:
    int size;
    int elementsAmount;
    Node *top;
    Node *head;
    
public:
    Stack() {
        head = NULL;
        top = NULL;
        size = 10;
    }
    Stack(const int size) {
        head = NULL;
        top = NULL;
        this->size = size;
    }
    
    bool isFull();
    bool isEmpty();
    void push(const int value);
    int pop();
    int peek(const int index);
    int stack_top();
    void display();
};

bool Stack::isEmpty() {
    
    if(elementsAmount == 0){
        return true;
    }
    else {
        return false;
    }
}

bool Stack::isFull() {
    
    if (elementsAmount == size) {
        return true;
    }
    else {
        return false;
    }
}

void Stack::push(const int value){
    
    if ( isFull() ) {
        std::cout << "stack overflow" << std::endl;
        return;
    }
    
    Node *temp = new Node;
    temp->data = value;
    
    if (head == NULL) {
        
        head = temp;
        head->next = NULL;
        top = head;
    }
    else {
        
        temp->next = top;
        top = temp;
    }
    
    ++elementsAmount;
}

int Stack::pop() {
    
    if ( isEmpty() ) {
        std::cout << "stack underflow" << std::endl;
        return -1;
    }
    
    int data = top->data;
    Node *temp = top;
    top = top->next;
    
    delete temp;
    --elementsAmount;
    
    return data;
}

int Stack::peek (const int index) {
    
    if ( isEmpty() ) {
        std::cout << "stack is empty" << std::endl;
        return -1;
    }
    
    if (!index || index > elementsAmount) {
        std::cout << "incorrect index" << std::endl;
        return -1;
    }
    
    Node *current = top;
    for (int i(elementsAmount); i > (elementsAmount - index + 1); i--) {
        current = current->next;
    }
    
    return current->data;
}

int Stack::stack_top() {
    
    if ( isEmpty() ) {
        std::cout << "stack is empty" << std::endl;
        return -1;
    }
    else {
        return top->data;
    }
}

void Stack::display() {
    
    Node *current = top;
    
    for (int i(elementsAmount); i > 0; --i) {
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << std::endl;
}
