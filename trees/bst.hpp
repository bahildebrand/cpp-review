class BST {
    protected:
        class Element {
            private:
                int val;

            public:
                Element *left;
                Element *right;
                Element(int v): val(v), left(nullptr), right(nullptr) {}
                int     getVal() { return val; }
        };

    private:
        Element *root;

    public:
        BST(): root(nullptr) {}
        void insert(Element *e);
};