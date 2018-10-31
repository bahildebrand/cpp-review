#include "bst.hpp"
#include <queue>
#include <iostream>

using namespace std;

void BST::insert(int v) {
    Element *cur = this->root;
    Element *next = nullptr;

    if( cur == nullptr ) {
        this->root = new Element(v);
    } else {
        while(cur != nullptr) {
            if(v < cur->getVal()) {
                next = cur->getLeft();

                // if node doesn't exist insert here
                if(next == nullptr) {
                    next = new Element(v);
                    cur->setLeft(next);
                    break;
                } else {
                    cur = next;
                }
            } else if(v > cur->getVal()) {
            next = cur->getRight();

                // if node doesn't exist insert here
                if(next == nullptr) {
                    next = new Element(v);
                    cur->setRight(next);
                    break;
                }
                else {
                    cur = next;
                }
                
            } else {
                //not allowing duplicates
                break;
            }
        }
    }
}

void BST::remove(int v) {
    
}

bool BST::search(int v) {
    Element *cur = this->root;
    Element *next = nullptr;
    bool found = false;

    while(cur != nullptr) {
        if(v < cur->getVal()) {
            next = cur->getLeft(); 

            if(next == nullptr) {
                break;
            }
            else {
                cur = next;
            }

        } else if(v > cur->getVal()) {
            next = cur->getRight(); 

            if(next == nullptr) {
                break;
            }
            else {
                cur = next;
            }

        } else {
            found = true;
            break;
        }
    }

    return found;
}

void BST::dfsTraverse(Element *e) {
    cout << e->getVal() << endl;
    if(e->getLeft() != nullptr) {
        dfsTraverse(e->getLeft());
    }

    if(e->getRight() != nullptr) {
        dfsTraverse(e->getRight());
    }
}

void BST::DFS() {
    dfsTraverse(this->root);
}

void BST::BFS() {
    Element *curEle = this->root;
    queue<Element*> q;

    while(curEle) {
        cout << curEle->getVal() << endl;
        if(curEle->getLeft() != nullptr) {
            q.push(curEle->getLeft());
        }

        if(curEle->getRight() != nullptr) {
            q.push(curEle->getRight());
        }

        curEle = q.front();
        q.pop();
    }
}
