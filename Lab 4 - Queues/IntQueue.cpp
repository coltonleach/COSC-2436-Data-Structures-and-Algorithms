#include <iostream>
#include "IntQueue.h"
#include <cstdlib>
#include <memory>
using namespace std;
//Constructor
template <typename T> IntQueue<T>::IntQueue(int s)
{
   queueSize = s;
   queueArray = new T [queueSize];
   front = -1;
   rear = -1;
   numItems = 0;
}


/********************************************
  Function enqueue inserts the value in num 
  at the rear of the queue.                 
********************************************/
template <typename T> void IntQueue<T>::enqueue(T num)
{
   if (isFull())
   {
      cout << "The queue is full.\n";
   }
   else
   {
      // Calculate the new rear position
      rear = (rear + 1) % queueSize;      
      // Insert new item
      queueArray[rear] = num;      
      // Update item count
      numItems++;
   }
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
template <typename T> void IntQueue<T>::dequeue(T &num)
{
   if (isEmpty())
   {
      cout << "The queue is empty.\n";
   }
   else
   {
      // Move front
      front = (front + 1) % queueSize;
      // Retrieve the front item
      num = queueArray[front];
      // Update item count		
      numItems--;
      cout << num << " was removed from the queue.\n";
   }
}

//__________________________________________________
//All of these functions below can be used for any data type

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
template <typename T> bool IntQueue<T>::isEmpty() const
{
   return numItems == 0;
}

//********************************************
// Function isFull returns true if the queue *
// is full, and false otherwise.             *
//********************************************
template <typename T> bool IntQueue<T>::isFull() const
{
   return numItems == queueSize;
}

//*******************************************
// Function clear resets the front and rear *
// indices, and sets numItems to 0.         *
//*******************************************
template <typename T> void IntQueue<T>::clear()
{
   front = -1;
   rear = -1;
   numItems = 0;
}

