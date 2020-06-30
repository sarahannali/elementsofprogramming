#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

namespace CircularQueues
{
    class CircularQueue
    {
    public:
        CircularQueue(int);
        void Enqueue(int);
        int Dequeue();
        int Size() const { return total_elements; };
    private:
        const int scale_factor = 2;
        unsigned int total_elements = 0;
        int head = 0;
        int tail = 0;
        std::vector<int> entries;
    };
}

#endif