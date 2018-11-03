#include <iostream>
#include "htable.hpp"

using namespace std;

int main(void) {
    HTable h(1024);

    h.insert(10);
    h.insert(20);

    cout << "10: " <<  h.search(10) << endl;
    cout << "20: " <<  h.search(20) << endl;
    cout << "25: " <<  h.search(25) << endl;
}