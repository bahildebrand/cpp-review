#include <functional>
#include "htable.hpp"

using namespace std;

unsigned int HTable::hashFunc(int v) {
    hash<int> intHash;

    return intHash(v) % tSize;
}

// linear probing insert
void HTable::insert(int v) {
    unsigned int idx = hashFunc(v);

    if(table[idx].occupied) {
        unsigned int startIdx = idx;

        while(!table[idx].occupied){
            if(++idx >= tSize) {
                idx = 0;
            }

            if(idx == startIdx) {
                return;
            }
        }
    }

    table[idx].val = v;
    table[idx].occupied = true;
}

bool HTable::search(int v) {
    bool ret = false;
    unsigned int idx = hashFunc(v);

    if(table[idx].occupied == true) {
        if(table[idx].val == v) {
            ret = true;
        } else {
            unsigned int startIdx = idx;

            while(!table[idx].occupied){
                if(++idx >= tSize) {
                    idx = 0;
                }

                if(idx == startIdx) {
                    ret = false;
                    break;
                } else if (table[idx].val == v) {
                    ret = true;
                }
            }  
        }
    }

    return ret;
}