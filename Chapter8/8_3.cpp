#include <iostream>
#include "ListNode.h"
#include "LinkedList.h"

using LinkedLists::LinkedList;
using ListNodes::ListNode;
using namespace std;

ListNode<int> *CycleFinder(ListNode<int> *head)
{
    ListNode<int> *slow_itr = head->GetNext();
    ListNode<int> *fast_itr = head->GetNext()->GetNext();

    while (fast_itr && fast_itr->GetNext())
    {
        slow_itr = slow_itr->GetNext();
        fast_itr = fast_itr->GetNext()->GetNext();

        if (slow_itr == fast_itr)
        {

            int cycle_len = 0;

            do
            {
                ++cycle_len;
                fast_itr = fast_itr->GetNext();
            } while (slow_itr != fast_itr);

            auto cycle_iter_1 = head;
            auto cycle_iter_2 = head;

            while (cycle_len)
            {
                cycle_iter_1 = cycle_iter_1->GetNext();
                cycle_len--;
            }

            while (cycle_iter_1 != cycle_iter_2)
            {
                cycle_iter_1 = cycle_iter_1->GetNext();
                cycle_iter_2 = cycle_iter_2->GetNext();
            }

            return cycle_iter_1;
        }
    }

    return nullptr;
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

    e->SetNext(d);

    auto ans = CycleFinder(a);

    if (ans == nullptr)
    {
        cout << "No Cycle Found";
    }
    else
    {
        cout << ans->GetData();
    }

    return 0;
}
