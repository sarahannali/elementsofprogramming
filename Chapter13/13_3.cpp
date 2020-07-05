#include <iostream>
#include "LRUCache.h"

using LRUCaches::LRUCache;
using namespace std;

int main()
{
    LRUCache cache;
    cache.Insert(123, 13);
    cache.Remove(123);
}