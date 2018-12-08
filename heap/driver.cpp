#include "MaxHeap.hpp"
#include "Heap.hpp"
#include <iostream>

int main(void) {
    MaxHeap<int> mh;
    Heap<int> h;

    cout << "---------------MaxHeap---------------" << endl;

    mh.insert(2);
    cout << mh.peek() << endl;
    mh.insert(5);
    cout << mh.peek() << endl;
    mh.insert(7);
    mh.pop();
    cout << mh.peek() << endl;

    cout << "--------------MinHeap-----------------" << endl;
    
    h.insert(7);
    cout << h.peek() << endl;
    h.insert(5);
    cout << h.peek() << endl;
    h.insert(2);
    h.pop();
    cout << h.peek() << endl;

    return 0;
}