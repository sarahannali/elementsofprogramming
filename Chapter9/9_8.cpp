#include <iostream>
#include "CircularQueue.h"

using CircularQueues::CircularQueue;
using namespace std;

int main()
{
    CircularQueue circular_queue(3);
    circular_queue.Enqueue(1);
    circular_queue.Enqueue(2);
    circular_queue.Enqueue(3);
    circular_queue.Enqueue(4);

    cout << circular_queue.Dequeue() << '\n';
    cout << circular_queue.Dequeue() << '\n';

    circular_queue.Enqueue(5);

    cout << circular_queue.Dequeue() << '\n';
    cout << circular_queue.Dequeue() << '\n';
    cout << circular_queue.Dequeue() << '\n';
}