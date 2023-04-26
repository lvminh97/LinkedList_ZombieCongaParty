#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

template <class T>
class Node {
private:
    T data;
    Node<T> *next;
    Node<T> *previous;

public:
    Node();
    Node(T data);
    Node(T data, Node<T>* next);
    T getData();
    void setData(T data);
    Node<T>* getNext();
    void setNext(Node<T>* next);
    Node<T>* getPrevious();
    void setPrevious(Node<T>* prev);
};

template <class T>
class LinkedList {
private:
    Node<T> *front, *end;

public:
    LinkedList();
    ~LinkedList();

    void AddToFront(T data);
    void AddToEnd(T data);
    void AddAtIndex(T data, int index);
    void AddBefore(Node<T>* node, T data);
    void AddAfter(Node<T>* node, T data);
    T RemoveFromFront();
    T RemoveFromEnd();
    void RemoveTheFirst(T data);
    void RemoveAllOf(T data);
};

/****************************************************************************/

template <class T>
Node<T>::Node() : data(0), next(nullptr), previous(nullptr) {}

template <class T>
Node<T>::Node(T data) : data(data), next(nullptr), previous(nullptr) {}

template <class T>
Node<T>::Node(T data, Node<T>* next) : data(datt), next(next), previous(nullptr) {}

template <class T>
T Node<T>::getData() {
    return this->data;
}

template <class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template <class T>
Node<T>* Node<T>::getNext() {
    return this->next;
}

template <class T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template <class T>
Node<T>* Node<T>::getPrevious() {
    return this->previous;
}

template <class T>
void Node<T>::setPrevious(Node<T>* prev) {
    this->previous = prev;
}

/****************************************************************************/

#endif