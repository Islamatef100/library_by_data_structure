#pragma once
using namespace std;
template<typename ItemType>
class Node {
public:
    ItemType data; // data
    Node* next; // pointer to next
};

template<typename ItemType>
class List {
private:
    Node<ItemType>* head;

public:
    // Class constructor. Note that We don't need the Parameterized constructor with the max here.
    List(void);

    // Destructor
    ~List(void);

    // Function: Determines whether the list is empty.
    // Pre:  List has been initialized.
    // Post: Function value = (list is empty)
    bool IsEmpty();

    // Function: Adds newItem to the list at a specific place and returns the created node.
    // Pre:  List has been initialized.
    // Post: New item is added and the created node are returned.
    Node<ItemType>* InsertNode(int index, ItemType x);
    Node<ItemType>* Insertfirst(int index, ItemType x);
    // Function: Searches the list for a specific value.
    // Pre:  List has been initialized.
    // Post: Location of the value is returned if found otherwise 0 is returned
    int FindNode(ItemType x);

    // Function: Deletes a node by its value
    // Pre:  List has been initialized.
    // Post: Node is deleted from the list.
    void DeleteNode(ItemType x);
    void DisplayList(void);
    ItemType Displayitem(int id);
    void edit(int id, ItemType x);
    ItemType search(int id, ItemType x);
};

template<typename ItemType>
List<ItemType>::List(void)
{
    head = NULL;
}

template<typename ItemType>
List<ItemType>::~List(void)
{
    Node<ItemType>* currNode = head;
    Node<ItemType>* nextNode = NULL;
    while (currNode != NULL) {
        nextNode = currNode->next;
        delete currNode; // destroy the current node
        currNode = nextNode;
    }
}

template<typename ItemType>
bool List<ItemType>::IsEmpty()
{
    return head == NULL;
}
template<typename ItemType>
Node<ItemType>* List<ItemType>::Insertfirst(int index, ItemType x)
{
    Node<ItemType>* newnode = new Node<ItemType>;
    if (index != 0)
        return NULL;
    else
    {
        newnode->data = x;
        newnode->next = head;
        head = newnode;
    }
    return newnode;
}
template<typename ItemType>
Node<ItemType>* List<ItemType>::InsertNode(int index, ItemType x)
{
    if (index < 0)
        return NULL;
    Node<ItemType>* newnode = new Node<ItemType>;
    newnode->data = x;
    int currindex = 1;
    Node<ItemType>* currnode = head;
    while (currnode && currindex < index)
    {
        currnode = currnode->next;
        currindex++;
    }
    if (index > 0 && currnode == NULL)
        return NULL;
    if (index == 0)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        newnode->next = currnode->next;
        currnode->next = newnode;

    }
    return newnode;
}

template<typename ItemType>
int List<ItemType>::FindNode(ItemType x)
{
    //Node<ItemType>* prevnode = NULL;
    Node<ItemType>* currnode = head;
    //int currindex = 1;
    while (currnode && currnode->data != x)
    {
        //prevnode = currnode;
        currnode = currnode->next;
        //currindex++;
    }
    if (currnode)
    {
        cout << "d: " << currnode->data << endl;
    }

    return 0;
}

template<typename ItemType>
void List< ItemType>::DeleteNode(ItemType x)
{
    Node<ItemType>* prevnode = NULL;
    Node<ItemType>* currnode = head;
    //int currindex = 1;
    while (currnode && currnode->data != x)
    {
        prevnode = currnode;
        currnode = currnode->next;
        //currindex++;
    }
    if (currnode)
    {
        if (prevnode)
        {
            prevnode->next = currnode->next;
            delete currnode;
        }
        else
        {
            head = currnode->next;
            delete currnode;
        }
        //return currindex;
    }

    // return NULL;
}

template<typename ItemType>
void List<ItemType>::DisplayList(void)
{
    Node<ItemType>* currnode = head;
    //int currindex = 1;
    while (currnode)
    {
        cout << currnode->data << endl;
        currnode = currnode->next;
    }
}

template<typename ItemType>
ItemType List<ItemType>::Displayitem(int id)
{
    Node<ItemType>* currnode = head;
    //int currindex = 1;
    for (int i = 0; i < id; i++)
    {
        currnode = currnode->next;
    }
    //cout << currnode->data << endl;
    return currnode->data;
}
template<typename ItemType>
void List<ItemType>::edit(int id, ItemType x)
{
    Node<ItemType>* currnode = head;
    //int currindex = 1;
    for (int i = 0; i < id - 1; i++)
    {
        currnode = currnode->next;
    }
    //cout << currnode->data << endl;
    currnode->data = x;
    //return currnode->data;
}
template<typename ItemType>
ItemType List<ItemType>::search(int id, ItemType x)
{
    Node<ItemType>* currnode = head;
    //int currindex = 1;
    for (int i = 0; i < (id - 1); i++)
    {
        //prevnode = currnode;
        currnode = currnode->next;
        //currindex++;
        if (currnode == NULL)
            break;
    }
       if (currnode)
        return currnode->data;
       else if(head ==NULL)
       {
           return x;
       }
    return 0;
}
