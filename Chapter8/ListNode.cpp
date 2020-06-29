#include "ListNode.h"

namespace ListNodes
{
    template <typename T>
    ListNode<T>::ListNode(T given_data, ListNode<T> *given_next)
    {
        this->data = given_data;
        this->next = given_next;
    }

    template <typename T>
    ListNode<T> *ListNode<T>::GetNext()
    {
        return this->next;
    }

    template <typename T>
    T ListNode<T>::GetData()
    {
        return this->data;
    }

    template <typename T>
    void ListNode<T>::SetData(T given_data)
    {
        this->data = given_data;
    }

    template <typename T>
    void ListNode<T>::SetNext(ListNode *given_next)
    {
        this->next = given_next;
    }

    template class ListNode<int>;

} // namespace ListNodes