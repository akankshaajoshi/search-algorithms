class BinaryTree
{
private:
    Node *root;

public:
    bool search(Node *root, int target)
    {
        if (root == nullptr)
            return false;

        if (root->data == target)
            return true;

        search(root->left, target);
        search(root->right, target);
    }
};

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};