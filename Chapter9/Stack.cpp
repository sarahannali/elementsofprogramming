#include "Stack.h"
#include <algorithm>

namespace Stacks
{

    void Stack::Push(int element)
    {
        CachedElement new_element = {element, std::max(element, Empty() ? element : GetMax())};
        cached_elements.push(new_element);
    }

    void Stack::Pop()
    {
        if (Empty())
        {
            throw "Pop(): empty stack";
        }

        cached_elements.pop();
    }

    int Stack::GetMax()
    {
        if (Empty())
        {
            throw "Max(): empty stack";
        }

        return cached_elements.top().max;
    }

} // namespace Stacks