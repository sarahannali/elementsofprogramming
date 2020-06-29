#include <iostream>
#include "ListNode.h"
#include "LinkedList.h"

using LinkedLists::LinkedList;
using ListNodes::ListNode;
using namespace std;

void KthElement(ListNode<int> *head, int k)
{
    ListNode<int> *tail_element = head;
    ListNode<int> *kth_element = head;

    while (k+1)
    {
        tail_element = tail_element->GetNext();
        k--;
    }

    while (tail_element->GetNext())
    {
        tail_element = tail_element->GetNext();
        kth_element = kth_element->GetNext();
    }

    kth_element->SetNext(kth_element->GetNext()->GetNext());
}

int main()
{
    ListNode<int> *a, *b, *c, *d, *e, *f, *g;

    g = new ListNode<int>(10);
    f = new ListNode<int>(13, g);
    e = new ListNode<int>(2, f);
    d = new ListNode<int>(7, e);
    c = new ListNode<int>(5, d);
    b = new ListNode<int>(3, c);
    a = new ListNode<int>(11, b);

    KthElement(a, 3);

    ListNode<int> *nodeLoop = a;

    while (nodeLoop)
    {
        cout << nodeLoop->GetData() << '\n';
        nodeLoop = nodeLoop->GetNext();
    }

    return 0;
}
