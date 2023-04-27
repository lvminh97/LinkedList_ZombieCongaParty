#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
using namespace std;

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
    int size;

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
    T RemoveBefore(Node<T>* node);
    T RemoveAfter(Node<T>* node);
    bool ElementExists(T data);
    Node<T>* Find(T data);
    int IndexOf(T data);
    T RetrieveFront();
    T RetrieveEnd();
    T Retrieve(int index);
    void PrintList();
    void Empty();
    int Length();
};

/****************************************************************************/

template <class T>
Node<T>::Node() : data(0), next(nullptr), previous(nullptr) {}

template <class T>
Node<T>::Node(T data) : data(data), next(nullptr), previous(nullptr) {}

template <class T>
Node<T>::Node(T data, Node<T>* next) : data(data), next(next), previous(nullptr) {}

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

template <class T>
LinkedList<T>::LinkedList() : front(nullptr), end(nullptr), size(0) {}

template <class T>
LinkedList<T>::~LinkedList() {

}

template <class T>
void LinkedList<T>::AddToFront(T data) {
    Node<T> *newNode = new Node<T>(data, front);
    if(front != nullptr) {
        front->setPrevious(newNode);
    }
    front = newNode;
    if(size == 0) {
        end = front;
    }
    size++;
}

template <class T>
void LinkedList<T>::AddToEnd(T data) {
    Node<T> *newNode = new Node<T>(data);
    newNode->setPrevious(end);
    if(end != nullptr) {
        end->setNext(newNode);
    }
    end = newNode;
    if(size == 0) {
        front = end;
    }
    size++;
}

template <class T>
void LinkedList<T>::AddAtIndex(T data, int index) {
    if(index < 0 || index > size) {
        throw out_of_range("LinkedList::AddAtIndex => index is out of range");
    }
    if(index == 0) {
        AddToFront(data);
    }
    else if(index == size) {
        AddToEnd(data);
    }
    else {
        Node<T> *cur = front;
        int i = 0;
        while(i < index) {
            cur = cur->getNext();
            i++;
        }
        
        Node<T> *newNode = new Node<T>(data);
        newNode->setPrevious(cur->getPrevious());
        cur->getPrevious()->setNext(newNode);
        cur->setPrevious(newNode);
        newNode->setNext(cur);
        size++;
    }
}

template <class T>
void LinkedList<T>::AddBefore(Node<T> *node, T data) {
    if(node == front) {
        AddToFront(data);
    }
    else if(node == end) {
        AddAtIndex(data, size - 1);
    }
    else {
        Node<T> *newNode = new Node<T>(data);
        newNode->setPrevious(node->getPrevious());
        node->getPrevious()->setNext(newNode);
        node->setPrevious(newNode);
        newNode->setNext(node);
        size++;
    }
}

template <class T>
void LinkedList<T>::AddAfter(Node<T> *node, T data) {
    if(node == front) {
        AddAtIndex(data, 1);
    }
    else if(node == end) {
        AddToEnd(data);
    }
    else {
        Node<T> *newNode = new Node<T>(data);
        node->getNext()->setPrevious(newNode);
        newNode->setNext(node->getNext());
        node->setNext(newNode);
        newNode->setPrevious(node);
        size++;
    }
}

template <class T>
T LinkedList<T>::RemoveFromFront() {
    if(size == 0) {
        throw runtime_error("LinkedList::RemoveFromFront => list is empty");
    }
    T value = front->getData();
    Node<T> *cur = front;
    front = front->getNext();
    front->setPrevious(nullptr);
    delete cur;
    size--;
    return value;
}

template <class T>
T LinkedList<T>::RemoveFromEnd() {
    if(size == 0) {
        throw runtime_error("LinkedList::RemoveFromEnd => list is empty");
    }
    T value = end->getData();
    Node<T> *cur = end;
    end = end->getPrevious();
    end->setNext(nullptr);
    delete cur;
    size--;
    return value;
}

template <class T>
void LinkedList<T>::RemoveTheFirst(T data) {
    int i = 0;
    Node<T> *cur = front;
    while(i < size) {
        if(cur->getData() == data) {
            break;
        }
        cur = cur->getNext();
        i++;
    }
    if(cur == front) {
        RemoveTheFirst();
    }
    else if(cur == end) {
        RemoveFromEnd();
    }
    else {
        
    }
}

template <class T>
void LinkedList<T>::RemoveAllOf(T data) {

}

template <class T>
T LinkedList<T>::RemoveBefore(Node<T> *node) {

}

template <class T>
T LinkedList<T>::RemoveAfter(Node<T> *node) {

}

template <class T>
bool LinkedList<T>::ElementExists(T data) {
    return IndexOf(data) != -1;
}

template <class T>
Node<T>* Find(T data) {

}

template <class T>
int LinkedList<T>::IndexOf(T data) {
    int i = 0;
    Node<T> *cur = front;
    while(i < size) {
        if(cur->getData() == data){
            return i;
        }
        cur = cur->getNext();
        i++;
    }
    return -1;
}

template <class T>
T LinkedList<T>::RetrieveFront() {
    return front->getData();
}

template <class T>
T LinkedList<T>::RetrieveEnd() {
    return end->getData();
}

template <class T> 
T LinkedList<T>::Retrieve(int index) {
    if(index < 0 || index >= size) {
        throw out_of_range("LinkedList::Retrieve => index is out of range");
    }
    Node<T> *cur = front;
    int i = 0;
    while(i < index) {
        cur = cur->getNext();
        i++;
    }
    return cur->getData();
}

template <class T>
void LinkedList<T>::PrintList() {
    Node<T> *cur = front;
    while(cur != nullptr) {
        cout << cur->getData() << " ";
        cur = cur->getNext();
    }
    cout << endl;
}

template <class T>
void LinkedList<T>::Empty() {
    ~LinkedList();
}

template <class T>
int LinkedList<T>::Length() {
    return size;
}

#endif