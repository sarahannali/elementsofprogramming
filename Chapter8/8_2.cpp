#include <iostream>
#include "ListNode.h"
#include "LinkedList.h"

using LinkedLists::LinkedList;
using ListNodes::ListNode;
using namespace std;

void ReverseNodes(LinkedList<int> &list1, int initial_node, int final_node)
{
    ListNode<int> *sublist_head = list1.GetHead();

    int k = 1;
    while (k++ < initial_node)
    {
        sublist_head->SetNext(sublist_head->GetNext());
    }

    auto *sublist_iter = sublist_head->GetNext();

    while (initial_node++ < final_node)
    {
        auto *temp = sublist_iter->GetNext();
        sublist_iter->SetNext(temp->GetNext());
        temp->SetNext(sublist_head->GetNext());
        sublist_head->SetNext(temp);
    }
}

int main()
{
    LinkedList<int> list1{};

    ListNode<int> *e = new ListNode<int>(2);
    ListNode<int> *d = new ListNode<int>(7, e);
    ListNode<int> *c = new ListNode<int>(5, d);
    ListNode<int> *b = new ListNode<int>(3, c);
    ListNode<int> *a = new ListNode<int>(11, b);

    list1.SetHead(a);
    list1.SetTail(e);

    ReverseNodes(list1, 2, 4);

    ListNode<int> *nodeLoop = list1.GetHead();

    while (nodeLoop)
    {
        cout << nodeLoop->GetData() << '\n';
        nodeLoop = nodeLoop->GetNext();
    }

    return 0;
}
