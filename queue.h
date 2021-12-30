#pragma once
// The class definition for QueueType using templates
class FullQueue
    // Exception class thrown by enqueue when Queue is full.
{};

class EmptyQueue
    // Exception class thrown by dequeue and first when Queue is empty.
{};

#include <iostream>
using namespace std;

template<typename ItemType>
class QueueType
{
private:
    int front;
    int rear;
    ItemType* items;
    int maxQue;
    int counter;

public:

    // Class constructor.
    QueueType();

    // Parameterized constructor.
    QueueType(int max);

    // Destructor
    ~QueueType();

    // Function: Determines whether the queue is full.
    // Pre:  Queue has been initialized.
    // Post: Function value = (queue is full)
    bool IsFull() const;

    // Function: Determines whether the queue is empty.
    // Pre:  Queue has been initialized.
    // Post: Function value = (queue is empty)
    bool IsEmpty() const;

    // Function: makes the queue empty.
    // Pre:  Queue has been initialized.
    // Post: Queue is empty
    void MakeEmpty();

    // Function: Adds newItem to the end of the queue.
    // Pre:  Queue has been initialized.
    // Post: If (Queue is full), FullQueue exception is thrown;
    //       otherwise, newItem is at the end of the queue.
    void Enqueue(ItemType);

    // Function: Removes item from the queue that was inserted.
    // Pre:  Queue has been initialized.
    // Post: If (Queue is empty), EmptyQueue exception is thrown;
    //       otherwise, Removes item from the queue that was inserted
    void Dequeue(ItemType& item);

    // Function: Returns a copy of item on the queue.
    // Pre:  Queue has been initialized.
    // Post: If (queue is empty), EmptyQueue exception is thrown;
    //       otherwise, Removes item from the queue that was inserted
    void First(ItemType& item);

    int GetLength();

    void DisplayQueue();
};

template<typename ItemType>
QueueType<ItemType>::QueueType()
{
    maxQue = 501; //Default
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
    counter = 0;
}

template<typename ItemType>
QueueType<ItemType>::QueueType(int max)
{
    maxQue = max;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
    counter = 0;
}

template<typename ItemType>
QueueType<ItemType>::~QueueType()
{
    delete[] items;
}

template<typename ItemType>
bool QueueType<ItemType>::IsFull() const
{
    //return ((rear + 1) % maxQue == front);
    return counter == maxQue;
}

template<typename ItemType>
bool QueueType<ItemType>::IsEmpty() const
{
    //return (rear == front);
    return counter == 0;
}

template<typename ItemType>
void QueueType<ItemType>::MakeEmpty()
{
    front = maxQue - 1;
    rear = maxQue - 1;
    counter = 0;
}

template<typename ItemType>
void QueueType<ItemType>::Enqueue(ItemType newItem)
{
    if (IsFull())
    {
        throw FullQueue();
    }
    else
    {
        rear = (rear + 1) % maxQue;
        counter++;
        items[rear] = newItem;
    }
}

template<typename ItemType>
void QueueType<ItemType>::Dequeue(ItemType& item)
{
    if (IsEmpty())
    {
        throw EmptyQueue();
    }
    else
    {
        front = (front + 1) % maxQue;
        counter--;
        item = items[front];
    }
}

template<typename ItemType>
void QueueType<ItemType>::First(ItemType& item)
{
    if (IsEmpty())
    {
        throw EmptyQueue();
    }
    else
    {
        item = items[front];
    }
}

template<typename ItemType>
int QueueType<ItemType>::GetLength()
{
    return counter;
}

template<typename ItemType>
void QueueType<ItemType>::DisplayQueue()
{
    if (IsEmpty()) return;

    for (int i = 1; i <= counter; i++)
        cout << items[(front + i) % maxQue] << endl;
}
