#include <iostream>
#include "ListNode.h"
#include "LinkedList.h"

using LinkedLists::LinkedList;
using ListNodes::ListNode;
using namespace std;

void MergeLists(LinkedList<int> &list1, LinkedList<int> &list2)
{
    ListNode<int> *node1 = list1.GetHead();
    ListNode<int> *node2 = list2.GetHead();

    ListNode<int> *head = new ListNode<int>();
    ListNode<int> *tail = head;

    while (tail)
    {

        if (node1 == nullptr)
        {
            tail->SetNext(node2);
            break;
        }

        if (node2 == nullptr)
        {
            tail->SetNext(node1);
            break;
        }

        if (node1->GetData() <= node2->GetData())
        {
            tail->SetNext(node1);
            node1 = node1->GetNext();
        }

        else
        {
            tail->SetNext(node2);
            node2 = node2->GetNext();
        }

        tail = tail->GetNext();
    }
    
    list1.SetHead(head->GetNext());
}

int main()
{
    LinkedList<int> list1{};

    ListNode<int> *c = new ListNode<int>(7);
    ListNode<int> *b = new ListNode<int>(5, c);
    ListNode<int> *a = new ListNode<int>(2, b);

    list1.SetHead(a);
    list1.SetTail(c);

    LinkedList<int> list2{};

    ListNode<int> *e = new ListNode<int>(11);
    ListNode<int> *d = new ListNode<int>(3, e);

    list2.SetHead(d);
    list2.SetTail(e);

    MergeLists(list1, list2);

    ListNode<int> *nodeLoop = list1.GetHead();

    while (nodeLoop)
    {
        cout << nodeLoop->GetData() << '\n';
        nodeLoop = nodeLoop->GetNext();
    }

    return 0;
}
