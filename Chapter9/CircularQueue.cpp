#include "CircularQueue.h"
#include <algorithm>

namespace CircularQueues
{
    CircularQueue::CircularQueue(int given_size)
        : entries(given_size)
    {
    }

    void CircularQueue::Enqueue(int given_element)
    {
        if (total_elements == entries.size())
        {
            std::rotate(entries.begin(), entries.begin() + head, entries.end());
            head = 0;
            tail = total_elements;
            entries.resize(entries.size() * scale_factor);
        }

        entries[tail] = given_element;
        tail = (tail + 1);
        total_elements++;
    }

    int CircularQueue::Dequeue()
    {
        int result = entries[head];
        head++;
        total_elements--;
        return result;
    }

} // namespace CircularQueues