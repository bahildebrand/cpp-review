#include "bst.hpp"

void BST::insert(int v) {
    Element *cur = this->root;
    Element *next = nullptr;

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