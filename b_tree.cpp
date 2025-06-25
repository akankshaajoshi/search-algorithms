class BTree
{
private:
    Node *root;
    int t;

    void splitChild(Node *parent, int i, Node *child);
    void insertNonFull(Node *node, int key);
};

struct Node
{
    int *keys;
    Node **children;
    int numKeys;
    bool isLeaf;

    Node(int t, bool leaf)
    {
        keys = new int[2 * t - 1];
        children = new Node *[2 * t];
        numKeys = 0;
        isLeaf = leaf;
    }
};