#include <iostream>
#include <string>
#include "linkedlist_xxx.hpp"

using namespace std;

int main() {
    LinkedList<int> a;
    a.AddToFront(1);
    a.PrintList();
    a.AddToFront(2);
    a.PrintList();
    a.AddToEnd(3);
    a.PrintList();
    a.AddAtIndex(900, 2);
    a.PrintList();
    cout << a.IndexOf(3) << endl;
    return 0;
}