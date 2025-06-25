class LinkedList
{

private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    Node *search(int target)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == target)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
