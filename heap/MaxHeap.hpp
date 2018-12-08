#ifndef MAXHEAP__
#define MAXHEAP__

#include "Heap.hpp"

template <class T> class MaxHeap : public Heap<T> {
    protected:
        bool compFunc(T a, T b) { return a >= b; }
};

#endif // MAXHEAP__