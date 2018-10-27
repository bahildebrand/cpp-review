#include <iostream>

class Stack {
    public:
        Stack(): head(nullptr) {}
        ~Stack() {
            while(head != nullptr) {
                Item *next = head->getNext();
                delete head;
                head = next;
            }
        }
        void push(int data) {
            Item *newItem = new Item(head, data);
            head = newItem;
        }
        int pop() {
            int val = 0;

            if(head != nullptr) {
                Item *next = head->getNext();
                val = head->getData();

                delete head;
                head = next;
            }

            return val;
        }

    protected:
        class Item {
            public:
                Item(Item *n, int d): next(n), data(d) {}
                int getData() { return data; }
                Item *getNext() { return next; }
            private:
                Item *next;
                int data;
        };

    private:
        Item *head;
};

int main() {
    Stack s;
    int i;

    for(i = 1; i < 20; i++) {
        s.push(i);
    }

    while(i > 0) {
        std::cout << s.pop() << std::endl;
        i--;
    }
}