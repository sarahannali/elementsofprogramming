#include <iostream>
#include "ListNode.h"
#include "LinkedList.h"

using LinkedLists::LinkedList;
using ListNodes::ListNode;
using namespace std;

int ListLength(LinkedList<int> &list)
{
    ListNode<int> *node = list.GetHead();
    int list_length = 1;
    while (node->GetNext())
    {
        list_length++;
        node = node->GetNext();
    }

    return list_length;
}

ListNode<int> *OverlappingNode(LinkedList<int> &list1, LinkedList<int> &list2)
{
    if (list1.GetTail() == list2.GetTail())
    {

        int list1_length = ListLength(list1);
        int list2_length = ListLength(list2);

        ListNode<int> *node1 = list1_length > list2_length ? list1.GetHead() : list2.GetHead();
        ListNode<int> *node2 = list1_length > list2_length ? list2.GetHead() : list1.GetHead();

        int list_diff = abs(list1_length - list2_length);

        while (list_diff)
        {
            node1 = node1->GetNext();
            list_diff--;
        }

        while (node1 != node2 && node1->GetNext())
        {
            node1 = node1->GetNext();
            node2 = node2->GetNext();
        }

        return node1;
    }

    return nullptr;
}

int main()
{
    LinkedList<int> list1{};

    ListNode<int> *c = new ListNode<int>(7);
    ListNode<int> *b = new ListNode<int>(5, c);
    ListNode<int> *a = new ListNode<int>(2, b);

    list1.SetHead(a);

    LinkedList<int> list2{};

    ListNode<int> *g = new ListNode<int>(10);
    ListNode<int> *f = new ListNode<int>(13, g);
    ListNode<int> *e = new ListNode<int>(11, f);
    ListNode<int> *d = new ListNode<int>(3, e);

    c->SetNext(e);

    list2.SetHead(d);
    list2.SetTail(g);
    
    list1.SetTail(g);

    auto ans = OverlappingNode(list1, list2);

    ans ? cout << ans->GetData() : cout << "No Overlapping Nodes";

    return 0;
}
