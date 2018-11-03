class HTable {
    protected:
        virtual unsigned int hashFunc(int v);
        class Entry {
            public:
                int val;
                bool occupied;
                Entry(): occupied(false) {}
        };

    private:
        Entry* table;
        unsigned int tSize;

    public:
        HTable(unsigned int size): tSize(size) { table = new Entry[size]; }
        ~HTable() { delete table; }
        bool search(int v);
        virtual void insert(int v);
};