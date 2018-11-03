#include "bst.hpp"
#include <iostream>

using namespace std;

int main() {
    BST b;

    b.insert(10);
    b.insert(5);
    b.insert(11);
    b.insert(19);
    b.insert(100);
    b.insert(1000);
    b.insert(-10);

    cout << "PREORDER:" << endl;
    b.DFS(PREORDER);

    cout << "INORDER:" << endl;
    b.DFS(INORDER);

    cout << "POSTORDER:" << endl;
    b.DFS(POSTORDER);
}