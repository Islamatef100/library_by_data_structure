#pragma once

// The class definition for StackType using templates
class FullStack
    // Exception class thrown by Push when stack is full.
{};

class EmptyStack
    // Exception class thrown by Pop and Top when stack is empty.
{};


template<typename ItemType>
class StackType
{
private:
    int top;
    int maxStack;
    ItemType* items;

public:

    // Class constructor.
    StackType();

    // Parameterized constructor.
    StackType(int max);

    // Destructor
    ~StackType();

    // Function: Determines whether the stack is full.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is full)
    bool IsFull() const;

    // Function: Determines whether the stack is empty.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is empty)
    bool IsEmpty() const;

    // Function: makes the stack empty.
    // Pre:  Stack has been initialized.
    // Post: Stack is empty
    void MakeEmpty() const;

    // Function: Adds newItem to the top of the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is full), FullStack exception is thrown;
    //       otherwise, newItem is at the top of the stack.
    void Push(ItemType item);

    // Function: Removes top item from the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is empty), EmptyStack exception is thrown;
    //       otherwise, top element has been removed from stack.
    void Pop(ItemType& item);

    // Function: Returns a copy of top item on the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is empty), EmptyStack exception is thrown;
    //       otherwise, top element has been removed from stack.
    ItemType Top();

    int GetLength();

};

// The function definitions for class StackType.

template<typename ItemType>
StackType<ItemType>::StackType(int max)
{
    maxStack = max;
    top = -1;
    items = new ItemType[maxStack];
}

template<typename ItemType>
StackType<ItemType>::StackType()
{
    maxStack = 500;  //Default
    top = -1;
    items = new ItemType[maxStack];
}

template<typename ItemType>
bool StackType<ItemType>::IsEmpty() const
{
    return (top == -1);
}

template<typename ItemType>
void StackType<ItemType>::MakeEmpty() const
{
    top = -1;
}

template<typename ItemType>
bool StackType<ItemType>::IsFull() const
{
    return (top == maxStack - 1);
}

template<typename ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
    if (IsFull())
        throw FullStack();
    top++;
    items[top] = newItem;
}

template<typename ItemType>
void StackType<ItemType>::Pop(ItemType& item)
{
    if (IsEmpty())
        throw EmptyStack();
    item = items[top];
    top--;
}

template<typename ItemType>
ItemType StackType<ItemType>::Top()
{
    if (IsEmpty())
        throw EmptyStack();
    return items[top];
}

template<typename ItemType>
int StackType<ItemType>::GetLength()
{
    return top + 1;
}

template<typename ItemType>
StackType<ItemType>::~StackType()
{
    delete[] items;
}
