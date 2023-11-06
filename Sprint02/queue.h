#ifndef QUEUE
#define QUEUE

#include "linkedlist.h"

template<class T>
class Queue{
public:
    T dequeue();
    T peek();
    void enqueue(T);
    bool isEmpty();
private:
    LinkedList<T> data;
};

template<class T>
T Queue<T>::dequeue() {
    if (data.isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data.remove(0);
}

template<class T>
T Queue<T>::peek() {
    if (data.isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data.get(0);
}

template<class T>
void Queue<T>::enqueue(T value) {
    data.add(value);
}

template<class T>
bool Queue<T>::isEmpty() {
    return data.isEmpty();
}

#endif
