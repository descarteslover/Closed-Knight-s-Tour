#pragma once
#include <iostream>

using namespace std;

class InvalidQueueOperation {};

template <typename T>
struct Node {
    T value;
    Node<T>* next = nullptr;
    Node<T>(T val, Node<T>* nxt = nullptr) { value = val; next = nxt; }
};

template <class T>
class Queue {
public:
    Queue();
    ~Queue();
    void Enqueue(T);
    T Dequeue();
    T Front();
    bool IsEmpty();
    void Print();

private:
    Node<T>* queue;
};

template <class T>
Queue<T>::Queue() {
    queue = nullptr;
}

template <class T>
Queue<T>::~Queue() {
    Node<T>* temp;
    while (queue != nullptr) {
        temp = queue;
        queue = queue->next;
        delete temp;
    }
}

template <class T>
void Queue<T>::Enqueue(T item)
{
    if (queue == nullptr) {
        queue = new Node<T>(item);
        return;
    }

    Node<T>* temp = queue;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new Node<T>(item);

}

template <class T>
bool Queue<T>::IsEmpty()
{
    return queue == nullptr;
}

template <class T>
T Queue<T>::Dequeue()
{
    if (queue == nullptr) {
        throw InvalidQueueOperation();
    }

    Node<T>* temp = queue;
    T item = queue->value;
    queue = queue->next;
    delete temp;

    return item;
}

template <class T>
T Queue<T>::Front()
{
    if (queue == nullptr) {
        throw InvalidQueueOperation();
    }

    T item = queue->value;

    return item;
}

template<class T>
void Queue<T>::Print(){
    Node<T>* temp = queue;
    while (temp != nullptr) {
        T data = temp->value;
        cout << data;
        if (temp->next != nullptr) {cout << " --> "; }
        temp = temp->next;
    }
    cout << endl;
}