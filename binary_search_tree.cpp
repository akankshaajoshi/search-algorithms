class BinarySearchTree
{
private:
    Node *root;

public:
    bool search(Node *node, int target)
    {
        if (node == nullptr)
            return false;

        if (node->data == target)
            return true;

        if (target < node->data)
            return search(node->left, target);
        else
            return search(node->right, target);
    }
};

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};