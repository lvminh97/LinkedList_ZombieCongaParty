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
Node<T>::Node() : data(0), next(NULL), previous(NULL) {}

template <class T>
Node<T>::Node(T data) : data(data), next(NULL), previous(NULL) {}

template <class T>
Node<T>::Node(T data, Node<T>* next) : data(data), next(next), previous(NULL) {}

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
LinkedList<T>::LinkedList() : front(NULL), end(NULL), size(0) {}

template <class T>
LinkedList<T>::~LinkedList() {
    Empty();
}

template <class T>
void LinkedList<T>::AddToFront(T data) {
    // create new node before front
    Node<T> *newNode = new Node<T>(data, front);
    if(front != NULL) {
        front->setPrevious(newNode);
    }
    front = newNode;        // make new node as new front of list
    if(size == 0) {         // if new node is the first element of list, then front is the same with end
        end = front;
    }
    size++;                 // update the size of list
}

template <class T>
void LinkedList<T>::AddToEnd(T data) {
    // create new node after end
    Node<T> *newNode = new Node<T>(data);
    newNode->setPrevious(end);
    if(end != NULL) {
        end->setNext(newNode);
    }
    end = newNode;          // make new node as new end of list
    if(size == 0) {         // if new node is the first element of list, then front is the same with end
        front = end;
    }
    size++;                 // update the size of list
}

template <class T>
void LinkedList<T>::AddAtIndex(T data, int index) {
    if(index < 0 || index > size) {     // throw exception when index is out of range
        throw out_of_range("LinkedList::AddAtIndex => index is out of range");
    }
    if(index == 0) {            // new node as new front of list
        AddToFront(data);
    }
    else if(index == size) {    // new node as new end of list
        AddToEnd(data);
    }
    else {                      
        Node<T> *cur = front;
        int i = 0;
        // loop to index
        while(i < index) {
            cur = cur->getNext();
            i++;
        }
        
        // create new node and link to previous and next
        Node<T> *newNode = new Node<T>(data);
        newNode->setPrevious(cur->getPrevious());
        cur->getPrevious()->setNext(newNode);
        cur->setPrevious(newNode);
        newNode->setNext(cur);
        size++;     // update the size of list
    }
}

template <class T>
void LinkedList<T>::AddBefore(Node<T> *node, T data) {
    if(node == front) {         // new node as new front of list
        AddToFront(data);
    }
    else if(node == end) {      // new node is before end of list 
        AddAtIndex(data, size - 1);
    }
    else {
        // create new node and link to previous and next
        Node<T> *newNode = new Node<T>(data);
        newNode->setPrevious(node->getPrevious());
        node->getPrevious()->setNext(newNode);
        node->setPrevious(newNode);
        newNode->setNext(node);
        size++;                 // update the size of list
    }
}

template <class T>
void LinkedList<T>::AddAfter(Node<T> *node, T data) {
    if(node == front) {         // new node is after front of list
        AddAtIndex(data, 1);
    }
    else if(node == end) {      // new node as new end of list
        AddToEnd(data);
    }
    else {
        // create new node and link to previous and next
        Node<T> *newNode = new Node<T>(data);
        node->getNext()->setPrevious(newNode);
        newNode->setNext(node->getNext());
        node->setNext(newNode);
        newNode->setPrevious(node);
        size++;                 // update the size of list
    }
}

template <class T>
T LinkedList<T>::RemoveFromFront() {
    if(size == 0) {             // throw exception when list is empty
        throw runtime_error("LinkedList::RemoveFromFront => the list is empty");
    }

    T value = front->getData(); // get value of front
    Node<T> *cur = front;       // store current front to temporary
    // update next node as new front of list
    front = front->getNext();   
    if (front != NULL) {
        front->setPrevious(NULL);
    }
    delete cur;                 // free memory space
    size--;                     // update the size of list
    return value;               // return value
}

template <class T>
T LinkedList<T>::RemoveFromEnd() {
    if(size == 0) {             // throw exception when list is empty
        throw runtime_error("LinkedList::RemoveFromEnd => the list is empty");
    }
    T value = end->getData();   // get value of end
    Node<T> *cur = end;         // store current end to temporary
    // update previous node as new end of list
    end = end->getPrevious();
    if (end != NULL) {
        end->setNext(NULL);
    }
    delete cur;                 // free memory space
    size--;                     // update the size of list
    return value;               // return value
}

template <class T>
void LinkedList<T>::RemoveTheFirst(T data) {
    // loop to find the first node that has value equal data
    Node<T> *cur = front;       
    while(cur != NULL) {
        if(cur->getData() == data) {    // found
            if(cur == front) {          // front?
                RemoveFromFront();
            }
            else if(cur == end) {       // end?
                RemoveFromEnd();
            }
            else {
                // update the new connection and free memory space
                cur->getPrevious()->setNext(cur->getNext());
                cur->getNext()->setPrevious(cur->getPrevious());
                delete cur;
                size--;     // update the size of list
            }
            break;          // function is ended when find and delete 1 node
        }
        cur = cur->getNext();       // move to next node
    }
}

template <class T>
void LinkedList<T>::RemoveAllOf(T data) {
    // loop through all nodes of list
    Node<T> *cur = front;
    while(cur != NULL) {
        if(cur->getData() == data) {    // found
            if(cur == front) {          // front?
                RemoveFromFront();
                cur = front;
            }
            else if(cur == end) {       // end?
                RemoveFromEnd();
                break;
            }
            else {
                // update the new connection and free memory space
                Node<T>* temp = cur->getNext();
                cur->getPrevious()->setNext(cur->getNext());
                cur->getNext()->setPrevious(cur->getPrevious());
                delete cur;
                size--;         // update the size of list
                cur = temp;     // move to next node
            }
        }
        else {
            cur = cur->getNext();       // move to next node
        }
    }
}

template <class T>
T LinkedList<T>::RemoveBefore(Node<T> *node) {
    if(node == front) {         // throw exception when the node is front of list
        throw runtime_error("LinkedList::RemoveBefore => current node is the first node of list");
    }
    Node<T> *prev = node->getPrevious();    // get previous node
    T value = prev->getData();              // get the value

    if(prev == front) {                     // if the deleted node is front, update new front 
        node->setPrevious(NULL);
        delete prev;
        front = node;
    }
    else {
        // delete node and make new connection
        node->setPrevious(prev->getPrevious());
        prev->getPrevious()->setNext(node);
        delete prev;
    }
    size--;         // update the size of list
    return value;   // return value
}

template <class T>
T LinkedList<T>::RemoveAfter(Node<T> *node) {
    if(node == end) {           // throw exception when the node is end of list
        throw runtime_error("LinkedList:RemoveAfter => current node is the last node of list");
    }
    Node<T> *next = node->getNext();        // get next node
    T value = next->getData();              // get the value
    if(next == end) {                       // if the deleted node is end, update new end
        node->setNext(NULL);
        delete next;
        end = node;
    }
    else {
        // delete the node and make new connection
        node->setNext(next->getNext());
        next->getNext()->setPrevious(node);
        delete next;
    }
    size--;             // update the size of list
    return value;       // return value
}

template <class T>
bool LinkedList<T>::ElementExists(T data) {
    // check list contains the element?
    return IndexOf(data) != -1;
}

template <class T>
Node<T>* LinkedList<T>::Find(T data) {
    Node<T>* cur = front;
    // loop all nodes of list to find 
    while(cur != NULL) {
        if(cur->getData() == data) {    // if found, return node
            return cur;
        }
        cur = cur->getNext();
    }
    // if not found, return NULL
    return NULL;
}

template <class T>
int LinkedList<T>::IndexOf(T data) {
    int i = 0;
    Node<T> *cur = front;
    // loop all nodes of list to find 
    while(i < size) {
        if(cur->getData() == data){     // if found, return index
            return i;
        }
        cur = cur->getNext();
        i++;
    }
    return -1;      // if not found, return -1
}

template <class T>
T LinkedList<T>::RetrieveFront() {
    if(size == 0) {     // throw exception when the list is empty
        throw runtime_error("LinkedList::RetrieveFront => the list is empty");
    }
    return front->getData();        // return the data of front
}

template <class T>
T LinkedList<T>::RetrieveEnd() {
    if(size == 0) {     // throw exception when the list is empty
        throw runtime_error("LinkedList::RetrieveEnd => the list is empty");
    }
    return end->getData();          // return the data of end
}

template <class T> 
T LinkedList<T>::Retrieve(int index) {
    if(index < 0 || index >= size) {        // throw exception when index is out of range
        throw out_of_range("LinkedList::Retrieve => index is out of range");
    }
    // loop to index
    Node<T> *cur = front;
    int i = 0;
    while(i < index) {
        cur = cur->getNext();
        i++;
    }
    return cur->getData();      // return the data
}

template <class T>
void LinkedList<T>::PrintList() {
    Node<T> *cur = front;
    // loop all nodes of list to print to the screen
    while(cur != NULL) {
        cout << cur->getData();
        if(cur != end) {
            cout << '=';
        }
        cur = cur->getNext();
    }
    // print new line
    cout << endl;
}

template <class T>
void LinkedList<T>::Empty() {
    // loop each node of list and free memory space
    Node<T> *cur = front;
    while(cur != NULL) {
        Node<T> *temp = cur->getNext();
        delete cur;
        cur = temp;
    }
    front = end = NULL;     // reset front and end
    size = 0;               // reset the size of list
}

template <class T>
int LinkedList<T>::Length() {
    return size;            // get the size of list
}

#endif