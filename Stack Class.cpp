#include <iostream>

template <class T>
class Stack {
private:
    T *st;
    int size;
    int top;
    
public:
    Stack() {
        size = 10;
        top = -1;
        st = new T[10];
    }
    
    Stack(const int size) {
        
        this->size = size;
        top = -1;
        st = new T[this->size];
    }
    
    ~Stack() {
        delete[] st;
        st = NULL;
    }
    
    void push(const T value);
    T pop();
    T peek(const int index);
    T stack_top();
    bool isEmpty();
    bool isFull();
    void display();
};

template<class T>
void Stack<T>::push (const T value) {
    
    if ( isFull() ) {
        std::cout << "stack overflow" << std::endl;
    }
    else {
        ++top;
        st[top] = value;
    }
}

template <class T>
T Stack<T>::pop() {
    
    if ( isEmpty() ) {
        std::cout << "stack is empty" << std::endl;
        return -1;
    }
    
    return st[top--];
}

template <class T>
T Stack<T>::peek (const int index) {
    
    if (top + 1 < index) {
        std::cout << "incorrect index" << std::endl;
        return -1;
    }
    else {
        return st[top - index + 1];
    }
}

template <class T>
T Stack<T>::stack_top () {
    
    if ( isEmpty() ) {
        return -1;
    }
    else {
        return st[top];
    }
}

template <class T>
bool Stack<T>::isEmpty() {
    
    if ( isEmpty() ) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
bool Stack<T>::isFull() {
    
    if (top == size - 1) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
void Stack<T>::display() {
    
    for (int index(top); index >= 0; --index)
    {
        std::cout << st[index] << ' ';
    }
    std::cout << std::endl;
}
