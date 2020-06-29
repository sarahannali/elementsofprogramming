#include "LinkedList.h"

namespace LinkedLists
{
    template <typename T>
    void LinkedList<T>::SetHead(ListNode<T> *given_head)
    {
        if (given_head == this->head)
            return;
        else
        {
            if (this->head)
                given_head->SetNext(this->head);

            this->head = given_head;
        }
    }

    template <typename T>
    void LinkedList<T>::SetTail(ListNode<T> *given_tail)
    {
        if (this->tail)
        {
            this->tail->SetNext(given_tail);
        }
        this->tail = given_tail;
    }

    template class LinkedList<int>;

} // namespace LinkedLists
