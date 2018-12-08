#ifndef HEAP__
#define HEAP__

#include <vector>

using namespace std;

template <class T> class Heap {
    protected:
        virtual bool compFunc(T a, T b) { return a <= b; }
    
    private:
        std::vector<T> * m_arr;
        int getLeft(int cur) { return (cur*2)+2; }
        int getRight(int cur) { return (cur*2)+1; }
        int getParent(int cur) { return (cur-1)/2; }
        void swap(T& a, T& b);

    public:
        Heap() { this->m_arr = new std::vector<T>; }
        ~Heap() { delete m_arr; }
        void insert(T val);
        void pop();
        T peek() { return this->m_arr->at(0); }
};

template <class T> void Heap<T>::swap(T& a, T& b) {
    T temp;

    temp = a;
    a = b;
    b = temp;
}

template <class T> void Heap<T>::pop() {
    vector<T>& vecRef = *this->m_arr;

    if(vecRef.empty()){
        return;
    }

    vecRef[0] = vecRef.back();
    vecRef.erase(vecRef.end()-1);

    int next = 0;
    int cur = 0;

    while(cur < vecRef.size()) {
        int l = getLeft(cur);
        int r = getRight(cur); 
        if(l < vecRef.size() && compFunc(vecRef[l], vecRef[cur])) {
            next = l;
        }
        if(r < vecRef.size() && compFunc(vecRef[r], vecRef[next])) {
            next = r;
        }
        if(next != cur) {
            swap(vecRef[next], vecRef[cur]);
            cur = next;
        } else {
            break;
        }
    }
}

template <class T> void Heap<T>::insert(T val) {
    vector<T>& vecRef = *this->m_arr;
    vecRef.push_back(val);
    int cur = vecRef.size()-1;

    while(cur > 0) {
        int parent = getParent(cur);

        if( parent < 0 ) {
            break;
        }

        if(compFunc(vecRef[cur], vecRef[parent])) {
            swap(vecRef[cur], vecRef[parent]);

            cur = parent;
        } else {
            break;
        }
    }
}

#endif // HEAP__