#include <iostream>
#include "Stack.h"

using Stacks::Stack;
using namespace std;

int main()
{
    Stack test_stack {};
    test_stack.Push(16);
    test_stack.Push(20);
    test_stack.Push(10);
    test_stack.Push(30);
    cout << test_stack.GetMax() << '\n';

    test_stack.Pop();
    cout << test_stack.GetMax();
}