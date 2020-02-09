  
//
//  LL_queue.cpp
//  Queue
//
//  Created by Nulyaka on 2/2/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#ifndef LLqueue_h
#define LLqueue_h

#include <iostream>

template <class T>
class QueueNode{
public:
    T data;
    QueueNode *prev;
    QueueNode *next;
};

template <class T>
class QueueLL{
private:
    QueueNode<T> *front;
    QueueNode<T> *rear;
    int size;
public:
    QueueLL() { this->front = nullptr; this->rear = nullptr; }
    
    bool isEmpty();
    void display();
    
    void enqueue(const T value);
    T dequeue();
    
    ~QueueLL();
};

template <class T>
bool QueueLL<T>::isEmpty() {
    
    if (front == nullptr) {
        return true;
    }
    
    return false;
}

// Display from rear node to front node
template <class T>
void QueueLL<T>::display() {
    
    QueueNode<T> *current = rear;
    
    if (current == nullptr) {
        return;
    }
    
    while (current != nullptr) {
        
        std::cout << current->data << ' ';
        current = current->prev;
    }
    std::cout << std::endl;
}

template <class T>
void QueueLL<T>::enqueue(const T value) {
    
    QueueNode<T> *temp = new QueueNode<T>;
    temp->data = value;
    temp->prev = nullptr;
    temp->next = nullptr;
    
    if (temp == nullptr) {
        std::cout << "Stack is full!" << std::endl;
        return;
    }
    
    if (front == nullptr) {
        front = temp;
        rear = temp;
    }
    else {
        temp->prev = rear;
        rear->next = temp;
        rear = temp;
    }
}

template <class T>
T QueueLL<T>::dequeue() {
    
    T data(nullptr);
    
    if ( !isEmpty() ) {
        
        data = front->data;
        
        QueueNode<T> *temp = front;
        
        if (front != rear) {
            front = front->next;
            front->prev = nullptr;
        }
        else {
            rear = nullptr;
            front = nullptr;
        }
        
        delete temp;
    }
    
    return data;
}

template <class T>
QueueLL<T>::~QueueLL() {
    
    if (isEmpty()) {
        return;
    }
    
    QueueNode<T> *current = nullptr;
    
    while(rear != nullptr){
        
        current = rear;
        rear = rear->prev;
        rear->next = nullptr;
        
        delete current;
        current = nullptr;
    }
}

#endif /* LLqueue_h */
