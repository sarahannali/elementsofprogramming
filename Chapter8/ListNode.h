#ifndef LISTNODE_H
#define LISTNODE_H

#include <cstddef>

namespace ListNodes
{
    template <typename T>
    class ListNode
    {
    public:
        ListNode(){};
        ListNode(T, ListNode<T> * = nullptr);
        ListNode<T> *GetNext();
        T GetData();
        void SetData(T);
        void SetNext(ListNode * = nullptr);

    private:
        T data;
        ListNode<T> *next;
    };

} // namespace ListNodes

#endif
