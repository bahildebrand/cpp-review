class BST {
    protected:
        class Element {
            private:
                int val;
                Element *left;
                Element *right;

            public:
                Element(int v): val(v), left(nullptr), right(nullptr) {}
                int getVal() { return val; }
                Element *getLeft() { return left; }
                Element *getRight() { return right; }
                void setRight(Element *e) { right = e; }
                void setLeft(Element *e) { left = e; }
        };

    private:
        Element *root;
        void dfsTraverse(Element *e);

    public:
        BST(): root(nullptr) {}
        virtual void insert(int v);
        virtual void remove(int v);
        bool search(int v);
        void DFS();
        void BFS();
};