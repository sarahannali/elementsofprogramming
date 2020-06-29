#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"

namespace LinkedLists
{
    using ListNodes::ListNode;

    template <typename T>
    class LinkedList
    {
    public:
        LinkedList(){};
        ListNode<T> *GetHead() const { return head; };
        void SetHead(ListNode<T> *);
        ListNode<T> *GetTail() const { return tail; };
        void SetTail(ListNode<T> *);
        void InsertNode();
        void DeleteNode();

    private:
        ListNode<T> *head = nullptr;
        ListNode<T> *tail = nullptr;
    };

} // namespace LinkedLists

#endif
