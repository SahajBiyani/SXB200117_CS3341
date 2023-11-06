#ifndef STACK
#define STACK

#include "linkedlist.h"

template<class T>
class Stack{
public:
    T pop();
    T peek();
    void push(T);
    bool isEmpty();
private:
    LinkedList<T> data;
};

template<class T>
T Stack<T>::pop() {
    if (data.isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data.remove(data.size() - 1);
}

template<class T>
T Stack<T>::peek() {
    if (data.isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data.get(data.size() - 1);
}

template<class T>
void Stack<T>::push(T value) {
    data.add(value);
}

template<class T>
bool Stack<T>::isEmpty() {
    return data.isEmpty();
}

#endif
