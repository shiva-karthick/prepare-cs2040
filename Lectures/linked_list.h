
struct ListNode
{
    int data;       // data
    ListNode *next; // pointer to next node
};

class List
{
public:
    int size;
    ListNode *head;

public:
    List();  // constructor
    ~List(); // destructor
    void insert(int data);
    void remove(int data);
};

/*
Constructor
*/
List::List()
{
    head = nullptr;
    size = 0;
}

// Destructor
List::~List()
{
    ListNode *current = head;
    ListNode *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

void List::insert(int data)
{
    ListNode *newNode = new ListNode; // malloc a new node
    newNode->data = data;             // set the data
    newNode->next = nullptr;          // set the next pointer to null, because it will be the last node and there is no next node. This is the tail.

    if (head == nullptr) // if the list is empty
    {
        head = newNode; // set the head to the new node, pass the pointer to the new node
    }
    else
    {
        ListNode *current = head;        // set the current pointer to the head
        while (current->next != nullptr) // cycle through the list until the end, where the next pointer is null
        {
            current = current->next; // set the current pointer to the next node
        }
        current->next = newNode;
    }
    size++; // increment the size
}

void List::remove(int data)
{
    if (head == nullptr)
    {
        return;
    }

    ListNode *current = head;
    ListNode *previous = nullptr;

    while (current->data != data) // O(n) time
    {
        if (current->next == nullptr)
        {
            return;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    if (current == head)
    {
        head = head->next;
    }
    else
    {
        previous->next = current->next;
    }
    size--;
}