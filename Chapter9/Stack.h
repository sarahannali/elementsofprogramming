#ifndef STACK_H
#define STACK_H

#include <stack>

namespace Stacks
{
    class Stack
    {
    public:
        void Push(int);
        void Pop();
        bool Empty() const { return cached_elements.empty(); };
        int GetMax();

    private:
        struct CachedElement
        {
            int element;
            int max;
        };

        std::stack<CachedElement> cached_elements;
    };
} // namespace Stacks

#endif